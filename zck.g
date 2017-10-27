
/* VAL: STRING|QSTRING|INTEGER|DECIMAL|DATE|QDATE|TITLE_ID|CHAR_SCOPE (bit 12 in token type)
 * OP:  yeah, you can guess, k. (bit 11 in token type)
 */

Start     → Stmt*                           ;        // FOLLOW: {VAL}
Stmt      → VAL OP StmtRHS                  ;        // FOLLOW: {VAL}
StmtRHS   → VAL                                      // FOLLOW: {VAL}
          | OPEN_BRACE ListOpen                      // FOLLOW: {OPEN_BRACE}
          ;                                          // FOLLOW: {VAL, OPEN_BRACE}
ListOpen  → CLOSE_BRACE                              // FOLLOW: {CLOSE_BRACE}
          | VAL ListEnd                              // FOLLOW: {VAL}
          | OPEN_BRACE ListOpen                      // FOLLOW: {OPEN_BRACE}
          ;                                          // FOLLOW: {OPEN_BRACE, CLOSE_BRACE, VAL}
ListEnd   → OP StmtRHS Stmt* CLOSE_BRACE             // FOLLOW: {OP}
          | VAL* CLOSE_BRACE                         // FOLLOW: {VAL, CLOSE_BRACE}
          ;                                          // FOLLOW: {OP, VAL, CLOSE_BRACE}
