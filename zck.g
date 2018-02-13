
/* VAL: STRING|QSTRING|INTEGER|DECIMAL|DATE|QDATE|TITLE_ID|CHAR_SCOPE (bit 12 in token type)
 * OP:  >|<|>=|<=|==|=|!= // OP_GT|OP_LT|OP_GTEQ|OP_LTEQ|OP_DEQ|OP_EQ|OP_NEQ (bit 11 in token type)
 * LIST_SCOPE: e.g., any_demesne_title (bit 14 in token type)
 */

START      → Block
Block      → StmtVal*                                                // LA: {VAL, LIST_SCOPE, L_BRACE, IF, WHILE}
List       → L_BRACE Block R_BRACE                                   // LA: {L_BRACE}
StmtVal    → IF IfBody                                               // LA: {IF}
           | WHILE LoopBody                                          // LA: {WHILE}
           | LIST_SCOPE LoopBody                                     // LA: {LIST_SCOPE}
           | VAL StmtCont?                                           // LA: {VAL}
           | List                                                    // LA: {L_BRACE}
           ;                                                         // LA: {VAL, LIST_SCOPE, L_BRACE, IF, WHILE}
IfBody     → OP_EQ? List (THEN List)? ElsIf*                         // LA: {OP_EQ, L_BRACE}
ElsIf      → ELSIF IfBody                                            // LA: {ELSIF}
LoopBody   → OP_EQ? List (DO List)?                                  // LA: {OP_EQ, L_BRACE}
StmtCont   → OP StmtRHS                                              // LA: {OP}
           | List                                                    // LA: {L_BRACE}
           ;                                                         // LA: {OP, L_BRACE}
StmtRHS    → VAL                                                     // LA: {VAL}
           | List                                                    // LA: {L_BRACE}
           ;                                                         // LA: {VAL, L_BRACE}
