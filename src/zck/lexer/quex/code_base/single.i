/* This file does:
 *
 * (1) QUEX_OPTION_MULTI is defined => Do nothing!
 *
 * (2) Is is not defined => 'single analyzer mode'. That is, the application
 *     is only linked to one quex-generated analyzer.
 * 
 * There are parts of the code which are the same for all quex-generated 
 * analyzers. Those are included with the analyzer engine, if the engine is 
 * the only one generated by quex. They are included manually by the user
 * if there are multiple engines.
 *
 * Single mode: 'quex/code_base/Single.i' is included along with the generated
 *              engine.
 *              QUEX_OPTION_MULTI is NOT defined.
 *
 * Multiple analyzer mode: The user includes 'quex/code_base/multi.i' in one of
 *                         his files.
 *              QUEX_OPTION_MULTI IS defined.
 *
 * (C) Frank-Rene Schaefer                                                   */

#if ! defined(QUEX_OPTION_MULTI)
#ifndef __QUEX_INCLUDE_GUARD__SINGLE_I
#define __QUEX_INCLUDE_GUARD__SINGLE_I
#   define  QUEX_OPTION_MULTI_ALLOW_IMPLEMENTATION
#   include <quex/code_base/multi.i>
#   undef   QUEX_OPTION_MULTI_ALLOW_IMPLEMENTATION
#endif /* __QUEX_INCLUDE_GUARD__SINGLE_I */
#endif
