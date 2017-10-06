// -*- c++ -*-

#pragma once
#include "common.h"


_ZCK_NAMESPACE_BEGIN;


class FileLocation {
    uint        _line;
    const char* _pathname;

    // column index tracking will be added when we migrate from the flex scanner to a quex scanner; we could do it now,
    // but it's more of a PITA.
    // uint column;

public:

    FileLocation(const char* path = "", uint line = 0) : _line(line), _pathname(path) {}

    uint        line()     const noexcept { return _line; }
    const char* pathname() const noexcept { return _pathname; }

    void line(uint line)            noexcept { _line = line; }
    void pathname(const char* path) noexcept { _pathname = path; }
};


// since FileLocation is quite verbose for such a common thing to be passing around, we actually use this alias:

using FLoc = FileLocation;


_ZCK_NAMESPACE_END;
