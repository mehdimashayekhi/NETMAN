/*
    NETCODE colored petri net simulator
    source file for allocating a petri net dyamically, rather than as const objects

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/MEMORY.C,v 2.17 1996/05/05 02:05:56 gilem Exp $
*/
#define SUPER_USER
#include "petri.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef CONST_NET

/*
    initialize a place on dynamic creation 
*/
void InitPlace( PLACE_NUMBER place, char* szName, PLACE_NUMBER pnNumSize, PlacePolicy policy )
{
    int iLengthName;
    iLengthName = strlen(szName);
    if( iLengthName > 0 ) 
    {
        net.place[place].name = (char*)malloc( sizeof(char)*iLengthName+1 );
        if( !net.place[place].name )
        {
        	logerror("initplace: could not allocate name");
    		CloseLogFile();
        	return;
        }
        strcpy( net.place[place].name, szName );
    }
    else 
        net.place[place].name = 0;

    if( pnNumSize > 0 )
    {
        net.place[place].number = (PLACE_NUMBER*)malloc( sizeof(PLACE_NUMBER)*pnNumSize );
        if( !net.place[place].number )
        {
        	logerror("initplace: could not allocate number");
    		CloseLogFile();
       		return;
        }
        net.place[place].number[0] = pnNumSize-1;
    }
    else
        net.place[place].number = 0;

    net.place[place].policy = policy;
    /* zero out other arguments (other than stats) */
    net.place[place].tokenCount = 0;
    net.place[place].tokenList = NULL;
    net.place[place].outputCount = 0;
    net.place[place].outputTran = NULL;
}

/*
    initialize a dynamically allocated transition 
*/
void InitTransition( TRANS_NUMBER trans, char* szName, PLACE_NUMBER pnNumSize, TRANS_TYPE type, double dResetTime,
                    ARC_NUMBER anIn, ARC_NUMBER anOut, 
                    FireFunctionPtr pfFire, EnableFunctionPtr pfEnable, TimeFunctionPtr pfTime )
{
    Transition *pTrans;
    int iLengthName;

    pTrans = &net.tran[trans];
    iLengthName = strlen(szName);
    
    if( iLengthName > 0 )
    {
        pTrans->name = (char*)malloc( sizeof(char)*iLengthName+1 );
        if( !pTrans->name )
        {
        	logerror("InitTransition: could not allocate name");
    		CloseLogFile();
        	return;
        }
        strcpy( pTrans->name, szName );
    }
    else
        pTrans->name = 0;

    if( pnNumSize > 0 )
    {
        pTrans->number = (PLACE_NUMBER*)malloc( sizeof(PLACE_NUMBER)*pnNumSize );
        if( !pTrans->number )
        {
        	logerror("InitTransition: could not allocate number");
    		CloseLogFile();
        	return;
        }
        pTrans->number[0] = pnNumSize-1;
    }
    else
        pTrans->number = 0;

    pTrans->type = type;
    pTrans->inputCount = anIn;
    if( anIn > 0 )
    {
        pTrans->inputArc = (NCTArc*)malloc( sizeof(NCTArc)*anIn );
        if( !pTrans->inputArc )
        {
        	logerror("InitTransition: could not allocate input arc");
    		CloseLogFile();
        	return;
        }    
    }
    else
        pTrans->inputArc = 0;

    pTrans->outputCount = anOut;
    if( anOut > 0 )
    {
        pTrans->outputArc = (NCTArc*)malloc( sizeof(NCTArc)*anOut );
        if( !pTrans->outputArc )
        {
        	logerror("InitTransition: could not allocate output arc");
    		CloseLogFile();
       		return;
        }    
    }
    else
        pTrans->outputArc = 0;

    pTrans->FireFunction = pfFire;
    pTrans->EnableFunction = pfEnable;
	pTrans->TimeFunction = pfTime;

    /* now initialize other values also */
    pTrans->resetTime = dResetTime;
}

void InitArc( NCTArc *pArc, TOKEN_NUMBER weight, PLACE_NUMBER place, ARC_INDEX index, TOKEN_SIZE colorCount )
{
    pArc->weight = weight;
    pArc->place = place;
    pArc->index = index;
    pArc->colorCount = colorCount;

    if( colorCount > 0 )
    {
        pArc->color = (ArcColor*)malloc( sizeof(ArcColor)*colorCount );
        if( !pArc->color )
        {
        	logerror("InitArc: could not allocate color");
    		CloseLogFile();
       		return;
        }
    }
    else
        pArc->color = 0;
}

/*
    support functions only to be used within this file
*/
void PlaceAddOutputTransition( PLACE_NUMBER place, TRANS_NUMBER trans );
void PlaceAddOutputTransition( PLACE_NUMBER place, TRANS_NUMBER trans )
{
    /* store the working values temporarily */
    Place* ptrPlace;
    ptrPlace = &net.place[place];

    /* check to see if the place has a list of output transitions */
    if( ptrPlace->outputCount == 0 )
        ptrPlace->outputTran = (TRANS_NUMBER*)calloc( 1, sizeof(TRANS_NUMBER) );
    else
        ptrPlace->outputTran =  (TRANS_NUMBER*)realloc( (void*)ptrPlace->outputTran,
            (ptrPlace->outputCount+1)*sizeof(TRANS_NUMBER) );


    if( !ptrPlace->outputTran )
    {
    	logerror("PlaceAddOutputTransition: could not allocate outputTran");
		CloseLogFile();
   		return;
    }
    
    /* now add the transition to the array */
    ptrPlace->outputTran[ptrPlace->outputCount] = trans;

    /* now add one to the number in the array */
    ptrPlace->outputCount++;
}

/*
    set up the global net structure for the given number of places and transitions
    return true on success, false on fail
*/
BOOLEAN DimensionNet(PLACE_NUMBER nPlaces, TRANS_NUMBER nTransitions)
{
    net.placeCount=nPlaces;
    net.tranCount=nTransitions;
    /* use calloc instead of malloc, because it initializes the block to 0 */
    /* initialize all of the pointers in the net structure */
    if( nPlaces )
    {
        net.place=(Place*)calloc( nPlaces, sizeof(Place));
	    if( !net.place )
	    {
	    	logerror("DimensionNet: could not allocate place");
			CloseLogFile();
		    return FALSE;
	    }
    }

    if( nTransitions )
    {
        net.tran=(Transition*)calloc( nTransitions, sizeof(Transition));
        if( !net.tran )
	    {
	    	logerror("DimensionNet: could not allocate trans");
			CloseLogFile();
            return FALSE;
	    }
        net.enabledList=(PLACE_NUMBER*)calloc( nTransitions, sizeof( TRANS_NUMBER));
        if( !net.enabledList )
	    {
	    	logerror("DimensionNet: could not allocate enabledList");
			CloseLogFile();
            return FALSE;
	    }
        net.equalList=(PLACE_NUMBER*)calloc( nTransitions, sizeof( TRANS_NUMBER));
        if( !net.equalList )
	    {
	    	logerror("DimensionNet: could not allocate equalList");
			CloseLogFile();
            return FALSE;
	    }
    }

    return TRUE;
}


BOOLEAN TransitionDimension( TRANS_NUMBER tNo, ARC_NUMBER nInput, ARC_NUMBER nOutput )
{
    /* allocate the proper space for the transition in question
        return true on success, or false on fail */
    Transition* ptrT;
    ptrT = &net.tran[tNo];

    /* first ensure that there is nothing already there
        if so, free the arcs */
    if( ptrT->inputArc != 0
        || ptrT->outputArc != 0 )
    {
        logerror("transition %d already dimensioned", tNo );
        return FALSE;
    }

    /* now allocate the space */
    /* use calloc, to initialize space to zero first */
    ptrT->inputCount = nInput;
    ptrT->outputCount = nOutput;

    if( nInput )
    {
        ptrT->inputArc = (NCTArc*)calloc( nInput, sizeof(NCTArc) );
        if( !ptrT->inputArc )
	    {
	    	logerror("TransitionDimension: could not allocate inputArc");
			CloseLogFile();
            return FALSE;
	    }
    }

    if( nOutput )
    {
        ptrT->outputArc = (NCTArc*)calloc( nOutput, sizeof(NCTArc) );
        if( !ptrT->outputArc )
	    {
	    	logerror("TransitionDimension: could not allocate outputArc");
			CloseLogFile();
            return FALSE;
	    }
    }

    return TRUE;
}


/*
    check all the pointers for global problems, as well as building all of the lists
    of output transition numbers for each place which it is connected to.
*/
BOOLEAN AddPlacePointers( )
{
/*  since the DimensionNet function zeros out all of the memory blocks, there is not
    much verification to do:

    DANGER: you must only call this function ONCE.  calling it a second time will
    screw up the place pointers
*/

/*  build a list of output transitions for each place */
TRANS_NUMBER t;
PLACE_NUMBER p;

/* for each transition */
for( t=0; t < net.tranCount; t++ )
{
    /* for each input place */
    for( p=0; p < net.tran[t].inputCount; p++ )
    {
        /* add this transition number 't' to the input place */
        PlaceAddOutputTransition( net.tran[t].inputArc[p].place, t );
    }
}

return TRUE;
}

#endif /* CONST_NET */

void FreePlace( PLACE_NUMBER pNo );
void FreePlace( PLACE_NUMBER pNo )
{
#ifndef CONST_NET
    /* free the array of output transitions */
    if( net.place[pNo].outputTran )
        free(net.place[pNo].outputTran);
    net.place[pNo].outputTran = 0;
    net.place[pNo].outputCount = 0;
    /* free the number and the name of the net */
    if( net.place[pNo].name )
    {
        free(net.place[pNo].name);
        net.place[pNo].name = 0;
    }
    if( net.place[pNo].number )
    {
        free(net.place[pNo].number);
        net.place[pNo].number = 0;
    }
#endif /* CONST_NET */
    
    /* free the memory associated with the tokens */
    PlaceClearMarking( &net.place[pNo] );
}

void FreeTransition( TRANS_NUMBER tNo );
void FreeTransition( TRANS_NUMBER tNo )
{
#ifndef CONST_NET
    int iArc;

    /* free the number and the name of the net */
    if( net.tran[tNo].name )
    {
        free(net.tran[tNo].name);
        net.tran[tNo].name = 0;
    }
    if( net.tran[tNo].number )
    {
        free(net.tran[tNo].number);
        net.tran[tNo].number = 0;
    }
    /* free each of the input and output arcs */
    for( iArc=0; iArc<net.tran[tNo].inputCount; iArc++ )
    {
        if( net.tran[tNo].inputArc[iArc].color != NULL )
        {
            free( net.tran[tNo].inputArc[iArc].color );
            net.tran[tNo].inputArc[iArc].color = 0;
            net.tran[tNo].inputArc[iArc].colorCount = 0;
        }
    }
    
    for( iArc=0; iArc<net.tran[tNo].outputCount; iArc++ )
    {
        if( net.tran[tNo].outputArc[iArc].color != NULL )
        {
            free( net.tran[tNo].outputArc[iArc].color );
            net.tran[tNo].outputArc[iArc].color = 0;
            net.tran[tNo].outputArc[iArc].colorCount = 0;
        }
    }

    /* free the arrays of input and output arcs */
    if( net.tran[tNo].inputArc )
        free(net.tran[tNo].inputArc);
    net.tran[tNo].inputArc = 0;
    net.tran[tNo].inputCount = 0;
    
    if( net.tran[tNo].outputArc )
        free(net.tran[tNo].outputArc);
    net.tran[tNo].outputArc = 0;
    net.tran[tNo].outputCount = 0;
#endif
}

/*
    clear the marking of the whole net 
*/                   
#include "dplayer.h"
void ClearMarking()
{
    PLACE_NUMBER i;      
    

    /* for each place */
    for (i=0; i<net.placeCount; i++)
    {
        PlaceClearMarking( &net.place[i] );
    }

}


/******************************************************************************************/
/*  This subroutine frees all of the memory allocated throughout the program.             */
/******************************************************************************************/
void FreeMemory(void)
{
    if( gIterSpace != NULL )
        free(gIterSpace);

    /***********Free Place Information*********/
    {
        PLACE_NUMBER i;
    
        /* for each place */
        for (i=0; i<net.placeCount; i++)
        {
            FreePlace( i );
        }

        #ifndef CONST_NET
        if( net.place )
            free(net.place);
        net.place = 0;
        net.placeCount = 0;
        #endif /* CONST_NET */
    }


#ifndef CONST_NET
    /***********Free Transition Information*********/
    {
        TRANS_NUMBER j;
    
        for (j=0; j<net.tranCount; j++)
        {
            FreeTransition( j );
        }
            
        /* finally free the array of transitions */
        if( net.tran )
            free(net.tran);
        net.tran = 0;
        net.tranCount = 0;
    }

    /******Free Network Information *********/
    if( net.enabledList )
        free(net.enabledList);
    net.enabledList = 0;
    
    if( net.equalList )
        free(net.equalList);
    net.equalList = 0;
    net.enabledCount = 0;

#endif /* CONST_NET */

	/* now free the memlist */
   memlist_clear();
}





