/*
    NETCODE colored petri net simulator

    MEMLIST.C

    contains the basic functioning of a linked list for the purpose of
    keeping track of the color values which are used in testing the array
    there are only one of these lists per program, as the starting data
    is global

    unfortunately, this function does compare pointers, which makes
    it unfit for segmented architectures such as dos, which have multiple
    pointer values for the same memory locations.   We will fix this by
    making conditionally huge pointers for dos/win16.  However, functions
    will be required for operating systems which do not allow flat or huge 
    pointers.

    this file assumes that char exists and is 1 byte in length


    (c) 1996 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/MEMLIST.C,v 2.20 1997/03/04 04:12:02 gilem Exp $
*/


#define SUPER_USER
#include "petri.h" 
#include <memory.h>
#include <string.h>   

int CONDITIONAL_HUGE *testhuge;

/*
    the memblock is the basic unit in the list, because it contains
    the location of the memory block, the size of the block, and
    the pointer to the next block.
*/
typedef struct memblock_tag {
    TOKEN_VALUE  *where;
    TOKEN_SIZE   size; /* in units of token_value, not necessarily bytes */
    struct memblock_tag *next;
} memblock;


/*
    the head memblock is empty, but serves as a block which always
    exists

    the backup is used to store the backup for a specific enabling
    marking so that it doesn't need to be calculated for every
    inhibit combination.  It cannot be manipulated directly, only
    backed up and restored.
*/
memblock head = {0,0,0};
memblock backup = {0,0,0};

/* internal functions */
void memblock_delete(memblock *head, memblock *item);
void memlist_add( memblock *head, TOKEN_VALUE* begin, TOKEN_SIZE size );
void memlist_deleteall(memblock *head);
void memlist_copy(memblock *dest, memblock *source);

void
memlist_add( memblock *head, TOKEN_VALUE* begin, TOKEN_SIZE size ) {
    memblock *newm;

    newm = (memblock*)malloc( sizeof(memblock) );
    if( !newm ) {
        logerror("memlist_add, out of memory");
        return;
    }
    newm->where = begin;
    newm->size = size;
    newm->next = head->next;
    head->next = newm;
}

void
memblock_delete(memblock *head, memblock *item) {
    memblock *current = head;
    memblock *last = head;

    if( item == head )
        return;


    while( item != current ) {

        if( current->next ) {
            last = current;
            current = current->next;
        }
        else
            return;
    }

    /* now remove the item */
    last->next = current->next;
    free( current );
}

void
memlist_deleteall(memblock *head) {
    /* clear the list and the backup */
    while( head->next )
        memblock_delete(head, head->next);
    head->where = 0;
    head->size = 0;
    head->next = 0;
}

void
memlist_copy(memblock *dest, memblock *source) {
    /* clear the destination */
    memlist_deleteall(dest);
    /* now copy, ignoring order */
    while( source->next ) {
        source = source->next;
        memlist_add( dest, source->where, source->size );
    }
}

void
memlist_backup() {                  
	/*
		backup the list so that the original list can
		be tested against each inhibiting token combination
	*/
	
    memlist_copy( &backup, &head );
}

void
memlist_restore() {                                        
	/*
		restore the last list which was backed up
	*/
    memlist_copy( &head, &backup );
}


void
memlist_clear() {
    memlist_deleteall(&head);
    memlist_deleteall(&backup);
}


int
memlist_merge(TOKEN_VALUE* dest, TOKEN_VALUE* source, TOKEN_SIZE size) {
    /*
    test if the value beginning at the location begin, and
    continuing for size intersects with any other color value
    if so, then compare it to it.  If it matches, then update
    the memlist, combining the values if necessary... if compare
    fails, then return false

    note: on returning FALSE, the list may have been changed beyond
    repair, since we are assuming that a false will end the comparison
    
    NOTE: for now we will actually return two different
    truth values from this function.  1 if compare was
    necessary, and 2 if no overlaps

	argument size is a number of TOKEN_VALUES, not bytes
    */

    memblock *current = &head;
	memblock *working;
    memblock *last = &head;
    BOOLEAN found = FALSE;
	BOOLEAN bDuplicate = FALSE;

    /*
        look for an overlapping data range
        taking into account that the size of the data may be more
        than a single byte
    */
    TOKEN_VALUE *enddest;
    TOKEN_VALUE *endworking;
    char *cmpbegin;
    char *cmpend;
	char *cmpsource;
    int result;

    if( size <= 0 ){
        logerror("memlist_merge, invalid data");
        return MERGE_ERROR;
    }

    while( current->next ) {
        /* get the byte boudaries of the two ranges, leaving the last byte
			for the moment.  NOTE that these pointers are TOKEN_VALUES, and not chars */
		working = current->next;
        enddest = dest + size ;
        endworking = working->where + working->size;
        /* two cases where the byte boundaries (of the destination) are non-overlapping */
        /* note that since the enddest and endworking are actually one byte past the
            end of the block, we must check for the equality case */
        if( endworking <= dest
            || enddest <= working->where ) {
            current = current->next;
        }
        /*
        in any case of overlap, the overlapped value
        is represented by the max(begin) to the min(end)
        */
        else {
            found = TRUE;
            /* there IS an overlap */
            /* compare from the max begin to the min end */
            cmpbegin = (char*)ncmax( dest, working->where);
            cmpend = (char*)ncmin( endworking, enddest );
			cmpsource = (char*)source + ((char*)cmpbegin - (char*)dest);

            /* if the bytes are not aligned, then return false,
                because no way to reconcile on both big and little
                endian machines */
            if( (cmpend - cmpbegin) % sizeof(TOKEN_VALUE) )
                return MERGE_ERROR;

			/* compare the destination with the source */
            result = memcmp( cmpbegin, cmpsource, cmpend-cmpbegin );
            if(result)
                return MERGE_DIFF;

            /*
            now need to remove the current item, combine the
            two results, and move on to the next item

			for now we will not combine the items, but will instead continue 
			to compare the item with the remaining overlapping items until
			all of the list has been checked. 
			To avoid having dupliate items in the list, we will set a flag if
			one item is exactly the same as another item, and then fail to 
			add it to the list
            */
            {
            memblock *temp;
            /* make our current item equal to the sum of the old item 
            begin = ncmin( begin, current->where );
            size = (ncmax( endnew, endcurrent ) - begin + 1) / sizeof(TOKEN_VALUE); */
			if( dest == working->where 
				&& endworking == enddest ) {
				bDuplicate = TRUE;
				break;
			}
            /* move on to the next item */
            temp = current->next;
            /* do not delete the working item, because we are using it
			memblock_delete( &head, working ); */
            current = temp;
            }
        }

    }

    /* since we have reached the end, we must add the current data point */
	if( !bDuplicate )
		memlist_add( &head, dest, size );

    /* special return code for no comparisons necessary
        used for testing the function to the netman output */
    if( !found )
        return MERGE_NOMATCH;

    return MERGE_SAME;
}

TOKEN_SIZE 
memlist_LookupSize(TOKEN_VALUE* ptv) {
	/*
		use the specified token value to lookup the size of the element that you wish 
		to return.  This is used for allowing unknown-length color vectors on output 
		arcs.  If the pointer which is used was used in the transition which is being
		fired, then the memlist should locate the pointer, and return the number of
		elements remaining in the vector.  If it is not found in the immediate 
		vector, then zero is returned.
	*/
	memblock *pmbCurrent=&head;
	memblock *pmbWorking;
	BOOLEAN bFound=FALSE;
	TOKEN_VALUE *ptvBegin, *ptvEnd;
	TOKEN_SIZE iReturn=0;

	while(pmbCurrent->next) {
		pmbWorking = pmbCurrent->next;
		ptvBegin = pmbWorking->where;
		ptvEnd = ptvBegin + pmbWorking->size - 1;

		if( ptv >= ptvBegin 
			&& ptv <= ptvEnd ) {
			if(bFound)
				logerror("<warning> memlist_lookupsize ambiguous reference to unknown size on output arc");
			else {
				bFound = TRUE;
				iReturn = ptvEnd - ptv + 1;
			}
		}
		pmbCurrent = pmbWorking;
	}
	return iReturn;
}
