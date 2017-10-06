// -*- c++ -*-

#pragma once

#include "common.h"


_ZCK_NAMESPACE_BEGIN;


#include "AST.h"
#include "ParseContext.h"
#include <Lexer>
#include <memory>

using token_id_t = QUEX_TYPE_TOKEN_ID;


class Parser {
public:
    using namespace quex;

    uptr<ParseContext> parse_file(const char*);

private:
    Lexer  _lexer;
    Token* _next_token;
    uptr<ParseContext> _upCtx;

    void consume() { _lexer.receive(&_next_token); }

    void match_id(token_id_t t) {
        if (_next_token->type_id() != t)
            throw VParseException(FLoc(_upCtx->path(), _next_token->line_number(), _next_token->column_number()),
                                  "Unexpected token %s (expected %s)",
                                  _next_token->type_id_name(), _next_token->map_id_to_name(t));
    }

    void match_id_mask(token_id_t mask) {
        if ( (_next_token->type_id() & mask) != 0 )
            throw VParseException(FLoc(_upCtx->path(), _next_token->line_number(), _next_token->column_number()),
                                  "Unexpected token %s", _next_token->type_id_name());
    }

    /* methods corresponding to grammar rules */

    void rule_Start();
    void rule_Stmt();
    void rule_StmtRHS();
    void rule_ListOpen();
    void rule_ListEnd(Token start_token);
};


_ZCK_NAMESPACE_END;
