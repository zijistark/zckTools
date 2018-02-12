
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

    /* (881 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_14:
    __quex_debug("Init State\n");
    __quex_debug_state(881);
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
    /* (881 from 885)  */
    goto _14;


    __quex_assert_no_passage();
_5:
    /* (DROP_OUT from 881)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _16;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_6:
    /* (DROP_OUT from 882)  */
    goto _11;


    __quex_assert_no_passage();
_7:
    /* (DROP_OUT from 883)  */
    goto _12;


    __quex_assert_no_passage();
_8:
    /* (DROP_OUT from 884)  */
    goto _13;


    __quex_assert_no_passage();
_2:
    /* (882 from 881)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(882);
goto _6;


    __quex_assert_no_passage();
_3:
    /* (883 from 881)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(883);
goto _7;


    __quex_assert_no_passage();
_4:
    /* (884 from 881)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(884);
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
    __quex_debug("* TERMINAL <LOOP 234>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_12:
    __quex_debug("* TERMINAL <LOOP 235>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_13:
    __quex_debug("* TERMINAL <LOOP 236>\n");
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
#define   CONTINUE do { goto _513; } while(0)

#ifdef    RETURN
#   undef RETURN
#endif
#define   RETURN   do { goto _512; } while(0)

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
#   define QUEX_LABEL_STATE_ROUTER _515

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
_514:
    me->buffer._lexeme_start_p = me->buffer._read_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);
_89:
    /* (801 from RELOAD_FORWARD) (801 from BEFORE_ENTRY)  */

    input = *(me->buffer._read_p);


    __quex_debug("Init State\n");
    __quex_debug_state(801);
switch( input ) {
case 0x0: goto _195;
case 0x1: goto _168;
case 0x9: goto _113;
case 0xA: goto _97;
case 0xD: 
case 0x20: goto _90;
case 0x21: goto _91;
case 0x22: goto _108;
case 0x23: goto _92;
case 0x2B: goto _107;
case 0x2D: goto _95;
case 0x2E: goto _99;
case 0x30: goto _103;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _98;
case 0x3C: goto _101;
case 0x3D: goto _93;
case 0x3E: goto _110;
case 0x62: goto _111;
case 0x63: goto _100;
case 0x64: goto _106;
case 0x65: goto _94;
case 0x69: goto _112;
case 0x6B: goto _111;
case 0x74: goto _105;
case 0x77: goto _109;
case 0x7B: goto _104;
case 0x7D: goto _102;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _96;
}


    __quex_assert_no_passage();
_168:
    /* (DROP_OUT from 841) (DROP_OUT from 848) (DROP_OUT from 835) (DROP_OUT from 801) (DROP_OUT from 845) (DROP_OUT from 839) (DROP_OUT from 842) (DROP_OUT from 849) (DROP_OUT from 836) (DROP_OUT from 846) (DROP_OUT from 843) (DROP_OUT from 850) (DROP_OUT from 837) (DROP_OUT from 840) (DROP_OUT from 844) (DROP_OUT from 820)  */

        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _88;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_169:
    /* (DROP_OUT from 802)  */
    goto _44;


    __quex_assert_no_passage();
_170:
    /* (DROP_OUT from 866) (DROP_OUT from 807) (DROP_OUT from 817) (DROP_OUT from 861) (DROP_OUT from 832) (DROP_OUT from 876) (DROP_OUT from 852) (DROP_OUT from 827) (DROP_OUT from 873) (DROP_OUT from 821) (DROP_OUT from 824) (DROP_OUT from 811) (DROP_OUT from 818) (DROP_OUT from 833) (DROP_OUT from 808) (DROP_OUT from 831) (DROP_OUT from 853) (DROP_OUT from 828) (DROP_OUT from 874) (DROP_OUT from 856) (DROP_OUT from 868) (DROP_OUT from 812) (DROP_OUT from 819) (DROP_OUT from 863) (DROP_OUT from 806) (DROP_OUT from 860) (DROP_OUT from 803) (DROP_OUT from 875) (DROP_OUT from 823) (DROP_OUT from 869) (DROP_OUT from 872)  */
    goto _84;


    __quex_assert_no_passage();
_171:
    /* (DROP_OUT from 804)  */
    goto _62;


    __quex_assert_no_passage();
_172:
    /* (DROP_OUT from 805)  */
    goto _65;


    __quex_assert_no_passage();
_173:
    /* (DROP_OUT from 809)  */
    goto _42;


    __quex_assert_no_passage();
_174:
    /* (DROP_OUT from 810) (DROP_OUT from 870) (DROP_OUT from 859) (DROP_OUT from 871) (DROP_OUT from 815)  */
    goto _77;


    __quex_assert_no_passage();
_175:
    /* (DROP_OUT from 813)  */
    goto _67;


    __quex_assert_no_passage();
_176:
    /* (DROP_OUT from 814)  */
    goto _71;


    __quex_assert_no_passage();
_177:
    /* (DROP_OUT from 816)  */
    goto _70;


    __quex_assert_no_passage();
_178:
    /* (DROP_OUT from 822)  */
    goto _69;


    __quex_assert_no_passage();
_179:
    /* (DROP_OUT from 825)  */
    goto _43;


    __quex_assert_no_passage();
_180:
    /* (DROP_OUT from 826)  */
    goto _72;


    __quex_assert_no_passage();
_181:
    /* (DROP_OUT from 829)  */
    goto _83;


    __quex_assert_no_passage();
_182:
    /* (DROP_OUT from 830)  */
    goto _68;


    __quex_assert_no_passage();
_183:
    /* (DROP_OUT from 834)  */
    goto _74;


    __quex_assert_no_passage();
_184:
    /* (DROP_OUT from 838)  */
    goto _81;


    __quex_assert_no_passage();
_185:
    /* (DROP_OUT from 847)  */
    goto _80;


    __quex_assert_no_passage();
_186:
    /* (DROP_OUT from 851)  */
    goto _76;


    __quex_assert_no_passage();
_187:
    /* (DROP_OUT from 854)  */
    goto _75;


    __quex_assert_no_passage();
_188:
    /* (DROP_OUT from 855)  */
    goto _66;


    __quex_assert_no_passage();
_189:
    /* (DROP_OUT from 857)  */
    goto _82;


    __quex_assert_no_passage();
_190:
    /* (DROP_OUT from 858) (DROP_OUT from 864) (DROP_OUT from 862)  */
    goto _78;


    __quex_assert_no_passage();
_191:
    /* (DROP_OUT from 867) (DROP_OUT from 865)  */
    goto _79;


    __quex_assert_no_passage();
_192:
    /* (DROP_OUT from 877)  */
    goto _73;


    __quex_assert_no_passage();
_193:
    /* (DROP_OUT from 878)  */
    goto _63;


    __quex_assert_no_passage();
_194:
    /* (DROP_OUT from 879)  */
    goto _64;


    __quex_assert_no_passage();
_90:
    /* (802 from 801)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(802);
goto _169;


    __quex_assert_no_passage();
_196:
    /* (803 from RELOAD_FORWARD)  */
_334:
    input = *(me->buffer._read_p);


    __quex_debug_state(803);
switch( input ) {
case 0x0: goto _197;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: goto _170;
case 0x3D: goto _167;
case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_91:
    /* (803 from 801)  */
    ++(me->buffer._read_p);

    goto _334;


    __quex_assert_no_passage();
_92:
    /* (804 from 801)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(804);
goto _171;


    __quex_assert_no_passage();
_198:
    /* (805 from RELOAD_FORWARD)  */
_337:
    input = *(me->buffer._read_p);


    __quex_debug_state(805);
if     ( input == 0x3D )  goto _166;
else if( input == 0x0 )   goto _199;
else                      goto _172;


    __quex_assert_no_passage();
_93:
    /* (805 from 801)  */
    ++(me->buffer._read_p);

    goto _337;


    __quex_assert_no_passage();
_200:
    /* (806 from RELOAD_FORWARD)  */
_339:
    input = *(me->buffer._read_p);


    __quex_debug_state(806);
switch( input ) {
case 0x0: goto _201;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x5F: goto _115;
case 0x6C: goto _160;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_94:
    /* (806 from 801)  */
    ++(me->buffer._read_p);

    goto _339;


    __quex_assert_no_passage();
_202:
    /* (807 from RELOAD_FORWARD)  */
_341:
    input = *(me->buffer._read_p);


    __quex_debug_state(807);
switch( input ) {
case 0x0: goto _203;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _170;
case 0x2E: goto _99;
case 0x30: goto _103;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _98;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_95:
    /* (807 from 801)  */
    ++(me->buffer._read_p);

    goto _341;


    __quex_assert_no_passage();
_96:
    /* (808 from 831) (808 from 868) (808 from 859) (808 from 818) (808 from 828) (808 from 865) (808 from 856) (808 from 806) (808 from 875) (808 from 834) (808 from 853) (808 from 803) (808 from 872) (808 from 863) (808 from 869) (808 from 860) (808 from 819) (808 from 810) (808 from 829) (808 from 866) (808 from 857) (808 from 807) (808 from 876) (808 from 826) (808 from 854) (808 from 873) (808 from 832) (808 from 823) (808 from 851) (808 from 801) (808 from 870) (808 from 861) (808 from 811) (808 from 867) (808 from 858) (808 from 817) (808 from 808) (808 from 877) (808 from 827) (808 from 864) (808 from 874) (808 from 833) (808 from 824) (808 from 815) (808 from 852) (808 from 871) (808 from 862) (808 from 821) (808 from 812)  */

    ++(me->buffer._read_p);

_344:
    input = *(me->buffer._read_p);


    __quex_debug_state(808);
switch( input ) {
case 0x0: goto _205;
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
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_204:
    /* (808 from RELOAD_FORWARD)  */
    goto _344;


    __quex_assert_no_passage();
_97:
    /* (809 from 801)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(809);
goto _173;


    __quex_assert_no_passage();
_98:
    /* (810 from 807) (810 from 801)  */

    ++(me->buffer._read_p);

_348:
    input = *(me->buffer._read_p);


    __quex_debug_state(810);
switch( input ) {
case 0x0: goto _207;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _174;
case 0x2E: goto _148;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _147;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _174;
default: goto _96;
}


    __quex_assert_no_passage();
_206:
    /* (810 from RELOAD_FORWARD)  */
    goto _348;


    __quex_assert_no_passage();
_99:
    /* (811 from 819) (811 from 801) (811 from 815) (811 from 807)  */

    ++(me->buffer._read_p);

_351:
    input = *(me->buffer._read_p);


    __quex_debug_state(811);
switch( input ) {
case 0x0: goto _209;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _170;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _146;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_208:
    /* (811 from RELOAD_FORWARD)  */
    goto _351;


    __quex_assert_no_passage();
_100:
    /* (812 from 801)  */
    ++(me->buffer._read_p);

_353:
    input = *(me->buffer._read_p);


    __quex_debug_state(812);
switch( input ) {
case 0x0: goto _211;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x5F: goto _144;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_210:
    /* (812 from RELOAD_FORWARD)  */
    goto _353;


    __quex_assert_no_passage();
_212:
    /* (813 from RELOAD_FORWARD)  */
_355:
    input = *(me->buffer._read_p);


    __quex_debug_state(813);
if     ( input == 0x3D )  goto _143;
else if( input == 0x0 )   goto _213;
else                      goto _175;


    __quex_assert_no_passage();
_101:
    /* (813 from 801)  */
    ++(me->buffer._read_p);

    goto _355;


    __quex_assert_no_passage();
_102:
    /* (814 from 801)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(814);
goto _176;


    __quex_assert_no_passage();
_103:
    /* (815 from 815) (815 from 807) (815 from 871) (815 from 801) (815 from 819)  */

    ++(me->buffer._read_p);

_359:
    input = *(me->buffer._read_p);


    __quex_debug_state(815);
switch( input ) {
case 0x0: goto _215;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _174;
case 0x2E: goto _99;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _103;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _174;
default: goto _96;
}


    __quex_assert_no_passage();
_214:
    /* (815 from RELOAD_FORWARD)  */
    goto _359;


    __quex_assert_no_passage();
_104:
    /* (816 from 801)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(816);
goto _177;


    __quex_assert_no_passage();
_216:
    /* (817 from RELOAD_FORWARD)  */
_362:
    input = *(me->buffer._read_p);


    __quex_debug_state(817);
switch( input ) {
case 0x0: goto _217;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x68: goto _140;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_105:
    /* (817 from 801)  */
    ++(me->buffer._read_p);

    goto _362;


    __quex_assert_no_passage();
_106:
    /* (818 from 801)  */
    ++(me->buffer._read_p);

_364:
    input = *(me->buffer._read_p);


    __quex_debug_state(818);
switch( input ) {
case 0x0: goto _219;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x5F: goto _115;
case 0x6F: goto _139;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_218:
    /* (818 from RELOAD_FORWARD)  */
    goto _364;


    __quex_assert_no_passage();
_107:
    /* (819 from 801)  */
    ++(me->buffer._read_p);

_366:
    input = *(me->buffer._read_p);


    __quex_debug_state(819);
switch( input ) {
case 0x0: goto _221;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _170;
case 0x2E: goto _99;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _103;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_220:
    /* (819 from RELOAD_FORWARD)  */
    goto _366;


    __quex_assert_no_passage();
_222:
    /* (820 from RELOAD_FORWARD)  */
_368:
    input = *(me->buffer._read_p);


    __quex_debug_state(820);
switch( input ) {
case 0x0: goto _223;
case 0x1: 
case 0xA: 
case 0xD: goto _168;
case 0x22: goto _126;
case 0x2D: goto _125;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _123;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _124;
}


    __quex_assert_no_passage();
_108:
    /* (820 from 801)  */
    ++(me->buffer._read_p);

    goto _368;


    __quex_assert_no_passage();
_224:
    /* (821 from RELOAD_FORWARD)  */
_370:
    input = *(me->buffer._read_p);


    __quex_debug_state(821);
switch( input ) {
case 0x0: goto _225;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x68: goto _119;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_109:
    /* (821 from 801)  */
    ++(me->buffer._read_p);

    goto _370;


    __quex_assert_no_passage();
_226:
    /* (822 from RELOAD_FORWARD)  */
_372:
    input = *(me->buffer._read_p);


    __quex_debug_state(822);
if     ( input == 0x3D )  goto _118;
else if( input == 0x0 )   goto _227;
else                      goto _178;


    __quex_assert_no_passage();
_110:
    /* (822 from 801)  */
    ++(me->buffer._read_p);

    goto _372;


    __quex_assert_no_passage();
_228:
    /* (823 from RELOAD_FORWARD)  */
_374:
    input = *(me->buffer._read_p);


    __quex_debug_state(823);
switch( input ) {
case 0x0: goto _229;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x5F: goto _115;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_111:
    /* (823 from 801)  */
    ++(me->buffer._read_p);

    goto _374;


    __quex_assert_no_passage();
_112:
    /* (824 from 801)  */
    ++(me->buffer._read_p);

_376:
    input = *(me->buffer._read_p);


    __quex_debug_state(824);
switch( input ) {
case 0x0: goto _231;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x66: goto _114;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_230:
    /* (824 from RELOAD_FORWARD)  */
    goto _376;


    __quex_assert_no_passage();
_113:
    /* (825 from 801)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(825);
goto _179;


    __quex_assert_no_passage();
_114:
    /* (826 from 824)  */
    ++(me->buffer._read_p);

_379:
    input = *(me->buffer._read_p);


    __quex_debug_state(826);
switch( input ) {
case 0x0: goto _233;
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
case 0x9D: goto _180;
default: goto _96;
}


    __quex_assert_no_passage();
_232:
    /* (826 from RELOAD_FORWARD)  */
    goto _379;


    __quex_assert_no_passage();
_115:
    /* (827 from 818) (827 from 806) (827 from 823)  */

    ++(me->buffer._read_p);

_382:
    input = *(me->buffer._read_p);


    __quex_debug_state(827);
switch( input ) {
case 0x0: goto _235;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
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
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_234:
    /* (827 from RELOAD_FORWARD)  */
    goto _382;


    __quex_assert_no_passage();
_116:
    /* (828 from 827) (828 from 856)  */

    ++(me->buffer._read_p);

_385:
    input = *(me->buffer._read_p);


    __quex_debug_state(828);
switch( input ) {
case 0x0: goto _237;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _170;
case 0x2D: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _117;
case 0x3C: case 0x3D: case 0x3E: goto _170;
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
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_236:
    /* (828 from RELOAD_FORWARD)  */
    goto _385;


    __quex_assert_no_passage();
_117:
    /* (829 from 828) (829 from 829)  */

    ++(me->buffer._read_p);

_388:
    input = *(me->buffer._read_p);


    __quex_debug_state(829);
switch( input ) {
case 0x0: goto _239;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _181;
case 0x2D: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _117;
case 0x3C: case 0x3D: case 0x3E: goto _181;
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
case 0x9D: goto _181;
default: goto _96;
}


    __quex_assert_no_passage();
_238:
    /* (829 from RELOAD_FORWARD)  */
    goto _388;


    __quex_assert_no_passage();
_118:
    /* (830 from 822)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(830);
goto _182;


    __quex_assert_no_passage();
_240:
    /* (831 from RELOAD_FORWARD)  */
_391:
    input = *(me->buffer._read_p);


    __quex_debug_state(831);
switch( input ) {
case 0x0: goto _241;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x69: goto _120;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_119:
    /* (831 from 821)  */
    ++(me->buffer._read_p);

    goto _391;


    __quex_assert_no_passage();
_242:
    /* (832 from RELOAD_FORWARD)  */
_393:
    input = *(me->buffer._read_p);


    __quex_debug_state(832);
switch( input ) {
case 0x0: goto _243;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x6C: goto _121;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_120:
    /* (832 from 831)  */
    ++(me->buffer._read_p);

    goto _393;


    __quex_assert_no_passage();
_244:
    /* (833 from RELOAD_FORWARD)  */
_395:
    input = *(me->buffer._read_p);


    __quex_debug_state(833);
switch( input ) {
case 0x0: goto _245;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x65: goto _122;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_121:
    /* (833 from 832)  */
    ++(me->buffer._read_p);

    goto _395;


    __quex_assert_no_passage();
_246:
    /* (834 from RELOAD_FORWARD)  */
_397:
    input = *(me->buffer._read_p);


    __quex_debug_state(834);
switch( input ) {
case 0x0: goto _247;
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
case 0x9D: goto _183;
default: goto _96;
}


    __quex_assert_no_passage();
_122:
    /* (834 from 833)  */
    ++(me->buffer._read_p);

    goto _397;


    __quex_assert_no_passage();
_123:
    /* (835 from 820) (835 from 837)  */

    ++(me->buffer._read_p);

_400:
    input = *(me->buffer._read_p);


    __quex_debug_state(835);
switch( input ) {
case 0x0: goto _249;
case 0x1: 
case 0xA: 
case 0xD: goto _168;
case 0x22: goto _126;
case 0x2E: goto _128;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _127;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _124;
}


    __quex_assert_no_passage();
_248:
    /* (835 from RELOAD_FORWARD)  */
    goto _400;


    __quex_assert_no_passage();
_124:
    /* (836 from 839) (836 from 844) (836 from 850) (836 from 841) (836 from 845) (836 from 836) (836 from 842) (836 from 846) (836 from 837) (836 from 843) (836 from 848) (836 from 820) (836 from 835) (836 from 849) (836 from 840)  */

    ++(me->buffer._read_p);

_403:
    input = *(me->buffer._read_p);


    __quex_debug_state(836);
switch( input ) {
case 0x0: goto _251;
case 0x1: 
case 0xA: 
case 0xD: goto _168;
case 0x22: goto _126;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _124;
}


    __quex_assert_no_passage();
_250:
    /* (836 from RELOAD_FORWARD)  */
    goto _403;


    __quex_assert_no_passage();
_252:
    /* (837 from RELOAD_FORWARD)  */
_405:
    input = *(me->buffer._read_p);


    __quex_debug_state(837);
switch( input ) {
case 0x0: goto _253;
case 0x1: 
case 0xA: 
case 0xD: goto _168;
case 0x22: goto _126;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _123;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _124;
}


    __quex_assert_no_passage();
_125:
    /* (837 from 820)  */
    ++(me->buffer._read_p);

    goto _405;


    __quex_assert_no_passage();
_126:
    /* (838 from 841) (838 from 839) (838 from 849) (838 from 835) (838 from 842) (838 from 836) (838 from 843) (838 from 850) (838 from 837) (838 from 844) (838 from 840) (838 from 845) (838 from 820)  */

    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(838);
goto _184;


    __quex_assert_no_passage();
_254:
    /* (839 from RELOAD_FORWARD)  */
_409:
    input = *(me->buffer._read_p);


    __quex_debug_state(839);
switch( input ) {
case 0x0: goto _255;
case 0x1: 
case 0xA: 
case 0xD: goto _168;
case 0x22: goto _126;
case 0x2E: goto _128;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _137;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _124;
}


    __quex_assert_no_passage();
_127:
    /* (839 from 835)  */
    ++(me->buffer._read_p);

    goto _409;


    __quex_assert_no_passage();
_128:
    /* (840 from 835) (840 from 850) (840 from 849) (840 from 839)  */

    ++(me->buffer._read_p);

_412:
    input = *(me->buffer._read_p);


    __quex_debug_state(840);
switch( input ) {
case 0x0: goto _257;
case 0x1: 
case 0xA: 
case 0xD: goto _168;
case 0x22: goto _126;
case 0x2D: goto _129;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _130;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _124;
}


    __quex_assert_no_passage();
_256:
    /* (840 from RELOAD_FORWARD)  */
    goto _412;


    __quex_assert_no_passage();
_258:
    /* (841 from RELOAD_FORWARD)  */
_414:
    input = *(me->buffer._read_p);


    __quex_debug_state(841);
switch( input ) {
case 0x0: goto _259;
case 0x1: 
case 0xA: 
case 0xD: goto _168;
case 0x22: goto _126;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _130;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _124;
}


    __quex_assert_no_passage();
_129:
    /* (841 from 840)  */
    ++(me->buffer._read_p);

    goto _414;


    __quex_assert_no_passage();
_130:
    /* (842 from 841) (842 from 840)  */

    ++(me->buffer._read_p);

_417:
    input = *(me->buffer._read_p);


    __quex_debug_state(842);
switch( input ) {
case 0x0: goto _261;
case 0x1: 
case 0xA: 
case 0xD: goto _168;
case 0x22: goto _126;
case 0x2E: goto _131;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _132;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _124;
}


    __quex_assert_no_passage();
_260:
    /* (842 from RELOAD_FORWARD)  */
    goto _417;


    __quex_assert_no_passage();
_131:
    /* (843 from 842) (843 from 844)  */

    ++(me->buffer._read_p);

_420:
    input = *(me->buffer._read_p);


    __quex_debug_state(843);
switch( input ) {
case 0x0: goto _263;
case 0x1: 
case 0xA: 
case 0xD: goto _168;
case 0x22: goto _126;
case 0x2D: goto _133;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _134;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _124;
}


    __quex_assert_no_passage();
_262:
    /* (843 from RELOAD_FORWARD)  */
    goto _420;


    __quex_assert_no_passage();
_132:
    /* (844 from 842)  */
    ++(me->buffer._read_p);

_422:
    input = *(me->buffer._read_p);


    __quex_debug_state(844);
switch( input ) {
case 0x0: goto _265;
case 0x1: 
case 0xA: 
case 0xD: goto _168;
case 0x22: goto _126;
case 0x2E: goto _131;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _124;
}


    __quex_assert_no_passage();
_264:
    /* (844 from RELOAD_FORWARD)  */
    goto _422;


    __quex_assert_no_passage();
_266:
    /* (845 from RELOAD_FORWARD)  */
_424:
    input = *(me->buffer._read_p);


    __quex_debug_state(845);
switch( input ) {
case 0x0: goto _267;
case 0x1: 
case 0xA: 
case 0xD: goto _168;
case 0x22: goto _126;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _134;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _124;
}


    __quex_assert_no_passage();
_133:
    /* (845 from 843)  */
    ++(me->buffer._read_p);

    goto _424;


    __quex_assert_no_passage();
_134:
    /* (846 from 843) (846 from 845)  */

    ++(me->buffer._read_p);

_427:
    input = *(me->buffer._read_p);


    __quex_debug_state(846);
switch( input ) {
case 0x0: goto _269;
case 0x1: 
case 0xA: 
case 0xD: goto _168;
case 0x22: goto _135;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _136;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _124;
}


    __quex_assert_no_passage();
_268:
    /* (846 from RELOAD_FORWARD)  */
    goto _427;


    __quex_assert_no_passage();
_135:
    /* (847 from 846) (847 from 848)  */

    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(847);
goto _185;


    __quex_assert_no_passage();
_136:
    /* (848 from 846)  */
    ++(me->buffer._read_p);

_431:
    input = *(me->buffer._read_p);


    __quex_debug_state(848);
switch( input ) {
case 0x0: goto _271;
case 0x1: 
case 0xA: 
case 0xD: goto _168;
case 0x22: goto _135;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _124;
}


    __quex_assert_no_passage();
_270:
    /* (848 from RELOAD_FORWARD)  */
    goto _431;


    __quex_assert_no_passage();
_272:
    /* (849 from RELOAD_FORWARD)  */
_433:
    input = *(me->buffer._read_p);


    __quex_debug_state(849);
switch( input ) {
case 0x0: goto _273;
case 0x1: 
case 0xA: 
case 0xD: goto _168;
case 0x22: goto _126;
case 0x2E: goto _128;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _138;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _124;
}


    __quex_assert_no_passage();
_137:
    /* (849 from 839)  */
    ++(me->buffer._read_p);

    goto _433;


    __quex_assert_no_passage();
_138:
    /* (850 from 849)  */
    ++(me->buffer._read_p);

_435:
    input = *(me->buffer._read_p);


    __quex_debug_state(850);
switch( input ) {
case 0x0: goto _275;
case 0x1: 
case 0xA: 
case 0xD: goto _168;
case 0x22: goto _126;
case 0x2E: goto _128;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _168;
default: goto _124;
}


    __quex_assert_no_passage();
_274:
    /* (850 from RELOAD_FORWARD)  */
    goto _435;


    __quex_assert_no_passage();
_276:
    /* (851 from RELOAD_FORWARD)  */
_437:
    input = *(me->buffer._read_p);


    __quex_debug_state(851);
switch( input ) {
case 0x0: goto _277;
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
case 0x9D: goto _186;
default: goto _96;
}


    __quex_assert_no_passage();
_139:
    /* (851 from 818)  */
    ++(me->buffer._read_p);

    goto _437;


    __quex_assert_no_passage();
_278:
    /* (852 from RELOAD_FORWARD)  */
_439:
    input = *(me->buffer._read_p);


    __quex_debug_state(852);
switch( input ) {
case 0x0: goto _279;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x65: goto _141;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_140:
    /* (852 from 817)  */
    ++(me->buffer._read_p);

    goto _439;


    __quex_assert_no_passage();
_280:
    /* (853 from RELOAD_FORWARD)  */
_441:
    input = *(me->buffer._read_p);


    __quex_debug_state(853);
switch( input ) {
case 0x0: goto _281;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x6E: goto _142;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_141:
    /* (853 from 852)  */
    ++(me->buffer._read_p);

    goto _441;


    __quex_assert_no_passage();
_282:
    /* (854 from RELOAD_FORWARD)  */
_443:
    input = *(me->buffer._read_p);


    __quex_debug_state(854);
switch( input ) {
case 0x0: goto _283;
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
case 0x9D: goto _187;
default: goto _96;
}


    __quex_assert_no_passage();
_142:
    /* (854 from 853)  */
    ++(me->buffer._read_p);

    goto _443;


    __quex_assert_no_passage();
_143:
    /* (855 from 813)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(855);
goto _188;


    __quex_assert_no_passage();
_144:
    /* (856 from 812)  */
    ++(me->buffer._read_p);

_446:
    input = *(me->buffer._read_p);


    __quex_debug_state(856);
switch( input ) {
case 0x0: goto _285;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _170;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _145;
case 0x3C: case 0x3D: case 0x3E: goto _170;
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
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_284:
    /* (856 from RELOAD_FORWARD)  */
    goto _446;


    __quex_assert_no_passage();
_145:
    /* (857 from 856) (857 from 857)  */

    ++(me->buffer._read_p);

_449:
    input = *(me->buffer._read_p);


    __quex_debug_state(857);
switch( input ) {
case 0x0: goto _287;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _189;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _145;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _189;
default: goto _96;
}


    __quex_assert_no_passage();
_286:
    /* (857 from RELOAD_FORWARD)  */
    goto _449;


    __quex_assert_no_passage();
_146:
    /* (858 from 864) (858 from 811) (858 from 858)  */

    ++(me->buffer._read_p);

_452:
    input = *(me->buffer._read_p);


    __quex_debug_state(858);
switch( input ) {
case 0x0: goto _289;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _190;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _146;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _190;
default: goto _96;
}


    __quex_assert_no_passage();
_288:
    /* (858 from RELOAD_FORWARD)  */
    goto _452;


    __quex_assert_no_passage();
_290:
    /* (859 from RELOAD_FORWARD)  */
_454:
    input = *(me->buffer._read_p);


    __quex_debug_state(859);
switch( input ) {
case 0x0: goto _291;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _174;
case 0x2E: goto _148;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _158;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _174;
default: goto _96;
}


    __quex_assert_no_passage();
_147:
    /* (859 from 810)  */
    ++(me->buffer._read_p);

    goto _454;


    __quex_assert_no_passage();
_148:
    /* (860 from 871) (860 from 870) (860 from 859) (860 from 810)  */

    ++(me->buffer._read_p);

_457:
    input = *(me->buffer._read_p);


    __quex_debug_state(860);
switch( input ) {
case 0x0: goto _293;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _170;
case 0x2D: goto _149;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _150;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_292:
    /* (860 from RELOAD_FORWARD)  */
    goto _457;


    __quex_assert_no_passage();
_294:
    /* (861 from RELOAD_FORWARD)  */
_459:
    input = *(me->buffer._read_p);


    __quex_debug_state(861);
switch( input ) {
case 0x0: goto _295;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _170;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _156;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_149:
    /* (861 from 860)  */
    ++(me->buffer._read_p);

    goto _459;


    __quex_assert_no_passage();
_296:
    /* (862 from RELOAD_FORWARD)  */
_461:
    input = *(me->buffer._read_p);


    __quex_debug_state(862);
switch( input ) {
case 0x0: goto _297;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _190;
case 0x2E: goto _151;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _152;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _190;
default: goto _96;
}


    __quex_assert_no_passage();
_150:
    /* (862 from 860)  */
    ++(me->buffer._read_p);

    goto _461;


    __quex_assert_no_passage();
_151:
    /* (863 from 862) (863 from 868) (863 from 869) (863 from 864)  */

    ++(me->buffer._read_p);

_464:
    input = *(me->buffer._read_p);


    __quex_debug_state(863);
switch( input ) {
case 0x0: goto _299;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _170;
case 0x2D: goto _154;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _153;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_298:
    /* (863 from RELOAD_FORWARD)  */
    goto _464;


    __quex_assert_no_passage();
_152:
    /* (864 from 862)  */
    ++(me->buffer._read_p);

_466:
    input = *(me->buffer._read_p);


    __quex_debug_state(864);
switch( input ) {
case 0x0: goto _301;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _190;
case 0x2E: goto _151;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _146;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _190;
default: goto _96;
}


    __quex_assert_no_passage();
_300:
    /* (864 from RELOAD_FORWARD)  */
    goto _466;


    __quex_assert_no_passage();
_153:
    /* (865 from 866) (865 from 863)  */

    ++(me->buffer._read_p);

_469:
    input = *(me->buffer._read_p);


    __quex_debug_state(865);
switch( input ) {
case 0x0: goto _303;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _191;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _155;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _191;
default: goto _96;
}


    __quex_assert_no_passage();
_302:
    /* (865 from RELOAD_FORWARD)  */
    goto _469;


    __quex_assert_no_passage();
_154:
    /* (866 from 863)  */
    ++(me->buffer._read_p);

_471:
    input = *(me->buffer._read_p);


    __quex_debug_state(866);
switch( input ) {
case 0x0: goto _305;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _170;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _153;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_304:
    /* (866 from RELOAD_FORWARD)  */
    goto _471;


    __quex_assert_no_passage();
_306:
    /* (867 from RELOAD_FORWARD)  */
_473:
    input = *(me->buffer._read_p);


    __quex_debug_state(867);
switch( input ) {
case 0x0: goto _307;
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
case 0x9D: goto _191;
default: goto _96;
}


    __quex_assert_no_passage();
_155:
    /* (867 from 865)  */
    ++(me->buffer._read_p);

    goto _473;


    __quex_assert_no_passage();
_308:
    /* (868 from RELOAD_FORWARD)  */
_475:
    input = *(me->buffer._read_p);


    __quex_debug_state(868);
switch( input ) {
case 0x0: goto _309;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _170;
case 0x2E: goto _151;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _157;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_156:
    /* (868 from 861)  */
    ++(me->buffer._read_p);

    goto _475;


    __quex_assert_no_passage();
_310:
    /* (869 from RELOAD_FORWARD)  */
_477:
    input = *(me->buffer._read_p);


    __quex_debug_state(869);
switch( input ) {
case 0x0: goto _311;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _170;
case 0x2E: goto _151;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_157:
    /* (869 from 868)  */
    ++(me->buffer._read_p);

    goto _477;


    __quex_assert_no_passage();
_312:
    /* (870 from RELOAD_FORWARD)  */
_479:
    input = *(me->buffer._read_p);


    __quex_debug_state(870);
switch( input ) {
case 0x0: goto _313;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _174;
case 0x2E: goto _148;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _159;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _174;
default: goto _96;
}


    __quex_assert_no_passage();
_158:
    /* (870 from 859)  */
    ++(me->buffer._read_p);

    goto _479;


    __quex_assert_no_passage();
_314:
    /* (871 from RELOAD_FORWARD)  */
_481:
    input = *(me->buffer._read_p);


    __quex_debug_state(871);
switch( input ) {
case 0x0: goto _315;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _174;
case 0x2E: goto _148;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _103;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _174;
default: goto _96;
}


    __quex_assert_no_passage();
_159:
    /* (871 from 870)  */
    ++(me->buffer._read_p);

    goto _481;


    __quex_assert_no_passage();
_160:
    /* (872 from 806)  */
    ++(me->buffer._read_p);

_483:
    input = *(me->buffer._read_p);


    __quex_debug_state(872);
switch( input ) {
case 0x0: goto _317;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x69: goto _161;
case 0x73: goto _162;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_316:
    /* (872 from RELOAD_FORWARD)  */
    goto _483;


    __quex_assert_no_passage();
_161:
    /* (873 from 872) (873 from 874) (873 from 876)  */

    ++(me->buffer._read_p);

_486:
    input = *(me->buffer._read_p);


    __quex_debug_state(873);
switch( input ) {
case 0x0: goto _319;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x66: goto _165;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_318:
    /* (873 from RELOAD_FORWARD)  */
    goto _486;


    __quex_assert_no_passage();
_162:
    /* (874 from 872)  */
    ++(me->buffer._read_p);

_488:
    input = *(me->buffer._read_p);


    __quex_debug_state(874);
switch( input ) {
case 0x0: goto _321;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x65: goto _163;
case 0x69: goto _161;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_320:
    /* (874 from RELOAD_FORWARD)  */
    goto _488;


    __quex_assert_no_passage();
_322:
    /* (875 from RELOAD_FORWARD)  */
_490:
    input = *(me->buffer._read_p);


    __quex_debug_state(875);
switch( input ) {
case 0x0: goto _323;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x5F: goto _164;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_163:
    /* (875 from 874)  */
    ++(me->buffer._read_p);

    goto _490;


    __quex_assert_no_passage();
_324:
    /* (876 from RELOAD_FORWARD)  */
_492:
    input = *(me->buffer._read_p);


    __quex_debug_state(876);
switch( input ) {
case 0x0: goto _325;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _170;
case 0x69: goto _161;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _96;
}


    __quex_assert_no_passage();
_164:
    /* (876 from 875)  */
    ++(me->buffer._read_p);

    goto _492;


    __quex_assert_no_passage();
_326:
    /* (877 from RELOAD_FORWARD)  */
_494:
    input = *(me->buffer._read_p);


    __quex_debug_state(877);
switch( input ) {
case 0x0: goto _327;
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
case 0x9D: goto _192;
default: goto _96;
}


    __quex_assert_no_passage();
_165:
    /* (877 from 873)  */
    ++(me->buffer._read_p);

    goto _494;


    __quex_assert_no_passage();
_166:
    /* (878 from 805)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(878);
goto _193;


    __quex_assert_no_passage();
_167:
    /* (879 from 803)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(879);
goto _194;
_23:
    /* (490 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

_498:
__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_497:
    __quex_debug("Init State\n");
    __quex_debug_state(490);
switch( input ) {
case 0x0: goto _35;
case 0x9: goto _25;
case 0xA: goto _24;
case 0xD: 
case 0x20: goto _26;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _28;
default: goto _27;
}


    __quex_assert_no_passage();
_36:
    /* (490 from 496)  */
    goto _497;


    __quex_assert_no_passage();
_33:
    /* (490 from RELOAD_FORWARD)  */
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

    goto _498;


    __quex_assert_no_passage();
_32:
    /* (DROP_OUT from 494)  */
    goto _37;
_499:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_29:
    /* (DROP_OUT from 491)  */
    goto _38;


    __quex_assert_no_passage();
_30:
    /* (DROP_OUT from 492)  */
    goto _39;


    __quex_assert_no_passage();
_31:
    /* (DROP_OUT from 493)  */
    goto _40;


    __quex_assert_no_passage();
_28:
    /* (DROP_OUT from 490)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _88;
    goto _499;


    __quex_assert_no_passage();
_24:
    /* (491 from 490)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(491);
goto _29;


    __quex_assert_no_passage();
_25:
    /* (492 from 490)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(492);
goto _30;


    __quex_assert_no_passage();
_26:
    /* (493 from 490)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(493);
goto _31;


    __quex_assert_no_passage();
_27:
    /* (494 from 490)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(494);
goto _32;
_46:
    /* (523 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

_505:
__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_504:
    __quex_debug("Init State\n");
    __quex_debug_state(523);
switch( input ) {
case 0x0: goto _55;
case 0x9: goto _48;
case 0xA: goto _47;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _50;
default: goto _49;
}


    __quex_assert_no_passage();
_56:
    /* (523 from 527)  */
    goto _504;


    __quex_assert_no_passage();
_54:
    /* (523 from RELOAD_FORWARD)  */
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

    goto _505;


    __quex_assert_no_passage();
_53:
    /* (DROP_OUT from 526)  */
    goto _61;
_506:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_51:
    /* (DROP_OUT from 524)  */
    goto _59;


    __quex_assert_no_passage();
_52:
    /* (DROP_OUT from 525)  */
    goto _60;


    __quex_assert_no_passage();
_50:
    /* (DROP_OUT from 523)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _88;
    goto _506;


    __quex_assert_no_passage();
_47:
    /* (524 from 523)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(524);
goto _51;


    __quex_assert_no_passage();
_48:
    /* (525 from 523)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(525);
goto _52;


    __quex_assert_no_passage();
_49:
    /* (526 from 523)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(526);
goto _53;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_85:
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
_86:
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
_87:
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
_34:
    __quex_debug("* TERMINAL END_OF_STREAM\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 79 "zck.qx"
self_send(T_TERMINATION);

__QUEX_PURE_RETURN;


#   line 3340 "Lexer.cpp"

}
    /* End of Stream FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
__QUEX_PURE_RETURN;
_88:
    __quex_debug("* TERMINAL FAILURE\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 80 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_FAILURE);

__QUEX_PURE_RETURN;


#   line 3359 "Lexer.cpp"

}
RETURN;
_41:
    __quex_debug("* TERMINAL <skip>\n");
goto _23;
_45:
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
_37:
    __quex_debug("* TERMINAL <LOOP EXIT>\n");
    --(me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _22;

_38:
    __quex_debug("* TERMINAL <LOOP 140>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _36;

_39:
    __quex_debug("* TERMINAL <LOOP 141>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _36;

_40:
    __quex_debug("* TERMINAL <LOOP 142>\n");
goto _36;

_42:
    __quex_debug("* TERMINAL ENTER SKIP:\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

goto _41;

_43:
    __quex_debug("* TERMINAL ENTER SKIP:\n");
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

goto _41;

_44:
    __quex_debug("* TERMINAL ENTER SKIP:\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)1);

goto _41;

_58:
    __quex_debug("* TERMINAL <SKIP RANGE TERMINATED>\n");
goto _22;
_57:
    __quex_debug("* TERMINAL <LOOP EXIT>\n");
    --(me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _22;

_59:
    __quex_debug("* TERMINAL <COUPLE 155>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _58;

_60:
    __quex_debug("* TERMINAL <LOOP 156>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _56;

_61:
    __quex_debug("* TERMINAL <LOOP 157>\n");
goto _56;

_62:
    __quex_debug("* TERMINAL <skip range><skip_range open>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
goto _46;
_63:
    __quex_debug("* TERMINAL \"==\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 81 "zck.qx"
self_send(T_OP_DEQ);

__QUEX_PURE_RETURN;


#   line 3489 "Lexer.cpp"

}
RETURN;
_64:
    __quex_debug("* TERMINAL \"!=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 82 "zck.qx"
self_send(T_OP_NEQ);

__QUEX_PURE_RETURN;


#   line 3505 "Lexer.cpp"

}
RETURN;
_65:
    __quex_debug("* TERMINAL \"=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 83 "zck.qx"
self_send(T_OP_EQ);

__QUEX_PURE_RETURN;


#   line 3521 "Lexer.cpp"

}
RETURN;
_66:
    __quex_debug("* TERMINAL \"<=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 84 "zck.qx"
self_send(T_OP_LTEQ);

__QUEX_PURE_RETURN;


#   line 3537 "Lexer.cpp"

}
RETURN;
_67:
    __quex_debug("* TERMINAL \"<\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 85 "zck.qx"
self_send(T_OP_LT);

__QUEX_PURE_RETURN;


#   line 3553 "Lexer.cpp"

}
RETURN;
_68:
    __quex_debug("* TERMINAL \">=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 86 "zck.qx"
self_send(T_OP_GTEQ);

__QUEX_PURE_RETURN;


#   line 3569 "Lexer.cpp"

}
RETURN;
_69:
    __quex_debug("* TERMINAL \">\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 87 "zck.qx"
self_send(T_OP_GT);

__QUEX_PURE_RETURN;


#   line 3585 "Lexer.cpp"

}
RETURN;
_70:
    __quex_debug("* TERMINAL \"{\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 88 "zck.qx"
self_send(T_L_BRACE);

__QUEX_PURE_RETURN;


#   line 3601 "Lexer.cpp"

}
RETURN;
_71:
    __quex_debug("* TERMINAL \"}\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 89 "zck.qx"
self_send(T_R_BRACE);

__QUEX_PURE_RETURN;


#   line 3617 "Lexer.cpp"

}
RETURN;
_72:
    __quex_debug("* TERMINAL \"if\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 90 "zck.qx"
self_send(T_IF);

__QUEX_PURE_RETURN;


#   line 3633 "Lexer.cpp"

}
RETURN;
_73:
    __quex_debug("* TERMINAL {ELSIF}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 91 "zck.qx"
self_send(T_ELSIF);

__QUEX_PURE_RETURN;


#   line 3649 "Lexer.cpp"

}
RETURN;
_74:
    __quex_debug("* TERMINAL \"while\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(5);
{

#   line 92 "zck.qx"
self_send(T_WHILE);

__QUEX_PURE_RETURN;


#   line 3665 "Lexer.cpp"

}
RETURN;
_75:
    __quex_debug("* TERMINAL \"then\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(4);
{

#   line 93 "zck.qx"
self_send(T_THEN);

__QUEX_PURE_RETURN;


#   line 3681 "Lexer.cpp"

}
RETURN;
_76:
    __quex_debug("* TERMINAL \"do\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 94 "zck.qx"
self_send(T_DO);

__QUEX_PURE_RETURN;


#   line 3697 "Lexer.cpp"

}
RETURN;
_77:
    __quex_debug("* TERMINAL {SIGN}[0-9]+\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 95 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_INTEGER);

__QUEX_PURE_RETURN;


#   line 3714 "Lexer.cpp"

}
RETURN;
_78:
    __quex_debug("* TERMINAL {DECIMAL}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 96 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_DECIMAL);

__QUEX_PURE_RETURN;


#   line 3731 "Lexer.cpp"

}
RETURN;
_79:
    __quex_debug("* TERMINAL {DATE}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 97 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_DATE);

__QUEX_PURE_RETURN;


#   line 3748 "Lexer.cpp"

}
RETURN;
_80:
    __quex_debug("* TERMINAL \"\\\"\"{DATE}\"\\\"\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 98 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), LexemeBegin+1, LexemeEnd-1);
self_send(T_QDATE);

__QUEX_PURE_RETURN;


#   line 3765 "Lexer.cpp"

}
RETURN;
_81:
    __quex_debug("* TERMINAL {QSTRING}\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 99 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), LexemeBegin+1, LexemeEnd-1);
self_send(T_QSTRING);

__QUEX_PURE_RETURN;


#   line 3781 "Lexer.cpp"

}
RETURN;
_82:
    __quex_debug("* TERMINAL {CHAR_ID}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 100 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_CHAR_SCOPE);

__QUEX_PURE_RETURN;


#   line 3798 "Lexer.cpp"

}
RETURN;
_83:
    __quex_debug("* TERMINAL {TITLE_ID}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 101 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_TITLE_ID);

__QUEX_PURE_RETURN;


#   line 3815 "Lexer.cpp"

}
RETURN;
_84:
    __quex_debug("* TERMINAL {STRING}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 102 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_STRING);

__QUEX_PURE_RETURN;


#   line 3832 "Lexer.cpp"

}
RETURN;
if(0) {
    /* Avoid unreferenced labels. */
    goto _85;
    goto _86;
    goto _87;
    goto _34;
    goto _88;
    goto _41;
    goto _45;
    goto _37;
    goto _38;
    goto _39;
    goto _40;
    goto _42;
    goto _43;
    goto _44;
    goto _58;
    goto _57;
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
    goto _75;
    goto _76;
    goto _77;
    goto _78;
    goto _79;
    goto _80;
    goto _81;
    goto _82;
    goto _83;
    goto _84;
}
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_515:
switch( target_state_index ) {
case 33: {
goto _33;}
case 34: {
goto _34;}
case 45: {
goto _45;}
case 54: {
goto _54;}
case 89: {
goto _89;}
case 168: {
goto _168;}
case 170: {
goto _170;}
case 172: {
goto _172;}
case 174: {
goto _174;}
case 175: {
goto _175;}
case 178: {
goto _178;}
case 180: {
goto _180;}
case 181: {
goto _181;}
case 183: {
goto _183;}
case 186: {
goto _186;}
case 187: {
goto _187;}
case 189: {
goto _189;}
case 190: {
goto _190;}
case 191: {
goto _191;}
case 192: {
goto _192;}
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
case 246: {
goto _246;}
case 248: {
goto _248;}
case 250: {
goto _250;}
case 252: {
goto _252;}
case 254: {
goto _254;}
case 256: {
goto _256;}
case 258: {
goto _258;}
case 260: {
goto _260;}
case 262: {
goto _262;}
case 264: {
goto _264;}
case 266: {
goto _266;}
case 268: {
goto _268;}
case 270: {
goto _270;}
case 272: {
goto _272;}
case 274: {
goto _274;}
case 276: {
goto _276;}
case 278: {
goto _278;}
case 280: {
goto _280;}
case 282: {
goto _282;}
case 284: {
goto _284;}
case 286: {
goto _286;}
case 288: {
goto _288;}
case 290: {
goto _290;}
case 292: {
goto _292;}
case 294: {
goto _294;}
case 296: {
goto _296;}
case 298: {
goto _298;}
case 300: {
goto _300;}
case 302: {
goto _302;}
case 304: {
goto _304;}
case 306: {
goto _306;}
case 308: {
goto _308;}
case 310: {
goto _310;}
case 312: {
goto _312;}
case 314: {
goto _314;}
case 316: {
goto _316;}
case 318: {
goto _318;}
case 320: {
goto _320;}
case 322: {
goto _322;}
case 324: {
goto _324;}
case 326: {
goto _326;}
default: {
goto _326;}
}
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */


    __quex_assert_no_passage();
_55:
    /* (RELOAD_FORWARD from 523)  */
    target_state_index = QUEX_LABEL(54); target_state_else_index = QUEX_LABEL(45);

_511:
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

_510:

    __quex_debug3("RELOAD_FORWARD: success->%i; failure->%i", 
                  (int)target_state_index, (int)target_state_else_index);
    __quex_assert(*(me->buffer._read_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    
    __quex_debug_reload_before();                 
    load_result = QUEX_NAME(Buffer_load_forward)(&me->buffer, (QUEX_TYPE_LEXATOM**)position, PositionRegisterN);
    __quex_debug_reload_after(load_result);

    switch( load_result ) {
    case E_LoadResult_DONE:              QUEX_GOTO_STATE(target_state_index);      
    case E_LoadResult_BAD_LEXATOM:       goto _85;
    case E_LoadResult_FAILURE:           goto _86;
    case E_LoadResult_NO_SPACE_FOR_LOAD: goto _87;
    case E_LoadResult_NO_MORE_DATA:      QUEX_GOTO_STATE(target_state_else_index); 
    default:                             __quex_assert(false);
    }


    __quex_assert_no_passage();
_35:
    /* (RELOAD_FORWARD from 490)  */
    target_state_index = QUEX_LABEL(33); target_state_else_index = QUEX_LABEL(34);

    goto _511;


    __quex_assert_no_passage();
_195:
    /* (RELOAD_FORWARD from 801)  */
    target_state_index = QUEX_LABEL(89); target_state_else_index = QUEX_LABEL(34);

    goto _510;


    __quex_assert_no_passage();
_197:
    /* (RELOAD_FORWARD from 803)  */
    target_state_index = QUEX_LABEL(196); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_199:
    /* (RELOAD_FORWARD from 805)  */
    target_state_index = QUEX_LABEL(198); target_state_else_index = QUEX_LABEL(172);

    goto _510;


    __quex_assert_no_passage();
_201:
    /* (RELOAD_FORWARD from 806)  */
    target_state_index = QUEX_LABEL(200); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_203:
    /* (RELOAD_FORWARD from 807)  */
    target_state_index = QUEX_LABEL(202); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_205:
    /* (RELOAD_FORWARD from 808)  */
    target_state_index = QUEX_LABEL(204); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_207:
    /* (RELOAD_FORWARD from 810)  */
    target_state_index = QUEX_LABEL(206); target_state_else_index = QUEX_LABEL(174);

    goto _510;


    __quex_assert_no_passage();
_209:
    /* (RELOAD_FORWARD from 811)  */
    target_state_index = QUEX_LABEL(208); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_211:
    /* (RELOAD_FORWARD from 812)  */
    target_state_index = QUEX_LABEL(210); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_213:
    /* (RELOAD_FORWARD from 813)  */
    target_state_index = QUEX_LABEL(212); target_state_else_index = QUEX_LABEL(175);

    goto _510;


    __quex_assert_no_passage();
_215:
    /* (RELOAD_FORWARD from 815)  */
    target_state_index = QUEX_LABEL(214); target_state_else_index = QUEX_LABEL(174);

    goto _510;


    __quex_assert_no_passage();
_217:
    /* (RELOAD_FORWARD from 817)  */
    target_state_index = QUEX_LABEL(216); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_219:
    /* (RELOAD_FORWARD from 818)  */
    target_state_index = QUEX_LABEL(218); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_221:
    /* (RELOAD_FORWARD from 819)  */
    target_state_index = QUEX_LABEL(220); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_223:
    /* (RELOAD_FORWARD from 820)  */
    target_state_index = QUEX_LABEL(222); target_state_else_index = QUEX_LABEL(168);

    goto _510;


    __quex_assert_no_passage();
_225:
    /* (RELOAD_FORWARD from 821)  */
    target_state_index = QUEX_LABEL(224); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_227:
    /* (RELOAD_FORWARD from 822)  */
    target_state_index = QUEX_LABEL(226); target_state_else_index = QUEX_LABEL(178);

    goto _510;


    __quex_assert_no_passage();
_229:
    /* (RELOAD_FORWARD from 823)  */
    target_state_index = QUEX_LABEL(228); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_231:
    /* (RELOAD_FORWARD from 824)  */
    target_state_index = QUEX_LABEL(230); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_233:
    /* (RELOAD_FORWARD from 826)  */
    target_state_index = QUEX_LABEL(232); target_state_else_index = QUEX_LABEL(180);

    goto _510;


    __quex_assert_no_passage();
_235:
    /* (RELOAD_FORWARD from 827)  */
    target_state_index = QUEX_LABEL(234); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_237:
    /* (RELOAD_FORWARD from 828)  */
    target_state_index = QUEX_LABEL(236); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_239:
    /* (RELOAD_FORWARD from 829)  */
    target_state_index = QUEX_LABEL(238); target_state_else_index = QUEX_LABEL(181);

    goto _510;


    __quex_assert_no_passage();
_241:
    /* (RELOAD_FORWARD from 831)  */
    target_state_index = QUEX_LABEL(240); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_243:
    /* (RELOAD_FORWARD from 832)  */
    target_state_index = QUEX_LABEL(242); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_245:
    /* (RELOAD_FORWARD from 833)  */
    target_state_index = QUEX_LABEL(244); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_247:
    /* (RELOAD_FORWARD from 834)  */
    target_state_index = QUEX_LABEL(246); target_state_else_index = QUEX_LABEL(183);

    goto _510;


    __quex_assert_no_passage();
_249:
    /* (RELOAD_FORWARD from 835)  */
    target_state_index = QUEX_LABEL(248); target_state_else_index = QUEX_LABEL(168);

    goto _510;


    __quex_assert_no_passage();
_251:
    /* (RELOAD_FORWARD from 836)  */
    target_state_index = QUEX_LABEL(250); target_state_else_index = QUEX_LABEL(168);

    goto _510;


    __quex_assert_no_passage();
_253:
    /* (RELOAD_FORWARD from 837)  */
    target_state_index = QUEX_LABEL(252); target_state_else_index = QUEX_LABEL(168);

    goto _510;


    __quex_assert_no_passage();
_255:
    /* (RELOAD_FORWARD from 839)  */
    target_state_index = QUEX_LABEL(254); target_state_else_index = QUEX_LABEL(168);

    goto _510;


    __quex_assert_no_passage();
_257:
    /* (RELOAD_FORWARD from 840)  */
    target_state_index = QUEX_LABEL(256); target_state_else_index = QUEX_LABEL(168);

    goto _510;


    __quex_assert_no_passage();
_259:
    /* (RELOAD_FORWARD from 841)  */
    target_state_index = QUEX_LABEL(258); target_state_else_index = QUEX_LABEL(168);

    goto _510;


    __quex_assert_no_passage();
_261:
    /* (RELOAD_FORWARD from 842)  */
    target_state_index = QUEX_LABEL(260); target_state_else_index = QUEX_LABEL(168);

    goto _510;


    __quex_assert_no_passage();
_263:
    /* (RELOAD_FORWARD from 843)  */
    target_state_index = QUEX_LABEL(262); target_state_else_index = QUEX_LABEL(168);

    goto _510;


    __quex_assert_no_passage();
_265:
    /* (RELOAD_FORWARD from 844)  */
    target_state_index = QUEX_LABEL(264); target_state_else_index = QUEX_LABEL(168);

    goto _510;


    __quex_assert_no_passage();
_267:
    /* (RELOAD_FORWARD from 845)  */
    target_state_index = QUEX_LABEL(266); target_state_else_index = QUEX_LABEL(168);

    goto _510;


    __quex_assert_no_passage();
_269:
    /* (RELOAD_FORWARD from 846)  */
    target_state_index = QUEX_LABEL(268); target_state_else_index = QUEX_LABEL(168);

    goto _510;


    __quex_assert_no_passage();
_271:
    /* (RELOAD_FORWARD from 848)  */
    target_state_index = QUEX_LABEL(270); target_state_else_index = QUEX_LABEL(168);

    goto _510;


    __quex_assert_no_passage();
_273:
    /* (RELOAD_FORWARD from 849)  */
    target_state_index = QUEX_LABEL(272); target_state_else_index = QUEX_LABEL(168);

    goto _510;


    __quex_assert_no_passage();
_275:
    /* (RELOAD_FORWARD from 850)  */
    target_state_index = QUEX_LABEL(274); target_state_else_index = QUEX_LABEL(168);

    goto _510;


    __quex_assert_no_passage();
_277:
    /* (RELOAD_FORWARD from 851)  */
    target_state_index = QUEX_LABEL(276); target_state_else_index = QUEX_LABEL(186);

    goto _510;


    __quex_assert_no_passage();
_279:
    /* (RELOAD_FORWARD from 852)  */
    target_state_index = QUEX_LABEL(278); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_281:
    /* (RELOAD_FORWARD from 853)  */
    target_state_index = QUEX_LABEL(280); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_283:
    /* (RELOAD_FORWARD from 854)  */
    target_state_index = QUEX_LABEL(282); target_state_else_index = QUEX_LABEL(187);

    goto _510;


    __quex_assert_no_passage();
_285:
    /* (RELOAD_FORWARD from 856)  */
    target_state_index = QUEX_LABEL(284); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_287:
    /* (RELOAD_FORWARD from 857)  */
    target_state_index = QUEX_LABEL(286); target_state_else_index = QUEX_LABEL(189);

    goto _510;


    __quex_assert_no_passage();
_289:
    /* (RELOAD_FORWARD from 858)  */
    target_state_index = QUEX_LABEL(288); target_state_else_index = QUEX_LABEL(190);

    goto _510;


    __quex_assert_no_passage();
_291:
    /* (RELOAD_FORWARD from 859)  */
    target_state_index = QUEX_LABEL(290); target_state_else_index = QUEX_LABEL(174);

    goto _510;


    __quex_assert_no_passage();
_293:
    /* (RELOAD_FORWARD from 860)  */
    target_state_index = QUEX_LABEL(292); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_295:
    /* (RELOAD_FORWARD from 861)  */
    target_state_index = QUEX_LABEL(294); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_297:
    /* (RELOAD_FORWARD from 862)  */
    target_state_index = QUEX_LABEL(296); target_state_else_index = QUEX_LABEL(190);

    goto _510;


    __quex_assert_no_passage();
_299:
    /* (RELOAD_FORWARD from 863)  */
    target_state_index = QUEX_LABEL(298); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_301:
    /* (RELOAD_FORWARD from 864)  */
    target_state_index = QUEX_LABEL(300); target_state_else_index = QUEX_LABEL(190);

    goto _510;


    __quex_assert_no_passage();
_303:
    /* (RELOAD_FORWARD from 865)  */
    target_state_index = QUEX_LABEL(302); target_state_else_index = QUEX_LABEL(191);

    goto _510;


    __quex_assert_no_passage();
_305:
    /* (RELOAD_FORWARD from 866)  */
    target_state_index = QUEX_LABEL(304); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_307:
    /* (RELOAD_FORWARD from 867)  */
    target_state_index = QUEX_LABEL(306); target_state_else_index = QUEX_LABEL(191);

    goto _510;


    __quex_assert_no_passage();
_309:
    /* (RELOAD_FORWARD from 868)  */
    target_state_index = QUEX_LABEL(308); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_311:
    /* (RELOAD_FORWARD from 869)  */
    target_state_index = QUEX_LABEL(310); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_313:
    /* (RELOAD_FORWARD from 870)  */
    target_state_index = QUEX_LABEL(312); target_state_else_index = QUEX_LABEL(174);

    goto _510;


    __quex_assert_no_passage();
_315:
    /* (RELOAD_FORWARD from 871)  */
    target_state_index = QUEX_LABEL(314); target_state_else_index = QUEX_LABEL(174);

    goto _510;


    __quex_assert_no_passage();
_317:
    /* (RELOAD_FORWARD from 872)  */
    target_state_index = QUEX_LABEL(316); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_319:
    /* (RELOAD_FORWARD from 873)  */
    target_state_index = QUEX_LABEL(318); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_321:
    /* (RELOAD_FORWARD from 874)  */
    target_state_index = QUEX_LABEL(320); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_323:
    /* (RELOAD_FORWARD from 875)  */
    target_state_index = QUEX_LABEL(322); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_325:
    /* (RELOAD_FORWARD from 876)  */
    target_state_index = QUEX_LABEL(324); target_state_else_index = QUEX_LABEL(170);

    goto _510;


    __quex_assert_no_passage();
_327:
    /* (RELOAD_FORWARD from 877)  */
    target_state_index = QUEX_LABEL(326); target_state_else_index = QUEX_LABEL(192);

    goto _510;

_512:
/* RETURN -- after executing 'on_after_match' code. */
    __QUEX_PURE_RETURN;


_513:
/* CONTINUE -- after executing 'on_after_match' code. */

_22:
/* CONTINUE -- without executing 'on_after_match' (e.g. on FAILURE). */


    /* Mode change = another function takes over the analysis.
     * => After mode change the analyzer function needs to be quit!
     * ASSERT: 'CONTINUE' after mode change is not allowed.                   */
    __quex_assert(   me->DEBUG_analyzer_function_at_entry 
                  == me->current_analyzer_function);


    if( QUEX_NAME(TokenQueue_is_full)(&self._token_queue) ) {
        return;
    }


goto _514;

    __quex_assert_no_passage();

    /* Following labels are referenced in macros. It cannot be detected
     * whether the macros are applied in user code or not. To avoid compiler.
     * warnings of unused labels, they are referenced in unreachable code.   */
    goto _512; /* in RETURN                */
    goto _513; /* in CONTINUE              */
    goto _22; /* in CONTINUE and skippers */
#   if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
    goto _515; /* in QUEX_GOTO_STATE       */
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


