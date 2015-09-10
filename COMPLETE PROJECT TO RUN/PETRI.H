/*
    NETCODE colored petri net simulator

    this is the main header file for accessing the data structures and functions
    for the NETMAN simulator called NETCODE.  It loads the proper file based
    on the definition of SUPER_USER.

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/PETRI.H,v 2.22 1997/05/15 04:18:05 gilem Exp $
*/


/* first prevent the header from being loaded more than once */
#ifndef PETRI_H
#define PETRI_H

/* these are all generic definitions which are used throughout the code */
#ifndef FALSE
    #define FALSE 0
#endif

#ifndef TRUE
    #define TRUE 1
#endif

#ifndef NULL
    #define NULL 0
#endif

typedef unsigned short BOOLEAN;

/* define the platform that we are working on, if it is abnormal  */
/* #define DIRECTOR */

/* #define MACOS */
#define MSWIN
/*#define NC_MSDOS*/


/*
    the main data structure can be created in several methods
    the first method used was to dynamically allocate all of the
    parts of the net using malloc.  if none of the following defines
    are used, then malloc is used.  However, some microprocessors
    do not contain malloc in their libraries, and there is also
    an advantage to using static allocation, because the
    majority of the net may be placed in EPROM or ROM in a microprocessor.
    NETMAN generates code of the latter type, and therefore the
    line:
	#define CONST_NET
    must be included in this file to use these type of files
    this line alone does not inhibit the use of malloc for tokens
    but does for the net definition
*/


#define SEGMENTED_MEMORY



/* define if the simulation will be interactive or not */
#ifdef DIRECTOR
	/*
		this is used to allow the use of segmented memory such as DOS or MAC
		by reducing the size of the source functions.  NOTE that this does not
		reduce the memory required to store the main PetriNet.  If the space
		required to store the single block of places or transitions is more
		than 64k, it will still fail to run under DOS.
	*/
	#define SEGMENTED_MEMORY
	#ifndef MACOS
		#define SMALL_POINTERS
	#endif
#else
	#define INTERACTIVE
#endif

#ifdef NC_MSDOS
	#define SEGMENTED_MEMORY
#endif

/* if the net is destined for rom, then use conditional const
    features, else remove all CONDITIONAL_CONST directives */
#ifdef CONST_NET
    #define CONDITIONAL_CONST const
#else
    #define CONDITIONAL_CONST
#endif

#ifdef SMALL_POINTERS
    #define CONDITIONAL_HUGE _huge
#else
    #define CONDITIONAL_HUGE
#endif

/* these are definitions for the numbers which are used to access
    petri net objects.  They can be made smaller or larger to allow trading
    off of size of code/data for size of net allowed.  Code will be added in
    the future to ensure that given a certain datatypes chosen, the user
    doesn't create overflow problems

    some requirements on these assignments:
        the token_number must be at least as large as the place_number
        for colored purposes
*/
typedef int PLACE_NUMBER;
typedef int TOKEN_NUMBER;		/* this should not be unsigned, because it is used for arc weight */
typedef int TOKEN_SIZE;        /* this is the number the 'color' in a token */
typedef int TOKEN_VALUE;        /* this is the value of a 'color' in a token */
typedef int TRANS_NUMBER;
typedef int TRANS_TYPE;
typedef int ARC_NUMBER;
typedef int ARC_INDEX;
typedef unsigned char FLAGS;

/* now load the proper file, based on the definition of the
    preprocessor variable SUPER_USER */
#include "petriusr.h"
#include "superusr.h"
/* no longer allow access to sysfunc, otherwise user can redefine petri nets */
#include "sysfunc.h"

#endif /* PETRI_H */


