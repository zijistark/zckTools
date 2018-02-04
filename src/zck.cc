
#include "zck.h"

#include <cstdio>
#include <getopt.h>

using namespace std;
using namespace zck;


char const* const TAB = "  ";


string pretty_label(AST const* pNode) {
    auto const& t = pNode->token();
//    string s = t.get_string();
    string s;

    switch (t.type_id()) {
        case T_OP_DEQ:      s = "==";     break;
        case T_OP_EQ:       s = "=";      break;
        case T_OP_LTEQ:     s = "<=";     break;
        case T_OP_LT:       s = "<";      break;
        case T_OP_GTEQ:     s = ">=";     break;
        case T_OP_GT:       s = ">";      break;
        case T_L_BRACE:  s = "{";      break;
        case T_R_BRACE: s = "}";      break;
        default:            s = t.type_id_name();
    }

    if (t.type_id() & Parser::TM_VAL) {
        s += "\\n";
        s += (char*)t.get_text();
    }

    return s;
}


struct options {
    string input;
    string output;
    bool   verbose;

    options() : verbose(false) {}
} g_opt;


void
print_help(char const* prog, ostream& out) {
    out << "USAGE:" << endl;
    out << TAB << prog << "[-v] -i FILE [-o FILE]" << endl;
}


class Translator {
    int _indent;

public:
    Translator(AST const* pRoot, ostream& out = cout) : _indent(0) { walk(pRoot, out); }

private:

    void indent(ostream& o) const noexcept {
        for (auto i = _indent; i > 0; --i) o << TAB;
    }

    void walk(AST const* pNode, ostream& o) {
        auto& t = pNode->token();

        if (t.type_id() == T_LIST)
            write_list(pNode, o);
        else if (t.type_id() & Parser::TM_OP)
            write_op(pNode, o);
        else if (t.type_id() & Parser::TM_VAL)
            write_val(pNode, o);
        else if (t.type_id() == T_IF || t.type_id() == T_ELSIF)
            write_ifelsif(pNode, o);
        else
            throw VException("Internal error: Unexpected token type %s in AST", t.type_id_name());
    }

    void write_list(AST const* pNode, ostream& o, bool force_open = false) {
        if (pNode->parent() && !force_open) { // if the node has no parent, it's a root list, and the curly braces are implicit
            o << "{\n";
            ++_indent;
        }

        for (auto pKid : pNode->children())
            walk(pKid, o);

        if (pNode->parent() && !force_open) {
            --_indent;
            indent(o);
            o << "}";
        }
    }

    void write_op(AST const* pNode, ostream& o) {
        auto& kids = pNode->children();
        auto& t = pNode->token();
        assert( kids.size() == 2 ); // binary operators ought to have exactly two children!

        indent(o);
        walk(kids.front(), o);

        switch (t.type_id()) {
            case T_OP_EQ:   o << " = ";  break;
            case T_OP_NEQ:  o << " != "; break;
            case T_OP_DEQ:  o << " == "; break;
            case T_OP_LTEQ: o << " <= "; break;
            case T_OP_LT:   o << " < ";  break;
            case T_OP_GTEQ: o << " >= "; break;
            case T_OP_GT:   o << " > ";  break;
            default:
                throw VException("Internal error: Unexpected OP token type %s in AST", t.type_id_name());
        }

        walk(kids.back(), o);
        o << "\n";
    }

    void write_ifelsif(AST const* pNode, ostream& o) {
        const char* const which = (pNode->token().type_id() == T_IF) ? "if" : "else_if";
        auto& kids = pNode->children();

        assert( kids.size() == 2 ); // should have 2 list children

        auto& cond_list = kids[0];
        auto& exec_list = kids[1];

        o << which << " = {\n";
        ++_indent;
        indent(o);
        o << "limit = ";
        write_list(cond_list, o);
        o << "\n";
        write_list(exec_list, o, true);
        --_indent;
        indent(o);
        o << "}\n";
    }

    void write_val(AST const* pNode, ostream& o) {
        assert( pNode->children().empty() ); // scalar values should never have children!
        assert( pNode->token().get_text() != &QUEX_NAME_TOKEN(LexemeNull) ); // should never be empty text for VAL tokens
        auto txt = (char*)pNode->token().get_text();
        assert( txt && *txt ); // likewise
        o << txt;
        // TODO: quote text if nec.
    }
};


int
main(int argc, char* argv[]) {
    char const* const short_opts = "i:o:vh";
    option const long_opts[] = {
      {"input",   required_argument, nullptr, 'i'},
      {"output",  required_argument, nullptr, 'o'},
      {"verbose", no_argument,       nullptr, 'v'},
      {"help",    no_argument,       nullptr, 'h'},
      {nullptr, 0, nullptr, 0}
    };

    while (true) {
        int opt_idx = 0;
        auto const opt = getopt_long(argc, argv, short_opts, long_opts, &opt_idx);

        /* Detect the end of the options. */
        if (opt == -1) break;

        switch (opt) {
        case 'v':
            g_opt.verbose = true;
            break;

        case 'i':
            g_opt.input = optarg;
            break;

        case 'o':
            g_opt.output = optarg;
            break;

        case 'h':
            print_help(argv[0], cout);
            return 0;

        case '?':
        default:
            print_help(argv[0], cerr);
            return 1;
        }
    }

    if (g_opt.input.empty()) {
        cerr << "Parameter '-i' / '--input' required!" << endl;
        print_help(argv[0], cerr);
        return 1;
    }

    // if (g_opt.output.empty()) {
    //     cerr << "Parameter '-o' / '--output' required!" << endl;
    //     print_help(argv[0], cerr);
    //     return 1;
    // }

    try {

        Parser parser( g_opt.input.c_str() );
        Translator(parser.root());

        // cout << "digraph {" << endl << TAB << "rankdir=LR" << endl;
        // walk_tree( parser.root() );
        // cout << "}" << endl;
    }
    catch (std::exception& e) {
        cout << "Fatal: " << e.what() << endl;
        return 1;
    }

    return 0;
}
