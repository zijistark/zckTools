// -*- c++ -*-

#pragma once

#include "common.h"
#include <string.h>
#include <stdlib.h>
#include <memory>
#include <vector>
#include <Lexer>


NAMESPACE_ZCK;


using namespace ::quex;


class AST {
public:
    using vec_t = std::vector<AST*>;

    AST(AST* pParent = nullptr) : _pParent(nullptr) {
        if (pParent) pParent->add_child(this);
    }

    AST(const Token& otherTok, AST* pParent = nullptr) : _pParent(nullptr) {
        QUEX_NAME_TOKEN(copy)(&_tok, &otherTok);
        if (pParent) pParent->add_child(this);
    }

    // AST(QUEX_TYPE_TOKEN_ID token_id, const char* text, size_t line = 0, size_t column = 0)
    //     : _tok(token_id, text, 0) {
    //     _tok.set_line_number(line);
    //     _tok.set_column_number(column);
    // }

    Token&       token()       noexcept { return _tok; }
    const Token& token() const noexcept { return _tok; }

    vec_t&       children()       noexcept { return _children; }
    vec_t const& children() const noexcept { return _children; }

    AST*       parent()       noexcept { return _pParent; }
    const AST* parent() const noexcept { return _pParent; }
    void       parent(AST* pNewParent) noexcept { _pParent = pNewParent; }

    AST* add_child(AST* pNode) { _children.push_back(pNode); pNode->parent(this); return pNode; }

private:
    Token _tok;
    vec_t _children;
    AST*  _pParent;
};


NAMESPACE_ZCK_END;
