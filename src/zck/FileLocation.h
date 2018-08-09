// -*- c++ -*-

#pragma once
#include "common.h"


NAMESPACE_ZCK;


class FileLocation {
    size_t      _line_n;
    size_t      _column_n;
    const char* _pathname;

    // column index tracking will be added when we migrate from the flex scanner to a quex scanner; we could do it now,
    // but it's more of a PITA.
    // uint column;

public:

    FileLocation(const char* path = "", size_t line = 0, size_t column = 0)
        : _line_n(line), _column_n(column), _pathname(path) {}

    size_t      line()     const noexcept { return _line_n; }
    size_t      column()   const noexcept { return _column_n; }
    const char* pathname() const noexcept { return _pathname; }

    void line(size_t line)          noexcept { _line_n = line; }
    void column(size_t column)      noexcept { _column_n = column; }
    void pathname(const char* path) noexcept { _pathname = path; }
};


// since FileLocation is quite verbose for such a common thing to be passing around, we actually use this alias:

using FLoc = FileLocation;


NAMESPACE_ZCK_END;
