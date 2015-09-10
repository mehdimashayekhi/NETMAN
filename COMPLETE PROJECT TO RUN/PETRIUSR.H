/*
    NETCODE colored petri net simulator

    all of the functions definitions necessary for the user to access the petri net safely

    this header should be included, and not petri.h, in order to allow the user
    to access the net without changing the basic functionality of the petri net
    if the user wishes to change the basic functionality of the petri net
    then petri.h is needed

    DO NOT INCLUDE THIS FILE DIRECTLY, RATHER INCLUDE PETRI.H
    WITH SUPER_USER UNdefined

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\projects\netman.vc\simulate\petriout/RCS/PETRIUSR.H,v 1.98 1995/11/14 13:36:49 gilem Exp $
*/

#ifndef PETRIUSR_H
#define PETRIUSR_H

/* make sure that petri.h is loaded, in case this was included instead */
#include "petri.h"

double ncGetTime(void);
int ncGetIntTime(void);

/* only allow this file to load if SUPER_USER is declared */
#ifndef SUPER_USER

    /* give the user NULL structure definitions, so that they cannot access the members */
    typedef struct TokenType Token;
    typedef struct PlaceType Place;
    typedef struct ArcType NCTArc;

#endif /* SUPER_USER */
#endif /* PETRIUSR_H */


