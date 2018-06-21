/* -*- C++ -*- vim: set syntax=cpp: 
 * PURPOSE: Token Queue 
 *
 * A token queue is a queue where read and write cycles are separate.
 * That is, when the queue is filled, it is not read until the 
 * filling terminated. Then, the read does not terminate before there
 * is no more token left.
 *
 * Wrap-arround is neither necessary nor meaningful!
 *
 * (C) 2004-2017 Frank-Rene Schaefer                                          */
#ifndef __QUEX_INCLUDE_GUARD__TOKEN__TOKEN_QUEUE_I
#define __QUEX_INCLUDE_GUARD__TOKEN__TOKEN_QUEUE_I

#include <quex/code_base/definitions>
#include <quex/code_base/asserts>
#include <quex/code_base/MemoryManager>

/* NOTE: QUEX_TYPE_TOKEN must be defined at this place!                       */


QUEX_NAMESPACE_MAIN_OPEN

QUEX_INLINE void
QUEX_NAME(TokenQueue_construct)(QUEX_NAME(TokenQueue)* me, 
                                QUEX_TYPE_TOKEN*       Memory, 
                                const size_t           N)
/* me:     The token queue.
 * Memory: Pointer to memory of token queue, 0x0 --> no initial memory.
 * N:      Number of token objects that the array can carry.                  */
{
    QUEX_TYPE_TOKEN* iterator   = 0x0;
    QUEX_TYPE_TOKEN* memory_end = &Memory[N];

    __quex_assert(Memory != 0x0);
    __quex_assert(N > (size_t)QUEX_SETTING_TOKEN_QUEUE_SAFETY_BORDER);

    /* Call placement new (plain constructor) for all tokens in chunk.        */
    for(iterator = Memory; iterator != memory_end; ++iterator) {
        QUEX_NAME_TOKEN(construct)(iterator);
    }
    QUEX_NAME(TokenQueue_init)(me, Memory, memory_end); 
}

QUEX_INLINE void
QUEX_NAME(TokenQueue_reset)(QUEX_NAME(TokenQueue)* me) 
{                                                    
    me->read_iterator  = (QUEX_TYPE_TOKEN*)me->begin; 
    me->write_iterator = (QUEX_TYPE_TOKEN*)me->begin; 

    __quex_assert(  me->end - me->begin 
                  > (ptrdiff_t)QUEX_SETTING_TOKEN_QUEUE_SAFETY_BORDER);
    __quex_assert(   me->end_minus_safety_border 
                  == me->end - (ptrdiff_t)QUEX_SETTING_TOKEN_QUEUE_SAFETY_BORDER);         
}

QUEX_INLINE void
QUEX_NAME(TokenQueue_init)(QUEX_NAME(TokenQueue)* me, 
                           QUEX_TYPE_TOKEN* Memory, 
                           QUEX_TYPE_TOKEN* MemoryEnd) 
{
    __quex_assert(  MemoryEnd - Memory 
                  > (ptrdiff_t)QUEX_SETTING_TOKEN_QUEUE_SAFETY_BORDER);
    me->begin                   = Memory;                           
    me->end                     = MemoryEnd;                        
    me->end_minus_safety_border = MemoryEnd - QUEX_SETTING_TOKEN_QUEUE_SAFETY_BORDER;         
    QUEX_NAME(TokenQueue_reset)(me);                                
}

QUEX_INLINE void
QUEX_NAME(TokenQueue_resources_absent_mark)(QUEX_NAME(TokenQueue)* me) 
{
    me->begin                   = (QUEX_TYPE_TOKEN*)0;                           
    me->end                     = (QUEX_TYPE_TOKEN*)0;
    me->read_iterator           = (QUEX_TYPE_TOKEN*)0; 
    me->write_iterator          = (QUEX_TYPE_TOKEN*)0; 
    me->end_minus_safety_border = (QUEX_TYPE_TOKEN*)0;
}

QUEX_INLINE bool
QUEX_NAME(TokenQueue_resources_absent)(QUEX_NAME(TokenQueue)* me) 
{
    return    me->begin                   == (QUEX_TYPE_TOKEN*)0                           
           && me->end                     == (QUEX_TYPE_TOKEN*)0
           && me->read_iterator           == (QUEX_TYPE_TOKEN*)0 
           && me->write_iterator          == (QUEX_TYPE_TOKEN*)0
           && me->end_minus_safety_border == (QUEX_TYPE_TOKEN*)0;
}

QUEX_INLINE void
QUEX_NAME(TokenQueue_destruct)(QUEX_NAME(TokenQueue)* me)
{
    QUEX_TYPE_TOKEN* iterator = 0x0;
    /* Call explicit destructors for all tokens in array                      */
    for(iterator = me->begin; iterator != me->end; ++iterator) {
        QUEX_NAME_TOKEN(destruct)(iterator);
    }

    /* The memory chunk for the token queue itself is located inside the
     * analyzer object. Thus, no explicit free is necessary. In case of user
     * managed token queue memory the user takes care of the deletion.        */
    QUEX_NAME(TokenQueue_resources_absent_mark)(me);
}

QUEX_INLINE void   
QUEX_NAME(TokenQueue_remainder_get)(QUEX_NAME(TokenQueue)* me,
                                    QUEX_TYPE_TOKEN**      begin,
                                    QUEX_TYPE_TOKEN**      end)
{
    *begin = me->read_iterator;
    *end   = me->write_iterator;
    QUEX_NAME(TokenQueue_reset)(me);
}

QUEX_INLINE void 
QUEX_NAME(TokenQueue_memory_get)(QUEX_NAME(TokenQueue)* me,
                                 QUEX_TYPE_TOKEN**      memory,
                                 size_t*                n)
{
    *memory = me->begin;
    *n      = (size_t)(me->end - me->begin);
}

QUEX_INLINE bool 
QUEX_NAME(TokenQueue_is_full)(QUEX_NAME(TokenQueue)* me) 
{ return me->write_iterator >= me->end_minus_safety_border; }

QUEX_INLINE bool 
QUEX_NAME(TokenQueue_is_empty)(QUEX_NAME(TokenQueue)* me)
{ return me->read_iterator == me->write_iterator; }

QUEX_INLINE QUEX_TYPE_TOKEN* 
QUEX_NAME(TokenQueue_pop)(QUEX_NAME(TokenQueue)* me)
{
#   if defined(QUEX_OPTION_TOKEN_REPETITION_SUPPORT)
    size_t    repetition_count;
#   endif

    __quex_assert(QUEX_NAME(TokenQueue_begin)(me) != 0x0);

    if( QUEX_NAME(TokenQueue_is_empty)(me) ) {        
        return (QUEX_TYPE_TOKEN*)0;
    }
#   if defined(QUEX_OPTION_TOKEN_REPETITION_SUPPORT)
    else if( __QUEX_SETTING_TOKEN_ID_REPETITION_TEST(me->read_iterator->_id) ) {
        repetition_count = QUEX_NAME_TOKEN(repetition_n_get)(me->read_iterator);
        if( repetition_count == 0 ) { 
            /* This case should never occurr!                                 */
            /* Repetition count == 0 => pop repeated token from queue.        */
            ++(me->read_iterator);
            if( QUEX_NAME(TokenQueue_is_empty)(me) ) {        
                return (QUEX_TYPE_TOKEN*)0;
            }
        }
        else if( repetition_count == 1 ) { 
            /* Repetition will be 0, so remove token from the queue.          */
            return me->read_iterator++;
        }
        else {
            QUEX_NAME_TOKEN(repetition_n_set)(me->read_iterator, 
                      (QUEX_NAME_TOKEN(repetition_n_get)(me->read_iterator) - 1));
            return me->read_iterator;  
        } 
    }
#   endif
    /* Tokens are in queue --> take next token from queue                    */ 
    return me->read_iterator++;
}

QUEX_INLINE QUEX_TYPE_TOKEN* QUEX_NAME(TokenQueue_begin)(QUEX_NAME(TokenQueue)* me)
{ return me->begin; }

QUEX_INLINE QUEX_TYPE_TOKEN* QUEX_NAME(TokenQueue_back)(QUEX_NAME(TokenQueue)* me)
{ return me->end - 1; }

QUEX_INLINE QUEX_TYPE_TOKEN* QUEX_NAME(TokenQueue_last_token)(QUEX_NAME(TokenQueue)* me)
{ return me->write_iterator == me->begin ? (QUEX_TYPE_TOKEN*)0 : &me->write_iterator[-1]; }

QUEX_INLINE size_t QUEX_NAME(TokenQueue_available_n)(QUEX_NAME(TokenQueue)* me) 
{ return (size_t)(me->end - me->write_iterator); }

QUEX_INLINE void
QUEX_NAME(TokenQueue_set_token_TERMINATION)(QUEX_NAME(TokenQueue)* me) 
/* Reset entire token queue and set the token 'TERMINATION'. This should
 * only be called in case of a detected error.                                */
{
    QUEX_NAME(TokenQueue_reset)(me);
    (me->write_iterator++)->_id =  QUEX_TOKEN_ID(TERMINATION);
}

QUEX_NAMESPACE_MAIN_CLOSE

#endif /* __QUEX_INCLUDE_GUARD__TOKEN__TOKEN_QUEUE_I */
