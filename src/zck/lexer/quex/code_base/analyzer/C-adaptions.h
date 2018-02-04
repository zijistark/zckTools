#ifndef __QUEX_INCLUDE_GUARD__ANALYZER__C_ADAPTIONS_H
#define __QUEX_INCLUDE_GUARD__ANALYZER__C_ADAPTIONS_H

#include <quex/code_base/token/TokenPolicy>

#ifdef self_accumulator_add
/* Token / Token Policy _____________________________________________________*/
#   undef self_token_take_text

/* Modes ____________________________________________________________________*/
#   undef self_current_mode_p
#   undef self_current_mode_id
#   undef self_current_mode_name
/* Map: mode id to mode and vice versa */
#   undef self_map_mode_id_to_mode_p
#   undef self_map_mode_p_to_mode_id
/* Changing Modes */
#   undef self_set_mode_brutally
#   undef self_enter_mode
/* Changing Modes with stack */ 
#   undef self_pop_mode
#   undef self_pop_drop_mode
#   undef self_push_mode
/* Undo lexeme match */
#   undef self_undo
#   undef self_undo_n

/* Accumulator ______________________________________________________________*/
#   undef self_accumulator_add
#   undef self_accumulator_add_character
#   undef self_accumulator_clear
#   undef self_accumulator_flush
#   undef self_accumulator_is_empty
/* Indentation/Counter _____________________________________________________*/
#   ifdef QUEX_OPTION_COUNTER_LINE
#   undef self_line_number            
#   undef self_line_number_at_begin 
#   undef self_line_number_at_begin_set
#   undef self_line_number_at_end   
#   endif
#   ifdef QUEX_OPTION_COUNTER_COLUMN
#   undef self_column_number          
#   undef self_column_number_at_begin 
#   undef self_column_number_at_begin_set
#   undef self_column_number_at_end   
#   endif
#   ifdef QUEX_OPTION_INDENTATION_TRIGGER
#   undef self_indentation                    
#   undef self_disable_next_indentation_event 
#   endif
#endif

/* Modes */
#define self_current_mode_p()     /* QUEX_NAME(Mode)* */ QUEX_NAME(get_mode)(&self)
#define self_current_mode_id()    /* int */              QUEX_NAME(get_mode_id)(&self)
#define self_current_mode_name()  /* const char* */      QUEX_NAME(get_mode_name)(&self)

/* Map: mode id to mode and vice versa */
#define self_map_mode_id_to_mode_p(ID)           QUEX_NAME(map_mode_id_to_mode)(&self, (ID))
#define self_map_mode_p_to_mode_id(ModeP)        QUEX_NAME(map_mode_to_mode_id)(&self, (ModeP))
                                                 
/* Changing Modes */                             
#define self_set_mode_brutally(ModeP)            QUEX_NAME(set_mode_brutally)(&self, (ModeP))
#define self_enter_mode(ModeP)                   QUEX_NAME(enter_mode)(&self, (ModeP))
                                                 
/* Changing Modes with stack */                  
#define self_pop_mode()                          QUEX_NAME(pop_mode)(&self)
#define self_pop_drop_mode()                     QUEX_NAME(pop_drop_mode)(&self)
#define self_push_mode(ModeP)                    QUEX_NAME(push_mode)(&self, (ModeP))
                                                 
#ifdef      QUEX_OPTION_COUNTER_LINE     
#   define  self_line_number_at_begin()          (self.counter._line_number_at_begin)
#   define  self_line_number_at_begin_set(X)     do { self.counter._line_number_at_begin = (X); } while(0)
#   define  self_line_number_at_end()            (self.counter._line_number_at_end)
#   define  self_line_number()                   (self_line_number_at_begin())
#endif                                           
#ifdef      QUEX_OPTION_COUNTER_COLUMN  
#   define  self_column_number_at_begin()        (self.counter._column_number_at_begin)
#   define  self_column_number_at_begin_set(X)   do { self.counter._column_number_at_begin = (X); } while(0)
#   define  self_column_number_at_end()          (self.counter._column_number_at_end)
#   define  self_column_number()                 (self_column_number_at_begin())
#endif                                           
#ifdef      QUEX_OPTION_INDENTATION_TRIGGER      
#   define  self_indentation()                   (counter._indentation_stack.back - counter._indentation_stack.front + 1)
#endif

/* Accumulator ______________________________________________________________*/
#   define self_accumulator_add(Begin, End)      QUEX_NAME(Accumulator__add)(&self.accumulator, Begin, End)
#   define self_accumulator_add_character(Char)  QUEX_NAME(Accumulator__add_character)(&self.accumulator, Char)
#   define self_accumulator_clear()              QUEX_NAME(Accumulator__clear)(&self.accumulator)
#   define self_accumulator_is_empty()           (self.accumulator.text.begin == self.accumulator.text.end)
#   define self_accumulator_flush(TokenID)       QUEX_NAME(Accumulator__flush)(&self.accumulator, TokenID)

/* Undo lexeme match */
#   define self_undo()                           QUEX_NAME(undo)(&self)
#   define self_undo_n(N)                        QUEX_NAME(undo_n)(&self, N)

#endif /* __QUEX_INCLUDE_GUARD__ANALYZER__C_ADAPTIONS_H */
