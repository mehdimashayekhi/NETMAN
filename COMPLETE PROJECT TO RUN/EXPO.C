/*
    NETCODE colored petri net simulator
    source file for exponential variables

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/EXPO.C,v 1.89 1995/07/26 14:01:30 gilem Exp $
*/
#define SUPER_USER
#include "petri.h"
#include <math.h>
#include <stdlib.h>


/***************************************************************************************/
/*  This function returns a exponential distributed random number with a mean of lambda*/
/***************************************************************************************/
double Exponential(double lamda)
{
double u;
double t;
double sv;

/* make sure it is never 0 */
int iRandom;
iRandom = rand();
sv=iRandom;
srand(80+sv);
u=((double)iRandom+1.0)/((double)RAND_MAX+1.0);
t=-log(u)*lamda;
return t;
}
