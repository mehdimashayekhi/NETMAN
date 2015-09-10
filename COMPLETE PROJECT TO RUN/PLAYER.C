/*
    NETCODE colored petri net simulator
    source file for executing the petri net

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/PLAYER.C,v 1.85 1995/07/14 21:41:26 gilem Exp $
*/
#define SUPER_USER
#include "petri.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;





/*****************************************************************************************/
/*  This is the main subroutine within the program.  It calls all the functions needed to*/
/*  execute the user defined Petri net.  If there are no transitions left to fire, it    */
/*  exits.  Otherwise it runs indefinitely.                                              */
/*  CHANGED to return TRUE if there are more transitions to fire, and false if none      */
/*****************************************************************************************/
BOOLEAN PetriPlayer()
{
if (net.enabledCount>0)
    {
    PickTransition();                           /*Pick a transition to fire*/
    AdjustNetwork();                            /*Adjust the timing of the network                                                    incrementing the time BEFORE firing */
//    PrintMarking();
    Fire();                                     /*Fire the transtion*/
    PrintState();                               /*Print Current state of the net*/
    FindEnabled();                              /*Check Transitions*/
    PrintEnabled();                             /*Print out all the enabled transtions*/
    return TRUE;
    }
else
    {
    logprintf("\nNo transitions left to fire...");
    return FALSE;
    }
}

