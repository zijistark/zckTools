/* -*- C++ -*-  vim: set syntax=cpp:
 *
 * (C) 2008 Frank-Rene Schaefer */
#ifndef __QUEX_INCLUDE_GUARD__BUFFER__BUFFER_PRINT_I
#define __QUEX_INCLUDE_GUARD__BUFFER__BUFFER_PRINT_I

#include <quex/code_base/definitions>
#include <quex/code_base/buffer/Buffer>
#include <quex/code_base/buffer/lexatoms/LexatomLoader>
#include <quex/code_base/buffer/asserts>
#include <quex/code_base/buffer/asserts.i>
#include <quex/code_base/buffer/Buffer_print>


QUEX_NAMESPACE_MAIN_OPEN

QUEX_INLINE void  
QUEX_NAME(Buffer_print_content_detailed_lines)(QUEX_TYPE_LEXATOM** iterator, 
                                               QUEX_TYPE_LEXATOM*  Begin, 
                                               QUEX_TYPE_LEXATOM*  TotalEnd, 
                                               QUEX_NAME(Buffer)*  buffer);

QUEX_INLINE void  
QUEX_NAME(Buffer_print_content)(QUEX_NAME(Buffer)* me)
{
    QUEX_NAME(Buffer_print_content_core)(sizeof(QUEX_TYPE_LEXATOM),
                                         (const uint8_t*)me->_memory._front,
                                         (const uint8_t*)me->_memory._back, 
                                         (const uint8_t*)me->_read_p, 
                                         (const uint8_t*)me->input.end_p,
                                         /* BordersF */ true);

}

QUEX_INLINE void  
QUEX_NAME(Buffer_print_content_detailed)(QUEX_NAME(Buffer)* me) 
{
    /* Assumptions: 
     *    (1) width of terminal     = 80 chars
     *    (2) border right and left = 3 chars
     *    (3) display at least the last 5 chars at the begin of buffer.
     *                                  5 chars around input_p.
     *                                  5 chars from lexeme_start.
     *                                  5 chars to the end of buffer.
     *
     *    |12345 ...      12345  ....       12345      ....    12345|
     *    Begin           lexeme start        input_p               buffer end     */ 
    QUEX_TYPE_LEXATOM*  iterator  = me->_memory._front;
    QUEX_TYPE_LEXATOM*  total_end = me->_memory._back + 1;
    __quex_assert(me != 0x0);

    if( QUEX_NAME(Buffer_resources_absent)(me) ) {
        __QUEX_STD_printf("  <detailed buffer content cannot be displayed>\n");
        return;
    }

    __QUEX_STD_fprintf(stderr, "_________________________________________________________________\n");
    QUEX_NAME(Buffer_print_content_detailed_lines)(&iterator, me->_memory._front,      total_end, me);
    QUEX_NAME(Buffer_print_content_detailed_lines)(&iterator, me->_lexeme_start_p - 2, total_end, me);
    QUEX_NAME(Buffer_print_content_detailed_lines)(&iterator, me->_read_p        - 2, total_end, me);
    if( me->input.end_p != 0x0 ) {
        QUEX_NAME(Buffer_print_content_detailed_lines)(&iterator, me->input.end_p - 4, total_end, me);
    }
    QUEX_NAME(Buffer_print_content_detailed_lines)(&iterator, me->_memory._back   - 4, total_end, me);
    __QUEX_STD_fprintf(stderr, "_________________________________________________________________\n");
}

QUEX_INLINE void  
QUEX_NAME(Buffer_print_content_core)(const size_t   ElementSize, 
                                     const uint8_t* Front,
                                     const uint8_t* Back,
                                     const uint8_t* ReadP,
                                     const uint8_t* InputEndP,
                                     bool           BordersF)
{
    const uint8_t* it;
    __QUEX_STD_printf("[");
    for(it=Front; it <= Back; it += ElementSize) {
        if( it < InputEndP ) {
            switch( ElementSize ) {
            case 1:  __QUEX_STD_printf("%02X", it[0]); break;
            case 2:  __QUEX_STD_printf("%04X", ((uint16_t*)it)[0]); break;
            case 4: 
            default: __QUEX_STD_printf("%08X", ((uint32_t*)it)[0]); break;
            }
        }
        else {
            __QUEX_STD_printf("--");
        }

        if( &it[ElementSize] == ReadP ) {
            __QUEX_STD_printf(">");
        }
        else if( BordersF && (it == Front || &it[1] == Back ) ) {
            __QUEX_STD_printf("|");
        }
        else if( it != Back && &it[ElementSize] != ReadP ) {
            __QUEX_STD_printf(".");
        }
    }
    __QUEX_STD_printf("]");
}

QUEX_INLINE void  
QUEX_NAME(Buffer_print_this)(QUEX_NAME(Buffer)* me)
{
    __QUEX_STD_printf("  buffer: ");
    if( QUEX_NAME(Buffer_resources_absent)(me) ) {
        __QUEX_STD_printf("<uninitialized>\n");
        return;
    }
    __QUEX_STD_printf("{\n");
    QUEX_NAME(BufferMemory_print_this)(&me->_memory);

    __QUEX_STD_printf("    _read_p:                      ");
    QUEXED(print_relative_positions)(&me->_memory._front[0], &me->_memory._back[1], 
                                     sizeof(QUEX_TYPE_LEXATOM), me->_read_p);
    __QUEX_STD_printf("\n");
    __QUEX_STD_printf("    _lexeme_start_p:              ");
    QUEXED(print_relative_positions)(&me->_memory._front[0], &me->_memory._back[1], 
                                     sizeof(QUEX_TYPE_LEXATOM), me->_lexeme_start_p);
    __QUEX_STD_printf("\n");

    __QUEX_STD_printf("    _lexatom_at_lexeme_start:     0x%X;\n", (int)me->_lexatom_at_lexeme_start);
#       ifdef __QUEX_OPTION_SUPPORT_BEGIN_OF_LINE_PRE_CONDITION
    __QUEX_STD_printf("    _lexatom_before_lexeme_start: 0x%X;\n", (int)me->_lexatom_before_lexeme_start);
#       endif

    QUEX_NAME(LexatomLoader_print_this)(me->filler);

    __QUEX_STD_printf("    input: {\n");
    __QUEX_STD_printf("      lexatom_index_begin: %i;\n", (int)QUEX_NAME(Buffer_input_lexatom_index_begin)(me));
    __QUEX_STD_printf("      end_character_index: %i;\n", (int)QUEX_NAME(Buffer_input_lexatom_index_end)(me));
    __QUEX_STD_printf("      end_p:               ");
    QUEXED(print_relative_positions)(&me->_memory._front[0], &me->_memory._back[1], 
                                     sizeof(QUEX_TYPE_LEXATOM), me->input.end_p);
    __QUEX_STD_printf("\n");
    __QUEX_STD_printf("    }\n");
    __QUEX_STD_printf("  }\n");
}


QUEX_INLINE void  
QUEX_NAME(Buffer_print_content_detailed_lines)(QUEX_TYPE_LEXATOM** iterator, 
                                               QUEX_TYPE_LEXATOM*  Begin, 
                                               QUEX_TYPE_LEXATOM*  TotalEnd, 
                                               QUEX_NAME(Buffer)*  buffer)
{
    int                 length = 0;
    QUEX_TYPE_LEXATOM*  end    = Begin + 5 > TotalEnd ? TotalEnd : Begin + 5;

    if( Begin > *iterator ) {
        *iterator = Begin;
        __QUEX_STD_fprintf(stderr, "                                           ...\n");
    } else if( *iterator >= end ) {
        return;
    }

    for(; *iterator < end; ++*iterator) {
        length = 0;
        __QUEX_STD_fprintf(stderr, "   ");

        if( *iterator == buffer->_memory._front ) {
            __QUEX_STD_fprintf(stderr, "buffer front");
            length += 12;
        }
        if( *iterator == buffer->_lexeme_start_p ) {
            if( length ) { __QUEX_STD_fprintf(stderr, ", "); length += 2; }
            __QUEX_STD_fprintf(stderr, "lexeme start");
            length += 12;
        }
        if( *iterator == buffer->_read_p ) {
            if( length ) { __QUEX_STD_fprintf(stderr, ", "); length += 2; }
            __QUEX_STD_fprintf(stderr, "input");
            length += 5;
        }
        if( *iterator == buffer->input.end_p ) {
            if( length ) { __QUEX_STD_fprintf(stderr, ", "); length += 2; }
            __QUEX_STD_fprintf(stderr, "end of file");
            length += 11;
        }
        if( *iterator == buffer->_memory._back ) {
            if( length ) { __QUEX_STD_fprintf(stderr, ", "); length += 2; }
            __QUEX_STD_fprintf(stderr, "buffer back");
            length += 11;
        }
        if( length ) {
            for(; length < 39; ++length)
                __QUEX_STD_fprintf(stderr, "-");
            __QUEX_STD_fprintf(stderr, ">");
        } else {
            __QUEX_STD_fprintf(stderr, "                                        ");
        }

        /* Print the character information */
        __QUEX_STD_fprintf(stderr, "[%04X] 0x%04X\n", 
                           (int)(*iterator - buffer->_memory._front),
                           (int)(**iterator));
    }
}

QUEX_NAMESPACE_MAIN_CLOSE

#endif /* __QUEX_INCLUDE_GUARD__BUFFER__BUFFER_PRINT_I */
