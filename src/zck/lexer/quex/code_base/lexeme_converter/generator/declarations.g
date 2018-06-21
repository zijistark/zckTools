/* -*- C++ -*- vim: set syntax=cpp: 
 *
 * Declaration of all converter functions towards 'utf8', 'utf16', 'utf32',
 * 'char', and 'wchar_t': 
 *
 *    QUEX_CONVERTER_CHAR_DEF(__QUEX_FROM, utf8)(...)
 *    QUEX_CONVERTER_CHAR_DEF(__QUEX_FROM, utf16)(...)
 *    QUEX_CONVERTER_CHAR_DEF(__QUEX_FROM, utf32)(...)
 *    QUEX_CONVERTER_CHAR_DEF(__QUEX_FROM, char)(...)
 *    QUEX_CONVERTER_CHAR_DEF(__QUEX_FROM, wchar_t)(...)
 *
 *    QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, utf8)(...)     for string and buffer 
 *    QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, utf16)(...)    for string and buffer 
 *    QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, utf32)(...)    for string and buffer 
 *    QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, char)(...)     for string and buffer 
 *    QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, wchar_t)(...)  for string and buffer 
 *
 * (C) 2012 Frank-Rene Schaefer, ABSOLUTELY NO WARRANTY                      */
#if   ! defined(__QUEX_FROM)
#   error      "__QUEX_FROM definition missing!"
#elif ! defined(QUEX_TYPE_LEXATOM)
#   error      "QUEX_TYPE_LEXATOM definition missing!"
#elif ! defined(QUEX_INLINE)
#   error      "QUEX_INLINE definition missing!"
#elif ! defined(QUEX_CONVERTER_CHAR_DEF)
#   error      "QUEX_CONVERTER_CHAR_DEF definition missing!"
#elif ! defined(QUEX_CONVERTER_STRING_DEF)
#   error      "QUEX_CONVERTER_STRING_DEF definition missing!"
#endif

/* (1) Character converters */
QUEX_INLINE void
QUEX_CONVERTER_CHAR_DEF(__QUEX_FROM, utf8)(const QUEX_TYPE_LEXATOM** input_pp, 
                                           uint8_t**                 output_pp);
QUEX_INLINE void
QUEX_CONVERTER_CHAR_DEF(__QUEX_FROM, utf16)(const QUEX_TYPE_LEXATOM**  input_pp, 
                                            uint16_t**                output_pp);
QUEX_INLINE void
QUEX_CONVERTER_CHAR_DEF(__QUEX_FROM, utf32)(const QUEX_TYPE_LEXATOM**  input_pp, 
                                            uint32_t**                output_pp);
QUEX_INLINE void
QUEX_CONVERTER_CHAR_DEF(__QUEX_FROM, char)(const QUEX_TYPE_LEXATOM**  input_pp, 
                                           char**                    output_pp);
QUEX_INLINE void
QUEX_CONVERTER_CHAR_DEF(__QUEX_FROM, pretty_char)(const QUEX_TYPE_LEXATOM**  input_pp, 
                                                  char**                    output_pp);
#if ! defined(__QUEX_OPTION_WCHAR_T_DISABLED)
QUEX_INLINE void
QUEX_CONVERTER_CHAR_DEF(__QUEX_FROM, wchar)(const QUEX_TYPE_LEXATOM**  input_pp, 
                                            wchar_t**                 output_pp);
#endif

/* (2) String converters */
QUEX_INLINE void
QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, utf8)(const QUEX_TYPE_LEXATOM**  source_pp, 
                                             const QUEX_TYPE_LEXATOM*   SourceEnd, 
                                             uint8_t**                 drain_pp,  
                                             const uint8_t*            DrainEnd);
QUEX_INLINE void
QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, utf16)(const QUEX_TYPE_LEXATOM**  source_pp, 
                                              const QUEX_TYPE_LEXATOM*   SourceEnd, 
                                              uint16_t**                drain_pp,  
                                              const uint16_t*           DrainEnd);
QUEX_INLINE void
QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, utf32)(const QUEX_TYPE_LEXATOM**  source_pp, 
                                              const QUEX_TYPE_LEXATOM*   SourceEnd, 
                                              uint32_t**                drain_pp,  
                                              const uint32_t*           DrainEnd);
QUEX_INLINE void
QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, char)(const QUEX_TYPE_LEXATOM**  source_pp, 
                                             const QUEX_TYPE_LEXATOM*   SourceEnd, 
                                             char**                    drain_pp,  
                                             const char*               DrainEnd);
QUEX_INLINE void
QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, pretty_char)(const QUEX_TYPE_LEXATOM**  source_pp, 
                                                    const QUEX_TYPE_LEXATOM*   SourceEnd, 
                                                    char**                    drain_pp,  
                                                    const char*               DrainEnd);

#if ! defined(__QUEX_OPTION_WCHAR_T_DISABLED)
QUEX_INLINE void
QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, wchar)(const QUEX_TYPE_LEXATOM**  source_pp, 
                                              const QUEX_TYPE_LEXATOM*   SourceEnd, 
                                              wchar_t**                 drain_pp,  
                                              const wchar_t*            DrainEnd);
#endif

#if ! defined(__QUEX_OPTION_PLAIN_C)
    QUEX_INLINE std::basic_string<uint8_t>
    QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, utf8)(const std::basic_string<QUEX_TYPE_LEXATOM>& Source);
    QUEX_INLINE std::basic_string<uint16_t>
    QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, utf16)(const std::basic_string<QUEX_TYPE_LEXATOM>& Source);
    QUEX_INLINE std::basic_string<uint32_t>
    QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, utf32)(const std::basic_string<QUEX_TYPE_LEXATOM>& Source);
    QUEX_INLINE std::basic_string<char>
    QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, char)(const std::basic_string<QUEX_TYPE_LEXATOM>& Source);
    QUEX_INLINE std::basic_string<char>
    QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, pretty_char)(const std::basic_string<QUEX_TYPE_LEXATOM>& Source);
#   if ! defined(__QUEX_OPTION_WCHAR_T_DISABLED)
    QUEX_INLINE std::basic_string<wchar_t>
    QUEX_CONVERTER_STRING_DEF(__QUEX_FROM, wchar)(const std::basic_string<QUEX_TYPE_LEXATOM>& Source);
#   endif
#endif

#undef __QUEX_FROM      

