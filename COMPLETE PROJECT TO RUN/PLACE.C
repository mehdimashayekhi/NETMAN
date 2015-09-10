/*
    NETCODE colored petri net simulator
    source file for manipulating places and their markings

    (c) 1995 - Michael R. Gile
    see COPYRIGH.T for more details

    $Header: E:\\PROJECTS\\NETMAN.VC\\SIMULATE\\PETRIOUT/RCS/PLACE.C,v 2.11 1996/04/17 03:02:39 gilem Exp $
*/
#define SUPER_USER
#include "petri.h"
#include <stdlib.h>
#include <stdio.h>

#include "dplayer.h"


/*
    remove all of the tokens associated with this place 
*/
void PlaceClearMarking( Place *pPlace )
{
    Token *tokenPtr,*next;

    /* detach the token list */
    tokenPtr = pPlace->tokenList;
    pPlace->tokenList = NULL;
    pPlace->tokenCount = 0;

    /* delete all of the tokens */
    while (tokenPtr!=NULL)
    {
        next=(Token*)tokenPtr->next;
        DeleteToken( tokenPtr );
        tokenPtr=next;
    }

}

/*
    record the stats due to the token being added to the place 
    NOTE: call BEFORE Adding a token to a place 
*/
void StatAddTokenToPlace( Place* pPlace, Token* pToken );
void StatAddTokenToPlace( Place* pPlace, Token* pToken )
{
    /* record the time the specific token entered */
    pToken->enterTime = net.totalTime;

    /* Keeps running total of (# tokens in place)x(tokens length of time in place) */
    pPlace->sumation += (pPlace->tokenCount * (net.totalTime - pPlace->timeLastChange));
    pPlace->timeLastChange = net.totalTime;
    
    /* increment the number of tokens in the place */
    pPlace->tokenCount++;
          
    /* When the first token has entered the place, a timer begins to record the 
       total time the place remains occupied */
    if (pPlace->tokenCount == 1)
        pPlace->begTime = net.totalTime;

}

void StatRemoveTokenFromPlace( Place* pPlace, Token* pToken );
void StatRemoveTokenFromPlace( Place* pPlace, Token* pToken )
{
    double deltaT ;

    /* Keeps running total of (# tokens in place)x(tokens length of time in place) */
    pPlace->sumation += (pPlace->tokenCount * (net.totalTime - pPlace->timeLastChange));
    pPlace->timeLastChange = net.totalTime;


    pPlace->totalTokenNum++;
    pPlace->tokenCount--;

    /* When the last token leaves the place, the timer stops recording */
    /* the total time the place was occupied */

    if (pPlace->tokenCount == 0) {
        deltaT = (net.totalTime - pPlace->begTime);
        pPlace->occupied += deltaT;

        if (pPlace->firstTime) {                          /* calculates min/max times */
            pPlace->minTimeOccupied = deltaT;              /* each place is occupied   */
            pPlace->maxTimeOccupied = deltaT;
            pPlace->firstTime = FALSE;
        }
        else {
            if (deltaT < pPlace->minTimeOccupied)
                pPlace->minTimeOccupied = deltaT;
            if (deltaT > pPlace->maxTimeOccupied)
                pPlace->maxTimeOccupied = deltaT;
        }
        pPlace->begTime = 0.0;
    }

    /* Update the total amount of time the token remained in the place */
    pPlace->timeTokensInPlace += (net.totalTime - pToken->enterTime);
}

/*
    add a token to the place, at the end of the token list
*/                                

void PlaceNumAddTokenToEnd( PLACE_NUMBER pNo, Token* ptr)
{        

    /* stats */
    StatAddTokenToPlace( &net.place[pNo], ptr );

    /* call the proper token function */
    AddTokenToEnd( &net.place[pNo].tokenList, ptr ); 
    
    
}

void PlaceAddTokenToEnd( Place* ptrPlace, Token* ptr)
{
    if( ptrPlace )
    {
        /* stats */
        StatAddTokenToPlace( ptrPlace, ptr );

        /* call the proper token function */
        AddTokenToEnd( &ptrPlace->tokenList, ptr );

    }
    else
        logerror("PlaceAddTokenToEnd: null place pointer");
}

void PlaceAddTokenToFront( Place* ptrPlace, Token* ptrToken)
{
    if( ptrPlace )
    {
        /* stats */
        StatAddTokenToPlace( ptrPlace, ptrToken );
        /* add the token to the place list */
        AddTokenToFront( &ptrPlace->tokenList, ptrToken );
    }
}


/*****************************************************************************************/
/*  This function adds a token to a place.  Both are defined by pointers to existing     */
/*  structures.                                                                              */
/*****************************************************************************************/
void PlaceAddToken(Place *placePtr,Token *tokenPtr)
{
    if(placePtr == NULL)
        return;

    switch( placePtr->policy )
    {
    case RANDOM:
    case FIFO:
        PlaceAddTokenToEnd( placePtr, tokenPtr );
        break;
    case LIFO:
        PlaceAddTokenToFront( placePtr, tokenPtr );
        break;
    }
}

/*****************************************************************************************/
/*  This function removes a specific token from a place.  Both are defined by pointers to*/
/*  existing  structures.                                                                */
/*****************************************************************************************/
Token* PlaceRemoveToken(Place *placePtr)
{
    Token* ptrReturn;

    if(placePtr == NULL)
        return NULL;

    placePtr->tokenCount--;

    switch( placePtr->policy )
    {
    case RANDOM:
        ptrReturn = PlaceRemoveRandomToken( placePtr );
        break;
    case FIFO:
    case LIFO:
        ptrReturn = PlaceRemoveTokenFromFront( placePtr );
        break;
    }
    
    return ptrReturn;
}

/*****************************************************************************************/
/*  This function removes a random token from a place and returns it to the caller.  This*/
/*  function does NOT distinguish between token types.                                   */
/*****************************************************************************************/
Token* PlaceRemoveRandomToken(Place *placePtr)
{
    TOKEN_NUMBER num;
    if (placePtr->tokenCount==0)
        return NULL;
    
    num=(TOKEN_NUMBER)( ((double)placePtr->tokenCount * (double)rand())/((double)RAND_MAX+1.0));
    
    return PlaceRemoveTokenNum( placePtr, num );
}

Token* PlaceRemoveTokenFromEnd( Place* pPlace )
{
    return PlaceRemoveTokenNum( pPlace, pPlace->tokenCount-1 );
}

Token* PlaceRemoveTokenFromFront( Place* pPlace )
{                                          
    return PlaceRemoveTokenNum( pPlace, 0 );
}

Token* PlaceRemoveTokenNum( Place* pPlace, TOKEN_NUMBER num)
{
    /* return the pointer to the token, and remove it from the list */
    Token *pToken, *pLast=NULL;
    TOKEN_NUMBER i;

    if( pPlace == NULL )
        return NULL;
        
    if( pPlace->tokenCount <= num )
        return NULL;

    /* get a pointer to the tokenList */
    pToken = pPlace->tokenList;

    /* special case of removing first token */
    if( num == 0 )
    {
        pPlace->tokenList = pToken->next;
    }
    else
    {
        /* skip to the num token */ 
        for( i=0; i<num; i++ )
        {
            pLast = pToken;
            pToken = NextToken( pToken );
        }
    
        /* now remove the pToken from the list */
        if( pLast == NULL )
            pPlace->tokenList = NULL;
        else
            pLast->next = pToken->next;
    }

    /* record stats, and remove one from the tokencount */
    StatRemoveTokenFromPlace( pPlace, pToken );

    /* now remove the pointer to the next token from the token */
    pToken->next = NULL;    
    return pToken;
}


/*****************************************************************************************/
/*  This function removes returns the number of tokens contained within a place.         */ 
/*****************************************************************************************/
TOKEN_NUMBER PlaceGetNumTokens(Place *placePtr)
{
return placePtr->tokenCount;
}

/*****************************************************************************************/
/*  This function removes returns the address of the token-List pointer inside a Place   */
/*  This is to aallow the user to maanipulate the token list himself within the enabling */
/*  and firing functions.                                                                */
/*****************************************************************************************/
Token** GetTokenList(Place *placePtr)
{
return (&placePtr->tokenList);
}

Token* PlacePeekTokenNum( Place* pPlace, TOKEN_NUMBER num)
{
    /* return the pointer to the token, without removing it */
    Token *pToken;
    TOKEN_NUMBER i;

    if( pPlace == NULL )
        return NULL;
        
    if( pPlace->tokenCount <= num )
        return NULL;
        
    
    pToken = pPlace->tokenList;
    for( i=0; i<num; i++ )
    {
        pToken = NextToken( pToken );
    }
    
    return pToken;
}

