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

    __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, "_________________________________________________________________\n");
    QUEX_NAME(Buffer_print_content_detailed_lines)(&iterator, me->_memory._front,      total_end, me);
    QUEX_NAME(Buffer_print_content_detailed_lines)(&iterator, me->_lexeme_start_p - 2, total_end, me);
    QUEX_NAME(Buffer_print_content_detailed_lines)(&iterator, me->_read_p        - 2, total_end, me);
    if( me->input.end_p != 0x0 ) {
        QUEX_NAME(Buffer_print_content_detailed_lines)(&iterator, me->input.end_p - 4, total_end, me);
    }
    QUEX_NAME(Buffer_print_content_detailed_lines)(&iterator, me->_memory._back   - 4, total_end, me);
    __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, "_________________________________________________________________\n");
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
        __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, "                                           ...\n");
    } else if( *iterator >= end ) {
        return;
    }

    for(; *iterator < end; ++*iterator) {
        length = 0;
        __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, "   ");

        if( *iterator == buffer->_memory._front ) {
            __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, "buffer front");
            length += 12;
        }
        if( *iterator == buffer->_lexeme_start_p ) {
            if( length ) { __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, ", "); length += 2; }
            __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, "lexeme start");
            length += 12;
        }
        if( *iterator == buffer->_read_p ) {
            if( length ) { __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, ", "); length += 2; }
            __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, "input");
            length += 5;
        }
        if( *iterator == buffer->input.end_p ) {
            if( length ) { __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, ", "); length += 2; }
            __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, "end of file");
            length += 11;
        }
        if( *iterator == buffer->_memory._back ) {
            if( length ) { __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, ", "); length += 2; }
            __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, "buffer back");
            length += 11;
        }
        if( length ) {
            for(; length < 39; ++length)
                __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, "-");
            __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, ">");
        } else {
            __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, "                                        ");
        }

        /* Print the character information */
        __QUEX_STD_fprintf(QUEX_SETTING_DEBUG_OUTPUT_CHANNEL, "[%04X] 0x%04X\n", 
                           (int)(*iterator - buffer->_memory._front),
                           (int)(**iterator));
    }
}

QUEX_INLINE void
QUEX_NAME(Buffer_print_overflow_message)(QUEX_NAME(Buffer)* me)
{
    (void)me; 
#   ifdef QUEX_OPTION_INFORMATIVE_BUFFER_OVERFLOW_MESSAGE
    uint8_t                   utf8_encoded_str[512]; 
    char                      message[1024];
    char*                     it         = &message[0];
    const char*               MessageEnd = &message[1024];
    uint8_t*                  WEnd       = 0x0;
    uint8_t*                  witerator  = 0x0;
    QUEX_TYPE_LEXATOM*        End        = 0x0;
    const QUEX_TYPE_LEXATOM*  iterator   = 0x0;

    /* Print out the lexeme start, so that the user has a hint. */
    WEnd        = utf8_encoded_str + 512 - 7;
    witerator   = utf8_encoded_str; 
    End         = me->_memory._back; 
    iterator    = me->_lexeme_start_p; 

    QUEX_CONVERTER_STRING(QUEX_SETTING_CHARACTER_CODEC, utf8)(&iterator, End, &witerator, WEnd);

    /* No use of 'snprintf()' because not all systems seem to support it propperly. */
    it += __QUEX_STD_strlcpy(it, 
              "Distance between lexeme start and current pointer exceeds buffer size.\n"
              "(tried to load buffer",
              MessageEnd - it);
    it += __QUEX_STD_strlcpy(it, "forward)", MessageEnd - it);
    it += __QUEX_STD_strlcpy(it, "As a hint consider the beginning of the lexeme:\n[[", 
                             MessageEnd - it);
    it += __QUEX_STD_strlcpy(it, (char*)utf8_encoded_str, MessageEnd - it);
    it += __QUEX_STD_strlcpy(it, "]]\n", MessageEnd - it);

    QUEX_ERROR_EXIT(message);
#   else
    QUEX_ERROR_EXIT("Distance between lexeme start and current pointer exceeds buffer size.\n"
                    "(tried to load buffer forward). Please, compile with option\n\n"
                    "    QUEX_OPTION_INFORMATIVE_BUFFER_OVERFLOW_MESSAGE\n\n"
                    "in order to get a more informative output. Most likely, one of your patterns\n"
                    "eats more than you intended. Alternatively you might want to set the buffer\n"
                    "size to a greater value or use skippers (<skip: [ \\n\\t]> for example).\n");
#   endif /* QUEX_OPTION_INFORMATIVE_BUFFER_OVERFLOW_MESSAGE */
}

QUEX_NAMESPACE_MAIN_CLOSE

#endif /* __QUEX_INCLUDE_GUARD__BUFFER__BUFFER_PRINT_I */
