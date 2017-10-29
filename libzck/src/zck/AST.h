// -*- c++ -*-

#pragma once

#include "common.h"
#include <vector>
#include <Lexer-token>


_ZCK_NAMESPACE_BEGIN;


class AST {
public:
    using namespace quex;
    using vec_t = std::vector<AST*>;

    AST(AST* pParent = nullptr) : _pParent(pParent) { }
    AST(Token const& tok, AST* pParent = nullptr) : _tok(tok), _pParent(pParent) { }

    Token&       token()       noexcept { return _tok; }
    Token const& token() const noexcept { return _tok; }

    vec_t&       children()       noexcept { return _children; }
    vec_t const& children() const noexcept { return _children; }

    AST*       parent()       noexcept { return _pParent; }
    AST const* parent() const noexcept { return _pParent; }
    void       parent(AST* pNewParent) noexcept { _pParent = pNewParent; }

    AST* add_child(AST* pNode) { _children.push_back(pNode); pNode->parent(this); return pNode; }

    auto       operator[](size_t i)       noexcept { return _children[i]; }
    auto const operator[](size_t i) const noexcept { return _children[i]; }

    auto size()  const noexcept { return _children.size(); }
    auto empty() const noexcept { return size() == 0; }
    auto begin()       noexcept { return _vec.begin(); }
    auto end()         noexcept { return _vec.end(); }
    auto begin() const noexcept { return _vec.cbegin(); }
    auto end()   const noexcept { return _vec.cend(); }

private:
    Token _tok;
    vec_t _children;
    AST*  _pParent;
};


_ZCK_NAMESPACE_END;
