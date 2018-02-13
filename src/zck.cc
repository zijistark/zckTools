
#include "zck.h"

#include <cstdio>
#include <getopt.h>
#include <boost/filesystem.hpp>

using namespace std;
using namespace zck;
namespace fs = boost::filesystem;


const char* const TAB = "\t";
const char* const VERSION = "v0.0-5";

struct options {
    int verbose;

    options() : verbose(0) {}
} g_opt;


void
print_help(char const* prog, ostream& out) {
    out << "USAGE:" << endl;
    out << TAB << prog << " [-v|-V|-h]" << endl;
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
        else if ((t.type_id() & Parser::TM_LIST_SCOPE) ||
                 t.type_id() == T_IF || t.type_id() == T_ELSIF || t.type_id() == T_WHILE)
            write_conditional_or_loop(pNode, o);
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

        if (t.type_id() == T_OP_NEQ) {
            // operator != implementation currently only works for non-numeric triggers (i.e., those which do not support
            // full range of comparison operators). to get it to work for numeric triggers, we need to be able to recognize
            // numeric triggers separately in order to give them the implementation of NOT { num_trigger == X } rather than
            // NOT { regular_trigger = X }. since != does not have very many uses for numeric triggers in practice, I'm not
            // bothering for now.

            // also: heavy usage of != will result in a lot of unnecessary NOTs that should be [intelligently] coalesced into
            // a bigger NOR -- for some reason the NOT trigger actually consumes quite a lot of CPU cycles overall
            // (presumably due to the very high overhead of CK2script execution and the sheer amount of negations which occur
            // in script logic), so in the future this should be an intermediate tree rewriting step so that an optimization
            // pass can reduce the heavy usage of NOT by using NOR.

            if (kids.back()->token().type_id() != T_LIST) {
                // this version can be a one-liner; don't normally care much about output prettiness, but helps readability
                o << "not = { ";
                walk(kids.front(), o);
                o << " = ";
                walk(kids.back(), o);
                o << " }\n";
            }
            else {
                o << "not = {\n";
                ++_indent;
                indent(o);
                walk(kids.front(), o);
                o << " = ";
                walk(kids.back(), o);
                o << "\n";
                --_indent;
                indent(o);
                o << "}\n";
            }

            return;
        }

        walk(kids.front(), o);

        switch (t.type_id()) {
            case T_OP_EQ:   o << " = ";  break;
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

    void write_conditional_or_loop(AST const* pNode, ostream& o) {
        auto& t = pNode->token();
        auto& kids = pNode->children();
        assert( kids.size() > 0 && kids.size() <= 2 );

        auto tid = t.type_id();
        const char* name = (tid & Parser::TM_LIST_SCOPE) ? (char*)t.get_text()
                           : tid == T_WHILE ? "while"
                           : tid == T_IF ? "if"
                           : "else_if";

        indent(o);

        if (kids.size() == 2) { // new syntax
            o << name << " = {\n";
            ++_indent;
            indent(o);
            o << "limit = ";
            write_list(kids[0], o);
            o << "\n";
            write_list(kids[1], o, true);
            --_indent;
            indent(o);
            o << "}\n";
        }
        else {
            // backward-compatible syntax + pure trigger/effect syntax (i.e., conditional block existence exclusive to
            // effect block existence)
            o << name << " = ";
            write_list(kids[0], o);
            o << "\n";
        }
    }

    void write_val(AST const* pNode, ostream& o) {
        assert( pNode->children().empty() ); // scalar values should never have children!
        auto& t = pNode->token();
        auto txt = (char*)t.get_text();
        assert( t.type_id() == T_QSTRING || *txt != '\0');

        /* some aliases -- as always until ZCK starts to grow into something ready to be used heavily, we're doing this
         * shit in a silly but very easy way */

        if (strcmp(txt, "save_target") == 0)
            o << "save_event_target_as";
        else if (strcmp(txt, "save_global_target") == 0)
            o << "save_global_event_target_as";
        else if (strcmp(txt, "clear_global_target") == 0)
            o << "clear_global_event_target";
        else if (strcmp(txt, "clear_target") == 0)
            o << "clear_event_target";
        else if (strncmp("target:", txt, strlen("target:")) == 0)
            o << "event_" << txt;
        else if (t.type_id() == T_QSTRING || t.type_id() == T_QDATE)
            o << "\"" << txt << "\"";
        else
            o << txt;
        // TODO: quote text if nec.
    }
};


bool find_root_path(fs::path& out_path) {
    auto p = fs::current_path();

    while (true) {
        if (exists(p / "config.zck")) {
            out_path = p;
            return true;
        }
        else if (p.has_parent_path()) p = p.parent_path();
        else break;
    }

    return false;
}


int main(int argc, char* argv[]) {
    char const* const short_opts = "vVh";
    option const long_opts[] = {
      {"verbose", no_argument, nullptr, 'v'},
      {"version", no_argument, nullptr, 'V'},
      {"help",    no_argument, nullptr, 'h'},
      {nullptr, 0, nullptr, 0}
    };

    while (true) {
        int opt_idx = 0;
        auto const opt = getopt_long(argc, argv, short_opts, long_opts, &opt_idx);

        /* Detect the end of the options. */
        if (opt == -1) break;

        switch (opt) {
        case 'v':
            g_opt.verbose++;
            break;

        case 'h':
            print_help(argv[0], cout);
            return 0;

        case 'V':
            cout << "ZCK compiler " << VERSION << endl;
            cout << "Copyright (C) 2018 Matthew D. Hall" << endl;
            return 0;

        case '?':
        default:
            print_help(argv[0], cerr);
            return 1;
        }
    }

    try {
        /* search for mod root folder, then change the current directory to it */
        fs::path root_path;

        if (!find_root_path(root_path))
            throw runtime_error("Cannot invoke zck outside of a mod folder! Did you forget to add a config.zck file to the mod's root folder?");

        fs::current_path(root_path);

        /* recursively scan all relevant directories under us for .zck files to translate to CK2script files */

        // TODO: only scan the directory types about which we give a shit

        vector<fs::path> in_paths;

        for (auto&& e : fs::recursive_directory_iterator(".")) {
            const auto& p = e.path();
            if (fs::is_regular_file(p) && p.extension() == ".zck" && p.filename() != "config.zck")
                in_paths.emplace_back(p);
        }

        for (const auto& in_path : in_paths) {
            auto out_file = in_path.stem();
            out_file += "_ZCK.txt";
            auto out_path = in_path.parent_path() / out_file;

            if (g_opt.verbose >= 1)
                cout << "[COMPILE] " << in_path.generic_string() << endl;

            /* parse the source & translate it into the target stream */
            Parser parser(in_path.generic_string().c_str());

            /* open the target's stream */
            fs::ofstream out(out_path, std::ios::binary);

            if (!out)
                throw VException("Could not open file for writing: %s", out_path.generic_string().c_str());

            out << "# -*- ck2 -*-\n# Generated from ZCK source code; compiler version: " << VERSION << "\n\n";
            Translator(parser.root(), out);
        }
    }
    catch (std::exception& e) {
        cout << "Fatal: " << e.what() << endl;
        return 1;
    }

    return 0;
}
