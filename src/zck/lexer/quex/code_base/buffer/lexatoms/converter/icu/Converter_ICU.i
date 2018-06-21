/* -*- C++ -*-  vim: set syntax=cpp:
 * (C) 2007-2008 Frank-Rene Schaefer  */
#ifndef  __QUEX_INCLUDE_GUARD__BUFFER__LEXATOMS__CONVERTER__ICU__CONVERTER_ICU_I
#define  __QUEX_INCLUDE_GUARD__BUFFER__LEXATOMS__CONVERTER__ICU__CONVERTER_ICU_I

#include <quex/code_base/definitions>
#include <quex/code_base/compatibility/stdint.h>
#include <quex/code_base/MemoryManager>
#include <quex/code_base/buffer/lexatoms/converter/icu/Converter_ICU>

#include <quex/code_base/analyzer/configuration/validation>

QUEX_NAMESPACE_MAIN_OPEN

QUEX_INLINE bool
QUEX_NAME(Converter_ICU_initialize)(QUEX_NAME(Converter)* me, 
                                    const char*           FromCoding, 
                                    const char*           ToCoding);
QUEX_INLINE bool    
QUEX_NAME(Converter_ICU_initialize_by_bom_id)(QUEX_NAME(Converter)* me,
                                              QUEX_TYPE_BOM         BomId);

QUEX_INLINE E_LoadResult
QUEX_NAME(Converter_ICU_convert)(QUEX_NAME(Converter)*       me, 
                                 uint8_t**                   source, 
                                 const uint8_t*              SourceEnd, 
                                 QUEX_TYPE_LEXATOM**       drain,  
                                 const QUEX_TYPE_LEXATOM*  DrainEnd);
QUEX_INLINE void
QUEX_NAME(Converter_ICU_delete_self)(QUEX_NAME(Converter)* me);

QUEX_INLINE ptrdiff_t 
QUEX_NAME(Converter_ICU_stomach_byte_n)(QUEX_NAME(Converter)* me);

QUEX_INLINE void 
QUEX_NAME(Converter_ICU_stomach_clear)(QUEX_NAME(Converter)* me);

QUEX_INLINE void 
QUEX_NAME(Converter_ICU_print_this)(QUEX_NAME(Converter)* me);

QUEX_INLINE QUEX_NAME(Converter)*
QUEX_NAME(Converter_ICU_new)(const char* FromCoding, const char* ToCoding)
{
    QUEX_NAME(Converter_ICU)*  me = \
         (QUEX_NAME(Converter_ICU)*)QUEXED(MemoryManager_allocate)(sizeof(QUEX_NAME(Converter_ICU)),
                                                                   E_MemoryObjectType_CONVERTER);

    me->to_handle   = 0x0;
    me->from_handle = 0x0;
    me->status      = U_ZERO_ERROR;
    /* Setup the pivot buffer                                            */
    me->pivot.source = &me->pivot.buffer[0];
    me->pivot.target = &me->pivot.buffer[0];
    me->reset_upon_next_conversion_f = TRUE;

    if( ! QUEX_NAME(Converter_construct)(&me->base,
                                         FromCoding, ToCoding,
                                         QUEX_NAME(Converter_ICU_initialize),
                                         QUEX_NAME(Converter_ICU_initialize_by_bom_id),
                                         QUEX_NAME(Converter_ICU_convert),
                                         QUEX_NAME(Converter_ICU_delete_self),
                                         QUEX_NAME(Converter_ICU_stomach_byte_n),
                                         QUEX_NAME(Converter_ICU_stomach_clear),
                                         QUEX_NAME(Converter_ICU_print_this)) ) {
        QUEXED(MemoryManager_free)((void*)me, E_MemoryObjectType_CONVERTER);
        return (QUEX_NAME(Converter)*)0;
    }

    return &me->base;
}

QUEX_INLINE bool
QUEX_NAME(Converter_ICU_initialize)(QUEX_NAME(Converter)* alter_ego, 
                                    const char*           FromCoding, 
                                    const char*           ToCoding)
/* Initializes the converter, or in case that 'FromCodec == 0', it marks
 * the object as 'not-initialized'. 'Converter_IConv_initialize_by_bom_id()'
 * will act upon that information.  
 *
 * RETURNS: true, if success. false, else.                                    */
{
    QUEX_NAME(Converter_ICU)* me = (QUEX_NAME(Converter_ICU)*)alter_ego;
#   if   defined(QUEX_OPTION_ENDIAN_LITTLE)
    const bool little_endian_f = true;
#   elif defined(QUEX_OPTION_ENDIAN_BIG)
    const bool little_endian_f = false;
#   elif defined(QUEX_OPTION_ENDIAN_SYSTEM) 
    const bool little_endian_f = QUEXED(system_is_little_endian)();
#   endif
    me->from_handle = 0x0;
    me->to_handle   = 0x0; 
    if( ! FromCoding ) {
        /* me->from_handle = 0; mark as 'not-initialized'.                    */
        return true;                            /* still, nothing went wrong. */
        return true;
    }

    __quex_assert(me);

    /* Default: assume input encoding to have dynamic lexatom sizes.          */
    if( ucnv_compareNames(FromCoding, "UTF32") == 0 ) {
        FromCoding = "UTF32_PlatformEndian";
    }
    else if( ucnv_compareNames(FromCoding, "UTF16") == 0 ) {
        FromCoding = "UTF16_PlatformEndian";
    }

    /* Open conversion handles                                                */
    me->status      = U_ZERO_ERROR;
    me->from_handle = ucnv_open(FromCoding, &me->status);
    if( me->from_handle == NULL || ! U_SUCCESS(me->status) ) return false;

    if( ! U_SUCCESS(me->status) ) {
        return false;
    }

    /* ByteN / Character:                                               */
    if( ucnv_isFixedWidth(me->from_handle, &me->status) && U_SUCCESS(me->status) ) {
        me->base.byte_n_per_lexatom = ucnv_getMaxCharSize(me->from_handle);
    }
    else {
        me->base.byte_n_per_lexatom = -1;
    }
    if( __QUEX_STD_strcmp(FromCoding, "UTF16") == 0 ) {
        me->base.input_code_unit_size = 2;
    }
    else if( __QUEX_STD_strcmp(FromCoding, "UTF8") == 0 ) {
        me->base.input_code_unit_size = 1;
    }

    if( ! ToCoding ) {
         /* From the ICU Documentation: "ICU does not use UCS-2. UCS-2 is a
          * subset of UTF-16. UCS-2 does not support surrogates, and UTF-16
          * does support surrogates. This means that UCS-2 only supports
          * UTF-16's Base Multilingual Plane (BMP). The notion of UCS-2 is
          * deprecated and dead. Unicode 2.0 in 1996 changed its default
          * encoding to UTF-16." (userguide.icu-project.org/icufaq)      */
        switch( sizeof(QUEX_TYPE_LEXATOM) ) {
        case 4:  ToCoding = little_endian_f ? "UTF32-LE" : "UTF32-LE"; break;
        case 2:  ToCoding = little_endian_f ? "UTF16-LE" : "UTF16-LE"; break;
        case 1:  ToCoding = "ISO-8859-1"; break;
        default:  __quex_assert(false); return false;
        }
    } 

    me->status = U_ZERO_ERROR;
    me->to_handle = ucnv_open(ToCoding, &me->status);
    if( me->to_handle == NULL || ! U_SUCCESS(me->status) ) return false;

    /* Setup the pivot buffer                                            */
    //me->pivot.source = &me->pivot.buffer[0];
    //me->pivot.target = &me->pivot.buffer[0];         
    me->reset_upon_next_conversion_f = TRUE;

    return true;
}

QUEX_INLINE bool    
QUEX_NAME(Converter_ICU_initialize_by_bom_id)(QUEX_NAME(Converter)* alter_ego,
                                              QUEX_TYPE_BOM         BomId)
{
    QUEX_NAME(Converter_ICU)* me = (QUEX_NAME(Converter_ICU)*)alter_ego;
    const char* name;

    if( me->from_handle ) ucnv_close(me->from_handle); 
    if( me->to_handle )   ucnv_close(me->to_handle);

    switch( BomId ) {
    case QUEX_BOM_UTF_8:           name = "UTF-8"; break;                      
    case QUEX_BOM_UTF_1:           name = "UTF-1"; break;                      
    case QUEX_BOM_UTF_EBCDIC:      return false; /* name = "UTF_EBCDIC"; */
    case QUEX_BOM_BOCU_1:          name = "BOCU-1"; break;                    
    case QUEX_BOM_GB_18030:        name = "gb18030"; break;                
    case QUEX_BOM_UTF_7:           name = "UTF-7"; break;                      
    case QUEX_BOM_UTF_16:          name = "UTF-16"; break;                                  
    case QUEX_BOM_UTF_16_LE:       name = "UTF-16LE"; break;              
    case QUEX_BOM_UTF_16_BE:       name = "UTF-16BE"; break;              
    case QUEX_BOM_UTF_32:          name = "UTF-32"; break;                    
    case QUEX_BOM_UTF_32_LE:       name = "UTF-32LE"; break;              
    case QUEX_BOM_UTF_32_BE:       name = "UTF-32BE"; break;              
    case QUEX_BOM_SCSU:            name = "SCSU"; break;                        
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

    return QUEX_NAME(Converter_ICU_initialize)(alter_ego, name, NULL);
}

QUEX_INLINE E_LoadResult
QUEX_NAME(Converter_ICU_convert)(QUEX_NAME(Converter)*       alter_ego, 
                                 uint8_t**                   source, 
                                 const uint8_t*              SourceEnd, 
                                 QUEX_TYPE_LEXATOM**       drain,  
                                 const QUEX_TYPE_LEXATOM*  DrainEnd)
/* RETURNS: 'true'  if the drain was completely filled.
 *          'false' if the drain could not be filled completely and 
 *                  more source bytes are required.                      */
{
    QUEX_NAME(Converter_ICU)* me          = (QUEX_NAME(Converter_ICU)*)alter_ego;
    uint8_t*                  SourceBegin = *source;
    (void)SourceBegin;
#   if 0
    QUEX_TYPE_LEXATOM*      DEBUG_DrainBegin  = *drain;
    int                       i = 0;
#   endif

    __quex_assert(me);
    __quex_assert(me->to_handle);
    __quex_assert(me->from_handle);
    __quex_assert(SourceEnd >= *source);
    __quex_assert(DrainEnd >= *drain);
    __quex_assert(&me->pivot.buffer[0] <= me->pivot.source);
    __quex_assert(me->pivot.source     <= me->pivot.target);
    __quex_assert(me->pivot.target     <= &me->pivot.buffer[QUEX_SETTING_ICU_PIVOT_BUFFER_SIZE]);

    me->status = U_ZERO_ERROR;
    ucnv_convertEx(me->to_handle, me->from_handle,
                   (char**)drain,        (const char*)DrainEnd,
                   (const char**)source, (const char*)SourceEnd,
                   &me->pivot.buffer[0], &me->pivot.source, &me->pivot.target, &me->pivot.buffer[QUEX_SETTING_ICU_PIVOT_BUFFER_SIZE],
                   /* reset = */me->reset_upon_next_conversion_f ? TRUE : FALSE, 
                   /* flush = */FALSE,
                   &me->status);
    me->reset_upon_next_conversion_f = FALSE;
    
    if( me->status == U_INVALID_CHAR_FOUND ) {
        me->status = U_ZERO_ERROR;
        return E_LoadResult_BAD_LEXATOM;
    }
    me->status = U_ZERO_ERROR;

    __quex_assert(*source >= SourceBegin);

    return *drain == DrainEnd ? E_LoadResult_COMPLETE 
                              : E_LoadResult_INCOMPLETE;
}

QUEX_INLINE ptrdiff_t 
QUEX_NAME(Converter_ICU_stomach_byte_n)(QUEX_NAME(Converter)* alter_ego)
/* To compute the source bytes which have not been converted during the last
 * conversion the 3-buffer setup must be considered. First, ICU converts the
 * source data into a pivot buffer encoded in UTF16. The the content of the
 * pivot buffer is converted into the user's drain. 
 * 
 *  source buffer  [x.x.x|y.y|z|a.a.a|b.b.b|c.c. ]    'c's are not complete
 *  (e.g. UTF8)    :   .-'   : '---. '-.   '---.      => pending = 2
 *                 :   :     '-.   :   '---.   :      
 *  pivot buffer   [X.X|Y.Y|Y.Y|Z.Z|A.A|A.A|B.B| ...  pivot.source--> 'A's
 *  (fix UTF16)    :   :   .---'   :                  pivot.target--> after 'B's
 *                 :   :   :   .---'                  
 *  drain buffer   [ X | Y | Z ]                      Drain filled to limit
 *  (some UCS)                                        'A' and 'B' cannot be 
 *                                                    converted.
 * 
 * => Source bytes NOT translated in the last conversion:
 * 
 *    (1) The 'c's that where incomplete: 'ucnv_toUCountPending()'
 *    (2) Source bytes that produced the 'A's and 'B's in the pivot buffer.  
 *
 * However, what if the conversion contained a 0xFFFD, i.e. a conversion error.
 * At the current time, I know of no reliable way to get the stomach byte
 * number <fschaef 2015y10m24d>
 * => Only report, if nothing left in pivot buffer.                          */
{
    QUEX_NAME(Converter_ICU)* me = (QUEX_NAME(Converter_ICU)*)alter_ego;

#   if 0
    /* If things go really bad; set the above to '#if 1'; Then the ICU never
     * claims to know how many bytes are in the stomach.                     */
    return (ptrdiff_t)-1;
#   endif 

    if( me->pivot.source != me->pivot.target ) {
        return (ptrdiff_t)-1;                      /* Unable to tell. Sorry. */
    }
    return ucnv_toUCountPending(me->from_handle, &me->status);
}

QUEX_INLINE void 
QUEX_NAME(Converter_ICU_stomach_clear)(QUEX_NAME(Converter)* alter_ego)
{
    QUEX_NAME(Converter_ICU)* me = (QUEX_NAME(Converter_ICU)*)alter_ego;

    // if( me->from_handle ) ucnv_reset(me->from_handle);
    // if( me->to_handle )   ucnv_reset(me->to_handle);

    /* Reset the pivot buffer iterators */
    //me->pivot.source = &me->pivot.buffer[0];
    //me->pivot.target = &me->pivot.buffer[0];
    me->reset_upon_next_conversion_f = TRUE;

    me->status = U_ZERO_ERROR;
}

QUEX_INLINE void
QUEX_NAME(Converter_ICU_delete_self)(QUEX_NAME(Converter)* alter_ego)
{
    QUEX_NAME(Converter_ICU)* me = (QUEX_NAME(Converter_ICU)*)alter_ego;

    if( me->from_handle ) ucnv_close(me->from_handle);
    if( me->to_handle )   ucnv_close(me->to_handle);

    QUEXED(MemoryManager_free)((void*)me, E_MemoryObjectType_CONVERTER);

    /* There should be a way to call 'ucnv_flushCache()' as soon as all converters
     * are freed automatically.                                                       */
    u_cleanup();
}

QUEX_INLINE void 
QUEX_NAME(Converter_ICU_print_this)(QUEX_NAME(Converter)* alter_ego)
{
    QUEX_NAME(Converter_ICU)* me = (QUEX_NAME(Converter_ICU)*)alter_ego;
    const void*  PivotBegin = (const void*)&me->pivot.buffer[0];
    const void*  PivotEnd   = (const void*)&me->pivot.buffer[QUEX_SETTING_ICU_PIVOT_BUFFER_SIZE];

    __QUEX_STD_printf("        type:                         ICU, IBM (tm);\n");
    __QUEX_STD_printf("        from_handle:                  ((%p));\n", (void*)me->from_handle);
    __QUEX_STD_printf("        to_handle:                    ((%p));\n", (void*)me->to_handle);
    __QUEX_STD_printf("        status:                       %s;\n",     u_errorName(me->status));
    __QUEX_STD_printf("        reset_upon_next_conversion_f: %s;\n",
                      E_Boolean_NAME(me->reset_upon_next_conversion_f));

    __QUEX_STD_printf("        pivot: {\n");
    __QUEX_STD_printf("           buffer: { begin: ((%p)) end: ((%p)) size: %i; }\n",
                      PivotBegin, PivotEnd, (int)QUEX_SETTING_ICU_PIVOT_BUFFER_SIZE);
    __QUEX_STD_printf("           source: ");
    QUEXED(print_relative_positions)(PivotBegin, PivotEnd, sizeof(UChar),
                                     (void*)me->pivot.source);
    __QUEX_STD_printf("\n");
    __QUEX_STD_printf("           target: ");
    QUEXED(print_relative_positions)(PivotBegin, PivotEnd, sizeof(UChar),
                                     me->pivot.target);
    __QUEX_STD_printf("\n");
    __QUEX_STD_printf("        }\n");
}

QUEX_NAMESPACE_MAIN_CLOSE

#endif /* __INCLUDE_GUARD__QUEX_BUFFER__CONVERTER_ICU_I__ */
