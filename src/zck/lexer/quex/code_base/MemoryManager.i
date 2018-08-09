/* -*- C++ -*- vim: set syntax=cpp: */

/* This file contains an implementation which can potentially be shared between
 * multiple different lexical analyzers. See 'multi.i' for further info.     */

#ifndef __QUEX_INCLUDE_GUARD__MEMORY_MANAGER_I
#define __QUEX_INCLUDE_GUARD__MEMORY_MANAGER_I

#include <quex/code_base/definitions>
#include <quex/code_base/MemoryManager>

QUEX_NAMESPACE_QUEX_OPEN

uint8_t*
QUEXED_DEF(MemoryManager_allocate)(const size_t       ByteN, 
                                   E_MemoryObjectType Type)
{
    uint8_t* me = 0;
#   ifdef __cplusplus
    try                   { me = new uint8_t[ByteN]; } 
    catch(std::bad_alloc) { return (uint8_t*)0; }
#   else
    me = (uint8_t*)__QUEX_STD_malloc(ByteN);
#   endif

    (void)Type;
#   ifdef QUEX_OPTION_ASSERTS
    __QUEX_STD_memset((void*)me, 0xFF, ByteN);
#   endif
    return me;
}
       
void 
QUEXED_DEF(MemoryManager_free)(void*              alter_ego, 
                               E_MemoryObjectType Type)  
{ 
    (void)Type;
    /* The de-allocator shall never be called for LexemeNull object.         */
    if( ! alter_ego ) return;
#   ifdef __cplusplus
    uint8_t* me = (uint8_t*)alter_ego;
    delete [] me;
#   else
    void* me = (void*)alter_ego;
    __QUEX_STD_free(me); 
#   endif
}

size_t
QUEXED_DEF(MemoryManager_insert)(uint8_t* drain_begin_p,  uint8_t* drain_end_p,
                                 uint8_t* source_begin_p, uint8_t* source_end_p)
/* Inserts as many bytes as possible into the array from 'drain_begin_p'
 * to 'drain_end_p'. The source of bytes starts at 'source_begin_p' and
 * ends at 'source_end_p'.
 *
 * RETURNS: Number of bytes that have been copied.                           */
{
    /* Determine the insertion size.                                         */
    const size_t DrainSize = (size_t)(drain_end_p  - drain_begin_p);
    size_t       size      = (size_t)(source_end_p - source_begin_p);
    __quex_assert(drain_end_p  >= drain_begin_p);
    __quex_assert(source_end_p >= source_begin_p);

    if( DrainSize < size ) size = DrainSize;

    /* memcpy() might fail if the source and drain domain overlap! */
#   ifdef QUEX_OPTION_ASSERTS 
    if( drain_begin_p > source_begin_p ) __quex_assert(drain_begin_p >= source_begin_p + size);
    else                                 __quex_assert(drain_begin_p <= source_begin_p - size);
#   endif
    __QUEX_STD_memcpy(drain_begin_p, source_begin_p, size);

    return size;
}

char*
QUEXED_DEF(MemoryManager_clone_string)(const char* String)
{ 
    char* result;
   
    if( ! String ) {
        return (char*)0;
    }
   
    result = (char*)QUEXED(MemoryManager_allocate)(
                                 sizeof(char)*(__QUEX_STD_strlen(String)+1),
                                 E_MemoryObjectType_INPUT_NAME);
    if( ! result ) {
        return (char*)0;
    }
    __QUEX_STD_strcpy(result, String);
    return result;
}

bool 
QUEXED_DEF(system_is_little_endian)(void)
{
    union {
        long int multi_bytes;
        char     c[sizeof (long int)];
    } u;
    u.multi_bytes = 1;
    return u.c[sizeof(long int)-1] != 1;
}

void
QUEXED_DEF(print_relative_positions)(const void*  Begin,       const void* End, 
                                     size_t       ElementSize, const void* P)
/* Begin       = pointer to first element of buffer.
 * End         = pointer behind last element of buffer.
 * ElementSize = size in bytes of each element of buffer.
 * P           = pointer for which relative position is to be printed.        */
{
    const uint8_t* BytePBegin = (const uint8_t*)Begin;
    const uint8_t* BytePEnd   = (const uint8_t*)End;
    const uint8_t* ByteP      = (const uint8_t*)P;

    if( P == 0x0 ) {
        __QUEX_STD_printf("<void>;");
    }
    else if( P < Begin ) {
        __QUEX_STD_printf("begin - %i <beyond boarder>;", 
                          (int)(BytePBegin - ByteP) / (int)ElementSize);
    }
    else if( P >= End ) {
        __QUEX_STD_printf("end + %i <beyond boarder>;", 
                          (int)(ByteP - BytePEnd) / (int)ElementSize);
    }
    else {
        __QUEX_STD_printf("begin + %i, end - %i;", 
                          (int)(ByteP - BytePBegin) / (int)ElementSize, 
                          (int)(BytePEnd - ByteP) / (int)ElementSize);
    }
}

ptrdiff_t
QUEXED_DEF(strlcpy)(char* dst, const char* src, size_t siz)
{
    /* Copy src to string dst of size siz.  At most siz-1 characters
     * will be copied.  Always NUL terminates (unless siz == 0).
     *
     * RETURNS: strlen(src); if retval >= siz, truncation occurred.           
     *
     * Original 'strlcpy' returns 'size_t', however 'ptrdiff_t' is fitter for
     * pointer arithmetic
     *
     * 'strlcpy()' is copied from BSD sources since it is not part of the 
     * standard C library. The following copyright/license notice concerns only 
     * the body of this function:
     *_________________________________________________________________________
     * Copyright (c) 1998 Todd C. Miller <Todd.Miller@courtesan.com>          *
     * Permission to use, copy, modify, and distribute this software for any  *
     * purpose with or without fee is hereby granted, provided that the above *
     * copyright notice and this permission notice appear in all copies.      *
     *________________________________________________________________________*/

    register char *d = dst;
    register const char *s = src;
    register size_t n = siz;

    /* Copy as many bytes as will fit */
    if (n != 0 && --n != 0) {
        do {
            if ((*d++ = *s++) == 0) break;
        } while (--n != 0);
    }

    /* Not enough room in dst, add NUL and traverse rest of src */
    if (n == 0) {
        if (siz != 0)
            *d = '\0';/* NUL-terminate dst */
        while (*s++);
    }

    return (s - src - 1);/* count does n ot include NUL */
}

QUEX_NAMESPACE_QUEX_CLOSE
 
#endif /*  __QUEX_INCLUDE_GUARD__MEMORY_MANAGER_I */


