/*
    NETCODE colored petri net simulator
    source file for firing functions for a petri net

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/FIRE.C,v 2.11 1996/04/17 03:02:39 gilem Exp $
*/
#define SUPER_USER
#include "petri.h"
#include <stdio.h>
#include <stdlib.h>

/*****************************************************************************************/
/*  This function chooses the transition with the minimum remaining firing(RFT) time from*/
/*  the enabledList.  It stores transitions with equal RFTs in equalList.  If there are  */
/*  more than one transitions with equal RFTs, one is choosen randomly.                  */
/*****************************************************************************************/
void PickTransition(void)
{
TRANS_NUMBER tran,countEnabled,countEqual,i;
double min=1e25,time;

countEnabled=countEqual=i=0;
while (countEnabled!=net.enabledCount)
    {
    tran=net.enabledList[i];
    if (tran!=EMPTY)
        {
        countEnabled++;
        time=net.tran[tran].timeToFire;
        if (time==min)
            {
            net.equalList[countEqual]=tran;
            countEqual++;
            }
        if (time<min)
            {
            countEqual=1;
            net.equalList[0]=tran;
            min=time;
            }   
        }
    i++;
    }
    
tran=(TRANS_NUMBER)((double)countEqual*(double)rand()/((double)RAND_MAX+1.0));
net.tranToFire=net.equalList[tran];
}



/*****************************************************************************************/
/*  This simple function returns the firing time of a function. The time is calculated if*/
/*  necessary.  This is where other probabilistic distributions can be added to NETCODE. */
/*  This would be accomplished by defining another type of transition and writing a      */
/*  function that returned a time to fire based on the resetTime.  This would be very    */
/*  similar to the Exponential function                                                  */
/*****************************************************************************************/
double FiringTime(TRANS_NUMBER num)
{
/* 
	special case of transition with time function, where we need to 
	let the user calculate the time first.  We think that the EnableTransition 
	function is only called directly after CanBeEnabled, which calls IsCombinationEnabling.
	So when this function is called, we should have the proper setup.
*/
	/* iff the transition time function is defined */
	if( net.tran[num].TimeFunction ) 
		net.tran[num].resetTime = net.tran[num].TimeFunction(num);

    switch( net.tran[num].type )
    {
    case IMMEDIATE:
        /* immediate transitions are always ready to fire */
        return net.totalTime;
    
    case DETERMINISTIC:
        return (net.tran[num].resetTime+net.totalTime);

    case EXPONENTIAL:
        return (Exponential(net.tran[num].resetTime)+net.totalTime);

    default:
        logerror( "FiringTime: distribution type not yet supported" );
        return 0;
    }
}

/*****************************************************************************************/
/*  This function adjust the network due to the firing of a transition.  This includes   */
/*   adjusting the global time counternad the lastTime variables                         */
/*****************************************************************************************/
void AdjustNetwork(void)
{
net.totalTime=net.tran[net.tranToFire].timeToFire;      
net.lastTime=net.tran[net.tranToFire].timeToFire;
}


