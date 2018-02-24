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
    Parser(const char* file_path);

    const char* path() const noexcept { return _path; }

    const AST* root() const     noexcept { return _pRoot; }
    AST*       root()           noexcept { return _pRoot; }
    void       root(AST* pTree) noexcept { _pRoot = pTree; }

    const ErrorQueue& error_queue() const noexcept { return _errors; }
    ErrorQueue&       error_queue()       noexcept { return _errors; }

    /* TM_: Token Mask (token type grouping) */

    static const token_id_t TM_OP_ASSIGN    = (1<<14);
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
    const char* _path;

    /* transient state only used while constructing object (i.e., parsing a file) */
    Lexer  _lex;
    Token* _pTok; // lookahead token

    const auto& peek() { return *_pTok; }

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

    // TODO: add a version of match(token_id_t...) [templated variadic function] that will match any of the token IDs that
    // are passed to it. maybe we can also avoid directly using bitmask matching this way (assuming it can be made to compile
    // to similar instructions), so that, e.g., we actually do know the list of next expected token types if we're throwing a
    // parse exception when trying to match a token ID set via bitmask.

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
        rule_Block(_pRoot = new AST( make_token(T_LIST) ));
        match(T_TERMINATION);
    }

    void rule_StmtVal(AST* pRoot) {
        if (peek_match(T_IF))
            rule_IfBody(pRoot->add_child( advance_and_save() ));
        else if (peek_matchmask(TM_LIST_SCOPE) || peek_match(T_WHILE))
            rule_LoopBody(pRoot->add_child( advance_and_save() ));
        else if (peek_match(T_VAR_REF))
            rule_VRefRHS( pRoot, advance_and_save() );
        else if (peek_matchmask(TM_VAL)) {
            auto pVal = advance_and_save();
            if (peek_matchmask(TM_OP) || peek_match(T_L_BRACE))
                rule_StmtCont(pRoot, pVal);
            else
                pRoot->add_child(pVal);
        }
        else
            rule_List(pRoot->add_child(new AST( make_token(T_LIST, peek().line_number(), peek().column_number()) )));
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
            rule_List(pOp->add_child(new AST( make_token(T_LIST, peek().line_number(), peek().column_number()) )));
        }
    }

    void rule_StmtRHS(AST* pRoot) {
        if (peek_matchmask(TM_VAL))
            pRoot->add_child( advance_and_save() );
        else
            rule_List(pRoot->add_child(new AST( make_token(T_LIST, peek().line_number(), peek().column_number()) )));
    }

    void rule_IfBody(AST* pRoot) {
        if (peek_match(T_OP_EQ)) advance();

        rule_List(pRoot->add_child(new AST( make_token(T_LIST, peek().line_number(), peek().column_number()) )));

        if (peek_match(T_THEN)) {
            advance();
            rule_List(pRoot->add_child(new AST( make_token(T_LIST, peek().line_number(), peek().column_number()) )));
        }

        while (peek_match(T_ELSIF))
            rule_ElsIf(pRoot->parent());
    }

    void rule_LoopBody(AST* pRoot) {
        if (peek_match(T_OP_EQ)) advance();

        rule_List(pRoot->add_child(new AST( make_token(T_LIST, peek().line_number(), peek().column_number()) )));

        if (peek_match(T_DO)) {
            advance();
            rule_List(pRoot->add_child(new AST( make_token(T_LIST, peek().line_number(), peek().column_number()) )));
        }
    }

    void rule_ElsIf(AST* pRoot) {
        rule_IfBody(pRoot->add_child( match_and_save(T_ELSIF) ));
    }

    void rule_VRefRHS(AST* pRoot, AST* pLHS) {
        if (peek_matchmask(TM_OP_ASSIGN)) {
            auto pOp = pRoot->add_child( advance_and_save() );

            if (pOp->token().type_id() == T_OP_EQ)
                pOp->token().set(T_OP_ASSIGN);

            pOp->add_child(pLHS);

            if (peek_match(T_VAR_REF) || peek_match(T_INTEGER) || peek_match(T_DECIMAL) || peek_match(T_STRING))
                pOp->add_child( advance_and_save() );
            else
                throw VParseException(token_loc(), "Unexpected token (expected VAR_REF, INTEGER, DECIMAL, or STRING)");

            return;
        }

        /* variable comparison */

        auto pOp = pRoot->add_child( matchmask_and_save(TM_OP) );
        pOp->add_child(pLHS);

        if (peek_match(T_VAR_REF) || peek_match(T_INTEGER) || peek_match(T_DECIMAL))
            pOp->add_child( advance_and_save() );
        else
            throw VParseException(token_loc(), "Unexpected token (expected VAR_REF, INTEGER, or DECIMAL)");
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
