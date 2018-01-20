
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

    /* (854 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_14:
    __quex_debug("Init State\n");
    __quex_debug_state(854);
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
    /* (854 from 858)  */
    goto _14;


    __quex_assert_no_passage();
_8:
    /* (DROP_OUT from 857)  */
    goto _13;
_15:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_6:
    /* (DROP_OUT from 855)  */
    goto _11;


    __quex_assert_no_passage();
_7:
    /* (DROP_OUT from 856)  */
    goto _12;


    __quex_assert_no_passage();
_5:
    /* (DROP_OUT from 854)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _16;
    goto _15;


    __quex_assert_no_passage();
_3:
    /* (856 from 854)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(856);
goto _7;


    __quex_assert_no_passage();
_4:
    /* (857 from 854)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(857);
goto _8;


    __quex_assert_no_passage();
_2:
    /* (855 from 854)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(855);
goto _6;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_10:
    __quex_debug("* TERMINAL <LOOP EXIT>\n");
    --(me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _0;

_11:
    __quex_debug("* TERMINAL <LOOP 244>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_12:
    __quex_debug("* TERMINAL <LOOP 245>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_13:
    __quex_debug("* TERMINAL <LOOP 246>\n");
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
#define   CONTINUE do { goto _396; } while(0)

#ifdef    RETURN
#   undef RETURN
#endif
#define   RETURN   do { goto _395; } while(0)

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
#   define QUEX_LABEL_STATE_ROUTER _398

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
_397:
    me->buffer._lexeme_start_p = me->buffer._read_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);
_79:
    /* (794 from BEFORE_ENTRY) (794 from RELOAD_FORWARD)  */

    input = *(me->buffer._read_p);


    __quex_debug("Init State\n");
    __quex_debug_state(794);
switch( input ) {
case 0x0: goto _160;
case 0x1: goto _138;
case 0x9: goto _91;
case 0xA: goto _88;
case 0xD: 
case 0x20: goto _94;
case 0x21: goto _84;
case 0x22: goto _95;
case 0x23: goto _80;
case 0x2B: goto _83;
case 0x2D: goto _87;
case 0x2E: goto _93;
case 0x30: goto _85;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _98;
case 0x3C: goto _97;
case 0x3D: goto _92;
case 0x3E: goto _81;
case 0x62: goto _89;
case 0x63: goto _96;
case 0x64: case 0x65: 
case 0x6B: goto _89;
case 0x7B: goto _86;
case 0x7D: goto _90;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _82;
}


    __quex_assert_no_passage();
_138:
    /* (DROP_OUT from 841) (DROP_OUT from 848) (DROP_OUT from 835) (DROP_OUT from 810) (DROP_OUT from 845) (DROP_OUT from 839) (DROP_OUT from 842) (DROP_OUT from 836) (DROP_OUT from 833) (DROP_OUT from 846) (DROP_OUT from 843) (DROP_OUT from 837) (DROP_OUT from 794) (DROP_OUT from 840) (DROP_OUT from 844) (DROP_OUT from 838)  */

        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _78;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_139:
    /* (DROP_OUT from 795)  */
    goto _57;


    __quex_assert_no_passage();
_140:
    /* (DROP_OUT from 796)  */
    goto _64;


    __quex_assert_no_passage();
_141:
    /* (DROP_OUT from 804) (DROP_OUT from 799) (DROP_OUT from 814) (DROP_OUT from 821) (DROP_OUT from 811) (DROP_OUT from 808) (DROP_OUT from 831) (DROP_OUT from 802) (DROP_OUT from 822) (DROP_OUT from 797) (DROP_OUT from 850) (DROP_OUT from 819) (DROP_OUT from 829) (DROP_OUT from 823) (DROP_OUT from 798) (DROP_OUT from 820)  */
    goto _74;


    __quex_assert_no_passage();
_142:
    /* (DROP_OUT from 817) (DROP_OUT from 815) (DROP_OUT from 816) (DROP_OUT from 800) (DROP_OUT from 813)  */
    goto _67;


    __quex_assert_no_passage();
_143:
    /* (DROP_OUT from 801)  */
    goto _65;


    __quex_assert_no_passage();
_144:
    /* (DROP_OUT from 803)  */
    goto _37;


    __quex_assert_no_passage();
_145:
    /* (DROP_OUT from 805)  */
    goto _66;


    __quex_assert_no_passage();
_146:
    /* (DROP_OUT from 806)  */
    goto _38;


    __quex_assert_no_passage();
_147:
    /* (DROP_OUT from 807)  */
    goto _60;


    __quex_assert_no_passage();
_148:
    /* (DROP_OUT from 809)  */
    goto _39;


    __quex_assert_no_passage();
_149:
    /* (DROP_OUT from 812)  */
    goto _62;


    __quex_assert_no_passage();
_150:
    /* (DROP_OUT from 827) (DROP_OUT from 818) (DROP_OUT from 826)  */
    goto _68;


    __quex_assert_no_passage();
_151:
    /* (DROP_OUT from 824) (DROP_OUT from 825)  */
    goto _69;


    __quex_assert_no_passage();
_152:
    /* (DROP_OUT from 828)  */
    goto _61;


    __quex_assert_no_passage();
_153:
    /* (DROP_OUT from 830)  */
    goto _72;


    __quex_assert_no_passage();
_154:
    /* (DROP_OUT from 832)  */
    goto _73;


    __quex_assert_no_passage();
_155:
    /* (DROP_OUT from 834)  */
    goto _71;


    __quex_assert_no_passage();
_156:
    /* (DROP_OUT from 847)  */
    goto _70;


    __quex_assert_no_passage();
_157:
    /* (DROP_OUT from 849)  */
    goto _58;


    __quex_assert_no_passage();
_158:
    /* (DROP_OUT from 851)  */
    goto _59;


    __quex_assert_no_passage();
_159:
    /* (DROP_OUT from 852)  */
    goto _63;


    __quex_assert_no_passage();
_80:
    /* (795 from 794)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(795);
goto _139;


    __quex_assert_no_passage();
_81:
    /* (796 from 794)  */
    ++(me->buffer._read_p);

_259:
    input = *(me->buffer._read_p);


    __quex_debug_state(796);
if     ( input == 0x3D )  goto _137;
else if( input == 0x0 )   goto _162;
else                      goto _140;


    __quex_assert_no_passage();
_161:
    /* (796 from RELOAD_FORWARD)  */
    goto _259;


    __quex_assert_no_passage();
_82:
    /* (797 from 800) (797 from 813) (797 from 822) (797 from 799) (797 from 825) (797 from 832) (797 from 818) (797 from 831) (797 from 821) (797 from 798) (797 from 802) (797 from 815) (797 from 824) (797 from 850) (797 from 827) (797 from 808) (797 from 817) (797 from 794) (797 from 830) (797 from 811) (797 from 820) (797 from 797) (797 from 814) (797 from 823) (797 from 804) (797 from 826) (797 from 816) (797 from 829) (797 from 819)  */

    ++(me->buffer._read_p);

_262:
    input = *(me->buffer._read_p);


    __quex_debug_state(797);
switch( input ) {
case 0x0: goto _164;
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
default: goto _82;
}


    __quex_assert_no_passage();
_163:
    /* (797 from RELOAD_FORWARD)  */
    goto _262;


    __quex_assert_no_passage();
_83:
    /* (798 from 794)  */
    ++(me->buffer._read_p);

_264:
    input = *(me->buffer._read_p);


    __quex_debug_state(798);
switch( input ) {
case 0x0: goto _166;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x2E: goto _93;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _85;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _82;
}


    __quex_assert_no_passage();
_165:
    /* (798 from RELOAD_FORWARD)  */
    goto _264;


    __quex_assert_no_passage();
_84:
    /* (799 from 794)  */
    ++(me->buffer._read_p);

_266:
    input = *(me->buffer._read_p);


    __quex_debug_state(799);
switch( input ) {
case 0x0: goto _168;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: goto _141;
case 0x3D: goto _136;
case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _82;
}


    __quex_assert_no_passage();
_167:
    /* (799 from RELOAD_FORWARD)  */
    goto _266;


    __quex_assert_no_passage();
_85:
    /* (800 from 802) (800 from 817) (800 from 800) (800 from 798) (800 from 794)  */

    ++(me->buffer._read_p);

_269:
    input = *(me->buffer._read_p);


    __quex_debug_state(800);
switch( input ) {
case 0x0: goto _170;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _142;
case 0x2E: goto _93;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _85;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _142;
default: goto _82;
}


    __quex_assert_no_passage();
_169:
    /* (800 from RELOAD_FORWARD)  */
    goto _269;


    __quex_assert_no_passage();
_86:
    /* (801 from 794)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(801);
goto _143;


    __quex_assert_no_passage();
_87:
    /* (802 from 794)  */
    ++(me->buffer._read_p);

_272:
    input = *(me->buffer._read_p);


    __quex_debug_state(802);
switch( input ) {
case 0x0: goto _172;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x2E: goto _93;
case 0x30: goto _85;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _98;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _82;
}


    __quex_assert_no_passage();
_171:
    /* (802 from RELOAD_FORWARD)  */
    goto _272;


    __quex_assert_no_passage();
_88:
    /* (803 from 794)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(803);
goto _144;


    __quex_assert_no_passage();
_89:
    /* (804 from 794)  */
    ++(me->buffer._read_p);

_275:
    input = *(me->buffer._read_p);


    __quex_debug_state(804);
switch( input ) {
case 0x0: goto _174;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _141;
case 0x5F: goto _135;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _82;
}


    __quex_assert_no_passage();
_173:
    /* (804 from RELOAD_FORWARD)  */
    goto _275;


    __quex_assert_no_passage();
_90:
    /* (805 from 794)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(805);
goto _145;


    __quex_assert_no_passage();
_91:
    /* (806 from 794)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(806);
goto _146;


    __quex_assert_no_passage();
_92:
    /* (807 from 794)  */
    ++(me->buffer._read_p);

_279:
    input = *(me->buffer._read_p);


    __quex_debug_state(807);
if     ( input == 0x3D )  goto _134;
else if( input == 0x0 )   goto _176;
else                      goto _147;


    __quex_assert_no_passage();
_175:
    /* (807 from RELOAD_FORWARD)  */
    goto _279;


    __quex_assert_no_passage();
_93:
    /* (808 from 794) (808 from 800) (808 from 798) (808 from 802)  */

    ++(me->buffer._read_p);

_282:
    input = *(me->buffer._read_p);


    __quex_debug_state(808);
switch( input ) {
case 0x0: goto _178;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _112;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _82;
}


    __quex_assert_no_passage();
_177:
    /* (808 from RELOAD_FORWARD)  */
    goto _282;


    __quex_assert_no_passage();
_94:
    /* (809 from 794)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(809);
goto _148;


    __quex_assert_no_passage();
_95:
    /* (810 from 794)  */
    ++(me->buffer._read_p);

_285:
    input = *(me->buffer._read_p);


    __quex_debug_state(810);
switch( input ) {
case 0x0: goto _180;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _119;
case 0x2D: goto _120;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _118;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _121;
}


    __quex_assert_no_passage();
_179:
    /* (810 from RELOAD_FORWARD)  */
    goto _285;


    __quex_assert_no_passage();
_181:
    /* (811 from RELOAD_FORWARD)  */
_287:
    input = *(me->buffer._read_p);


    __quex_debug_state(811);
switch( input ) {
case 0x0: goto _182;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _141;
case 0x5F: goto _114;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _82;
}


    __quex_assert_no_passage();
_96:
    /* (811 from 794)  */
    ++(me->buffer._read_p);

    goto _287;


    __quex_assert_no_passage();
_97:
    /* (812 from 794)  */
    ++(me->buffer._read_p);

_289:
    input = *(me->buffer._read_p);


    __quex_debug_state(812);
if     ( input == 0x3D )  goto _113;
else if( input == 0x0 )   goto _184;
else                      goto _149;


    __quex_assert_no_passage();
_183:
    /* (812 from RELOAD_FORWARD)  */
    goto _289;


    __quex_assert_no_passage();
_98:
    /* (813 from 802) (813 from 794)  */

    ++(me->buffer._read_p);

_292:
    input = *(me->buffer._read_p);


    __quex_debug_state(813);
switch( input ) {
case 0x0: goto _186;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _142;
case 0x2E: goto _99;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _100;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _142;
default: goto _82;
}


    __quex_assert_no_passage();
_185:
    /* (813 from RELOAD_FORWARD)  */
    goto _292;


    __quex_assert_no_passage();
_99:
    /* (814 from 817) (814 from 816) (814 from 813) (814 from 815)  */

    ++(me->buffer._read_p);

_295:
    input = *(me->buffer._read_p);


    __quex_debug_state(814);
switch( input ) {
case 0x0: goto _188;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x2D: goto _104;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _103;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _82;
}


    __quex_assert_no_passage();
_187:
    /* (814 from RELOAD_FORWARD)  */
    goto _295;


    __quex_assert_no_passage();
_100:
    /* (815 from 813)  */
    ++(me->buffer._read_p);

_297:
    input = *(me->buffer._read_p);


    __quex_debug_state(815);
switch( input ) {
case 0x0: goto _190;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _142;
case 0x2E: goto _99;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _101;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _142;
default: goto _82;
}


    __quex_assert_no_passage();
_189:
    /* (815 from RELOAD_FORWARD)  */
    goto _297;


    __quex_assert_no_passage();
_101:
    /* (816 from 815)  */
    ++(me->buffer._read_p);

_299:
    input = *(me->buffer._read_p);


    __quex_debug_state(816);
switch( input ) {
case 0x0: goto _192;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _142;
case 0x2E: goto _99;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _102;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _142;
default: goto _82;
}


    __quex_assert_no_passage();
_191:
    /* (816 from RELOAD_FORWARD)  */
    goto _299;


    __quex_assert_no_passage();
_193:
    /* (817 from RELOAD_FORWARD)  */
_301:
    input = *(me->buffer._read_p);


    __quex_debug_state(817);
switch( input ) {
case 0x0: goto _194;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _142;
case 0x2E: goto _99;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _85;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _142;
default: goto _82;
}


    __quex_assert_no_passage();
_102:
    /* (817 from 816)  */
    ++(me->buffer._read_p);

    goto _301;


    __quex_assert_no_passage();
_103:
    /* (818 from 814)  */
    ++(me->buffer._read_p);

_303:
    input = *(me->buffer._read_p);


    __quex_debug_state(818);
switch( input ) {
case 0x0: goto _196;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _150;
case 0x2E: goto _106;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _111;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _150;
default: goto _82;
}


    __quex_assert_no_passage();
_195:
    /* (818 from RELOAD_FORWARD)  */
    goto _303;


    __quex_assert_no_passage();
_197:
    /* (819 from RELOAD_FORWARD)  */
_305:
    input = *(me->buffer._read_p);


    __quex_debug_state(819);
switch( input ) {
case 0x0: goto _198;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _105;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _82;
}


    __quex_assert_no_passage();
_104:
    /* (819 from 814)  */
    ++(me->buffer._read_p);

    goto _305;


    __quex_assert_no_passage();
_105:
    /* (820 from 819)  */
    ++(me->buffer._read_p);

_307:
    input = *(me->buffer._read_p);


    __quex_debug_state(820);
switch( input ) {
case 0x0: goto _200;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x2E: goto _106;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _107;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _82;
}


    __quex_assert_no_passage();
_199:
    /* (820 from RELOAD_FORWARD)  */
    goto _307;


    __quex_assert_no_passage();
_106:
    /* (821 from 820) (821 from 822) (821 from 826) (821 from 818)  */

    ++(me->buffer._read_p);

_310:
    input = *(me->buffer._read_p);


    __quex_debug_state(821);
switch( input ) {
case 0x0: goto _202;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x2D: goto _108;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _109;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _82;
}


    __quex_assert_no_passage();
_201:
    /* (821 from RELOAD_FORWARD)  */
    goto _310;


    __quex_assert_no_passage();
_107:
    /* (822 from 820)  */
    ++(me->buffer._read_p);

_312:
    input = *(me->buffer._read_p);


    __quex_debug_state(822);
switch( input ) {
case 0x0: goto _204;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x2E: goto _106;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _82;
}


    __quex_assert_no_passage();
_203:
    /* (822 from RELOAD_FORWARD)  */
    goto _312;


    __quex_assert_no_passage();
_108:
    /* (823 from 821)  */
    ++(me->buffer._read_p);

_314:
    input = *(me->buffer._read_p);


    __quex_debug_state(823);
switch( input ) {
case 0x0: goto _206;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _109;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _82;
}


    __quex_assert_no_passage();
_205:
    /* (823 from RELOAD_FORWARD)  */
    goto _314;


    __quex_assert_no_passage();
_109:
    /* (824 from 823) (824 from 821)  */

    ++(me->buffer._read_p);

_317:
    input = *(me->buffer._read_p);


    __quex_debug_state(824);
switch( input ) {
case 0x0: goto _208;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _151;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _110;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _82;
}


    __quex_assert_no_passage();
_207:
    /* (824 from RELOAD_FORWARD)  */
    goto _317;


    __quex_assert_no_passage();
_209:
    /* (825 from RELOAD_FORWARD)  */
_319:
    input = *(me->buffer._read_p);


    __quex_debug_state(825);
switch( input ) {
case 0x0: goto _210;
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
case 0x9D: goto _151;
default: goto _82;
}


    __quex_assert_no_passage();
_110:
    /* (825 from 824)  */
    ++(me->buffer._read_p);

    goto _319;


    __quex_assert_no_passage();
_111:
    /* (826 from 818)  */
    ++(me->buffer._read_p);

_321:
    input = *(me->buffer._read_p);


    __quex_debug_state(826);
switch( input ) {
case 0x0: goto _212;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _150;
case 0x2E: goto _106;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _112;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _150;
default: goto _82;
}


    __quex_assert_no_passage();
_211:
    /* (826 from RELOAD_FORWARD)  */
    goto _321;


    __quex_assert_no_passage();
_112:
    /* (827 from 826) (827 from 827) (827 from 808)  */

    ++(me->buffer._read_p);

_324:
    input = *(me->buffer._read_p);


    __quex_debug_state(827);
switch( input ) {
case 0x0: goto _214;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _150;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _112;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _150;
default: goto _82;
}


    __quex_assert_no_passage();
_213:
    /* (827 from RELOAD_FORWARD)  */
    goto _324;


    __quex_assert_no_passage();
_113:
    /* (828 from 812)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(828);
goto _152;


    __quex_assert_no_passage();
_215:
    /* (829 from RELOAD_FORWARD)  */
_327:
    input = *(me->buffer._read_p);


    __quex_debug_state(829);
switch( input ) {
case 0x0: goto _216;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _115;
case 0x3C: case 0x3D: case 0x3E: goto _141;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _116;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _82;
}


    __quex_assert_no_passage();
_114:
    /* (829 from 811)  */
    ++(me->buffer._read_p);

    goto _327;


    __quex_assert_no_passage();
_115:
    /* (830 from 829) (830 from 830)  */

    ++(me->buffer._read_p);

_330:
    input = *(me->buffer._read_p);


    __quex_debug_state(830);
switch( input ) {
case 0x0: goto _218;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _153;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _115;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _153;
default: goto _82;
}


    __quex_assert_no_passage();
_217:
    /* (830 from RELOAD_FORWARD)  */
    goto _330;


    __quex_assert_no_passage();
_116:
    /* (831 from 829) (831 from 850)  */

    ++(me->buffer._read_p);

_333:
    input = *(me->buffer._read_p);


    __quex_debug_state(831);
switch( input ) {
case 0x0: goto _220;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _141;
case 0x2D: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _117;
case 0x3C: case 0x3D: case 0x3E: goto _141;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _117;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _82;
}


    __quex_assert_no_passage();
_219:
    /* (831 from RELOAD_FORWARD)  */
    goto _333;


    __quex_assert_no_passage();
_117:
    /* (832 from 832) (832 from 831)  */

    ++(me->buffer._read_p);

_336:
    input = *(me->buffer._read_p);


    __quex_debug_state(832);
switch( input ) {
case 0x0: goto _222;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _154;
case 0x2D: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _117;
case 0x3C: case 0x3D: case 0x3E: goto _154;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _117;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _82;
}


    __quex_assert_no_passage();
_221:
    /* (832 from RELOAD_FORWARD)  */
    goto _336;


    __quex_assert_no_passage();
_118:
    /* (833 from 810) (833 from 835)  */

    ++(me->buffer._read_p);

_339:
    input = *(me->buffer._read_p);


    __quex_debug_state(833);
switch( input ) {
case 0x0: goto _224;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _119;
case 0x2E: goto _122;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _123;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _121;
}


    __quex_assert_no_passage();
_223:
    /* (833 from RELOAD_FORWARD)  */
    goto _339;


    __quex_assert_no_passage();
_119:
    /* (834 from 836) (834 from 833) (834 from 840) (834 from 837) (834 from 844) (834 from 842) (834 from 841) (834 from 838) (834 from 835) (834 from 810) (834 from 839) (834 from 846) (834 from 843)  */

    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(834);
goto _155;


    __quex_assert_no_passage();
_120:
    /* (835 from 810)  */
    ++(me->buffer._read_p);

_343:
    input = *(me->buffer._read_p);


    __quex_debug_state(835);
switch( input ) {
case 0x0: goto _226;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _119;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _118;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _121;
}


    __quex_assert_no_passage();
_225:
    /* (835 from RELOAD_FORWARD)  */
    goto _343;


    __quex_assert_no_passage();
_121:
    /* (836 from 839) (836 from 844) (836 from 841) (836 from 845) (836 from 836) (836 from 810) (836 from 833) (836 from 842) (836 from 846) (836 from 837) (836 from 843) (836 from 848) (836 from 838) (836 from 835) (836 from 840)  */

    ++(me->buffer._read_p);

_346:
    input = *(me->buffer._read_p);


    __quex_debug_state(836);
switch( input ) {
case 0x0: goto _228;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _119;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _121;
}


    __quex_assert_no_passage();
_227:
    /* (836 from RELOAD_FORWARD)  */
    goto _346;


    __quex_assert_no_passage();
_122:
    /* (837 from 838) (837 from 839) (837 from 840) (837 from 833)  */

    ++(me->buffer._read_p);

_349:
    input = *(me->buffer._read_p);


    __quex_debug_state(837);
switch( input ) {
case 0x0: goto _230;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _119;
case 0x2D: goto _126;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _127;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _121;
}


    __quex_assert_no_passage();
_229:
    /* (837 from RELOAD_FORWARD)  */
    goto _349;


    __quex_assert_no_passage();
_123:
    /* (838 from 833)  */
    ++(me->buffer._read_p);

_351:
    input = *(me->buffer._read_p);


    __quex_debug_state(838);
switch( input ) {
case 0x0: goto _232;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _119;
case 0x2E: goto _122;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _124;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _121;
}


    __quex_assert_no_passage();
_231:
    /* (838 from RELOAD_FORWARD)  */
    goto _351;


    __quex_assert_no_passage();
_233:
    /* (839 from RELOAD_FORWARD)  */
_353:
    input = *(me->buffer._read_p);


    __quex_debug_state(839);
switch( input ) {
case 0x0: goto _234;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _119;
case 0x2E: goto _122;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _125;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _121;
}


    __quex_assert_no_passage();
_124:
    /* (839 from 838)  */
    ++(me->buffer._read_p);

    goto _353;


    __quex_assert_no_passage();
_125:
    /* (840 from 839)  */
    ++(me->buffer._read_p);

_355:
    input = *(me->buffer._read_p);


    __quex_debug_state(840);
switch( input ) {
case 0x0: goto _236;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _119;
case 0x2E: goto _122;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _121;
}


    __quex_assert_no_passage();
_235:
    /* (840 from RELOAD_FORWARD)  */
    goto _355;


    __quex_assert_no_passage();
_126:
    /* (841 from 837)  */
    ++(me->buffer._read_p);

_357:
    input = *(me->buffer._read_p);


    __quex_debug_state(841);
switch( input ) {
case 0x0: goto _238;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _119;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _127;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _121;
}


    __quex_assert_no_passage();
_237:
    /* (841 from RELOAD_FORWARD)  */
    goto _357;


    __quex_assert_no_passage();
_127:
    /* (842 from 837) (842 from 841)  */

    ++(me->buffer._read_p);

_360:
    input = *(me->buffer._read_p);


    __quex_debug_state(842);
switch( input ) {
case 0x0: goto _240;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _119;
case 0x2E: goto _128;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _129;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _121;
}


    __quex_assert_no_passage();
_239:
    /* (842 from RELOAD_FORWARD)  */
    goto _360;


    __quex_assert_no_passage();
_128:
    /* (843 from 842) (843 from 844)  */

    ++(me->buffer._read_p);

_363:
    input = *(me->buffer._read_p);


    __quex_debug_state(843);
switch( input ) {
case 0x0: goto _242;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _119;
case 0x2D: goto _131;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _130;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _121;
}


    __quex_assert_no_passage();
_241:
    /* (843 from RELOAD_FORWARD)  */
    goto _363;


    __quex_assert_no_passage();
_129:
    /* (844 from 842)  */
    ++(me->buffer._read_p);

_365:
    input = *(me->buffer._read_p);


    __quex_debug_state(844);
switch( input ) {
case 0x0: goto _244;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _119;
case 0x2E: goto _128;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _121;
}


    __quex_assert_no_passage();
_243:
    /* (844 from RELOAD_FORWARD)  */
    goto _365;


    __quex_assert_no_passage();
_130:
    /* (845 from 846) (845 from 843)  */

    ++(me->buffer._read_p);

_368:
    input = *(me->buffer._read_p);


    __quex_debug_state(845);
switch( input ) {
case 0x0: goto _246;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _132;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _133;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _121;
}


    __quex_assert_no_passage();
_245:
    /* (845 from RELOAD_FORWARD)  */
    goto _368;


    __quex_assert_no_passage();
_131:
    /* (846 from 843)  */
    ++(me->buffer._read_p);

_370:
    input = *(me->buffer._read_p);


    __quex_debug_state(846);
switch( input ) {
case 0x0: goto _248;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _119;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _130;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _121;
}


    __quex_assert_no_passage();
_247:
    /* (846 from RELOAD_FORWARD)  */
    goto _370;


    __quex_assert_no_passage();
_132:
    /* (847 from 845) (847 from 848)  */

    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(847);
goto _156;


    __quex_assert_no_passage();
_133:
    /* (848 from 845)  */
    ++(me->buffer._read_p);

_374:
    input = *(me->buffer._read_p);


    __quex_debug_state(848);
switch( input ) {
case 0x0: goto _250;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _132;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _121;
}


    __quex_assert_no_passage();
_249:
    /* (848 from RELOAD_FORWARD)  */
    goto _374;


    __quex_assert_no_passage();
_134:
    /* (849 from 807)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(849);
goto _157;


    __quex_assert_no_passage();
_135:
    /* (850 from 804)  */
    ++(me->buffer._read_p);

_377:
    input = *(me->buffer._read_p);


    __quex_debug_state(850);
switch( input ) {
case 0x0: goto _252;
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
case 0x78: case 0x79: case 0x7A: goto _116;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _141;
default: goto _82;
}


    __quex_assert_no_passage();
_251:
    /* (850 from RELOAD_FORWARD)  */
    goto _377;


    __quex_assert_no_passage();
_136:
    /* (851 from 799)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(851);
goto _158;


    __quex_assert_no_passage();
_137:
    /* (852 from 796)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(852);
goto _159;
_18:
    /* (543 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

_381:
__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_380:
    __quex_debug("Init State\n");
    __quex_debug_state(543);
switch( input ) {
case 0x0: goto _30;
case 0x9: goto _20;
case 0xA: goto _19;
case 0xD: 
case 0x20: goto _21;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _23;
default: goto _22;
}


    __quex_assert_no_passage();
_31:
    /* (543 from 549)  */
    goto _380;


    __quex_assert_no_passage();
_28:
    /* (543 from RELOAD_FORWARD)  */
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

    goto _381;


    __quex_assert_no_passage();
_23:
    /* (DROP_OUT from 543)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _78;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_24:
    /* (DROP_OUT from 544)  */
    goto _33;


    __quex_assert_no_passage();
_25:
    /* (DROP_OUT from 545)  */
    goto _34;


    __quex_assert_no_passage();
_26:
    /* (DROP_OUT from 546)  */
    goto _35;


    __quex_assert_no_passage();
_27:
    /* (DROP_OUT from 547)  */
    goto _32;


    __quex_assert_no_passage();
_19:
    /* (544 from 543)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(544);
goto _24;


    __quex_assert_no_passage();
_20:
    /* (545 from 543)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(545);
goto _25;


    __quex_assert_no_passage();
_21:
    /* (546 from 543)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(546);
goto _26;


    __quex_assert_no_passage();
_22:
    /* (547 from 543)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(547);
goto _27;
_41:
    /* (576 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

_388:
__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_387:
    __quex_debug("Init State\n");
    __quex_debug_state(576);
switch( input ) {
case 0x0: goto _50;
case 0x9: goto _43;
case 0xA: goto _42;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _45;
default: goto _44;
}


    __quex_assert_no_passage();
_51:
    /* (576 from 580)  */
    goto _387;


    __quex_assert_no_passage();
_49:
    /* (576 from RELOAD_FORWARD)  */
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

    goto _388;


    __quex_assert_no_passage();
_47:
    /* (DROP_OUT from 578)  */
    goto _55;
_389:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_46:
    /* (DROP_OUT from 577)  */
    goto _54;


    __quex_assert_no_passage();
_48:
    /* (DROP_OUT from 579)  */
    goto _56;


    __quex_assert_no_passage();
_45:
    /* (DROP_OUT from 576)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _78;
    goto _389;


    __quex_assert_no_passage();
_42:
    /* (577 from 576)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(577);
goto _46;


    __quex_assert_no_passage();
_43:
    /* (578 from 576)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(578);
goto _47;


    __quex_assert_no_passage();
_44:
    /* (579 from 576)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(579);
goto _48;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_75:
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
_76:
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
_77:
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
_29:
    __quex_debug("* TERMINAL END_OF_STREAM\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 76 "zck.qx"
self_send(T_TERMINATION);

__QUEX_PURE_RETURN;


#   line 2605 "Lexer.cpp"

}
    /* End of Stream FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
__QUEX_PURE_RETURN;
_78:
    __quex_debug("* TERMINAL FAILURE\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 77 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_FAILURE);

__QUEX_PURE_RETURN;


#   line 2624 "Lexer.cpp"

}
RETURN;
_36:
    __quex_debug("* TERMINAL <skip>\n");
goto _18;
_40:
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
_32:
    __quex_debug("* TERMINAL <LOOP EXIT>\n");
    --(me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _17;

_33:
    __quex_debug("* TERMINAL <LOOP 165>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _31;

_34:
    __quex_debug("* TERMINAL <LOOP 166>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _31;

_35:
    __quex_debug("* TERMINAL <LOOP 167>\n");
goto _31;

_37:
    __quex_debug("* TERMINAL ENTER SKIP:\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

goto _36;

_38:
    __quex_debug("* TERMINAL ENTER SKIP:\n");
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

goto _36;

_39:
    __quex_debug("* TERMINAL ENTER SKIP:\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)1);

goto _36;

_53:
    __quex_debug("* TERMINAL <SKIP RANGE TERMINATED>\n");
goto _17;
_52:
    __quex_debug("* TERMINAL <LOOP EXIT>\n");
    --(me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _17;

_54:
    __quex_debug("* TERMINAL <COUPLE 180>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _53;

_55:
    __quex_debug("* TERMINAL <LOOP 181>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _51;

_56:
    __quex_debug("* TERMINAL <LOOP 182>\n");
goto _51;

_57:
    __quex_debug("* TERMINAL <skip range><skip_range open>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
goto _41;
_58:
    __quex_debug("* TERMINAL \"==\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 78 "zck.qx"
self_send(T_OP_DEQ);

__QUEX_PURE_RETURN;


#   line 2754 "Lexer.cpp"

}
RETURN;
_59:
    __quex_debug("* TERMINAL \"!=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 79 "zck.qx"
self_send(T_OP_NEQ);

__QUEX_PURE_RETURN;


#   line 2770 "Lexer.cpp"

}
RETURN;
_60:
    __quex_debug("* TERMINAL \"=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 80 "zck.qx"
self_send(T_OP_EQ);

__QUEX_PURE_RETURN;


#   line 2786 "Lexer.cpp"

}
RETURN;
_61:
    __quex_debug("* TERMINAL \"<=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 81 "zck.qx"
self_send(T_OP_LTEQ);

__QUEX_PURE_RETURN;


#   line 2802 "Lexer.cpp"

}
RETURN;
_62:
    __quex_debug("* TERMINAL \"<\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 82 "zck.qx"
self_send(T_OP_LT);

__QUEX_PURE_RETURN;


#   line 2818 "Lexer.cpp"

}
RETURN;
_63:
    __quex_debug("* TERMINAL \">=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 83 "zck.qx"
self_send(T_OP_GTEQ);

__QUEX_PURE_RETURN;


#   line 2834 "Lexer.cpp"

}
RETURN;
_64:
    __quex_debug("* TERMINAL \">\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 84 "zck.qx"
self_send(T_OP_GT);

__QUEX_PURE_RETURN;


#   line 2850 "Lexer.cpp"

}
RETURN;
_65:
    __quex_debug("* TERMINAL \"{\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 85 "zck.qx"
self_send(T_OPEN_BRACE);

__QUEX_PURE_RETURN;


#   line 2866 "Lexer.cpp"

}
RETURN;
_66:
    __quex_debug("* TERMINAL \"}\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 86 "zck.qx"
self_send(T_CLOSE_BRACE);

__QUEX_PURE_RETURN;


#   line 2882 "Lexer.cpp"

}
RETURN;
_67:
    __quex_debug("* TERMINAL {SIGN}[0-9]+\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 87 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_INTEGER);

__QUEX_PURE_RETURN;


#   line 2899 "Lexer.cpp"

}
RETURN;
_68:
    __quex_debug("* TERMINAL {DECIMAL}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 88 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_DECIMAL);

__QUEX_PURE_RETURN;


#   line 2916 "Lexer.cpp"

}
RETURN;
_69:
    __quex_debug("* TERMINAL {DATE}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 89 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_DATE);

__QUEX_PURE_RETURN;


#   line 2933 "Lexer.cpp"

}
RETURN;
_70:
    __quex_debug("* TERMINAL \"\\\"\"{DATE}\"\\\"\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 90 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), LexemeBegin+1, LexemeEnd-1);
self_send(T_QDATE);

__QUEX_PURE_RETURN;


#   line 2950 "Lexer.cpp"

}
RETURN;
_71:
    __quex_debug("* TERMINAL {QSTRING}\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 91 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), LexemeBegin+1, LexemeEnd-1);
self_send(T_QSTRING);

__QUEX_PURE_RETURN;


#   line 2966 "Lexer.cpp"

}
RETURN;
_72:
    __quex_debug("* TERMINAL {CHAR_ID}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 92 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_CHAR_SCOPE);

__QUEX_PURE_RETURN;


#   line 2983 "Lexer.cpp"

}
RETURN;
_73:
    __quex_debug("* TERMINAL {TITLE_ID}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 93 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_TITLE_ID);

__QUEX_PURE_RETURN;


#   line 3000 "Lexer.cpp"

}
RETURN;
_74:
    __quex_debug("* TERMINAL {STRING}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 94 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_STRING);

__QUEX_PURE_RETURN;


#   line 3017 "Lexer.cpp"

}
RETURN;
if(0) {
    /* Avoid unreferenced labels. */
    goto _75;
    goto _76;
    goto _77;
    goto _29;
    goto _78;
    goto _36;
    goto _40;
    goto _32;
    goto _33;
    goto _34;
    goto _35;
    goto _37;
    goto _38;
    goto _39;
    goto _53;
    goto _52;
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
    goto _73;
    goto _74;
}
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_398:
switch( target_state_index ) {
case 28: {
goto _28;}
case 29: {
goto _29;}
case 40: {
goto _40;}
case 49: {
goto _49;}
case 79: {
goto _79;}
case 138: {
goto _138;}
case 140: {
goto _140;}
case 141: {
goto _141;}
case 142: {
goto _142;}
case 147: {
goto _147;}
case 149: {
goto _149;}
case 150: {
goto _150;}
case 151: {
goto _151;}
case 153: {
goto _153;}
case 154: {
goto _154;}
case 161: {
goto _161;}
case 163: {
goto _163;}
case 165: {
goto _165;}
case 167: {
goto _167;}
case 169: {
goto _169;}
case 171: {
goto _171;}
case 173: {
goto _173;}
case 175: {
goto _175;}
case 177: {
goto _177;}
case 179: {
goto _179;}
case 181: {
goto _181;}
case 183: {
goto _183;}
case 185: {
goto _185;}
case 187: {
goto _187;}
case 189: {
goto _189;}
case 191: {
goto _191;}
case 193: {
goto _193;}
case 195: {
goto _195;}
case 197: {
goto _197;}
case 199: {
goto _199;}
case 201: {
goto _201;}
case 203: {
goto _203;}
case 205: {
goto _205;}
case 207: {
goto _207;}
case 209: {
goto _209;}
case 211: {
goto _211;}
case 213: {
goto _213;}
case 215: {
goto _215;}
case 217: {
goto _217;}
case 219: {
goto _219;}
case 221: {
goto _221;}
case 223: {
goto _223;}
case 225: {
goto _225;}
case 227: {
goto _227;}
case 229: {
goto _229;}
case 231: {
goto _231;}
case 233: {
goto _233;}
case 235: {
goto _235;}
case 237: {
goto _237;}
case 239: {
goto _239;}
case 241: {
goto _241;}
case 243: {
goto _243;}
case 245: {
goto _245;}
case 247: {
goto _247;}
case 249: {
goto _249;}
case 251: {
goto _251;}
default: {
goto _251;}
}
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */


    __quex_assert_no_passage();
_30:
    /* (RELOAD_FORWARD from 543)  */
    target_state_index = QUEX_LABEL(28); target_state_else_index = QUEX_LABEL(29);

_394:
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

_393:

    __quex_debug3("RELOAD_FORWARD: success->%i; failure->%i", 
                  (int)target_state_index, (int)target_state_else_index);
    __quex_assert(*(me->buffer._read_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    
    __quex_debug_reload_before();                 
    load_result = QUEX_NAME(Buffer_load_forward)(&me->buffer, (QUEX_TYPE_LEXATOM**)position, PositionRegisterN);
    __quex_debug_reload_after(load_result);

    switch( load_result ) {
    case E_LoadResult_DONE:              QUEX_GOTO_STATE(target_state_index);      
    case E_LoadResult_BAD_LEXATOM:       goto _75;
    case E_LoadResult_FAILURE:           goto _76;
    case E_LoadResult_NO_SPACE_FOR_LOAD: goto _77;
    case E_LoadResult_NO_MORE_DATA:      QUEX_GOTO_STATE(target_state_else_index); 
    default:                             __quex_assert(false);
    }


    __quex_assert_no_passage();
_50:
    /* (RELOAD_FORWARD from 576)  */
    target_state_index = QUEX_LABEL(49); target_state_else_index = QUEX_LABEL(40);

    goto _394;


    __quex_assert_no_passage();
_160:
    /* (RELOAD_FORWARD from 794)  */
    target_state_index = QUEX_LABEL(79); target_state_else_index = QUEX_LABEL(29);

    goto _393;


    __quex_assert_no_passage();
_162:
    /* (RELOAD_FORWARD from 796)  */
    target_state_index = QUEX_LABEL(161); target_state_else_index = QUEX_LABEL(140);

    goto _393;


    __quex_assert_no_passage();
_164:
    /* (RELOAD_FORWARD from 797)  */
    target_state_index = QUEX_LABEL(163); target_state_else_index = QUEX_LABEL(141);

    goto _393;


    __quex_assert_no_passage();
_166:
    /* (RELOAD_FORWARD from 798)  */
    target_state_index = QUEX_LABEL(165); target_state_else_index = QUEX_LABEL(141);

    goto _393;


    __quex_assert_no_passage();
_168:
    /* (RELOAD_FORWARD from 799)  */
    target_state_index = QUEX_LABEL(167); target_state_else_index = QUEX_LABEL(141);

    goto _393;


    __quex_assert_no_passage();
_170:
    /* (RELOAD_FORWARD from 800)  */
    target_state_index = QUEX_LABEL(169); target_state_else_index = QUEX_LABEL(142);

    goto _393;


    __quex_assert_no_passage();
_172:
    /* (RELOAD_FORWARD from 802)  */
    target_state_index = QUEX_LABEL(171); target_state_else_index = QUEX_LABEL(141);

    goto _393;


    __quex_assert_no_passage();
_174:
    /* (RELOAD_FORWARD from 804)  */
    target_state_index = QUEX_LABEL(173); target_state_else_index = QUEX_LABEL(141);

    goto _393;


    __quex_assert_no_passage();
_176:
    /* (RELOAD_FORWARD from 807)  */
    target_state_index = QUEX_LABEL(175); target_state_else_index = QUEX_LABEL(147);

    goto _393;


    __quex_assert_no_passage();
_178:
    /* (RELOAD_FORWARD from 808)  */
    target_state_index = QUEX_LABEL(177); target_state_else_index = QUEX_LABEL(141);

    goto _393;


    __quex_assert_no_passage();
_180:
    /* (RELOAD_FORWARD from 810)  */
    target_state_index = QUEX_LABEL(179); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_182:
    /* (RELOAD_FORWARD from 811)  */
    target_state_index = QUEX_LABEL(181); target_state_else_index = QUEX_LABEL(141);

    goto _393;


    __quex_assert_no_passage();
_184:
    /* (RELOAD_FORWARD from 812)  */
    target_state_index = QUEX_LABEL(183); target_state_else_index = QUEX_LABEL(149);

    goto _393;


    __quex_assert_no_passage();
_186:
    /* (RELOAD_FORWARD from 813)  */
    target_state_index = QUEX_LABEL(185); target_state_else_index = QUEX_LABEL(142);

    goto _393;


    __quex_assert_no_passage();
_188:
    /* (RELOAD_FORWARD from 814)  */
    target_state_index = QUEX_LABEL(187); target_state_else_index = QUEX_LABEL(141);

    goto _393;


    __quex_assert_no_passage();
_190:
    /* (RELOAD_FORWARD from 815)  */
    target_state_index = QUEX_LABEL(189); target_state_else_index = QUEX_LABEL(142);

    goto _393;


    __quex_assert_no_passage();
_192:
    /* (RELOAD_FORWARD from 816)  */
    target_state_index = QUEX_LABEL(191); target_state_else_index = QUEX_LABEL(142);

    goto _393;


    __quex_assert_no_passage();
_194:
    /* (RELOAD_FORWARD from 817)  */
    target_state_index = QUEX_LABEL(193); target_state_else_index = QUEX_LABEL(142);

    goto _393;


    __quex_assert_no_passage();
_196:
    /* (RELOAD_FORWARD from 818)  */
    target_state_index = QUEX_LABEL(195); target_state_else_index = QUEX_LABEL(150);

    goto _393;


    __quex_assert_no_passage();
_198:
    /* (RELOAD_FORWARD from 819)  */
    target_state_index = QUEX_LABEL(197); target_state_else_index = QUEX_LABEL(141);

    goto _393;


    __quex_assert_no_passage();
_200:
    /* (RELOAD_FORWARD from 820)  */
    target_state_index = QUEX_LABEL(199); target_state_else_index = QUEX_LABEL(141);

    goto _393;


    __quex_assert_no_passage();
_202:
    /* (RELOAD_FORWARD from 821)  */
    target_state_index = QUEX_LABEL(201); target_state_else_index = QUEX_LABEL(141);

    goto _393;


    __quex_assert_no_passage();
_204:
    /* (RELOAD_FORWARD from 822)  */
    target_state_index = QUEX_LABEL(203); target_state_else_index = QUEX_LABEL(141);

    goto _393;


    __quex_assert_no_passage();
_206:
    /* (RELOAD_FORWARD from 823)  */
    target_state_index = QUEX_LABEL(205); target_state_else_index = QUEX_LABEL(141);

    goto _393;


    __quex_assert_no_passage();
_208:
    /* (RELOAD_FORWARD from 824)  */
    target_state_index = QUEX_LABEL(207); target_state_else_index = QUEX_LABEL(151);

    goto _393;


    __quex_assert_no_passage();
_210:
    /* (RELOAD_FORWARD from 825)  */
    target_state_index = QUEX_LABEL(209); target_state_else_index = QUEX_LABEL(151);

    goto _393;


    __quex_assert_no_passage();
_212:
    /* (RELOAD_FORWARD from 826)  */
    target_state_index = QUEX_LABEL(211); target_state_else_index = QUEX_LABEL(150);

    goto _393;


    __quex_assert_no_passage();
_214:
    /* (RELOAD_FORWARD from 827)  */
    target_state_index = QUEX_LABEL(213); target_state_else_index = QUEX_LABEL(150);

    goto _393;


    __quex_assert_no_passage();
_216:
    /* (RELOAD_FORWARD from 829)  */
    target_state_index = QUEX_LABEL(215); target_state_else_index = QUEX_LABEL(141);

    goto _393;


    __quex_assert_no_passage();
_218:
    /* (RELOAD_FORWARD from 830)  */
    target_state_index = QUEX_LABEL(217); target_state_else_index = QUEX_LABEL(153);

    goto _393;


    __quex_assert_no_passage();
_220:
    /* (RELOAD_FORWARD from 831)  */
    target_state_index = QUEX_LABEL(219); target_state_else_index = QUEX_LABEL(141);

    goto _393;


    __quex_assert_no_passage();
_222:
    /* (RELOAD_FORWARD from 832)  */
    target_state_index = QUEX_LABEL(221); target_state_else_index = QUEX_LABEL(154);

    goto _393;


    __quex_assert_no_passage();
_224:
    /* (RELOAD_FORWARD from 833)  */
    target_state_index = QUEX_LABEL(223); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_226:
    /* (RELOAD_FORWARD from 835)  */
    target_state_index = QUEX_LABEL(225); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_228:
    /* (RELOAD_FORWARD from 836)  */
    target_state_index = QUEX_LABEL(227); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_230:
    /* (RELOAD_FORWARD from 837)  */
    target_state_index = QUEX_LABEL(229); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_232:
    /* (RELOAD_FORWARD from 838)  */
    target_state_index = QUEX_LABEL(231); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_234:
    /* (RELOAD_FORWARD from 839)  */
    target_state_index = QUEX_LABEL(233); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_236:
    /* (RELOAD_FORWARD from 840)  */
    target_state_index = QUEX_LABEL(235); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_238:
    /* (RELOAD_FORWARD from 841)  */
    target_state_index = QUEX_LABEL(237); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_240:
    /* (RELOAD_FORWARD from 842)  */
    target_state_index = QUEX_LABEL(239); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_242:
    /* (RELOAD_FORWARD from 843)  */
    target_state_index = QUEX_LABEL(241); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_244:
    /* (RELOAD_FORWARD from 844)  */
    target_state_index = QUEX_LABEL(243); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_246:
    /* (RELOAD_FORWARD from 845)  */
    target_state_index = QUEX_LABEL(245); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_248:
    /* (RELOAD_FORWARD from 846)  */
    target_state_index = QUEX_LABEL(247); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_250:
    /* (RELOAD_FORWARD from 848)  */
    target_state_index = QUEX_LABEL(249); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_252:
    /* (RELOAD_FORWARD from 850)  */
    target_state_index = QUEX_LABEL(251); target_state_else_index = QUEX_LABEL(141);

    goto _393;

_395:
/* RETURN -- after executing 'on_after_match' code. */
    __QUEX_PURE_RETURN;


_396:
/* CONTINUE -- after executing 'on_after_match' code. */

_17:
/* CONTINUE -- without executing 'on_after_match' (e.g. on FAILURE). */


    /* Mode change = another function takes over the analysis.
     * => After mode change the analyzer function needs to be quit!
     * ASSERT: 'CONTINUE' after mode change is not allowed.                   */
    __quex_assert(   me->DEBUG_analyzer_function_at_entry 
                  == me->current_analyzer_function);


    if( QUEX_NAME(TokenQueue_is_full)(&self._token_queue) ) {
        return;
    }


goto _397;

    __quex_assert_no_passage();

    /* Following labels are referenced in macros. It cannot be detected
     * whether the macros are applied in user code or not. To avoid compiler.
     * warnings of unused labels, they are referenced in unreachable code.   */
    goto _395; /* in RETURN                */
    goto _396; /* in CONTINUE              */
    goto _17; /* in CONTINUE and skippers */
#   if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
    goto _398; /* in QUEX_GOTO_STATE       */
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


