// -*- c++ -*-

#ifndef _INCLUDE_GUARD_ZCK_COMMON_H_
#define _INCLUDE_GUARD_ZCK_COMMON_H_


#include <cstdint>
#include <cassert>
#include <cstring>
#include <ostream>
#include <memory>


#define _ZCK_NAMESPACE_BEGIN namespace zck {
#define _ZCK_NAMESPACE_END }

#ifndef SIZE_MAX
#define SIZE_MAX (~(size_t)0)
#endif


_ZCK_NAMESPACE_BEGIN;


//using uptr = std::unique_ptr;
typedef unsigned int uint; // would be 'using' but this is usually already a typedef


/* mdh_strncpy
 *
 * copy not more than `length` characters from the string `src` (including any NULL terminator) to the string `dst`
 * while never overflowing the `dst_sz` memory available to `dst`. return value: actual amount of characters copied.
 *
 * precondition: `length <= strlen(src)`; we do not check the actual length ourselves for performance reasons.
 * precondition: `dst_sz` is the max size of the memory for `dst` (not max length but max length + null terminator)
 * precondition: the memory backing `src` and `dst` may not overlap; if it does, UNDEFINED BEHAVIOR! CHAOS! SIN!
 *
 * 1. `dst` is always NULL-terminated when done (unlike strncpy)
 * 2. performance of the bounded copy should be virtually as good as you can get.
 * --> `dst` will never be unnecessarily padded with O(N) NULLs in a lot of cases (unlike strncpy)
 * --> memcpy is intensively optimized for non-overlapping block memory transfer (SIMD, etc.)
 *
 * motivation for creation: strncpy is practically obsolete and broken -- but it's also slow due to a poor POSIX
 * standardization choice, sprintf and similar are also slower, and of course, strcpy can overflow its output buffer.
 */
static inline size_t mdh_strncpy(char* dst, size_t dst_sz, const char* src, size_t length) {
    size_t n = (length > dst_sz) ? dst_sz : length;
    memcpy(dst, src, n);
    dst[n] = '\0'; // only sometimes necessary (when not using as a replacement for strcpy on well-formed input)
    return n;
}


_ZCK_NAMESPACE_END;


#endif // _INCLUDE_GUARD_ZCK_COMMON_H_
