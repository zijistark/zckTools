
#include "zck.h"

int main(int argc, const char** argv[]) {
    using namespace std;
    using namespace zck;

    Parser parser;
    unique_ptr<ParseContext> upCtx = parser.parse_file( (argc == 1) ? "example.zck" : argv[1] );

    // TODO: display the AST in a pretty-printed form
    // text output is tricky for nontrivial trees... probably use graphviz to lay it out on an SVG and exec Chrome on it

    return 0;
}

