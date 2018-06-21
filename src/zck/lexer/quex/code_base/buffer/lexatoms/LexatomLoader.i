/* -*- C++ -*- vim: set syntax=cpp: */
#ifndef  __QUEX_INCLUDE_GUARD__BUFFER__LEXATOMS__LEXATOM_LOADER_I
#define  __QUEX_INCLUDE_GUARD__BUFFER__LEXATOMS__LEXATOM_LOADER_I

#include <quex/code_base/definitions>
#include <quex/code_base/buffer/Buffer>
#include <quex/code_base/MemoryManager>
#include <quex/code_base/buffer/lexatoms/LexatomLoader>
#include <quex/code_base/buffer/Buffer_print>

QUEX_NAMESPACE_MAIN_OPEN

QUEX_INLINE bool       QUEX_NAME(LexatomLoader_ByteLoader_Converter_consistency)(QUEX_NAME(ByteLoader)*  byte_loader, 
                                                                                 QUEX_NAME(Converter)*   converter);
QUEX_INLINE bool       QUEX_NAME(LexatomLoader_lexatom_index_seek)(QUEX_NAME(LexatomLoader)*         me, 
                                                                    const QUEX_TYPE_STREAM_POSITION  LexatomIndex);
QUEX_INLINE QUEX_TYPE_STREAM_POSITION 
                       QUEX_NAME(LexatomLoader_lexatom_index_tell)(QUEX_NAME(LexatomLoader)* me);
QUEX_INLINE bool       QUEX_NAME(LexatomLoader_lexatom_index_step_to)(QUEX_NAME(LexatomLoader)*        me,
                                                                      const QUEX_TYPE_STREAM_POSITION TargetCI);
QUEX_INLINE void       QUEX_NAME(LexatomLoader_reverse_byte_order)(QUEX_TYPE_LEXATOM*       Begin, 
                                                                  const QUEX_TYPE_LEXATOM* End);

QUEX_INLINE void       QUEX_NAME(LexatomLoader_delete_self)(QUEX_NAME(LexatomLoader)*); 

                       
QUEX_INLINE QUEX_NAME(LexatomLoader)*
QUEX_NAME(LexatomLoader_new)(QUEX_NAME(ByteLoader)*  byte_loader, 
                             QUEX_NAME(Converter)*   converter)
{
    QUEX_NAME(LexatomLoader)* filler;

    /* byte_loader = 0; possible if memory is filled manually.               */
    if( converter ) {
        if( ! QUEX_NAME(LexatomLoader_ByteLoader_Converter_consistency)(byte_loader, converter) ) {
            return (QUEX_NAME(LexatomLoader)*)0;
        }
        filler = QUEX_NAME(LexatomLoader_Converter_new)(byte_loader, converter);
    }
    else {
        filler = QUEX_NAME(LexatomLoader_Plain_new)(byte_loader); 
    }
    
    return filler;
}

QUEX_INLINE bool
QUEX_NAME(LexatomLoader_ByteLoader_Converter_consistency)(QUEX_NAME(ByteLoader)*  byte_loader, 
                                                          QUEX_NAME(Converter)*   converter)
{
    if( ! byte_loader ) {
        return true;
    }
    else if( converter->input_code_unit_size == -1 ) {
        return true;
    }
    else if( converter->input_code_unit_size >= (int)byte_loader->element_size ) {
        return true;
    }
    else {
        __QUEX_STD_printf("Error: The specified byte loader provides elements of size %i.\n", 
                          (int)byte_loader->element_size);
        __QUEX_STD_printf("Error: The converter requires input elements of size <= %i.\n", 
                          (int)converter->input_code_unit_size);
        __QUEX_STD_printf("Error: This happens, for example, when using 'wistream' input\n"
                          "Error: without considering 'sizeof(wchar_t)' with respect to\n"
                          "Error: the encodings code unit's size. (UTF8=1byte, UTF16=2byte, etc.)\n");
        return false;
    }
}

QUEX_INLINE void       
QUEX_NAME(LexatomLoader_delete_self)(QUEX_NAME(LexatomLoader)* me)
{ 
    if( ! me ) return;

    if( me->byte_loader ) {
        QUEX_NAME(ByteLoader_delete)(&me->byte_loader);
    }

    /* destruct_self: Free resources occupied by 'me' BUT NOT 'myself'.
     * delete_self:   Free resources occupied by 'me' AND 'myself'.           */
    if( me->derived.destruct_self ) {
        me->derived.destruct_self(me);
    }

    QUEXED(MemoryManager_free)((void*)me, E_MemoryObjectType_BUFFER_FILLER);
}

QUEX_INLINE void    
QUEX_NAME(LexatomLoader_setup)(QUEX_NAME(LexatomLoader)*   me,
                               size_t       (*derived_load_lexatoms)(QUEX_NAME(LexatomLoader)*,
                                                                     QUEX_TYPE_LEXATOM*, 
                                                                     const size_t, 
                                                                     bool*, bool*),
                               ptrdiff_t    (*stomach_byte_n)(QUEX_NAME(LexatomLoader)*),
                               void         (*stomach_clear)(QUEX_NAME(LexatomLoader)*),
                               void         (*derived_destruct_self)(QUEX_NAME(LexatomLoader)*),
                               void         (*derived_fill_prepare)(QUEX_NAME(LexatomLoader)*  me,
                                                                    QUEX_NAME(Buffer)*         buffer,
                                                                    void**                     begin_p,
                                                                    const void**               end_p),
                               ptrdiff_t    (*derived_fill_finish)(QUEX_NAME(LexatomLoader)* me,
                                                                   QUEX_TYPE_LEXATOM*        BeginP,
                                                                   const QUEX_TYPE_LEXATOM*  EndP,
                                                                   const void*               FilledEndP),
                               void         (*derived_get_fill_boundaries)(QUEX_NAME(LexatomLoader)*  alter_ego,
                                                                           QUEX_NAME(Buffer)*         buffer,
                                                                           void**                     begin_p, 
                                                                           const void**               end_p),
                               void         (*derived_print_this)(QUEX_NAME(LexatomLoader)*  alter_ego),
                               QUEX_NAME(ByteLoader)*  byte_loader,
                               ptrdiff_t    ByteNPerCharacter)
{
    __quex_assert(me);
    __quex_assert(derived_load_lexatoms);
    __quex_assert(derived_destruct_self);

    /* Support for buffer filling without user interaction                   */
    me->stomach_byte_n        = stomach_byte_n;
    me->stomach_clear         = stomach_clear;
    me->input_lexatom_tell    = QUEX_NAME(LexatomLoader_lexatom_index_tell);
    me->input_lexatom_seek    = QUEX_NAME(LexatomLoader_lexatom_index_seek);
    me->derived.load_lexatoms = derived_load_lexatoms;
    me->derived.destruct_self = derived_destruct_self;
    me->derived.print_this    = derived_print_this;
    me->delete_self           = QUEX_NAME(LexatomLoader_delete_self);

    /* Support for manual buffer filling.                                    */
    me->derived.fill_prepare        = derived_fill_prepare;
    me->derived.fill_finish         = derived_fill_finish;
    me->derived.get_fill_boundaries = derived_get_fill_boundaries;

    me->byte_loader                 = byte_loader;

    me->_byte_order_reversion_active_f = false;
    me->lexatom_index_next_to_fill   = 0;
    me->byte_n_per_lexatom           = ByteNPerCharacter;
}

QUEX_INLINE ptrdiff_t       
QUEX_NAME(LexatomLoader_load)(QUEX_NAME(LexatomLoader)*  me, 
                              QUEX_TYPE_LEXATOM*         LoadP, 
                              const ptrdiff_t            LoadN,
                              QUEX_TYPE_STREAM_POSITION  StartLexatomIndex,
                              bool*                      end_of_stream_f,
                              bool*                      encoding_error_f)
/* Seeks the input position StartLexatomIndex and loads 'LoadN' 
 * lexatoms into the engine's buffer starting from 'LoadP'.
 *
 * RETURNS: Number of loaded lexatoms.                                     */
{
    ptrdiff_t                loaded_n;

    /* (1) Seek to the position where loading shall start.                       
     *                                                                       */
    if( ! me->input_lexatom_seek(me, StartLexatomIndex) ) {
        return 0;
    }
    __quex_assert(me->lexatom_index_next_to_fill == StartLexatomIndex);

    /* (2) Load content into the given region.                                   
     *                                                                       */
    loaded_n = (ptrdiff_t)me->derived.load_lexatoms(me, LoadP, (size_t)LoadN,
                                                    end_of_stream_f, encoding_error_f);
#   ifdef QUEX_OPTION_ON_LOAD_DETECT_BUFFER_LIMIT_CODE_IN_CONTENT
    {
        const QUEX_TYPE_LEXATOM* p;
        /* The buffer limit code is not to appear inside the loaded content. */
        for(p=LoadP; p != &LoadP[loaded_n]; ++p) {
            __quex_assert(*p != QUEX_SETTING_BUFFER_LIMIT_CODE);
        }
    }
#   endif

    __quex_assert(loaded_n <= LoadN);
    me->lexatom_index_next_to_fill += loaded_n;

    /* (3) Optionally reverse the byte order.                                    
     *                                                                       */
    if( me->_byte_order_reversion_active_f ) {
        QUEX_NAME(LexatomLoader_reverse_byte_order)(LoadP, &LoadP[loaded_n]);
    }

    return loaded_n;
}


QUEX_INLINE void
QUEX_NAME(LexatomLoader_reverse_byte_order)(QUEX_TYPE_LEXATOM*       Begin, 
                                           const QUEX_TYPE_LEXATOM* End)
{
    uint8_t              tmp = 0xFF;
    QUEX_TYPE_LEXATOM* iterator = 0x0;

    switch( sizeof(QUEX_TYPE_LEXATOM) ) {
    default:
        __quex_assert(false);
        break;
    case 1:
        /* Nothing to be done */
        break;
    case 2:
        for(iterator=Begin; iterator != End; ++iterator) {
            tmp = *(((uint8_t*)iterator) + 0);
            *(((uint8_t*)iterator) + 0) = *(((uint8_t*)iterator) + 1);
            *(((uint8_t*)iterator) + 1) = tmp;
        }
        break;
    case 4:
        for(iterator=Begin; iterator != End; ++iterator) {
            tmp = *(((uint8_t*)iterator) + 0);
            *(((uint8_t*)iterator) + 0) = *(((uint8_t*)iterator) + 3);
            *(((uint8_t*)iterator) + 3) = tmp;
            tmp = *(((uint8_t*)iterator) + 1);
            *(((uint8_t*)iterator) + 1) = *(((uint8_t*)iterator) + 2);
            *(((uint8_t*)iterator) + 2) = tmp;
        }
        break;
    }
}

QUEX_INLINE void       
QUEX_NAME(LexatomLoader_print_this)(QUEX_NAME(LexatomLoader)* me)
{
    __QUEX_STD_printf("    filler: {\n");
    if( ! me ) {
        __QUEX_STD_printf("      type: <none>\n");
    }
    else {
        __QUEX_STD_printf("      lexatom_index_next_to_fill:     %i;\n", 
                          (int)me->lexatom_index_next_to_fill);
        __QUEX_STD_printf("      byte_n_per_lexatom:             %i;\n", 
                          (int)me->byte_n_per_lexatom);
        __QUEX_STD_printf("      _byte_order_reversion_active_f: %s;\n", 
                          E_Boolean_NAME(me->_byte_order_reversion_active_f)); 
        /* me->byte_loader->print_this(me->byte_loader); */
        if( me->derived.print_this ) me->derived.print_this(me);
        if( ! me->byte_loader ) {
            __QUEX_STD_printf("      byte_loader: <none>\n");
        }
        else {
            if( me->byte_loader->print_this ) me->byte_loader->print_this(me->byte_loader); 
        }
    }
    __QUEX_STD_printf("    }\n");
}

QUEX_NAMESPACE_MAIN_CLOSE

#include <quex/code_base/buffer/Buffer.i>
#include <quex/code_base/buffer/bytes/ByteLoader.i>
#include <quex/code_base/buffer/lexatoms/LexatomLoader_navigation.i>
#include <quex/code_base/buffer/lexatoms/LexatomLoader_Converter.i>
#include <quex/code_base/buffer/lexatoms/LexatomLoader_Plain.i>

#endif /* __QUEX_INCLUDE_GUARD__BUFFER__BUFFERFILLER_I */

