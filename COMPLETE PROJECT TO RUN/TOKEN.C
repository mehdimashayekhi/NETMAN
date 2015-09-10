/*
    NETCODE colored petri net simulator
    source file for manipulating tokens and their colors

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/TOKEN.C,v 2.18 1997/05/15 04:17:22 gilem Exp $
*/
#define SUPER_USER
#include "petri.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/*The functions within this file are the most basic of token/tokenList manipulators      */
/*These should only be used for special cases.  The token functions in place.c are more  */
/*suitable for basic token manipulation.  These functions do not update place information*/
/*such as the token count.                                                               */

/*****************************************************************************************/
/*  This function adds a token to a linked list.  It always adds them to the front of the*/
/*  list.                                                                                */
/*****************************************************************************************/
void AddToken(Token** tokenList, Token *tokenPtr)
{
if (tokenPtr==NULL)
    return;
tokenPtr->next=(Token*)*tokenList;
*tokenList=tokenPtr;
}

/*****************************************************************************************/
/*  This function adds a token to a linked list.  It always adds them to the front of the*/
/*  list.                                                                                */
/*****************************************************************************************/
void AddTokenToFront(Token** tokenList, Token *tokenPtr)
{
if (tokenPtr==NULL)
    return;
tokenPtr->next=(Token*)*tokenList;
*tokenList=tokenPtr;
}

/*****************************************************************************************/
/*  This function adds a token to the end of a linked list data structure.  This might be*/
/*  useful for implementing a queue or stack.                                            */
/*****************************************************************************************/
void AddTokenToEnd(Token** tokenList, Token *tokenPtr)
{
Token *tempPtr;

if (tokenPtr==NULL)                 /*If token doesn't exist*/
    return;
    
if (*tokenList==NULL)               /*If List is empty*/
    {
    *tokenList=tokenPtr;
    (*tokenList)->next=NULL;
    return;
    }

tempPtr=*tokenList;                 /*Normal case*/
while (tempPtr->next!=NULL)
    tempPtr=(Token*)tempPtr->next;
tempPtr->next=(Token*)tokenPtr;
tokenPtr->next=NULL;
}


/*****************************************************************************************/
/*  This function returns the next token pointer in a linked list of tokens              */
/*****************************************************************************************/
Token* NextToken(Token *tokenPtr)
{
if (tokenPtr==NULL) 
    return NULL;
else
    return ((Token*)(tokenPtr->next));
}

/*****************************************************************************************/
/*  This function frees the memory of a given token                                      */
/*****************************************************************************************/
void DeleteToken(Token *tokenPtr)
{
    if (tokenPtr != NULL)
    {
            /* free the colored token information */
            if( tokenPtr->value != NULL )
            {
                    tokenPtr->count = 0;
                    free( tokenPtr->value );
                    tokenPtr->value = 0;
            }
            
            /* delete the token */
        free(tokenPtr);
    }
}

/*****************************************************************************************/
/*  This function allocates memory for a new token and returns its pointer.              */
/*****************************************************************************************/

Token* NewToken(void)
{
Token *tokenPtr;
tokenPtr=(Token*)malloc(sizeof(Token));
        if( !tokenPtr )
	    {
	    	logerror("NewToken: could not allocate token");
			CloseLogFile();
            return 0;
	    }
/* initialize the token */
tokenPtr->next=NULL;
tokenPtr->count = 0;
tokenPtr->value = NULL;

return tokenPtr;
}

/*****************************************************************************************/
/*  make a copy of the token passed, and return its copy, with the same colors           */
/*****************************************************************************************/

Token* TokenClone(Token *pToken)
{
	Token *pNew;
	/* allocate the token */
	pNew = NewToken();
	/* if the old token doesn't exist, then return */
	if( !pToken ) {
		logerror("TokenClone, passed a null token");
	}
	/* copy the token value from the old token into the new token */
	pNew->count = pToken->count;
	if( pToken->count ) {
		pNew->value = (TOKEN_VALUE*)malloc( pToken->count*sizeof(TOKEN_VALUE) );
		if( !pNew->value ) {
			logerror("TokenClone, could not allocate token value");
			CloseLogFile();
		}
		memcpy( pNew->value, pToken->value, pToken->count*sizeof(TOKEN_VALUE) );
	}
	return pNew;
}

/********************************************
        FUNCTIONS TO MANIPULATE COLORED TOKENS
*********************************************/

/* function with variable number of arguments to set the color of a token
        to the specified integer list, of length howMany */
void TokenSetColor( Token* ptr, TOKEN_SIZE howMany, ... )
{
        /* for now we won't worry about speed, and we will just use an array
                which is realloced every time.
                For optimization, we can make the size of this be a multiple of a number */


        /* first of all, check the size of the token */
        if( ptr->count != howMany )
        {
	        ptr->value = (TOKEN_VALUE*)realloc( ptr->value, howMany*sizeof(TOKEN_VALUE) );
	        ptr->count = howMany;
	        if( !ptr->value )
		    {
		    	logerror("TokenSetColor: could not allocate value");
		    	CloseLogFile();
	            return;
		    }

        }

        /* if there are extra arguments */
        if( howMany )
        {
        va_list ap;
        TOKEN_SIZE i;
        TOKEN_VALUE arg;

        va_start( ap, howMany );

        /* while there are still arguments to be retrieved... */
        for( i=0; i<howMany; i++ )
        {
                arg = va_arg(ap, TOKEN_VALUE);
                ptr->value[i] = arg;
        }

        va_end( ap );
        }
}


void TokenAddColorToEnd( Token* pToken, TOKEN_VALUE val)
{
        TOKEN_SIZE num;

        if( pToken == NULL )
                return;
                
        num = pToken->count;
        pToken->count++;
        pToken->value = (TOKEN_VALUE*)realloc( pToken->value, pToken->count*sizeof(TOKEN_VALUE) );
    if( !pToken->value )
    {
    	logerror("TokenAddColorToEnd: could not allocate value");
		CloseLogFile();
    	return;
    }
        pToken->value[num] = val;
}

void TokenAddColorToFront( Token* pToken, TOKEN_VALUE val)
{
        TOKEN_SIZE num;
        
        if( pToken == NULL )
                return;
                
        num = pToken->count;
        pToken->count++;
                
        if( pToken->value == NULL )
        {
            pToken->value = (TOKEN_VALUE*)malloc( pToken->count*sizeof(TOKEN_VALUE));
		    if( !pToken->value )
		    {
		    	logerror("TokenAddColorToFront: could not allocate value");
				CloseLogFile();
		    	return;
		    }
        }
        else
        {
                TOKEN_VALUE *valOld;
                /* since we already have some color, we must copy and add a new color */
                valOld = pToken->value;
                pToken->value = (TOKEN_VALUE*)malloc( pToken->count*sizeof(TOKEN_VALUE) );
			    if( !pToken->value )
			    {
			    	logerror("TokenAddColorToFront: could not REALLOC value");
					CloseLogFile();
			    	return;
			    }
                memcpy( (pToken->value+1), valOld, num*sizeof(TOKEN_VALUE) ); 
                free( valOld );
        }

        pToken->value[0] = val;
}

TOKEN_VALUE TokenRemoveColorFromEnd( Token* pToken)
{
        TOKEN_VALUE val;
        
        if( pToken == NULL )
                return 0;
                
        if( pToken->value == NULL )
                return 0;
        
        val = pToken->value[pToken->count-1];
        pToken->count--;
        pToken->value = (TOKEN_VALUE*)realloc( pToken->value, pToken->count*sizeof(TOKEN_VALUE) );
			    if( !pToken->value )
			    {
			    	logerror("TokenRemoveColorFromEnd: could not REALLOC value");
					CloseLogFile();
			    }
        return val;
}

TOKEN_VALUE TokenRemoveColorFromFront( Token* pToken)
{
        TOKEN_VALUE val, *valOld;
        
        
        if( pToken == NULL )
                return 0;
                
        if( pToken->value == NULL )
                return 0;
        
        val = pToken->value[0];
        pToken->count--;
        
        /* since we already have some color, we must copy and add a new color */
        valOld = pToken->value;
        if( pToken->count > 0 )
        {
            pToken->value = (TOKEN_VALUE*)malloc( pToken->count*sizeof(TOKEN_VALUE) );
            if( !pToken->value )
    	    {
    	    	logerror("TokenRemoveColorFromFront: could not alloc value");
    			CloseLogFile();
    	    	return val;
    	    }
    		memcpy( pToken->value, (valOld+1), pToken->count*sizeof(TOKEN_VALUE) ); 
        }
        else
            pToken->count = 0;

        free( valOld );
                
        return val;
}

void TokenSetColorNum( Token* pToken, TOKEN_SIZE num, TOKEN_VALUE val)
{
    /* set the color num to val, reallocing if too small
    	NOTE: this is the only function which will allocate values
        for the token without initializing them, if the value being set
        is above the current bound of the token.  Therefore, we will be sure
        to set the new values of the token to zero.
        NOTE: that once again, num is zero-based
    */

    /* if not enough elements realloc a larger space */
    TOKEN_SIZE tsOld, i;
    tsOld = pToken->count ;

        if( tsOld <= num )
        {
            pToken->value = (TOKEN_VALUE*)realloc( pToken->value, (num+1)*sizeof(TOKEN_VALUE) );
			    if( !pToken->value )
			    {
			    	logerror("TokenSetColorNum: could not REALLOC value");
					CloseLogFile();
			    	return;
			    }
            pToken->count = (TOKEN_SIZE) num+1;
            /* set all the new values to zero, for convenience */
			for( i=tsOld; i<num; i++ ) {
            	pToken->value[i] = 0;
            }
        }

    /* now set the element */
    pToken->value[num] = val;
}

TOKEN_VALUE TokenGetColorNum( Token* pToken, TOKEN_SIZE num)
{
        /* get the value of the num token value, or return 0 if out of range
                values start at 0 */
        if( pToken == NULL )
                return 0;
                
        if( (pToken->count <= num)
                || (num < 0) )
                return 0;
                
        /* return the num element */
        return pToken->value[num];
}

void TokenArraySetColor( Token* pToken, TOKEN_SIZE howMany, TOKEN_VALUE* array)
{
        /* set the first howMany elements in the token, shrinking/expanding
                size of the array if necessary */
        if( pToken == NULL )
                return;
        
        /* resize array if necessary */
        if( pToken->count != howMany )
        {
                pToken->value = (TOKEN_VALUE*)realloc( pToken->value, howMany*sizeof(TOKEN_VALUE) );
   			    if( !pToken->value )
			    {
			    	logerror("TokenArraySetColor: could not REALLOC value");
					CloseLogFile();
			    	return;
			    }

        }
        
        /* copy the values */
        memcpy( pToken->value, array, howMany*sizeof(TOKEN_VALUE) );
}

void TokenArrayGetColor( Token* pToken, TOKEN_SIZE howMany, TOKEN_VALUE* array)
{
        /* get the first howMany elements from the token, and place them
                in the array */
        TOKEN_SIZE i;
        
        if( pToken == NULL )
                return;
                
        /* iterate through the number of elements in the token */
        for( i=0; i<howMany; i++ )
        {
                /* don't over step the token array */
                if( i >= pToken->count )
                        break;
                /* copy the value */
                array[i] = pToken->value[i];
        }       
}
