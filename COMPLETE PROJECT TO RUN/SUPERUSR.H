/*
    NETCODE colored petri net simulator

    this file includes a single declaration which allows the includer
    of this file to access the global variables in the petrinet.
    In addition, the user has access to all of the structures of
    the petrinet, so that they can be edited directly.   In order
    to access the petrinet in the normal user mode, then include
    the file "petri.h"

    DO NOT INCLUDE THIS FILE DIRECTLY, RATHER INCLUDE PETRI.H
    WITH SUPER_USER defined

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/SUPERUSR.H,v 2.17 1996/05/05 02:05:56 gilem Exp $
*/

#ifndef SUPERUSR_H
#define SUPERUSR_H

/* make sure that petri.h is loaded, in case this was included instead */
#include "petri.h"

/* only allow access to this file based on the state of the super_user variable */
#ifdef SUPER_USER

#include <stdio.h>
#include <stdlib.h>

#define ncmin(a,b)  ((a<b)?(a):(b))
#define ncmax(a,b)  ((a>b)?(a):(b))

/* defines that only the super users need to know */

    /* this assumes that the enabledList type is a signed value */
    #define EMPTY -1

/* data structure definitions */
typedef struct TokenType {
    struct TokenType *next;
    TOKEN_SIZE count;
    TOKEN_VALUE *value;
    /* stats */
    double enterTime;
    } Token;

typedef enum {
        RANDOM=0,
        FIFO=1,
        LIFO=2
        }PlacePolicy;

typedef struct {
    /* token passing policy */
    PlacePolicy policy;

    TOKEN_NUMBER tokenCount;
    Token *tokenList;

    TRANS_NUMBER outputCount;
    CONDITIONAL_CONST TRANS_NUMBER *outputTran;

    /* name */
    CONDITIONAL_CONST char* name;
	CONDITIONAL_CONST PLACE_NUMBER* number;

    /* stats */
    TOKEN_NUMBER totalTokenNum;     /* total max tokens that passed through place */
    double begTime;                 /* timer begins when place becomes occupied */
    double occupied;                /* amount of time place is occupied */
    double timeLastChange;          /* records last time value seen when taking measurements */
    double sumation;                /* calculates sum of all (# tokens)x(amnt of time tokens in place) */
    double minTimeOccupied ;
    double maxTimeOccupied ;
    double timeTokensInPlace;
    BOOLEAN firstTime;
} Place;

typedef void (*FireFunctionPtr)(TRANS_NUMBER);
typedef BOOLEAN (*EnableFunctionPtr)(TRANS_NUMBER);
typedef double (*TimeFunctionPtr)(TRANS_NUMBER);

/* some flags for use with the arc colors
        a special case: if compare_flag, and not value flag, and null pointer to var,
        then it is a don't care condition */
#define COMPARE_FLAG    0x01
#define VALUE_FLAG      0x02

/* define unknown size for arcs, which allow them to be of any size > 0*/
#define UNKNOWN_SIZE	0
typedef struct {
    TOKEN_VALUE* var;
    FLAGS flags;
	TOKEN_SIZE size;  /* the number of token values which will be copied to/from the var
							pointer.  A number of 1 is the normal value, and 0 indicates
							an unknown(but >0).  The zero is only valid for ouptut values
							and the last element of an input arc */
    } ArcColor;

typedef struct {
    TOKEN_NUMBER weight;
    PLACE_NUMBER place;
    ARC_INDEX index;
    TOKEN_SIZE colorCount;
    CONDITIONAL_CONST ArcColor* color;
    } NCTArc;

/* distribution types for a transition */
#define IMMEDIATE       0
#define EXPONENTIAL     1
#define DETERMINISTIC   2

typedef struct {
    TRANS_TYPE type;

    TRANS_NUMBER enabled;
    double resetTime;
    double timeToFire;

    ARC_NUMBER inputCount;
    ARC_NUMBER outputCount;

    CONDITIONAL_CONST NCTArc *inputArc;
    CONDITIONAL_CONST NCTArc *outputArc;

    FireFunctionPtr FireFunction;
    EnableFunctionPtr EnableFunction;
	TimeFunctionPtr TimeFunction;

        /* name */
        CONDITIONAL_CONST char* name;
		CONDITIONAL_CONST PLACE_NUMBER* number;

    /* stats */
        TRANS_NUMBER numOfFirings;
        double totalFireTime;
        double startEnable;
        double minFireTime;
        double maxFireTime;
        BOOLEAN firstTime;

	/* variable transition time data.  If we have a variable transition time
		function, then we must keep track of the first enabling combination */
	long int lFirstCombo;
    } Transition;


typedef enum {
    RUN_FAST,
    RUN_FAIR
    } RunMode;

typedef struct {

    Place *place;
    Transition *tran;

    TRANS_NUMBER tranToFire;
    TRANS_NUMBER tranCurrent;
    double totalTime,lastTime;

    PLACE_NUMBER placeCount;
    TRANS_NUMBER tranCount;
    TRANS_NUMBER enabledCount;

    TRANS_NUMBER *enabledList;
    TRANS_NUMBER *equalList;

    RunMode mode;
    double statStartTime;
    } PetriNet;

/* main.c */
void ShowHelp(void);

/********* enabled.c prototypes *********/
BOOLEAN CanBeEnabled( TRANS_NUMBER );
void FindAllEnabled( void );
void EnableTransition( TRANS_NUMBER );
void MakeInitialEnabledList( void );
void AddToEnabledList( TRANS_NUMBER tran );
void RemoveFromEnabledList( TRANS_NUMBER tran );
void FindEnabled( void );
void DisableTransition( TRANS_NUMBER, BOOLEAN );
BOOLEAN IsEnabled( TRANS_NUMBER );

/********* expo.c prototypes *********/
double Exponential( double );

/********* fire.c prototypes *********/
void PickTransition( void );
void Fire( void );
double FiringTime( TRANS_NUMBER );
void AdjustNetwork( void);

/********* memory.c prototypes **************/
void ClearMarking(void);
void FreeMemory( void );
void InitPlace( PLACE_NUMBER place, char* szName, PLACE_NUMBER pnNumSize, PlacePolicy policy );
void InitArc( NCTArc *pArc, TOKEN_NUMBER weight, PLACE_NUMBER place, ARC_INDEX index, TOKEN_SIZE colorCount );
void InitTransition( TRANS_NUMBER trans, char* szName, PLACE_NUMBER pnNumSize, TRANS_TYPE type, double dResetTime,
                    ARC_NUMBER anIn, ARC_NUMBER anOut,
                    FireFunctionPtr pfFire, EnableFunctionPtr pfEnable, TimeFunctionPtr pfTime );

/********* init.c prototypes *********/
void SetInitialMarking(void);
void InitializeNet(void);
void CheckProperties(void);

#ifndef CONST_NET
    void ZeroPetri( void );
    BOOLEAN AddPlacePointers( void );
    BOOLEAN DimensionNet( PLACE_NUMBER nPlaces, TRANS_NUMBER nTransitions );
    BOOLEAN TransitionDimension( TRANS_NUMBER, ARC_NUMBER nInput, ARC_NUMBER nOutput );
#endif /* CONST_NET */


/********* trans.c prototypes *********/
TRANS_TYPE GetTransitionType( TRANS_NUMBER );
void SetTransitionType( TRANS_NUMBER , TRANS_NUMBER );
double GetTransitionTimeToFire( TRANS_NUMBER );
void SetTransitionTimeToFire( TRANS_NUMBER ,double );
double GetTransitionResetTime( TRANS_NUMBER );
void SetTransitionResetTime( TRANS_NUMBER ,double );
Place* TransGetInputPlace( ARC_INDEX );
Place* TransGetOutputPlace( ARC_INDEX );

/********* place.c prototypes *********/
Token** GetTokenList( Place* );
void PlaceNumAddTokenToEnd( PLACE_NUMBER, Token* );
void PlaceClearMarking( Place *pPlace );

/********* player.c prototypes *********/
BOOLEAN PetriPlayer( void );

/********* print.c prototypes *********/
void PrintMarking( void );
void PrintEnabled( void );
void PrintState( void );
void CloseLogFile( void );

/********* token.c prototypes *********/
void AddToken( Token** , Token * );
void AddTokenToFront( Token** , Token * );
void AddTokenToEnd( Token** , Token * );
Token* NextToken( Token * );
void DeleteToken( Token * );

/************* define.c **********/
#ifndef CONST_NET
    void DefineNet( void );
#endif

/************** marking.c ***************/
void InitialMarking(void);

/* stats.c */
void InitStats(BOOLEAN bTimeZero);
double PercentTimePlaceOccupied (PLACE_NUMBER pNo);
double TimeAvgNumTokensInPlace (PLACE_NUMBER pNo);
double AvgTimeTokenRemainsPlace (PLACE_NUMBER pNo);
double Throughput (TRANS_NUMBER tNo);
double PercentUsage (TRANS_NUMBER tNo);
double AvgTimeFiringOfTran (TRANS_NUMBER tNo);
void StatDisplayAll(void);
void StatDisplayPlace(PLACE_NUMBER pNo);
void StatDisplayTransition(TRANS_NUMBER tNo);
void ShowNetmanNumber(CONDITIONAL_CONST PLACE_NUMBER* subArray);

/********* Global Variables **********/
extern PetriNet     net;
#ifndef MACOS
extern FILE* logFile;
#endif
extern BOOLEAN bQuiet;
extern TOKEN_NUMBER* gIterSpace;

/* token functions */
Token* NewToken( void );
Token* TokenClone(Token *pToken);
void TokenSetColor( Token*, TOKEN_SIZE howMany, ... );
void TokenAddColorToEnd( Token*, TOKEN_VALUE );
void TokenAddColorToFront( Token*, TOKEN_VALUE );
TOKEN_VALUE TokenRemoveColorFromEnd( Token* );
TOKEN_VALUE TokenRemoveColorFromFront( Token* );
void TokenSetColorNum( Token*, TOKEN_SIZE, TOKEN_VALUE );
TOKEN_VALUE TokenGetColorNum( Token*, TOKEN_SIZE );
    /* functions to get/set color to/from arrays */
void TokenArraySetColor( Token*, TOKEN_SIZE howMany, TOKEN_VALUE* array);
void TokenArrayGetColor( Token*, TOKEN_SIZE howMany, TOKEN_VALUE* array);

/* place functions */
    /* use place policy to handle adding and removing tokens */
void PlaceAddToken( Place*, Token* );
Token* PlaceRemoveToken( Place* );

void PlaceAddTokenToEnd( Place*, Token* );
void PlaceAddTokenToFront( Place*, Token* );

Token* PlaceRemoveTokenFromEnd( Place* );
Token* PlaceRemoveTokenFromFront( Place* );
Token* PlaceRemoveRandomToken( Place* );

    /* reference token by number */
TOKEN_NUMBER PlaceGetNumTokens( Place* );
Token* PlacePeekTokenNum( Place*, TOKEN_NUMBER );
Token* PlaceRemoveTokenNum( Place*, TOKEN_NUMBER );

/* transition functions */
int TransGetNumInputArcs( void );
CONDITIONAL_CONST NCTArc* TransGetInputArcByIndex( ARC_INDEX );
CONDITIONAL_CONST NCTArc* TransGetInputArcByOrder( ARC_NUMBER );

int TransGetNumOutputArcs ( void );
CONDITIONAL_CONST NCTArc* TransGetOutputArcByIndex( ARC_INDEX );
CONDITIONAL_CONST NCTArc* TransGetOutputArcByOrder( ARC_NUMBER );

/* arc functions */
int ArcGetWeight( NCTArc* );
ARC_INDEX ArcGetIndex( NCTArc* );
Place* ArcGetPlace( NCTArc* );

/* color.c */
long CalculateFifoValue(void);

/* memlist.c - used for color support */
#define MERGE_ERROR	 -1
#define MERGE_DIFF    0
#define MERGE_SAME	  1
#define MERGE_NOMATCH 2
void memlist_clear(void);
int memlist_merge(TOKEN_VALUE* dest, TOKEN_VALUE* source, TOKEN_SIZE size);
TOKEN_SIZE memlist_LookupSize(TOKEN_VALUE* pTV);
void memlist_backup(void);
void memlist_restore(void);

#endif /* SUPER_USER */
#endif /* SUPERUSR_H */
