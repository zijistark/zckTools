// -*- c++ -*-

#pragma once

#include "common.h"


_ZCK_NAMESPACE_BEGIN;

#include "ErrorQueue.h"
#include <vector>
#include <string>


class AST;
class Parser;

class ParseContext {
public:

    // TODO: constructor, interface to allocator & errors

    AST const* root() const noexcept { return _pRoot; }
    AST*       root()       noexcept { return _pRoot; }

    void set_root(AST* pNode) noexcept { _pRoot = pNode; }

    ErrorQueue const& error_queue() const noexcept { return _errors; }
    ErrorQueue&       error_queue()       noexcept { return _errors; }

    std::string const& path() const noexcept { return _path; }
    std::string&       path()       noexcept { return _path; }

protected:
    friend class Parser;
    ParseContext() : _pRoot(nullptr) { }
    ParseContext(const std::string& path) : _pRoot(nullptr), _path(path) { }

    AST* _pRoot;
    ErrorQueue _errors;
    std::string _path; // not using boost::filesystem::path here to keep the Boost libraries decoupled from libzck
    /* TODO: memory pool (would be nice if it was compatible with STL allocator interface so that ALL memory allocation
     * for the parse can be pooled together) */
};


_ZCK_NAMESPACE_END;
