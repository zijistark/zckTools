/* vim:set ft=c: -*- C++ -*- */
#ifndef __QUEX_INCLUDE_GUARD__BUFFER__BUFFER_I
#define __QUEX_INCLUDE_GUARD__BUFFER__BUFFER_I

#include <quex/code_base/asserts>
#include <quex/code_base/buffer/asserts>
#include <quex/code_base/definitions>
#include <quex/code_base/buffer/Buffer>
#include <quex/code_base/buffer/Buffer_print.i>
#include <quex/code_base/buffer/lexatoms/LexatomLoader>
#include <quex/code_base/MemoryManager>

QUEX_NAMESPACE_MAIN_OPEN

QUEX_INLINE void*     QUEX_NAME(Buffer_fill)(QUEX_NAME(Buffer)*  me, 
                                             const void*         ContentBegin,
                                             const void*         ContentEnd);
QUEX_INLINE void      QUEX_NAME(Buffer_fill_prepare)(QUEX_NAME(Buffer)*  me, 
                                                     void**              begin_p, 
                                                     const void**        end_p);
QUEX_INLINE void      QUEX_NAME(Buffer_fill_finish)(QUEX_NAME(Buffer)* me,
                                                    const void*        FilledEndP);
QUEX_INLINE bool      QUEX_NAME(Buffer_is_end_of_stream_inside)(QUEX_NAME(Buffer)* me);
QUEX_INLINE void      QUEX_NAME(Buffer_init_content)(QUEX_NAME(Buffer)* me, 
                                                     QUEX_TYPE_LEXATOM* EndOfFileP);
QUEX_INLINE void      QUEX_NAME(Buffer_init_content_core)(QUEX_NAME(Buffer)*        me, 
                                                          QUEX_TYPE_STREAM_POSITION LI_Begin,
                                                          QUEX_TYPE_STREAM_POSITION LI_EndOfStream,
                                                          QUEX_TYPE_LEXATOM*        EndOfFileP);
QUEX_INLINE void      QUEX_NAME(Buffer_init_analyzis)(QUEX_NAME(Buffer)*   me);
QUEX_INLINE void      QUEX_NAME(Buffer_init_analyzis_core)(QUEX_NAME(Buffer)*        me,
                                                           QUEX_TYPE_LEXATOM*        ReadP,
                                                           QUEX_TYPE_LEXATOM*        LexatomStartP,
                                                           QUEX_TYPE_LEXATOM         LexatomAtLexemeStart,
                                                           QUEX_TYPE_LEXATOM         LexatomBeforeLexemeStart,
                                                           QUEX_TYPE_STREAM_POSITION BackupLexatomIndexOfReadP);

QUEX_INLINE void      QUEX_NAME(Buffer_on_overflow_DEFAULT)(void*              aux, 
                                                            QUEX_NAME(Buffer)* buffer, 
                                                            bool               ForwardF);
QUEX_INLINE void      QUEX_NAME(Buffer_on_before_buffer_change_DEFAULT)(void*  aux,
                                                                        const  QUEX_TYPE_LEXATOM*, 
                                                                        const  QUEX_TYPE_LEXATOM*);
QUEX_INLINE ptrdiff_t QUEX_NAME(Buffer_nested_free_front)(QUEX_NAME(Buffer)* me);
QUEX_INLINE void      QUEX_NAME(Buffer_adapt_to_new_memory_location_root)(QUEX_NAME(Buffer)* me,
                                                                          QUEX_TYPE_LEXATOM* old_memory_root,
                                                                          QUEX_TYPE_LEXATOM* new_memory_root,
                                                                          ptrdiff_t          NewRootSize);

QUEX_INLINE void
QUEX_NAME(Buffer_construct)(QUEX_NAME(Buffer)*        me, 
                            QUEX_NAME(LexatomLoader)* filler,
                            QUEX_TYPE_LEXATOM*        memory,
                            const size_t              MemorySize,
                            QUEX_TYPE_LEXATOM*        EndOfFileP,
                            E_Ownership               Ownership,
                            QUEX_NAME(Buffer)*        IncludingBuffer)
{
    /* Ownership of InputMemory is passed to 'me->_memory'.                  */
    QUEX_NAME(BufferMemory_construct)(&me->_memory, memory, MemorySize, 
                                      Ownership, IncludingBuffer); 
    
    /* By setting begin and end to zero, we indicate to the loader that      
     * this is the very first load procedure.                                */
    me->filler       = filler;
    me->fill         = QUEX_NAME(Buffer_fill);
    me->fill_prepare = QUEX_NAME(Buffer_fill_prepare);
    me->fill_finish  = QUEX_NAME(Buffer_fill_finish);

    /* Event handlers.                                                       */
    QUEX_NAME(Buffer_set_event_handlers)(me, (void (*)(void*))0,
                                         (void (*)(void*))0, (void*)0);

    /* Initialize.                                                           */
    QUEX_NAME(Buffer_init)(me, EndOfFileP);

    QUEX_BUFFER_ASSERT_CONSISTENCY(me);
}

QUEX_INLINE void
QUEX_NAME(Buffer_init)(QUEX_NAME(Buffer)* me, QUEX_TYPE_LEXATOM* EndOfFileP)
{
    QUEX_NAME(Buffer_init_content)(me, EndOfFileP);
    QUEX_NAME(Buffer_init_analyzis)(me); 
}

QUEX_INLINE void
QUEX_NAME(Buffer_destruct)(QUEX_NAME(Buffer)* me)
/* Destruct 'me' and mark all resources as absent.                            */
{
    QUEX_NAME(Buffer_call_on_buffer_before_change)(me);

    if( me->filler ) {
        me->filler->delete_self(me->filler); 
    }
    me->filler = (QUEX_NAME(LexatomLoader)*)0;

    QUEX_NAME(BufferMemory_destruct)(&me->_memory);

    QUEX_NAME(Buffer_resources_absent_mark)(me);
}

QUEX_INLINE void
QUEX_NAME(Buffer_shallow_copy)(QUEX_NAME(Buffer)* drain, const QUEX_NAME(Buffer)* source)
/*    ,.
 *   /  \   DANGER: Do not use this function, except that you totally 
 *  /    \                understand its implications!
 *  '----'
 * Copy indices and references *as is*. The purpose of this function is solely
 * to copy the setup of a buffer to a safe place and restore it. 
 *
 *           NOT TO BE USED AS A REPLACEMENT FOR COPYING/CLONING!
 *
 * At the time of this writing, the only propper application is when a backup 
 * is generated in a memento. When it is restored in the 'real' buffer object 
 * the pointers point to the right places and the ownership is handled propperly.
 *
 * The caller of this function MUST determine whether 'drain' or 'source'
 * maintains ownership.                                                       */
{
    QUEX_BUFFER_ASSERT_CONSISTENCY(source);
    *drain = *source;
}

QUEX_INLINE bool 
QUEX_NAME(Buffer_has_intersection)(QUEX_NAME(Buffer)*       me,
                                   const QUEX_TYPE_LEXATOM* Begin,
                                   ptrdiff_t                Size)
{
    const QUEX_TYPE_LEXATOM* End      = &Begin[Size];
    QUEX_NAME(Buffer)*       root     = QUEX_NAME(Buffer_nested_find_root)(me);
    const QUEX_TYPE_LEXATOM* my_begin = root->_memory._front;
    const QUEX_TYPE_LEXATOM* my_end   = &me->_memory._back[1];

    /* No intersection in two cases:
     * (1) second interval lies completely before: 'End <= my_begin'.
     * (2) second interval lies completely after:  'Begin >= my_begin'.       */
    if( Begin >= my_end || End <= my_begin ) return false;
    else                                     return true;
}

QUEX_INLINE void
QUEX_NAME(Buffer_resources_absent_mark)(QUEX_NAME(Buffer)* me)
{
    __QUEX_STD_memset((void*)me, 0, sizeof(QUEX_NAME(Buffer)));
}

QUEX_INLINE bool    
QUEX_NAME(Buffer_resources_absent)(QUEX_NAME(Buffer)* me)
{
    return    me->filler == (QUEX_NAME(LexatomLoader)*)0 
           && QUEX_NAME(BufferMemory_resources_absent)(&me->_memory);
}

QUEX_INLINE void     
QUEX_NAME(Buffer_dysfunctional_set)(QUEX_NAME(Buffer)*  me)
{
    QUEX_NAME(Buffer_init_analyzis_core)(me, 
    /* ReadP                          */ (QUEX_TYPE_LEXATOM*)0,
    /* LexatomStartP                  */ (QUEX_TYPE_LEXATOM*)0,
    /* LexatomAtLexemeStart           */ (QUEX_TYPE_LEXATOM)0,                                   
    /* LexatomBeforeLexemeStart       */ (QUEX_TYPE_LEXATOM)0,
    /* BackupLexatomIndexOfReadP      */ (QUEX_TYPE_STREAM_POSITION)-1);
}

QUEX_INLINE bool     
QUEX_NAME(Buffer_dysfunctional)(QUEX_NAME(Buffer)*  me)
{
    return    me->_read_p                         == (QUEX_TYPE_LEXATOM*)0
           && me->_lexeme_start_p                 == (QUEX_TYPE_LEXATOM*)0
           && me->_lexatom_at_lexeme_start        == (QUEX_TYPE_LEXATOM)0                                   
#          ifdef  __QUEX_OPTION_SUPPORT_BEGIN_OF_LINE_PRE_CONDITION                 
           && me->_lexatom_before_lexeme_start    == (QUEX_TYPE_LEXATOM)0
#          endif
           && me->_backup_lexatom_index_of_lexeme_start_p == (QUEX_TYPE_STREAM_POSITION)-1;
}

QUEX_INLINE void
QUEX_NAME(Buffer_init_analyzis)(QUEX_NAME(Buffer)*   me) 
/* Initialize:  _read_p                          
 *              _lexeme_start_p                 
 *              _lexatom_at_lexeme_start     
 *              _lexatom_before_lexeme_start                                  */
{
    QUEX_TYPE_LEXATOM*  BeginP = &me->_memory._front[1];

    if( ! me->_memory._front ) {
        /* No memory => FSM is put into a non-functional state.               */
        QUEX_NAME(Buffer_init_analyzis_core)(me, 
        /* ReadP                          */ (QUEX_TYPE_LEXATOM*)0,
        /* LexatomStartP                  */ (QUEX_TYPE_LEXATOM*)0,
        /* LexatomAtLexemeStart           */ (QUEX_TYPE_LEXATOM)0,                                   
        /* LexatomBeforeLexemeStart       */ (QUEX_TYPE_LEXATOM)0,
        /* BackupLexatomIndexOfReadP      */ (QUEX_TYPE_STREAM_POSITION)-1);
    }
    else {
        /* The first state in the state machine does not increment. 
         * => input pointer is set to the first position, not before.         */
        QUEX_NAME(Buffer_init_analyzis_core)(me, 
        /* ReadP                          */ BeginP,
        /* LexatomStartP                  */ BeginP,
        /* LexatomAtLexemeStart           */ (QUEX_TYPE_LEXATOM)0,
        /* LexatomBeforeLexemeStart       */ QUEX_SETTING_CHARACTER_NEWLINE_IN_ENGINE_CODEC,
        /* BackupLexatomIndexOfReadP      */ (QUEX_TYPE_STREAM_POSITION)-1);
    }
}

QUEX_INLINE void
QUEX_NAME(Buffer_init_analyzis_core)(QUEX_NAME(Buffer)*        me,
                                     QUEX_TYPE_LEXATOM*        ReadP,
                                     QUEX_TYPE_LEXATOM*        LexatomStartP,
                                     QUEX_TYPE_LEXATOM         LexatomAtLexemeStart,
                                     QUEX_TYPE_LEXATOM         LexatomBeforeLexemeStart,
                                     QUEX_TYPE_STREAM_POSITION BackupLexatomIndexOfReadP) 
{
    (void)LexatomBeforeLexemeStart;

    me->_read_p                         = ReadP;
    me->_lexeme_start_p                 = LexatomStartP;
    me->_lexatom_at_lexeme_start        = LexatomAtLexemeStart;                                   
#   ifdef  __QUEX_OPTION_SUPPORT_BEGIN_OF_LINE_PRE_CONDITION                 
    me->_lexatom_before_lexeme_start    = LexatomBeforeLexemeStart;
#   endif
    me->_backup_lexatom_index_of_lexeme_start_p = BackupLexatomIndexOfReadP;
}

QUEX_INLINE void
QUEX_NAME(Buffer_init_content)(QUEX_NAME(Buffer)* me, QUEX_TYPE_LEXATOM* EndOfFileP)
/*  Initialize: input.lexatom_index_begin
 *              input.lexatom_index_end_of_stream                         
 *              input.end_p                                                   */
{
    QUEX_TYPE_LEXATOM*        BeginP           = &me->_memory._front[1];
    QUEX_TYPE_LEXATOM*        EndP             = me->_memory._back;
    QUEX_TYPE_STREAM_POSITION ci_begin         = (QUEX_TYPE_STREAM_POSITION)0;
    QUEX_TYPE_STREAM_POSITION ci_end_of_stream = (QUEX_TYPE_STREAM_POSITION)-1;
    QUEX_TYPE_LEXATOM*        end_p            = (QUEX_TYPE_LEXATOM*)0;
    (void)EndP;

    if( ! me->_memory._front ) {
        ci_end_of_stream = (QUEX_TYPE_STREAM_POSITION)-1;
        end_p            = (QUEX_TYPE_LEXATOM*)0;
        ci_begin         = (QUEX_TYPE_STREAM_POSITION)-1;
    }
    else if( me->filler && me->filler->byte_loader ) {
        __quex_assert(0 == EndOfFileP);

#       if 0
        loaded_n         = QUEX_NAME(LexatomLoader_load)(me->filler, BeginP, ContentSize,
                                                         0, &end_of_stream_f, &encoding_error_f);
        ci_end_of_stream = ((! loaded_n) || end_of_stream_f) ? loaded_n 
                                                             : (QUEX_TYPE_STREAM_POSITION)-1;
        end_p            = &BeginP[loaded_n];
#       endif
        /* Setup condition to initiate immediate load when the state machine
         * is entered: 'read pointer hits buffer limit code'.                */
        ci_begin         = (QUEX_TYPE_STREAM_POSITION)0;
        ci_end_of_stream = (QUEX_TYPE_STREAM_POSITION)-1;
        end_p            = &BeginP[0];
    } 
    else {
        __quex_assert(0 != me->_memory._front);           /* See first condition. */
        __quex_assert(! EndOfFileP || (EndOfFileP >= BeginP && EndOfFileP <= EndP));

        if( EndOfFileP ) {
            ci_end_of_stream = EndOfFileP - BeginP;
            end_p            = EndOfFileP;   
        }
        else {
            ci_end_of_stream = (QUEX_TYPE_STREAM_POSITION)-1;
            end_p            = BeginP;   
        }
    }

    QUEX_NAME(Buffer_init_content_core)(me, ci_begin, ci_end_of_stream, end_p);
}

QUEX_INLINE void
QUEX_NAME(Buffer_init_content_core)(QUEX_NAME(Buffer)* me, 
                                    QUEX_TYPE_STREAM_POSITION LI_Begin,
                                    QUEX_TYPE_STREAM_POSITION LI_EndOfStream,
                                    QUEX_TYPE_LEXATOM*        EndOfFileP)
{
    me->input.lexatom_index_begin         = LI_Begin;
    me->input.lexatom_index_end_of_stream = LI_EndOfStream;
    me->input.end_p                       = EndOfFileP;
    if( me->input.end_p ) {
        *(me->input.end_p)                = QUEX_SETTING_BUFFER_LIMIT_CODE;
    }

    QUEX_IF_ASSERTS_poison(&me->input.end_p[1], me->_memory._back);
}

QUEX_INLINE void
QUEX_NAME(Buffer_register_content)(QUEX_NAME(Buffer)*        me,
                                   QUEX_TYPE_LEXATOM*        EndOfInputP,
                                   QUEX_TYPE_STREAM_POSITION CharacterIndexBegin)
/* Registers information about the stream that fills the buffer and its
 * relation to the buffer. 
 *  
 *  EndOfInputP --> Position behind the last lexatom in the buffer that has
 *                  been streamed.
 *          '0' --> No change.
 *  
 *  CharacterIndexBegin --> Character index of the first lexatom in the 
 *                          buffer.
 *                 '-1' --> No change.                                       */
{
    if( EndOfInputP ) {
        __quex_assert(EndOfInputP <= me->_memory._back);
        __quex_assert(EndOfInputP >  me->_memory._front);

        me->input.end_p    = EndOfInputP;
        *(me->input.end_p) = QUEX_SETTING_BUFFER_LIMIT_CODE;
    }

    if( CharacterIndexBegin != (QUEX_TYPE_STREAM_POSITION)-1 ) {
        me->input.lexatom_index_begin = CharacterIndexBegin;
    }

    QUEX_IF_ASSERTS_poison(&me->input.end_p[1], me->_memory._back);
    /* NOT: assert(QUEX_NAME(Buffer_input_lexatom_index_begin)(me) >= 0);
     * This function may be called before content is setup/loaded propperly. */ 
}

QUEX_INLINE void       
QUEX_NAME(Buffer_register_eos)(QUEX_NAME(Buffer)*        me,
                               QUEX_TYPE_STREAM_POSITION CharacterIndexEndOfStream)
{
    me->input.lexatom_index_end_of_stream = CharacterIndexEndOfStream;
}

QUEX_INLINE bool
QUEX_NAME(Buffer_is_empty)(QUEX_NAME(Buffer)* me)
/* RETURNS: true, if buffer does not contain anything.
 *          false, else.                                                     */
{ 
    return    me->input.end_p == &me->_memory._front[1] 
           && me->input.lexatom_index_begin == 0; 
}

QUEX_INLINE QUEX_TYPE_STREAM_POSITION  
QUEX_NAME(Buffer_input_lexatom_index_end)(QUEX_NAME(Buffer)* me)
/* RETURNS: Character index of the lexatom to which '.input.end_p' points.
 *                                                                           */
{
    __quex_assert(me->input.lexatom_index_begin >= 0);
    QUEX_BUFFER_ASSERT_pointers_in_range(me);

    return   me->input.lexatom_index_begin 
           + (me->input.end_p - &me->_memory._front[1]);
}

QUEX_INLINE void
QUEX_NAME(Buffer_read_p_add_offset)(QUEX_NAME(Buffer)* buffer, const size_t Offset)
/* Add offset to '._read_p'. No check applies whether this is admissible.
 *                                                                           */
{ 
    QUEX_BUFFER_ASSERT_pointers_in_range(buffer);
    buffer->_read_p += Offset; 
    QUEX_BUFFER_ASSERT_pointers_in_range(buffer);
}

QUEX_INLINE size_t
QUEX_NAME(Buffer_content_size)(QUEX_NAME(Buffer)* me)
{
    return QUEX_NAME(BufferMemory_size)(&(me->_memory)) - 2;
}

QUEX_INLINE bool 
QUEX_NAME(Buffer_is_end_of_stream_inside)(QUEX_NAME(Buffer)* me)
{ 
    const ptrdiff_t ContentSize = (ptrdiff_t)QUEX_NAME(Buffer_content_size)(me);

    if( me->input.lexatom_index_end_of_stream == (QUEX_TYPE_STREAM_POSITION)-1 ) {
        return false;
    }
    else if( me->input.lexatom_index_end_of_stream < me->input.lexatom_index_begin ) {
        return false;
    }
    
    return me->input.lexatom_index_end_of_stream - me->input.lexatom_index_begin < ContentSize;
}

QUEX_INLINE bool 
QUEX_NAME(Buffer_is_end_of_stream)(QUEX_NAME(Buffer)* me)
{ 
    QUEX_BUFFER_ASSERT_CONSISTENCY(me);
    if( me->input.lexatom_index_end_of_stream == (QUEX_TYPE_STREAM_POSITION)-1 ) {
        return false;
    }
    else if( me->_read_p != me->input.end_p ) {
        return false;
    }

    return    QUEX_NAME(Buffer_input_lexatom_index_end)(me) 
           == me->input.lexatom_index_end_of_stream;
}

QUEX_INLINE bool                  
QUEX_NAME(Buffer_is_begin_of_stream)(QUEX_NAME(Buffer)* buffer)
{ 
    QUEX_BUFFER_ASSERT_CONSISTENCY(buffer);
    if     ( buffer->_lexeme_start_p != &buffer->_memory._front[1] ) return false;
    else if( QUEX_NAME(Buffer_input_lexatom_index_begin)(buffer) )   return false;
    else                                                             return true;
}

QUEX_INLINE void  
QUEX_NAME(Buffer_set_event_handlers)(QUEX_NAME(Buffer)* me,
                                     void   (*on_before_change)(void* aux),
                                     void   (*on_overflow)(void*  aux),
                                     void*  aux)
{
    me->event.on_buffer_before_change = on_before_change;
    me->event.on_buffer_overflow      = on_overflow;
    me->event.aux                     = aux;
}

QUEX_INLINE void
QUEX_NAME(Buffer_call_on_buffer_before_change)(QUEX_NAME(Buffer)* me)
{
    QUEX_ASSERT_BUFFER_INVARIANCE_SETUP(bi, me);
    if( me->event.on_buffer_before_change ) {
        me->event.on_buffer_before_change(me->event.aux); 
    }
    QUEX_ASSERT_BUFFER_INVARIANCE_VERIFY_SAME(bi, me);
}

QUEX_INLINE void
QUEX_NAME(Buffer_call_on_buffer_overflow)(QUEX_NAME(Buffer)* me)
{
    QUEX_ASSERT_BUFFER_INVARIANCE_SETUP(bi, me);
    if( me->event.on_buffer_overflow ) {
        me->event.on_buffer_overflow(me->event.aux);
    }
    QUEX_ASSERT_BUFFER_INVARIANCE_VERIFY(bi, me);
}

QUEX_INLINE bool
QUEX_NAME(Buffer_negotiate_allocate_memory)(const size_t        Size, 
                                            QUEX_TYPE_LEXATOM** memory, 
                                            size_t*             memory_size)
{
    const size_t MinSize = 4;             /* 2 for boarder, 2 for content */

    *memory_size = Size;

    do {
        *memory = (QUEX_TYPE_LEXATOM*)QUEXED(MemoryManager_allocate)(
                           (*memory_size) * sizeof(QUEX_TYPE_LEXATOM), 
                           E_MemoryObjectType_BUFFER_MEMORY);
        if( *memory ) {
            return true;
        }

        (*memory_size) = (MinSize + (*memory_size)) >> 1;

    } while( (*memory_size) > MinSize );

    return false;
}


QUEX_INLINE void
QUEX_NAME(Buffer_pointers_add_offset)(QUEX_NAME(Buffer)*  me,
                                      ptrdiff_t           offset,
                                      QUEX_TYPE_LEXATOM** position_register,
                                      const size_t        PositionRegisterN)
/* Modify all buffer related pointers and lexatom indices by an offset. It is
 * assumed, that buffer content has been moved by 'offset' and that pointers
 * and offsets still related to the content before the move. 
 *
 * EXAMPLE: (lexatom index at buffer begin, read_p)
 *
 *                       0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 
 * Stream:               [a][b][c][d][e][f][g][h][j][i][k][l][m][n][o][p]
 *
 * Buffer before move:           |[d][e][f][g][h]|
 *                                |        |
 *     lexatom_index_begin = 3 ---'        |
 *     read_p -----------------------------'
 *
 * Buffer after move, then ADD:  |[f][g][h][j][i]|
 *                                |   |
 *     lexatom_index_begin = 5 ---'   |
 *     read_p ------------------------'
 *
 * ADAPTS: _read_p, _lexeme_start_p, position registers, end_p, 
 *         input.end_lexatom_index                                            */
{ 
#   define QUEX_BUFFER_POINTER_ADD(P, BORDER, OFFSET)                \
           ((P) = (  ((P) == (QUEX_TYPE_LEXATOM*)0) ? (P)            \
                   : ((BORDER) - (P) < OFFSET)     ? (BORDER)        \
                   : (P) + (OFFSET)))
#   define QUEX_BUFFER_POINTER_SUBTRACT(P, BORDER, NEGATIVE_OFFSET)  \
           ((P) = (  ((P) == (QUEX_TYPE_LEXATOM*)0)     ? (P)        \
                   : ((BORDER) - (P) > NEGATIVE_OFFSET) ? (BORDER)   \
                   : (P) + (NEGATIVE_OFFSET)))
    QUEX_TYPE_LEXATOM*  border = (QUEX_TYPE_LEXATOM*)0;
    QUEX_TYPE_LEXATOM** pit    = (QUEX_TYPE_LEXATOM**)0x0;
    QUEX_TYPE_LEXATOM** pEnd   = &position_register[PositionRegisterN];

    QUEX_BUFFER_ASSERT_pointers_in_range(me);

    if( offset > 0 ) {
        border = me->_memory._back;
        QUEX_BUFFER_POINTER_ADD(me->_read_p,         border, offset);
        QUEX_BUFFER_POINTER_ADD(me->_lexeme_start_p, border, offset);
        QUEX_BUFFER_POINTER_ADD(me->input.end_p,     border, offset);

        for(pit = position_register; pit != pEnd; ++pit) {
            QUEX_BUFFER_POINTER_ADD(*pit, border, offset); 
        }
    }
    else if( offset < 0 ) {
        border = &me->_memory._front[1];
        QUEX_BUFFER_POINTER_SUBTRACT(me->_read_p,         border, offset);
        QUEX_BUFFER_POINTER_SUBTRACT(me->_lexeme_start_p, border, offset);
        QUEX_BUFFER_POINTER_SUBTRACT(me->input.end_p,     border, offset);

        for(pit = position_register; pit != pEnd; ++pit) {
            QUEX_BUFFER_POINTER_SUBTRACT(*pit, border, offset); 
        }
    }
    else {
        return;
    }

    *(me->input.end_p) = (QUEX_TYPE_LEXATOM)QUEX_SETTING_BUFFER_LIMIT_CODE;

    me->input.lexatom_index_begin -= offset;

    QUEX_BUFFER_ASSERT_pointers_in_range(me);

#   undef QUEX_BUFFER_POINTER_ADD
#   undef QUEX_BUFFER_POINTER_SUBTRACT
}

QUEX_INLINE void
QUEX_NAME(BufferInvariance_construct)(QUEX_NAME(BufferInvariance)* me, 
                                      QUEX_NAME(Buffer)*           subject)
/* Store all buffer related pointers and indicates present in 'subject'.      */
{
    me->front_p             = subject->_memory._front;
    me->back_p              = subject->_memory._back;
    me->end_p               = subject->input.end_p;
    me->read_p              = subject->_read_p;
    me->lexeme_start_p      = subject->_lexeme_start_p;
    me->lexatom_index_begin = subject->input.lexatom_index_begin;
}

QUEX_INLINE void
QUEX_NAME(BufferInvariance_assert)(QUEX_NAME(BufferInvariance)* me, 
                                   QUEX_NAME(Buffer)*           subject,
                                   bool                         SameF)
/* Assert that pointers and indices in 'me' and 'subject' are equivalent or
 * the same. When 'SameF' is true, equivalents is required.
 *
 * ASSERTS: see above.                                                        */
{
    if( SameF ) {
        __quex_assert(me->front_p             == subject->_memory._front);
        __quex_assert(me->back_p              == subject->_memory._back);
        __quex_assert(me->end_p               == subject->input.end_p);
        __quex_assert(me->lexatom_index_begin == subject->input.lexatom_index_begin);
    }

    /* Dislocation of '_read_p' same as the dislocation of '_lexeme_start_p'. */
    __quex_assert(me->read_p - subject->_read_p == me->lexeme_start_p - subject->_lexeme_start_p);
}

QUEX_INLINE void
QUEX_NAME(BufferInvariance_restore)(QUEX_NAME(BufferInvariance)* me, 
                                    QUEX_NAME(Buffer)*           subject)
/* Restores all pointers and indices relevant for a buffer from 'me' into 
 * 'subject'.                                                                 */
{
    subject->_memory._front            = me->front_p;
    subject->_memory._back             = me->back_p;
    subject->input.end_p               = me->end_p;
    subject->_read_p                   = me->read_p;
    subject->_lexeme_start_p           = me->lexeme_start_p;
    subject->input.lexatom_index_begin = me->lexatom_index_begin;
}

QUEX_NAMESPACE_MAIN_CLOSE

#include <quex/code_base/buffer/lexatoms/LexatomLoader.i>
#include <quex/code_base/buffer/Buffer_print.i>
#include <quex/code_base/buffer/Buffer_navigation.i>
#include <quex/code_base/buffer/Buffer_fill.i>
#include <quex/code_base/buffer/Buffer_load.i>
#include <quex/code_base/buffer/Buffer_nested.i>
#include <quex/code_base/buffer/Buffer_move.i>
#include <quex/code_base/buffer/BufferMemory.i>

#endif /* __QUEX_INCLUDE_GUARD__BUFFER__BUFFER_I */
