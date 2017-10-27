#include <fstream>
#include <iostream>

#include <Lexer>

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

        if (token_p->type_id() != T_TERMINATION)
            cout << "'";

        switch (token_p->type_id()) {
            case T_OP_DEQ:      cout << "==";     break;
            case T_OP_EQ:       cout << "=";      break;
            case T_OP_LTEQ:     cout << "<=";     break;
            case T_OP_LT:       cout << "<";      break;
            case T_OP_GTEQ:     cout << ">=";     break;
            case T_OP_GT:       cout << ">";      break;
            case T_OPEN_BRACE:  cout << "{";      break;
            case T_CLOSE_BRACE: cout << "}";      break;

            case T_FAILURE:
            case T_DECIMAL:
            case T_DATE:
            case T_QDATE:
            case T_QSTRING:
            case T_TITLE_ID:
            case T_STRING:
                cout << token_p->text;
                break;

            case T_INTEGER:    cout << token_p->number; break;
            case T_CHAR_SCOPE: cout << "c_" << token_p->number; break;


            default: break;
        }

        if (token_p->type_id() != T_TERMINATION)
            cout << "'";

        cout << endl;
        ++number_of_tokens;

        if (token_p->type_id() == T_TERMINATION) break;
        if (token_p->type_id() == T_FAILURE) break;
    }

    cout << "| [END] number of tokens = " << number_of_tokens << "\n";
    cout << "`-----------------------------------------------------------------\n";

    if (qlex.error_code != E_Error_None) qlex.print_this();
    return 0;
}
