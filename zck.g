
/* VAL == STRING|QSTRING|INTEGER|DECIMAL|DATE|QDATE|TITLE_ID|CHAR_SCOPE */

START     : stmt*
Stmt      : VAL OP StmtRHS                   // LA: {VAL}
StmtRHS   : VAL                              // LA: {VAL}
          | OPEN_BRACE ListOpen              // LA: {OPEN_BRACE}
          ;                                  // LA: {VAL, OPEN_BRACE}
ListOpen  : CLOSE_BRACE                      // LA: {CLOSE_BRACE}
          | VAL ListEnd                      // LA: {VAL}
          ;                                  // LA: {CLOSE_BRACE, VAL}
ListEnd   : OP StmtRHS Stmt* CLOSE_BRACE     // LA: {OP}
          | VAL* CLOSE_BRACE                 // LA: {VAL, CLOSE_BRACE}
          ;                                  // LA: {OP, VAL, CLOSE_BRACE}
