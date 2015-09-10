/*****************************************************************************

	DPLAYER.C - the director player shell for NETCODE.  This began as a simple
		xobject file, but now has been edited beyond recognition.   It allows
		one to compile a NETMAN generated simlulation program as an XObject
		under director, rather than as a simple console application.

	This player by itself will not compile, without the addition of the
	remainder of the NETCODE player files, including those generated from 
	the appropriate NETMAN file.
 
 
this file started as:
						   Macromedia player XObject
				  Sample code for Director Windows Player 3.1

						 (c) Copyright 1993 Macromedia
							  All Rights Reserved


			   Sample code and XObject documentation prepared by
					  Patrick Milligan of Oakleaf Designs

			  Direct your comments to him via AppleLink: OAKLEAF,
				   Phone: 408-257-1547, or Fax: 408-996-9432

current version:
    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/DPLAYER.C,v 2.19 1996/06/17 20:10:09 gilem Exp $

 *****************************************************************************/
	
/* include the files necessary for the petri net manipulation */
#define SUPER_USER
#include "petri.h"
#include "userfunc.h"

#ifdef DIRECTOR	// include/exclude whole file from build      



#include "dplayer.h"

                     

/*
------------------------------------------------------------------------------
Global Variables:
------------------------------------------------------------------------------
*/


NETCODEObjPtr gpMe=0;     
long    lPlayerError = ERROR_SUCCESS;
#ifdef MSWIN
	HANDLE  hInst;   
#endif

/* matrix to hold the necessary place and transition numbers for lookup */
#define CELLS_PER_FLOOR		17 /* indexed from zero */
#define MACHINES_PER_PROCESS    4 /* indexed from 1 */
#define NODES_PER_MACHINE		7 /* indexed as below */
                                 
#define TRANS_ENTER_Q			0 /* indexes into the matrix */
#define TRANS_ENTER_MACHINE		1 /* transitions start at zero */
#define TRANS_PROCESSING		2
#define FIRST_PLACE				3 /* for looping */
#define PLACE_IN_Q				3
#define PLACE_M_PROCESSING		4
#define PLACE_M_FREE			5
#define PLACE_OUT_Q				6
#define LAST_PLACE				6 /* for looping */

/*
this is the array for storing the proper place and transition numbers
they must be in the same order as the matrix index used above in order
for the initialization function to work properly
CURRENTLY UNUSED
*/
const long MachineNodes[NODES_PER_MACHINE] =
	{ 0, 1, 2, 0, 2, 3, 4 };

/* the node numbers within each machine
	NOTE: in order to avoid confusion, I made these 1-based... just ignore
    the first value...
*/
long NodeNumber[CELLS_PER_FLOOR+1][MACHINES_PER_PROCESS+1][NODES_PER_MACHINE];
/* the wait places for when the user is choosing a machine
	a good way to implement the user choosing a machine to run on is to
	make a transition which will fire whenever a machine is not specified
	for a specific mfg cell.  When the transition is fired, we can set the
	global which indicate which part is currently waiting to be scheduled

	This method will make sure the the job is either in machine, or in
	the wait place at all times.  When the user moves the job, it will
	either be placed withing a machine queue or within the final place

	look in the userfunc for more the declarations
		boolean bWaitingJob;
		long tvWaitingJob;
		long pnWaitingCell;
 */
#define WAIT_PLACE_NUM	7
long WaitPlace[CELLS_PER_FLOOR+1];


/* information for each machine in the floor.
note that this structure could be combined with the information above to
form a more unified data structure*/
#define MAX_USER_JOBS	100
long lNextJob = 1;
double totalTime=0;
typedef struct {
	long lType;
	long lQueueDiscipline;

} MachineInfoClass;


/* old sample stuff FIXFLAG need to remove it after the stubs are all filled */
typedef struct {
	long lTime;
	long lJob;
} JobRecord;
MachineInfoClass MachineInfoArray[CELLS_PER_FLOOR+1][MACHINES_PER_PROCESS+1];
long lFloorLoad;
long lNumSampleJobs=10;
JobRecord jrSampleJob[10];



/*
------------------------------------------------------------------------------
Main function
------------------------------------------------------------------------------
*/

#ifdef MACOS
#ifdef THINK_C
	/* the mac has a main funciton: the windows data which is similar
	(specifying the input functions with multiple strings)
	is contained in the rc file */
	/*******************************************************************
	DANGER DANGER DANGER DANGER DANGER DANGER DANGER DANGER DANGER DANGER 
	DANGER DANGER DANGER DANGER DANGER DANGER DANGER DANGER DANGER DANGER
	
	When creating a code resource, Think C designates the first function that
	appears in the source file that contains main() as the entry point.
	If main() is to be the entry point, no other function should precede it.
	
	DANGER DANGER DANGER DANGER DANGER DANGER DANGER DANGER DANGER DANGER 
	DANGER DANGER DANGER DANGER DANGER DANGER DANGER DANGER DANGER DANGER 
	*******************************************************************/
	main()
	{

		
		/* 
		
		-- Message name table -- 
		
			this section defines the functions which are supported by the xobject
			as well as the names and arguments of those functions.  They must be the first
			thing in the main function so that director/mac can look them up.
			
			In the cross platform case, these strings should be the same as those which are
			found in filename.rc, with the exception of beginning with a \p, and not having
			the trailing \0.  We did not write macros for defining these, because the
			windows version uses resources to develop the xobject.
		
		*/
XMessagesBegin
XMessage	"\p-- NETCODE, petri net simulator xobject (stubs only) 22Mar96 MRG";
XMessage			"\pI        mNew -- Standard creation method\0";
XMessage			"\pX        mDispose -- Standard dispose method\0";
XMessage			"\pS        mName               --Returns the XObject name (Widget)";
XMessage			"\pI        mStatus             --Returns an integer status code";
XMessage			"\pSI       mGetErrorString, code        --Returns an error string";
XMessage			"\pXO       mSetMessageLogger, object -- Set a message logger instance ";
XMessage			"\pX        mSetInitialMarking -- Reset the initial marking";
XMessage			"\pX        mStep -- Fire one transition in the petri net";
XMessage			"\pX        mGo -- Start the Petri net firing continuously";
XMessage			"\pXI       mGoUntil, time -- Run the Petri net until the specified time";
XMessage			"\pI        mGoUntilNextCell -- run the simulation until a job is waiting";
XMessage			"\pI        mGetCurrentWaitingJob -- return the job number of the waiting job";
XMessage			"\pI        mGetCurrentWaitingCell -- return the cell number where a job is waiting";
XMessage			"\pX        mResetFloor -- Reset the entire factory, returning the jobs to start";
XMessage			"\pX        mResetStats -- Reset the statistics of the system";
XMessage			"\pI        mGetTime -- get the current time of the simulation";
XMessage			"\pXIII     mSetMachineType, cell, machine, type -- set a machine type";
XMessage			"\pIII      mGetMachineType, cell, machine -- retrieve the machine type";
XMessage			"\pXI       mSetFloorLoad, sample load -- set the mfg floor to a preset load";
XMessage			"\pI        mGetFloorLoad -- get the mfg floor sample load";
XMessage			"\pIIIIIII  mAddUserJob, boards, onsertion, insertion, manual, releaseTime, dueDate - add a user job";
XMessage			"\pIIII     mTryUserJob, cell, machine, job -- try the user job in a specific machine";
XMessage			"\pXIII     mRemoveUserJob, cell, machine, job -- remove the user job from a specific machine";
XMessage			"\pXIII     mSetMachineQueueDiscipline, cell, machine, order -- set the queue ordering";
XMessage			"\pIII      mGetMachineQueueDiscipline, cell, machine -- get the queue ordering";
XMessage			"\pIII      mGetMachineNumberJobsInQueue, cell, machine -- get the number of jobs waiting for machine";
XMessage			"\pIII      mGetMachineRemainingProcessingTime, cell, machine -- get the remaining time to process current part";
XMessage			"\pIIII     mGetMachineJobExpectedProcessingTime, cell, machine, queuePosition -- get the expected time to process the job in the specified queue position";
XMessage			"\pIIII     mGetMachineJobNumber, cell, machine, queuePosition -- get the job number for the job in the specified queue position";
XMessage			"\pIIII     mGetMachineJobReleaseTime, cell, machine, queuePosition -- get the release time for the job specified";
XMessage			"\pIIII     mGetMachineJobDueDate, cell, machine, queuePosition -- get the due date for the job specified";
XMessage			"\pIII      mGetUtilization, cell, machine -- get the utilization for a machine";
XMessage			"\pII       mGetFlowtime, job -- get the flow time for the specified job";
XMessage			"\pI        mGetMakespan";
XMessage			"\pI        mGetAvgLateness";
XMessage			"\pI        mGetAvgTardiness";
XMessage			"\pI        mGetMaxTardiness";
XMessage			"\pI        mGetNumTardyJobs";
XMessage			"\pII       mGetNumberOfSuccessfulBoards, job -- get the number of boards completed in the job";

XMessagesEnd

		/*		
		-- Method dispatch table -- 
		
			this actually lists the entry points to each of the functions.  It is 
			essential that these functions be in the EXACT order that they are in the 
			table above, or else director will not be able to locate them.  		
		*/
		
		XMethodsBegin
			XMethod MethodNew;
			XMethod MethodDispose;
			XMethod MethodName;

			XMethod	MethodStatus;
			XMethod	MethodGetErrorString;

			XMethod MethodSetMessageLogger;

			XMethod MethodSetInitialMarking;
			XMethod MethodStep;
			XMethod MethodGo;
			XMethod MethodGoUntil;
			XMethod MethodGoUntilNextCell;
			XMethod MethodGetCurrentWaitingJob;
			XMethod MethodGetCurrentWaitingCell;			
			XMethod MethodResetFloor;
			XMethod MethodResetStats;
			XMethod MethodGetTime;
			
			XMethod MethodSetMachineType;
			XMethod MethodGetMachineType;
			
			XMethod MethodSetFloorLoad;
			XMethod MethodGetFloorLoad;
			
			XMethod MethodAddUserJob;
			XMethod MethodTryUserJob;
			XMethod MethodRemoveUserJob;

			XMethod MethodSetMachineQueueDiscipline;
			XMethod MethodGetMachineQueueDiscipline;

			XMethod MethodGetMachineNumberOfJobsInQueue;
			XMethod MethodGetMachineRemainingProcessingTime;
			XMethod MethodGetMachineJobExpectedProcessingTime;
			XMethod MethodGetMachineJobNumber;
			XMethod MethodGetMachineJobReleaseTime;
			XMethod MethodGetMachineJobDueDate;
			
			XMethod MethodGetUtilization;
			XMethod MethodGetFlowtime;
			XMethod MethodGetMakespan;
			XMethod MethodGetAvgLateness;
			XMethod MethodGetAvgTardiness;
			XMethod MethodGetMaxTardiness;
			XMethod MethodGetNumTardyJobs;
			XMethod MethodGetNumberOfSuccessfulBoards;
		XMethodsEnd



	} /* end main() */
#else /* rest is for codewarrior */
void __Startup__(void);

/* DANGER
because this project is so large, we must use the large memory model, along with these pragmas around
the __startup__ function.  The pragmas are because the assembly in the xobject.h were written for the
small memory model. 
*/
#pragma near_code								// all code references must be 16-bit   PC relative
#pragma far_data	 off						// all data references must be  16-bit A4 relative


asm void __Startup__(void)
	{

		
		/* 
		
		-- Message name table -- 
		
			this section defines the functions which are supported by the xobject
			as well as the names and arguments of those functions.  They must be the first
			thing in the main function so that director/mac can look them up.
			
			In the cross platform case, these strings should be the same as those which are
			found in filename.rc, with the exception of beginning with a \p, and not having
			the trailing \0.  We did not write macros for defining these, because the
			windows version uses resources to develop the xobject.

		*/
XMessagesBegin
XMessage	"\p-- NETCODE, petri net simulator xobject (stubs only) 22Mar96 MRG",\
			"\pI        mNew -- Standard creation method\0",\
			"\pX        mDispose -- Standard dispose method\0",\
			"\pS        mName               --Returns the XObject name (Widget)",\
			"\pI        mStatus             --Returns an integer status code",\
			"\pSI       mGetErrorString, code        --Returns an error string",\
			"\pXO       mSetMessageLogger, object -- Set a message logger instance ",\
			"\pX        mSetInitialMarking -- Reset the initial marking",\
			"\pX        mStep -- Fire one transition in the petri net",\
			"\pX        mGo -- Start the Petri net firing continuously",\
			"\pXI       mGoUntil, time -- Run the Petri net until the specified time",\
			"\pI        mGoUntilNextCell -- run the simulation until a job is waiting",\
			"\pI        mGetCurrentWaitingJob -- return the job number of the waiting job",\
			"\pI        mGetCurrentWaitingCell -- return the cell number where a job is waiting",\
			"\pX        mResetFloor -- Reset the entire factory, returning the jobs to start",\
			"\pX        mResetStats -- Reset the statistics of the system",\
			"\pI        mGetTime -- get the current time of the simulation",\
			"\pXIII     mSetMachineType, cell, machine, type -- set a machine type",\
			"\pIII      mGetMachineType, cell, machine -- retrieve the machine type",\
			"\pXI       mSetFloorLoad, sample load -- set the mfg floor to a preset load",\
			"\pI        mGetFloorLoad -- get the mfg floor sample load",\
			"\pIIIIIII  mAddUserJob, boards, onsertion, insertion, manual, releaseTime, dueDate - add a user job",\
			"\pIIII     mTryUserJob, cell, machine, job -- try the user job in a specific machine",\
			"\pXIII     mRemoveUserJob, cell, machine, job -- remove the user job from a specific machine",\
			"\pXIII     mSetMachineQueueDiscipline, cell, machine, order -- set the queue ordering",\
			"\pIII      mGetMachineQueueDiscipline, cell, machine -- get the queue ordering",\
			"\pIII      mGetMachineNumberJobsInQueue, cell, machine -- get the number of jobs waiting for machine",\
			"\pIII      mGetMachineRemainingProcessingTime, cell, machine -- get the remaining time to process current part",\
			"\pIIII     mGetMachineJobExpectedProcessingTime, cell, machine, queuePosition -- get the expected time to process the job in the specified queue position",\
			"\pIIII     mGetMachineJobNumber, cell, machine, queuePosition -- get the job number for the job in the specified queue position",\
			"\pIIII     mGetMachineJobReleaseTime, cell, machine, queuePosition -- get the release time for the job specified",\
			"\pIIII     mGetMachineJobDueDate, cell, machine, queuePosition -- get the due date for the job specified",\
			"\pIII      mGetUtilization, cell, machine -- get the utilization for a machine",\
			"\pII       mGetFlowtime, job -- get the flow time for the specified job",\
			"\pI        mGetMakespan",\
			"\pI        mGetAvgLateness",\
			"\pI        mGetAvgTardiness",\
			"\pI        mGetMaxTardiness",\
			"\pI        mGetNumTardyJobs",\
			"\pII       mGetNumberOfSuccessfulBoards, job -- get the number of boards completed in the job";
XMessagesEnd

		/*
		-- Method dispatch table --

			this actually lists the entry points to each of the functions.  It is
			essential that these functions be in the EXACT order that they are in the
			table above, or else director will not be able to locate them.
		*/

		XMethodsBegin
			XMethod MethodNew;
			XMethod MethodDispose;
			XMethod MethodName;

			XMethod	MethodStatus;
			XMethod	MethodGetErrorString;

			XMethod MethodSetMessageLogger;

			XMethod MethodSetInitialMarking;
			XMethod MethodStep;
			XMethod MethodGo;
			XMethod MethodGoUntil;
			XMethod MethodGoUntilNextCell;
			XMethod MethodGetCurrentWaitingJob;
			XMethod MethodGetCurrentWaitingCell;			
			XMethod MethodResetFloor;
			XMethod MethodResetStats;
			XMethod MethodGetTime;
			
			XMethod MethodSetMachineType;
			XMethod MethodGetMachineType;
			
			XMethod MethodSetFloorLoad;
			XMethod MethodGetFloorLoad;
			
			XMethod MethodAddUserJob;
			XMethod MethodTryUserJob;
			XMethod MethodRemoveUserJob;

			XMethod MethodSetMachineQueueDiscipline;
			XMethod MethodGetMachineQueueDiscipline;
			
			XMethod MethodGetMachineNumberOfJobsInQueue;
			XMethod MethodGetMachineRemainingProcessingTime;
			XMethod MethodGetMachineJobExpectedProcessingTime;
			XMethod MethodGetMachineJobNumber;
			XMethod MethodGetMachineJobReleaseTime;
			XMethod MethodGetMachineJobDueDate;

			XMethod MethodGetUtilization;
			XMethod MethodGetFlowtime;
			XMethod MethodGetMakespan;
			XMethod MethodGetAvgLateness;
			XMethod MethodGetAvgTardiness;
			XMethod MethodGetMaxTardiness;
			XMethod MethodGetNumTardyJobs;
			XMethod MethodGetNumberOfSuccessfulBoards;
		XMethodsEnd


	} /* end main() */
	
#pragma far_code					// all code references must be 16-bit   PC relative
#pragma far_data	 reset			// all data references must be  16-bit A4 relative
	
	
#endif /* thinkc */
#endif /* macos*/

#ifdef MSWIN
	/* windows has a libmain function rather than a main function */
	int  __far __pascal __export LibMain(
		HINSTANCE hndInstance, WORD wDataSeg, WORD cbHeapSize, LPSTR ignore);

	/*
	------------------------------------------------------------------------------
	FUNCTION        ||      LibMain()

	Windows Entry Procedure for DLLs.  Called by LibEntry routine.
	------------------------------------------------------------------------------
	*/

	int __far __pascal __export LibMain(
		HINSTANCE hndInstance, WORD wDataSeg, WORD cbHeapSize, LPSTR ignore)
	{
		if (cbHeapSize != 0)
		{
			if (! LocalInit( (UINT)wDataSeg, (UINT)NULL, (UINT)cbHeapSize))
			{
				return (0);
			}
		}
		hInst = hndInstance;
		return (1);
	}


	// MRG: this function was axed, because there is no way to do this on the mac version
	// Log some useful debug info to message window
	static void MessageWindow( NETCODEObjPtr pMe, const char *format, ...)
	{
		char    buf[250];               // !!@ No error check on size.
	
		wvsprintf( buf, format, ((char *)&format)+sizeof(char *) );
		pMe->myxtbl->showMsg( buf );
	}
#endif


/*
------------------------------------------------------------------------------
Mac functions to match the windows XObject equivalent
------------------------------------------------------------------------------
*/
#ifdef MACOS
Handle 
CloneHandle(Handle hThis) 
{
	Handle hCopy;
	Size memSize;
	/* first create the space for the new handle */
	memSize = GetHandleSize(hThis);
	hCopy = NewHandle(memSize);
	/* check if an error has occured by not being able to create handle */
	if( !hCopy )
		return 0;
	/* lock the handle */
	HLock( hCopy );
	HLock( hThis );
	/* copy the handle */
	BlockMove( *hThis, *hCopy, memSize );
	/* unlock the handle */
	HUnlock( hThis );
	HUnlock( hCopy );
	/* return the handle */
	return hCopy;
}

#endif

/*
------------------------------------------------------------------------------
Callback Functions:
------------------------------------------------------------------------------
*/


/*
------------------------------------------------------------------------------
FUNCTION        ||      _player_mNew

Create a new instance of the Player XObject.  Initialize instance variables.
NOTE: this function does not use the ordinary shortcut macros defined above,
because the system is not set up right at this point.   That is why this
is the ugliest function which we have here

return: zero on success, or non-zero on error
------------------------------------------------------------------------------
*/

long 
CALLBACK_FUNCTION(New)( CALLBACK_VARS )
{
	long localError;

	#ifdef MACOS
	NETCODEObjPtr pMe;
	XMethodOpen( hPlayer );
	pMe = *hPlayer;
	/* set the error code to zero if we dont get a pointer */
	SetHandleSize((Handle)hPlayer, sizeof(NETCODEObj));
	localError = MemError();
	#endif

	#ifdef MSWIN
	/* set the error code to zero if we get a pointer */
	localError = ! MsgSetMyHandleSize(hPlayer, sizeof(NETCODEObj));
	#endif


	/* check if there is a return value for this on the mac */
	if( !localError )
	{
		#ifdef MSWIN
		/* set up the xtbl member so that we don't have to work with
			it in other functions */
		rXMethodOpen( hPlayer );
		#endif

		/* Initialize instance data */
		pMe->hErrMsg = NULL;

		pMe->count = 2;
		pMe->msgLogger = 0;
		pMe->step = 0;

		/****************************/
		/* initialize the global log file (in the netcode source */
		/* fixflag: metrowerks cannot handle fopen w/o souix library */
		#ifndef MACOS
		logFile = fopen( "NETCODE.log", "w" );
		if( logFile == 0 )
			logerror("Cannot open log file");
		#endif
		/* initialize the petri net */
		LogMessage("mNew registered, about to initialize net", pMe);
		/* note: code resources don't initialize globals */
		bWaitingJob=FALSE;
 		pnWaitingCell=-1;
 		tvWaitingJob=-1;

		InitializeNet();
		InitNodeNumbers();
		/****************************/

		#ifdef MSWIN
		rXMethodClose( hPlayer );
		#endif
	} 
	else
		LogMessage("mNew failed!!", 0);

	#ifdef MACOS
	XMethodClose( hPlayer );
	#endif
                                                               
	return (localError);
}

/*
-----------------------------------------------------------------------------
FUNCTION       ||      _player_mDispose

Dispose of a Player XObject instance.  Free instance data (if any).

NOTE: just like the mNew handler, this function has a lot of system
dependencies.  This is because the memory handling asre very different
between the mac and windows version of director.  The remaining
functions should be very similar.
-----------------------------------------------------------------------------
matched to stub
*/


long 
CALLBACK_FUNCTION(Dispose)( CALLBACK_VARS )
{
	long lReturn;
    rXMethodOpen( hPlayer );

    /* prepare the return code */
    lPlayerError = ERROR_SUCCESS;

    /* if there is a saved error code, then delete it */
    if (pMe->hErrMsg != NULL)
    {
        // Dispose of saved error message:
        MsgDisposeHandle(pMe->hErrMsg);
    }

    /* now free the petri net */
    FreeMemory();
    
    /* send a debug message */
    LogMessage( "mDispose: memory freed, and about to release", pMe );

    #ifdef MSWIN
    /* close the method */
    /* int the windows version, the memory must be unlocked before it
        is destroyed */
    rXMethodClose( hPlayer );
    xtbl->xobj_Dispose( hPlayer );
    #endif

	lReturn = lPlayerError;

    #ifdef MACOS
    /* close the method */
    SendSuper( mDispose, (long)hPlayer );
    rXMethodClose( hPlayer );
    #endif

    /* return the error code */
	return (lPlayerError);
}

/*
------------------------------------------------------------------------------
FUNCTION        ||      _player_mName

Return the name of this XObject (e.g. "Player")
NOTE: this object must be deleted by the calling object, not this one.
------------------------------------------------------------------------------
*/
LxMemHandle 
CALLBACK_FUNCTION(Name)( CALLBACK_VARS )
{
    LxMemHandle hString;

    rXMethodOpen(hPlayer);
    hString = AllocStringFromPtr("NETCODE");

    /* send a debug message */
    LogMessage( "mName: returning name", pMe );


    rXMethodClose(hPlayer);
    return (hString);
}

/*
------------------------------------------------------------------------------
FUNCTION        ||      _player_mStatus

Return the integer status code from the last Method call.
------------------------------------------------------------------------------
*/

long 
CALLBACK_FUNCTION(Status)( CALLBACK_VARS )
{
    long error;
    rXMethodOpen(hPlayer);
    error = lPlayerError;

    /* send a debug message */
    LogMessage( "mStatus: returning status code", pMe );

    rXMethodClose(hPlayer);
    return (error);
}

/*
------------------------------------------------------------------------------
FUNCTION        ||      _player_mError

Return an error string corresponding to the passed error code.
------------------------------------------------------------------------------
*/

LxMemHandle 
CALLBACK_FUNCTION(GetErrorString)( long lErrorCode, CALLBACK_VARS )
{
	LPSTR       pStrMsg;
	LxMemHandle hStrMsg;

    rXMethodOpen( hPlayer );

	switch ((short) lErrorCode)
	{
		case ERROR_SUCCESS:
			pStrMsg = "";
			break;
		case ERROR_MEM_ALLOC:
			pStrMsg = "Memory allocation failure";
			break;
		case ERROR_CELL:
			pStrMsg = "Cell out of range";
			break;
		case ERROR_MACHINE:
			pStrMsg = "Machine out of range";
			break;
		case ERROR_WAIT_CELL:
			pStrMsg = "There is a job waiting at another cell";
			break;
		case ERROR_WAIT_JOB:
			pStrMsg = "There is a different job waiting";
			break;
		case ERROR_WAIT_JOB_FIND:
			pStrMsg = "INTERNAL: job not found";
			break;
		case ERROR_TOO_MANY_JOBS:
			pStrMsg = "Too many jobs have been created";
			break;
      case ERROR_JOB_NOT_FOUND:
      	pStrMsg = "The job could not be found in the specified queue";
      	break;
		default:
			pStrMsg = "Unknown error";
			break;
	}
	hStrMsg = AllocStringFromPtr(pStrMsg);

	// Save a copy of returned string in instance variable
    if (pMe->hErrMsg != NULL)
    {
        // Dispose of saved error message:
        MsgDisposeHandle(pMe->hErrMsg);
    }
	pMe->hErrMsg = MsgCloneHandle(hStrMsg);

    /* send a debug message */
    LogMessage( "mError: returning error code", pMe );

	rXMethodClose( hPlayer );
	return (hStrMsg);
}

                                     
long 		
CALLBACK_FUNCTION(SetMachineType)( long lCell, long lMachine, long lType, CALLBACK_VARS )
{   
	long lReturn = 0;
	/* set the machine type of the specified machine */
	rXMethodOpen( hPlayer );
    /* send a debug message */
    LogMessage( "mSetMachineType: received", pMe );
    
    if( lType < 0 || lType > 5 )
    {                
    	LogMessage( "ERROR: machine type must be between 0 and 5", pMe );
    	lReturn = -1;
    }
    else
    {   
    	if( lPlayerError = CheckCellAndMachine(lCell, lMachine, pMe) ) 
			lReturn = lPlayerError;
		else
		   	MachineInfoArray[lCell][lMachine].lType = lType;
    }
    
	rXMethodClose( hPlayer );  
	return lReturn;
}

long		
CALLBACK_FUNCTION(GetMachineType)( long lCell, long lMachine, CALLBACK_VARS )
{                                                       
	long lReturn = 0;
	/* get the machine type of the specified machine */
	rXMethodOpen( hPlayer );
    /* send a debug message */
    LogMessage( "mGetMachineType: received", pMe );
    
    /* test to see if reasonable */
    	if( lPlayerError = CheckCellAndMachine(lCell, lMachine, pMe) ) 
			lReturn = lPlayerError;
    	else
    		/* success */
    		lReturn = MachineInfoArray[lCell][lMachine].lType ;

	rXMethodClose( hPlayer );
	return lReturn;
}

long		
CALLBACK_FUNCTION(SetFloorLoad)( long lSampleLoad, CALLBACK_VARS )
{
	long lReturn = 0;                                     
	/* set the basic floor load for the system */
	rXMethodOpen( hPlayer );
    /* send a debug message */
    LogMessage( "mSetFloorLoad: received", pMe );

    if( lSampleLoad < 0 || lSampleLoad > 5 )
    {                
    	LogMessage( "ERROR: machine type must be between 0 and 5", pMe );
    	lReturn = -1;
    }
    else
    	lFloorLoad = lSampleLoad;

	rXMethodClose( hPlayer );
	return lReturn;
}

long 		
CALLBACK_FUNCTION(GetFloorLoad)( CALLBACK_VARS )
{                                                 
	long lReturn = 0;                                     
	/* get the floor load for the system */
	rXMethodOpen( hPlayer );
    /* send a debug message */
    LogMessage( "mGetFloorLoad: received", pMe );

   	lReturn = lFloorLoad;

	rXMethodClose( hPlayer );
	return lReturn;
}

long
CALLBACK_FUNCTION(AddUserJob)( long lBoards, long lOnsertion, long lInsertion, long lManual, long lReleaseTime, long lDueDate,CALLBACK_VARS )
{
	long lReturn;
	/* add a user job to the system, and put in the start place */
	rXMethodOpen( hPlayer );
    /* send a debug message */
    LogMessage( "mAddUserJob: received", pMe );
    /* check to make sure that the next job number isn't greater than the max */
    if( lNextJob < MAX_USER_JOBS ) {
	    /* create a user job with the specified information */
	    Token *pToken;
	    pToken = NewToken();
	    /* now dimension the token by adding the last value */
	    TokenSetColorNum( pToken, JOB_LENGTH-1, 0 );
	    /* now set the remaining colors */
	    /* override any negative values */
	    if(lBoards<0) lBoards = 0;
	    if(lOnsertion<0) lOnsertion = 0;
	    if(lInsertion<0) lInsertion = 0;
	    if(lManual<0) lManual = 0;
	    if(lReleaseTime<0) lReleaseTime = 0;
	    if(lDueDate<0) lDueDate = 0;

	    TokenSetColorNum( pToken, JR_SERIAL, lNextJob );
	    TokenSetColorNum( pToken, JR_RELEASE_TIME, lReleaseTime );
	    TokenSetColorNum( pToken, JR_DUE_DATE, lDueDate);
	    TokenSetColorNum( pToken, JR_BOARD, lBoards);
	    TokenSetColorNum( pToken, JR_SMT, lOnsertion);
	    TokenSetColorNum( pToken, JR_THROUGH, lInsertion);
	    TokenSetColorNum( pToken, JR_MANUAL, lManual );

    	/* increment to the next job */
		lReturn = lNextJob;
		lNextJob++;

        /* since this change may affect the net, find all enabled */
        FindAllEnabled();
	} else {
		/* save the error, and return a negative value */
		lPlayerError = lReturn = ERROR_TOO_MANY_JOBS;
	}
	rXMethodClose( hPlayer );
	return lReturn;
}

long		
CALLBACK_FUNCTION(SetMachineQueueDiscipline)( long lCell, long lMachine, long lQueueDiscipline, CALLBACK_VARS )
{                                                                 
	long lReturn=0;
	/* set the queue policy for the specified machine, reordering 
		the queue to follow this discipline, now and in the future */
	rXMethodOpen( hPlayer );
    /* send a debug message */
    LogMessage( "mSetMachineQueueDiscipline: received", pMe );

    if( lQueueDiscipline < 0 || lQueueDiscipline > 5 )
    {                
    	LogMessage( "ERROR: queue order must be between 0 and 5", pMe );
    	lReturn = -1;
    }
    else
    {   
    	if( lPlayerError = CheckCellAndMachine(lCell, lMachine, pMe) ) 
			lReturn = lPlayerError;
		else
    		/* success */
    		MachineInfoArray[lCell][lMachine].lQueueDiscipline = lQueueDiscipline;
    }

	rXMethodClose( hPlayer );
	return lReturn;
}

long		
CALLBACK_FUNCTION(GetMachineQueueDiscipline)( long lCell, long lMachine, CALLBACK_VARS )
{                                                                 	
	long lReturn=0;
	/* get the queue policy for the specified machine */
	rXMethodOpen( hPlayer );
    /* send a debug message */
    LogMessage( "mGetMachineQueueDiscipline: received", pMe );

    	if( lPlayerError = CheckCellAndMachine(lCell, lMachine, pMe) ) 
			lReturn = lPlayerError;
		else
    		/* success */
    		lReturn = MachineInfoArray[lCell][lMachine].lQueueDiscipline;


	rXMethodClose( hPlayer );
	return lReturn;
}

long 		
CALLBACK_FUNCTION(TryUserJob)( long lCell, long lMachine, long lJob, CALLBACK_VARS )
{                                                       
	/* there is a user job waiting in the input queue for the Cell
		specify the given job for the Cell/machine pair in the token color,
		then run the simulation until the part has made it into the
		input place of the given job.  This will allow the user to see
		the effect of the job on the queue of the chosen machine */
	long lReturn;
	rXMethodOpen( hPlayer );
    /* send a debug message */
    LogMessage( "mTryUserJob: received", pMe );
    /* check the machine and cell values */
    lReturn = CheckCellAndMachine( lCell, lMachine, pMe );
    if( !lReturn ) {
    	/* now check if there is a job waiting at this cell */
    	if( lCell == pnWaitingCell ) {
	    	/* get the job out of the wait place */
	    	if( lJob == tvWaitingJob ) {
	    		/* try to find the job */
	    		/* get the place number from the waiting place array */
	    		PLACE_NUMBER pno;
	    		Token *pToken;
	    		pno = WaitPlace[ lCell ];
	    		/* now get the number of tokens in the place
	    			NOTE: since it is fifo, it should be the last token
	    		 */
	    		pToken = PlaceFindJob( &net.place[pno], lJob );

	    		if(pToken) {
	    			/* put the job into the machine place */
	    			PLACE_NUMBER pQ;
	    			pQ = NodeNumber[lCell][lMachine][PLACE_IN_Q];
	    			/* fixflag ignore the queue discipline for now */
	    			/* set machine to the chosen machine */
	    			TokenSetColorNum( pToken, JR_CURRENT_MACHINE, lMachine );
	    			PlaceAddTokenToEnd( &net.place[pQ], pToken );
	    			/* now reset the job waiting values, so that we can continue */
	    			pnWaitingCell = INVALID_WAIT;
	    			tvWaitingJob = INVALID_WAIT;
	    			bWaitingJob = 0;

                    FindAllEnabled();
	    		} else
	    			lPlayerError = lReturn = ERROR_WAIT_JOB_FIND;
	    	} else
	    		lPlayerError = lReturn = ERROR_WAIT_JOB;
	    } else
	    	lReturn = lPlayerError = ERROR_WAIT_CELL;
    }
	rXMethodClose( hPlayer );
	return lReturn;
}

long
CALLBACK_FUNCTION(RemoveUserJob)( long lCell, long lMachine, long lJob, CALLBACK_VARS )
{
	/* remove the job number from process and machine inq, and return it
		to the choice place of the Cell */
	long lReturn;
	rXMethodOpen( hPlayer );
    /* send a debug message */
    LogMessage( "mRemoveUserJob: received", pMe );
    /* check the machine and cell values */
    lReturn = CheckCellAndMachine( lCell, lMachine, pMe );
    if( !lReturn ) {
    	if( !bWaitingJob ) {
	    	/* get the queue number */
			/* put the job into the machine place */
			PLACE_NUMBER pQ;
			Token *pToken;
			pQ = NodeNumber[lCell][lMachine][PLACE_IN_Q];
			pToken = PlaceFindJob( &net.place[pQ], lJob );

	    	if( pToken ) {
	    		/* now return the job to the waiting place */
	    		PLACE_NUMBER pno;
	    		pno = WaitPlace[ lCell ];
	    		/* set machine to unknown */
    			TokenSetColorNum( pToken, JR_CURRENT_MACHINE, 0 );
   	    		PlaceAddTokenToEnd( &net.place[pno], pToken );
	    		/* and reset the waiting flags */
	    		bWaitingJob = TRUE;
	    		pnWaitingCell = lCell;
	    		tvWaitingJob = lJob;
                FindAllEnabled();
		    } else
		    	lReturn = lPlayerError = ERROR_WAIT_JOB_FIND;
		 } else
		 	lReturn = lPlayerError = ERROR_WAIT_JOB;
    }
	rXMethodClose( hPlayer );
	return lReturn;
}

long
CALLBACK_FUNCTION(GetMachineNumberOfJobsInQueue)( long lCell, long lMachine, CALLBACK_VARS )
{
	/*
   	return the number of jobs which are waiting for machine cell,machine
      returns the number in q (not including the one in-process
      a return value of 0 indicates processing current job
      a return value of -1 indicates that there are no jobs in q, and there
      are no jobs being processed
   */
	long lReturn=-1;
	rXMethodOpen( hPlayer );
   /* first check the cell and machine */
    lReturn = CheckCellAndMachine( lCell, lMachine, pMe );
    if( !lReturn ) {
      PLACE_NUMBER pno;
    	/* set lReturn to indicate no jobs */
      lReturn = -1;
   	/* if there is a part in-process */
		pno = NodeNumber[lCell][lMachine][PLACE_M_PROCESSING];
      if( net.place[pno].tokenCount )
      	lReturn = 0;
      /* if there are parts in the queue */
		pno = NodeNumber[lCell][lMachine][PLACE_IN_Q];
      if( net.place[pno].tokenCount )
      	lReturn = net.place[pno].tokenCount;
    }else{
    	lPlayerError = lReturn;
    }
	rXMethodClose( hPlayer );
	return lReturn;
}

long
CALLBACK_FUNCTION(GetMachineJobNumber)( long lCell, long lMachine, long lJobQueuePosition, CALLBACK_VARS )
{
	long lReturn=-1;
	rXMethodOpen( hPlayer );
   lReturn = GetMachineJobProperty( lCell, lMachine, lJobQueuePosition, JR_SERIAL, pMe );
	rXMethodClose( hPlayer );
	return lReturn;
}

long
CALLBACK_FUNCTION(GetMachineJobReleaseTime)( long lCell, long lMachine, long lJobQueuePosition, CALLBACK_VARS )
{
	long lReturn=-1;
	rXMethodOpen( hPlayer );
   lReturn = GetMachineJobProperty( lCell, lMachine, lJobQueuePosition, JR_RELEASE_TIME, pMe );
	rXMethodClose( hPlayer );
	return lReturn;
}

long
CALLBACK_FUNCTION(GetMachineJobDueDate)( long lCell, long lMachine, long lJobQueuePosition, CALLBACK_VARS )
{
	long lReturn=-1;
	rXMethodOpen( hPlayer );
   lReturn = GetMachineJobProperty( lCell, lMachine, lJobQueuePosition, JR_DUE_DATE, pMe );
	rXMethodClose( hPlayer );
	return lReturn;
}

long
CALLBACK_FUNCTION(GetMachineJobExpectedProcessingTime)( long lCell, long lMachine, long lJobQueuePosition, CALLBACK_VARS )
{
	long lReturn=-1;
	rXMethodOpen( hPlayer );
   lReturn = GetMachineJobProperty( lCell, lMachine, lJobQueuePosition, JR_PROCESS_TIME, pMe );
	rXMethodClose( hPlayer );
	return lReturn;
}

long
CALLBACK_FUNCTION(GetMachineRemainingProcessingTime)( long lCell, long lMachine, CALLBACK_VARS )
{
	/* unlike the other getmachine* functions, this one only concerns the
   	machine in process.  In order to find this, we simply look at the
      transition which is enabled by the token in the process place */
	long lReturn;
	rXMethodOpen( hPlayer );
   /* check the cell */
   lReturn = CheckCellAndMachine( lCell, lMachine, pMe );
   if( !lReturn ) {
		/* get the transition for the machine */
      TRANS_NUMBER tno;
      tno = NodeNumber[lCell][lMachine][TRANS_PROCESSING];
      if( net.tran[tno].enabled ) {
      	lReturn = net.tran[tno].timeToFire - net.totalTime;
      	}
      else
      	lPlayerError = lReturn = ERROR_JOB_NOT_FOUND;
   }
	rXMethodClose( hPlayer );
	return lReturn;
}

/*
------------------------------------------------------------------------------
STATISTIC FUNCTIONS
return the requested statistics about the performance of the floor
------------------------------------------------------------------------------
*/


long
CALLBACK_FUNCTION(GetUtilization)( long lCell, long lMachine, CALLBACK_VARS )
{
	long lReturn=0;
	rXMethodOpen( hPlayer );
    	if( lPlayerError = CheckCellAndMachine(lCell, lMachine, pMe) )
			lReturn = lPlayerError;
		else
    	{
    		lReturn = rand();
    	}
	rXMethodClose( hPlayer );
	return lReturn;
}

long
CALLBACK_FUNCTION(GetFlowtime)( long lJobNumber, CALLBACK_VARS )
{
	long lReturn=0;
	rXMethodOpen( hPlayer );
    if( lJobNumber < 1 || lJobNumber >= lNextJob )
    {
    	lReturn = -2;
	    LogMessage( "user job doesn't exist", pMe );
    }
	else {
		lReturn = rand();
	}
	rXMethodClose( hPlayer );
	return lReturn;
}

long
CALLBACK_FUNCTION(GetMakespan)( CALLBACK_VARS )
{
	long lReturn;
	rXMethodOpen( hPlayer );
	lReturn = rand();
	rXMethodClose( hPlayer );
	return lReturn;
}

long
CALLBACK_FUNCTION(GetAvgLateness)( CALLBACK_VARS )
{
	long lReturn;
	rXMethodOpen( hPlayer );
	lReturn = rand();
	rXMethodClose( hPlayer );
	return lReturn;
}

long
CALLBACK_FUNCTION(GetAvgTardiness)( CALLBACK_VARS )
{
	long lReturn;
	rXMethodOpen( hPlayer );
	lReturn = rand();
	rXMethodClose( hPlayer );
	return lReturn;
}

long
CALLBACK_FUNCTION(GetMaxTardiness)( CALLBACK_VARS )
{
	long lReturn;
	rXMethodOpen( hPlayer );
	lReturn = rand();
	rXMethodClose( hPlayer );
	return lReturn;
}

long
CALLBACK_FUNCTION(GetNumTardyJobs)( CALLBACK_VARS )
{
	long lReturn;
	rXMethodOpen( hPlayer );
	lReturn = rand();
	rXMethodClose( hPlayer );
	return lReturn;
}





/*
------------------------------------------------------------------------------
SAMPLE XOBJECT FUNCTIONS
functions taken from the mac sample xobject and ported
------------------------------------------------------------------------------
*/

long
CALLBACK_FUNCTION(SetMessageLogger)( Obj msgLogger, CALLBACK_VARS )
{
	rXMethodOpen( hPlayer );
	pMe->msgLogger = msgLogger;
    /* send a debug message */
    LogMessage( "mSetMessageLogger: received and message logger set up", pMe );
	rXMethodClose( hPlayer );
	return 0;
}

long
CALLBACK_FUNCTION(GetNumberOfSuccessfulBoards)( long lJobNumber, CALLBACK_VARS )
{
	long lReturn=0;
	rXMethodOpen( hPlayer );
	 if( lJobNumber < 1 || lJobNumber >= lNextJob )
	 {
 		lReturn = -2;
		 LogMessage( "user job doesn't exist", pMe );
	 }
	else {
		lReturn = rand();
	}
	rXMethodClose( hPlayer );
	return lReturn;
}

/*
------------------------------------------------------------------------------
NETCODE functions:
new functions added specifically for the NETCODE simulator and other tests
------------------------------------------------------------------------------
*/                

long
CALLBACK_FUNCTION(SetInitialMarking)( CALLBACK_VARS )
{
	rXMethodOpen( hPlayer );
	 LogMessage( "mSetInitialMarking: starting...", pMe );
	SetInitialMarking();
    /* send a debug message */
    LogMessage( "mSetInitialMarking: marking reset", pMe );
	rXMethodClose( hPlayer );
	return 0;
}

long
CALLBACK_FUNCTION(Step)( CALLBACK_VARS )
{
	rXMethodOpen( hPlayer );

	/* step the petri net*/
	PetriPlayer();
	/*fixflag debugging crash of petriplayer */
	LogMessage( "mStep: received ", pMe );

    pMe->step++;

	/* update the time displayed within director */
	DirectorUpdateTime( pMe );
	
	/* send a log message to verify that the function was called */
	LogMessage( "mStep: received and completed", pMe );           

	rXMethodClose( hPlayer );
	return 0;
}
long
CALLBACK_FUNCTION(Go)( CALLBACK_VARS )
{
	rXMethodOpen( hPlayer );
	/* for now step the petri net until a stop is received */

    /* send a debug message */
    LogMessage( "mGo: received", pMe );

	/* we don't currently know if this will run in the background */
	rXMethodClose( hPlayer );
	return 0;
}

long
CALLBACK_FUNCTION(GoUntilNextCell)( CALLBACK_VARS )
{
	long lReturn;
	rXMethodOpen( hPlayer );
	/* for now step the petri net until a stop is received */

    /* send a debug message */
    LogMessage( "mGoUntilNextCell: received", pMe );
    
    /* keep stepping until the flag is set, or else there are no more 
    	steps to make
    */
    while(!bWaitingJob) {
    	/* exit if there are no more enabled transitions */
    	if(!PetriPlayer())
    		break;
    	pMe->step++;
    	DirectorUpdateTime(pMe);
    }

	lReturn = pnWaitingCell;
	/* we don't currently know if this will run in the background */
	rXMethodClose( hPlayer );
	return lReturn;
}
long
CALLBACK_FUNCTION(GetCurrentWaitingJob)( CALLBACK_VARS )
{
	long lReturn;
	rXMethodOpen( hPlayer );
	/* for now step the petri net until a stop is received */

    /* send a debug message */
    LogMessage( "mGetCurrentWaitingJob: received", pMe );

	lReturn = tvWaitingJob;
	/* we don't currently know if this will run in the background */
	rXMethodClose( hPlayer );
	return lReturn;
}
long
CALLBACK_FUNCTION(GetCurrentWaitingCell)( CALLBACK_VARS )
{
	long lReturn;
	rXMethodOpen( hPlayer );
	/* for now step the petri net until a stop is received */

    /* send a debug message */
    LogMessage( "mGetCurrentWaitingCell: received", pMe );

	lReturn = pnWaitingCell;
	/* we don't currently know if this will run in the background */
	rXMethodClose( hPlayer );
	return lReturn;
}

long
CALLBACK_FUNCTION(GoUntil)( long when, CALLBACK_VARS )
{
	rXMethodOpen( hPlayer );
    /* send a debug message */
    LogMessage( "mGoUntil: received", pMe );
	rXMethodClose( hPlayer );
	return 0;
}

long
CALLBACK_FUNCTION(ResetFloor)( CALLBACK_VARS )
{                     
	rXMethodOpen( hPlayer );
    /* send a debug message */
    LogMessage( "mReseFloor: received", pMe );
    /* for each place in the system... if the place contains a token with a valid
    	serial_no, and the token also is long enough to be a job, then remove
    	the token, clearing its stats, and return to the start place */
	/* need to reset the preload */
	/* fixflag: should reset stats here also */
	rXMethodClose( hPlayer ); 
	return 0;
}

long
CALLBACK_FUNCTION(ResetStats)( CALLBACK_VARS )
{                     
	rXMethodOpen( hPlayer );
    /* send a debug message */
    LogMessage( "mResetStats: received", pMe );
    InitStats(FALSE);
    LogMessage( "mResetStats: completed", pMe );
	rXMethodClose( hPlayer ); 
	return 0;
}

long
CALLBACK_FUNCTION(GetTime)( CALLBACK_VARS )
{
	long lReturn;                  
	rXMethodOpen( hPlayer );
    /* send a debug message */
    LogMessage( "mGetTime: received", pMe );
    /*InitStats(FALSE);*/
    lReturn = totalTime;
	rXMethodClose( hPlayer ); 
	return lReturn;
}




/*
------------------------------------------------------------------------------
Internal Functions:

since these functions are called from within the callbacks, they are passed
pointer to the objects in question, and are not required to call xmethodopen
and xmethodclose, as long as they are used to retrieve the pointer from the
calling function.
------------------------------------------------------------------------------
*/
/* Send a mLogMessage to our logger objects.
	Demonstrate Send( .. mPerform ) call */
#include <stdio.h>
void LogMessage( char *szMsg, NETCODEObjPtr pMe)
{
	TyValue		args[5];                               
	long lArg = 1;                      


	/* if the message logger doesn't exist, then we MUST return */
	if( pMe==NULL || pMe->msgLogger==NULL )
		return;

	/* args[0] will contain the return value after the call */

	/* Arg 1 is the message to send.
		TY_CSTRINGP is only allowed as message name for mPerform */
	args[1].tvType = TY_CSTRINGP;
	args[1].tvValue = (long) "mLogMessage";

	/* Arg 2 is a string that we allocate */
	args[2].tvType = TY_CSTRINGH;
	args[2].tvValue = (long) AllocStringFromPtr( szMsg );

	/* Arg 4 is some number passed to us */
	args[3].tvType = TY_LONGINT;
	args[3].tvValue = lArg;

	/* Dispatch to the instance */
		MsgSendPerform( 3, (long)args, pMe->msgLogger );
                                

	/* We must free the string handle we allocated */
	MsgDisposeHandle( (LxMemHandle)args[2].tvValue );
}

void
DirectorUpdateTime(NETCODEObjPtr pMe)
{
	TyValue		args[5];  
	char		szUpdate[] = "mUpdateTime";

	/* make sure that the net logger is registered */
	if (! pMe->msgLogger)
		return;


	/* args[0] will contain the return value after the call */

	/* Arg 1 is the message to send.
		TY_CSTRINGP is only allowed as message name for mPerform */
	args[1].tvType = TY_CSTRINGP;
	args[1].tvValue = (long) szUpdate;

	/* Arg 2 is a string that we allocate */
	args[2].tvType = TY_LONGINT;
	args[2].tvValue = pMe->step;
 	args[2].tvValue = (long)(net.totalTime*100.0);

	/* Dispatch to the instance */
	MsgSendPerform( 2, (long)args, pMe->msgLogger );
}

void InitNodeNumbers( )
{
	/*
	initialize the matrix of node numbers so that director is allowed
	to retrieve information about the current state of the network

	this function assumes that every place in the main net between 0
	and CELLS_PER_FLOOR is a macro place representing a process
	and that every place in a process between 1 and MACHINES_PER_PROCESS
	are macro CELLS

	this function doesn't bother to check that they all exist, so you
	better be careful!  Should probably return a result code which would
	tell if there was a failure.
	*/

	PLACE_NUMBER i, j, k;

	/* for each process */
	for( i=1; i<=CELLS_PER_FLOOR; i++ ) {
		/* find the wait place for each process */
				/* locate the place */
				PLACE_NUMBER p;
				for( p=0; p<net.placeCount; p++ ) {
					/* must check the transition number for each */
					if( net.place[p].number != 0
						&& net.place[p].number[0] == 2
						/* check process number */
						&& net.place[p].number[1] == i
						/* check machine number */
						&& net.place[p].number[2] == WAIT_PLACE_NUM ) {
							WaitPlace[i] = p;
							break;									
						}		
				}

		/* for each machine */
		for( j=1; j<=MACHINES_PER_PROCESS; j++ ) {
			/* for each transition */
			for( k=0; k<FIRST_PLACE; k++ ) {
				/* locate the transition */
				TRANS_NUMBER t;
				for( t=0; t<net.tranCount; t++ ) {
					/* must check the transition number for each */
					if( net.tran[t].number != 0
						&& net.tran[t].number[0] == 3
						/* check process number */
						&& net.tran[t].number[1] == i
						/* check machine number */
						&& net.tran[t].number[2] == j
						/* lookup machine node number */
						&& net.tran[t].number[3] == MachineNodes[k] ) {
							NodeNumber[i][j][k] = t;
							break;
						}
				}
			}
			/* for each place */
			for( k=FIRST_PLACE; k<=LAST_PLACE; k++ ) {
				/* locate the place */
				PLACE_NUMBER p;
				for( p=0; p<net.placeCount; p++ ) {
					/* must check the transition number for each */
					if( net.place[p].number != 0
						&& net.place[p].number[0] == 3
						/* check process number */
						&& net.place[p].number[1] == i
						/* check machine number */
						&& net.place[p].number[2] == j
						/* lookup machine node number */
						&& net.place[p].number[3] == MachineNodes[k] )		{
							NodeNumber[i][j][k] = p;
							break;											
						}
				}
			}
		}
	}

}


Token *
PlaceFindJob( Place *pPlace, long lJob ) {
	/* try to find the job specified in the place provided */
	/* return null on not found */
	TOKEN_NUMBER t;
	BOOLEAN bFound = FALSE;
	Token *pToken=NULL;
	for( t=0; t<pPlace->tokenCount; t++ ) {
		/* peek the token to see if it is the job */
		pToken = PlacePeekTokenNum( pPlace, t );
		/* now check the length and the first value of the token */
		if( pToken->count > MIN_JOB_LENGTH
			&& pToken->value[0] == lJob ) {
			bFound = TRUE;
			break;
			}
	}
	if( bFound )
		pToken = PlaceRemoveTokenNum( pPlace, t );
	else
		pToken = NULL;
	return pToken;
}

long
CheckCellAndMachine(long lCell, long lMachine, NETCODEObjPtr pMe)
{
	/* check the validity of the cell and machine values passed to the
		machine
		returns 0 on succes, or an error code on failure
	*/

    if( lCell <= 0 || lCell > CELLS_PER_FLOOR )
	{
		LogMessage( "ERROR: Cell out of range", pMe );
		return ERROR_CELL;
	}
	else if( lMachine <= 0 || lMachine > MACHINES_PER_PROCESS )
	{
		LogMessage( "ERROR: machine out of range", pMe );
		return ERROR_MACHINE;
	}

	return 0;
}

long
GetMachineJobProperty( long lCell, long lMachine, long lJobQueuePosition, long lProperty, NETCODEObjPtr pMe )
{
	long lReturn;
   /* first check the cell and machine */
    lReturn = CheckCellAndMachine( lCell, lMachine, pMe );
    if( !lReturn ) {
      PLACE_NUMBER pno;
      Token *pToken;
		/* if we are looking at the in-process job */
      if( lJobQueuePosition == 0 ) {
         /* if there is a part in-process */
         pno = NodeNumber[lCell][lMachine][PLACE_M_PROCESSING];
         pToken = PlacePeekTokenNum( &net.place[pno], 0 );
         if( pToken ) {
         	lReturn = TokenGetColorNum( pToken, lProperty );
         } else
         	lPlayerError = lReturn = ERROR_JOB_NOT_FOUND;
      } else {
      	/* the tokens in the list are measured from 1 */
      	lJobQueuePosition--;
         pno = NodeNumber[lCell][lMachine][PLACE_IN_Q];
         if( lJobQueuePosition >= 0
         	&& lJobQueuePosition < net.place[pno].tokenCount ) {
            pToken = PlacePeekTokenNum( &net.place[pno], lJobQueuePosition );
            if( pToken )
               lReturn = TokenGetColorNum( pToken, lProperty ) ;
            else
	         	lPlayerError = lReturn = ERROR_JOB_NOT_FOUND;
         } else {
         	lPlayerError = lReturn = ERROR_JOB_NOT_FOUND;
         }
      }
    }else{
    	lPlayerError = lReturn;
    }
    return lReturn;
}


/*
------------------------------------------------------------------------------
Obsolete  Functions:

since we have changed the interface along the way to make it easier for
the director scripting, these functions have lost their purpose in the process
------------------------------------------------------------------------------
*/


void
UserChoosing( long lProcess, long lJobNumber )
{
/*
	send a message to director that the job number is waiting at the decision
	place in a process to choose a machine.  This will signal the UI to select
	a place to route it.

   fixflag: obsolete, replaced by gountilnextcell
*/
}


#endif // whole file ifdef DIRECTOR
