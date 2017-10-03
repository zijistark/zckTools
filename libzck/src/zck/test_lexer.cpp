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

        if (token_p->type_id() != QUEX_TKN_TERMINATION)
            cout << "'";

        switch (token_p->type_id()) {
            case QUEX_TKN_OP_DEQ:      cout << "=="; break;
            case QUEX_TKN_OP_EQ:       cout << "=";  break;
            case QUEX_TKN_OP_LTEQ:     cout << "<="; break;
            case QUEX_TKN_OP_LT:       cout << "<";  break;
            case QUEX_TKN_OP_GTEQ:     cout << ">="; break;
            case QUEX_TKN_OP_GT:       cout << ">";  break;
            case QUEX_TKN_OPEN_BRACE:  cout << "{";  break;
            case QUEX_TKN_CLOSE_BRACE: cout << "}";  break;

            case QUEX_TKN_FAILURE:
            case QUEX_TKN_DECIMAL:
            case QUEX_TKN_DATE:
            case QUEX_TKN_QDATE:
            case QUEX_TKN_QSTRING:
            case QUEX_TKN_TITLE_ID:
            case QUEX_TKN_STRING:
                cout << token_p->text;
                break;

            case QUEX_TKN_INTEGER:    cout << token_p->number; break;
            case QUEX_TKN_CHAR_SCOPE: cout << "c_" << token_p->number; break;

            case QUEX_TKN_KW_THIS: cout << "THIS"; break;
            case QUEX_TKN_KW_ROOT: cout << "ROOT"; break;
            case QUEX_TKN_KW_PREV: for (size_t i = 0; i < token_p->number; ++i) cout << "PREV"; break;
            case QUEX_TKN_KW_FROM: for (size_t i = 0; i < token_p->number; ++i) cout << "FROM"; break;
            case QUEX_TKN_KW_ROOTFROM:
                cout << "ROOT_"; for (size_t i = 0; i < token_p->number; ++i) cout << "FROM";
                break;

            default: break;
        }

        if (token_p->type_id() != QUEX_TKN_TERMINATION)
            cout << "'";

        cout << endl;
        ++number_of_tokens;

        if (token_p->type_id() == QUEX_TKN_TERMINATION) break;
        if (token_p->type_id() == QUEX_TKN_FAILURE) break;
    }

    cout << "| [END] number of tokens = " << number_of_tokens << "\n";
    cout << "`-----------------------------------------------------------------\n";

    if (qlex.error_code != E_Error_None) qlex.print_this();
    return 0;
}
