/* -*- C++ -*-   vim: set syntax=cpp: */
#ifndef __QUEX_INCLUDE_GUARD__ANALYZER__MEMBER__TOKEN_RECEIVING_I
#define __QUEX_INCLUDE_GUARD__ANALYZER__MEMBER__TOKEN_RECEIVING_I

#ifndef QUEX_TYPE_ANALYZER
#   error "QUEX_TYPE_ANALYZER definition missing."
#endif
#ifndef QUEX_TYPE_TOKEN
#   error "QUEX_TYPE_TOKEN definition missing."
#endif

#include <quex/code_base/token/TokenPolicy>
#include <quex/code_base/definitions>

QUEX_NAMESPACE_MAIN_OPEN

QUEX_INLINE QUEX_TYPE_TOKEN*
QUEX_NAME(remaining_token_pop)(QUEX_TYPE_ANALYZER*);

QUEX_INLINE void
QUEX_NAME(receive)(QUEX_TYPE_ANALYZER* me, QUEX_TYPE_TOKEN** result_pp)
{ 
    *result_pp = QUEX_NAME(remaining_token_pop)(me);
    if( *result_pp ) return; 

    /* Restart filling the queue from begin                                   */
    QUEX_NAME(TokenQueue_reset)(&me->_token_queue); /* Use 1st token of queue */

    /* Analyze until there is some content in the queue                       */
    do {
        me->current_analyzer_function(me);

        QUEX_ASSERT_TOKEN_QUEUE_AFTER_SENDING(&me->_token_queue);

        if( me->error_code != E_Error_None ) {
            QUEX_NAME(TokenQueue_set_token_TERMINATION)(&me->_token_queue);
            break;
        }

    } while( QUEX_NAME(TokenQueue_is_empty)(&me->_token_queue) );
    
    *result_pp = QUEX_NAME(TokenQueue_pop)(&me->_token_queue);
}

QUEX_INLINE QUEX_TYPE_TOKEN*
QUEX_NAME(receive_from_chunk)(QUEX_TYPE_ANALYZER*    me, 
                              bool                   EndOfChunkF, 
                              QUEX_TYPE_TOKEN_ID     StreamTerminatingTokenId)
/* Receives tokens from memory chunks. This function is only to be used by the
 * Feeder and the Gavager adapters.
 * 
 * RETURNS: NULL, requires refill.
 *          Pointer to token, that has been identified 
 *          (This may be the 'BYE' token).                                    */
{
    QUEX_TYPE_TOKEN*       token_p;
    QUEX_TYPE_LEXATOM*     start_p;
    const QUEX_TYPE_TOKEN* last_token_in_queue_p;

    /* If token queue is not empty => it has been ensured that all tokens are
     * generated well inside the buffer's boundaries.                         */
    token_p = QUEX_NAME(remaining_token_pop)(me);
    if( token_p ) return token_p;

    /* Restart filling the queue from begin                                   */
    QUEX_NAME(TokenQueue_reset)(&me->_token_queue); /* Use 1st token of queue */

    /* Token queue is empty. A new step begins. 
     * Backup read position. It may be reset in case of reaching boundaries.  */
    do {
        start_p = me->buffer._read_p;

        me->current_analyzer_function(me);
        QUEX_ASSERT_TOKEN_QUEUE_AFTER_SENDING(&me->_token_queue);

        if( me->error_code != E_Error_None ) {
            QUEX_NAME(TokenQueue_reset)(&me->_token_queue);
            return (QUEX_TYPE_TOKEN*)0; 
        }
    } while( QUEX_NAME(TokenQueue_is_empty)(&me->_token_queue) );

    if( me->buffer._read_p < me->buffer.input.end_p ) {
        /* Complete token queue is generated without reaching buffer boarders.*/
        return token_p;
    }

    /* Last token ended on the content's border. 
     * Last token id 'stream end' => token queue is ok. 
     * Else                       => must refill and restart from 'start_p'.  */
    last_token_in_queue_p = QUEX_NAME(TokenQueue_last_token)(&me->_token_queue); 
    __quex_assert(0 != last_token_in_queue_p); /* not empty => last token exists.  */
    if( EndOfChunkF && last_token_in_queue_p->id == StreamTerminatingTokenId ) {
        /* The 'good bye' token may stand very well on the border.            */
        return token_p;                                                       
    }                                                                         
    else {                                                                    
        /* All generated tokens are in doubt.                                 
         * Reset token queue. Restart analysis with more content.             */
        QUEX_NAME(TokenQueue_reset)(&me->_token_queue);
        me->buffer._read_p = start_p;
        return (QUEX_TYPE_TOKEN*)0; 
    }
}

QUEX_INLINE QUEX_TYPE_TOKEN*
QUEX_NAME(remaining_token_pop)(QUEX_TYPE_ANALYZER* me)
/* Considers the current 'error_code' and the remaining token queue. If the 
 * current state is 'error', then the complete token queue is deleted and the
 * TERMINATION token is setup. Else, it is tried to take a token which remained
 * in the token queue.
 *
 * RETURNS: Pointer to token, if a token could be found (without analysis).
 *          Null, else.                                                       */
{
    /* Make sure that all remaining tokens are passed to the receiver, before
     * notifying about error.                                                 */
    QUEX_TYPE_TOKEN* token_p = QUEX_NAME(TokenQueue_pop)(&me->_token_queue);

    if( token_p ) {
        return token_p;
    }
    else if( me->error_code != E_Error_None ) {
        QUEX_NAME(TokenQueue_set_token_TERMINATION)(&me->_token_queue);
        return QUEX_NAME(TokenQueue_pop)(&me->_token_queue);
    }
    else {
        return (QUEX_TYPE_TOKEN*)0;
    }
}

QUEX_NAMESPACE_MAIN_CLOSE
#endif
