// -*- c++ -*-

#pragma once

#include "common.h"
#include "FileLocation.h"

#include <exception>
#include <stdexcept>
#include <cstdio>
#include <cstdarg>
#include <cstdlib>


NAMESPACE_ZCK;


class VException : public std::exception {
    char msg[1024];

public:
    VException() = delete;

    explicit VException(const char* format, ...) {
        va_list vl;
        va_start(vl, format);
        vsnprintf(&msg[0], sizeof(msg), format, vl);
        va_end(vl);
    }

    const char* what() const noexcept {
        return msg;
    }

    ~VException() noexcept {}
};


class ParseException : public std::exception {};


class VParseException : public ParseException {
    char msg[1024];

#if defined(__CYGWIN__) && !defined(_WIN32)
    /* Cygwin POSIX under Microsoft Windows. */
    #define SIZE_F "%lu"
    static_assert(sizeof(size_t) == sizeof(long unsigned int));
#else
    #define SIZE_F "%llu"
    static_assert(sizeof(size_t) == sizeof(long long unsigned int));
#endif
    static inline constexpr char const* SIZE_FMT = (sizeof(size_t) == sizeof(long long unsigned int)) ?
                                                    "%llu" : "%lu";

public:
    VParseException() = delete;

    explicit VParseException(const FLoc& fl, const char* format, ...) {
        auto buf_sz_left = sizeof(msg);
        va_list vl;
        va_start(vl, format);
        auto len = vsnprintf(&msg[0], buf_sz_left, format, vl);
        va_end(vl);

        assert(len >= 0);
        buf_sz_left -= len;

        snprintf(&msg[len], buf_sz_left, " in '%s' at line " SIZE_F ", column " SIZE_F, fl.pathname(), fl.line(), fl.column());
    }

    const char* what() const noexcept {
        return msg;
    }

    ~VParseException() noexcept {}

#undef SIZE_F
};


NAMESPACE_ZCK_END;
