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

QUEX_INLINE ptrdiff_t QUEX_NAME(Buffer_move_forward)(QUEX_NAME(Buffer)*  me, 
                                                     ptrdiff_t           move_distance);
QUEX_INLINE void      QUEX_NAME(Buffer_move_forward_undo)(QUEX_NAME(Buffer)* me,
                                                          intmax_t           move_distance,
                                                          ptrdiff_t          move_size);
QUEX_INLINE ptrdiff_t QUEX_NAME(Buffer_move_backward)(QUEX_NAME(Buffer)* me, 
                                                      ptrdiff_t          move_distance);

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
QUEX_INLINE void      QUEX_NAME(Buffer_init_analyzis)(QUEX_NAME(Buffer)*   me);

QUEX_INLINE void      QUEX_NAME(Buffer_on_overflow_DEFAULT)(QUEX_NAME(Buffer)*, bool ForwardF);
QUEX_INLINE void      QUEX_NAME(Buffer_on_content_change_DEFAULT)(const QUEX_TYPE_LEXATOM*, 
                                                                  const QUEX_TYPE_LEXATOM*);

QUEX_INLINE void
QUEX_NAME(Buffer_construct)(QUEX_NAME(Buffer)*        me, 
                            QUEX_NAME(LexatomLoader)* filler,
                            QUEX_TYPE_LEXATOM*        memory,
                            const size_t              MemorySize,
                            QUEX_TYPE_LEXATOM*        EndOfFileP,
                            E_Ownership               Ownership)
{
    /* Ownership of InputMemory is passed to 'me->_memory'.                  */
    QUEX_NAME(BufferMemory_construct)(&me->_memory, memory, MemorySize, 
                                      Ownership); 
    
    /* By setting begin and end to zero, we indicate to the loader that      
     * this is the very first load procedure.                                */
    me->filler       = filler;
    me->fill         = QUEX_NAME(Buffer_fill);
    me->fill_prepare = QUEX_NAME(Buffer_fill_prepare);
    me->fill_finish  = QUEX_NAME(Buffer_fill_finish);

    /* Event handlers.                                                       */
    me->on_content_change = QUEX_NAME(Buffer_on_content_change_DEFAULT);
    me->on_overflow       = QUEX_NAME(Buffer_on_overflow_DEFAULT);

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
    if( me->filler ) {
        me->filler->delete_self(me->filler); 
    }
    me->filler = (QUEX_NAME(LexatomLoader)*)0;
    QUEX_NAME(BufferMemory_destruct)(&me->_memory);

    QUEX_NAME(Buffer_resources_absent_mark)(me);
}

QUEX_INLINE bool
QUEX_NAME(Buffer_construct_included)(QUEX_NAME(Buffer)*        including,
                                     QUEX_NAME(Buffer)*        included,
                                     QUEX_NAME(LexatomLoader)* filler)
/* Construct 'included' buffer (-> memory split):
 *
 * Constructor takes over ownership over 'filler'. If construction fails,
 * the 'filler' is immediatedly deleted.
 *
 * To optimize memory usage and minimize the generation of new buffers in 
 * situations of extensive file inclusions, the current buffer's memory may
 * be split to generate the included buffer's memory.
 *
 *                 including  .---------------------.
 *                 buffer     |0|a|b|c|d|0| | | | | |
 *                            '---------------------'
 *                   read_p -------'     |
 *                   end_p  -------------'
 *
 *                              /    split      \
 *                             /                 \
 *                                  
 *        including  .-----------.     included .---------.
 *        buffer     |0|a|b|c|d|0|  +  buffer   | | | | | |
 *                   '-----------'              '---------'
 *          read_p -------'     |
 *          end_p  -------------'
 *
 * NOTE: Loaded content is NEVER overwritten or split. This is a precaution
 *       for situations where byte loaders may not be able to reload content
 *       that has already been loaded (for example 'TCP socket' byte loaders).
 *
 * RETURNS: true,  if memory has been allocated and the 'included' buffer is
 *                 ready to rumble.
 *          false, if memory allocation failed. 'included' buffer is not 
 *                 functional.
 *                                                                            */
{
    /*         front           read_p      end_p                 back
     *           |               |           |                   |
     *          .-------------------------------------------------.
     *          |0|-|-|-|-|-|-|-|a|b|c|d|e|f|0| | | | | | | | | | |
     *          '-------------------------------------------------'
     *                                         :                 :
     *                                         '--- available ---'
     *                                                                        */
    ptrdiff_t                 available_size =   including->_memory._back 
                                               - including->input.end_p;
    QUEX_TYPE_LEXATOM*        memory;
    size_t                    memory_size;
    E_Ownership               ownership;
    QUEX_TYPE_STREAM_POSITION backup_ios;

    if( QUEX_NAME(Buffer_resources_absent)(including) ) {
        if( filler ) {
            filler->delete_self(filler); 
        }
        QUEX_NAME(Buffer_resources_absent_mark)(included);
        return false;
    }
    else if( available_size < (ptrdiff_t)(QUEX_SETTING_BUFFER_INCLUDE_MIN_SIZE) ) {
        /* Buffer_move_away_passed_content() refuses to move if end of stream
         * is inside buffer. 
         * => Trick: Backup & restore 'lexatom_index_end_of_stream'           */
        backup_ios = including->input.lexatom_index_end_of_stream;
        including->input.lexatom_index_end_of_stream = (QUEX_TYPE_STREAM_POSITION)-1;
        /* Position registers are only relevant during lexical analyzis.
         * Inclusion happens in a 'terminal' or external to the lexer step.   
         * => Position registers = empty set.                                 */
        (void)QUEX_NAME(Buffer_move_away_passed_content)(including, 
                                                         (QUEX_TYPE_LEXATOM)0, 0x0); 
        including->input.lexatom_index_end_of_stream = backup_ios;

        /* After 'move away' possibly:
         *
         *   size(including's buffer) < 'QUEX_SETTING_BUFFER_INCLUDE_MIN_SIZE'
         *
         * However, 'including' buffer is NOT used before 'included' terminates.
         * => included is pasted back at the end of including.                */
        available_size = including->_memory._back - including->input.end_p;
    }

    if( available_size < (ptrdiff_t)(QUEX_SETTING_BUFFER_INCLUDE_MIN_SIZE) ) {
        memory_size = (size_t)(QUEX_SETTING_BUFFER_SIZE);
        memory      = (QUEX_TYPE_LEXATOM*)QUEXED(MemoryManager_allocate)(
                                memory_size * sizeof(QUEX_TYPE_LEXATOM), 
                                E_MemoryObjectType_BUFFER_MEMORY);
        if( ! memory ) {
            if( filler ) {
                filler->delete_self(filler); 
            }
            QUEX_NAME(Buffer_resources_absent_mark)(included);
            return false;
        }
        ownership = E_Ownership_LEXICAL_ANALYZER;
    }
    else {
        memory                   = &including->input.end_p[1];
        memory_size              = (size_t)(&including->_memory._back[1] - memory);
        including->_memory._back = &including->input.end_p[0];
        __quex_assert(memory);
        ownership = E_Ownership_INCLUDING_BUFFER;
    }

    QUEX_NAME(Buffer_construct)(included, filler, memory, memory_size, 
                                (QUEX_TYPE_LEXATOM*)0, ownership);
    QUEX_BUFFER_ASSERT_CONSISTENCY(included);
    QUEX_BUFFER_ASSERT_CONSISTENCY(including);
    return true;
}

QUEX_INLINE void
QUEX_NAME(Buffer_destruct_included)(QUEX_NAME(Buffer)* including,
                                    QUEX_NAME(Buffer)* included)
{
    if( included->_memory.ownership == E_Ownership_INCLUDING_BUFFER ) {
        __quex_assert(&included->_memory._front[0] == &including->_memory._back[1]);
        including->_memory._back = included->_memory._back;
    }
    /* Destructor only frees memory, if ownership is 'LEXICAL_ANALYZER'.      */
    QUEX_NAME(Buffer_destruct)(included);
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
QUEX_NAME(Buffer_init_analyzis)(QUEX_NAME(Buffer)*   me) 
/* Initialize:  _read_p                          
 *              _lexeme_start_p                 
 *              _lexatom_at_lexeme_start     
 *              _lexatom_before_lexeme_start                                 */
{
    QUEX_TYPE_LEXATOM*  BeginP = &me->_memory._front[1];

    if( ! me->_memory._front ) {
        /* No memory => FSM is put into a non-functional state.         */
        me->_read_p                      = (QUEX_TYPE_LEXATOM*)0;
        me->_lexeme_start_p              = (QUEX_TYPE_LEXATOM*)0;
        me->_lexatom_at_lexeme_start     = (QUEX_TYPE_LEXATOM)0;                                   
#       ifdef  __QUEX_OPTION_SUPPORT_BEGIN_OF_LINE_PRE_CONDITION                 
        me->_lexatom_before_lexeme_start = (QUEX_TYPE_LEXATOM)0;
#       endif
    }
    else {
        /* The first state in the state machine does not increment. 
         * => input pointer is set to the first position, not before.        */
        me->_read_p                      = BeginP;                                
        me->_lexeme_start_p              = BeginP;                                
        me->_lexatom_at_lexeme_start     = '\0';  /* Nothing covered. */
#       ifdef  __QUEX_OPTION_SUPPORT_BEGIN_OF_LINE_PRE_CONDITION                     
        /* When the buffer is initialized, a line begins. Set 'newline'.     */
        me->_lexatom_before_lexeme_start = QUEX_SETTING_CHARACTER_NEWLINE_IN_ENGINE_CODEC;
#       endif
    }
}

QUEX_INLINE void
QUEX_NAME(Buffer_init_content)(QUEX_NAME(Buffer)* me, QUEX_TYPE_LEXATOM* EndOfFileP)
/*  Initialize: input.lexatom_index_begin
 *              input.lexatom_index_end_of_stream                         
 *              input.end_p                                                  */
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
        __quex_assert(! EndOfFileP);

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
        __quex_assert(me->_memory._front);           /* See first condition. */
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
    me->input.lexatom_index_begin         = ci_begin;
    me->input.lexatom_index_end_of_stream = ci_end_of_stream;
    me->input.end_p                       = end_p;
    if( me->input.end_p ) {
        *(me->input.end_p)                = QUEX_SETTING_BUFFER_LIMIT_CODE;
    }

    QUEX_IF_ASSERTS_poison(&me->input.end_p[1], me->_memory._back);
}

QUEX_INLINE void
QUEX_NAME(Buffer_register_content)(QUEX_NAME(Buffer)*        me,
                                   QUEX_TYPE_LEXATOM*      EndOfInputP,
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
QUEX_NAME(Buffer_is_end_of_file)(QUEX_NAME(Buffer)* me)
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
QUEX_NAME(Buffer_is_begin_of_file)(QUEX_NAME(Buffer)* buffer)
{ 
    QUEX_BUFFER_ASSERT_CONSISTENCY(buffer);
    if     ( buffer->_read_p != buffer->_memory._front )           return false;
    else if( QUEX_NAME(Buffer_input_lexatom_index_begin)(buffer) ) return false;
    else                                                           return true;
}

QUEX_INLINE bool
QUEX_NAME(Buffer_move_and_load_forward)(QUEX_NAME(Buffer)*        me, 
                                        QUEX_TYPE_STREAM_POSITION NewCharacterIndexBegin,
                                        QUEX_TYPE_STREAM_POSITION MinCharacterIndexInBuffer)
/* RETURNS:  true -- if the the buffer could be filled start from 
 *                   NewCharacterIndexBegin.
 *           false, else.
 *
 * In case, that the loading fails, the buffer is setup as it was BEFORE the call
 * to this function.
 *
 * EXPLANATION:
 *
 * Before:    .-------------------------------------- prev lexatom_index_begin             
 *            :                 
 *            | . . . . . . . . .x.x.x.x.x.x.x.x.x.x.x| 
 *                              |<---- move size ---->|
 * After:     |<- move distance |
 *            .-------------------------------------- new lexatom_index_begin
 *            :                     .---------------- prev lexatom index begin
 *            :                     :  
 *            |x.x.x.x.x.x.x.x.x.x.x|N.N.N.N.N.N.N. . | 
 *            |- move_size -------->|- loaded_n ->|
 *                                                             
 * Moves the region of size 'Size' from the end of the buffer to the beginning
 * of the buffer and tries to load as many lexatoms as possible behind it. */
{
    QUEX_TYPE_LEXATOM*        BeginP      = &me->_memory._front[1];
    QUEX_TYPE_LEXATOM*        EndP        = me->_memory._back;
    const ptrdiff_t           ContentSize = (ptrdiff_t)QUEX_NAME(Buffer_content_size)(me);
    QUEX_TYPE_STREAM_POSITION load_lexatom_index;
    ptrdiff_t                 load_request_n;
    QUEX_TYPE_LEXATOM*        load_p;
    ptrdiff_t                 loaded_n;
    intmax_t                  move_distance;
    ptrdiff_t                 move_size;
    bool                      end_of_stream_f  = false;
    bool                      encoding_error_f = false;

    QUEX_BUFFER_ASSERT_CONSISTENCY(me);
    __quex_assert(me->input.lexatom_index_begin        <= NewCharacterIndexBegin);
    __quex_assert(NewCharacterIndexBegin               <= MinCharacterIndexInBuffer);
    __quex_assert(NewCharacterIndexBegin + ContentSize >= MinCharacterIndexInBuffer );

    if(    me->input.lexatom_index_end_of_stream != -1
        && MinCharacterIndexInBuffer >= me->input.lexatom_index_end_of_stream ) {
        /* If the end of the stream is INSIDE the buffer already, then there
         * is no need, no chance, of loading more content.                   */
        return false;
    }

    /* Move existing content in the buffer to appropriate position.          */
    move_distance      = NewCharacterIndexBegin - me->input.lexatom_index_begin;
    move_size          = QUEX_NAME(Buffer_move_forward)(me, (ptrdiff_t)move_distance);
    load_lexatom_index = NewCharacterIndexBegin + move_size;
    load_request_n     = ContentSize - move_size; 
    load_p             = &BeginP[move_size];

    __quex_assert(load_lexatom_index == NewCharacterIndexBegin + (load_p - BeginP));
    __quex_assert(load_p >= BeginP);
    __quex_assert(&load_p[load_request_n] <= EndP);
    (void)EndP;
    loaded_n = QUEX_NAME(LexatomLoader_load)(me->filler, load_p, load_request_n,
                                             load_lexatom_index,
                                             &end_of_stream_f, &encoding_error_f);

    if( (! loaded_n) || end_of_stream_f ) { /* End of stream detected.       */
        QUEX_NAME(Buffer_register_eos)(me, load_lexatom_index + loaded_n);
    }

    /* (3) In case of failure, restore previous buffer content.              */
    if( MinCharacterIndexInBuffer >= load_lexatom_index + loaded_n ) {
        QUEX_NAME(Buffer_move_forward_undo)(me, move_distance, move_size);
        return false;
    }

    QUEX_NAME(Buffer_register_content)(me, &load_p[loaded_n], NewCharacterIndexBegin);
    return true;
}

QUEX_INLINE bool
QUEX_NAME(Buffer_move_and_load_backward)(QUEX_NAME(Buffer)*        me, 
                                         QUEX_TYPE_STREAM_POSITION NewCharacterIndexBegin)
/* Before:                     
 *            .------------------------------------- prev lexatom index begin
 *            :
 *            |x.x.x.x.x.x.x.x.x.x. . . . . . . . . . . . . |
 *            |<--- move size---->|                         
 * After:                                             
 *            .------------------------------------- new lexatom index begin
 *            :                     .--------------- prev lexatom index begin
 *            :                     :
 *            :--- move distance--->|                 
 *            |N.N.N.N.N.N.N.N.N.N.N.x.x.x.x.x.x.x.x.x.x. . | 
 *                               
 * Moves the region of size 'Size' from the beginning of the buffer to the end
 * and tries to load as many lexatoms as possible behind it. If the try fails
 * something is seriously wrong.                                             */
{
    QUEX_TYPE_LEXATOM*       BeginP   = &me->_memory._front[1];
    QUEX_TYPE_LEXATOM*       EndP     = me->_memory._back;
    QUEX_TYPE_STREAM_POSITION  ci_begin = QUEX_NAME(Buffer_input_lexatom_index_begin)(me);
    ptrdiff_t                  load_request_n;
    ptrdiff_t                  loaded_n;
    ptrdiff_t                  move_distance;
    QUEX_TYPE_LEXATOM*         end_p;
    bool                       end_of_stream_f = false;
    bool                       encoding_error_f = false;

    __quex_assert(NewCharacterIndexBegin >= 0);
    __quex_assert(ci_begin  >= NewCharacterIndexBegin);

    /* (1) Move away content, so that previous content can be reloaded.      */
    move_distance  = (ptrdiff_t)(ci_begin - NewCharacterIndexBegin);
    load_request_n = QUEX_NAME(Buffer_move_backward)(me, (ptrdiff_t)move_distance);

    __quex_assert(&BeginP[load_request_n] <= EndP);

    /* (2) Move away content, so that previous content can be reloaded.      */
    loaded_n = QUEX_NAME(LexatomLoader_load)(me->filler, BeginP, load_request_n,
                                             NewCharacterIndexBegin,
                                             &end_of_stream_f, &encoding_error_f);
                           
    /* (3) In case of error, the stream must have been corrupted. Previously
     *     present content is not longer available. Continuation impossible. */
    if( loaded_n != load_request_n ) {
        QUEX_ERROR_EXIT("Buffer filler failed to load content that has been loaded before.!");
        return false;
    }

    end_p = EndP - me->input.end_p < move_distance ? 
            EndP : &me->input.end_p[move_distance];

    QUEX_NAME(Buffer_register_content)(me, end_p, NewCharacterIndexBegin);
    return true;
}
   
QUEX_INLINE ptrdiff_t
QUEX_NAME(Buffer_move_away_passed_content)(QUEX_NAME(Buffer)*  me,
                                           QUEX_TYPE_LEXATOM** position_register,
                                           const size_t        PositionRegisterN)
/* Free some space AHEAD so that new content can be loaded. Content that 
 * is still used, or expected to be used shall remain inside the buffer.
 * Following things need to be respected:
 *
 *    _lexeme_start_p  --> points to the lexeme that is currently treated.
 *                         MUST BE INSIDE BUFFER!
 *    _read_p          --> points to the lexatom that is currently used
 *                         for triggering. MUST BE INSIDE BUFFER!
 *    fall back region --> A used defined buffer backwards from the lexeme
 *                         start. Shall help to avoid extensive backward
 *                         loading.
 *
 * RETURNS: Moved distance.                                                  */
{ 
    QUEX_TYPE_LEXATOM*        BeginP = &me->_memory._front[1];
    const QUEX_TYPE_LEXATOM*  EndP   = me->_memory._back;
    const ptrdiff_t           ContentSize = (ptrdiff_t)QUEX_NAME(Buffer_content_size)(me);
    QUEX_TYPE_LEXATOM*        move_begin_p;
    ptrdiff_t                 move_size;
    ptrdiff_t                 move_distance;
    const ptrdiff_t           FallBackN = (ptrdiff_t)QUEX_SETTING_BUFFER_MIN_FALLBACK_N;
    QUEX_TYPE_LEXATOM**       pr_it     = 0x0;

    QUEX_BUFFER_ASSERT_CONSISTENCY(me);
    __quex_assert(FallBackN >= 0);

    if( me->_read_p - me->_lexeme_start_p >= ContentSize - FallBackN ) { 
        /* OVERFLOW: If stretch from _read_p to _lexeme_start_p 
         * spans the whole buffer, then nothing can be loaded.               */
        me->on_overflow(me, /* Forward */ true);
        return 0;
    }
    else if( QUEX_NAME(Buffer_is_end_of_stream_inside)(me) ) {
        /* Refuse the move, if the end of stream is inside buffer.           */
        return 0;
    }

    /* Determine from where the region-to-be-moved BEGINS, what its size is
     * and how far it is to be moved.                                        */
    move_begin_p  = me->_read_p;
    if( me->_lexeme_start_p ) {
        move_begin_p = QUEX_MIN(move_begin_p, me->_lexeme_start_p);
    }
    if( move_begin_p - BeginP <= FallBackN ) {
        return 0;
    }
    move_begin_p  = &move_begin_p[- FallBackN];
    move_distance = move_begin_p - BeginP;

    if( ! move_distance ) {
        return 0;
    }

    move_size = QUEX_NAME(Buffer_move_forward)(me, move_distance);

    /* Pointer Adaption: _read_p, _lexeme_start_p, position registers.
     *                   input.end_p, input.end_lexatom_index              */
    me->_read_p                                   -= move_distance;
    if( me->_lexeme_start_p ) me->_lexeme_start_p -= move_distance;
   
    if( position_register ) {
        /* All position registers MUST point behind '_lexeme_start_p'.       */
        for(pr_it = position_register; pr_it != &position_register[PositionRegisterN]; ++pr_it) {
            if( ! *pr_it ) continue;
            *pr_it = (*pr_it - BeginP) >= move_distance ? *pr_it - move_distance : 0;
        }
    }

    /* input.end_p/end_lexatom_index: End lexatom index remains the SAME, 
     * since no new content has been loaded into the buffer.                 */
    __quex_assert(me->input.end_p - BeginP >= move_distance);

    QUEX_NAME(Buffer_register_content)(me, &me->input.end_p[- move_distance], 
                                       me->input.lexatom_index_begin + move_distance);

    /*_______________________________________________________________________*/
    __quex_assert(me->input.end_p == &move_begin_p[move_size - move_distance]);
    (void)move_size;
    QUEX_IF_ASSERTS_poison(&EndP[- move_distance + 1], EndP);
    QUEX_BUFFER_ASSERT_CONSISTENCY(me);
    (void)EndP;

    return move_distance;
}

QUEX_INLINE E_LoadResult
QUEX_NAME(Buffer_load_forward)(QUEX_NAME(Buffer)*  me,
                               QUEX_TYPE_LEXATOM** position_register,
                               const size_t        PositionRegisterN)
/* Load as much new content into the buffer as possible--from what lies ahead
 * in the input stream. Maintains '_read_p', '_lexeme_start_p' inside the
 * buffer (if possible also fallback region). The 'input.end_p' pointer and
 * 'input.end_lexatom_index' are adapted according to the newly loaded
 * content, i.e. the point to exactly the same lexatom as before the load.
 *
 * BEHAVIOR: BLOCKING wait for incoming stream content. 
 *           No return without content--except at end of stream.
 *
 *           Buffer and pointers are adapted are adapted IN ANY CASE!
 *
 *           (i) Content present:
 *               => return 'true'.
 *
 *           (ii) No content:
 *               => pointers are 'disabled' because 'end_p = _read_p'.
 *                  return 'false'.
 *
 * RETURNS: 
 *          
 *     DONE              => Something has been loaded   (analysis MAY CONTINUE)
 *     FAILURE           => General load failure.       (analysis MUST STOP)
 *     NO_SPACE_FOR_LOAD => Lexeme exceeds buffer size. (analysis MUST STOP)
 *     ENCODING_ERROR    => Failed. conversion error    (analysis MUST STOP)
 *     NO_MORE_DATA      => No more data available.     (analysis MUST STOP)
 *     BAD_LEXATOM       => Read pointer on buffer limit code,
 *                          but it was not a buffer limit.
 *
 * The case of 'end-of-stream' may be true in both cases. When 'end-of-stream' 
 * is detected, the lexatom index of the 'end-of-stream' is registered. This 
 * prevents future attemps to load beyond that index. Again, even if 
 * 'end-of-stream' has been detected, there might be lexatoms for the lexer 
 * to chew on.                                                               */
{
    QUEX_TYPE_LEXATOM*          BeginP      = &me->_memory._front[1];
    QUEX_TYPE_LEXATOM*          EndP        = me->_memory._back;
    const ptrdiff_t             ContentSize = (ptrdiff_t)QUEX_NAME(Buffer_content_size)(me);
    QUEX_TYPE_STREAM_POSITION   ci_begin    = QUEX_NAME(Buffer_input_lexatom_index_begin)(me);
    QUEX_TYPE_STREAM_POSITION   ci_load_begin;
    ptrdiff_t                   move_distance;
    ptrdiff_t                   load_request_n;
    ptrdiff_t                   loaded_n;
    bool                        end_of_stream_f  = false;
    bool                        encoding_error_f = false;

    QUEX_BUFFER_ASSERT_CONSISTENCY(me);

    if( me->_read_p != me->input.end_p) {
        /* If the read pointer does not stand on the end of input pointer, then
         * the 'buffer limit code' at the read pointer is a bad lexatom.    
         * Buffer limit codes cannot be possibly be part of buffer content.  */
        return E_LoadResult_BAD_LEXATOM;
    }
    else if( ! me->filler || ! me->filler->byte_loader ) {
        QUEX_NAME(Buffer_register_eos)(me, ci_begin + (me->input.end_p - BeginP));
        return E_LoadResult_NO_MORE_DATA;  /* No filler/loader => no load!   */
    }

    /* Move remaining content.
     * Maintain lexeme and fallback.                 
     * Adapt pointers.                                                       */
    move_distance = QUEX_NAME(Buffer_move_away_passed_content)(me, position_register, 
                                                               PositionRegisterN);
    if( ! move_distance && me->input.end_p == EndP ) {
        return E_LoadResult_NO_SPACE_FOR_LOAD;  /* No free space for loading. */
    }

    /* Load new content.                                                     */
    ci_load_begin  = me->input.lexatom_index_begin + (me->input.end_p - BeginP);
    load_request_n = ContentSize                   - (me->input.end_p - BeginP);
    loaded_n       = QUEX_NAME(LexatomLoader_load)(me->filler, 
                                                   me->input.end_p, load_request_n,
                                                   ci_load_begin, 
                                                   &end_of_stream_f,
                                                   &encoding_error_f);
    QUEX_NAME(Buffer_register_content)(me, &me->input.end_p[loaded_n], -1);

    if( ! loaded_n ) {
        /* If filler returned, then either some lexatoms have been filled, 
         * or it indicates 'end-of-stream' by 'load_n = 0'.                  */
        end_of_stream_f = true; 
    }
    if( end_of_stream_f ) {
        QUEX_NAME(Buffer_register_eos)(me, ci_load_begin + loaded_n); 
    }

    __quex_debug_buffer_load(me, "LOAD FORWARD(exit)\n");
    QUEX_BUFFER_ASSERT_CONSISTENCY(me);
    if     ( encoding_error_f ) return E_LoadResult_BAD_LEXATOM;
    else if( loaded_n )         return E_LoadResult_DONE;
    else                        return E_LoadResult_NO_MORE_DATA;
}

QUEX_INLINE ptrdiff_t        
QUEX_NAME(Buffer_move_away_upfront_content)(QUEX_NAME(Buffer)* me)
/* Free some space in the REAR so that previous content can be re-loaded. Some 
 * content is to be left in front, so that no immediate reload is necessary
 * once the analysis goes forward again. Following things need to be respected:
 *
 *    _lexeme_start_p  --> points to the lexeme that is currently treated.
 *                         MUST BE INSIDE BUFFER!
 *    _read_p          --> points to the lexatom that is currently used
 *                         for triggering. MUST BE INSIDE BUFFER!
 *
 * RETURNS: Distance the the buffer content has been freed to be filled.     */
{
    const QUEX_TYPE_LEXATOM*  BeginP      = &me->_memory._front[1];
    QUEX_TYPE_LEXATOM*        EndP        = me->_memory._back;
    QUEX_TYPE_LEXATOM*        LastP       = &me->_memory._back[-1];
    const ptrdiff_t           ContentSize = EndP - BeginP;
    ptrdiff_t                 move_distance;
    ptrdiff_t                 move_distance_max;
    ptrdiff_t                 move_distance_nominal;
    QUEX_TYPE_LEXATOM*        end_p;

    QUEX_BUFFER_ASSERT_CONSISTENCY(me);
    __quex_assert(me->_read_p <= LastP);

    if( me->input.lexatom_index_begin == 0 && BeginP == me->_read_p ) {
        return 0;                        /* Begin of stream.                 */
    }
    else if( me->_lexeme_start_p >= LastP ) { 
        /* If _lexeme_start_p at back, then no new content can be loaded.    */
        me->on_overflow(me, /* Forward */ false);
        return 0;
    }

    /* Max. possible move distance: where 'read_p' or 'lexeme_start_p'
     * land on last position in the buffer.                                  */
    move_distance_max = LastP - QUEX_MAX(me->_read_p, me->_lexeme_start_p);
    /* Also, move before lexatom index '0' is impossible.                    */
    move_distance_max = QUEX_MIN(move_distance_max, (ptrdiff_t)me->input.lexatom_index_begin);

    /* Desired move distance: ContentSize / 3                                */
    move_distance_nominal = ContentSize > 3 ?  ContentSize / 3 : ContentSize;

    move_distance = QUEX_MIN(move_distance_max, move_distance_nominal); 
    if( ! move_distance ) {
        return 0;
    }

    (void)QUEX_NAME(Buffer_move_backward)(me, move_distance);

    /* Pointer Adaption: _read_p, _lexeme_start_p.                           */
    me->_read_p += move_distance;
    if( me->_lexeme_start_p ) me->_lexeme_start_p += move_distance;

    /* Adapt and of content pointer and new lexatom index at begin.          */
    end_p = EndP - me->input.end_p < move_distance ? EndP
                                                   : &me->input.end_p[move_distance];

    QUEX_NAME(Buffer_register_content)(me, end_p, 
                                       me->input.lexatom_index_begin - move_distance);

    /*_______________________________________________________________________*/
    QUEX_IF_ASSERTS_poison(BeginP, &BeginP[move_distance]); 
    QUEX_BUFFER_ASSERT_CONSISTENCY(me);

    return move_distance;
}

QUEX_INLINE E_LoadResult   
QUEX_NAME(Buffer_load_backward)(QUEX_NAME(Buffer)* me)
/* Load *previous* content into the buffer so that the analyzer can continue
 * seeminglessly (in backward direction).
 *
 * BEHAVIOR: BLOCKING wait for incoming stream content. 
 *           No return without content--except at end of stream.
 *
 *           Buffer and pointers are adapted are adapted IN ANY CASE!
 *
 * RETURNS: 
 *          
 *     DONE              => Something has been loaded   (analysis MAY CONTINUE)
 *     FAILURE           => General load failure.       (analysis MUST STOP)
 *     NO_SPACE_FOR_LOAD => Lexeme exceeds buffer size. (analysis MUST STOP)
 *     ENCODING_ERROR    => Failed. Conversion error.   (analysis MUST STOP)
 *     NO_MORE_DATA      => Begin of stream reached.    (analysis MUST STOP)
 *
 *  __________________________________________________________________________
 * ! In the false case, the range from 'Begin' to '_lexeme_start_p' may       !
 * ! have ARBITRARY CONTENT. Then the '_read_p' MUST be reset IMMEDIATELY and !
 * ! only forward analysis may work.                                          !
 * '--------------------------------------------------------------------------'
 *
 *_____________________________________________________________________________
 * NO ADAPTIONS OF POST-CONTEXT POSITIONS. Reason: Backward analysis appears
 * only in the following two cases.
 *  
 *  (1) When checking for a pre-condition. This does not involve pre-contexts.
 * 
 *  (2) When tracing back along a 'pseudo-ambigous post context'. However,
 *      the stretch from 'end-of-core' pattern to 'end-of-post context' lies
 *      completely in between 'lexeme start' to 'read '. Thus, one never has
 *      to go farther back then the buffer's begin.                          */
{
    QUEX_TYPE_LEXATOM*  BeginP = &me->_memory._front[1];
    ptrdiff_t           move_distance;
    ptrdiff_t           loaded_n;
    bool                end_of_stream_f  = false;
    bool                encoding_error_f = false;

    QUEX_BUFFER_ASSERT_CONSISTENCY(me);

    __quex_debug_buffer_load(me, "BACKWARD(entry)\n");
    if( me->_read_p != me->_memory._front ) {
        /* If the read pointer does not stand on 'front', then the buffer limit
         * code is a bad character, Buffer limit codes are not supposed to     
         * appear in buffer content.                                         */
        return E_LoadResult_BAD_LEXATOM;
    }
    else if( me->input.lexatom_index_begin == 0 ) {
        return E_LoadResult_NO_MORE_DATA; /* Begin of stream.                */
    }
    else if( ! me->filler || ! me->filler->byte_loader ) {
        return E_LoadResult_NO_MORE_DATA; /* No filler/loader => no loading! */
    }
    else if( ! QUEX_NAME(ByteLoader_seek_is_enabled)(me->filler->byte_loader) ) {
        return E_LoadResult_NO_MORE_DATA; /* Stream cannot go backwards.     */
    }

    move_distance = QUEX_NAME(Buffer_move_away_upfront_content)(me);

    if( ! move_distance ) {
        return E_LoadResult_NO_SPACE_FOR_LOAD; /* Cannot be further back.    */
    }

    /* Load new content.                                                     */
    loaded_n = QUEX_NAME(LexatomLoader_load)(me->filler, 
                                             BeginP, move_distance,
                                             me->input.lexatom_index_begin, 
                                             &end_of_stream_f, &encoding_error_f);
    if( encoding_error_f ) {
        return E_LoadResult_BAD_LEXATOM;
    }

    if( loaded_n  != move_distance ) {
        /* Serious: previously loaded content could not be loaded again!     
         * => Buffer has now hole: 
         *    from BeginP[loaded_n] to Begin[move_distance]                 
         * The analysis can continue in forward direction, but not backwards.*/
        return E_LoadResult_FAILURE;     
    }

    __quex_debug_buffer_load(me, "BACKWARD(exit)\n");
    QUEX_BUFFER_ASSERT_CONSISTENCY(me);
    return E_LoadResult_DONE;     
}

QUEX_INLINE ptrdiff_t
QUEX_NAME(Buffer_move_forward)(QUEX_NAME(Buffer)* me, 
                               ptrdiff_t          move_distance)
/* Moves the entire (meaningful) content of the buffer by 'move_distance'
 * forward. It does NOT MODIFY any pointers about the buffer content!
 *
 *                                                               EndP
 *                                         |<---- move size ---->|
 *     Before:   | . . . . . . . . . . . . .x.x.x.x.x.x.x.x.x.x.x| 
 *               |<---- move distance -----|                     |
 *                  .----------------------'                     |
 *               .-'                            .----------------'
 *               |                     .-------'
 *     After:    |x.x.x.x.x.x.x.x.x.x.x| . . . . . . . . . . . . | 
 *               |<---- move_size ---->|
 *
 * The callback 'on_content_change()' informs the user that any pointer into
 * the buffer must now copy its pointed objects, because the pointers will 
 * become invalid.
 *
 * RETURNS: Number of lexatoms that have been moved.                       */
{
    QUEX_TYPE_LEXATOM* BeginP     = &me->_memory._front[1];
    const ptrdiff_t    FilledSize = me->input.end_p - BeginP;
    ptrdiff_t          move_size;

    me->on_content_change(BeginP, me->input.end_p);

    if( move_distance >= FilledSize ) {
        return 0;
    }

    move_size = FilledSize - move_distance;

    if( move_distance && move_size ) {
        __QUEX_STD_memmove((void*)BeginP, (void*)&BeginP[move_distance],
                           (size_t)move_size * sizeof(QUEX_TYPE_LEXATOM));
    }
    return move_size;
}

QUEX_INLINE ptrdiff_t
QUEX_NAME(Buffer_move_backward)(QUEX_NAME(Buffer)* me, 
                                ptrdiff_t          move_distance)
/* Moves content so that previous content may be filled into the buffer.
 *
 *          BeginP
 *            |<--- move size---->|                         
 *            |x.x.x.x.x.x.x.x.x.x| . . . . . . . . . . . . . . |
 *            |                   '--------------.               
 *            '------------.                      '-------------.
 *                          '---------------.                   |
 *            :------- move distance------->|                   |
 *            | . . . . . . . . . . . . . . |x.x.x.x.x.x.x.x.x.x| 
 *                               
 *
 * RETURNS: Number of lexatom that need to be filled into the gap.
 *                                                                           */
{
    QUEX_TYPE_LEXATOM*  BeginP      = &me->_memory._front[1];
    const ptrdiff_t     ContentSize = (ptrdiff_t)QUEX_NAME(Buffer_content_size)(me);
    ptrdiff_t           move_size;

    me->on_content_change(BeginP, me->input.end_p);

    if( move_distance > ContentSize ) {
        return ContentSize;
    }

    move_size = ContentSize - move_distance;

    if( move_distance && move_size ) {
        __QUEX_STD_memmove((void*)&BeginP[move_distance], BeginP, 
                           (size_t)move_size * sizeof(QUEX_TYPE_LEXATOM));
    }
    return (ptrdiff_t)move_distance;
}

QUEX_INLINE void
QUEX_NAME(Buffer_move_forward_undo)(QUEX_NAME(Buffer)* me,
                                    intmax_t           move_distance,
                                    ptrdiff_t          move_size)
/* Restore the buffer's raw memory to what it was before in the 'FORWARD' case. 
 * It is assumed that the buffer's parameters in
 *
 *                         me->input
 *
 * remained UNTOUCHED during the moving and loading of the caller function.
 * That is, they indicate the situation to be restored.                      */
{
    QUEX_TYPE_LEXATOM* BeginP      = &me->_memory._front[1];
    QUEX_TYPE_LEXATOM* EndP        = me->_memory._back;
    ptrdiff_t            load_request_n;
    ptrdiff_t            loaded_n;
    bool                 end_of_stream_f = false;
    bool                 encoding_error_f = false;

    /* Character with lexatom index 'MinCharacterIndexInBuffer' has
     * not been loaded. => Buffer must be setup as before.                   */
    if( move_size ) {
        __QUEX_STD_memmove((void*)&BeginP[move_distance], (void*)BeginP, 
                           (size_t)move_size * sizeof(QUEX_TYPE_LEXATOM));
        load_request_n = (ptrdiff_t)move_distance;
    }
    else {
        load_request_n = (me->input.end_p - BeginP);
    }
    __quex_assert(&BeginP[load_request_n] <= EndP);
    (void)EndP;
    loaded_n = QUEX_NAME(LexatomLoader_load)(me->filler, BeginP, load_request_n,
                                             me->input.lexatom_index_begin,
                                             &end_of_stream_f, &encoding_error_f);

    if( loaded_n != load_request_n ) {
        QUEX_ERROR_EXIT("Buffer filler failed to load content that has been loaded before.!");
    }
    else {
        /* Ensure, that the buffer limit code is restored.                   */
        *(me->input.end_p) = (QUEX_TYPE_LEXATOM)QUEX_SETTING_BUFFER_LIMIT_CODE;
    }
}

QUEX_INLINE void      
QUEX_NAME(Buffer_on_content_change_DEFAULT)(const QUEX_TYPE_LEXATOM* BeginP, 
                                            const QUEX_TYPE_LEXATOM* EndP)
{ (void)BeginP; (void)EndP; }

QUEX_INLINE void
QUEX_NAME(Buffer_on_overflow_DEFAULT)(QUEX_NAME(Buffer)* me, bool ForwardF)
{
    (void)me; (void)ForwardF;
#   ifdef QUEX_OPTION_INFORMATIVE_BUFFER_OVERFLOW_MESSAGE
    uint8_t                   utf8_encoded_str[512]; 
    char                      message[1024];
    char*                     it         = &message[0];
    const char*               MessageEnd = &message[1024];
    uint8_t*                  WEnd       = 0x0;
    uint8_t*                  witerator  = 0x0;
    QUEX_TYPE_LEXATOM*        End        = 0x0;
    const QUEX_TYPE_LEXATOM*  iterator   = 0x0;

    /* Print out the lexeme start, so that the user has a hint. */
    WEnd        = utf8_encoded_str + 512 - 7;
    witerator   = utf8_encoded_str; 
    End         = me->_memory._back; 
    iterator    = me->_lexeme_start_p; 

    QUEX_CONVERTER_STRING(QUEX_SETTING_CHARACTER_CODEC, utf8)(&iterator, End, &witerator, WEnd);

    /* No use of 'snprintf()' because not all systems seem to support it propperly. */
    it += __QUEX_STD_strlcpy(it, 
              "Distance between lexeme start and current pointer exceeds buffer size.\n"
              "(tried to load buffer",
              MessageEnd - it);
    it += __QUEX_STD_strlcpy(it, ForwardF ? "forward)" : "backward)",                   
                             MessageEnd - it);
    it += __QUEX_STD_strlcpy(it, "As a hint consider the beginning of the lexeme:\n[[", 
                             MessageEnd - it);
    it += __QUEX_STD_strlcpy(it, (char*)utf8_encoded_str, MessageEnd - it);
    it += __QUEX_STD_strlcpy(it, "]]\n", MessageEnd - it);

    QUEX_ERROR_EXIT(message);
#   else
    QUEX_ERROR_EXIT("Distance between lexeme start and current pointer exceeds buffer size.\n"
                    "(tried to load buffer forward). Please, compile with option\n\n"
                    "    QUEX_OPTION_INFORMATIVE_BUFFER_OVERFLOW_MESSAGE\n\n"
                    "in order to get a more informative output. Most likely, one of your patterns\n"
                    "eats more than you intended. Alternatively you might want to set the buffer\n"
                    "size to a greater value or use skippers (<skip: [ \\n\\t]> for example).\n");
#   endif /* QUEX_OPTION_INFORMATIVE_BUFFER_OVERFLOW_MESSAGE */
}

QUEX_NAMESPACE_MAIN_CLOSE

#include <quex/code_base/buffer/lexatoms/LexatomLoader.i>
#include <quex/code_base/buffer/Buffer_print.i>
#include <quex/code_base/buffer/Buffer_navigation.i>
#include <quex/code_base/buffer/Buffer_fill.i>
#include <quex/code_base/buffer/BufferMemory.i>

#endif /* __QUEX_INCLUDE_GUARD__BUFFER__BUFFER_I */


