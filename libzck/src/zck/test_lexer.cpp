#include <fstream>
#include <iostream>

#include "Lexer"

int
main(int argc, char** argv) {
    using namespace std;
    using namespace quex;

    Lexer  qlex(argc == 1 ? "test_lexer.txt" : argv[1]);
    Token* token_p = nullptr;
    int    number_of_tokens = 0;

    cout << ",-----------------------------------------------------------------\n";
    cout << "| [START]\n";

    while (qlex.error_code == E_Error_None) {
        qlex.receive(&token_p);
        if (token_p == nullptr) break;

        cout << "| " << token_p->type_id_name() << " ";

        if (token_p->type_id() != TK_TERMINATION)
            cout << "'";

        switch (token_p->type_id()) {
            case TK_OP_DEQ:      cout << "=="; break;
            case TK_OP_EQ:       cout << "=";  break;
            case TK_OP_LTEQ:     cout << "<="; break;
            case TK_OP_LT:       cout << "<";  break;
            case TK_OP_GTEQ:     cout << ">="; break;
            case TK_OP_GT:       cout << ">";  break;
            case TK_OPEN_BRACE:  cout << "{";  break;
            case TK_CLOSE_BRACE: cout << "}";  break;

            case TK_FAILURE:
            case TK_DECIMAL:
            case TK_DATE:
            case TK_QDATE:
            case TK_QSTRING:
            case TK_TITLE_ID:
            case TK_STRING:
                cout << token_p->text;
                break;

            case TK_INTEGER:    cout << token_p->number; break;
            case TK_CHAR_SCOPE: cout << "c_" << token_p->number; break;

            case TK_KW_THIS: cout << "THIS"; break;
            case TK_KW_ROOT: cout << "ROOT"; break;
            case TK_KW_PREV: for (size_t i = 0; i < token_p->number; ++i) cout << "PREV"; break;
            case TK_KW_FROM: for (size_t i = 0; i < token_p->number; ++i) cout << "FROM"; break;
            case TK_KW_ROOTFROM:
                cout << "ROOT_"; for (size_t i = 0; i < token_p->number; ++i) cout << "FROM";
                break;

            default: break;
        }

        if (token_p->type_id() != TK_TERMINATION)
            cout << "'";

        cout << endl;
        ++number_of_tokens;

        if (token_p->type_id() == TK_TERMINATION) break;
        if (token_p->type_id() == TK_FAILURE) break;
    }

    cout << "| [END] number of tokens = " << number_of_tokens << "\n";
    cout << "`-----------------------------------------------------------------\n";

    if (qlex.error_code != E_Error_None) qlex.print_this();
    return 0;
}
