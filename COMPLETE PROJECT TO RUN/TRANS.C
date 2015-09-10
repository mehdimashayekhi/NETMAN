/*
    NETCODE colored petri net simulator
    source file for manipulating transitions

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/TRANS.C,v 1.98 1995/11/14 13:36:49 gilem Exp $
*/
#define SUPER_USER
#include "petri.h"

/* functions to get the proper input arcs */
int TransGetNumInputArcs( void )
{
	return net.tran[net.tranCurrent].inputCount;
}

int TransGetNumOutputArcs ( void )
{
	return net.tran[net.tranCurrent].outputCount;
}

CONDITIONAL_CONST NCTArc* TransGetInputArcByIndex( ARC_INDEX index )
{
	TRANS_NUMBER tran;
	ARC_NUMBER i;
		
	tran=net.tranCurrent;

	/* check all of the input arcs for the particular index */
	for (i=0; i<net.tran[tran].inputCount; i++)
	    {
	    if (index == net.tran[tran].inputArc[i].index)
	        {
			return &net.tran[tran].inputArc[i];
	        }
	    }
	    
	return NULL;
}

CONDITIONAL_CONST NCTArc* TransGetOutputArcByIndex( ARC_INDEX index )
{
	TRANS_NUMBER tran;
	ARC_NUMBER i;
	
	tran=net.tranCurrent;
	
	/* check all of the input arcs for the particular index */
	for (i=0; i<net.tran[tran].outputCount; i++)
	    {
	    if (index == net.tran[tran].outputArc[i].index)
	        {
	        return &net.tran[tran].outputArc[i];
	        }
	    }
	    
	return NULL;
}

CONDITIONAL_CONST NCTArc* TransGetInputArcByOrder( ARC_NUMBER num )
{
	Transition* pTrans;
	
	pTrans = &net.tran[net.tranCurrent];
	
	/* lookup the input arc, starting at zero */
	if( num <= pTrans->inputCount )
	{
		return &pTrans->inputArc[num];
	}
	else
		return NULL;
}

CONDITIONAL_CONST NCTArc* TransGetOutputArcByOrder( ARC_NUMBER num )
{
	Transition* pTrans;
	
	pTrans = &net.tran[net.tranCurrent];
	
	/* lookup the input arc, starting at zero */
	if( num <= pTrans->outputCount )
	{
		return &pTrans->outputArc[num];
	}
	else
		return NULL;
}

/******************************************************************************************/
/*  This function returns the address of a input place connected to the current transition*/
/*  via the arc index.  The place address can then be used to access any information      */
/*  contained within that place.                                                          */
/******************************************************************************************/
Place* TransGetInputPlace(ARC_INDEX index)
{
	PLACE_NUMBER place;
	CONDITIONAL_CONST NCTArc* theArc;
	
	theArc = TransGetInputArcByIndex( index );
	
	if( theArc )
	{
		/* since we found the place, then return its pointer */
		place=theArc->place;
		return &net.place[place];
	}
	else
		return NULL;
	
}

/*******************************************************************************************/
/*  This function returns the address of a output place connected to the current transition*/
/*  via the arc index.  The place address can then be used to access any information       */
/*  contained within that place.                                                           */
/*******************************************************************************************/
Place* TransGetOutputPlace(ARC_INDEX index)
{
	PLACE_NUMBER place;
	CONDITIONAL_CONST NCTArc* theArc;
	
	theArc = TransGetOutputArcByIndex( index );
	
	if( theArc )
	{
		place = theArc->place;
		return &net.place[place];
	}
	else
		return NULL;
}

/*****************************************************************************************/
/*  This simple function returns the type of a transition                                */
/*****************************************************************************************/
TRANS_TYPE GetTransitionType(TRANS_NUMBER tran)
{
return net.tran[tran].type;
}

/*****************************************************************************************/
/*  This simple function sets the type of a transition                                   */
/*****************************************************************************************/
void SetTransitionType(TRANS_NUMBER tran, TRANS_TYPE type)
{
net.tran[tran].type=type;
}

/*****************************************************************************************/
/*  This simple function returns the a transitions time to fire                          */
/*****************************************************************************************/
double GetTransitionTimeToFire(TRANS_NUMBER tran)
{
return net.tran[tran].timeToFire;
}

/*****************************************************************************************/
/*  This simple function sets a transition's time to fire                                */
/*****************************************************************************************/
void SetTransitionTimeToFire(TRANS_NUMBER tran,double time)
{
net.tran[tran].timeToFire=time;
}

/*****************************************************************************************/
/*  This simple function returns the a transitions reset time                            */
/*****************************************************************************************/
double GetTransitionResetTime(TRANS_NUMBER tran)
{
return net.tran[tran].resetTime;
}

/*****************************************************************************************/
/*  This simple function sets a transition's reset time                                  */
/*****************************************************************************************/
void SetTransitionResetTime(TRANS_NUMBER tran,double time)
{
net.tran[tran].resetTime=time;
}

