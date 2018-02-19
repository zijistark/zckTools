
/* VAL: STRING|QSTRING|INTEGER|DECIMAL|DATE|QDATE|TITLE_ID|CHAR_SCOPE (bit 12 in token type)
 * OP:  >|<|>=|<=|==|=|!= // OP_GT|OP_LT|OP_GTEQ|OP_LTEQ|OP_DEQ|OP_EQ|OP_NEQ (bit 11 in token type)
 * ASSIGN: =|+=|-=|*=|/= (bit 15 in the token type -- not the actual OP_ASSIGN token, which corresponds to '=')
 * LIST_SCOPE: e.g., any_demesne_title (bit 14 in token type)
 */

START        → Block
Block        → StmtVal*                                                // LA: {VAL, LIST_SCOPE, L_BRACE, IF, WHILE}
List         → L_BRACE Block R_BRACE                                   // LA: {L_BRACE}
StmtVal      → IF IfBody                                               // LA: {IF}
             | WHILE LoopBody                                          // LA: {WHILE}
             | LIST_SCOPE LoopBody                                     // LA: {LIST_SCOPE}
             | VAR_REF ASSIGN (VAR_REF|INTEGER|DECIMAL|STRING)         // LA: {VAR_REF}
             | VAL StmtCont?                                           // LA: {VAL}
             | List                                                    // LA: {L_BRACE}
             ;                                                         // LA: {VAL, LIST_SCOPE, L_BRACE, IF, WHILE}
IfBody       → OP_EQ? List (THEN List)? ElsIf*                         // LA: {OP_EQ, L_BRACE}
ElsIf        → ELSIF IfBody                                            // LA: {ELSIF}
LoopBody     → OP_EQ? List (DO List)?                                  // LA: {OP_EQ, L_BRACE}
StmtCont     → OP StmtRHS                                              // LA: {OP}
             | List                                                    // LA: {L_BRACE}
             ;                                                         // LA: {OP, L_BRACE}
StmtRHS      → VAL                                                     // LA: {VAL}
             | List                                                    // LA: {L_BRACE}
             ;                                                         // LA: {VAL, L_BRACE}

/* for upcoming version, when we support full arithmetic expressions: */

START        → Block
Block        → StmtVal*                                                // LA: {VAL, LIST_SCOPE, L_BRACE, IF, WHILE}
List         → L_BRACE Block R_BRACE                                   // LA: {L_BRACE}
StmtVal      → IF IfBody                                               // LA: {IF}
             | WHILE LoopBody                                          // LA: {WHILE}
             | LIST_SCOPE LoopBody                                     // LA: {LIST_SCOPE}
             | VAR_REF OP_ASSIGN VExpr                                 // LA: {VAR_REF}
             | VAL StmtCont?                                           // LA: {VAL}
             | List                                                    // LA: {L_BRACE}
             ;                                                         // LA: {VAL, LIST_SCOPE, L_BRACE, IF, WHILE}
IfBody       → OP_EQ? List (THEN List)? ElsIf*                         // LA: {OP_EQ, L_BRACE}
ElsIf        → ELSIF IfBody                                            // LA: {ELSIF}
LoopBody     → OP_EQ? List (DO List)?                                  // LA: {OP_EQ, L_BRACE}
VExpr        → VExprMult ((OP_ADD|OP_SUB) VExprMult)*                  // LA: {INTEGER, DECIMAL, VAR_REF, L_PAREN}
VExprMult    → VExprUnary ((OP_MUL|OP_DIV) VExprUnary)*                // LA: {INTEGER, DECIMAL, VAR_REF, L_PAREN}
VExprUnary   → OP_SUB VExprUnary                                       // LA: {OP_SUB}
             | VExprPrimary                                            // LA: {INTEGER, DECIMAL, VAR_REF, L_PAREN}
             ;                                                         // LA: {OP_SUB, INTEGER, DECIMAL, VAR_REF, L_PAREN}
VExprPrimary → INTEGER                                                 // LA: {INTEGER}
             | DECIMAL                                                 // LA: {DECIMAL}
             | VAR_REF                                                 // LA: {VAR_REF}
             | L_PAREN VExpr R_PAREN                                   // LA: {L_PAREN}
             ;                                                         // LA: {INTEGER, DECIMAL, VAR_REF, L_PAREN}
StmtCont     → OP StmtRHS                                              // LA: {OP}
             | List                                                    // LA: {L_BRACE}
             ;                                                         // LA: {OP, L_BRACE}
StmtRHS      → VAL                                                     // LA: {VAL}
             | List                                                    // LA: {L_BRACE}
             ;                                                         // LA: {VAL, L_BRACE}
