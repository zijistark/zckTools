// -*- c++ -*-

#pragma once

#include "common.h"
#include <vector>


_ZCK_NAMESPACE_BEGIN;


class AST {
public:
    using namespace quex;
    using children_t = std::vector<AST*>;

    Token&       token()       noexcept { return _tok; }
    Token const& token() const noexcept { return _tok; }

    children_t&       children()       noexcept { return _children; }
    children_t const& children() const noexcept { return _children; }

private:
    Token _tok;
    children_t _children;
};


_ZCK_NAMESPACE_END;