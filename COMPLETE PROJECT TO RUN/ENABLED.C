/*
    NETCODE colored petri net simulator
    source file for enable functions

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/ENABLED.C,v 2.18 1996/05/06 04:14:23 gilem Exp $
*/
#define SUPER_USER
#include "petri.h"
#include <stdio.h>


/*************************************************************************************/
/*  This function checks for newly enabled or disabled transitions.  The transitions */
/*  which it checks are the ones which are connected to input places which might have*/
/*  been changed by the last firing.                                                 */
/*************************************************************************************/
void FindEnabled(void )
{
TRANS_NUMBER i,fire, tran;
PLACE_NUMBER j,place;
long lFirstCombo;

fire=net.tranToFire;
/*
	this function now performs a special check when the transition has a time function 
*/

/*******First Check if last fired transition is still enabled********/
if (CanBeEnabled(fire))
    {
    EnableTransition(fire);
    logprintf( "\n->>>>Enabling  Transition #%2d", fire );
    }
    
/*******Check if output of last transition fired enabled or disabled any other transitions*******/
/* Enabled <----Reduced marking of an inhibitor arc*/
/* Disabled <----Reduced marking of n input arc*/
for (i=0; i<net.tran[fire].outputCount; i++){
    place=net.tran[fire].outputArc[i].place;
    for (j=0; j<net.place[place].outputCount; j++){
        tran=net.place[place].outputTran[j];
        if (!IsEnabled(tran) && CanBeEnabled(tran))
            {
            EnableTransition(tran);
            logprintf( "\n->>>>Enabling  Transition #%2d", tran );
            }
        if (IsEnabled(tran)) {
			/* store the first enabling combo */
			lFirstCombo=net.tran[tran].lFirstCombo;
        	if( !CanBeEnabled(tran)) {
            	DisableTransition(tran, FALSE);
               	logprintf( "\n->>>>Disabling Transition #%2d", tran );
			} else if(
				net.tran[tran].TimeFunction != NULL
				&& lFirstCombo!=net.tran[tran].lFirstCombo){
			/* can also be disabled by changing the enabling marking */
            	DisableTransition(tran, FALSE);
               	logprintf( "\n->>>>Disabling Transition #%2d", tran );
			}
        }
    }
}

/*******Check if input of last transition fired enabled or disabled other transition *******/
/* Enabled <----Reduced marking of an inhibitor arc*/
/* Disabled <----Reduced marking of n input arc*/
for (i=0; i<net.tran[fire].inputCount; i++) {
    place=net.tran[fire].inputArc[i].place;
    for (j=0; j<net.place[place].outputCount; j++){
        tran=net.place[place].outputTran[j];

        if (!IsEnabled(tran) && CanBeEnabled(tran)){
            EnableTransition(tran);
            logprintf("\n->>>>Enabling  Transition #%2d",tran);
        }
        if (IsEnabled(tran)) {
			/* store the first enabling combo */
			lFirstCombo=net.tran[tran].lFirstCombo;
        	if(!CanBeEnabled(tran)) {
            DisableTransition(tran, FALSE);
            logprintf("\n->>>>Disabling Transition #%2d",tran);
			} else if(
				net.tran[tran].TimeFunction != NULL
				&& lFirstCombo!=net.tran[tran].lFirstCombo){
			/* can also be disabled by changing the enabling marking */
            	DisableTransition(tran, FALSE);
               	logprintf( "\n->>>>Disabling Transition #%2d", tran );
			}
		}
    }
}

/******** now check all transitions with an user-defined transition enabling function *****/
/*  this is an opportunity to OPTIMIZE, because we could put them in a separate list 
	sacrificing a little memory for a lot of speed ****/
for( i=0; i<net.tranCount; i++ )
{
	/* if the transition has an enable function */
	if( net.tran[i].EnableFunction != NULL )
	{
	    tran=i;

	    if (!IsEnabled(tran) && CanBeEnabled(tran))
	        {
	        EnableTransition(tran);
            logprintf("\n->>>>Enabling  Transition #%2d",tran);
	        }

	    if (IsEnabled(tran)) {
			/* store the first enabling combo */
			lFirstCombo=net.tran[tran].lFirstCombo;
		    if(!CanBeEnabled(tran)) {
		        DisableTransition(tran, FALSE);
	            logprintf("\n->>>>Disabling Transition #%2d",tran);
			} else if(
				net.tran[tran].TimeFunction != NULL
				&& lFirstCombo!=net.tran[tran].lFirstCombo){
			/* can also be disabled by changing the enabling marking */
            	DisableTransition(tran, FALSE);
               	logprintf( "\n->>>>Disabling Transition #%2d", tran );
			}
		}
	}
}

}



/*************************************************************************************/
/*  Checks all the transitions in the network which can be enabled. This             */
/*  is ony called once, at the beginning of the program.  All other enable checks are*/
/*  performed by the FindEnabled() function.                                         */
/* MRG removed lastTime variable because it was obsolete */
/* this function can be called at any time the net is changed by an external force */
/*************************************************************************************/
void FindAllEnabled(void )
{
TRANS_NUMBER i;

for (i=0; i<net.tranCount; i++)
    {
    if (CanBeEnabled(i))                                    /*Enabled?*/
        EnableTransition(i);
    else
        DisableTransition(i, FALSE);
    }
}

/*************************************************************************************/
/*  This function makes the initial enable list at the begining of the program.  This*/
/*  function follows after FindAllEnabled().  Enabled transitions are placed on the  */
/*  list using their index.  Unused places within the enabled list are assigned a    */
/*  transition number (EMPTY).  The number of enabled transitions is also stored. */
/*************************************************************************************/
void MakeInitialEnabledList(void )
{
TRANS_NUMBER i;

net.enabledCount=0;
for (i=0; i<net.tranCount; i++)
    {
    if (IsEnabled(i))                                   /*Enabled?*/
        {
        net.enabledList[net.enabledCount]=i;
        net.enabledCount++;
        }
    }
for (i=net.enabledCount; i<net.tranCount; i++)
    net.enabledList[i]=EMPTY;
}


/*************************************************************************************/
/*  This function adds a transition to the enabled list.  This requires that an empty*/
/*  spot must be found on the list.  The first empty spot is filled in with the      */
/*  transition number to be added. The list should rarely be full because that would */ 
/*  require that all of the transitions were enabled.                                */
/*************************************************************************************/
void AddToEnabledList(TRANS_NUMBER tran )
{
TRANS_NUMBER i;

for (i=0; i<net.tranCount; i++)
    {
    if (net.enabledList[i]==EMPTY)
        {
        net.enabledList[i]=tran;
        net.enabledCount++;
        break;
        }
    }
}

/*************************************************************************************/
/*  This function removes a transition to the enabled list.  This requires finding   */
/*  the transition to be removed within the list.  That spot is then made EMPTY. The */
/*  enabledCount is then decremented.                                                */
/*************************************************************************************/
void RemoveFromEnabledList(TRANS_NUMBER tran)
{
TRANS_NUMBER i;

for (i=0; i<net.tranCount; i++)
    {
    if (net.enabledList[i]==tran)
        {
        net.enabledList[i]=EMPTY;
        net.enabledCount--;
        break;
        }
    }
}

/*************************************************************************************/
/*  This simple function enables a transition and calculates is firing time          */
/*************************************************************************************/
void EnableTransition(TRANS_NUMBER tran)
{
/* make sure that the transition is not already enabled */
if( net.tran[tran].enabled == TRUE )
	return;
net.tran[tran].enabled=TRUE;
net.tran[tran].timeToFire=FiringTime(tran);
AddToEnabledList(tran);

/* record time the transition was enabled */
net.tran[tran].startEnable = net.totalTime;
}


/*************************************************************************************/
/*  This simple function disables a transition.                                      */
/*************************************************************************************/
void DisableTransition(TRANS_NUMBER tran, BOOLEAN bFired)
{
double deltaT;
/* make sure that the transition is not already disabled */
if( net.tran[tran].enabled == FALSE )
	return;
net.tran[tran].enabled=FALSE;
RemoveFromEnabledList(tran);

/* If the transition disabled because the token fired ... */
if (bFired) {
    deltaT = (net.totalTime - net.tran[tran].startEnable);
    /* Update total fire time of tran */
    net.tran[tran].totalFireTime += deltaT;                 
    if (net.tran[tran].firstTime) {
        net.tran[tran].minFireTime = deltaT;
        net.tran[tran].maxFireTime = deltaT;
        net.tran[tran].firstTime = FALSE;
    }
    else {                                                  
        /*Update minimum firing time*/
        if (deltaT < net.tran[tran].minFireTime)              
            /*and maximum firing time*/
            net.tran[tran].minFireTime = deltaT;
        if (deltaT > net.tran[tran].maxFireTime)
            net.tran[tran].maxFireTime = deltaT;
    }
}

net.tran[tran].startEnable = 0.0;
}

/*************************************************************************************/
/*  This simple function returns whether or not a transition is enabled              */                         
/*************************************************************************************/
BOOLEAN IsEnabled(TRANS_NUMBER tran)
{
if (net.tran[tran].enabled)
    return TRUE;
else
    return FALSE;
}


