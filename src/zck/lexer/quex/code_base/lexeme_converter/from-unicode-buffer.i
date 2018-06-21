/* -*- C++ -*- vim: set syntax=cpp:
 * PURPOSE: 
 *
 * Provide the implementation of character and string converter functions
 * FROM the buffer's unicode to utf8, utf16, utf32, char, and wchar_t.
 *
 * STEPS:
 *
 * (1) Include the COMPLETE implementation of a reference transformation.
 *
 *             "character-converter-from-utf8.i"
 *             "character-converter-from-utf16.i"
 *             "character-converter-from-utf32.i"
 *
 *     Sometimes the size of QUEX_TYPE_LEXATOM could not be determined at 
 *     code generation time, therefore all need to be included.
 *
 * (2) Map the functions of the pattern
 *
 *        QUEX_CONVERTER_CHAR(unicode, *)(....)
 *
 *     to what is appropriate from the given headers, e.g.
 *
 *        QUEX_CONVERTER_CHAR(utf8, *)(....)
 *
 * (2b) Generate converters towards 'char' and 'wchar_t'
 *
 *        generator/character-converter-to-char-wchar_t.gi
 *
 * (3) Derive string converter functions from character converters.
 *
 *        generator/implementations.gi
 *
 * These functions ARE DEPENDENT on QUEX_TYPE_LEXATOM.
 * => Thus, they are placed in the analyzer's namespace.
 *
 * 2010 (C) Frank-Rene Schaefer; 
 * ABSOLUTELY NO WARRANTY                                                    */
#ifndef __QUEX_INCLUDE_GUARD__LEXEME_CONVERTER__FROM_UNICODE_BUFFER_I
#define __QUEX_INCLUDE_GUARD__LEXEME_CONVERTER__FROM_UNICODE_BUFFER_I

#include <quex/code_base/lexeme_converter/from-unicode-buffer>

/* (1) Access the implementation of the converter that will implement
 *     the unicode conversion.                                               */
#include <quex/code_base/lexeme_converter/from-utf8.i>
#include <quex/code_base/lexeme_converter/from-utf16.i>
#include <quex/code_base/lexeme_converter/from-utf32.i>


QUEX_NAMESPACE_TOKEN_OPEN

/* (2) Route the converters from 'unicode' to the implementing converter.    */
QUEX_INLINE void
QUEX_CONVERTER_CHAR_DEF(unicode, utf8)(const QUEX_TYPE_LEXATOM**  input_pp, 
                                       uint8_t**                  output_pp)
{ 
    switch( sizeof(QUEX_TYPE_LEXATOM) )
    {
    case 1:  QUEX_CONVERTER_CHAR(utf8, utf8)(input_pp, output_pp);   break;
    case 2:  QUEX_CONVERTER_CHAR(utf16, utf8)(input_pp, output_pp); break;
    case 4:  QUEX_CONVERTER_CHAR(utf32, utf8)(input_pp, output_pp); break;
    default: QUEX_ERROR_EXIT("Cannot derive converter for given element size.");
    }
}

QUEX_INLINE void
QUEX_CONVERTER_CHAR_DEF(unicode, utf16)(const QUEX_TYPE_LEXATOM**  input_pp, 
                                        uint16_t**                 output_pp)
{ 
    switch( sizeof(QUEX_TYPE_LEXATOM) )
    {
    case 1:  QUEX_CONVERTER_CHAR(utf8, utf16)(input_pp, output_pp);   break;
    case 2:  QUEX_CONVERTER_CHAR(utf16, utf16)(input_pp, output_pp); break;
    case 4:  QUEX_CONVERTER_CHAR(utf32, utf16)(input_pp, output_pp); break;
    default: QUEX_ERROR_EXIT("Cannot derive converter for given element size.");
    }
}

QUEX_INLINE void
QUEX_CONVERTER_CHAR_DEF(unicode, utf32)(const QUEX_TYPE_LEXATOM**  input_pp, 
                                        uint32_t**                 output_pp)
{ 
    switch( sizeof(QUEX_TYPE_LEXATOM) )
    {
    case 1:  QUEX_CONVERTER_CHAR(utf8, utf32)(input_pp, output_pp);  break;
    case 2:  QUEX_CONVERTER_CHAR(utf16, utf32)(input_pp, output_pp); break;
    case 4:  QUEX_CONVERTER_CHAR(utf32, utf32)(input_pp, output_pp); break;
    default: QUEX_ERROR_EXIT("Cannot derive converter for given element size.");
    }
}


/* (2b) Derive converters to char and wchar_t from the given set 
 *      of converters. (Generator uses __QUEX_FROM and QUEX_FROM_TYPE)      */
#define  __QUEX_FROM       unicode
#include <quex/code_base/lexeme_converter/generator/character-converter-to-char-wchar_t.gi>

/* (3) Generate string converters to utf8, utf16, utf32 based on the
 *     definitions of the character converters.                             */
#include <quex/code_base/lexeme_converter/generator/implementations.gi>

QUEX_NAMESPACE_TOKEN_CLOSE

#endif /* __QUEX_INCLUDE_GUARD__LEXEME_CONVERTER__FROM_UNICODE_BUFFER_I */
