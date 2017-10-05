/* -*- C++ -*-  vim: set syntax=cpp:
 * (C) 2007-2008 Frank-Rene Schaefer  */
#ifndef  __QUEX_INCLUDE_GUARD__BUFFER__LEXATOMS__CONVERTER__ICONV__CONVERTER_ICONV_I
#define  __QUEX_INCLUDE_GUARD__BUFFER__LEXATOMS__CONVERTER__ICONV__CONVERTER_ICONV_I

#ifndef __QUEX_OPTION_PLAIN_C
extern "C" { 
#endif
#include <errno.h>
#ifndef __QUEX_OPTION_PLAIN_C
}
#endif
#include <quex/code_base/definitions>
#include <quex/code_base/compatibility/iconv-argument-types.h>
#include <quex/code_base/MemoryManager>
#include <quex/code_base/buffer/lexatoms/converter/iconv/Converter_IConv>

#include <quex/code_base/analyzer/configuration/validation>

QUEX_NAMESPACE_MAIN_OPEN

QUEX_INLINE bool 
QUEX_NAME(Converter_IConv_initialize)(QUEX_NAME(Converter)* me,
                                const char* FromCodec, const char* ToCodec);

QUEX_INLINE bool    
QUEX_NAME(Converter_IConv_initialize_by_bom_id)(struct QUEX_NAME(Converter_tag)* me,
                                                QUEX_TYPE_BOM                    BomId);

QUEX_INLINE E_LoadResult 
QUEX_NAME(Converter_IConv_convert)(QUEX_NAME(Converter)*     me, 
                                   uint8_t**                 source, 
                                   const uint8_t*            SourceEnd,
                                   QUEX_TYPE_LEXATOM**       drain,  
                                   const QUEX_TYPE_LEXATOM*  DrainEnd);
QUEX_INLINE void 
QUEX_NAME(Converter_IConv_delete_self)(QUEX_NAME(Converter)* me);

QUEX_INLINE ptrdiff_t 
QUEX_NAME(Converter_IConv_stomach_byte_n)(QUEX_NAME(Converter)* me);

QUEX_INLINE void 
QUEX_NAME(Converter_IConv_stomach_clear)(QUEX_NAME(Converter)* me);

QUEX_INLINE void 
QUEX_NAME(Converter_IConv_print_this)(QUEX_NAME(Converter)* me);

QUEX_INLINE QUEX_NAME(Converter)*
QUEX_NAME(Converter_IConv_new)(const char* FromCodec, const char* ToCodec)
{
    QUEX_NAME(Converter_IConv)*  me = \
       (QUEX_NAME(Converter_IConv)*)
       QUEXED(MemoryManager_allocate)(sizeof(QUEX_NAME(Converter_IConv)),
                                      E_MemoryObjectType_CONVERTER);
    if( ! me ) {
        return (QUEX_NAME(Converter)*)0;
    }

    me->handle = (iconv_t)-1;
    if( ! QUEX_NAME(Converter_construct)(&me->base,
                                         FromCodec, ToCodec,
                                         QUEX_NAME(Converter_IConv_initialize),
                                         QUEX_NAME(Converter_IConv_initialize_by_bom_id),
                                         QUEX_NAME(Converter_IConv_convert),
                                         QUEX_NAME(Converter_IConv_delete_self),
                                         QUEX_NAME(Converter_IConv_stomach_byte_n),
                                         QUEX_NAME(Converter_IConv_stomach_clear),
                                         QUEX_NAME(Converter_IConv_print_this)) ) {
        QUEXED(MemoryManager_free)((void*)me, E_MemoryObjectType_CONVERTER);
        return (QUEX_NAME(Converter)*)0;
    }

    return &me->base;
}

QUEX_INLINE bool 
QUEX_NAME(Converter_IConv_initialize)(QUEX_NAME(Converter)* alter_ego,
                                      const char*           FromCodec, 
                                      const char*           ToCodec)
/* Initializes the converter, or in case that 'FromCodec == 0', it marks
 * the object as 'not-initialized'. 'Converter_IConv_initialize_by_bom_id()'
 * will act upon that information.  
 *
 * RETURNS: true, if success. false, else.                                    */
{
    QUEX_NAME(Converter_IConv)* me = (QUEX_NAME(Converter_IConv)*)alter_ego;

    if( ! FromCodec ) {
        me->handle = (iconv_t)-1;               /* mark 'not-initialized'.    */
        return true;                            /* still, nothing went wrong. */
    }
#   if   defined(QUEX_OPTION_ENDIAN_LITTLE)
    const bool little_endian_f = true;
#   elif defined(QUEX_OPTION_ENDIAN_BIG)
    const bool little_endian_f = false;
#   elif defined(QUEX_OPTION_ENDIAN_SYSTEM) 
    const bool little_endian_f = QUEXED(system_is_little_endian)();
#   endif

    /* Setup conversion handle */
    if( ! ToCodec ) {
        switch( sizeof(QUEX_TYPE_LEXATOM) ) {
        case 4:  ToCodec = little_endian_f ? "UCS-4LE" : "UCS-4BE"; break;
        case 2:  ToCodec = little_endian_f ? "UCS-2LE" : "UCS-2BE"; break;
        case 1:  ToCodec = "ASCII"; break;
        default:  __quex_assert(false); return false;
        }
    } 
    me->handle = iconv_open(ToCodec, FromCodec);
    if( me->handle == (iconv_t)-1 ) return false;
    
    /* ByteN / Character:
     * IConv does not provide something like 'isFixedWidth()'. So, the 
     * safe assumption "byte_n/lexatom != const" is made, except for some
     * well-known examples.                                              */
    me->base.byte_n_per_lexatom = -1;
    if(    __QUEX_STD_strcmp(FromCodec, "UCS-4LE") == 0 
        || __QUEX_STD_strcmp(FromCodec, "UCS-4BE")  == 0) {
        me->base.byte_n_per_lexatom   = 4;
        me->base.input_code_unit_size = 4;
    }
    else if(   __QUEX_STD_strcmp(FromCodec, "UCS-2LE") == 0 
            || __QUEX_STD_strcmp(FromCodec, "UCS-2BE")  == 0) {
        me->base.byte_n_per_lexatom   = 2;
        me->base.input_code_unit_size = 2;
    }
    else if( __QUEX_STD_strcmp(FromCodec, "UTF16") == 0 ) {
        me->base.byte_n_per_lexatom   = -1;
        me->base.input_code_unit_size = 2;
    }
    else if( __QUEX_STD_strcmp(FromCodec, "UTF8") == 0 ) {
        me->base.byte_n_per_lexatom   = -1;
        me->base.input_code_unit_size = 1;
    }

    return true;
}

QUEX_INLINE bool    
QUEX_NAME(Converter_IConv_initialize_by_bom_id)(QUEX_NAME(Converter)* alter_ego,
                                                QUEX_TYPE_BOM         BomId)
{
    QUEX_NAME(Converter_IConv)* me = (QUEX_NAME(Converter_IConv)*)alter_ego;
    const char* name;

    if( me->handle != (iconv_t)-1 ) {
        iconv_close(me->handle); 
    }

    switch( BomId ) {
    case QUEX_BOM_UTF_8:           name = "UTF-8"; break;                      
    case QUEX_BOM_UTF_1:           name = "UTF-1"; break;                      
    case QUEX_BOM_UTF_EBCDIC:      return false; /* name = "UTF_EBCDIC"; break; */
    case QUEX_BOM_BOCU_1:          return false; /* name = "BOCU_1"; break;     */
    case QUEX_BOM_GB_18030:        name = "GB18030"; break;                
    case QUEX_BOM_UTF_7:           name = "UTF-7"; break;                      
    case QUEX_BOM_UTF_16:          name = "UTF-16"; break;                                  
    case QUEX_BOM_UTF_16_LE:       name = "UTF-16LE"; break;              
    case QUEX_BOM_UTF_16_BE:       name = "UTF-16BE"; break;              
    case QUEX_BOM_UTF_32:          name = "UTF-32"; break;                    
    case QUEX_BOM_UTF_32_LE:       name = "UTF-32LE"; break;              
    case QUEX_BOM_UTF_32_BE:       name = "UTF-32BE"; break;              
    case QUEX_BOM_SCSU:            /* not supported. */
    case QUEX_BOM_SCSU_TO_UCS:     /* not supported. */
    case QUEX_BOM_SCSU_W0_TO_FE80: /* not supported. */
    case QUEX_BOM_SCSU_W1_TO_FE80: /* not supported. */
    case QUEX_BOM_SCSU_W2_TO_FE80: /* not supported. */
    case QUEX_BOM_SCSU_W3_TO_FE80: /* not supported. */
    case QUEX_BOM_SCSU_W4_TO_FE80: /* not supported. */
    case QUEX_BOM_SCSU_W5_TO_FE80: /* not supported. */
    case QUEX_BOM_SCSU_W6_TO_FE80: /* not supported. */
    case QUEX_BOM_SCSU_W7_TO_FE80: /* not supported. */
    default:
    case QUEX_BOM_NONE:            return false;
    }

    return me->base.initialize(alter_ego, name, NULL);
}

QUEX_INLINE E_LoadResult 
QUEX_NAME(Converter_IConv_convert)(QUEX_NAME(Converter)*  alter_ego, 
                                   uint8_t**              source, const uint8_t*              SourceEnd,
                                   QUEX_TYPE_LEXATOM**  drain,  const QUEX_TYPE_LEXATOM*  DrainEnd)
/* RETURNS:  true  --> User buffer is filled as much as possible with 
 *                     converted lexatoms.
 *           false --> More raw bytes are needed to fill the user buffer.           
 *
 *  IF YOU GET A COMPILE ERROR HERE, THEN PLEASE HAVE A LOOK AT THE FILE:
 *
 *      quex/code_base/compatibility/iconv-argument-types.h
 * 
 *  'iconv' is defined on different systems with different
 *  types of the second argument. There are two variants 'const char**'
 *  and 'char **'.  If you get an error here, consider defining 
 *
 *            -DQUEX_SETTING_ICONV_2ND_ARG_CONST_CHARPP
 *
 *  as a compile option. If you know of an elegant solution to solve the 
 *  problem for plain 'C', then please, let me know 
 *  <fschaef@users.sourceforge.net>.                                     */
{
    QUEX_NAME(Converter_IConv)* me                  = (QUEX_NAME(Converter_IConv)*)alter_ego;
    size_t                      source_bytes_left_n = (size_t)(SourceEnd - *source);
    size_t                      drain_bytes_left_n  = (size_t)(DrainEnd - *drain)*sizeof(QUEX_TYPE_LEXATOM);
    size_t                      report;
    
    /* Avoid strange error reports from 'iconv' in case that the source 
     * buffer is empty.                                                  */
    report = iconv(me->handle, 
                   __QUEX_ADAPTER_ICONV_2ND_ARG(source), &source_bytes_left_n,
                   (char**)drain,                        &drain_bytes_left_n);

    if( report != (size_t)-1 ) { 
        /* No Error => Raw buffer COMPLETELY converted.                      */
        __quex_assert(! source_bytes_left_n);
        return drain_bytes_left_n ? E_LoadResult_INCOMPLETE 
                                  : E_LoadResult_COMPLETE;
    }

    switch( errno ) {
    default:
        QUEX_ERROR_EXIT("Unexpected setting of 'errno' after call to GNU's iconv().");

    case EILSEQ:
        return E_LoadResult_BAD_LEXATOM;

    case EINVAL:
        /* Incomplete byte sequence for lexatom conversion.
         * => '*source' points to the beginning of the incomplete sequence.
         * => If drain is not filled, then new source content must be 
         *    provided.                                                      */
        return drain_bytes_left_n ? E_LoadResult_INCOMPLETE 
                                  : E_LoadResult_COMPLETE;

    case E2BIG:
        /* The input buffer was not able to hold the number of converted 
         * lexatoms. => Drain is filled to the limit.                        */
        return E_LoadResult_COMPLETE;
    }
}

QUEX_INLINE ptrdiff_t 
QUEX_NAME(Converter_IConv_stomach_byte_n)(QUEX_NAME(Converter)* me)
{ (void)me; return 0; }

QUEX_INLINE void 
QUEX_NAME(Converter_IConv_stomach_clear)(QUEX_NAME(Converter)* me)
{ (void)me; }

QUEX_INLINE void 
QUEX_NAME(Converter_IConv_delete_self)(QUEX_NAME(Converter)* alter_ego)
{
    QUEX_NAME(Converter_IConv)* me = (QUEX_NAME(Converter_IConv)*)alter_ego;

    iconv_close(me->handle); 
    QUEXED(MemoryManager_free)((void*)me, E_MemoryObjectType_CONVERTER);
}

QUEX_INLINE void 
QUEX_NAME(Converter_IConv_print_this)(QUEX_NAME(Converter)* alter_ego)
{
    QUEX_NAME(Converter_IConv)* me = (QUEX_NAME(Converter_IConv)*)alter_ego;

    __QUEX_STD_printf("        type:                 IConv, GNU;\n");
    __QUEX_STD_printf("        handle:               ((%p));\n", (const void*)(me->handle));
}

QUEX_NAMESPACE_MAIN_CLOSE


#endif /*  __QUEX_INCLUDE_GUARD__BUFFER__LEXATOMS__CONVERTER__ICONV__CONVERTER_ICONV_I */
