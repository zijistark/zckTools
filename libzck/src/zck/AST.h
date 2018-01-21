// -*- c++ -*-

#pragma once

#include "common.h"
#include <string.h>
#include <stdlib.h>
#include <memory>
#include <vector>
#include <Lexer>


_ZCK_NAMESPACE_BEGIN;


using namespace ::quex;


class AST {
public:
    using vec_t = std::vector<AST*>;

    AST(AST* pParent = nullptr) {
        if (pParent) pParent->add_child(this);
    }

    AST(Token const& otherTok, AST* pParent = nullptr) {
        QUEX_NAME_TOKEN(copy)(&_tok, &otherTok);
        if (pParent) pParent->add_child(this);
    }

    Token&       token()       noexcept { return _tok; }
    Token const& token() const noexcept { return _tok; }

    vec_t&       children()       noexcept { return _children; }
    vec_t const& children() const noexcept { return _children; }

    AST*       parent()       noexcept { return _pParent; }
    AST const* parent() const noexcept { return _pParent; }
    void       parent(AST* pNewParent) noexcept { _pParent = pNewParent; }

    AST* add_child(AST* pNode) { _children.push_back(pNode); pNode->parent(this); return pNode; }

private:
    Token _tok;
    vec_t _children;
    AST*  _pParent;
};


_ZCK_NAMESPACE_END;
