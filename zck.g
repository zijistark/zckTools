
/* VAL: STRING|QSTRING|INTEGER|DECIMAL|DATE|QDATE|TITLE_ID|CHAR_SCOPE (bit 12 in token type)
 * OP:  >|<|>=|<=|==|=|!= // OP_GT|OP_LT|OP_GTEQ|OP_LTEQ|OP_DEQ|OP_EQ|OP_NEQ (bit 11 in token type)
 */

Start      → List
List       → StmtVal*                                                // LA: {VAL, L_BRACE, R_BRACE}
ClosedList → L_BRACE List R_BRACE                                    // LA: {L_BRACE}
StmtVal    → IF ClosedList ClosedList ElseIf*                        // LA: {IF}
           | VAL StmtCont?                                           // LA: {VAL}
           | ClosedList                                              // LA: {L_BRACE}
           ;                                                         // LA: {IF, VAL, L_BRACE}
ElseIf     → ELSIF ClosedList ClosedList                             // LA: {ELSIF}
StmtCont   → OP StmtRHS                                              // LA: {OP}
           | ClosedList                                              // LA: {L_BRACE}
           ;                                                         // LA: {OP, L_BRACE}
StmtRHS    → VAL                                                     // LA: {VAL}
           | ClosedList                                              // LA: {L_BRACE}
           ;                                                         // LA: {VAL, L_BRACE}
