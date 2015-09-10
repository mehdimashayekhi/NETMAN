/*
    NETCODE colored petri net simulator
    source file for initializing the petri net

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/INIT.C,v 2.11 1996/04/17 03:02:39 gilem Exp $
*/
#define SUPER_USER
#include "petri.h"

/*
    restore the net to its initial marking
*/
void SetInitialMarking()
{
    ClearMarking();
    InitialMarking();
}

void InitializeNet()
{
#ifndef CONST_NET
    ZeroPetri();
    DefineNet();
#endif

    InitStats(TRUE);

#ifndef CONST_NET
    AddPlacePointers();
#endif

	/* check some properties of the net, to ensure that they are not wrong */
	CheckProperties();

    /* now set the initial marking */
    SetInitialMarking();


    PrintState();
    FindAllEnabled();
    MakeInitialEnabledList();
    PrintEnabled();

}

#ifndef CONST_NET
/*****************************************************************************************/
/*  This function intializes the Petri net network.                                      */
/*****************************************************************************************/
void ZeroPetri(void)
{
net.place=NULL;
net.tran=NULL;
net.tranToFire=0;
net.tranCurrent=0;
net.totalTime=0.0;
net.lastTime=0.0;
net.placeCount=0;
net.tranCount=0;
net.enabledCount=0;
net.enabledList=NULL;
net.equalList=NULL;
}
#else
    extern PetriNet net;
#endif /* CONST_NET */



void
CheckProperties(void) {
/*
	check the net structure for errors by NETMAN, or from modeling errors by the
	user.
*/

/*
	the first problem which we will look for is that of variable transition times.
	If this feature is being used, we are currently restricted to FIFO input places.
*/
	TRANS_NUMBER t;
	ARC_NUMBER a;
	Transition *pTrans;
	for( t=0; t<net.tranCount; t++ ) {
		/* for each transition which has a time function */
		pTrans = &net.tran[t];
		if( pTrans->TimeFunction != NULL ) {
			/* each input arc must be FIFO */
			for( a=0; a<pTrans->inputCount; a++ ) {
				if( net.place[pTrans->inputArc[a].place].policy != FIFO ) {
					logerror("Transition %d is not allowed to have a time function and non-fifo input places");
				}
			}
		}
	}
}
