/* -*- C++ -*- vim:set syntax=cpp:
 * (C) 2005-2010 Frank-Rene Schaefer
 * ABSOLUTELY NO WARRANTY                      */
#ifndef __QUEX_INCLUDE_GUARD__ANALYZER__HEADERS_I
#define __QUEX_INCLUDE_GUARD__ANALYZER__HEADERS_I

#if ! defined(__QUEX_INCLUDE_INDICATOR__ANALYZER__CONFIGURATION)
#   error "No configuration header included before this header."
#endif

/* NOT: "#include    <quex/code_base/lexeme.i>"
 *
 * Converters and helpers of 'lexeme.i' are only to be included from inside the
 * token class header.  Otherwise, it may occur multiple times when same token
 * class is used for multiple lexical analyzers.                              */

#include    <quex/code_base/analyzer/asserts.i>
#include    <quex/code_base/buffer/asserts.i>

/* Token sending happens only via macros, for flexibility. */
#include    <quex/code_base/analyzer/member/token-receiving.i>
#include    <quex/code_base/analyzer/member/mode-handling.i>
#include    <quex/code_base/analyzer/member/misc.i>
#include    <quex/code_base/analyzer/member/navigation.i>
#include    <quex/code_base/analyzer/struct/constructor.i>
#include    <quex/code_base/analyzer/struct/reset.i>

#include    <quex/code_base/analyzer/Mode.i>
#include    <quex/code_base/token/TokenQueue.i>

#include    <quex/code_base/buffer/Buffer.i>
#include    <quex/code_base/buffer/lexatoms/LexatomLoader.i>
#include    <quex/code_base/buffer/bytes/ByteLoader>

#ifdef      QUEX_OPTION_COUNTER
#   include <quex/code_base/analyzer/Counter.i>
#endif
#ifdef      QUEX_OPTION_INCLUDE_STACK
#   include <quex/code_base/analyzer/struct/include-stack.i>
#endif
#ifdef      QUEX_OPTION_INDENTATION_TRIGGER
#   include <quex/code_base/analyzer/member/on_indentation.i>
#endif

#endif /* __QUEX_INCLUDE_GUARD__ANALYZER__HEADERS_I */
