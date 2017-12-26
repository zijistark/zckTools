
#include "Parser.h"
#include "Exception.h"


_ZCK_NAMESPACE_BEGIN;


Parser::Parser(char const* path)
    : _pRoot(nullptr), _path(path), _lex(path), _pTok(nullptr)
{
    if (_lex.error_code != E_Error_None) {
        throw VException("Failed to initialize lexer: %s: %s", E_Error_NAME(_lex.error_code), path);
    }

    // prime a lookahead token
    advance();

    // begin recursive descent
    start();
}


_ZCK_NAMESPACE_END;
