/* PURPOSE:
 * 
 * Generate function implementations for all string converters FROM 
 * a given encoding '__QUEX_FROM':
 *
 *        QUEX_CONVERTER_STRING(FROM, utf8)(...)
 *        QUEX_CONVERTER_STRING(FROM, utf16)(...)
 *        QUEX_CONVERTER_STRING(FROM, utf32)(...)
 *        QUEX_CONVERTER_STRING(FROM, char)(...)
 *        QUEX_CONVERTER_STRING(FROM, wchar)(...)
 *
 * It is Assumed that the character converters for each function are 
 * available!
 *
 * PARAMETERS:
 *
 *   __QUEX_FROM        Name of the input character codec.
 *
 * (C) 2012 Frank-Rene Schaefer; ABSOLUTELY NO WARRANTY                      */ 
#if ! defined(__QUEX_FROM)
#    error "__QUEX_FROM must be defined!"
#endif

#define  __QUEX_TO         utf8
#define  __QUEX_TO_TYPE    uint8_t
#include <quex/code_base/lexeme_converter/generator/string-converter.gi>
#define  __QUEX_TO         utf16
#define  __QUEX_TO_TYPE    uint16_t
#include <quex/code_base/lexeme_converter/generator/string-converter.gi>
#define  __QUEX_TO         utf32
#define  __QUEX_TO_TYPE    uint32_t
#include <quex/code_base/lexeme_converter/generator/string-converter.gi>
#define  __QUEX_TO         char
#define  __QUEX_TO_TYPE    char
#include <quex/code_base/lexeme_converter/generator/string-converter.gi>
#define  __QUEX_TO         pretty_char
#define  __QUEX_TO_TYPE    char
#include <quex/code_base/lexeme_converter/generator/string-converter.gi>

#if ! defined(__QUEX_OPTION_WCHAR_T_DISABLED)
#   define  __QUEX_TO         wchar
#   define  __QUEX_TO_TYPE    wchar_t
#   include <quex/code_base/lexeme_converter/generator/string-converter.gi>
#   undef   __QUEX_TO     
#   undef   __QUEX_TO_TYPE 
#endif

#undef __QUEX_FROM

