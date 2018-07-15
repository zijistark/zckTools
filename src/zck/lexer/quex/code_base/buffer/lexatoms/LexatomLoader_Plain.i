/*  -*- C++ -*-  vim: set syntax=cpp: */
/* (C) 2008 Frank-Rene Schaefer*/
#ifndef  __QUEX_INCLUDE_GUARD__BUFFER__LEXATOMS__LEXATOM_LOADER_PLAIN_I
#define  __QUEX_INCLUDE_GUARD__BUFFER__LEXATOMS__LEXATOM_LOADER_PLAIN_I
/**/

#if ! defined (__QUEX_OPTION_PLAIN_C)
#   include <iostream> 
#   include <cerrno>
#   include <stdexcept>
#endif
#include <quex/code_base/definitions>
#include <quex/code_base/buffer/Buffer>
#include <quex/code_base/buffer/lexatoms/LexatomLoader>
#include <quex/code_base/MemoryManager>

QUEX_NAMESPACE_MAIN_OPEN

QUEX_INLINE void
QUEX_NAME(LexatomLoader_Plain_construct)(QUEX_NAME(LexatomLoader_Plain)*, QUEX_NAME(ByteLoader)* byte_loader);

QUEX_INLINE ptrdiff_t 
QUEX_NAME(LexatomLoader_Plain_stomach_byte_n)(QUEX_NAME(LexatomLoader)* alter_ego);

QUEX_INLINE void 
QUEX_NAME(LexatomLoader_Plain_stomach_clear)(QUEX_NAME(LexatomLoader)* alter_ego);

QUEX_INLINE void   
QUEX_NAME(LexatomLoader_Plain_destruct_self)(QUEX_NAME(LexatomLoader)* alter_ego);

QUEX_INLINE size_t 
QUEX_NAME(LexatomLoader_Plain_load_lexatoms)(QUEX_NAME(LexatomLoader)* alter_ego,
                                             QUEX_TYPE_LEXATOM*     RegionBeginP, 
                                             const size_t           N,
                                             bool*                  end_of_stream_f,
                                             bool*                  encoding_error_f);

QUEX_INLINE void 
QUEX_NAME(LexatomLoader_Plain_fill_prepare)(QUEX_NAME(LexatomLoader)*  alter_ego,
                                            QUEX_NAME(Buffer)*         buffer,
                                            void**                     begin_p,
                                            const void**               end_p);

QUEX_INLINE ptrdiff_t 
QUEX_NAME(LexatomLoader_Plain_fill_finish)(QUEX_NAME(LexatomLoader)*  alter_ego,
                                           QUEX_TYPE_LEXATOM*         insertion_p,
                                           const QUEX_TYPE_LEXATOM*   BufferEnd,
                                           const void*                ContentEnd);

QUEX_INLINE void 
QUEX_NAME(LexatomLoader_Plain_get_fill_boundaries)(QUEX_NAME(LexatomLoader)* alter_ego,
                                                   QUEX_NAME(Buffer)*        buffer,
                                                   void**                    begin_p, 
                                                   const void**              end_p);

QUEX_INLINE void 
QUEX_NAME(LexatomLoader_Plain_print_this)(QUEX_NAME(LexatomLoader)* alter_ego);

QUEX_INLINE QUEX_NAME(LexatomLoader)*
QUEX_NAME(LexatomLoader_Plain_new)(QUEX_NAME(ByteLoader)* byte_loader)
{
    QUEX_NAME(LexatomLoader_Plain)*  me = \
         (QUEX_NAME(LexatomLoader_Plain)*) \
          QUEXED(MemoryManager_allocate)(sizeof(QUEX_NAME(LexatomLoader_Plain)),
                                         E_MemoryObjectType_BUFFER_FILLER);
    if( ! me ) {
        return (QUEX_NAME(LexatomLoader*))0;
    }
    /* __quex_assert(byte_loader); not for manual filling. */

    QUEX_NAME(LexatomLoader_Plain_construct)(me, byte_loader);

    return &me->base;
}

QUEX_INLINE void
QUEX_NAME(LexatomLoader_Plain_construct)(QUEX_NAME(LexatomLoader_Plain)* me, 
                                         QUEX_NAME(ByteLoader)*          byte_loader)
{
    /* A linear relationship between stream position and lexatom index 
     * requires that the input stream is in 'binary mode'. That is, the 
     * stream position is proportional to the number of bytes that lie 
     * behind.                                                               */
    ptrdiff_t   byte_n_per_lexatom = byte_loader && byte_loader->binary_mode_f ? 
                                       (ptrdiff_t)sizeof(QUEX_TYPE_LEXATOM) : -1;
    QUEX_NAME(LexatomLoader_setup)(&me->base,
                                   QUEX_NAME(LexatomLoader_Plain_load_lexatoms),
                                   QUEX_NAME(LexatomLoader_Plain_stomach_byte_n),
                                   QUEX_NAME(LexatomLoader_Plain_stomach_clear),
                                   QUEX_NAME(LexatomLoader_Plain_destruct_self), 
                                   QUEX_NAME(LexatomLoader_Plain_fill_prepare), 
                                   QUEX_NAME(LexatomLoader_Plain_fill_finish), 
                                   QUEX_NAME(LexatomLoader_Plain_get_fill_boundaries),
                                   QUEX_NAME(LexatomLoader_Plain_print_this),
                                   byte_loader,
                                   byte_n_per_lexatom);
}

QUEX_INLINE ptrdiff_t 
QUEX_NAME(LexatomLoader_Plain_stomach_byte_n)(QUEX_NAME(LexatomLoader)* alter_ego) 
{
    (void)alter_ego;
    return (ptrdiff_t)0;
}

QUEX_INLINE void 
QUEX_NAME(LexatomLoader_Plain_stomach_clear)(QUEX_NAME(LexatomLoader)* alter_ego) 
{
    (void)alter_ego;
}

QUEX_INLINE void 
QUEX_NAME(LexatomLoader_Plain_destruct_self)(QUEX_NAME(LexatomLoader)* alter_ego) 
/* destruct_self: Free resources occupied by 'me' BUT NOT 'myself'.
 * delete_self:   Free resources occupied by 'me' AND 'myself'.              */
{
    (void)alter_ego;
    /* There is nothing allocated by a LexatomLoader_Plain. 
     * Nothing to do.                                                        */
}

QUEX_INLINE size_t   
QUEX_NAME(LexatomLoader_Plain_load_lexatoms)(QUEX_NAME(LexatomLoader)*  alter_ego,
                                             QUEX_TYPE_LEXATOM*         RegionBeginP, 
                                             const size_t               N,
                                             bool*                      end_of_stream_f,  
                                             bool*                      encoding_error_f)
/* Loads content into a region of memory. Does NOT effect any of the buffer's
 * variables. 
 *
 * RETURNS: Number of loaded lexatoms into the given region.               */
{ 
    QUEX_NAME(LexatomLoader_Plain)* me = (QUEX_NAME(LexatomLoader_Plain)*)alter_ego;
    size_t                          loaded_byte_n = (size_t)-1;
    size_t                          loaded_n;
    (void)encoding_error_f;

    __quex_assert(0 != alter_ego); 
    __quex_assert(0 != RegionBeginP); 
    __quex_assert(0 != me->base.byte_loader); 
    /* NOT: QUEX_IF_ASSERTS_poison(RegionBeginP, &RegionBeginP[N]);
     * The buffer must remain intact, in case that not all is loaded.        */
    loaded_byte_n = me->base.byte_loader->load(me->base.byte_loader, 
                                               RegionBeginP, 
                                               N * sizeof(QUEX_TYPE_LEXATOM),
                                               end_of_stream_f);

    if( loaded_byte_n % sizeof(QUEX_TYPE_LEXATOM) ) {
        __QUEX_STD_printf("Error: End of file cuts in the middle of a multi-byte character.");
    }
    loaded_n = loaded_byte_n / sizeof(QUEX_TYPE_LEXATOM);

    return loaded_n;
}

QUEX_INLINE void 
QUEX_NAME(LexatomLoader_Plain_fill_prepare)(QUEX_NAME(LexatomLoader)* alter_ego,
                                            QUEX_NAME(Buffer)*        buffer,
                                            void**                    begin_p,
                                            const void**              end_p)
{
    /* Move-away of passed content in engine's buffer is done by caller. */
    alter_ego->derived.get_fill_boundaries(alter_ego, buffer, begin_p, end_p);
}

QUEX_INLINE void 
QUEX_NAME(LexatomLoader_Plain_get_fill_boundaries)(QUEX_NAME(LexatomLoader)* alter_ego,
                                                   QUEX_NAME(Buffer)*        buffer,
                                                   void**                    begin_p, 
                                                   const void**              end_p)
{
    (void)alter_ego;

    *begin_p = (void*)buffer->input.end_p;
    *end_p   = (void*)buffer->_memory._back; 
}

QUEX_INLINE ptrdiff_t 
QUEX_NAME(LexatomLoader_Plain_fill_finish)(QUEX_NAME(LexatomLoader)*  alter_ego,
                                           QUEX_TYPE_LEXATOM*         insertion_p,
                                           const QUEX_TYPE_LEXATOM*   BufferEnd,
                                           const void*                FilledEndP_raw)
{
    const QUEX_TYPE_LEXATOM*  FilledEndP = (const QUEX_TYPE_LEXATOM*)FilledEndP_raw;
    (void)alter_ego;
    (void)BufferEnd;

    __quex_assert(FilledEndP >= insertion_p);
    __quex_assert(FilledEndP <= BufferEnd);
    /* Assert triggers => FilledEndP points WRONGLY BEHIND terminating zero. 
     * (FilledEndP, may point to it, at max.)                                */
    __quex_assert(   FilledEndP     <= insertion_p 
                  || FilledEndP[-1] != QUEX_SETTING_BUFFER_LIMIT_CODE);

    /* Copying of content is done, already, by caller.                       */
    /* Inserted number of lexatoms = End - Begin.                            */
    return (ptrdiff_t)(FilledEndP - insertion_p);
}

QUEX_INLINE void 
QUEX_NAME(LexatomLoader_Plain_print_this)(QUEX_NAME(LexatomLoader)* alter_ego)
{
    (void)alter_ego;
    __QUEX_STD_printf("      type:                           plain;\n");
}

QUEX_NAMESPACE_MAIN_CLOSE

#include <quex/code_base/buffer/lexatoms/LexatomLoader.i>

#endif /* __INCLUDE_GUARD__QUEX_BUFFER_INPUT_STRATEGY_PLAIN_I__ */
