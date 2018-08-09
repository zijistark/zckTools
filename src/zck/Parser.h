// -*- c++ -*-

#pragma once

#include "common.h"

#include "AST.h"
#include "FileLocation.h"
#include "ErrorQueue.h"
#include "Exception.h"
#include "Tracer.h"

#include <Lexer>


NAMESPACE_ZCK;


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

    static const token_id_t TM_KW_EFFECT  = (1<<17);
    static const token_id_t TM_KW_TRIGGER = (1<<16);
    static const token_id_t TM_OP_EXPR    = (1<<15);
    static const token_id_t TM_OP_ASSIGN  = (1<<14);
    static const token_id_t TM_LIST_SCOPE = (1<<13);
    static const token_id_t TM_KEYWORD    = (1<<12);
    static const token_id_t TM_VAL        = (1<<11);
    static const token_id_t TM_OP         = (1<<10);
    static const token_id_t TM_META       = (1<<9);
    static const token_id_t TM_EMPTY      = (1<<8);

protected:
    /* persistent state (i.e., still relevant/required after Parser construction) */
    AST*        _pRoot;
    ErrorQueue  _errors;
    const char* _path;

    /* transient state only used while constructing object (i.e., parsing a file) */
    Lexer    _lex;
    Token*   _pTok; // lookahead token

    Tracer<false> _tracer;

    const auto& peek() { return *_pTok; }

    /* just a handy helper method for error handling */
    auto token_loc() { return FLoc(_path, peek().line_number(), peek().column_number()); }

    /* helper for creating new meta-tokens */
    auto make_token(token_id_t id, size_t line = 0, size_t col = 0) {
        Token t;
        t.set(id);
        t.set_line_number( (line) ? line : peek().line_number() );
        t.set_column_number( (col) ? col : peek().column_number() );
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
        _tracer.push("StmtVal //");

        if (peek_match(T_IF))
            rule_IfBody(pRoot->add_child( advance_and_save() ));
        else if (peek_matchmask(TM_LIST_SCOPE) || peek_match(T_WHILE))
            rule_LoopBody(pRoot->add_child( advance_and_save() ));
        else if (peek_match(T_IS_NULL)) {
            auto pTrigger = advance_and_save();

            if (!peek_match(T_OP_EQ) && !peek_match(T_OP_NEQ))
                throw VParseException(token_loc(), "Unexpected token after IS_NULL (expected OP_EQ or OP_NEQ)");

            auto pOp = pRoot->add_child( advance_and_save() );
            pOp->add_child(pTrigger);
            pOp->add_child( matchmask_and_save(TM_VAL) );
        }
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
            rule_List(pRoot->add_child( new AST(make_token(T_LIST)) ));

        _tracer.pop("// StmtVal");
    }

    void rule_StmtCont(AST* pRoot, AST* pLHS) {
        _tracer.push("StmtCont //");

        if (peek_matchmask(TM_OP)) {
            auto pOp = pRoot->add_child( advance_and_save() );
            pOp->add_child(pLHS);
            rule_StmtRHS(pOp);
        }
        else {
            auto pOp = pRoot->add_child( new AST(make_token(T_OP_EQ)) );
            pOp->add_child(pLHS);
            rule_List(pOp->add_child( new AST(make_token(T_LIST)) ));
        }

        _tracer.pop("// StmtCont");
    }

    void rule_StmtRHS(AST* pRoot) {
        _tracer.push("StmtRHS //");

        if (peek_matchmask(TM_VAL))
            pRoot->add_child( advance_and_save() );
        else
            rule_List(pRoot->add_child( new AST(make_token(T_LIST)) ));

        _tracer.pop("// StmtRHS");
    }

    void rule_IfBody(AST* pRoot) {
        _tracer.push("IfBody //");

        if (peek_match(T_OP_EQ)) advance();

        rule_List(pRoot->add_child( new AST(make_token(T_LIST)) ));

        if (peek_match(T_THEN)) {
            advance();
            rule_List(pRoot->add_child( new AST(make_token(T_LIST)) ));
        }

        while (peek_match(T_ELSIF))
            rule_ElsIf(pRoot->parent());

        _tracer.pop("// IfBody");
    }

    void rule_LoopBody(AST* pRoot) {
        _tracer.push("LoopBody //");

        if (peek_match(T_OP_EQ)) advance();

        rule_List(pRoot->add_child( new AST(make_token(T_LIST)) ));

        if (peek_match(T_DO)) {
            advance();
            rule_List(pRoot->add_child( new AST(make_token(T_LIST)) ));
        }

        _tracer.pop("// LoopBody");
    }

    void rule_ElsIf(AST* pRoot) {
        _tracer.push("ElsIf //");

        rule_IfBody(pRoot->add_child( match_and_save(T_ELSIF) ));

        _tracer.pop("// ElsIf");
    }

    void rule_VRefRHS(AST* pRoot, AST* pLHS) {
        _tracer.push("VRefRHS //");

        if (peek_matchmask(TM_OP_ASSIGN)) {
            auto pOp = pRoot->add_child( advance_and_save() );

            if (pOp->token().type_id() == T_OP_EQ)
                pOp->token().set(T_OP_ASSIGN);

            pOp->add_child(pLHS);
            pOp->add_child(rule_VExpr());
            return;
        }

        /* variable comparison */

        auto pOp = pRoot->add_child( matchmask_and_save(TM_OP) );
        pOp->add_child(pLHS);

        if (peek_match(T_VAR_REF) || peek_match(T_INTEGER) || peek_match(T_DECIMAL))
            pOp->add_child( advance_and_save() );
        else
            throw VParseException(token_loc(), "Unexpected token (expected VAR_REF, INTEGER, or DECIMAL)");

        _tracer.pop("// VRefRHS");
    }

    AST* rule_VExpr() {
        _tracer.push("VExpr //");

        auto pExpr = rule_VExprMult();

        while (peek_match(T_OP_ADD) || peek_match(T_OP_SUB)) {
            auto pOp = advance_and_save();
            pOp->add_child(pExpr);
            pOp->add_child(rule_VExprMult());
            pExpr = pOp;
        }

        _tracer.pop("// VExpr");
        return pExpr;
    }

    AST* rule_VExprMult() {
        _tracer.push("VExprMult //");

        auto pExpr = rule_VExprPrimary();

        while (peek_match(T_OP_MUL) || peek_match(T_OP_DIV)) {
            auto pOp = advance_and_save();
            pOp->add_child(pExpr);
            pOp->add_child(rule_VExprPrimary());
            pExpr = pOp;
        }

        _tracer.pop("// VExprMult");
        return pExpr;
    }

    AST* rule_VExprPrimary() {
        _tracer.push("VExprPrimary //");

        if (peek_match(T_L_PAREN)) {
            advance();
            auto p = rule_VExpr();
            match(T_R_PAREN);
            return p;
        }

        if (peek_match(T_VAR_REF) || peek_match(T_INTEGER) || peek_match(T_DECIMAL) || peek_match(T_STRING))
        {
            _tracer.pop("// VExprPrimary");
            return advance_and_save();
        }
        else
            throw VParseException(token_loc(), "Unexpected token (expected VAR_REF, INTEGER, DECIMAL, or STRING)");

    }

    void rule_List(AST* pRoot) {
        _tracer.push("List //");

        match(T_L_BRACE);
        rule_Block(pRoot);
        match(T_R_BRACE);

        _tracer.pop("// List");
    }

    void rule_Block(AST* pRoot) {
        _tracer.push("Block //");

        while ( peek_matchmask(TM_VAL) ||
                peek_matchmask(TM_LIST_SCOPE) ||
                peek_match(T_L_BRACE) ||
                peek_match(T_IF) ||
                peek_match(T_WHILE) ||
                peek_match(T_IS_NULL) ) rule_StmtVal(pRoot);

        _tracer.pop("// Block");
    }
};


NAMESPACE_ZCK_END;
