/* -*- C++ -*- vim:set syntax=cpp: 
 * (C) Frank-Rene Schaefer    
 * ABSOLUTELY NO WARRANTY                                                     */
#ifndef __QUEX_INCLUDE_GUARD__LEXEME_I
#define __QUEX_INCLUDE_GUARD__LEXEME_I

#include <quex/code_base/definitions>

#if   ! defined(QUEX_INLINE)
#   error      "QUEX_INLINE definition missing."
#elif ! defined(QUEX_NAME_TOKEN)
#   error      "QUEX_NAME_TOKEN definition missing."
#elif ! defined(QUEX_TYPE_LEXATOM)
#   error      "QUEX_TYPE_LEXATOM definition missing."
#elif ! defined(QUEX_SETTING_CHARACTER_CODEC)
#   error      "QUEX_SETTING_CHARACTER_CODEC definition missing."
#elif ! defined(QUEX_CONVERTER_STRING)
#   error      "QUEX_CONVERTER_STRING definition missing."
#endif

QUEX_NAMESPACE_TOKEN_OPEN

QUEX_INLINE size_t 
QUEX_NAME_TOKEN(lexeme_length)(const QUEX_TYPE_LEXATOM* Str)
{
    const QUEX_TYPE_LEXATOM* iterator = Str;
    while( *iterator != 0 ) ++iterator; 
    return (size_t)(iterator - Str);
}

QUEX_INLINE size_t 
QUEX_NAME_TOKEN(lexeme_compare)(const QUEX_TYPE_LEXATOM* it0, 
                                const QUEX_TYPE_LEXATOM* it1)
{
    for(; *it0 == *it1; ++it0, ++it1) {
        /* Both letters are the same and == 0?
         * => both reach terminall zero without being different.              */
        if( *it0 == 0 ) return 0;
    }
    return (size_t)(*it0) - (size_t)(*it1);
}

QUEX_INLINE void
QUEX_NAME_TOKEN(lexeme_to_utf8)(const QUEX_TYPE_LEXATOM** source_p, 
                                const QUEX_TYPE_LEXATOM*  SourceEnd,
                                uint8_t**                 drain_p,  
                                const uint8_t*            DrainEnd)
{
    QUEX_CONVERTER_STRING(QUEX_SETTING_CHARACTER_CODEC,utf8)(
                          source_p, SourceEnd, drain_p, DrainEnd);
}

QUEX_INLINE void
QUEX_NAME_TOKEN(lexeme_to_utf16)(const QUEX_TYPE_LEXATOM** source_p, 
                                 const QUEX_TYPE_LEXATOM*  SourceEnd,
                                 uint16_t**                drain_p,  
                                 const uint16_t*           DrainEnd)
{
    QUEX_CONVERTER_STRING(QUEX_SETTING_CHARACTER_CODEC,utf16)(
                          source_p, SourceEnd, drain_p, DrainEnd);
}

QUEX_INLINE void
QUEX_NAME_TOKEN(lexeme_to_utf32)(const QUEX_TYPE_LEXATOM** source_p, 
                                 const QUEX_TYPE_LEXATOM*  SourceEnd,
                                 uint32_t**                drain_p,  
                                 const uint32_t*           DrainEnd)
{
    QUEX_CONVERTER_STRING(QUEX_SETTING_CHARACTER_CODEC,utf32)(
                          source_p, SourceEnd, drain_p, DrainEnd);
}

QUEX_INLINE void
QUEX_NAME_TOKEN(lexeme_to_char)(const QUEX_TYPE_LEXATOM** source_p, 
                                const QUEX_TYPE_LEXATOM*  SourceEnd,
                                char**                    drain_p,  
                                const char*               DrainEnd)
{
    QUEX_CONVERTER_STRING(QUEX_SETTING_CHARACTER_CODEC,char)(
                          source_p, SourceEnd, drain_p, DrainEnd);
}

QUEX_INLINE const char* 
QUEX_NAME_TOKEN(lexeme_to_pretty_char)(const QUEX_TYPE_LEXATOM* Lexeme, 
                                       char*                    buffer, 
                                       size_t                   BufferSize) 
/* Provides a somehow pretty-print of the text in the token. Note, that the 
 * buffer in case of UTF8 should be 4bytes longer than the longest expected 
 * string.                                                                    */
{
    const QUEX_TYPE_LEXATOM** source_p  = &Lexeme;
    const QUEX_TYPE_LEXATOM*  SourceEnd = &Lexeme[QUEX_NAME_TOKEN(lexeme_length)(Lexeme) + (size_t)1];
    char*                     original  = buffer;  /* Maintain original pointer    */
    char**                    drain_pp  = &buffer; /* Conv. changes buffer pointer */
    const char*               DrainEnd  = &buffer[BufferSize];

    QUEX_CONVERTER_STRING(QUEX_SETTING_CHARACTER_CODEC, pretty_char)(
                          source_p, SourceEnd, drain_pp, DrainEnd);

    return original;
}

#ifndef __QUEX_OPTION_PLAIN_C
QUEX_INLINE const std::string 
QUEX_NAME_TOKEN(lexeme_to_pretty_char)(const std::basic_string<QUEX_TYPE_LEXATOM>& Text) 
/* Provides a somehow pretty-print of the text in the token.          */
{
    return QUEX_CONVERTER_STRING(QUEX_SETTING_CHARACTER_CODEC, pretty_char)(Text);
}

#endif

#if ! defined(__QUEX_OPTION_WCHAR_T_DISABLED)
QUEX_INLINE void
QUEX_NAME_TOKEN(lexeme_to_wchar)(const QUEX_TYPE_LEXATOM** source_p, 
                                 const QUEX_TYPE_LEXATOM*  SourceEnd,
                                 wchar_t**                 drain_p,  
                                 const wchar_t*            DrainEnd)
{
    QUEX_CONVERTER_STRING(QUEX_SETTING_CHARACTER_CODEC,wchar)(
                          source_p, SourceEnd, drain_p,  DrainEnd);
}
#endif

QUEX_NAMESPACE_TOKEN_CLOSE

#endif /* __QUEX_INCLUDE_GUARD__LEXEME_I                                      */
