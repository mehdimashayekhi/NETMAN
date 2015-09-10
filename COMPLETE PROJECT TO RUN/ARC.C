/*
    NETCODE colored petri net simulator
    source file for arc functions

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/ARC.C,v 1.98 1995/11/14 13:36:49 gilem Exp $
*/

#define SUPER_USER
#include "petri.h"
#include <stdlib.h>

/* arc functions */
int ArcGetWeight( NCTArc* ptr )
{
	if (ptr != NULL)
		return ptr->weight;
	else
		return 0;
}

ARC_INDEX ArcGetIndex( NCTArc* ptr )
{
	if( ptr != NULL)
		return ptr->index;
	else
		return 0;
}

Place* ArcGetPlace( NCTArc* ptr )
{
	if( ptr != NULL )
		return &net.place[ptr->place];
	else
		return 0;
}
