// -*- c++ -*-

#pragma once

#include "common.h"

#include "AST.h"
#include "FileLocation.h"
#include "ErrorQueue.h"
#include "Exception.h"

#include <Lexer>


_ZCK_NAMESPACE_BEGIN;


using namespace ::quex;
using token_id_t = QUEX_TYPE_TOKEN_ID;

class Parser;
// using node_t = AST<Parser>;


class Parser {
public:
    /* all parsing of this file will be done upon this object's construction, but the Parser object is also a context
     * for the parse results afterward. once this Parser is destroyed, so will all of the memory allocated for the parse
     * and other such things (e.g., the associated error/warning queue). thus, manage the object's lifetime with care
     * when you're referencing any memory directly from the consequent AST externally. */
    Parser(char const* file_path);

    char const* path() const noexcept { return _path; }

    AST const* root() const     noexcept { return _pRoot; }
    AST*       root()           noexcept { return _pRoot; }
    void       root(AST* pTree) noexcept { _pRoot = pTree; }

    ErrorQueue const& error_queue() const noexcept { return _errors; }
    ErrorQueue&       error_queue()       noexcept { return _errors; }

    /* TM_: Token Mask (token type grouping) */

    static const token_id_t TM_LIST_SCOPE   = (1<<13);
    static const token_id_t TM_KEYWORD      = (1<<12);
    static const token_id_t TM_VAL          = (1<<11);
    static const token_id_t TM_OP           = (1<<10);
    static const token_id_t TM_META         = (1<<9);
    static const token_id_t TM_EMPTY        = (1<<8);

protected:
    /* persistent state (i.e., still relevant/required after Parser construction) */
    AST*        _pRoot;
    ErrorQueue  _errors;
    char const* _path;

    /* transient state only used while constructing object (i.e., parsing a file) */
    Lexer  _lex;
    Token* _pTok; // lookahead token

    auto const& peek() { return *_pTok; }

    /* just a handy helper method for error handling */
    auto token_loc() { return FLoc(_path, peek().line_number(), peek().column_number()); }

    /* helper for creating new meta-tokens */
    auto make_token(token_id_t id, size_t line = 0, size_t col = 0) {
        Token t;
        t.set(id);
        t.set_line_number(line);
        t.set_column_number(col);
        return t;
    }

    /* fundamental helper methods for parsing */

    void advance() {
        _lex.receive(&_pTok);
        assert( _pTok != nullptr );

        if (peek().type_id() == T_FAILURE)
            throw VParseException(token_loc(), "Failed to recognize token '%s'", _pTok->text);
    }

    void match(token_id_t t) {
        if (peek().type_id() != t)
            throw VParseException(token_loc(), "Unexpected token (expected %s)", peek().map_id_to_name(t));
        advance();
    }

    void matchmask(token_id_t mask) {
        if ( (peek().type_id() & mask) == 0 )
            throw VParseException(token_loc(), "Unexpected token %s", peek().type_id_name());
        advance();
    }

    /* helpers for matching the lookahead token (w/o any consumption) */

    auto peek_match(token_id_t t) { return peek().type_id() == t; }

    auto peek_matchmask(token_id_t mask) { return (peek().type_id() & mask); }

    /* versions which save the lookahead token into an AST node */

    auto advance_and_save() { auto p = new AST(peek()); advance(); return p; }

    auto match_and_save(token_id_t t) { auto p = new AST(peek()); match(t); return p; }

    auto matchmask_and_save(token_id_t mask) { auto p = new AST(peek()); matchmask(mask); return p; }

    /* methods corresponding to grammar rules */

    void start() {
        _pRoot = new AST( make_token(T_LIST) );
        rule_Block(_pRoot);
        match(T_TERMINATION);
    }

    void rule_StmtVal(AST* pRoot) {
        if (peek_match(T_IF)) {
            auto pIf = pRoot->add_child( advance_and_save() );
            rule_IfBody(pIf);
        }
        else if (peek_matchmask(TM_LIST_SCOPE) || peek_match(T_WHILE)) {
            auto pNode = pRoot->add_child( advance_and_save() );
            rule_LoopBody(pNode);
        }
        else if (peek_matchmask(TM_VAL)) {
            auto pVal = advance_and_save();
            if (peek_matchmask(TM_OP) || peek_match(T_L_BRACE))
                rule_StmtCont(pRoot, pVal);
        }
        else {
            auto pList = pRoot->add_child(new AST( make_token(T_LIST, peek().line_number(), peek().column_number()) ));
            rule_List(pList);
        }
    }

    void rule_StmtCont(AST* pRoot, AST* pLHS) {
        if (peek_matchmask(TM_OP)) {
            auto pOp = pRoot->add_child( advance_and_save());
            pOp->add_child(pLHS);
            rule_StmtRHS(pOp);
        }
        else {
            auto pOp = pRoot->add_child(new AST( make_token(T_OP_EQ, peek().line_number(), peek().column_number()) ));
            pOp->add_child(pLHS);
            auto pList = pOp->add_child(new AST( make_token(T_LIST, peek().line_number(), peek().column_number()) ));
            rule_List(pList);
        }
    }

    void rule_StmtRHS(AST* pRoot) {
        if (peek_matchmask(TM_VAL))
            pRoot->add_child( advance_and_save() );
        else {
            auto pList = pRoot->add_child(new AST( make_token(T_LIST, peek().line_number(), peek().column_number()) ));
            rule_List(pList);
        }
    }

    void rule_IfBody(AST* pRoot) {
        if (peek_match(T_OP_EQ)) advance();

        auto pList = pRoot->add_child(new AST( make_token(T_LIST, peek().line_number(), peek().column_number()) ));
        rule_List(pList);

        if (peek_match(T_THEN)) {
            advance();
            auto pList2 = pRoot->add_child(new AST( make_token(T_LIST, peek().line_number(), peek().column_number()) ));
            rule_List(pList2);
        }

        while (peek_match(T_ELSIF))
            rule_ElsIf(pRoot->parent());
    }

    void rule_LoopBody(AST* pRoot) {
        if (peek_match(T_OP_EQ)) advance();

        auto pList = pRoot->add_child(new AST( make_token(T_LIST, peek().line_number(), peek().column_number()) ));
        rule_List(pList);

        if (peek_match(T_DO)) {
            advance();
            auto pList2 = pRoot->add_child(new AST( make_token(T_LIST, peek().line_number(), peek().column_number()) ));
            rule_List(pList2);
        }
    }

    void rule_ElsIf(AST* pRoot) {
        auto pElsIf = pRoot->add_child( match_and_save(T_ELSIF) );
        rule_IfBody(pElsIf);
    }

    void rule_List(AST* pRoot) {
        match(T_L_BRACE);
        rule_Block(pRoot);
        match(T_R_BRACE);
    }

    void rule_Block(AST* pRoot) {
        while (peek_matchmask(TM_VAL) ||
               peek_matchmask(TM_LIST_SCOPE) ||
               peek_match(T_L_BRACE) ||
               peek_match(T_IF) ||
               peek_match(T_WHILE)) rule_StmtVal(pRoot);
    }
};


_ZCK_NAMESPACE_END;
