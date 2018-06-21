/* -*- C++ -*- vim: set syntax=cpp:
 * PURPOSE: 
 *
 * Generate string converter functions which convert a string from one 
 * character codec into another. The conversion is implemented by means
 * of a character converter function given by:
 *
 *            QUEX_CONVERTER_CHAR(FROM, TO)(in, out); 
 *
 * which converts only a single character. The converter function must
 * be defined before the inclusion of this file.
 *
 * PARAMETERS (must be defined macros):
 *
 *      __QUEX_FROM            -- Name of the source character encoding.
 *      __QUEX_TO_MAX_LENGTH   -- Maximum number of 'code units' which a character
 *                                may occupy. 
 *                                This is important to maintain a safety margin.
 *      __QUEX_TO              -- Name of the target encoding.
 *      __QUEX_TO_TYPE         -- Type of characters that carry the drain.            
 *
 * (C) 2010-2012 Frank-Rene Schaefer 
 * ABSOLUTELY NO WARRANTY                                                    */
#if   ! defined(__QUEX_FROM)
#   error      "__QUEX_FROM definition missing!"
#elif ! defined(__QUEX_TO_TYPE)
#   error      "__QUEX_TO_TYPE definition missing!"
#elif ! defined(__QUEX_TO)
#   error      "__QUEX_TO definition missing!"
#endif

/* UTF8 element = 1 byte. UCS character range => max. 4 chunks / char.   */
#define __QUEX_TO_MAX_LENGTH_utf8  4
/* UTF16 element = 2 bytes. Max. 2 chunks per character.                 */
#define __QUEX_TO_MAX_LENGTH_utf16 2
/* UTF32 element = 4 bytes. Always 1 chunk per character.                */
#define __QUEX_TO_MAX_LENGTH_utf32 1
/* Assume the worst case for 'char' and 'wchar_t': Both are encoded in 
 * UTF8 (!?). Thus, we would need 4 elements per character for UCS.      */
#define __QUEX_TO_MAX_LENGTH_char        __QUEX_TO_MAX_LENGTH_utf8
#define __QUEX_TO_MAX_LENGTH_pretty_char __QUEX_TO_MAX_LENGTH_char
#define __QUEX_TO_MAX_LENGTH_wchar       __QUEX_TO_MAX_LENGTH_utf8

/* Define max. length in terms of the given output codec.                */
#define ____QUEX_TO_MAX_LENGTH(X)        __QUEX_TO_MAX_LENGTH_ ## X
#define __QUEX_TO_MAX_LENGTH(X)          ____QUEX_TO_MAX_LENGTH(X)

QUEX_INLINE void
QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, __QUEX_TO)(const QUEX_TYPE_LEXATOM**  source_pp, 
                                                  const QUEX_TYPE_LEXATOM*   SourceEnd, 
                                                  __QUEX_TO_TYPE**          drain_pp,  
                                                  const __QUEX_TO_TYPE*     DrainEnd)
{
    const QUEX_TYPE_LEXATOM*  source_iterator; 
    __QUEX_TO_TYPE*          drain_iterator;

    __quex_assert(source_pp != 0x0);
    __quex_assert(*source_pp != 0x0);
    __quex_assert(drain_pp != 0x0);
    __quex_assert(*drain_pp != 0x0);

    drain_iterator  = *drain_pp;
    source_iterator = *source_pp;

    while( 1 + 1 == 2 ) { 
        if     ( source_iterator == SourceEnd ) break;
        else if( DrainEnd - drain_iterator < (ptrdiff_t)__QUEX_TO_MAX_LENGTH(__QUEX_TO) ) break;
        QUEX_CONVERTER_CHAR(__QUEX_FROM, __QUEX_TO)(&source_iterator, &drain_iterator);
        __quex_assert(source_iterator >  *source_pp);
        __quex_assert(source_iterator <= SourceEnd);
    }

    *drain_pp  = drain_iterator;
    *source_pp = source_iterator;
}

#if ! defined(__QUEX_OPTION_PLAIN_C)
QUEX_INLINE std::basic_string<__QUEX_TO_TYPE>
QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, __QUEX_TO)(const std::basic_string<QUEX_TYPE_LEXATOM>& Source)
{
    /* Avoiding the mess with 'c_str()' and 'begin()' in 'std::string()'
     * => copy string to a temporary array.                                   */
    QUEX_TYPE_LEXATOM*                 source = (QUEX_TYPE_LEXATOM*)
                                                QUEXED(MemoryManager_allocate)(
                                                sizeof(QUEX_TYPE_LEXATOM) * (Source.length() + 1),
                                                E_MemoryObjectType_TEXT);
    const QUEX_TYPE_LEXATOM*           source_iterator;
    const QUEX_TYPE_LEXATOM*           SourceEnd = &source[Source.length()];
    __QUEX_TO_TYPE                     drain[__QUEX_TO_MAX_LENGTH(__QUEX_TO)];
    __QUEX_TO_TYPE*                    drain_iterator  = 0;
    std::basic_string<__QUEX_TO_TYPE>  result;

    if( ! Source.copy(&source[0], Source.length()) ) {
        QUEXED(MemoryManager_free)(source, E_MemoryObjectType_TEXT);
        return result;
    }
    /* .copy() does not append a terminating zero ...
     * and it is not to be copied.                                            */

    for(source_iterator = &source[0]; source_iterator != SourceEnd; ) {
        drain_iterator = drain;
        QUEX_CONVERTER_CHAR(__QUEX_FROM, __QUEX_TO)(&source_iterator, &drain_iterator);
        __quex_assert(source_iterator >  &source[0]);
        __quex_assert(source_iterator <= SourceEnd);
        result.append((__QUEX_TO_TYPE*)drain, (size_t)(drain_iterator - drain));
    }

    QUEXED(MemoryManager_free)(source, E_MemoryObjectType_TEXT);
    return result;
}
#endif

#undef __QUEX_TO
#undef __QUEX_TO_TYPE
#undef __QUEX_TO_MAX_LENGTH_utf8 
#undef __QUEX_TO_MAX_LENGTH_utf16 
#undef __QUEX_TO_MAX_LENGTH_utf32 
#undef ____QUEX_TO_MAX_LENGTH  
#undef __QUEX_TO_MAX_LENGTH  

