/* -*- C++ -*- vim: set syntax=cpp: */
#ifndef __QUEX_INCLUDE_GUARD__BUFFER__ASSERTS_I
#define __QUEX_INCLUDE_GUARD__BUFFER__ASSERTS_I

#ifndef QUEX_OPTION_ASSERTS

#else

QUEX_NAMESPACE_MAIN_OPEN

QUEX_INLINE void
QUEX_NAME(BUFFER_ASSERT_pointers_in_range_core)(QUEX_NAME(Buffer)* B)                                      
/* Check whether _read_p and _lexeme_start_p are in ther appropriate range. */
{                                                                                    
    __quex_assert( (B) != 0x0 );                                                     
    if( ! (*B)._memory._front && ! (*B)._memory._back ) {                    
        return;
    }

    __quex_assert((*B)._memory._front      <  (*B)._memory._back);                     
    __quex_assert((*B)._read_p             >= (*B)._memory._front);                
    __quex_assert((*B)._lexeme_start_p     >= (*B)._memory._front);                

    __quex_assert((*B).input.end_p     >= (*B)._memory._front + 1);          
    __quex_assert((*B).input.end_p     <= (*B)._memory._back);               

    __quex_assert((*B)._read_p         <= (*B).input.end_p);              
    __quex_assert((*B)._lexeme_start_p <= (*B).input.end_p);              
}

QUEX_INLINE void
QUEX_NAME(BUFFER_ASSERT_limit_codes_in_place_core)(QUEX_NAME(Buffer)* B)                                            
{
    if( ! (*B)._memory._front && ! (*B)._memory._back ) {                    
        return;
    }
    __quex_assert(*((*B)._memory._front) == QUEX_SETTING_BUFFER_LIMIT_CODE);    
    __quex_assert(*((*B)._memory._back)  == QUEX_SETTING_BUFFER_LIMIT_CODE);    
    __quex_assert(*(*B).input.end_p      == QUEX_SETTING_BUFFER_LIMIT_CODE);   
}

QUEX_INLINE void
QUEX_NAME(BUFFER_ASSERT_CONSISTENCY_core)(QUEX_NAME(Buffer)* B)                                            
{                                                                                    
    if( ! B ) return;
    __quex_assert(   B->input.lexatom_index_begin == -1
                  || B->input.lexatom_index_begin >= 0);
    __quex_assert(   B->input.lexatom_index_end_of_stream == -1 
                  || B->input.lexatom_index_end_of_stream >= B->input.lexatom_index_begin);
    QUEX_NAME(BUFFER_ASSERT_pointers_in_range_core)(B);                                              
    QUEX_NAME(BUFFER_ASSERT_limit_codes_in_place_core)(B);
}

QUEX_INLINE void
QUEX_NAME(BUFFER_ASSERT_NO_BUFFER_LIMIT_CODE_core)(const QUEX_TYPE_LEXATOM* Begin, 
                                                   const QUEX_TYPE_LEXATOM* End)
{
    const QUEX_TYPE_LEXATOM* iterator = 0x0;
    __quex_assert(Begin <= End);

    for(iterator = Begin; iterator != End; ++iterator) {
        if( *iterator != QUEX_SETTING_BUFFER_LIMIT_CODE ) continue;

        if( iterator == Begin ) {
            QUEX_ERROR_EXIT("Buffer limit code character appeared as first character in buffer.\n"
                            "This is most probably a load failure.\n");
        } else {
            QUEX_ERROR_EXIT("Buffer limit code character appeared as normal text content.\n");
        }
    }
}

QUEX_NAMESPACE_MAIN_CLOSE

#endif

#endif /* __QUEX_INCLUDE_GUARD__BUFFER__ASSERTS_I */

