/*
------------------------------------------------------------------------------
Portability 
Macros and Types: NOTE: these are platform dependent
	the prefix for MSWIN will change dependent on the name of the xobject

	one problem is that the mac uses a value for types which are in
	a structure TyValue { short tvType, long tvValue } whereas windows uses
	LxValue { ty, it }.  Because of this confusion, and because the mac
	version has longer names, we will create typedefs for windows
	to use the mac version of the header.

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/DPLAYER.H,v 2.19 1996/06/17 20:10:09 gilem Exp $

------------------------------------------------------------------------------
*/

#ifndef DPLAYER_H
#define DPLAYER_H

#ifdef DIRECTOR

#ifdef MSWIN
	#include <windows.h>
#endif

#include "XObject.h"

#ifdef MACOS

	/* 
		FUNCTIONS omitted by the mac roms, 
		yet included in the MSWindows XObject library:
 	*/
	Handle CloneHandle(Handle);
	
	
	/* 
		PORTABILITY MACROS intended to be used in place of both the 
		Windows and the Macintosh versions of the XObject code.
	*/
	#define CALLBACK_FUNCTION(name) pascal Method##name
	#define DIRECTOR_PREFIX_
	#define CALLBACK_VARS       MsgId msg, NETCODEObjHandle hPlayer
    typedef char *LPSTR;

	/* on the mac, the hPlayer handle is just a pointer to a pointer */
	#define rXMethodOpen(x)		NETCODEObjPtr pMe; \
								XMethodOpen(x);     \
								pMe = *x;

	#define rXMethodClose(x)	XMethodClose(x)

	/* to allow the same header for the structure below */
	/* we will use the windows LxMemHandle to avoid confunsion with the
		windows.h HANDLE and the mac Handle */
	typedef struct XObj LxXObjHeader;
	typedef Handle LxMemHandle;

	/* abstract the alloc string function */
	#define AllocStringFromPtr	CStrToHandle

	/* mac function to call send like the windows dedicated functions */
	/* change the order of the msgsendperform so that it matches the windows functions */
	#define MsgSendPerform(x,y,z)	Send( (long) x, y, mPerform, z )
	#define MsgDisposeHandle    	DisposHandle
	#define MsgSetHandleSize     	SetHandleSize
	#define MsgCloneHandle			CloneHandle
	#define MsgSetMyHandleSize		SetHandleSize
#endif

#ifdef MSWIN
    #define CALLBACK_FUNCTION(name)  __far __pascal __export _netcode_m##name
	#define DIRECTOR_PREFIX_    pMe->myxtbl->
	#define CALLBACK_VARS       LxProcTablePtr xtbl, LxMemHandle hPlayer

	/* on windows, the hPlayer handle must be locked to find the pointer,
		also store the xtbl in the pointer to me */
	#define rXMethodOpen(x)		NETCODEObjPtr pMe;                             \
								pMe = xtbl->mem_Lock(x);                       \
								gpMe = pMe;									\
								pMe->myxtbl = xtbl;

	#define rXMethodClose(x)    xtbl->mem_Unlock(x);

	typedef LxMemHandle Obj;

	/* definitions for the polymorphic data types, so we can use
		the mac versions of the type */
	typedef LxValue TyValue;
	typedef LxValuePtr TyValuePtr;
	#define tvType				ty
	#define tvValue				it
	#define TY_CSTRINGP			TY_STRING_PTR
	#define TY_CSTRINGH			TY_STRING

	/* abstract the alloc string from ptr char function */
	#define AllocStringFromPtr	pMe->myxtbl->string_New

	/* message functions to call the proper function */
	#define MsgSendPerform		pMe->myxtbl->SendPerform
	#define MsgDisposeHandle	pMe->myxtbl->mem_Dispose
	#define MsgSetHandleSize	pMe->myxtbl->mem_SetSize
	#define MsgCloneHandle      pMe->myxtbl->mem_Clone
	#define MsgSetMyHandleSize	xtbl->mem_SetSize /* only used in msgnew */
#endif

/* 

this is the structure definition for the data associated with each
xobject.  The first member is all that is necessary (on either platform)
to make the xobject work.   The XClassBegin stuff used in the mac header
make it too difficult to access the variables, requiring the use of
macros.  We will therefore just create the strucure by hand, which doesn't
look any more ugly.

It would eventually be nice to add the basic netcode 'net' global to this 
structure to allow multiple instantiations of the netcode class, but for now
this would be more work that it is worth, so we are stuck with the global

*/
typedef struct
{
	/* Required header for ALL XObject data types */
	LxXObjHeader        baseObjectVars;
	/* end required data */

	LxMemHandle         hErrMsg;        /* Sample instance data: handle */
	long	count;		/* you must have at least one instance variable!	*/
	Obj		msgLogger;	/* target of mLogMessage */
	long 	step;

#ifdef MSWIN
	/* begin required data for windows version, to store the xtbl pointer */
	LxProcTablePtr myxtbl;
#endif

	/* define structure, pointer to struct, and handle to struct */
}   NETCODEObj, *NETCODEObjPtr, **NETCODEObjHandle;

/*
------------------------------------------------------------------------------
Constants:
------------------------------------------------------------------------------
*/
/* for now we define all error codes to be negative, to simplify return
codes.  a negative return value indicates one of these errors */
#define ERROR_NUM_CODES	 	4// max error + 1
#define ERROR_SUCCESS        0       // Successful return code
#define ERROR_MEM_ALLOC     -1       // Memory allocation error
#define ERROR_CELL			-2       // out of range cell
#define ERROR_MACHINE		-3		// out of range machine
#define ERROR_WAIT_CELL		-4
#define ERROR_WAIT_JOB		-5
#define ERROR_WAIT_JOB_FIND -6
#define ERROR_TOO_MANY_JOBS -7
#define ERROR_JOB_NOT_FOUND -8

#define MIN_JOB_LENGTH		20	// min length of a token to be a job
#define JR_SERIAL			0
#define JR_RELEASE_TIME		1
#define	JR_DUE_DATE			2
#define JR_BOARD			3
#define JR_SMT				4
#define JR_THROUGH			5
#define JR_MANUAL			6
#define JR_STEP				7
#define JR_CURRENT_MACHINE   9	// index into the job token of the current machine
#define JR_PROCESS_TIME		11

#define JOB_DATA			8   // color length
#define JOB_STEP_SIZE		9

#define JOB_MAX_CELL		17
#define JOB_LENGTH			(JOB_MAX_CELL*JOB_STEP_SIZE+JOB_DATA)
/*
------------------------------------------------------------------------------
Globals:
------------------------------------------------------------------------------
*/

extern NETCODEObjPtr gpMe;     

void LogMessage( char *msg, NETCODEObjPtr pMe); 

/*
------------------------------------------------------------------------------
Function Prototypes:
------------------------------------------------------------------------------
*/

/* callback functions which were built into the original windows example */
long 		CALLBACK_FUNCTION(New)( CALLBACK_VARS );
long 		CALLBACK_FUNCTION(Dispose)( CALLBACK_VARS );
LxMemHandle CALLBACK_FUNCTION(Name)( CALLBACK_VARS );
long 		CALLBACK_FUNCTION(Status)( CALLBACK_VARS );
LxMemHandle CALLBACK_FUNCTION(GetErrorString)( long lErrorCode, CALLBACK_VARS);

/* functions taken from the mac sample xobject and ported */
long 		CALLBACK_FUNCTION(SetBeepCount) (long num, CALLBACK_VARS );
long 		CALLBACK_FUNCTION(Beep) (long nArgs, TyValuePtr argp, CALLBACK_VARS );
long 		CALLBACK_FUNCTION(SetMessageLogger)( Obj msgLogger, CALLBACK_VARS );

/* new functions added specifically for the NETCODE simulator and other tests */
long 		CALLBACK_FUNCTION(SetInitialMarking)( CALLBACK_VARS );
long 		CALLBACK_FUNCTION(Step)( CALLBACK_VARS );
long 		CALLBACK_FUNCTION(Go)( CALLBACK_VARS );
long 		CALLBACK_FUNCTION(GoUntil)( long when, CALLBACK_VARS );
long		CALLBACK_FUNCTION(GoUntilNextCell)( CALLBACK_VARS );
long		CALLBACK_FUNCTION(GetCurrentWaitingJob)(CALLBACK_VARS);
long		CALLBACK_FUNCTION(GetCurrentWaitingCell)(CALLBACK_VARS);
long 		CALLBACK_FUNCTION(ResetFloor)(CALLBACK_VARS);
long 		CALLBACK_FUNCTION(ResetStats)( CALLBACK_VARS );

/* internal functions which are not callbacks */
void DirectorUpdateTime(NETCODEObjPtr pMe);
void InitNodeNumbers( void ); 
void UserChoosing( long lProcess, long lJobNumber );
void LogMessage( char *szMsg, NETCODEObjPtr pMe);
long CheckCellAndMachine(long lCell, long lMachine, NETCODEObjPtr pMe);
Token *PlaceFindJob( Place *pPlace, long lJob );
long GetMachineJobProperty( long lCell, long lMachine, long lJobQueuePosition, long lProperty, NETCODEObjPtr pMe );

/* callback functions from director specifically for simulator */
long		CALLBACK_FUNCTION(GetTime)( CALLBACK_VARS );

long 		CALLBACK_FUNCTION(SetMachineType)( long lCell, long lMachine, long lType, CALLBACK_VARS );
long		CALLBACK_FUNCTION(GetMachineType)( long lCell, long lMachine, CALLBACK_VARS );
long		CALLBACK_FUNCTION(SetFloorLoad)( long lSampleLoad, CALLBACK_VARS );
long 		CALLBACK_FUNCTION(GetFloorLoad)( CALLBACK_VARS );
long		CALLBACK_FUNCTION(AddUserJob)( long lBoards, long lOnsertion, long lInsertion, long lManual, long lReleaseTime, long lDueDate, CALLBACK_VARS );
long		CALLBACK_FUNCTION(SetMachineQueueDiscipline)( long lCell, long lMachine, long lQueueDiscipline, CALLBACK_VARS );
long		CALLBACK_FUNCTION(GetMachineQueueDiscipline)( long lCell, long lMachine, CALLBACK_VARS );
long 		CALLBACK_FUNCTION(TryUserJob)( long lCell, long lMachine, long lJob, CALLBACK_VARS );
long		CALLBACK_FUNCTION(RemoveUserJob)( long lCell, long lMachine, long lJob, CALLBACK_VARS );

long		CALLBACK_FUNCTION(GetMachineNumberOfJobsInQueue)( long lCell, long lMachine, CALLBACK_VARS );
long		CALLBACK_FUNCTION(GetMachineRemainingProcessingTime)( long lCell, long lMachine, CALLBACK_VARS );
long		CALLBACK_FUNCTION(GetMachineJobExpectedProcessingTime)( long lCell, long lMachine, long lJobQueuePosition, CALLBACK_VARS );
long		CALLBACK_FUNCTION(GetMachineJobNumber)( long lCell, long lMachine, long lJobQueuePosition, CALLBACK_VARS );
long		CALLBACK_FUNCTION(GetMachineJobReleaseTime)( long lCell, long lMachine, long lJobQueuePosition, CALLBACK_VARS );
long		CALLBACK_FUNCTION(GetMachineJobDueDate)( long lCell, long lMachine, long lJobQueuePosition, CALLBACK_VARS );

long		CALLBACK_FUNCTION(GetUtilization)( long lCell, long lMachine, CALLBACK_VARS );
long		CALLBACK_FUNCTION(GetFlowtime)( long lJobNumber, CALLBACK_VARS );
long		CALLBACK_FUNCTION(GetMakespan)( CALLBACK_VARS );
long		CALLBACK_FUNCTION(GetAvgLateness)( CALLBACK_VARS );
long		CALLBACK_FUNCTION(GetAvgTardiness)( CALLBACK_VARS );
long		CALLBACK_FUNCTION(GetMaxTardiness)( CALLBACK_VARS );
long		CALLBACK_FUNCTION(GetNumTardyJobs)( CALLBACK_VARS );
long        CALLBACK_FUNCTION(GetNumberOfSuccessfulBoards)( long lJobNumber, CALLBACK_VARS );



#endif // DIRECTOR
#endif // DPLAYER_H
