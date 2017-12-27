
#include "Lexer"

#include <quex/code_base/analyzer/C-adaptions.h>
/* The file 'multi.i' contains implementations which are the same for all 
 * possibly generated analyzers. If QUEX_OPTION_MULTI is defined, it is
 * NOT supposed to be included here. If not--in which case we have a single
 * analzer--then it is included.                                             */
#include <quex/code_base/single.i>

QUEX_NAMESPACE_MAIN_OPEN
QUEX_NAME(Mode) QUEX_NAME(MAIN) = {
    /* id                */ QUEX_NAME(ModeID_MAIN),
    /* name              */ "MAIN",
#   if      defined(QUEX_OPTION_INDENTATION_TRIGGER) \
       && ! defined(QUEX_OPTION_INDENTATION_DEFAULT_HANDLER)
    /* on_indentation    */ QUEX_NAME(Mode_on_indentation_null_function),
#   endif
    /* on_entry          */ QUEX_NAME(Mode_on_entry_exit_null_function),
    /* on_exit           */ QUEX_NAME(Mode_on_entry_exit_null_function),
#   if      defined(QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK)
    /* has_base          */ QUEX_NAME(MAIN_has_base),
    /* has_entry_from    */ QUEX_NAME(MAIN_has_entry_from),
    /* has_exit_to       */ QUEX_NAME(MAIN_has_exit_to),
#   endif
    /* analyzer_function */ QUEX_NAME(MAIN_analyzer_function)
};

QUEX_NAME(Mode)* (QUEX_NAME(mode_db)[__QUEX_SETTING_MAX_MODE_CLASS_N]) = {
    &QUEX_NAME(MAIN)
};
#define self        (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
#define LexemeNull  (&QUEX_LEXEME_NULL)
#define RETURN      return

void
QUEX_NAME(MAIN_on_entry)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* FromMode) {
    (void)me;
    (void)FromMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(MAIN).has_entry_from(FromMode);
#   endif

}

void
QUEX_NAME(MAIN_on_exit)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* ToMode)  {
    (void)me;
    (void)ToMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(MAIN).has_exit_to(ToMode);
#   endif

}

#if defined(QUEX_OPTION_INDENTATION_TRIGGER) 
void
QUEX_NAME(MAIN_on_indentation)(QUEX_TYPE_ANALYZER*    me, 
                                        QUEX_TYPE_INDENTATION  Indentation, 
                                        QUEX_TYPE_LEXATOM*   Begin) {
    (void)me;
    (void)Indentation;
    (void)Begin;
    return;
}
#endif

#ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
bool
QUEX_NAME(MAIN_has_base)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return false;
}
bool
QUEX_NAME(MAIN_has_entry_from)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
switch( Mode->id ) {

    case QUEX_NAME(ModeID_MAIN): {

    return true;
    }

    default: {

    return true;
    }

    }

}
bool
QUEX_NAME(MAIN_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
switch( Mode->id ) {

    case QUEX_NAME(ModeID_MAIN): {

    return true;
    }

    default: {

    return true;
    }

    }

}
#endif    
#undef self
#undef LexemeNull
#undef RETURN
QUEX_NAMESPACE_MAIN_CLOSE

/* #include "Lexer"*/
QUEX_NAMESPACE_MAIN_OPEN
#ifdef      QUEX_FUNCTION_COUNT_ARBITRARY
#   undef   QUEX_FUNCTION_COUNT_ARBITRARY
#endif
#ifdef      QUEX_OPTION_COUNTER
#    define QUEX_FUNCTION_COUNT_ARBITRARY(ME, BEGIN, END) \
            do {                              \
                QUEX_NAME(MAIN_counter)((ME), (BEGIN), (END));     \
                __quex_debug_counter();       \
            } while(0)
#else
#    define QUEX_FUNCTION_COUNT_ARBITRARY(ME, BEGIN, END) /* empty */
#endif
#ifdef QUEX_OPTION_COUNTER
static void
QUEX_NAME(MAIN_counter)(QUEX_TYPE_ANALYZER* me, QUEX_TYPE_LEXATOM* LexemeBegin, QUEX_TYPE_LEXATOM* LexemeEnd)
{
#   define self (*me)
/*  'QUEX_GOTO_STATE' requires 'QUEX_LABEL_STATE_ROUTER' */
#   define QUEX_LABEL_STATE_ROUTER _20
    QUEX_TYPE_LEXATOM              input                          = (QUEX_TYPE_LEXATOM)(0x00);
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
#   ifdef QUEX_OPTION_COUNTER_COLUMN
    QUEX_TYPE_LEXATOM*             count_reference_p              = (QUEX_TYPE_LEXATOM*)0x0;
#   endif /* QUEX_OPTION_COUNTER_COLUMN */
    (void)me;
    __QUEX_IF_COUNT_SHIFT_VALUES();
    /* Allow LexemeBegin == LexemeEnd (e.g. END_OF_STREAM)
     * => Caller does not need to check
     * BUT, if so quit immediately after 'shift values'.
     */
    __quex_assert(LexemeBegin <= LexemeEnd);
    if( LexemeBegin == LexemeEnd ) {
        return;
    }
    me->buffer._read_p = LexemeBegin;

    /* (836 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_14:
    __quex_debug("Init State\n");
    __quex_debug_state(836);
switch( input ) {
case 0x9: goto _3;
case 0xA: goto _2;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _5;
default: goto _4;
}


    __quex_assert_no_passage();
_9:
    /* (836 from 840)  */
    goto _14;


    __quex_assert_no_passage();
_8:
    /* (DROP_OUT from 839)  */
    goto _13;
_15:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_6:
    /* (DROP_OUT from 837)  */
    goto _11;


    __quex_assert_no_passage();
_7:
    /* (DROP_OUT from 838)  */
    goto _12;


    __quex_assert_no_passage();
_5:
    /* (DROP_OUT from 836)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _16;
    goto _15;


    __quex_assert_no_passage();
_2:
    /* (837 from 836)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(837);
goto _6;


    __quex_assert_no_passage();
_3:
    /* (838 from 836)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(838);
goto _7;


    __quex_assert_no_passage();
_4:
    /* (839 from 836)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(839);
goto _8;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_10:
    __quex_debug("* TERMINAL <LOOP EXIT>\n");
    --(me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _0;

_11:
    __quex_debug("* TERMINAL <LOOP 239>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_12:
    __quex_debug("* TERMINAL <LOOP 240>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_13:
    __quex_debug("* TERMINAL <LOOP 241>\n");
if( me->buffer._read_p != LexemeEnd ) goto _9;

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _0;

if(0) {
    /* Avoid unreferenced labels. */
    goto _10;
    goto _11;
    goto _12;
    goto _13;
}
_21: /* TERMINAL: BAD_LEXATOM */
;
_16: /* TERMINAL: FAILURE     */
goto _0;
_0:
/* Assert: lexeme in codec's character boundaries. */

     __quex_assert(me->buffer._read_p == LexemeEnd);
    return;
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_20:
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */

#undef self


#undef QUEX_LABEL_STATE_ROUTER

#    if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
     goto _20; /* in QUEX_GOTO_STATE       */
     goto _21; /* to BAD_LEXATOM           */
#    endif
    /* Avoid compiler warning: 'Unused labels' */

    goto _16;
    (void)target_state_index;
    (void)target_state_else_index;
}
#endif /* QUEX_OPTION_COUNTER */

#include <quex/code_base/buffer/Buffer>
#include <quex/code_base/token/TokenQueue>

#ifdef    CONTINUE
#   undef CONTINUE
#endif
#define   CONTINUE do { goto _386; } while(0)

#ifdef    RETURN
#   undef RETURN
#endif
#define   RETURN   do { goto _385; } while(0)

__QUEX_TYPE_ANALYZER_RETURN_VALUE  
QUEX_NAME(MAIN_analyzer_function)(QUEX_TYPE_ANALYZER* me) 
{
    /* NOTE: Different modes correspond to different analyzer functions. The 
     *       analyzer functions are all located inside the main class as static
     *       functions. That means, they are something like 'globals'. They 
     *       receive a pointer to the lexical analyzer, since static members do
     *       not have access to the 'this' pointer.                          */
#   ifdef     self
#       undef self
#   endif
#   define self (*((QUEX_TYPE_ANALYZER*)me))
/*  'QUEX_GOTO_STATE' requires 'QUEX_LABEL_STATE_ROUTER' */
#   define QUEX_LABEL_STATE_ROUTER _388

    /* Lexeme setup: 
     *
     * There is a temporary zero stored at the end of each lexeme, if the action 
     * references to the 'Lexeme'. 'LexemeNull' provides a reference to an empty
     * zero terminated string.                                                    */
#if defined(QUEX_OPTION_ASSERTS)
#   define Lexeme       QUEX_NAME(access_Lexeme)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeBegin  QUEX_NAME(access_LexemeBegin)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeL      QUEX_NAME(access_LexemeL)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeEnd    QUEX_NAME(access_LexemeEnd)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#else
#   define Lexeme       (me->buffer._lexeme_start_p)
#   define LexemeBegin  Lexeme
#   define LexemeL      ((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p))
#   define LexemeEnd    me->buffer._read_p
#endif

#define LexemeNull      (&QUEX_LEXEME_NULL)
    QUEX_TYPE_LEXATOM**            position                       = 0x0;
    E_LoadResult                   load_result                    = E_LoadResult_VOID;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
    const size_t                   PositionRegisterN              = (size_t)0;
    QUEX_TYPE_LEXATOM              input                          = (QUEX_TYPE_LEXATOM)(0x00);
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
#   ifdef QUEX_OPTION_COUNTER_COLUMN
    QUEX_TYPE_LEXATOM*             count_reference_p              = (QUEX_TYPE_LEXATOM*)0x0;
#   endif /* QUEX_OPTION_COUNTER_COLUMN */

    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */
#   if defined(QUEX_OPTION_ASSERTS)
    me->DEBUG_analyzer_function_at_entry = me->current_analyzer_function;
#   endif
_387:
    me->buffer._lexeme_start_p = me->buffer._read_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);
_77:
    /* (778 from BEFORE_ENTRY) (778 from RELOAD_FORWARD)  */

    input = *(me->buffer._read_p);


    __quex_debug("Init State\n");
    __quex_debug_state(778);
switch( input ) {
case 0x0: goto _155;
case 0x1: goto _134;
case 0x9: goto _85;
case 0xA: goto _82;
case 0xD: 
case 0x20: goto _79;
case 0x22: goto _92;
case 0x23: goto _83;
case 0x2B: goto _88;
case 0x2D: goto _89;
case 0x2E: goto _90;
case 0x30: goto _91;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _95;
case 0x3C: goto _94;
case 0x3D: goto _78;
case 0x3E: goto _81;
case 0x62: goto _87;
case 0x63: goto _86;
case 0x64: case 0x65: 
case 0x6B: goto _87;
case 0x7B: goto _93;
case 0x7D: goto _80;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _84;
}


    __quex_assert_no_passage();
_134:
    /* (DROP_OUT from 817) (DROP_OUT from 827) (DROP_OUT from 814) (DROP_OUT from 821) (DROP_OUT from 824) (DROP_OUT from 818) (DROP_OUT from 793) (DROP_OUT from 815) (DROP_OUT from 822) (DROP_OUT from 825) (DROP_OUT from 812) (DROP_OUT from 819) (DROP_OUT from 816) (DROP_OUT from 778) (DROP_OUT from 823) (DROP_OUT from 820)  */

        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _76;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_135:
    /* (DROP_OUT from 779)  */
    goto _58;


    __quex_assert_no_passage();
_136:
    /* (DROP_OUT from 780)  */
    goto _38;


    __quex_assert_no_passage();
_137:
    /* (DROP_OUT from 781)  */
    goto _64;


    __quex_assert_no_passage();
_138:
    /* (DROP_OUT from 782)  */
    goto _62;


    __quex_assert_no_passage();
_139:
    /* (DROP_OUT from 783)  */
    goto _36;


    __quex_assert_no_passage();
_140:
    /* (DROP_OUT from 784)  */
    goto _56;


    __quex_assert_no_passage();
_141:
    /* (DROP_OUT from 789) (DROP_OUT from 810) (DROP_OUT from 804) (DROP_OUT from 801) (DROP_OUT from 790) (DROP_OUT from 787) (DROP_OUT from 831) (DROP_OUT from 828) (DROP_OUT from 797) (DROP_OUT from 791) (DROP_OUT from 806) (DROP_OUT from 788) (DROP_OUT from 809) (DROP_OUT from 785) (DROP_OUT from 829)  */
    goto _72;


    __quex_assert_no_passage();
_142:
    /* (DROP_OUT from 786)  */
    goto _37;


    __quex_assert_no_passage();
_143:
    /* (DROP_OUT from 792) (DROP_OUT from 799) (DROP_OUT from 796) (DROP_OUT from 800) (DROP_OUT from 798)  */
    goto _65;


    __quex_assert_no_passage();
_144:
    /* (DROP_OUT from 794)  */
    goto _63;


    __quex_assert_no_passage();
_145:
    /* (DROP_OUT from 795)  */
    goto _60;


    __quex_assert_no_passage();
_146:
    /* (DROP_OUT from 808) (DROP_OUT from 802) (DROP_OUT from 803)  */
    goto _66;


    __quex_assert_no_passage();
_147:
    /* (DROP_OUT from 807) (DROP_OUT from 805)  */
    goto _67;


    __quex_assert_no_passage();
_148:
    /* (DROP_OUT from 811)  */
    goto _59;


    __quex_assert_no_passage();
_149:
    /* (DROP_OUT from 813)  */
    goto _69;


    __quex_assert_no_passage();
_150:
    /* (DROP_OUT from 826)  */
    goto _68;


    __quex_assert_no_passage();
_151:
    /* (DROP_OUT from 830)  */
    goto _71;


    __quex_assert_no_passage();
_152:
    /* (DROP_OUT from 832)  */
    goto _70;


    __quex_assert_no_passage();
_153:
    /* (DROP_OUT from 833)  */
    goto _61;


    __quex_assert_no_passage();
_154:
    /* (DROP_OUT from 834)  */
    goto _57;


    __quex_assert_no_passage();
_78:
    /* (779 from 778)  */
    ++(me->buffer._read_p);

_251:
    input = *(me->buffer._read_p);


    __quex_debug_state(779);
if     ( input == 0x3D )  goto _133;
else if( input == 0x0 )   goto _157;
else                      goto _135;


    __quex_assert_no_passage();
_156:
    /* (779 from RELOAD_FORWARD)  */
    goto _251;


    __quex_assert_no_passage();
_79:
    /* (780 from 778)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(780);
goto _136;


    __quex_assert_no_passage();
_80:
    /* (781 from 778)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(781);
goto _137;


    __quex_assert_no_passage();
_81:
    /* (782 from 778)  */
    ++(me->buffer._read_p);

_255:
    input = *(me->buffer._read_p);


    __quex_debug_state(782);
if     ( input == 0x3D )  goto _132;
else if( input == 0x0 )   goto _159;
else                      goto _138;


    __quex_assert_no_passage();
_158:
    /* (782 from RELOAD_FORWARD)  */
    goto _255;


    __quex_assert_no_passage();
_82:
    /* (783 from 778)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(783);
goto _139;


    __quex_assert_no_passage();
_83:
    /* (784 from 778)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(784);
goto _140;


    __quex_assert_no_passage();
_84:
    /* (785 from 797) (785 from 802) (785 from 792) (785 from 790) (785 from 808) (785 from 785) (785 from 829) (785 from 806) (785 from 796) (785 from 801) (785 from 778) (785 from 799) (785 from 789) (785 from 828) (785 from 805) (785 from 810) (785 from 787) (785 from 831) (785 from 800) (785 from 798) (785 from 803) (785 from 788) (785 from 791) (785 from 804) (785 from 832) (785 from 809) (785 from 830) (785 from 807)  */

    ++(me->buffer._read_p);

_260:
    input = *(me->buffer._read_p);


    __quex_debug_state(785);
switch( input ) {
case 0x0: goto _161;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _84;
}


    __quex_assert_no_passage();
_160:
    /* (785 from RELOAD_FORWARD)  */
    goto _260;


    __quex_assert_no_passage();
_85:
    /* (786 from 778)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(786);
goto _142;


    __quex_assert_no_passage();
_86:
    /* (787 from 778)  */
    ++(me->buffer._read_p);

_263:
    input = *(me->buffer._read_p);


    __quex_debug_state(787);
switch( input ) {
case 0x0: goto _163;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _141;
case 0x5F: goto _130;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _84;
}


    __quex_assert_no_passage();
_162:
    /* (787 from RELOAD_FORWARD)  */
    goto _263;


    __quex_assert_no_passage();
_164:
    /* (788 from RELOAD_FORWARD)  */
_265:
    input = *(me->buffer._read_p);


    __quex_debug_state(788);
switch( input ) {
case 0x0: goto _165;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _141;
case 0x5F: goto _127;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _84;
}


    __quex_assert_no_passage();
_87:
    /* (788 from 778)  */
    ++(me->buffer._read_p);

    goto _265;


    __quex_assert_no_passage();
_88:
    /* (789 from 778)  */
    ++(me->buffer._read_p);

_267:
    input = *(me->buffer._read_p);


    __quex_debug_state(789);
switch( input ) {
case 0x0: goto _167;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x2E: goto _90;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _91;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _84;
}


    __quex_assert_no_passage();
_166:
    /* (789 from RELOAD_FORWARD)  */
    goto _267;


    __quex_assert_no_passage();
_168:
    /* (790 from RELOAD_FORWARD)  */
_269:
    input = *(me->buffer._read_p);


    __quex_debug_state(790);
switch( input ) {
case 0x0: goto _169;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x2E: goto _90;
case 0x30: goto _91;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _95;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _84;
}


    __quex_assert_no_passage();
_89:
    /* (790 from 778)  */
    ++(me->buffer._read_p);

    goto _269;


    __quex_assert_no_passage();
_90:
    /* (791 from 790) (791 from 789) (791 from 778) (791 from 792)  */

    ++(me->buffer._read_p);

_272:
    input = *(me->buffer._read_p);


    __quex_debug_state(791);
switch( input ) {
case 0x0: goto _171;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _107;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _84;
}


    __quex_assert_no_passage();
_170:
    /* (791 from RELOAD_FORWARD)  */
    goto _272;


    __quex_assert_no_passage();
_91:
    /* (792 from 778) (792 from 792) (792 from 789) (792 from 790) (792 from 800)  */

    ++(me->buffer._read_p);

_275:
    input = *(me->buffer._read_p);


    __quex_debug_state(792);
switch( input ) {
case 0x0: goto _173;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _143;
case 0x2E: goto _90;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _91;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _143;
default: goto _84;
}


    __quex_assert_no_passage();
_172:
    /* (792 from RELOAD_FORWARD)  */
    goto _275;


    __quex_assert_no_passage();
_174:
    /* (793 from RELOAD_FORWARD)  */
_277:
    input = *(me->buffer._read_p);


    __quex_debug_state(793);
switch( input ) {
case 0x0: goto _175;
case 0x1: 
case 0xA: 
case 0xD: goto _134;
case 0x22: goto _112;
case 0x2D: goto _111;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _113;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _114;
}


    __quex_assert_no_passage();
_92:
    /* (793 from 778)  */
    ++(me->buffer._read_p);

    goto _277;


    __quex_assert_no_passage();
_93:
    /* (794 from 778)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(794);
goto _144;


    __quex_assert_no_passage();
_176:
    /* (795 from RELOAD_FORWARD)  */
_280:
    input = *(me->buffer._read_p);


    __quex_debug_state(795);
if     ( input == 0x3D )  goto _110;
else if( input == 0x0 )   goto _177;
else                      goto _145;


    __quex_assert_no_passage();
_94:
    /* (795 from 778)  */
    ++(me->buffer._read_p);

    goto _280;


    __quex_assert_no_passage();
_95:
    /* (796 from 790) (796 from 778)  */

    ++(me->buffer._read_p);

_283:
    input = *(me->buffer._read_p);


    __quex_debug_state(796);
switch( input ) {
case 0x0: goto _179;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _143;
case 0x2E: goto _96;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _97;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _143;
default: goto _84;
}


    __quex_assert_no_passage();
_178:
    /* (796 from RELOAD_FORWARD)  */
    goto _283;


    __quex_assert_no_passage();
_96:
    /* (797 from 796) (797 from 798) (797 from 799) (797 from 800)  */

    ++(me->buffer._read_p);

_286:
    input = *(me->buffer._read_p);


    __quex_debug_state(797);
switch( input ) {
case 0x0: goto _181;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x2D: goto _100;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _101;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _84;
}


    __quex_assert_no_passage();
_180:
    /* (797 from RELOAD_FORWARD)  */
    goto _286;


    __quex_assert_no_passage();
_97:
    /* (798 from 796)  */
    ++(me->buffer._read_p);

_288:
    input = *(me->buffer._read_p);


    __quex_debug_state(798);
switch( input ) {
case 0x0: goto _183;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _143;
case 0x2E: goto _96;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _98;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _143;
default: goto _84;
}


    __quex_assert_no_passage();
_182:
    /* (798 from RELOAD_FORWARD)  */
    goto _288;


    __quex_assert_no_passage();
_98:
    /* (799 from 798)  */
    ++(me->buffer._read_p);

_290:
    input = *(me->buffer._read_p);


    __quex_debug_state(799);
switch( input ) {
case 0x0: goto _185;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _143;
case 0x2E: goto _96;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _99;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _143;
default: goto _84;
}


    __quex_assert_no_passage();
_184:
    /* (799 from RELOAD_FORWARD)  */
    goto _290;


    __quex_assert_no_passage();
_186:
    /* (800 from RELOAD_FORWARD)  */
_292:
    input = *(me->buffer._read_p);


    __quex_debug_state(800);
switch( input ) {
case 0x0: goto _187;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _143;
case 0x2E: goto _96;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _91;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _143;
default: goto _84;
}


    __quex_assert_no_passage();
_99:
    /* (800 from 799)  */
    ++(me->buffer._read_p);

    goto _292;


    __quex_assert_no_passage();
_100:
    /* (801 from 797)  */
    ++(me->buffer._read_p);

_294:
    input = *(me->buffer._read_p);


    __quex_debug_state(801);
switch( input ) {
case 0x0: goto _189;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _108;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _84;
}


    __quex_assert_no_passage();
_188:
    /* (801 from RELOAD_FORWARD)  */
    goto _294;


    __quex_assert_no_passage();
_101:
    /* (802 from 797)  */
    ++(me->buffer._read_p);

_296:
    input = *(me->buffer._read_p);


    __quex_debug_state(802);
switch( input ) {
case 0x0: goto _191;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _146;
case 0x2E: goto _103;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _102;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _146;
default: goto _84;
}


    __quex_assert_no_passage();
_190:
    /* (802 from RELOAD_FORWARD)  */
    goto _296;


    __quex_assert_no_passage();
_192:
    /* (803 from RELOAD_FORWARD)  */
_298:
    input = *(me->buffer._read_p);


    __quex_debug_state(803);
switch( input ) {
case 0x0: goto _193;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _146;
case 0x2E: goto _103;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _107;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _146;
default: goto _84;
}


    __quex_assert_no_passage();
_102:
    /* (803 from 802)  */
    ++(me->buffer._read_p);

    goto _298;


    __quex_assert_no_passage();
_103:
    /* (804 from 803) (804 from 802) (804 from 809) (804 from 810)  */

    ++(me->buffer._read_p);

_301:
    input = *(me->buffer._read_p);


    __quex_debug_state(804);
switch( input ) {
case 0x0: goto _195;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x2D: goto _105;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _104;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _84;
}


    __quex_assert_no_passage();
_194:
    /* (804 from RELOAD_FORWARD)  */
    goto _301;


    __quex_assert_no_passage();
_104:
    /* (805 from 804) (805 from 806)  */

    ++(me->buffer._read_p);

_304:
    input = *(me->buffer._read_p);


    __quex_debug_state(805);
switch( input ) {
case 0x0: goto _197;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _147;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _106;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _147;
default: goto _84;
}


    __quex_assert_no_passage();
_196:
    /* (805 from RELOAD_FORWARD)  */
    goto _304;


    __quex_assert_no_passage();
_105:
    /* (806 from 804)  */
    ++(me->buffer._read_p);

_306:
    input = *(me->buffer._read_p);


    __quex_debug_state(806);
switch( input ) {
case 0x0: goto _199;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _104;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _84;
}


    __quex_assert_no_passage();
_198:
    /* (806 from RELOAD_FORWARD)  */
    goto _306;


    __quex_assert_no_passage();
_106:
    /* (807 from 805)  */
    ++(me->buffer._read_p);

_308:
    input = *(me->buffer._read_p);


    __quex_debug_state(807);
switch( input ) {
case 0x0: goto _201;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _147;
default: goto _84;
}


    __quex_assert_no_passage();
_200:
    /* (807 from RELOAD_FORWARD)  */
    goto _308;


    __quex_assert_no_passage();
_107:
    /* (808 from 803) (808 from 808) (808 from 791)  */

    ++(me->buffer._read_p);

_311:
    input = *(me->buffer._read_p);


    __quex_debug_state(808);
switch( input ) {
case 0x0: goto _203;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _146;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _107;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _146;
default: goto _84;
}


    __quex_assert_no_passage();
_202:
    /* (808 from RELOAD_FORWARD)  */
    goto _311;


    __quex_assert_no_passage();
_108:
    /* (809 from 801)  */
    ++(me->buffer._read_p);

_313:
    input = *(me->buffer._read_p);


    __quex_debug_state(809);
switch( input ) {
case 0x0: goto _205;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x2E: goto _103;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _109;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _84;
}


    __quex_assert_no_passage();
_204:
    /* (809 from RELOAD_FORWARD)  */
    goto _313;


    __quex_assert_no_passage();
_206:
    /* (810 from RELOAD_FORWARD)  */
_315:
    input = *(me->buffer._read_p);


    __quex_debug_state(810);
switch( input ) {
case 0x0: goto _207;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x2E: goto _103;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _84;
}


    __quex_assert_no_passage();
_109:
    /* (810 from 809)  */
    ++(me->buffer._read_p);

    goto _315;


    __quex_assert_no_passage();
_110:
    /* (811 from 795)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(811);
goto _148;


    __quex_assert_no_passage();
_111:
    /* (812 from 793)  */
    ++(me->buffer._read_p);

_318:
    input = *(me->buffer._read_p);


    __quex_debug_state(812);
switch( input ) {
case 0x0: goto _209;
case 0x1: 
case 0xA: 
case 0xD: goto _134;
case 0x22: goto _112;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _113;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _114;
}


    __quex_assert_no_passage();
_208:
    /* (812 from RELOAD_FORWARD)  */
    goto _318;


    __quex_assert_no_passage();
_112:
    /* (813 from 812) (813 from 821) (813 from 816) (813 from 793) (813 from 820) (813 from 815) (813 from 824) (813 from 819) (813 from 814) (813 from 823) (813 from 818) (813 from 822) (813 from 817)  */

    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(813);
goto _149;


    __quex_assert_no_passage();
_113:
    /* (814 from 793) (814 from 812)  */

    ++(me->buffer._read_p);

_323:
    input = *(me->buffer._read_p);


    __quex_debug_state(814);
switch( input ) {
case 0x0: goto _211;
case 0x1: 
case 0xA: 
case 0xD: goto _134;
case 0x22: goto _112;
case 0x2E: goto _115;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _116;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _114;
}


    __quex_assert_no_passage();
_210:
    /* (814 from RELOAD_FORWARD)  */
    goto _323;


    __quex_assert_no_passage();
_114:
    /* (815 from 822) (815 from 815) (815 from 824) (815 from 817) (815 from 814) (815 from 821) (815 from 827) (815 from 816) (815 from 820) (815 from 819) (815 from 823) (815 from 812) (815 from 793) (815 from 818) (815 from 825)  */

    ++(me->buffer._read_p);

_326:
    input = *(me->buffer._read_p);


    __quex_debug_state(815);
switch( input ) {
case 0x0: goto _213;
case 0x1: 
case 0xA: 
case 0xD: goto _134;
case 0x22: goto _112;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _114;
}


    __quex_assert_no_passage();
_212:
    /* (815 from RELOAD_FORWARD)  */
    goto _326;


    __quex_assert_no_passage();
_115:
    /* (816 from 819) (816 from 818) (816 from 817) (816 from 814)  */

    ++(me->buffer._read_p);

_329:
    input = *(me->buffer._read_p);


    __quex_debug_state(816);
switch( input ) {
case 0x0: goto _215;
case 0x1: 
case 0xA: 
case 0xD: goto _134;
case 0x22: goto _112;
case 0x2D: goto _120;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _119;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _114;
}


    __quex_assert_no_passage();
_214:
    /* (816 from RELOAD_FORWARD)  */
    goto _329;


    __quex_assert_no_passage();
_216:
    /* (817 from RELOAD_FORWARD)  */
_331:
    input = *(me->buffer._read_p);


    __quex_debug_state(817);
switch( input ) {
case 0x0: goto _217;
case 0x1: 
case 0xA: 
case 0xD: goto _134;
case 0x22: goto _112;
case 0x2E: goto _115;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _117;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _114;
}


    __quex_assert_no_passage();
_116:
    /* (817 from 814)  */
    ++(me->buffer._read_p);

    goto _331;


    __quex_assert_no_passage();
_117:
    /* (818 from 817)  */
    ++(me->buffer._read_p);

_333:
    input = *(me->buffer._read_p);


    __quex_debug_state(818);
switch( input ) {
case 0x0: goto _219;
case 0x1: 
case 0xA: 
case 0xD: goto _134;
case 0x22: goto _112;
case 0x2E: goto _115;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _118;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _114;
}


    __quex_assert_no_passage();
_218:
    /* (818 from RELOAD_FORWARD)  */
    goto _333;


    __quex_assert_no_passage();
_118:
    /* (819 from 818)  */
    ++(me->buffer._read_p);

_335:
    input = *(me->buffer._read_p);


    __quex_debug_state(819);
switch( input ) {
case 0x0: goto _221;
case 0x1: 
case 0xA: 
case 0xD: goto _134;
case 0x22: goto _112;
case 0x2E: goto _115;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _114;
}


    __quex_assert_no_passage();
_220:
    /* (819 from RELOAD_FORWARD)  */
    goto _335;


    __quex_assert_no_passage();
_119:
    /* (820 from 821) (820 from 816)  */

    ++(me->buffer._read_p);

_338:
    input = *(me->buffer._read_p);


    __quex_debug_state(820);
switch( input ) {
case 0x0: goto _223;
case 0x1: 
case 0xA: 
case 0xD: goto _134;
case 0x22: goto _112;
case 0x2E: goto _121;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _122;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _114;
}


    __quex_assert_no_passage();
_222:
    /* (820 from RELOAD_FORWARD)  */
    goto _338;


    __quex_assert_no_passage();
_120:
    /* (821 from 816)  */
    ++(me->buffer._read_p);

_340:
    input = *(me->buffer._read_p);


    __quex_debug_state(821);
switch( input ) {
case 0x0: goto _225;
case 0x1: 
case 0xA: 
case 0xD: goto _134;
case 0x22: goto _112;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _119;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _114;
}


    __quex_assert_no_passage();
_224:
    /* (821 from RELOAD_FORWARD)  */
    goto _340;


    __quex_assert_no_passage();
_121:
    /* (822 from 820) (822 from 823)  */

    ++(me->buffer._read_p);

_343:
    input = *(me->buffer._read_p);


    __quex_debug_state(822);
switch( input ) {
case 0x0: goto _227;
case 0x1: 
case 0xA: 
case 0xD: goto _134;
case 0x22: goto _112;
case 0x2D: goto _123;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _124;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _114;
}


    __quex_assert_no_passage();
_226:
    /* (822 from RELOAD_FORWARD)  */
    goto _343;


    __quex_assert_no_passage();
_228:
    /* (823 from RELOAD_FORWARD)  */
_345:
    input = *(me->buffer._read_p);


    __quex_debug_state(823);
switch( input ) {
case 0x0: goto _229;
case 0x1: 
case 0xA: 
case 0xD: goto _134;
case 0x22: goto _112;
case 0x2E: goto _121;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _114;
}


    __quex_assert_no_passage();
_122:
    /* (823 from 820)  */
    ++(me->buffer._read_p);

    goto _345;


    __quex_assert_no_passage();
_230:
    /* (824 from RELOAD_FORWARD)  */
_347:
    input = *(me->buffer._read_p);


    __quex_debug_state(824);
switch( input ) {
case 0x0: goto _231;
case 0x1: 
case 0xA: 
case 0xD: goto _134;
case 0x22: goto _112;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _124;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _114;
}


    __quex_assert_no_passage();
_123:
    /* (824 from 822)  */
    ++(me->buffer._read_p);

    goto _347;


    __quex_assert_no_passage();
_124:
    /* (825 from 824) (825 from 822)  */

    ++(me->buffer._read_p);

_350:
    input = *(me->buffer._read_p);


    __quex_debug_state(825);
switch( input ) {
case 0x0: goto _233;
case 0x1: 
case 0xA: 
case 0xD: goto _134;
case 0x22: goto _125;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _126;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _114;
}


    __quex_assert_no_passage();
_232:
    /* (825 from RELOAD_FORWARD)  */
    goto _350;


    __quex_assert_no_passage();
_125:
    /* (826 from 825) (826 from 827)  */

    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(826);
goto _150;


    __quex_assert_no_passage();
_126:
    /* (827 from 825)  */
    ++(me->buffer._read_p);

_354:
    input = *(me->buffer._read_p);


    __quex_debug_state(827);
switch( input ) {
case 0x0: goto _235;
case 0x1: 
case 0xA: 
case 0xD: goto _134;
case 0x22: goto _125;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _134;
default: goto _114;
}


    __quex_assert_no_passage();
_234:
    /* (827 from RELOAD_FORWARD)  */
    goto _354;


    __quex_assert_no_passage();
_236:
    /* (828 from RELOAD_FORWARD)  */
_356:
    input = *(me->buffer._read_p);


    __quex_debug_state(828);
switch( input ) {
case 0x0: goto _237;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _141;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _128;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _84;
}


    __quex_assert_no_passage();
_127:
    /* (828 from 788)  */
    ++(me->buffer._read_p);

    goto _356;


    __quex_assert_no_passage();
_128:
    /* (829 from 828) (829 from 831)  */

    ++(me->buffer._read_p);

_359:
    input = *(me->buffer._read_p);


    __quex_debug_state(829);
switch( input ) {
case 0x0: goto _239;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x2D: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _129;
case 0x3C: case 0x3D: case 0x3E: goto _141;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _129;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _84;
}


    __quex_assert_no_passage();
_238:
    /* (829 from RELOAD_FORWARD)  */
    goto _359;


    __quex_assert_no_passage();
_129:
    /* (830 from 829) (830 from 830)  */

    ++(me->buffer._read_p);

_362:
    input = *(me->buffer._read_p);


    __quex_debug_state(830);
switch( input ) {
case 0x0: goto _241;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _151;
case 0x2D: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _129;
case 0x3C: case 0x3D: case 0x3E: goto _151;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _129;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _84;
}


    __quex_assert_no_passage();
_240:
    /* (830 from RELOAD_FORWARD)  */
    goto _362;


    __quex_assert_no_passage();
_242:
    /* (831 from RELOAD_FORWARD)  */
_364:
    input = *(me->buffer._read_p);


    __quex_debug_state(831);
switch( input ) {
case 0x0: goto _243;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _131;
case 0x3C: case 0x3D: case 0x3E: goto _141;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _128;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _84;
}


    __quex_assert_no_passage();
_130:
    /* (831 from 787)  */
    ++(me->buffer._read_p);

    goto _364;


    __quex_assert_no_passage();
_131:
    /* (832 from 832) (832 from 831)  */

    ++(me->buffer._read_p);

_367:
    input = *(me->buffer._read_p);


    __quex_debug_state(832);
switch( input ) {
case 0x0: goto _245;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _152;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _131;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _152;
default: goto _84;
}


    __quex_assert_no_passage();
_244:
    /* (832 from RELOAD_FORWARD)  */
    goto _367;


    __quex_assert_no_passage();
_132:
    /* (833 from 782)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(833);
goto _153;


    __quex_assert_no_passage();
_133:
    /* (834 from 779)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(834);
goto _154;
_17:
    /* (535 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

_371:
__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_370:
    __quex_debug("Init State\n");
    __quex_debug_state(535);
switch( input ) {
case 0x0: goto _29;
case 0x9: goto _19;
case 0xA: goto _18;
case 0xD: 
case 0x20: goto _20;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _22;
default: goto _21;
}


    __quex_assert_no_passage();
_30:
    /* (535 from 541)  */
    goto _370;


    __quex_assert_no_passage();
_27:
    /* (535 from RELOAD_FORWARD)  */
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

    goto _371;


    __quex_assert_no_passage();
_26:
    /* (DROP_OUT from 539)  */
    goto _31;
_372:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_23:
    /* (DROP_OUT from 536)  */
    goto _32;


    __quex_assert_no_passage();
_24:
    /* (DROP_OUT from 537)  */
    goto _33;


    __quex_assert_no_passage();
_25:
    /* (DROP_OUT from 538)  */
    goto _34;


    __quex_assert_no_passage();
_22:
    /* (DROP_OUT from 535)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _76;
    goto _372;


    __quex_assert_no_passage();
_18:
    /* (536 from 535)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(536);
goto _23;


    __quex_assert_no_passage();
_19:
    /* (537 from 535)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(537);
goto _24;


    __quex_assert_no_passage();
_20:
    /* (538 from 535)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(538);
goto _25;


    __quex_assert_no_passage();
_21:
    /* (539 from 535)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(539);
goto _26;
_40:
    /* (568 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

_378:
__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_377:
    __quex_debug("Init State\n");
    __quex_debug_state(568);
switch( input ) {
case 0x0: goto _49;
case 0x9: goto _42;
case 0xA: goto _41;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _44;
default: goto _43;
}


    __quex_assert_no_passage();
_50:
    /* (568 from 572)  */
    goto _377;


    __quex_assert_no_passage();
_48:
    /* (568 from RELOAD_FORWARD)  */
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

    goto _378;


    __quex_assert_no_passage();
_47:
    /* (DROP_OUT from 571)  */
    goto _55;
_379:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_45:
    /* (DROP_OUT from 569)  */
    goto _53;


    __quex_assert_no_passage();
_46:
    /* (DROP_OUT from 570)  */
    goto _54;


    __quex_assert_no_passage();
_44:
    /* (DROP_OUT from 568)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _76;
    goto _379;


    __quex_assert_no_passage();
_41:
    /* (569 from 568)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(569);
goto _45;


    __quex_assert_no_passage();
_42:
    /* (570 from 568)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(570);
goto _46;


    __quex_assert_no_passage();
_43:
    /* (571 from 568)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(571);
goto _47;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_73:
    __quex_debug("* TERMINAL BAD_LEXATOM\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{
self.error_code = E_Error_NoHandler_OnBadLexatom;
self_send(QUEX_TOKEN_ID(TERMINATION));
__QUEX_PURE_RETURN;;

}
    /* Bad lexatom detection FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
__QUEX_PURE_RETURN;
_74:
    __quex_debug("* TERMINAL LOAD_FAILURE\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{
self.error_code = E_Error_NoHandler_OnLoadFailure;
self_send(QUEX_TOKEN_ID(TERMINATION));
__QUEX_PURE_RETURN;;

}
    /* Load failure FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
__QUEX_PURE_RETURN;
_75:
    __quex_debug("* TERMINAL OVERFLOW\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{
self.error_code = E_Error_NoHandler_OnOverflow;
self_send(QUEX_TOKEN_ID(TERMINATION));
__QUEX_PURE_RETURN;;

}
    /* Lexeme size exceeds buffer size. No further buffer load possible.
     */
__QUEX_PURE_RETURN;
_28:
    __quex_debug("* TERMINAL END_OF_STREAM\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 75 "zck.qx"
self_send(T_TERMINATION);

__QUEX_PURE_RETURN;


#   line 2551 "Lexer.cpp"

}
    /* End of Stream FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
__QUEX_PURE_RETURN;
_76:
    __quex_debug("* TERMINAL FAILURE\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 76 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_FAILURE);

__QUEX_PURE_RETURN;


#   line 2570 "Lexer.cpp"

}
RETURN;
_35:
    __quex_debug("* TERMINAL <skip>\n");
goto _17;
_39:
    __quex_debug("* TERMINAL SKIP_RANGE_OPEN\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{
#define Counter counter
self.error_code = E_Error_NoHandler_OnSkipRangeOpen;
self_send(QUEX_TOKEN_ID(TERMINATION));
__QUEX_PURE_RETURN;;

}
    /* End of Stream appeared, while scanning for end of skip-range.
     */
__QUEX_PURE_RETURN;
_31:
    __quex_debug("* TERMINAL <LOOP EXIT>\n");
    --(me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _16;

_32:
    __quex_debug("* TERMINAL <LOOP 163>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _30;

_33:
    __quex_debug("* TERMINAL <LOOP 164>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _30;

_34:
    __quex_debug("* TERMINAL <LOOP 165>\n");
goto _30;

_36:
    __quex_debug("* TERMINAL ENTER SKIP:\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

goto _35;

_37:
    __quex_debug("* TERMINAL ENTER SKIP:\n");
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

goto _35;

_38:
    __quex_debug("* TERMINAL ENTER SKIP:\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)1);

goto _35;

_52:
    __quex_debug("* TERMINAL <SKIP RANGE TERMINATED>\n");
goto _16;
_51:
    __quex_debug("* TERMINAL <LOOP EXIT>\n");
    --(me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _16;

_53:
    __quex_debug("* TERMINAL <COUPLE 178>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _52;

_54:
    __quex_debug("* TERMINAL <LOOP 179>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _50;

_55:
    __quex_debug("* TERMINAL <LOOP 180>\n");
goto _50;

_56:
    __quex_debug("* TERMINAL <skip range><skip_range open>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
goto _40;
_57:
    __quex_debug("* TERMINAL \"==\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 77 "zck.qx"
self_send(T_OP_DEQ);

__QUEX_PURE_RETURN;


#   line 2700 "Lexer.cpp"

}
RETURN;
_58:
    __quex_debug("* TERMINAL \"=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 78 "zck.qx"
self_send(T_OP_EQ);

__QUEX_PURE_RETURN;


#   line 2716 "Lexer.cpp"

}
RETURN;
_59:
    __quex_debug("* TERMINAL \"<=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 79 "zck.qx"
self_send(T_OP_LTEQ);

__QUEX_PURE_RETURN;


#   line 2732 "Lexer.cpp"

}
RETURN;
_60:
    __quex_debug("* TERMINAL \"<\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 80 "zck.qx"
self_send(T_OP_LT);

__QUEX_PURE_RETURN;


#   line 2748 "Lexer.cpp"

}
RETURN;
_61:
    __quex_debug("* TERMINAL \">=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 81 "zck.qx"
self_send(T_OP_GTEQ);

__QUEX_PURE_RETURN;


#   line 2764 "Lexer.cpp"

}
RETURN;
_62:
    __quex_debug("* TERMINAL \">\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 82 "zck.qx"
self_send(T_OP_GT);

__QUEX_PURE_RETURN;


#   line 2780 "Lexer.cpp"

}
RETURN;
_63:
    __quex_debug("* TERMINAL \"{\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 83 "zck.qx"
self_send(T_OPEN_BRACE);

__QUEX_PURE_RETURN;


#   line 2796 "Lexer.cpp"

}
RETURN;
_64:
    __quex_debug("* TERMINAL \"}\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 84 "zck.qx"
self_send(T_CLOSE_BRACE);

__QUEX_PURE_RETURN;


#   line 2812 "Lexer.cpp"

}
RETURN;
_65:
    __quex_debug("* TERMINAL {SIGN}[0-9]+\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 85 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_INTEGER);

__QUEX_PURE_RETURN;


#   line 2829 "Lexer.cpp"

}
RETURN;
_66:
    __quex_debug("* TERMINAL {DECIMAL}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 86 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_DECIMAL);

__QUEX_PURE_RETURN;


#   line 2846 "Lexer.cpp"

}
RETURN;
_67:
    __quex_debug("* TERMINAL {DATE}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 87 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_DATE);

__QUEX_PURE_RETURN;


#   line 2863 "Lexer.cpp"

}
RETURN;
_68:
    __quex_debug("* TERMINAL \"\\\"\"{DATE}\"\\\"\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 88 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), LexemeBegin+1, LexemeEnd-1);
self_send(T_QDATE);

__QUEX_PURE_RETURN;


#   line 2880 "Lexer.cpp"

}
RETURN;
_69:
    __quex_debug("* TERMINAL {QSTRING}\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 89 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), LexemeBegin+1, LexemeEnd-1);
self_send(T_QSTRING);

__QUEX_PURE_RETURN;


#   line 2896 "Lexer.cpp"

}
RETURN;
_70:
    __quex_debug("* TERMINAL {CHAR_ID}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 90 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_CHAR_SCOPE);

__QUEX_PURE_RETURN;


#   line 2913 "Lexer.cpp"

}
RETURN;
_71:
    __quex_debug("* TERMINAL {TITLE_ID}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 91 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_TITLE_ID);

__QUEX_PURE_RETURN;


#   line 2930 "Lexer.cpp"

}
RETURN;
_72:
    __quex_debug("* TERMINAL {STRING}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 92 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_STRING);

__QUEX_PURE_RETURN;


#   line 2947 "Lexer.cpp"

}
RETURN;
if(0) {
    /* Avoid unreferenced labels. */
    goto _73;
    goto _74;
    goto _75;
    goto _28;
    goto _76;
    goto _35;
    goto _39;
    goto _31;
    goto _32;
    goto _33;
    goto _34;
    goto _36;
    goto _37;
    goto _38;
    goto _52;
    goto _51;
    goto _53;
    goto _54;
    goto _55;
    goto _56;
    goto _57;
    goto _58;
    goto _59;
    goto _60;
    goto _61;
    goto _62;
    goto _63;
    goto _64;
    goto _65;
    goto _66;
    goto _67;
    goto _68;
    goto _69;
    goto _70;
    goto _71;
    goto _72;
}
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_388:
switch( target_state_index ) {
case 27: {
goto _27;}
case 28: {
goto _28;}
case 39: {
goto _39;}
case 48: {
goto _48;}
case 77: {
goto _77;}
case 134: {
goto _134;}
case 135: {
goto _135;}
case 138: {
goto _138;}
case 141: {
goto _141;}
case 143: {
goto _143;}
case 145: {
goto _145;}
case 146: {
goto _146;}
case 147: {
goto _147;}
case 151: {
goto _151;}
case 152: {
goto _152;}
case 156: {
goto _156;}
case 158: {
goto _158;}
case 160: {
goto _160;}
case 162: {
goto _162;}
case 164: {
goto _164;}
case 166: {
goto _166;}
case 168: {
goto _168;}
case 170: {
goto _170;}
case 172: {
goto _172;}
case 174: {
goto _174;}
case 176: {
goto _176;}
case 178: {
goto _178;}
case 180: {
goto _180;}
case 182: {
goto _182;}
case 184: {
goto _184;}
case 186: {
goto _186;}
case 188: {
goto _188;}
case 190: {
goto _190;}
case 192: {
goto _192;}
case 194: {
goto _194;}
case 196: {
goto _196;}
case 198: {
goto _198;}
case 200: {
goto _200;}
case 202: {
goto _202;}
case 204: {
goto _204;}
case 206: {
goto _206;}
case 208: {
goto _208;}
case 210: {
goto _210;}
case 212: {
goto _212;}
case 214: {
goto _214;}
case 216: {
goto _216;}
case 218: {
goto _218;}
case 220: {
goto _220;}
case 222: {
goto _222;}
case 224: {
goto _224;}
case 226: {
goto _226;}
case 228: {
goto _228;}
case 230: {
goto _230;}
case 232: {
goto _232;}
case 234: {
goto _234;}
case 236: {
goto _236;}
case 238: {
goto _238;}
case 240: {
goto _240;}
case 242: {
goto _242;}
case 244: {
goto _244;}
default: {
goto _244;}
}
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */


    __quex_assert_no_passage();
_29:
    /* (RELOAD_FORWARD from 535)  */
    target_state_index = QUEX_LABEL(27); target_state_else_index = QUEX_LABEL(28);

_384:
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

_383:

    __quex_debug3("RELOAD_FORWARD: success->%i; failure->%i", 
                  (int)target_state_index, (int)target_state_else_index);
    __quex_assert(*(me->buffer._read_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    
    __quex_debug_reload_before();                 
    load_result = QUEX_NAME(Buffer_load_forward)(&me->buffer, (QUEX_TYPE_LEXATOM**)position, PositionRegisterN);
    __quex_debug_reload_after(load_result);

    switch( load_result ) {
    case E_LoadResult_DONE:              QUEX_GOTO_STATE(target_state_index);      
    case E_LoadResult_BAD_LEXATOM:       goto _73;
    case E_LoadResult_FAILURE:           goto _74;
    case E_LoadResult_NO_SPACE_FOR_LOAD: goto _75;
    case E_LoadResult_NO_MORE_DATA:      QUEX_GOTO_STATE(target_state_else_index); 
    default:                             __quex_assert(false);
    }


    __quex_assert_no_passage();
_49:
    /* (RELOAD_FORWARD from 568)  */
    target_state_index = QUEX_LABEL(48); target_state_else_index = QUEX_LABEL(39);

    goto _384;


    __quex_assert_no_passage();
_155:
    /* (RELOAD_FORWARD from 778)  */
    target_state_index = QUEX_LABEL(77); target_state_else_index = QUEX_LABEL(28);

    goto _383;


    __quex_assert_no_passage();
_157:
    /* (RELOAD_FORWARD from 779)  */
    target_state_index = QUEX_LABEL(156); target_state_else_index = QUEX_LABEL(135);

    goto _383;


    __quex_assert_no_passage();
_159:
    /* (RELOAD_FORWARD from 782)  */
    target_state_index = QUEX_LABEL(158); target_state_else_index = QUEX_LABEL(138);

    goto _383;


    __quex_assert_no_passage();
_161:
    /* (RELOAD_FORWARD from 785)  */
    target_state_index = QUEX_LABEL(160); target_state_else_index = QUEX_LABEL(141);

    goto _383;


    __quex_assert_no_passage();
_163:
    /* (RELOAD_FORWARD from 787)  */
    target_state_index = QUEX_LABEL(162); target_state_else_index = QUEX_LABEL(141);

    goto _383;


    __quex_assert_no_passage();
_165:
    /* (RELOAD_FORWARD from 788)  */
    target_state_index = QUEX_LABEL(164); target_state_else_index = QUEX_LABEL(141);

    goto _383;


    __quex_assert_no_passage();
_167:
    /* (RELOAD_FORWARD from 789)  */
    target_state_index = QUEX_LABEL(166); target_state_else_index = QUEX_LABEL(141);

    goto _383;


    __quex_assert_no_passage();
_169:
    /* (RELOAD_FORWARD from 790)  */
    target_state_index = QUEX_LABEL(168); target_state_else_index = QUEX_LABEL(141);

    goto _383;


    __quex_assert_no_passage();
_171:
    /* (RELOAD_FORWARD from 791)  */
    target_state_index = QUEX_LABEL(170); target_state_else_index = QUEX_LABEL(141);

    goto _383;


    __quex_assert_no_passage();
_173:
    /* (RELOAD_FORWARD from 792)  */
    target_state_index = QUEX_LABEL(172); target_state_else_index = QUEX_LABEL(143);

    goto _383;


    __quex_assert_no_passage();
_175:
    /* (RELOAD_FORWARD from 793)  */
    target_state_index = QUEX_LABEL(174); target_state_else_index = QUEX_LABEL(134);

    goto _383;


    __quex_assert_no_passage();
_177:
    /* (RELOAD_FORWARD from 795)  */
    target_state_index = QUEX_LABEL(176); target_state_else_index = QUEX_LABEL(145);

    goto _383;


    __quex_assert_no_passage();
_179:
    /* (RELOAD_FORWARD from 796)  */
    target_state_index = QUEX_LABEL(178); target_state_else_index = QUEX_LABEL(143);

    goto _383;


    __quex_assert_no_passage();
_181:
    /* (RELOAD_FORWARD from 797)  */
    target_state_index = QUEX_LABEL(180); target_state_else_index = QUEX_LABEL(141);

    goto _383;


    __quex_assert_no_passage();
_183:
    /* (RELOAD_FORWARD from 798)  */
    target_state_index = QUEX_LABEL(182); target_state_else_index = QUEX_LABEL(143);

    goto _383;


    __quex_assert_no_passage();
_185:
    /* (RELOAD_FORWARD from 799)  */
    target_state_index = QUEX_LABEL(184); target_state_else_index = QUEX_LABEL(143);

    goto _383;


    __quex_assert_no_passage();
_187:
    /* (RELOAD_FORWARD from 800)  */
    target_state_index = QUEX_LABEL(186); target_state_else_index = QUEX_LABEL(143);

    goto _383;


    __quex_assert_no_passage();
_189:
    /* (RELOAD_FORWARD from 801)  */
    target_state_index = QUEX_LABEL(188); target_state_else_index = QUEX_LABEL(141);

    goto _383;


    __quex_assert_no_passage();
_191:
    /* (RELOAD_FORWARD from 802)  */
    target_state_index = QUEX_LABEL(190); target_state_else_index = QUEX_LABEL(146);

    goto _383;


    __quex_assert_no_passage();
_193:
    /* (RELOAD_FORWARD from 803)  */
    target_state_index = QUEX_LABEL(192); target_state_else_index = QUEX_LABEL(146);

    goto _383;


    __quex_assert_no_passage();
_195:
    /* (RELOAD_FORWARD from 804)  */
    target_state_index = QUEX_LABEL(194); target_state_else_index = QUEX_LABEL(141);

    goto _383;


    __quex_assert_no_passage();
_197:
    /* (RELOAD_FORWARD from 805)  */
    target_state_index = QUEX_LABEL(196); target_state_else_index = QUEX_LABEL(147);

    goto _383;


    __quex_assert_no_passage();
_199:
    /* (RELOAD_FORWARD from 806)  */
    target_state_index = QUEX_LABEL(198); target_state_else_index = QUEX_LABEL(141);

    goto _383;


    __quex_assert_no_passage();
_201:
    /* (RELOAD_FORWARD from 807)  */
    target_state_index = QUEX_LABEL(200); target_state_else_index = QUEX_LABEL(147);

    goto _383;


    __quex_assert_no_passage();
_203:
    /* (RELOAD_FORWARD from 808)  */
    target_state_index = QUEX_LABEL(202); target_state_else_index = QUEX_LABEL(146);

    goto _383;


    __quex_assert_no_passage();
_205:
    /* (RELOAD_FORWARD from 809)  */
    target_state_index = QUEX_LABEL(204); target_state_else_index = QUEX_LABEL(141);

    goto _383;


    __quex_assert_no_passage();
_207:
    /* (RELOAD_FORWARD from 810)  */
    target_state_index = QUEX_LABEL(206); target_state_else_index = QUEX_LABEL(141);

    goto _383;


    __quex_assert_no_passage();
_209:
    /* (RELOAD_FORWARD from 812)  */
    target_state_index = QUEX_LABEL(208); target_state_else_index = QUEX_LABEL(134);

    goto _383;


    __quex_assert_no_passage();
_211:
    /* (RELOAD_FORWARD from 814)  */
    target_state_index = QUEX_LABEL(210); target_state_else_index = QUEX_LABEL(134);

    goto _383;


    __quex_assert_no_passage();
_213:
    /* (RELOAD_FORWARD from 815)  */
    target_state_index = QUEX_LABEL(212); target_state_else_index = QUEX_LABEL(134);

    goto _383;


    __quex_assert_no_passage();
_215:
    /* (RELOAD_FORWARD from 816)  */
    target_state_index = QUEX_LABEL(214); target_state_else_index = QUEX_LABEL(134);

    goto _383;


    __quex_assert_no_passage();
_217:
    /* (RELOAD_FORWARD from 817)  */
    target_state_index = QUEX_LABEL(216); target_state_else_index = QUEX_LABEL(134);

    goto _383;


    __quex_assert_no_passage();
_219:
    /* (RELOAD_FORWARD from 818)  */
    target_state_index = QUEX_LABEL(218); target_state_else_index = QUEX_LABEL(134);

    goto _383;


    __quex_assert_no_passage();
_221:
    /* (RELOAD_FORWARD from 819)  */
    target_state_index = QUEX_LABEL(220); target_state_else_index = QUEX_LABEL(134);

    goto _383;


    __quex_assert_no_passage();
_223:
    /* (RELOAD_FORWARD from 820)  */
    target_state_index = QUEX_LABEL(222); target_state_else_index = QUEX_LABEL(134);

    goto _383;


    __quex_assert_no_passage();
_225:
    /* (RELOAD_FORWARD from 821)  */
    target_state_index = QUEX_LABEL(224); target_state_else_index = QUEX_LABEL(134);

    goto _383;


    __quex_assert_no_passage();
_227:
    /* (RELOAD_FORWARD from 822)  */
    target_state_index = QUEX_LABEL(226); target_state_else_index = QUEX_LABEL(134);

    goto _383;


    __quex_assert_no_passage();
_229:
    /* (RELOAD_FORWARD from 823)  */
    target_state_index = QUEX_LABEL(228); target_state_else_index = QUEX_LABEL(134);

    goto _383;


    __quex_assert_no_passage();
_231:
    /* (RELOAD_FORWARD from 824)  */
    target_state_index = QUEX_LABEL(230); target_state_else_index = QUEX_LABEL(134);

    goto _383;


    __quex_assert_no_passage();
_233:
    /* (RELOAD_FORWARD from 825)  */
    target_state_index = QUEX_LABEL(232); target_state_else_index = QUEX_LABEL(134);

    goto _383;


    __quex_assert_no_passage();
_235:
    /* (RELOAD_FORWARD from 827)  */
    target_state_index = QUEX_LABEL(234); target_state_else_index = QUEX_LABEL(134);

    goto _383;


    __quex_assert_no_passage();
_237:
    /* (RELOAD_FORWARD from 828)  */
    target_state_index = QUEX_LABEL(236); target_state_else_index = QUEX_LABEL(141);

    goto _383;


    __quex_assert_no_passage();
_239:
    /* (RELOAD_FORWARD from 829)  */
    target_state_index = QUEX_LABEL(238); target_state_else_index = QUEX_LABEL(141);

    goto _383;


    __quex_assert_no_passage();
_241:
    /* (RELOAD_FORWARD from 830)  */
    target_state_index = QUEX_LABEL(240); target_state_else_index = QUEX_LABEL(151);

    goto _383;


    __quex_assert_no_passage();
_243:
    /* (RELOAD_FORWARD from 831)  */
    target_state_index = QUEX_LABEL(242); target_state_else_index = QUEX_LABEL(141);

    goto _383;


    __quex_assert_no_passage();
_245:
    /* (RELOAD_FORWARD from 832)  */
    target_state_index = QUEX_LABEL(244); target_state_else_index = QUEX_LABEL(152);

    goto _383;

_385:
/* RETURN -- after executing 'on_after_match' code. */
    __QUEX_PURE_RETURN;


_386:
/* CONTINUE -- after executing 'on_after_match' code. */

_16:
/* CONTINUE -- without executing 'on_after_match' (e.g. on FAILURE). */


    /* Mode change = another function takes over the analysis.
     * => After mode change the analyzer function needs to be quit!
     * ASSERT: 'CONTINUE' after mode change is not allowed.                   */
    __quex_assert(   me->DEBUG_analyzer_function_at_entry 
                  == me->current_analyzer_function);


    if( QUEX_NAME(TokenQueue_is_full)(&self._token_queue) ) {
        return;
    }


goto _387;

    __quex_assert_no_passage();

    /* Following labels are referenced in macros. It cannot be detected
     * whether the macros are applied in user code or not. To avoid compiler.
     * warnings of unused labels, they are referenced in unreachable code.   */
    goto _385; /* in RETURN                */
    goto _386; /* in CONTINUE              */
    goto _16; /* in CONTINUE and skippers */
#   if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
    goto _388; /* in QUEX_GOTO_STATE       */
#   endif

    /* Prevent compiler warning 'unused variable'.                           */
    (void)QUEX_LEXEME_NULL;
    /* target_state_index and target_state_else_index appear when 
     * QUEX_GOTO_STATE is used without computed goto-s.                      */
    (void)target_state_index;
    (void)target_state_else_index;

#   undef Lexeme
#   undef LexemeBegin
#   undef LexemeEnd
#   undef LexemeNull
#   undef LexemeL
#   undef self
#   undef QUEX_LABEL_STATE_ROUTER
}
QUEX_NAMESPACE_MAIN_CLOSE


QUEX_NAMESPACE_MAIN_OPEN

bool
QUEX_NAME(user_constructor)(QUEX_TYPE_ANALYZER* me)
{
    (void)me;

    __quex_assert(QUEX_NAME(mode_db)[QUEX_NAME(ModeID_MAIN)]  == &(QUEX_NAME(MAIN)));


#define self  (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
/* START: User's constructor extensions _______________________________________*/

/* END: _______________________________________________________________________*/
#undef self
    return true;
}

void
QUEX_NAME(user_destructor)(QUEX_TYPE_ANALYZER* me)
{
    (void)me;

#define self  (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
/* START: User's constructor extensions _______________________________________*/

/* END: _______________________________________________________________________*/
#undef self
}

bool
QUEX_NAME(user_reset)(QUEX_TYPE_ANALYZER* me)
{
    (void)me;

#define self  (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
/* START: User's 'reset' ______________________________________________________*/

/* END: _______________________________________________________________________*/
#undef self
    return true;
}

void
QUEX_NAME(user_print)(QUEX_TYPE_ANALYZER* me)
{
    (void)me;

#define self  (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
/* START: User's constructor extensions _______________________________________*/

/* END: _______________________________________________________________________*/
#undef self
}

#ifdef QUEX_OPTION_INCLUDE_STACK

bool
QUEX_NAME(user_memento_pack)(QUEX_TYPE_ANALYZER* me, 
                             const char*         InputName, 
                             QUEX_NAME(Memento)* memento) 
{
    (void)me; (void)memento; (void)InputName;

#define self  (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
/* START: User's memento 'pack' _______________________________________________*/

/* END: _______________________________________________________________________*/
#undef self
    return true;
}

void
QUEX_NAME(user_memento_unpack)(QUEX_TYPE_ANALYZER*  me, 
                               QUEX_NAME(Memento)*  memento)
{
    (void)me; (void)memento;

#define self  (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
/* START: User's memento 'unpack' _____________________________________________*/

/* END: _______________________________________________________________________*/
#undef self
}
#endif /* QUEX_OPTION_INCLUDE_STACK */

QUEX_NAMESPACE_MAIN_CLOSE



#include "Lexer-token"
QUEX_NAMESPACE_TOKEN_OPEN
QUEX_TYPE_LEXATOM   QUEX_NAME_TOKEN(LexemeNull) = (QUEX_TYPE_LEXATOM)0;
QUEX_NAMESPACE_TOKEN_CLOSE


