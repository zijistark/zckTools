// -*- c++ -*-

#pragma once

#include "common.h"


_ZCK_NAMESPACE_BEGIN;


#include "AST.h"
#include "ParseContext.h"
#include <Lexer>
#include <memory>

using token_id = QUEX_TYPE_TOKEN_ID;


class Parser {
public:
    using namespace quex;

    uptr<ParseContext> parse_file(const char*);

private:
    Lexer  _lexer;
    Token* _next_token;

    void consume();
    void match(token_id);

    /* methods corresponding to grammar rules */

    void rule_Start();
    void rule_Stmt();
    void rule_StmtRHS();
    void rule_ListOpen();
    void rule_ListEnd(Token* start_token);
};


_ZCK_NAMESPACE_END;
