
/* VAL == STRING|QSTRING|INTEGER|DECIMAL|DATE|QDATE|TITLE_ID|CHAR_SCOPE|KW_* */

Start     : Stmt*
Stmt      : VAL OP StmtRHS                   // LA: {VAL}
StmtRHS   : VAL                              // LA: {VAL}
          | List                             // LA: {OPEN_BRACE}
          ;                                  
List      : OPEN_BRACE ListOpen              // LA: {OPEN_BRACE}
          | CLOSE_BRACE                      // LA: {CLOSE_BRACE}
          | VAL ListEnd                      // LA: {VAL}
          ;                                  // LA: {OPEN_BRACE, CLOSE_BRACE, VAL}
ListEnd   : OP StmtRHS Stmt* CLOSE_BRACE     // LA: {OP}
          | VAL* CLOSE_BRACE                 // LA: {VAL, CLOSE_BRACE}
          ;                                  // LA: {OP, VAL, CLOSE_BRACE}
