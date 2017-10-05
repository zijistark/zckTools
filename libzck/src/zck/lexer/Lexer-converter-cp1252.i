/* -*- C++ -*- vim: set syntax=cpp:
 * PURPOSE: 
 *
 * Provide the implementation of character and string converter functions
 * FROM the buffer's cp1252 to utf8, utf16, utf32, char, and wchar_t.
 *
 * STEPS:
 *
 * (1) Implement the character converters from buffer's cp1252 to 
 *     utf8, utf16, utf32. Those come out of quex's code generator.
 *
 * (1b) Derive the converts from cp1252 to char and wchar_t from
 *      those converters. For this use:
 *
 *          "../generator/character-converter-char-wchar_t.gi"
 *
 * (2) Generate the implementation of the string converters in terms
 *     of those character converters.
 *
 *     Use: "../generator/implementation-string-converters.gi"
 *
 *          which uses
 *
 *              "../generator/string-converter.gi"
 *
 *          to implement each string converter from the given 
 *          character converters. 
 *
 * These functions ARE DEPENDENT on QUEX_TYPE_LEXATOM.
 * => Thus, they are placed in the analyzer's namespace.
 *
 * 2010 (C) Frank-Rene Schaefer; 
 * ABSOLUTELY NO WARRANTY                                                    */
#ifndef __QUEX_INCLUDE_GUARD__LEXEME_CONVERTER__cp1252_I
#define __QUEX_INCLUDE_GUARD__LEXEME_CONVERTER__cp1252_I

#include "Lexer-converter-cp1252"

QUEX_NAMESPACE_TOKEN_OPEN

QUEX_INLINE void
QUEX_CONVERTER_CHAR_DEF(cp1252, utf32)(const QUEX_TYPE_LEXATOM** input_pp,
                                          uint32_t**                output_pp)
{
    uint32_t          unicode;
    int32_t           offset;
    QUEX_TYPE_LEXATOM input = *(*input_pp)++;

switch( input ) {

case 0x80: 
offset = (int32_t)(8236);
 goto code_unit_n_1;

case 0x82: 
offset = (int32_t)(8088);
 goto code_unit_n_1;

case 0x83: 
offset = (int32_t)(271);
 goto code_unit_n_1;

case 0x84: 
offset = (int32_t)(8090);
 goto code_unit_n_1;

case 0x85: 
offset = (int32_t)(8097);
 goto code_unit_n_1;

case 0x86: case 0x87: 
offset = (int32_t)(8090);
 goto code_unit_n_1;

case 0x88: 
offset = (int32_t)(574);
 goto code_unit_n_1;

case 0x89: 
offset = (int32_t)(8103);
 goto code_unit_n_1;

case 0x8A: 
offset = (int32_t)(214);
 goto code_unit_n_1;

case 0x8B: 
offset = (int32_t)(8110);
 goto code_unit_n_1;

case 0x8C: 
offset = (int32_t)(198);
 goto code_unit_n_1;

case 0x8E: 
offset = (int32_t)(239);
 goto code_unit_n_1;

case 0x91: case 0x92: 
offset = (int32_t)(8071);
 goto code_unit_n_1;

case 0x93: case 0x94: 
offset = (int32_t)(8073);
 goto code_unit_n_1;

case 0x95: 
offset = (int32_t)(8077);
 goto code_unit_n_1;

case 0x96: case 0x97: 
offset = (int32_t)(8061);
 goto code_unit_n_1;

case 0x98: 
offset = (int32_t)(580);
 goto code_unit_n_1;

case 0x99: 
offset = (int32_t)(8329);
 goto code_unit_n_1;

case 0x9A: 
offset = (int32_t)(199);
 goto code_unit_n_1;

case 0x9B: 
offset = (int32_t)(8095);
 goto code_unit_n_1;

case 0x9C: 
offset = (int32_t)(183);
 goto code_unit_n_1;

case 0x9E: 
offset = (int32_t)(224);
 goto code_unit_n_1;

case 0x9F: 
offset = (int32_t)(217);
 goto code_unit_n_1;

default: offset = (int32_t)(0);
 goto code_unit_n_1;

}

code_unit_n_1:
    unicode = (uint32_t)(input + offset);
    *(*output_pp)++ = unicode;
    __QUEX_PURE_RETURN;
}

QUEX_INLINE void
QUEX_CONVERTER_CHAR_DEF(cp1252, utf16)(const QUEX_TYPE_LEXATOM** input_pp,
                                          uint16_t**                output_pp)
{
    uint32_t          unicode;
    int32_t           offset;
    QUEX_TYPE_LEXATOM input = *(*input_pp)++;

switch( input ) {

case 0x80: 
offset = (int32_t)(8236);
 goto code_unit_n_1;

case 0x82: 
offset = (int32_t)(8088);
 goto code_unit_n_1;

case 0x83: 
offset = (int32_t)(271);
 goto code_unit_n_1;

case 0x84: 
offset = (int32_t)(8090);
 goto code_unit_n_1;

case 0x85: 
offset = (int32_t)(8097);
 goto code_unit_n_1;

case 0x86: case 0x87: 
offset = (int32_t)(8090);
 goto code_unit_n_1;

case 0x88: 
offset = (int32_t)(574);
 goto code_unit_n_1;

case 0x89: 
offset = (int32_t)(8103);
 goto code_unit_n_1;

case 0x8A: 
offset = (int32_t)(214);
 goto code_unit_n_1;

case 0x8B: 
offset = (int32_t)(8110);
 goto code_unit_n_1;

case 0x8C: 
offset = (int32_t)(198);
 goto code_unit_n_1;

case 0x8E: 
offset = (int32_t)(239);
 goto code_unit_n_1;

case 0x91: case 0x92: 
offset = (int32_t)(8071);
 goto code_unit_n_1;

case 0x93: case 0x94: 
offset = (int32_t)(8073);
 goto code_unit_n_1;

case 0x95: 
offset = (int32_t)(8077);
 goto code_unit_n_1;

case 0x96: case 0x97: 
offset = (int32_t)(8061);
 goto code_unit_n_1;

case 0x98: 
offset = (int32_t)(580);
 goto code_unit_n_1;

case 0x99: 
offset = (int32_t)(8329);
 goto code_unit_n_1;

case 0x9A: 
offset = (int32_t)(199);
 goto code_unit_n_1;

case 0x9B: 
offset = (int32_t)(8095);
 goto code_unit_n_1;

case 0x9C: 
offset = (int32_t)(183);
 goto code_unit_n_1;

case 0x9E: 
offset = (int32_t)(224);
 goto code_unit_n_1;

case 0x9F: 
offset = (int32_t)(217);
 goto code_unit_n_1;

default: offset = (int32_t)(0);
 goto code_unit_n_1;

}

code_unit_n_1:
    unicode = (uint32_t)(input + offset);
    *(*output_pp)++ = (uint16_t)(unicode);
    __QUEX_PURE_RETURN;
}

QUEX_INLINE void
QUEX_CONVERTER_CHAR_DEF(cp1252, utf8)(const QUEX_TYPE_LEXATOM**  input_pp, 
                                         uint8_t**                  output_pp)
{
    uint32_t          unicode;
    int32_t           offset;
    QUEX_TYPE_LEXATOM input = *(*input_pp)++;
    
switch( input ) {

case 0x80: 
offset = (int32_t)(8236);
 goto code_unit_n_3;

case 0x82: 
offset = (int32_t)(8088);
 goto code_unit_n_3;

case 0x83: 
offset = (int32_t)(271);
 goto code_unit_n_2;

case 0x84: 
offset = (int32_t)(8090);
 goto code_unit_n_3;

case 0x85: 
offset = (int32_t)(8097);
 goto code_unit_n_3;

case 0x86: case 0x87: 
offset = (int32_t)(8090);
 goto code_unit_n_3;

case 0x88: 
offset = (int32_t)(574);
 goto code_unit_n_2;

case 0x89: 
offset = (int32_t)(8103);
 goto code_unit_n_3;

case 0x8A: 
offset = (int32_t)(214);
 goto code_unit_n_2;

case 0x8B: 
offset = (int32_t)(8110);
 goto code_unit_n_3;

case 0x8C: 
offset = (int32_t)(198);
 goto code_unit_n_2;

case 0x8E: 
offset = (int32_t)(239);
 goto code_unit_n_2;

case 0x91: case 0x92: 
offset = (int32_t)(8071);
 goto code_unit_n_3;

case 0x93: case 0x94: 
offset = (int32_t)(8073);
 goto code_unit_n_3;

case 0x95: 
offset = (int32_t)(8077);
 goto code_unit_n_3;

case 0x96: case 0x97: 
offset = (int32_t)(8061);
 goto code_unit_n_3;

case 0x98: 
offset = (int32_t)(580);
 goto code_unit_n_2;

case 0x99: 
offset = (int32_t)(8329);
 goto code_unit_n_3;

case 0x9A: 
offset = (int32_t)(199);
 goto code_unit_n_2;

case 0x9B: 
offset = (int32_t)(8095);
 goto code_unit_n_3;

case 0x9C: 
offset = (int32_t)(183);
 goto code_unit_n_2;

case 0x9E: 
offset = (int32_t)(224);
 goto code_unit_n_2;

case 0x9F: 
offset = (int32_t)(217);
 goto code_unit_n_2;

case 0xA0: case 0xA1: case 0xA2: case 0xA3: case 0xA4: case 0xA5: case 0xA6: case 0xA7: 

case 0xA8: case 0xA9: case 0xAA: case 0xAB: case 0xAC: case 0xAD: case 0xAE: case 0xAF: 

case 0xB0: case 0xB1: case 0xB2: case 0xB3: case 0xB4: case 0xB5: case 0xB6: case 0xB7: 

case 0xB8: case 0xB9: case 0xBA: case 0xBB: case 0xBC: case 0xBD: case 0xBE: case 0xBF: 

case 0xC0: case 0xC1: case 0xC2: case 0xC3: case 0xC4: case 0xC5: case 0xC6: case 0xC7: 

case 0xC8: case 0xC9: case 0xCA: case 0xCB: case 0xCC: case 0xCD: case 0xCE: case 0xCF: 

case 0xD0: case 0xD1: case 0xD2: case 0xD3: case 0xD4: case 0xD5: case 0xD6: case 0xD7: 

case 0xD8: case 0xD9: case 0xDA: case 0xDB: case 0xDC: case 0xDD: case 0xDE: case 0xDF: 

case 0xE0: case 0xE1: case 0xE2: case 0xE3: case 0xE4: case 0xE5: case 0xE6: case 0xE7: 

case 0xE8: case 0xE9: case 0xEA: case 0xEB: case 0xEC: case 0xED: case 0xEE: case 0xEF: 

case 0xF0: case 0xF1: case 0xF2: case 0xF3: case 0xF4: case 0xF5: case 0xF6: case 0xF7: 

case 0xF8: case 0xF9: case 0xFA: case 0xFB: case 0xFC: case 0xFD: case 0xFE: case 0xFF: 
offset = (int32_t)(0);
 goto code_unit_n_2;

default: offset = (int32_t)(0);
 goto code_unit_n_1;

}

code_unit_n_1:
    unicode = (uint32_t)(input + offset);
    *(*output_pp)++ = (uint8_t)(unicode);
    __QUEX_PURE_RETURN;
code_unit_n_2:
    unicode = (uint32_t)(input + offset);
    *(*output_pp)++ = (uint8_t)(0xC0 | (unicode >> 6));
    *(*output_pp)++ = (uint8_t)(0x80 | (unicode & (uint32_t)0x3F));
    __QUEX_PURE_RETURN;
code_unit_n_3:
    unicode = (uint32_t)(input + offset);
    *(*output_pp)++ = (uint8_t)(0xE0 | (unicode >> 12));
    *(*output_pp)++ = (uint8_t)(0x80 | ((unicode & (uint32_t)0xFFF) >> 6));
    *(*output_pp)++ = (uint8_t)(0x80 | (unicode & (uint32_t)0x3F));
    __QUEX_PURE_RETURN;
}

#define __QUEX_FROM           cp1252

/* (1b) Derive converters to char and wchar_t from the given set 
 *      of converters. (Generator uses __QUEX_FROM and QUEX_FROM_TYPE)      */
#include <quex/code_base/lexeme_converter/generator/character-converter-to-char-wchar_t.gi>

/* (2) Generate string converters to utf8, utf16, utf32 based on the
 *     definitions of the character converters.                             */
#include <quex/code_base/lexeme_converter/generator/implementations.gi>

QUEX_NAMESPACE_TOKEN_CLOSE

#endif /* __QUEX_INCLUDE_GUARD__LEXEME_CONVERTER__cp1252_I */

