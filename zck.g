
/* VAL: STRING|QSTRING|INTEGER|DECIMAL|DATE|QDATE|TITLE_ID|CHAR_SCOPE (bit 12 in token type)
 * OP:  >|<|>=|<=|==|=|!= // OP_GT|OP_LT|OP_GTEQ|OP_LTEQ|OP_DEQ|OP_EQ|OP_NEQ (bit 11 in token type)
 * ASSIGN: =|+=|-=|*=|/= (bit 15 in the token type -- not the actual OP_ASSIGN token, which corresponds to '=')
 * LIST_SCOPE: e.g., any_demesne_title (bit 14 in token type)
 */

START        → Block
Block        → StmtVal*                                          // LA: {VAL, LIST_SCOPE, L_BRACE, IF, WHILE, VAR_REF}
List         → L_BRACE Block R_BRACE                             // LA: {L_BRACE}
StmtVal      → IF IfBody                                         // LA: {IF}
             | (WHILE|LIST_SCOPE) LoopBody                       // LA: {WHILE, LIST_SCOPE}
             | (IS_NULL|IS_VALID) (OP_EQ|OP_NEQ) VAL             // LA: {IS_NULL, IS_VALID}
             | VAR_REF VRefRHS                                   // LA: {VAR_REF}
             | VAL StmtCont?                                     // LA: {VAL}
             | List                                              // LA: {L_BRACE}
             ;                                                   // LA: {VAL, LIST_SCOPE, L_BRACE, IF, WHILE, VAR_REF, IS_NULL, IS_VALID}
IfBody       → OP_EQ? List (THEN List)? ElsIf*                   // LA: {OP_EQ, L_BRACE}
ElsIf        → ELSIF IfBody                                      // LA: {ELSIF}
LoopBody     → OP_EQ? List (DO List)?                            // LA: {OP_EQ, L_BRACE}
VRefRHS      → ASSIGN VExpr                                      // LA: {ASSIGN}
             | OP (VAR_REF|INTEGER|DECIMAL)                      // LA: {OP}
             ;                                                   // LA: {ASSIGN, OP}
VExpr        → VExprMult ((OP_ADD|OP_SUB) VExprMult)*            // LA: {INTEGER, DECIMAL, VAR_REF, STRING, L_PAREN}
VExprMult    → VExprPrimary ((OP_MUL|OP_DIV) VExprPrimary)*      // LA: {INTEGER, DECIMAL, VAR_REF, STRING, L_PAREN}
VExprPrimary → (INTEGER|DECIMAL|VAR_REF|STRING)                  // LA: {INTEGER, DECIMAL, VAR_REF, STRING}
             | L_PAREN VExpr R_PAREN                             // LA: {L_PAREN}
             ;                                                   // LA: {INTEGER, DECIMAL, VAR_REF, STRING, L_PAREN}
StmtCont     → OP StmtRHS                                        // LA: {OP}
             | List                                              // LA: {L_BRACE}
             ;                                                   // LA: {OP, L_BRACE}
StmtRHS      → VAL                                               // LA: {VAL}
             | List                                              // LA: {L_BRACE}
             ;                                                   // LA: {VAL, L_PAREN, L_BRACE}
