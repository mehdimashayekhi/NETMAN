/*
    NETCODE colored petri net simulator
    
    defines the functions necessary to get statistics from each of the nodes in the net    

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/STATS.C,v 2.17 1996/05/05 02:05:56 gilem Exp $
*/
#define SUPER_USER
#include "petri.h"
#include <stdio.h>
#include <stdlib.h>


double StatTime(void);
double StatTime()
{
    /* return the time referenced from statstart time */
    return( net.totalTime - net.statStartTime );
}

double Throughput (TRANS_NUMBER tNo)
{
    /* return the throughput of the transition since the statstart time */
    if( StatTime() > 0)
        return ( net.tran[tNo].numOfFirings / StatTime() );
    else
        return 0;
}

double PercentUsage (TRANS_NUMBER tNo)
{
    if( StatTime() > 0)
        return ( net.tran[tNo].totalFireTime / StatTime() );
    else
        return 0;
}

double AvgTimeFiringOfTran (TRANS_NUMBER tNo)
{
    if( net.tran[tNo].numOfFirings > 0 )
        return (net.tran[tNo].totalFireTime / net.tran[tNo].numOfFirings);
    else 
        return 0;
}

double PercentTimePlaceOccupied (PLACE_NUMBER pNo)
{
    if( StatTime() > 0)
        return ((net.place[pNo].occupied)/StatTime() );
    else
        return 0;
}

double TimeAvgNumTokensInPlace (PLACE_NUMBER pNo) 
{
    /* update the sumation to include the time up until now */
    net.place[pNo].sumation += (net.place[pNo].tokenCount *
        (net.totalTime - net.place[pNo].timeLastChange));

    /* now set the time last change, so that it is not added twice */
    net.place[pNo].timeLastChange = net.totalTime;

    if( StatTime() > 0)
        return ( (net.place[pNo].sumation)/ StatTime() );
    else
        return 0;
}

double AvgTimeTokenRemainsPlace (PLACE_NUMBER pNo) 
{
    if(net.place[pNo].totalTokenNum > 0)
        return ((net.place[pNo].timeTokensInPlace)/net.place[pNo].totalTokenNum);
    else 
        return 0;
}


void InitStats(BOOLEAN bTimeZero)
{
    /* NOTE: unlike all of the other members of the petri net, the
        statistics members of the net structures are not initialized in
        define.c . The purpose of this is that the stats may not be used
        in all circumstances.  This function assumes that the net
        has been defined, and then initilizes all of the stat members of the 
        net 
    */

    PLACE_NUMBER p;
    TRANS_NUMBER t;

    /* for each place */
    for( p=0; p<net.placeCount; p++ )
    {
        net.place[p].firstTime = TRUE;
        net.place[p].occupied = 0;
        net.place[p].sumation = 0;
        net.place[p].minTimeOccupied = 0;
        net.place[p].maxTimeOccupied = 0;
        net.place[p].timeTokensInPlace = 0;
        net.place[p].totalTokenNum = 0;

        // reset only on initial case
        if( bTimeZero ) 
        {
            net.place[p].timeLastChange = 0;
            net.place[p].begTime = 0;
        }
    }

    /* for each transition */
    for( t=0; t<net.tranCount; t++ )
    {
        net.tran[t].firstTime = TRUE;
        net.tran[t].numOfFirings = 0;
        net.tran[t].totalFireTime = 0;
        net.tran[t].minFireTime = 0;
        net.tran[t].maxFireTime = 0;

        // reset only in initial case
        if( bTimeZero )
        {
            net.tran[t].startEnable = 0;
        }
    }

    /* NOTE: the beginning of the stat time must be initilized
        to the current time, or else all of the stats taken
        after this time will be wrong */
    net.statStartTime = net.totalTime;

}


void StatDisplayAll()
{
    PLACE_NUMBER p;
    TRANS_NUMBER t;

    for( p=0; p<net.placeCount; p++)
    {
        StatDisplayPlace(p);
    }

    for( t=0; t<net.tranCount; t++ )
    {
        StatDisplayTransition(t);
    }
}

void ShowNetmanNumber(CONDITIONAL_CONST PLACE_NUMBER* subArray)
{
	PLACE_NUMBER i, iNum;
	logprintf("\nNETMAN number: ");
	iNum = subArray[0];
	for(i=1;i<iNum;i++)
	{
		if( subArray[i] >= 0 )
		{
			logprintf("p%d.", subArray[i]);
		}
		else
		{
			logprintf("t%d.", -subArray[i]-1);
		}
	}
	/* now the node number */
	logprintf("%d",subArray[iNum]); 
}

void StatDisplayPlace(PLACE_NUMBER pNo)
{
    Place* pPlace;

    if( pNo < net.placeCount )
    {

        pPlace = &net.place[pNo];

        logprintf( "\n\nPlace Number %d \t\t at Time = %lf\nPlace Name = %s", pNo, net.totalTime, pPlace->name );
		ShowNetmanNumber(net.place[pNo].number);
        logprintf( "\n\tStatistics Taken for %lf units", StatTime() );
        logprintf( "\n\tTotal Tokens Traveled = %ld", (long)pPlace->totalTokenNum );
        logprintf( "\n\tTotal Time Occupied = %lf", (double)pPlace->occupied );
        logprintf( "\n\tRatio of Time Occupied = %lf", (double)PercentTimePlaceOccupied(pNo) );
        logprintf( "\n\tAverage Number of Tokens in Place = %lf", (double)TimeAvgNumTokensInPlace(pNo) );
        logprintf( "\n\tAverage Time Token Remains in Place = %lf", (double)AvgTimeTokenRemainsPlace(pNo) );
    }
    else
    {
        logerror("place number out of range");
    }

}

void StatDisplayTransition(TRANS_NUMBER tNo)
{
    Transition* pTrans;

    if( tNo < net.tranCount )
    {
        pTrans = &net.tran[tNo];
    
        logprintf( "\n\nTransition Number %d \t\t at Time = %lf\nTransition Name = %s", tNo, net.totalTime, pTrans->name);
		ShowNetmanNumber(net.tran[tNo].number);
        logprintf( "\n\tStatistics Taken for %lf units", StatTime() );
		logprintf( "\n\tNumber Of Firings = %ld", (long)pTrans->numOfFirings );
        logprintf( "\n\tFiring Time (min, avg, max)= %lf, %lf, %lf", (double)pTrans->minFireTime,
                        AvgTimeFiringOfTran(tNo), pTrans->maxFireTime );
        logprintf( "\n\tUsage = %lf", (double)PercentUsage(tNo) );
        logprintf( "\n\tThroughput = %lf", (double)Throughput(tNo) );
    }
    else
    {
        logerror("transition number out of range");
    }
}

