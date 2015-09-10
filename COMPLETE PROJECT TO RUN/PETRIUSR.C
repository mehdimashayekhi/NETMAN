/*
    NETCODE colored petri net simulator
    old source file for accessing the petri net

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\projects\netman.vc\simulate\petriout/RCS/PETRIUSR.C,v 1.85 1995/07/14 21:41:26 gilem Exp $
*/
/*****************************************************************************************/
/*  all of the functions necessary for the user to access the petri net safely           */
/*****************************************************************************************/

#define SUPER_USER
#include "petri.h"
int i;


double ncGetTime()
{
	return net.totalTime;
}

int ncGetIntTime()
{
	return ((int)(10 * net.totalTime));
}
