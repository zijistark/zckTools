// -*- c++ -*-

#pragma once

#include "common.h"


_ZCK_NAMESPACE_BEGIN;


#include <vector>


class AST {
public:
    using namespace quex;
    using child_vec_t = std::vector<AST*>;

    Token&       token()       noexcept { return _tok; }
    Token const& token() const noexcept { return _tok; }

    child_vec_t&       children()       noexcept { return _children; }
    child_vec_t const& children() const noexcept { return _children; }

private:
    Token _tok;
    child_vec_t _children;
};


_ZCK_NAMESPACE_END;
