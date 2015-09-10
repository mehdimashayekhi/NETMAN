/* this file was generated from the NETMAN file:
	define30.c
	06/18/14 13:17:42
*/
#define SUPER_USER
#include "petri.h"
#include "userfunc.h"
#include <stdlib.h>

#ifndef CONST_NET
#ifdef SEGMENTED_MEMORY
void DefineNet30()
{
NCTArc *parcInputs, *parcOutputs;

InitTransition( 1950, "", 4, 2, 1.4, 1, 1, NULL, NULL, NULL );
net.tran[1950].number[1] = -18;
net.tran[1950].number[2] = 6;
net.tran[1950].number[3] = 14;
parcInputs = net.tran[1950].inputArc;
parcOutputs = net.tran[1950].outputArc;
InitArc( &parcInputs[0], 1, 1786, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1787, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;

InitTransition( 1951, "", 4, 0, 0, 1, 1, NULL, NULL, NULL );
net.tran[1951].number[1] = -18;
net.tran[1951].number[2] = 6;
net.tran[1951].number[3] = 15;
parcInputs = net.tran[1951].inputArc;
parcOutputs = net.tran[1951].outputArc;
InitArc( &parcInputs[0], 1, 1787, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1788, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;

InitTransition( 1952, "", 4, 2, 1, 1, 1, NULL, NULL, NULL );
net.tran[1952].number[1] = -18;
net.tran[1952].number[2] = 6;
net.tran[1952].number[3] = 16;
parcInputs = net.tran[1952].inputArc;
parcOutputs = net.tran[1952].outputArc;
InitArc( &parcInputs[0], 1, 1788, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1789, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;

InitTransition( 1953, "", 3, 0, 0, 2, 2, NULL, NULL, NULL );
net.tran[1953].number[1] = -18;
net.tran[1953].number[2] = 0;
parcInputs = net.tran[1953].inputArc;
parcOutputs = net.tran[1953].outputArc;
InitArc( &parcInputs[0], 1, 1603, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcInputs[1], 1, 1773, 0, 0 );
InitArc( &parcOutputs[0], 1, 1604, 0, 0 );
InitArc( &parcOutputs[1], 1, 1778, 0, 3 );
parcOutputs[1].color[0].var = &vehicle ;
parcOutputs[1].color[0].flags = 0 ;
parcOutputs[1].color[0].size = 1 ;
parcOutputs[1].color[1].var = &intersection ;
parcOutputs[1].color[1].flags = 0 ;
parcOutputs[1].color[1].size = 1 ;
parcOutputs[1].color[2].var = &bay ;
parcOutputs[1].color[2].flags = 0 ;
parcOutputs[1].color[2].size = 1 ;

InitTransition( 1954, "", 3, 0, 0, 2, 1, NULL, NULL, NULL );
net.tran[1954].number[1] = -18;
net.tran[1954].number[2] = 1;
parcInputs = net.tran[1954].inputArc;
parcOutputs = net.tran[1954].outputArc;
InitArc( &parcInputs[0], 1, 1777, 0, 0 );
InitArc( &parcInputs[1], 1, 1789, 0, 3 );
parcInputs[1].color[0].var = &vehicle ;
parcInputs[1].color[0].flags = 0 ;
parcInputs[1].color[0].size = 1 ;
parcInputs[1].color[1].var = &intersection ;
parcInputs[1].color[1].flags = 0 ;
parcInputs[1].color[1].size = 1 ;
parcInputs[1].color[2].var = &bay ;
parcInputs[1].color[2].flags = 0 ;
parcInputs[1].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1774, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;

InitTransition( 1955, "", 3, 2, 1.4, 1, 1, NULL, NULL, NULL );
net.tran[1955].number[1] = -18;
net.tran[1955].number[2] = 2;
parcInputs = net.tran[1955].inputArc;
parcOutputs = net.tran[1955].outputArc;
InitArc( &parcInputs[0], 1, 1774, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1775, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;

InitTransition( 1956, "", 3, 0, 0, 1, 1, NULL, NULL, NULL );
net.tran[1956].number[1] = -18;
net.tran[1956].number[2] = 3;
parcInputs = net.tran[1956].inputArc;
parcOutputs = net.tran[1956].outputArc;
InitArc( &parcInputs[0], 1, 1775, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1776, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;

InitTransition( 1957, "", 3, 0, 0, 1, 3, TF_12_4, NULL, NULL );
net.tran[1957].number[1] = -18;
net.tran[1957].number[2] = 4;
parcInputs = net.tran[1957].inputArc;
parcOutputs = net.tran[1957].outputArc;
InitArc( &parcInputs[0], 1, 1776, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 277, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[1], 1, 1773, 0, 0 );
InitArc( &parcOutputs[2], 1, 1777, 0, 0 );

InitTransition( 1958, "", 2, 0, 0, 1, 1, TF_0_18, NULL, NULL );
net.tran[1958].number[1] = 18;
parcInputs = net.tran[1958].inputArc;
parcOutputs = net.tran[1958].outputArc;
InitArc( &parcInputs[0], 1, 263, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 264, 0, 0 );

InitTransition( 1959, "", 2, 0, 0, 1, 1, TF_0_19, NULL, NULL );
net.tran[1959].number[1] = 19;
parcInputs = net.tran[1959].inputArc;
parcOutputs = net.tran[1959].outputArc;
InitArc( &parcInputs[0], 1, 231, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 232, 0, 0 );

InitTransition( 1960, "", 2, 0, 0, 1, 1, TF_0_20, NULL, NULL );
net.tran[1960].number[1] = 20;
parcInputs = net.tran[1960].inputArc;
parcOutputs = net.tran[1960].outputArc;
InitArc( &parcInputs[0], 1, 765, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 766, 0, 0 );

InitTransition( 1961, "", 2, 0, 0, 1, 1, TF_0_21, NULL, NULL );
net.tran[1961].number[1] = 21;
parcInputs = net.tran[1961].inputArc;
parcOutputs = net.tran[1961].outputArc;
InitArc( &parcInputs[0], 1, 789, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 790, 0, 0 );

InitTransition( 1962, "", 2, 0, 0, 1, 1, TF_0_22, NULL, NULL );
net.tran[1962].number[1] = 22;
parcInputs = net.tran[1962].inputArc;
parcOutputs = net.tran[1962].outputArc;
InitArc( &parcInputs[0], 1, 797, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 798, 0, 0 );

InitTransition( 1963, "", 2, 0, 0, 1, 1, TF_0_23, NULL, NULL );
net.tran[1963].number[1] = 23;
parcInputs = net.tran[1963].inputArc;
parcOutputs = net.tran[1963].outputArc;
InitArc( &parcInputs[0], 1, 1328, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1329, 0, 0 );

InitTransition( 1964, "", 2, 0, 0, 1, 1, TF_0_24, NULL, NULL );
net.tran[1964].number[1] = 24;
parcInputs = net.tran[1964].inputArc;
parcOutputs = net.tran[1964].outputArc;
InitArc( &parcInputs[0], 1, 1336, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1337, 0, 0 );

InitTransition( 1965, "", 2, 0, 0, 1, 1, TF_0_25, NULL, NULL );
net.tran[1965].number[1] = 25;
parcInputs = net.tran[1965].inputArc;
parcOutputs = net.tran[1965].outputArc;
InitArc( &parcInputs[0], 1, 1317, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1318, 0, 0 );

InitTransition( 1966, "", 2, 0, 0, 1, 1, TF_0_26, NULL, NULL );
net.tran[1966].number[1] = 26;
parcInputs = net.tran[1966].inputArc;
parcOutputs = net.tran[1966].outputArc;
InitArc( &parcInputs[0], 1, 1571, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1572, 0, 0 );

InitTransition( 1967, "", 2, 0, 0, 1, 1, TF_0_27, NULL, NULL );
net.tran[1967].number[1] = 27;
parcInputs = net.tran[1967].inputArc;
parcOutputs = net.tran[1967].outputArc;
InitArc( &parcInputs[0], 1, 1584, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1585, 0, 0 );

InitTransition( 1968, "", 2, 0, 0, 1, 1, TF_0_28, NULL, NULL );
net.tran[1968].number[1] = 28;
parcInputs = net.tran[1968].inputArc;
parcOutputs = net.tran[1968].outputArc;
InitArc( &parcInputs[0], 1, 1595, 0, 3 );
parcInputs[0].color[0].var = &vehicle ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &intersection ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &bay ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1596, 0, 0 );

InitTransition( 1969, "", 2, 2, 0, 1, 2, TF_0_29, NULL, TT_0_29 );
net.tran[1969].number[1] = 29;
parcInputs = net.tran[1969].inputArc;
parcOutputs = net.tran[1969].outputArc;
InitArc( &parcInputs[0], 1, 1607, 0, 3 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &a2 ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &a3 ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[1], 1, 1607, 0, 3 );
parcOutputs[1].color[0].var = &a1 ;
parcOutputs[1].color[0].flags = 0 ;
parcOutputs[1].color[0].size = 1 ;
parcOutputs[1].color[1].var = &a2 ;
parcOutputs[1].color[1].flags = 0 ;
parcOutputs[1].color[1].size = 1 ;
parcOutputs[1].color[2].var = &a3 ;
parcOutputs[1].color[2].flags = 0 ;
parcOutputs[1].color[2].size = 1 ;

InitTransition( 1970, "", 2, 2, 0, 1, 2, TF_0_30, NULL, TT_0_30 );
net.tran[1970].number[1] = 30;
parcInputs = net.tran[1970].inputArc;
parcOutputs = net.tran[1970].outputArc;
InitArc( &parcInputs[0], 1, 1608, 0, 3 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &a2 ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &a3 ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 10, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[1], 1, 1608, 0, 3 );
parcOutputs[1].color[0].var = &a1 ;
parcOutputs[1].color[0].flags = 0 ;
parcOutputs[1].color[0].size = 1 ;
parcOutputs[1].color[1].var = &a2 ;
parcOutputs[1].color[1].flags = 0 ;
parcOutputs[1].color[1].size = 1 ;
parcOutputs[1].color[2].var = &a3 ;
parcOutputs[1].color[2].flags = 0 ;
parcOutputs[1].color[2].size = 1 ;

InitTransition( 1971, "", 2, 2, 0, 1, 2, TF_0_31, NULL, TT_0_31 );
net.tran[1971].number[1] = 31;
parcInputs = net.tran[1971].inputArc;
parcOutputs = net.tran[1971].outputArc;
InitArc( &parcInputs[0], 1, 1616, 0, 3 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &a2 ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &a3 ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1350, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[1], 1, 1616, 0, 3 );
parcOutputs[1].color[0].var = &a1 ;
parcOutputs[1].color[0].flags = 0 ;
parcOutputs[1].color[0].size = 1 ;
parcOutputs[1].color[1].var = &a2 ;
parcOutputs[1].color[1].flags = 0 ;
parcOutputs[1].color[1].size = 1 ;
parcOutputs[1].color[2].var = &a3 ;
parcOutputs[1].color[2].flags = 0 ;
parcOutputs[1].color[2].size = 1 ;

InitTransition( 1972, "", 2, 2, 0, 1, 2, TF_0_32, NULL, TT_0_32 );
net.tran[1972].number[1] = 32;
parcInputs = net.tran[1972].inputArc;
parcOutputs = net.tran[1972].outputArc;
InitArc( &parcInputs[0], 1, 1614, 0, 3 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &a2 ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &a3 ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 544, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[1], 1, 1614, 0, 3 );
parcOutputs[1].color[0].var = &a1 ;
parcOutputs[1].color[0].flags = 0 ;
parcOutputs[1].color[0].size = 1 ;
parcOutputs[1].color[1].var = &a2 ;
parcOutputs[1].color[1].flags = 0 ;
parcOutputs[1].color[1].size = 1 ;
parcOutputs[1].color[2].var = &a3 ;
parcOutputs[1].color[2].flags = 0 ;
parcOutputs[1].color[2].size = 1 ;

InitTransition( 1973, "", 2, 2, 0, 1, 2, TF_0_33, NULL, TT_0_33 );
net.tran[1973].number[1] = 33;
parcInputs = net.tran[1973].inputArc;
parcOutputs = net.tran[1973].outputArc;
InitArc( &parcInputs[0], 1, 1612, 0, 3 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &a2 ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &a3 ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 535, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[1], 1, 1612, 0, 3 );
parcOutputs[1].color[0].var = &a1 ;
parcOutputs[1].color[0].flags = 0 ;
parcOutputs[1].color[0].size = 1 ;
parcOutputs[1].color[1].var = &a2 ;
parcOutputs[1].color[1].flags = 0 ;
parcOutputs[1].color[1].size = 1 ;
parcOutputs[1].color[2].var = &a3 ;
parcOutputs[1].color[2].flags = 0 ;
parcOutputs[1].color[2].size = 1 ;

InitTransition( 1974, "", 2, 2, 0, 1, 2, TF_0_34, NULL, TT_0_34 );
net.tran[1974].number[1] = 34;
parcInputs = net.tran[1974].inputArc;
parcOutputs = net.tran[1974].outputArc;
InitArc( &parcInputs[0], 1, 1610, 0, 3 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &a2 ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &a3 ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1074, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[1], 1, 1610, 0, 3 );
parcOutputs[1].color[0].var = &a1 ;
parcOutputs[1].color[0].flags = 0 ;
parcOutputs[1].color[0].size = 1 ;
parcOutputs[1].color[1].var = &a2 ;
parcOutputs[1].color[1].flags = 0 ;
parcOutputs[1].color[1].size = 1 ;
parcOutputs[1].color[2].var = &a3 ;
parcOutputs[1].color[2].flags = 0 ;
parcOutputs[1].color[2].size = 1 ;

InitTransition( 1975, "", 2, 2, 0, 1, 2, TF_0_35, NULL, TT_0_35 );
net.tran[1975].number[1] = 35;
parcInputs = net.tran[1975].inputArc;
parcOutputs = net.tran[1975].outputArc;
InitArc( &parcInputs[0], 1, 1609, 0, 3 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &a2 ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &a3 ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1075, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[1], 1, 1609, 0, 3 );
parcOutputs[1].color[0].var = &a1 ;
parcOutputs[1].color[0].flags = 0 ;
parcOutputs[1].color[0].size = 1 ;
parcOutputs[1].color[1].var = &a2 ;
parcOutputs[1].color[1].flags = 0 ;
parcOutputs[1].color[1].size = 1 ;
parcOutputs[1].color[2].var = &a3 ;
parcOutputs[1].color[2].flags = 0 ;
parcOutputs[1].color[2].size = 1 ;

InitTransition( 1976, "", 2, 2, 0, 1, 2, TF_0_36, NULL, TT_0_36 );
net.tran[1976].number[1] = 36;
parcInputs = net.tran[1976].inputArc;
parcOutputs = net.tran[1976].outputArc;
InitArc( &parcInputs[0], 1, 1611, 0, 3 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &a2 ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &a3 ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1073, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[1], 1, 1611, 0, 3 );
parcOutputs[1].color[0].var = &a1 ;
parcOutputs[1].color[0].flags = 0 ;
parcOutputs[1].color[0].size = 1 ;
parcOutputs[1].color[1].var = &a2 ;
parcOutputs[1].color[1].flags = 0 ;
parcOutputs[1].color[1].size = 1 ;
parcOutputs[1].color[2].var = &a3 ;
parcOutputs[1].color[2].flags = 0 ;
parcOutputs[1].color[2].size = 1 ;

InitTransition( 1977, "", 2, 2, 0, 1, 2, TF_0_37, NULL, TT_0_37 );
net.tran[1977].number[1] = 37;
parcInputs = net.tran[1977].inputArc;
parcOutputs = net.tran[1977].outputArc;
InitArc( &parcInputs[0], 1, 1613, 0, 3 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &a2 ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &a3 ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 534, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[1], 1, 1613, 0, 3 );
parcOutputs[1].color[0].var = &a1 ;
parcOutputs[1].color[0].flags = 0 ;
parcOutputs[1].color[0].size = 1 ;
parcOutputs[1].color[1].var = &a2 ;
parcOutputs[1].color[1].flags = 0 ;
parcOutputs[1].color[1].size = 1 ;
parcOutputs[1].color[2].var = &a3 ;
parcOutputs[1].color[2].flags = 0 ;
parcOutputs[1].color[2].size = 1 ;

InitTransition( 1978, "", 2, 2, 0, 1, 2, TF_0_38, NULL, TT_0_38 );
net.tran[1978].number[1] = 38;
parcInputs = net.tran[1978].inputArc;
parcOutputs = net.tran[1978].outputArc;
InitArc( &parcInputs[0], 1, 1615, 0, 3 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &a2 ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &a3 ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1340, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[1], 1, 1615, 0, 3 );
parcOutputs[1].color[0].var = &a1 ;
parcOutputs[1].color[0].flags = 0 ;
parcOutputs[1].color[0].size = 1 ;
parcOutputs[1].color[1].var = &a2 ;
parcOutputs[1].color[1].flags = 0 ;
parcOutputs[1].color[1].size = 1 ;
parcOutputs[1].color[2].var = &a3 ;
parcOutputs[1].color[2].flags = 0 ;
parcOutputs[1].color[2].size = 1 ;

InitTransition( 1979, "", 2, 2, 0, 1, 2, TF_0_39, NULL, TT_0_39 );
net.tran[1979].number[1] = 39;
parcInputs = net.tran[1979].inputArc;
parcOutputs = net.tran[1979].outputArc;
InitArc( &parcInputs[0], 1, 1617, 0, 3 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
parcInputs[0].color[1].var = &a2 ;
parcInputs[0].color[1].flags = 0 ;
parcInputs[0].color[1].size = 1 ;
parcInputs[0].color[2].var = &a3 ;
parcInputs[0].color[2].flags = 0 ;
parcInputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[0], 1, 1342, 0, 3 );
parcOutputs[0].color[0].var = &vehicle ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;
parcOutputs[0].color[1].var = &intersection ;
parcOutputs[0].color[1].flags = 0 ;
parcOutputs[0].color[1].size = 1 ;
parcOutputs[0].color[2].var = &bay ;
parcOutputs[0].color[2].flags = 0 ;
parcOutputs[0].color[2].size = 1 ;
InitArc( &parcOutputs[1], 1, 1617, 0, 3 );
parcOutputs[1].color[0].var = &a1 ;
parcOutputs[1].color[0].flags = 0 ;
parcOutputs[1].color[0].size = 1 ;
parcOutputs[1].color[1].var = &a2 ;
parcOutputs[1].color[1].flags = 0 ;
parcOutputs[1].color[1].size = 1 ;
parcOutputs[1].color[2].var = &a3 ;
parcOutputs[1].color[2].flags = 0 ;
parcOutputs[1].color[2].size = 1 ;

InitTransition( 1980, "", 2, 0, 0, 1, 1, TF_0_40, NULL, NULL );
net.tran[1980].number[1] = 40;
parcInputs = net.tran[1980].inputArc;
parcOutputs = net.tran[1980].outputArc;
InitArc( &parcInputs[0], 1, 1619, 0, 1 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
InitArc( &parcOutputs[0], 1, 167, 0, 1 );
parcOutputs[0].color[0].var = &intersection ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;

InitTransition( 1981, "", 2, 0, 0, 1, 1, TF_0_41, NULL, NULL );
net.tran[1981].number[1] = 41;
parcInputs = net.tran[1981].inputArc;
parcOutputs = net.tran[1981].outputArc;
InitArc( &parcInputs[0], 1, 1620, 0, 1 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
InitArc( &parcOutputs[0], 1, 1240, 0, 1 );
parcOutputs[0].color[0].var = &intersection ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;

InitTransition( 1982, "", 2, 0, 0, 1, 1, TF_0_42, NULL, NULL );
net.tran[1982].number[1] = 42;
parcInputs = net.tran[1982].inputArc;
parcOutputs = net.tran[1982].outputArc;
InitArc( &parcInputs[0], 1, 1621, 0, 1 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
InitArc( &parcOutputs[0], 1, 701, 0, 1 );
parcOutputs[0].color[0].var = &intersection ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;

InitTransition( 1983, "", 2, 0, 0, 1, 1, TF_0_43, NULL, NULL );
net.tran[1983].number[1] = 43;
parcInputs = net.tran[1983].inputArc;
parcOutputs = net.tran[1983].outputArc;
InitArc( &parcInputs[0], 1, 1622, 0, 1 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
InitArc( &parcOutputs[0], 1, 1507, 0, 1 );
parcOutputs[0].color[0].var = &intersection ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;

InitTransition( 1984, "", 2, 0, 0, 1, 1, TF_0_44, NULL, NULL );
net.tran[1984].number[1] = 44;
parcInputs = net.tran[1984].inputArc;
parcOutputs = net.tran[1984].outputArc;
InitArc( &parcInputs[0], 1, 1623, 0, 1 );
parcInputs[0].color[0].var = &a1 ;
parcInputs[0].color[0].flags = 0 ;
parcInputs[0].color[0].size = 1 ;
InitArc( &parcOutputs[0], 1, 434, 0, 1 );
parcOutputs[0].color[0].var = &intersection ;
parcOutputs[0].color[0].flags = 0 ;
parcOutputs[0].color[0].size = 1 ;

InitTransition( 1985, "", 2, 2, 0, 1, 1, TF_0_45, NULL, TT_0_45 );
net.tran[1985].number[1] = 45;
parcInputs = net.tran[1985].inputArc;
parcOutputs = net.tran[1985].outputArc;
InitArc( &parcInputs[0], 1, 1618, 0, 0 );
InitArc( &parcOutputs[0], 1, 1618, 0, 0 );


}
#endif /* SEGMENTED_MEMORY */
#endif /* CONST_NET */