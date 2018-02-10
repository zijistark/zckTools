
/* VAL: STRING|QSTRING|INTEGER|DECIMAL|DATE|QDATE|TITLE_ID|CHAR_SCOPE (bit 12 in token type)
 * OP:  >|<|>=|<=|==|=|!= // OP_GT|OP_LT|OP_GTEQ|OP_LTEQ|OP_DEQ|OP_EQ|OP_NEQ (bit 11 in token type)
 */

START      → Block
Block      → StmtVal*                                                // LA: {VAL, L_BRACE, R_BRACE}
List       → L_BRACE Block R_BRACE                                   // LA: {L_BRACE}
StmtVal    → IF IfCont                                               // LA: {IF}
           | VAL StmtCont?                                           // LA: {VAL}
           | List                                                    // LA: {L_BRACE}
           ;                                                         // LA: {IF, VAL, L_BRACE}
IfCont     → OP_EQ? List IfEffect? ElsIf*                            // LA: {OP_EQ, L_BRACE}
IfEffect   → (THEN|DO)? List                                         // LA: {THEN, DO, L_BRACE}
ElsIf      → ELSIF IfCont                                            // LA: {ELSIF}
StmtCont   → OP StmtRHS                                              // LA: {OP}
           | List                                                    // LA: {L_BRACE}
           ;                                                         // LA: {OP, L_BRACE}
StmtRHS    → VAL                                                     // LA: {VAL}
           | List                                                    // LA: {L_BRACE}
           ;                                                         // LA: {VAL, L_BRACE}
