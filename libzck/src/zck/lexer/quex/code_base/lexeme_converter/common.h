/* Common include headers for all converter functions. 
 *
 * (C) Frank-Rene Schaefer
 * ABSOLUTELY NO WARRANTY                                                    */
#ifndef  __QUEX_INCLUDE_GUARD__LEXEME_CONVERTER__COMMON_H
#define  __QUEX_INCLUDE_GUARD__LEXEME_CONVERTER__COMMON_H

#include <quex/code_base/definitions>
#include <quex/code_base/MemoryManager>
#include <quex/code_base/compatibility/stdint.h>
#include <quex/code_base/asserts>
#if ! defined(__QUEX_OPTION_PLAIN_C)
#   include <string>
#endif

#if defined(QUEX_CONVERTER_CHAR_DEF)
#   undef  __QUEX_CONVERTER_CHAR_DEF
#   undef  __QUEX_CONVERTER_STRING_DEF
#   undef  QUEX_CONVERTER_CHAR_DEF
#   undef  QUEX_CONVERTER_STRING_DEF
#   undef  __QUEX_CONVERTER_CHAR
#   undef  __QUEX_CONVERTER_STRING
#   undef  QUEX_CONVERTER_CHAR
#   undef  QUEX_CONVERTER_STRING
#endif

#define __QUEX_CONVERTER_CHAR_DEF(FROM, TO)    QUEX_NAME_TOKEN(FROM ## _to_ ## TO ## _character)
#define __QUEX_CONVERTER_STRING_DEF(FROM, TO)  QUEX_NAME_TOKEN(FROM ## _to_ ## TO)
#define QUEX_CONVERTER_CHAR_DEF(FROM, TO)      __QUEX_CONVERTER_CHAR_DEF(FROM, TO)
#define QUEX_CONVERTER_STRING_DEF(FROM, TO)    __QUEX_CONVERTER_STRING_DEF(FROM, TO)

#define __QUEX_CONVERTER_CHAR(FROM, TO)        QUEX_NAME_TOKEN(FROM ## _to_ ## TO ## _character)
#define __QUEX_CONVERTER_STRING(FROM, TO)      QUEX_NAME_TOKEN(FROM ## _to_ ## TO)
#define QUEX_CONVERTER_CHAR(FROM, TO)          __QUEX_CONVERTER_CHAR(FROM, TO)
#define QUEX_CONVERTER_STRING(FROM, TO)        __QUEX_CONVERTER_STRING(FROM, TO)

/* Signalize: Converters are available! 
 *
 * Since converters can come from multiple sources it is not possible to 
 * include in a header always the right converters. To get along, users of
 * converters must at least check that before they are included, the converter
 * headers have been made available--by inclusion before they were included  */
#define QUEX_OPTION_LEXEME_CONVERTERS

#endif                   /* __QUEX_INCLUDE_GUARD__LEXEME_CONVERTER__COMMON_H */
