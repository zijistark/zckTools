
#include "zck.h"

using namespace std;
using namespace zck;


/* this filename is 'ast2dot.cc', so you'd think we'd be outputting a .dot file for graphviz. we're not yet.  * instead,
   we're outputting the simplest, most classic form of tree text representations: nested parentheses with preorder
   traversal. */


string walk_tree(AST const* pNode) {
    string out = "(";
    out += pNode->token().type_id_name();
    for (auto&& child : pNode->children()) {
        out += " ";
        out += walk_tree(child);
    }
    return out + ")";
}

int main(int argc, char const* argv[]) {
    Parser parser( (argc == 1) ? "example.zck" : argv[1] );
    cout << walk_tree( parser.root() ) << endl;
    return 0;
}
