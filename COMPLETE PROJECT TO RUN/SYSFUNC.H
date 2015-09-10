/*
    NETCODE colored petri net simulator
    
    all of the functions definitions necessary for the user to access the petri net safely
    most of these functions have been obsoleted with the addition of the colored specification

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/SYSFUNC.H,v 2.11 1996/04/17 03:02:39 gilem Exp $
*/

#ifndef SYSFUNC_H
#define SYSFUNC_H

/* make sure that petri.h is loaded, in case this was included instead */
#include "petri.h"

/* begin function declarations for functions which are accessible to the user */

/* print functions */
int logprintf( const char* ptr, ... );
int logerror( const char* ptr, ... );

#endif /* SYSFUNC_H */





