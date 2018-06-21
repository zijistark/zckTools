/* -*- C++ -*- vim: set syntax=cpp:
 * PURPOSE: Character converters towards 'char' and 'wchar_t'.
 *
 * Generate string converter functions which convert a string from one 
 * character codec into 'char' or 'wchar'. The conversion is implemented by
 * means of a character converter function given by:
 *
 *            QUEX_CONVERTER_CHAR(FROM, TO)(in, out); 
 *
 * which converts only a single character. The converter function must
 * be defined before the inclusion of this file. This file implements default
 * converters for char and wchar. So for 'char' utf8 us used for 'wchar' utf16
 * or utf32 are used depending on the system's settings.
 *
 * (C) 2010-2012 Frank-Rene Schaefer 
 * ABSOLUTELY NO WARRANTY                                                    */

#if   ! defined(__QUEX_FROM)
#   error      "__QUEX_FROM definition missing!"
#elif   defined(__QUEX_TO_TYPE) 
#   error      "__QUEX_TO_TYPE definition missing!"
#elif   defined(__QUEX_TO) 
#   error      "__QUEX_TO definition missing!"
#elif   defined(__QUEX_TO_CODEC)
#   error      "__QUEX_TO_CODEC definition missing!"
#endif

QUEX_INLINE void
QUEX_CONVERTER_CHAR_DEF(__QUEX_FROM, char)(const QUEX_TYPE_LEXATOM** source_pp, 
                                           char**                    drain_pp)  
{
    switch( sizeof(char) )
    {
    case 1:
        QUEX_CONVERTER_CHAR(__QUEX_FROM, utf8)(source_pp, (uint8_t**)drain_pp);
        break;
    case 2:
        QUEX_CONVERTER_CHAR(__QUEX_FROM, utf16)(source_pp, (uint16_t**)drain_pp);
        break;
    case 4:
        QUEX_CONVERTER_CHAR(__QUEX_FROM, utf32)(source_pp, (uint32_t**)drain_pp);
        break;
    default:
        __quex_assert(false); /* Cannot be handled */
    }
}

QUEX_INLINE void
QUEX_CONVERTER_CHAR_DEF(__QUEX_FROM, pretty_char)(const QUEX_TYPE_LEXATOM** source_pp, 
                                                  char**                    drain_pp)  
{
    char* write_p = *drain_pp;

    QUEX_CONVERTER_CHAR(__QUEX_FROM,char)(source_pp, drain_pp);
   
    switch( *write_p ) { 
    case (int)'\n': *write_p++ = (char)'\\'; *write_p = (char)'n'; break;
    case (int)'\t': *write_p++ = (char)'\\'; *write_p = (char)'t'; break;
    case (int)'\r': *write_p++ = (char)'\\'; *write_p = (char)'r'; break;
    case (int)'\a': *write_p++ = (char)'\\'; *write_p = (char)'a'; break;
    case (int)'\b': *write_p++ = (char)'\\'; *write_p = (char)'b'; break;
    case (int)'\f': *write_p++ = (char)'\\'; *write_p = (char)'f'; break;
    case (int)'\v': *write_p++ = (char)'\\'; *write_p = (char)'v'; break;
    default: /* 'drain_pp' has been adapted by converter!       */ return;
    }
    /* 'drain_pp' is set to the post-adapted position.          */
    *drain_pp = &write_p[1];
}


#if ! defined(__QUEX_OPTION_WCHAR_T_DISABLED)
    QUEX_INLINE void
    QUEX_CONVERTER_CHAR_DEF(__QUEX_FROM, wchar)(const QUEX_TYPE_LEXATOM** source_pp, 
                                                wchar_t**                 drain_pp)  
    {
        switch( sizeof(wchar_t) )
        {
        case 1:
            QUEX_CONVERTER_CHAR(__QUEX_FROM, utf8)(source_pp, (uint8_t**)drain_pp);
            break;
        case 2:
            QUEX_CONVERTER_CHAR(__QUEX_FROM, utf16)(source_pp, (uint16_t**)drain_pp);
            break;
        case 4:
            QUEX_CONVERTER_CHAR(__QUEX_FROM, utf32)(source_pp, (uint32_t**)drain_pp);
            break;
        default:
            __quex_assert(false); /* Cannot be handled */
        }
    }
#endif

