start     : stmt*
stmt      : VAL OP stmt_rhs                  // LA: {VAL}
stmt_rhs  : VAL                              // LA: {VAL}
          | OPEN_BRACE list_cont             // LA: {OPEN_BRACE}
          ;                                  // LA: {VAL, OPEN_BRACE}
list_cont : CLOSE_BRACE                      // LA: {CLOSE_BRACE}
          | VAL list_end                     // LA: {VAL}
          ;                                  // LA: {CLOSE_BRACE, VAL}
list_end  : OP stmt_rhs stmt* CLOSE_BRACE    // LA: {OP}
          | VAL* CLOSE_BRACE                 // LA: {VAL, CLOSE_BRACE}
          ;                                  // LA: {OP, VAL, CLOSE_BRACE}
