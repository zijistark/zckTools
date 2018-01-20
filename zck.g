
/* VAL: STRING|QSTRING|INTEGER|DECIMAL|DATE|QDATE|TITLE_ID|CHAR_SCOPE (bit 12 in token type)
 * OP:  >|<|>=|<=|==|=|!= // OP_GT|OP_LT|OP_GTEQ|OP_LTEQ|OP_DEQ|OP_EQ|OP_NEQ (bit 11 in token type)
 */

Start     → List
List      → StmtVal*                                  // LA: {VAL, OPEN_BRACE, CLOSE_BRACE}
StmtVal   → VAL StmtCont?                             // LA: {VAL}
          | OPEN_BRACE List CLOSE_BRACE               // LA: {OPEN_BRACE}
          ;                                           // LA: {VAL, OPEN_BRACE}
StmtCont  → OP StmtRHS                                // LA: {OP}
          | OPEN_BRACE List CLOSE_BRACE               // LA: {OPEN_BRACE}
          ;                                           // LA: {OP, OPEN_BRACE}
StmtRHS   → VAL                                       // LA: {VAL}
          | OPEN_BRACE List CLOSE_BRACE               // LA: {OPEN_BRACE}
          ;                                           // LA: {VAL, OPEN_BRACE}
