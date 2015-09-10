/*
    NETCODE colored petri net simulator
    source file for printing information about the net

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/PRINT.C,v 2.17 1996/05/05 02:05:56 gilem Exp $
*/
#define SUPER_USER
#include "petri.h"
#include <stdio.h>
#include <stdarg.h>

#ifdef INTERACTIVE
#ifndef MACOS
	#include <conio.h>
#endif
#endif

#include <iostream>
#include <fstream>
using namespace std;
extern int Marking_Tracker;
ofstream fp("markingMehdi");

/*****************************************************************************************/
/*  This function prints the transitions and their RFTs which are enabled                */
/*****************************************************************************************/
void PrintEnabled(void)
{

	TRANS_NUMBER count,tran,i;
	i=count=0;
	while (count!=net.enabledCount)
	{
	    tran=net.enabledList[i];
	    if (tran!=EMPTY)
		{
		        logprintf("\nTransition #%2d is enabled,   Time to fire: %5.3lf    RFT: %3.3lf",
	    	            tran,net.tran[tran].timeToFire,net.tran[tran].timeToFire-net.totalTime);
		    count++;
		}
	    i++;
	}
}


void CloseLogFile(void)
{
#ifndef MACOS
			if(logFile)
	    	{
	    		fclose(logFile);
	    		logFile = 0;
	    	}
#endif
}

/*****************************************************************************************/
/*  This function prints the marking of each place within the network (Network Marking   */
/*****************************************************************************************/
void PrintState(void)
{
    PLACE_NUMBER i;

    if( bQuiet )
    {
    	#ifdef INTERACTIVE
        printf("\rCurrentTime: %lf", net.totalTime );
        #endif
    }
    else
    {
        for (i=0; i<net.placeCount; i++)
        {
            logprintf("\nPlace #%2d   Marking:%2d",i,net.place[i].tokenCount);
        }
        logprintf("\nTime Index: %lf ",net.totalTime);
    }

}



//void PrintMarking(void)
//{


//    int markingListMehdi[net.placeCount];
//    PLACE_NUMBER i;
//    for (i=0; i<net.placeCount; i++)
//        {
//            markingListMehdi[i]=net.place[i].tokenCount;
//        }
    ////cout << endl;
    ////cout <<"Marking added by mehdi:  ";
    ////cout << "M" << Marking_Tracker;
    ////cout <<"(";
//    fp << Marking_Tracker;
//    for (i=0; i<net.placeCount; i++)
//        {

//            fp<< ",";
//            fp << markingListMehdi[i];



//        }
  //      fp<<endl;

//}


int logprintf( const char* ptr, ... )
{
    /* this function sends the printf arguments to both the console
        and the log file, if requested

       NOTE: only prints if bQuiet == FALSE
    */

    /* first send the string and args to vsprintf, to get all of the arguments
        then pass it to the proper printf functions */
    char str[512];
    int iReturn;
    va_list arg;
    va_start( arg, ptr );

    iReturn = vsprintf( str, ptr, arg );

    va_end( arg );

#ifdef INTERACTIVE
	if( bQuiet==FALSE )
#ifdef __WATCOMC__
    /* watcom's printf statement doesn't display until a newline is written */
    	cprintf( str );
#else
    	printf( str );
#endif // __WATCOMC__
#endif // INTERACTIVE
#ifndef MACOS
    if( logFile && bQuiet==FALSE )
        fprintf( logFile, str );
#endif

    return iReturn;
}

int logerror( const char* ptr, ... )
{
    /*
    this function sends the printf arguments to both stderr
        and the log file, if requested
    it is intended so that the logprintf function can be used for less
    	serious functions, which won't cause the net to cease functioning properly
    an added side affect is that the interface for the errors is now
    	consistent.  We will always put it on a new line, and write ERROR before it.
    */

    /* first send the string and args to vsprintf, to get all of the arguments
        then pass it to the proper printf functions */
    char str[512];
    int iReturn;
    va_list arg;
    va_start( arg, ptr );

    iReturn = vsprintf( str, ptr, arg );

    va_end( arg );
#ifdef INTERACTIVE
#ifdef __WATCOMC__
    /* watcom's printf statement doesn't display until a newline is written */
    cprintf( str );
#else
    fprintf( stderr, str );
#endif // __WATCOMC__
#endif // INTERACTIVE
#ifndef MACOS
    if( logFile ) {

		fprintf( logFile, "\nERROR: ");
        fprintf( logFile, str );
	}
#endif
    return iReturn;
}
