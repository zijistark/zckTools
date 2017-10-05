// -*- c++ -*-

#pragma once

#include "common.h"


_ZCK_NAMESPACE_BEGIN;


#include <vector>


class AST;

class ParseContext {
public:

    // TODO: constructor, interface to allocator & errors

private:
    AST* _pRoot;
    // TODO: memory pool (would be nice if it was compatible with STL allocator interface)
    // TODO: error/warning queue from parse
};


_ZCK_NAMESPACE_END;
