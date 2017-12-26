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
    static const token_id_t TM_VAL = (1<<11);
    static const token_id_t TM_OP  = (1<<10);

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
            throw VParseException(token_loc(), "Unexpected token %s (expected %s)",
                                  peek().type_id_name(), peek().map_id_to_name(t));
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
        _pRoot = new AST( make_token(T_STMT_LIST) );

        while (peek_matchmask(TM_VAL))
            rule_Stmt(_pRoot);

        match(T_TERMINATION);
    }

    void rule_Stmt(AST* pRoot) {
        auto pLHS = matchmask_and_save(TM_VAL);
        auto pOp = pRoot->add_child( matchmask_and_save(TM_OP) );
        pOp->add_child(pLHS);
        rule_StmtRHS(pOp);
    }

    void rule_StmtRHS(AST* pRoot) {
        if (peek_match(T_OPEN_BRACE)) {
            /* save away line and column number of open brace for stamping *_LIST pseudo-tokens with it */
            auto nLine = peek().line_number();
            auto nCol = peek().column_number();
            advance();
            rule_ListOpen(pRoot, nLine, nCol);
        }
        else // terminal scalar
            pRoot->add_child( matchmask_and_save(TM_VAL) );
    }

    void rule_ListOpen(AST* pRoot, size_t nStartLine, size_t nStartCol) {
        if (peek_match(T_CLOSE_BRACE)) {
            pRoot->add_child( new AST( make_token(T_EMPTY_LIST, nStartLine, nStartCol) ) );
            advance();
        }
        else if (peek_matchmask(TM_VAL)) {
            /* save away the lookahead token so that rule_ListEnd() can use it when finally constructing AST node */
            auto pFirstNode = advance_and_save();
            rule_ListEnd(pRoot, nStartLine, nStartCol, pFirstNode);
        }
        else { // recursing into another list of some type
            /* save away line and column number of open brace for stamping *_LIST pseudo-tokens with it */
            auto nLine = peek().line_number();
            auto nCol = peek().column_number();
            match(T_OPEN_BRACE);
            rule_ListOpen(pRoot, nLine, nCol);
        }
    }

    void rule_ListEnd(AST* pRoot, size_t nStartLine, size_t nStartCol, AST* pFirstNode) {
        if (peek_matchmask(TM_OP)) {
            auto pStmtList = new AST( make_token(T_STMT_LIST, nStartLine, nStartCol), pRoot );
            pStmtList->add_child(pFirstNode);
            auto pOp = pStmtList->add_child( advance_and_save() );
            rule_StmtRHS(pOp);

            while (peek_matchmask(TM_VAL))
                rule_Stmt(pStmtList);
        }
        else { // scalar value list
            auto pValueList = new AST( make_token(T_VAL_LIST, nStartLine, nStartCol), pRoot );
            pValueList->add_child(pFirstNode);

            while (peek_matchmask(TM_VAL))
                pValueList->add_child( advance_and_save() );
        }

        match(T_CLOSE_BRACE);
    }
};


_ZCK_NAMESPACE_END;
