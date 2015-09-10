/*
    NETCODE colored petri net simulator
    These are the new functions for colored execution of a petri net within
    the NETCODE simulator.  The functions assume that the data structure
    has already been constructed, either by hand or by generation from
    NETMAN.

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\projects\netman.vc\simulate\petriout/RCS/color.c,v 2.17 1996/05/05 02:05:56 gilem Exp $
*/
#define SUPER_USER
#include "petri.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
    the purpose of the (standard) fire and (standard) enable functions
    has changed slightly from the creation of NETCODE.  Initially, they
    were allowed to change the structure of the net directly, by editing
    the tokens in each of the places.  This functionality was deemed
    to be difficult for two reasons:
        1) too difficult to write a user-defined code function
        2) too easy to make the system not perform like a petri net

    For this reason, a new method is used whereby the tokens are moved by the
    simulator, which assigns and checks the validity of the input tokens
    to the arc colors, and then calls a standard or fire function.

    The enabling condition is something IN ADDITION to the arc color being met

    After the fire function is called, then the simulator handles placing the
    new output transitions into the output places

    THEREFORE, there is no longer a need for standard fire functions, because
    the logic is within the canbeenabled function
*/
BOOLEAN IsTokenCombinationEnabling(void);
BOOLEAN CheckInputArcs(void);
BOOLEAN CheckInhibitArcs(void);
BOOLEAN CheckAllInhibitorCombinations(void);
BOOLEAN SetupInitialTokenCombination(void);
BOOLEAN SetupNextTokenCombination(void);
BOOLEAN SetupInitialInhibitCombination(void);
BOOLEAN SetupNextInhibitCombination(void);
void ChooseCombinationToFire(void);

/* global variables to keep a space which can hold the token iteration
    for now we will dynamically allocate it, although this part of the space can
    be known in advance, see InitializeToken

    when filled, a token combination is a match of token combination to input
    arcs.  each combination must be checked against ALL inhibitor combinations.
    looks like this: where HA is arc header, and HI is inhibitor header, and H0 is end header

    e.g. - HA 0 1 2 HA 1 HA 3 4 HI 0 H0

    */
TOKEN_NUMBER* gIterSpace=NULL;
TOKEN_NUMBER gIterSpaceSize=0;

#define IH_TYPE_END         0
#define IH_TYPE_INHIBIT     1
#define IH_TYPE_NORMAL      2

#define ITER_HEADER_SIZE    5 /* this is the number of TOKEN_NUMBER sized elements in the header
                                    of each segment of gIterSpace, it should be reflected
                                    in the IterHeader structure below */
typedef struct {
    TOKEN_NUMBER arcNumber; /* number of the arc in the transition struct */
    TOKEN_NUMBER arcType;   /* type of arc see above */
    TOKEN_NUMBER place;     /* the number of the place to which this arc is connected */
    TOKEN_NUMBER howMany;   /* how many tokens are currently in the place */
    TOKEN_NUMBER weight;    /* unsigned weight, see arcType to identify inhibitors */
} IterHeader;

/* some functions to deal with the iterheader.  These are critical to the proper operation of the system */
void IncrementIterHeader( IterHeader **ppIH, TOKEN_NUMBER **ppFirst );
void IncrementIterHeader( IterHeader **ppIH, TOKEN_NUMBER **ppFirst )
{
    (*ppIH) = (IterHeader*)( (*ppFirst) + (*ppIH)->weight );
    (*ppFirst) = ((TOKEN_NUMBER*)(*ppIH)) + ITER_HEADER_SIZE;
}

/*************************************************************************************/
/*  This function calls the appropriate enabling function (via a function pointer) to*/
/*  be called for a particular transition.  It then returns the result calculated by */
/*  thaat function                                                                   */
/*************************************************************************************/
BOOLEAN CanBeEnabled(TRANS_NUMBER tran )
{
    BOOLEAN bFound=FALSE;

	/*
		added a new little feature to this function to keep track of the first
		combination which is enabling.  This is only currently used to keep
		track of the first enabling combination when a transition has a
		variable time
	*/

    /*
        Set current transition before entering function
        used to restrict access to places not connect to tran
        tranCurrent is also used for the token combination functions
    */
    net.tranCurrent=tran;
	net.tran[tran].lFirstCombo=0;
    /*
        first make sure that the space allocated can handle all of the necessary combinations
        and initialize the space for this token
    */
    if( SetupInitialTokenCombination() )
    {
        /*
            now loop on the condition that there are still more combinations to be tried before
            all of the combinations are exhausted
        */
        do {
            bFound = IsTokenCombinationEnabling();
            if( bFound )
                break;

			net.tran[tran].lFirstCombo++;
        } while (SetupNextTokenCombination());
    }

    return bFound;
}

BOOLEAN SetupInitialTokenCombination()
{
/*
    set up the token combination for the first combination which may satisfy
    the input arc requirements

    return true if there is at least one combination (enough tokens)
    and return false if there are no valid combinations
*/
    /*
        check to make sure there is enough space in the token checking area
        first.  If not realloc it to be large enough.
    */
    {
        TOKEN_NUMBER i, iSum=0, iArcs;
        iArcs = net.tran[net.tranCurrent].inputCount;
        for(i=0; i<iArcs; i++)
        {
            /*
                get the input arcs, and add the weight +ITER_HEADER_SIZE to the number of space required
                see below for description of the other bytes
            */
            iSum += ITER_HEADER_SIZE + abs(net.tran[net.tranCurrent].inputArc[i].weight);
        }
        /* add one extra iter header for the end marker */
        iSum += ITER_HEADER_SIZE;

        if( iSum > gIterSpaceSize )
        {
            gIterSpace = (TOKEN_NUMBER*)realloc( gIterSpace, sizeof(TOKEN_NUMBER)*iSum );
            gIterSpaceSize = iSum;
        }

        if( gIterSpace == 0 && iSum > 0)
        {
            logerror( "could not allocate space for gIterSpace" );
	    	CloseLogFile();
	    	return FALSE;
        }

    }

    /*
        initialize the space for the token-checking area
        checking to make sure that there are enough tokens for
        all of the non-inhibitor input arcs
            if there are not enough tokens, then return false
            if there are enough tokens, then return true
    */
    {
        TOKEN_NUMBER i, j, iArcs;
        TOKEN_NUMBER iLocation=0;
        IterHeader   *pIH;
        BOOLEAN bSkip = FALSE;

        iArcs = net.tran[net.tranCurrent].inputCount;
        for(i=0; i<iArcs; i++)
        {
            /* set up the place to store the iter header */
            pIH = (IterHeader*)&gIterSpace[iLocation];

            /* get the input arcs, and add the weight +1 to the number of space required */
            pIH->weight = net.tran[net.tranCurrent].inputArc[i].weight;

            /* if an input arc, make sure that there are at least weight number of tokens */
            pIH->place = net.tran[net.tranCurrent].inputArc[i].place;
            pIH->howMany = net.place[pIH->place].tokenCount;
            pIH->arcNumber = i;


            if( pIH->weight > 0 )
            {
                /* the arc is not an inhibitor */
                /* the first element stores the type of arc... wasteful, but convenient
                   IH_TYPE_NORMAL => input arc ;
                   IH_TYPE_INHIBIT => inhibitor ;
                   IH_TYPE_END => end of list */
                pIH->arcType = IH_TYPE_NORMAL;
                /* since there are more tokens required than there are in the place,
                    this transition is definitely not enabled  */
                if( pIH->howMany < pIH->weight )
                    return FALSE;
            }
            else
            {
                /* the arc IS an inhibitor */
                pIH->arcType = IH_TYPE_INHIBIT;
                pIH->weight = -pIH->weight;

                /* if the inhibitor place doesn't have enough elements, then
                    it cannot inhibit anything, so skip it */
                if( pIH->howMany < pIH->weight )
                    bSkip = TRUE;
            }


            if( !bSkip )
            {
                /* initialize all of the token elements, setting up the first set
                    of tokens as the first x tokens in the place
                    NOTE: this assumes only one arc for each place */
                for(j=0; j<pIH->weight; j++)
                {
                    gIterSpace[iLocation+ITER_HEADER_SIZE+j] = j;
                }
            }
            else
                bSkip = FALSE;

            // increment to the next element, to prepare for the next arc
            iLocation += pIH->weight+ITER_HEADER_SIZE;


        }

        /* mark the end of the list */
        pIH = (IterHeader*)&gIterSpace[iLocation];
        pIH->arcType = 0;

    }

    return TRUE;
}

BOOLEAN SetupNextTokenCombination()
{
/*
    set up the next token combination
    the first combination is set up using initializeTokenCombination
    return TRUE if the next combination is set up
    and FALSE if there are no more valid combinations
    NOTE: this only sets the combination for the INPUT arcs, not for the inhibitors,
    because each valid input combination must be checked against all inhibiting combinations
*/
    IterHeader *pIH;
    TOKEN_NUMBER *pFirst;
    TOKEN_NUMBER i, j, max;

    /* initialize to the beginning of gIterSpace */
    pIH = (IterHeader*) gIterSpace;
    pFirst = &gIterSpace[ITER_HEADER_SIZE];

    /* while the current arc is an input arc */
    while( pIH->arcType == IH_TYPE_NORMAL )
    {
        /* set the max to the maximum element number which can be represented by this element */
        max = pIH->howMany - 1;

        /* count backwards through the elements */
        for( i=(pIH->weight-1); i>-1; i-- )
        {
            /* if the element is less than the max, then success */
            if( pFirst[i] < max )
            {
                /* add one to this element */
                pFirst[i]++;
                /* reset all the ones following this element */
                for( j=i+1; j<pIH->weight; j++ )
                {
                    pFirst[j] = pFirst[i] + j - i;
                }

                /* now return success, because the next combination has been selected */
                return TRUE;
            }

            /* the max of the previous item must be max-- */
            max--;
        }

        /* setup the next arc */
        IncrementIterHeader( &pIH, &pFirst );
    }

    /* there are no more combinations */
    return FALSE;
}

BOOLEAN SetupInitialInhibitCombination()
{
/* set up the intial inhibit combination.  This is quite a bit simpler
than the token combination function, because it doesn't have to build
the data structure */
    IterHeader *pIH;
    TOKEN_NUMBER *pFirst;
    TOKEN_NUMBER j;
    BOOLEAN bHasInhibitors=FALSE;

    /* initialize to the beginning of gIterSpace */
    pIH = (IterHeader*) gIterSpace;
    pFirst = &gIterSpace[ITER_HEADER_SIZE];

    /* find the first inhibitor, by skipping all of the input arcs */
    while( pIH->arcType == IH_TYPE_NORMAL )
    {
        /* setup the next arc */
        IncrementIterHeader( &pIH, &pFirst );
    }

    /* while there are more inhibitors to check */
    while( pIH->arcType == IH_TYPE_INHIBIT )
    {
        bHasInhibitors = TRUE;

        /* initalize each weight */
        for( j=0; j<pIH->weight; j++ )
        {
            pFirst[j] = j;
        }

        /* setup the next arc */
        IncrementIterHeader( &pIH, &pFirst );
    }

    return bHasInhibitors;
}

BOOLEAN SetupNextInhibitCombination()
{
/* return TRUE if next combination has been achieved, FALSE otherwise */
    IterHeader *pIH;
    TOKEN_NUMBER *pFirst;
    TOKEN_NUMBER i, j, max;

    /* initialize to the beginning of gIterSpace */
    pIH = (IterHeader*) gIterSpace;
    pFirst = &gIterSpace[ITER_HEADER_SIZE];

    /* find the first inhibitor, by skipping all of the input arcs */
    while( pIH->arcType == IH_TYPE_NORMAL )
    {
        /* setup the next arc */
        IncrementIterHeader( &pIH, &pFirst );
    }

    /* while there are more inhibitors to check */
    while( pIH->arcType == IH_TYPE_INHIBIT )
    {
        /* NOTE: the inside of this block is the same as the tokencombination function */
        /* set the max to the maximum element number which can be represented by this element */
        max = pIH->howMany - 1;

        /* count backwards through the elements */
        for( i=(pIH->weight-1); i>-1; i-- )
        {
            /* if the element is less than the max, then success */
            if( pFirst[i] < max )
            {
                /* add one to this element */
                pFirst[i]++;
                /* reset all the ones following this element */
                for( j=i+1; j<pIH->weight; j++ )
                {
                    pFirst[j] = pFirst[i] + j - i;
                }

                /* now return success, because the next combination has been selected */
                return TRUE;
            }


            /* the max of the previous item must be max-- */
            max--;
        }

        /* setup the next arc */
        IncrementIterHeader( &pIH, &pFirst );
    }


    return FALSE;
}


TOKEN_SIZE
CalculateInputArcNumberOfColors( NCTArc *pArc, BOOLEAN *pbUnknown );
TOKEN_SIZE
CalculateInputArcNumberOfColors( NCTArc *pArc, BOOLEAN *pbUnknown ) {
/*
	calculate the number of colors which must be contained in a token
	to be matched by this arc.  note that since this function is only necessary
	for the input arcs, it does not check if the arc lengths are unknown
	because of an intemediate value, but instead calculates them for the entire arc.
	If the arc size is unknown, then pbUnknown is set to true, and the returned
	value is the MINIMUM required size for using this arc
*/
	int i;
	int iTotal=0;
	TOKEN_SIZE uLast;
	if( pArc == NULL || pbUnknown==NULL  || pArc->colorCount<0 )
		logerror("CalculateInputArcNumberOfColors bad data");
	*pbUnknown = FALSE;
    /* check for special case of uncolored arc */
    if( pArc->colorCount==0 )
        return 0;
	for( i=0; i<pArc->colorCount-1; i++ ) {
		/* don't do much error checking here, just add the sizes of the arc
		colors, and then add them to the running total */
		iTotal += pArc->color[i].size;
	}
	/* last one */
	uLast = pArc->color[pArc->colorCount-1].size ;
	if( uLast == UNKNOWN_SIZE ) {
		iTotal++;
		*pbUnknown = TRUE;
	} else
		iTotal += uLast;
	return iTotal;
}

BOOLEAN CheckInputArcs()
{
/*
    check the token combination of input arcs (non-inhibitors), to ensure that it is valid
    return TRUE if enabled conditions are met, FALSE otherwise
*/
    BOOLEAN bSuccess = TRUE;
    IterHeader *pIH;
    TOKEN_NUMBER *pFirst, i;
    TOKEN_SIZE j;
    Token *pToken;
    CONDITIONAL_CONST NCTArc *pArc;
    CONDITIONAL_CONST ArcColor *pColor;
    int iTestMerge;
	BOOLEAN bUnknown;
	TOKEN_SIZE uSize, uColorIndex, k, uTotalSize;

    /*
    	NOTE: this function is currently being changed to check the values
    	at runtime rather than at generation time, to allow pointers to the
    	same areas of memory.  However, for now the generated code is being
    	used to verify that the memlist code is working correctly
    */
    /*
    	first we will clear the current memlist, which contains the
    	arc colors from the last transition
     */
    memlist_clear();

    /* initialize to the beginning of gIterSpace */
    pIH = (IterHeader*) gIterSpace;
    pFirst = &gIterSpace[ITER_HEADER_SIZE];

    /* for each input arc (there may be none)
    	and they are followed by the inhibitors
    */
    while( pIH->arcType == IH_TYPE_NORMAL )
    {
        /* get a pointer to the arc */
        pArc = &net.tran[net.tranCurrent].inputArc[pIH->arcNumber];

        /* for each of the (known to be non-zero) weight of the input arc */
        for( i=0; i<pIH->weight; i++ )
        {
            /* get the pointer to the token (to compare the color) */
            pToken = PlacePeekTokenNum( &net.place[pIH->place], pFirst[i] );

            /* first check to see if the token has the right number of colors
				for the arc */
			uTotalSize = CalculateInputArcNumberOfColors( pArc, &bUnknown );
			if( bUnknown ) {
				if( pToken->count < uTotalSize )
					return FALSE;
			}
			else {
		        if( pToken->count != uTotalSize )
			        return FALSE;
			}

            /* for each color of the arc */
			uColorIndex = 0;
            for( j=0; j<pArc->colorCount; j++ )
            {
                /* assign the color from the current arc */
                pColor = &pArc->color[j];
				uSize = pColor->size;

				/* if the size is unknown, then calculate it */
				if( uSize == 0 ) {
					if( j==pArc->colorCount-1 ) {
						uSize = pToken->count - uColorIndex ;
					} else
						logerror("CheckInputArcs invalid data");
				}

                /* store in the memlist, determining the compare flag */
                if( pColor->flags & VALUE_FLAG ) {
                    /* compare to the VALUE of the var item, for each of the length */
					for( k=0; k<uSize; k++ )
						if( ((TOKEN_VALUE)pColor->var) != TokenGetColorNum( pToken, k+uColorIndex ) )
							return FALSE;
				} else {

					/* check for the don't care condition, if the variable pointer
						happens to be null */
					if( pColor->var != NULL ) {

						/* for now assume all the size of the token value */
						iTestMerge = memlist_merge( pColor->var, &pToken->value[uColorIndex], uSize);
						switch( iTestMerge ) {
						case MERGE_NOMATCH:
		                    /* write */
							for( k=0; k<uSize; k++ )
	    						pColor->var[k] = TokenGetColorNum( pToken, k+uColorIndex );
							break;
						case MERGE_SAME:
							/* do nothing, continue to compare */
							break;
						case MERGE_DIFF:
							return FALSE;
							break;
						default:
							/* if( iTestMerge == MERGE_ERROR ) */
							logerror("inputarcs: problem with memlist_merge");
						} /* endswitch */
					}	 /* endif != null */
				} /* endif value_flag */

                /* increment the index */
				uColorIndex += uSize;
            }

        }

        /* set pIH to next arc */
        IncrementIterHeader( &pIH, &pFirst );
    }

    return bSuccess;
}


/*
    check the current token combination of input arcs (inhibitors), to ensure that it is valid
    return TRUE if enabled conditions are met, FALSE otherwise
    in other words, if an inhibitor is set, then return FALSE
    NOTE: this function is very similar to CheckInputArcs
*/
BOOLEAN CheckInhibitArcs()
{
    BOOLEAN bSuccess = TRUE;
    IterHeader *pIH;
    TOKEN_NUMBER *pFirst, i;
    TOKEN_SIZE j;
    Token *pToken;
    CONDITIONAL_CONST NCTArc *pArc;
    CONDITIONAL_CONST ArcColor *pColor;
	BOOLEAN bUnknown;
	TOKEN_SIZE uSize, uColorIndex, k, uTotalSize;

    int iTestMerge;

    /*
    	NOTE: this function is currently being changed to check the values
    	at runtime rather than at generation time, to allow pointers to the
    	same areas of memory.  However, for now the generated code is being
    	used to verify that the memlist code is working correctly
    */
    /*
    	we don't clear the memlist here, becuase we are using the memlist
    	from the current non-inhibitors.  See CheckAll... the calling
    	function, for the call to memlist_restore before calling
     */

    /* initialize to the beginning of gIterSpace */
    pIH = (IterHeader*) gIterSpace;
    pFirst = &gIterSpace[ITER_HEADER_SIZE];

    /* find the first inhibitor, by skipping all of the input arcs */
    while( pIH->arcType == IH_TYPE_NORMAL )
    {
        /* setup the next arc */
        IncrementIterHeader( &pIH, &pFirst );
    }

    /* while there are more inhibitors to check */
    while( pIH->arcType == IH_TYPE_INHIBIT )
    {
        BOOLEAN bCurrentArcInhibits = TRUE;

        /* get a pointer to the arc */
        pArc = &net.tran[net.tranCurrent].inputArc[pIH->arcNumber];

        /* first check to see if the place has enough tokens to be inhibiting */
        if( pIH->howMany < pIH->weight )
            bCurrentArcInhibits = FALSE;
        else
        {
            /* for each of the (known to be non-zero) weight of the input arc */
            for( i=0; i<pIH->weight; i++ )
            {
                /* get the pointer to the token (to compare the color) */
                pToken = PlacePeekTokenNum( &net.place[pIH->place], pFirst[i] );

				/* first check to see if the token has the right number of colors
					for the arc */
				uTotalSize = CalculateInputArcNumberOfColors( pArc, &bUnknown );
				if( bUnknown ) {
					if( pToken->count < uTotalSize )
						break;
				}
				else {
					if( pToken->count != uTotalSize )
						break;
				}

                /* compare each color in this token */
				uColorIndex=0;
                for( j=0; j<pArc->colorCount; j++ )
                {
                    /* assign the color */
                    pColor = &pArc->color[j];
					uSize = pColor->size;

					/* if the size is unknown, then calculate it */
					if( uSize == 0 ) {
						if( j==pArc->colorCount-1 ) {
							uSize = pToken->count - uColorIndex ;
						} else
							logerror("CheckInhibitArcs invalid data");
					}

	                /* store in the memlist, determining the compare flag */
	                if( pColor->flags & VALUE_FLAG ) {
						for( k=0; k<uSize; k++ )
							if( ((TOKEN_VALUE)pColor->var) != TokenGetColorNum( pToken, k+uColorIndex ) ) {
								bCurrentArcInhibits = FALSE;
								break;
							}
						if( bCurrentArcInhibits )
							break;
					} else {

						/* check for the don't care condition, if the variable pointer
							happens to be null */
						if( pColor->var != NULL ) {
							/* for now assume all the size of the token value */
							iTestMerge = memlist_merge( pColor->var, &pToken->value[uColorIndex], uSize );
							if( iTestMerge == MERGE_NOMATCH ) {
		                        /* write */
								for( k=0; k<uSize; k++ )
									pColor->var[k] = TokenGetColorNum( pToken, k+uColorIndex );
							} else if( iTestMerge == MERGE_DIFF ) {
	                            bCurrentArcInhibits = FALSE;
								break; /* break out of for loop, because compare failed */
							} else if( iTestMerge == MERGE_SAME ) {
								/* do nothing */
							} else {
								/* error or unknown return value */
								/* if( iTestMerge == MERGE_ERROR ) */
								logerror("InhibitArcs: problem with memlist_merge");
							}
						} /* endif var != null */
					}

					uColorIndex += uSize;

                } /* end loop for all colors */

            } /* end loop for all weights */
        } /* end else */

        /* if all the weights match, then the transition is inhibited */
        if( bCurrentArcInhibits == TRUE )
            return FALSE;

        /* set pIH to next arc */
        IncrementIterHeader( &pIH, &pFirst );
    }

    return bSuccess;
}

/*
    check the token combination of non-inhibitors with all combination of tokens
    in the inhibitors
    return TRUE if enabled conditions are met, FALSE otherwise
*/
BOOLEAN CheckAllInhibitorCombinations()
{
    /* set up initial inhibitor combination,
        this is necessary if we make a call to this function twice without
        initializing the token combination in between */

	/* first backup the information from the current input arcs */
	memlist_backup();

    if( SetupInitialInhibitCombination() )
    {

        do {
        	/* restore the memlist from the non-inhibitors */
        	memlist_restore();

            /* while there are more inhibitors */
            if( CheckInhibitArcs() == FALSE )
                return FALSE;

        } while( SetupNextInhibitCombination() );
    }

    return TRUE;
}

/*
    check the current token combination to see if it enables the current transition
    return TRUE if it does, and FALSE if not
*/
BOOLEAN IsTokenCombinationEnabling()
{
    BOOLEAN bColorMatch=FALSE, bSuccess=FALSE;

    /*
        first check to see if the current token combination satisfies the
        condition of the input arcs (non-inhibitors)
    */
    bColorMatch = CheckInputArcs();

    /*
        if the first condition is met, then make sure that the condition is still
        met for ALL of the combinations of tokens at the inhibitor arcs

        it is not necessary to check the user enabling condition for each
        inhibitor arc, because the inhibitor arc adds no information to the
        user-defined function.
    */
    if( bColorMatch )
    {
        bColorMatch = CheckAllInhibitorCombinations();
    }

    if( bColorMatch )
    {
        /*
            if the tokens on the input arcs satisfy the arc conditions, then check if
            the current token combination also satisfies the user-defined enable function
            If there is one combination which is valid, then we can return true.
            If no combinations are valid, then return false.
        */
        if( net.tran[net.tranCurrent].EnableFunction )
        {
            bSuccess = (*net.tran[net.tranCurrent].EnableFunction)(net.tranCurrent);
        }
        else
            /* since there is no user function, the combination does satisfy the requirements */
            bSuccess = TRUE;
    }
    else
        bSuccess = FALSE;

    return bSuccess;
}


/*
    FIRING FUNCTIONS:   to be placed in fire.c
        these are new firing functions to allow working with colored petri nets
        they are based on the knowledge of the functions used for checking the enabling of
        colored petri nets
*/

long CalculateFifoValue()
{
    /* this function calculates a FIFO-ness of the current marking
        as a simple sum of the location of the chosen tokens in each of the fifo places
        which are used as inputs

        it should work for last-in-first-out (lifo) also, because the only difference is that
        tokens are placed in the front, not in the back of the list.  So therefore we should
        let it work for both.

        speed could be increased by skipping this function when there
        are no fifo places as an input to the current transition
        and some additional (though probably less) speed could be gained
        by including the fifo property of the place within the giterspace */

    /* set up the iterspace */
    IterHeader *pIH;
    TOKEN_NUMBER *pFirst, i;
    CONDITIONAL_CONST NCTArc *pArc;
    long lFifoValue=0;

    /* initialize to the beginning of gIterSpace */
    pIH = (IterHeader*) gIterSpace;
    pFirst = &gIterSpace[ITER_HEADER_SIZE]; /* set up pFirst to point to the first token number associated with
                                                the current place */

    /* for each input arc (there may be none)
        and fifo value is only meaningful for the normal arcs, not inhibitors
        we may return a fifo value of zero if there are no fifo input arcs
    */
    while( pIH->arcType == IH_TYPE_NORMAL )
    {
        /* get a pointer to the arc */
        pArc = &net.tran[net.tranCurrent].inputArc[pIH->arcNumber];

        /* if the place is FIFO or LIFO */
        if( net.place[pIH->place].policy == FIFO
            || net.place[pIH->place].policy == LIFO )
        {

            /* for each of the (known to be non-zero) weight of the input arc */
            for( i=0; i<pIH->weight; i++ )
            {
                /* add the number of the token which is selected to the
                    fifo value, so that we will have a badness value for the marking */
                lFifoValue += pFirst[i];
            }

        } /* end if firing policy is fifo or lifo */


        /* set pIH to next arc */
        IncrementIterHeader( &pIH, &pFirst );

    }

    return lFifoValue;
}

/*
    choosing a token combination to fire
        in order to choose fairly between all of the enabling conditions, we will check all
        of the enabling conditions for the transition which has been chosen to fire, and then
        we will fire it.

    NOTE: this function is VERY inefficient, because in order to save space it sacrifices speed
        all token enabling conditions are checked, and a number is found for the number of possibilities.
        One of these possibilities is chosen, and that one is used.
*/
void ChooseCombinationToFire()
{
    /*
        this function has now been changed from simply choosing equally between all combinations
        to also taking into account if the input places are fifo.  If some of the input places
        are fifo, then a weight is given to the fifo-ness of a marking.  The enabling markings
        with minimum fifo value are the ones which are chosen for firing combination

    */
    long lTake;
    long lValid = 0;
    long lFifoValue=0, lFifoCount=0;
	long i;
	TRANS_NUMBER thisTran;
	thisTran = net.tranCurrent;

    if( SetupInitialTokenCombination() )
    {
        long lCurrentFifoValue;

		/*
			special case if the transition has a time function
		*/
		if( net.tran[thisTran].TimeFunction ) {
			long lCombo=net.tran[thisTran].lFirstCombo;
			/* now just setup the transition combination */
			for( i=0; i<lCombo; i++ )
				SetupNextTokenCombination();
			/* sanity check to make sure that the combination is still enabling */
			if( !IsTokenCombinationEnabling() )
				logerror("ChooseCombinationToFire: problem with TimeFunction");
			return;
		}
        /*
            now loop on the condition that there are still more combinations to be tried before
            all of the combinations are exhausted
        */
        do {

            if( IsTokenCombinationEnabling() )
            {
                lCurrentFifoValue = CalculateFifoValue();
                if( lFifoCount == 0 )
                {
                    /* this is the first enabling marking */
                    lFifoValue = lCurrentFifoValue;
                    lFifoCount = 1;

                    /* if the mode is set to fast, then select this marking immediately */
                    if( net.mode == RUN_FAST )
                        break;
                }
                else if( lCurrentFifoValue == lFifoValue )
                {
                    /* the current marking is equal to the previous values */
                    lFifoCount++;
                }
                else if( lCurrentFifoValue < lFifoValue )
                {
                    /* this marking is better than any previous */
                    lFifoValue = lCurrentFifoValue;
                    lFifoCount = 1;
                }
                /*
                else if( lCurrentFifoValue > lFifoValue )
                {
                     the current marking is worse than those already found
                     do nothing, because it is not a desired value
                }
                */
            }

        } while (SetupNextTokenCombination());
    }

    /* sanity check  */
    if( lFifoCount == 0 )
    {
        logerror( "ChooseCombinationToFire, no enabling tokens!" );
    }

    /* calculate the element to take */
    lTake = (long) ((double)lFifoCount * (double) rand() /  ((double)RAND_MAX+1));

    /* now find the proper element */
    lValid = 0;
    SetupInitialTokenCombination();

    do {

        if( IsTokenCombinationEnabling() )
        {
            if( CalculateFifoValue() == lFifoValue )
            {
                /* the lTake-th element has been found */
                if( lValid == lTake )
                    return;

                lValid++;
            }
        }
    } while (SetupNextTokenCombination());

}

/*
    firing the transition

        once the proper token enabling condition has been chosen, the necessary information can be
        found in the gIterList.  Since the higher token numbers are later in the list for each input
        place, removing them will not change the previous numbers.  This creates a very simple method
        for removing the tokens.
            while there are input places
                for i=weight-1; i>=0; i--
                    remove token i from current place

        adding the proper tokens to the output places is straight-forward.  Create each output token
        based on the output arcs of the transition
*/
/*****************************************************************************************/
/*  This function calls the appropriate firing function for a given transition.  This is */
/*  accomplished via a function pointer to a firing functions.  This is where a user     */
/*  defined firing function would get called.                                            */
/*****************************************************************************************/
void PreFire(void);
void PostFire(void);

void Fire()
{
/* essential to make enable functions work */
net.tranCurrent=net.tranToFire;

/* choose one of the enabling token combinations to fire */
ChooseCombinationToFire();

/* remove tokens from the input places */
PreFire();

/* call the user-defined fire function, if any */
if( net.tran[net.tranCurrent].FireFunction )
    (*net.tran[net.tranCurrent].FireFunction)(net.tranCurrent);

/* place tokens in the output places */
PostFire();

/* disable the transition, because it was fired
    if it is already reenabled, it will be checked
    with all the rest on the next round, because it was fired */
DisableTransition(net.tranToFire, TRUE);

/* Keeps track of # firings at each tran */
net.tran[net.tranToFire].numOfFirings++;

logprintf("\n****Transition #%2d was fired****",net.tranToFire);
}

void PreFire()
{
    /* remove all of the enabling tokens from the input places */
    IterHeader *pIH;
    TOKEN_NUMBER *pFirst, i;
    Token *pToken;
    Place *pPlace;

    /* initialize to the beginning of gIterSpace */
    pIH = (IterHeader*) gIterSpace;
    pFirst = &gIterSpace[ITER_HEADER_SIZE];

    /* for each input arc (there may be none) */
    while( pIH->arcType == IH_TYPE_NORMAL )
    {
        /* set up the place number */
        pPlace = &net.place[pIH->place];

        /* for each of the elements in the list, remove and delete the tokens */
        for( i=pIH->weight-1; i>=0; i-- )
        {
            pToken = PlaceRemoveTokenNum( pPlace, pFirst[i] );
            DeleteToken( pToken );
        }

        /* set pIH to next arc */
        IncrementIterHeader( &pIH, &pFirst );
    }
}

void PostFire()
{
    /* place new tokens in all of the output places, based on the current state of the
        global variables */
    ARC_NUMBER max, i;
    TOKEN_NUMBER j;
    TOKEN_SIZE k,kColor;
    Token *pToken, *pTokenClone;
	TOKEN_SIZE uSize,l;
    FLAGS flags;
    TOKEN_VALUE* pVar;
    CONDITIONAL_CONST NCTArc* output;

    /* setup the local variables to work with the current transition */
    output = net.tran[net.tranCurrent].outputArc;
    max = net.tran[net.tranCurrent].outputCount;

    /* for each output arc */
    for( i=0; i<max; i++ ) {
		if( output[i].weight <= 0 ) {
			logerror("PostFire: output arc of weight less than one found");
			continue;
		}
		/* do once, and then clone the token */
        /* create a token */
        pToken = NewToken();

		/* we used to do this color assignment in reverse, because it reduced the number
			of calls necessary to malloc/realloc.  We no longer do this, because it
			would require going through first and counting the number of elements
			in the arc first */
		for( k=0,kColor=0; k<output[i].colorCount; k++ ) {
				/* get the standard values for this color vector */
                flags = output[i].color[k].flags;
                pVar = output[i].color[k].var;
				uSize = output[i].color[k].size;
				/* if the size is unknown, then find it */
				if( uSize == UNKNOWN_SIZE )
					uSize = memlist_LookupSize( pVar );
				/* if the color is a value, and not a pointer, ignore the compare flag */
				if( flags & VALUE_FLAG ) {
					for( l=0; l<uSize; l++ ) {
						TokenSetColorNum( pToken, kColor, (TOKEN_VALUE)pVar );
						kColor++;
					}
				} else {
					if( pVar == NULL )
						logerror("PostFire, invalid arc color vector found");
					else {
						for( l=0; l<uSize; l++ ) {
							TokenSetColorNum( pToken, kColor, pVar[l] );
							kColor++;
						}
					}
				}
		}
		/* add the first token to the output place */
        PlaceAddToken( &net.place[output[i].place], pToken );

		/* for each of the successive weights, use the original list */
		for( j=1; j<output[i].weight; j++ ) {
			pTokenClone = TokenClone(pToken);
            PlaceAddToken( &net.place[output[i].place], pTokenClone );
		}

    }
}


