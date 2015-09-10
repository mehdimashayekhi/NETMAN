/*
    NETCODE colored petri net simulator
    source file for main functions

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\projects\netman.vc\simulate\petriout/RCS/MAIN.C,v 2.17 1996/05/05 02:05:56 gilem Exp $
*/

/*
    NOTE: this function has some dos-specific code right now
    in order to have a useful interface
*/

#define SUPER_USER
#include "petri.h"
#include "superusr.h"
#include "userfunc.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef INTERACTIVE
#ifndef MACOS
	#include <conio.h>
#endif
#endif

#ifndef CONST_NET
    PetriNet net;
#endif

/* globals to take care of the output of information to the screen */
#ifndef MACOS
FILE* logFile=0;        /* an ouptput file to log the session to */
#endif
BOOLEAN bQuiet=FALSE;   /* if TRUE, don't show state of net during every step */

void ShowHelp()
{
    /* show the options */
    const char str[] =
"\n\n q: Quit program \
\n s: Step (execute one transition) \
\n g: Go non-stop (press any key while running to halt )\
\n l: Toggle Log File\
\n i: Toggle quIet mode\
\n u: go Until a time\
\n t: display stats for a Transition\
\n p: display stats for a Place\
\n a: display All stats\
\n r: reset All stats\
\n";

    logprintf( str );
}

#ifdef INTERACTIVE


int main()
{
    char ch;
    char buf[256];
    long arg;
    BOOLEAN bContinue=TRUE, bNonStop=FALSE, bGoUntil=FALSE;
    double endTime;












								//Calls User Startup Function


										Startup();










    #ifdef THINK_C
    	KeyMap kmKeyState;
    #endif

    InitializeNet();

    /* choose the running mode
        run_fair to choose randomly between all enabling combinations of a transition
        run_fast to choose first one found (mostly for b/w nets)
        note that the latter may skew the stats for time tokens remain in places,
            because it produces a fifo effect */
    net.mode = RUN_FAIR;

    while(bContinue)
    {


 #ifdef THINK_C
 		GetKeys( kmKeyState );
 #endif

        /* any char will stop continuous mode */
        if( (bNonStop || (bGoUntil && net.totalTime < endTime) )

 #ifdef THINK_C
 			&& !kmKeyState
 #else
            && !kbhit()
 #endif
        )
        {
            ch = 's';
        }
        else
        {
            /* make sure we are stopped */
            bNonStop = bGoUntil = FALSE;

            /* consume all previous key hits */
#ifdef THINK_C
#else
            while( kbhit() )
                getch();
#endif

            /* wait for input from the user */
            logprintf( "\nEnter Command (? for list): " );

#ifdef THINK_C
			do {
				GetKeys( kmKeyState );
			} while( !kmKeyState );

            ch = (char) getc(stdin);

            logprintf( "%c\n", ch );
#else

			/* begin windows 95 fix */
			#if 0
    	        while( !kbhit() )
	                ;

				ch = (char) getch();
	            logprintf( "%c\n", ch );
			#else

			/* important!  there does not seem to be a way to remove the last character
			from the character stream under windows95.  We will have to presume that
			the user will figure out that the they must delete the last character */
			{
			char buf[80];
			scanf( "%s", buf );
            ch = (char) buf[0];
			}

			#endif

#endif

        }

        switch(ch) {
            case 's': /* Step */
            case 'S':
                bContinue = PetriPlayer();
                break;
            case 'q': /* Quit */
            case 'Q':
                bContinue = FALSE;
                break;
            case 'g': /* Non-stop */
            case 'G':
                bNonStop = TRUE;
                break;
            case 'i': /* toggle quiet mode */
            case 'I':
                bQuiet = (BOOLEAN)!bQuiet;
                break;
            case 'p': /* place */
            case 'P':
                logprintf("\nEnter Place Number: ");
                scanf("%ld", &arg);
                StatDisplayPlace( arg );
                break;
            case 't': /* trans */
            case 'T':
                logprintf("\nEnter Transition Number: ");
                scanf("%ld", &arg);
                StatDisplayTransition( arg );
                break;
            case 'a': /* toggle quiet mode */
            case 'A':
                /* show all stats */
                StatDisplayAll();
                break;
            case 'r':
            case 'R':
                /* reset stats */
                InitStats(FALSE);
                break;
            case 'u': /* go Until */
            case 'U':
                {
                    logprintf("\nEnter a time to stop");
                    scanf("%lf", &endTime );
                    bGoUntil = TRUE;
                }
					 break;

				case 'm':
				case 'M':
					SetInitialMarking();
					break;
            case 'l': /* log file */
            case 'L':
                {
                    if( logFile == 0 )
                    {
                        /* open a new log file */
                        printf("\nEnter name for the log file: ");
                        scanf("%s", buf);
                        logFile = fopen( buf, "w" );
                        if( logFile == 0 )
                            printf("\nCannot open log file");
                    }
                    else
                    {
                        /* close the log file */
                        fclose( logFile );
                        logFile = 0;
                    }
                }
                break;
            default:
                /* if command is not valid, then show help */
                ShowHelp();
                break;
        }


    }


    /* if logfile open, then close it */
	CloseLogFile();










								//Calls User Finishup Function




										Finishup();












	 FreeMemory();

    return EXIT_SUCCESS;
}

#endif /* ifdef INTERACTIVE */


