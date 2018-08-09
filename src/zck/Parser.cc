
#include "Parser.h"
#include "Exception.h"


NAMESPACE_ZCK;


Parser::Parser(char const* path)
    : _pRoot(nullptr), _path(path), _lex(path), _pTok(nullptr), _tracer("  ")
{
    if (_lex.error_code != E_Error_None) {
        throw VException("Failed to initialize lexer: %s: %s", E_Error_NAME(_lex.error_code), path);
    }

    // prime a lookahead token
    advance();

    // begin recursive descent
    start();
}


NAMESPACE_ZCK_END;
