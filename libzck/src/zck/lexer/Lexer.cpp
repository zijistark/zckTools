
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

    /* (1008 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_14:
    __quex_debug("Init State\n");
    __quex_debug_state(1008);
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
    /* (1008 from 1012)  */
    goto _14;


    __quex_assert_no_passage();
_8:
    /* (DROP_OUT from 1011)  */
    goto _13;
_15:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_6:
    /* (DROP_OUT from 1009)  */
    goto _11;


    __quex_assert_no_passage();
_7:
    /* (DROP_OUT from 1010)  */
    goto _12;


    __quex_assert_no_passage();
_5:
    /* (DROP_OUT from 1008)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _16;
    goto _15;


    __quex_assert_no_passage();
_2:
    /* (1009 from 1008)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(1009);
goto _6;


    __quex_assert_no_passage();
_3:
    /* (1010 from 1008)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(1010);
goto _7;


    __quex_assert_no_passage();
_4:
    /* (1011 from 1008)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(1011);
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
    __quex_debug("* TERMINAL <LOOP 257>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_12:
    __quex_debug("* TERMINAL <LOOP 258>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_13:
    __quex_debug("* TERMINAL <LOOP 259>\n");
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
#define   CONTINUE do { goto _555; } while(0)

#ifdef    RETURN
#   undef RETURN
#endif
#define   RETURN   do { goto _554; } while(0)

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
#   define QUEX_LABEL_STATE_ROUTER _557
#   define MAIN    (QUEX_NAME(MAIN))

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
_556:
    me->buffer._lexeme_start_p = me->buffer._read_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);
_83:
    /* (920 from RELOAD_FORWARD) (920 from BEFORE_ENTRY)  */

    input = *(me->buffer._read_p);


    __quex_debug("Init State\n");
    __quex_debug_state(920);
switch( input ) {
case 0x0: goto _194;
case 0x1: goto _170;
case 0x9: goto _107;
case 0xA: goto _106;
case 0xD: 
case 0x20: goto _95;
case 0x22: goto _84;
case 0x23: goto _97;
case 0x2B: goto _92;
case 0x2D: goto _98;
case 0x2E: goto _104;
case 0x30: goto _102;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _85;
case 0x3C: goto _87;
case 0x3D: goto _100;
case 0x3E: goto _88;
case 0x42: goto _86;
case 0x45: goto _101;
case 0x4D: goto _90;
case 0x5F: goto _89;
case 0x62: goto _94;
case 0x63: goto _108;
case 0x64: goto _96;
case 0x65: goto _91;
case 0x6B: goto _96;
case 0x6D: goto _99;
case 0x7B: goto _103;
case 0x7D: goto _105;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _93;
}


    __quex_assert_no_passage();
_185:
    /* (DROP_OUT from 952) (DROP_OUT from 953)  */

if( me->buffer._lexatom_before_lexeme_start == '\n' ) {
    goto _74;}

_349:
    goto _78;
_347:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_171:
    /* (DROP_OUT from 939) (DROP_OUT from 981) (DROP_OUT from 922) (DROP_OUT from 979) (DROP_OUT from 980)  */
    goto _68;


    __quex_assert_no_passage();
_172:
    /* (DROP_OUT from 969) (DROP_OUT from 935) (DROP_OUT from 929) (DROP_OUT from 927) (DROP_OUT from 936) (DROP_OUT from 978) (DROP_OUT from 988) (DROP_OUT from 985) (DROP_OUT from 951) (DROP_OUT from 966) (DROP_OUT from 948) (DROP_OUT from 963) (DROP_OUT from 945) (DROP_OUT from 960) (DROP_OUT from 958) (DROP_OUT from 955) (DROP_OUT from 970) (DROP_OUT from 933) (DROP_OUT from 930) (DROP_OUT from 976) (DROP_OUT from 986) (DROP_OUT from 967) (DROP_OUT from 946) (DROP_OUT from 961) (DROP_OUT from 956) (DROP_OUT from 971) (DROP_OUT from 968) (DROP_OUT from 931) (DROP_OUT from 928) (DROP_OUT from 926) (DROP_OUT from 941) (DROP_OUT from 923) (DROP_OUT from 938) (DROP_OUT from 983) (DROP_OUT from 977) (DROP_OUT from 984) (DROP_OUT from 962) (DROP_OUT from 975) (DROP_OUT from 957) (DROP_OUT from 972)  */
    goto _349;


    __quex_assert_no_passage();
_173:
    /* (DROP_OUT from 924)  */
    goto _63;


    __quex_assert_no_passage();
_174:
    /* (DROP_OUT from 925)  */
    goto _65;


    __quex_assert_no_passage();
_175:
    /* (DROP_OUT from 932)  */
    goto _41;


    __quex_assert_no_passage();
_176:
    /* (DROP_OUT from 934)  */
    goto _59;


    __quex_assert_no_passage();
_177:
    /* (DROP_OUT from 937)  */
    goto _61;


    __quex_assert_no_passage();
_178:
    /* (DROP_OUT from 940)  */
    goto _66;


    __quex_assert_no_passage();
_179:
    /* (DROP_OUT from 942)  */
    goto _67;


    __quex_assert_no_passage();
_180:
    /* (DROP_OUT from 943)  */
    goto _39;


    __quex_assert_no_passage();
_181:
    /* (DROP_OUT from 944)  */
    goto _40;


    __quex_assert_no_passage();
_182:
    /* (DROP_OUT from 947)  */
    goto _76;


    __quex_assert_no_passage();
_183:
    /* (DROP_OUT from 949)  */
    goto _77;


    __quex_assert_no_passage();
_184:
    /* (DROP_OUT from 982) (DROP_OUT from 990) (DROP_OUT from 950)  */
    goto _69;


    __quex_assert_no_passage();
_186:
    /* (DROP_OUT from 954)  */
    goto _60;


    __quex_assert_no_passage();
_187:
    /* (DROP_OUT from 959)  */
    goto _72;


    __quex_assert_no_passage();
_189:
    /* (DROP_OUT from 973)  */
    goto _64;


    __quex_assert_no_passage();
_190:
    /* (DROP_OUT from 974)  */
    goto _62;


    __quex_assert_no_passage();
_191:
    /* (DROP_OUT from 989) (DROP_OUT from 987)  */
    goto _70;


    __quex_assert_no_passage();
_192:
    /* (DROP_OUT from 993)  */
    goto _75;


    __quex_assert_no_passage();
_193:
    /* (DROP_OUT from 1003)  */
    goto _71;


    __quex_assert_no_passage();
_170:
    /* (DROP_OUT from 921) (DROP_OUT from 999) (DROP_OUT from 996) (DROP_OUT from 991) (DROP_OUT from 1006) (DROP_OUT from 1000) (DROP_OUT from 997) (DROP_OUT from 994) (DROP_OUT from 1004) (DROP_OUT from 1001) (DROP_OUT from 920) (DROP_OUT from 998) (DROP_OUT from 995) (DROP_OUT from 992) (DROP_OUT from 1005) (DROP_OUT from 1002)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _82;
    goto _347;


    __quex_assert_no_passage();
_188:
    /* (DROP_OUT from 964) (DROP_OUT from 965)  */
if( me->buffer._lexatom_before_lexeme_start == '\n' ) {
    goto _73;}

    goto _349;


    __quex_assert_no_passage();
_195:
    /* (921 from RELOAD_FORWARD)  */
_351:
    input = *(me->buffer._read_p);


    __quex_debug_state(921);
switch( input ) {
case 0x0: goto _196;
case 0x1: 
case 0xA: 
case 0xD: goto _170;
case 0x22: goto _156;
case 0x2D: goto _155;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _157;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _154;
}


    __quex_assert_no_passage();
_84:
    /* (921 from 920)  */
    ++(me->buffer._read_p);

    goto _351;


    __quex_assert_no_passage();
_85:
    /* (922 from 935) (922 from 920)  */

    ++(me->buffer._read_p);

_354:
    input = *(me->buffer._read_p);


    __quex_debug_state(922);
switch( input ) {
case 0x0: goto _198;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _171;
case 0x2E: goto _141;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _142;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _171;
default: goto _93;
}


    __quex_assert_no_passage();
_197:
    /* (922 from RELOAD_FORWARD)  */
    goto _354;


    __quex_assert_no_passage();
_86:
    /* (923 from 920) (923 from 926)  */

    ++(me->buffer._read_p);

_357:
    input = *(me->buffer._read_p);


    __quex_debug_state(923);
switch( input ) {
case 0x0: goto _200;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x45: goto _138;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_199:
    /* (923 from RELOAD_FORWARD)  */
    goto _357;


    __quex_assert_no_passage();
_201:
    /* (924 from RELOAD_FORWARD)  */
_359:
    input = *(me->buffer._read_p);


    __quex_debug_state(924);
if     ( input == 0x3D )  goto _137;
else if( input == 0x0 )   goto _202;
else                      goto _173;


    __quex_assert_no_passage();
_87:
    /* (924 from 920)  */
    ++(me->buffer._read_p);

    goto _359;


    __quex_assert_no_passage();
_203:
    /* (925 from RELOAD_FORWARD)  */
_361:
    input = *(me->buffer._read_p);


    __quex_debug_state(925);
if     ( input == 0x3D )  goto _136;
else if( input == 0x0 )   goto _204;
else                      goto _174;


    __quex_assert_no_passage();
_88:
    /* (925 from 920)  */
    ++(me->buffer._read_p);

    goto _361;


    __quex_assert_no_passage();
_89:
    /* (926 from 920) (926 from 926)  */

    ++(me->buffer._read_p);

_364:
    input = *(me->buffer._read_p);


    __quex_debug_state(926);
switch( input ) {
case 0x0: goto _206;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x42: goto _86;
case 0x45: goto _101;
case 0x5F: goto _89;
case 0x62: goto _135;
case 0x65: goto _134;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_205:
    /* (926 from RELOAD_FORWARD)  */
    goto _364;


    __quex_assert_no_passage();
_90:
    /* (927 from 920)  */
    ++(me->buffer._read_p);

_366:
    input = *(me->buffer._read_p);


    __quex_debug_state(927);
switch( input ) {
case 0x0: goto _208;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x4F: goto _130;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_207:
    /* (927 from RELOAD_FORWARD)  */
    goto _366;


    __quex_assert_no_passage();
_209:
    /* (928 from RELOAD_FORWARD)  */
_368:
    input = *(me->buffer._read_p);


    __quex_debug_state(928);
switch( input ) {
case 0x0: goto _210;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x5F: goto _123;
case 0x6E: goto _129;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_91:
    /* (928 from 920)  */
    ++(me->buffer._read_p);

    goto _368;


    __quex_assert_no_passage();
_211:
    /* (929 from RELOAD_FORWARD)  */
_370:
    input = *(me->buffer._read_p);


    __quex_debug_state(929);
switch( input ) {
case 0x0: goto _212;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _172;
case 0x2E: goto _104;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _102;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_92:
    /* (929 from 920)  */
    ++(me->buffer._read_p);

    goto _370;


    __quex_assert_no_passage();
_93:
    /* (930 from 950) (930 from 961) (930 from 922) (930 from 933) (930 from 972) (930 from 983) (930 from 955) (930 from 962) (930 from 927) (930 from 945) (930 from 984) (930 from 956) (930 from 967) (930 from 939) (930 from 946) (930 from 989) (930 from 929) (930 from 968) (930 from 979) (930 from 951) (930 from 990) (930 from 923) (930 from 930) (930 from 980) (930 from 952) (930 from 963) (930 from 935) (930 from 985) (930 from 957) (930 from 964) (930 from 936) (930 from 947) (930 from 986) (930 from 958) (930 from 969) (930 from 976) (930 from 941) (930 from 948) (930 from 920) (930 from 931) (930 from 970) (930 from 981) (930 from 953) (930 from 960) (930 from 975) (930 from 982) (930 from 965) (930 from 926) (930 from 987) (930 from 959) (930 from 966) (930 from 977) (930 from 938) (930 from 949) (930 from 988) (930 from 928) (930 from 971) (930 from 978)  */

    ++(me->buffer._read_p);

_373:
    input = *(me->buffer._read_p);


    __quex_debug_state(930);
switch( input ) {
case 0x0: goto _214;
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
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_213:
    /* (930 from RELOAD_FORWARD)  */
    goto _373;


    __quex_assert_no_passage();
_215:
    /* (931 from RELOAD_FORWARD)  */
_375:
    input = *(me->buffer._read_p);


    __quex_debug_state(931);
switch( input ) {
case 0x0: goto _216;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x5F: goto _123;
case 0x65: goto _124;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_94:
    /* (931 from 920)  */
    ++(me->buffer._read_p);

    goto _375;


    __quex_assert_no_passage();
_95:
    /* (932 from 920)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(932);
goto _175;


    __quex_assert_no_passage();
_96:
    /* (933 from 920)  */
    ++(me->buffer._read_p);

_378:
    input = *(me->buffer._read_p);


    __quex_debug_state(933);
switch( input ) {
case 0x0: goto _218;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x5F: goto _123;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_217:
    /* (933 from RELOAD_FORWARD)  */
    goto _378;


    __quex_assert_no_passage();
_97:
    /* (934 from 920)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(934);
goto _176;


    __quex_assert_no_passage();
_219:
    /* (935 from RELOAD_FORWARD)  */
_381:
    input = *(me->buffer._read_p);


    __quex_debug_state(935);
switch( input ) {
case 0x0: goto _220;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _172;
case 0x2E: goto _104;
case 0x30: goto _102;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _85;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_98:
    /* (935 from 920)  */
    ++(me->buffer._read_p);

    goto _381;


    __quex_assert_no_passage();
_221:
    /* (936 from RELOAD_FORWARD)  */
_383:
    input = *(me->buffer._read_p);


    __quex_debug_state(936);
switch( input ) {
case 0x0: goto _222;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x6F: goto _118;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_99:
    /* (936 from 920)  */
    ++(me->buffer._read_p);

    goto _383;


    __quex_assert_no_passage();
_223:
    /* (937 from RELOAD_FORWARD)  */
_385:
    input = *(me->buffer._read_p);


    __quex_debug_state(937);
if     ( input == 0x3D )  goto _117;
else if( input == 0x0 )   goto _224;
else                      goto _177;


    __quex_assert_no_passage();
_100:
    /* (937 from 920)  */
    ++(me->buffer._read_p);

    goto _385;


    __quex_assert_no_passage();
_101:
    /* (938 from 926) (938 from 920)  */

    ++(me->buffer._read_p);

_388:
    input = *(me->buffer._read_p);


    __quex_debug_state(938);
switch( input ) {
case 0x0: goto _226;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x4E: goto _114;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_225:
    /* (938 from RELOAD_FORWARD)  */
    goto _388;


    __quex_assert_no_passage();
_102:
    /* (939 from 920) (939 from 929) (939 from 935) (939 from 981) (939 from 939)  */

    ++(me->buffer._read_p);

_391:
    input = *(me->buffer._read_p);


    __quex_debug_state(939);
switch( input ) {
case 0x0: goto _228;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _171;
case 0x2E: goto _104;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _102;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _171;
default: goto _93;
}


    __quex_assert_no_passage();
_227:
    /* (939 from RELOAD_FORWARD)  */
    goto _391;


    __quex_assert_no_passage();
_103:
    /* (940 from 920)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(940);
goto _178;


    __quex_assert_no_passage();
_104:
    /* (941 from 935) (941 from 920) (941 from 929) (941 from 939)  */

    ++(me->buffer._read_p);

_395:
    input = *(me->buffer._read_p);


    __quex_debug_state(941);
switch( input ) {
case 0x0: goto _230;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _172;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _113;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_229:
    /* (941 from RELOAD_FORWARD)  */
    goto _395;


    __quex_assert_no_passage();
_105:
    /* (942 from 920)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(942);
goto _179;


    __quex_assert_no_passage();
_106:
    /* (943 from 920)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(943);
goto _180;


    __quex_assert_no_passage();
_107:
    /* (944 from 920)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(944);
goto _181;


    __quex_assert_no_passage();
_231:
    /* (945 from RELOAD_FORWARD)  */
_400:
    input = *(me->buffer._read_p);


    __quex_debug_state(945);
switch( input ) {
case 0x0: goto _232;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x5F: goto _109;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_108:
    /* (945 from 920)  */
    ++(me->buffer._read_p);

    goto _400;


    __quex_assert_no_passage();
_109:
    /* (946 from 945)  */
    ++(me->buffer._read_p);

_402:
    input = *(me->buffer._read_p);


    __quex_debug_state(946);
switch( input ) {
case 0x0: goto _234;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _172;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _110;
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _111;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_233:
    /* (946 from RELOAD_FORWARD)  */
    goto _402;


    __quex_assert_no_passage();
_110:
    /* (947 from 946) (947 from 947)  */

    ++(me->buffer._read_p);

_405:
    input = *(me->buffer._read_p);


    __quex_debug_state(947);
switch( input ) {
case 0x0: goto _236;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _182;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _110;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _182;
default: goto _93;
}


    __quex_assert_no_passage();
_235:
    /* (947 from RELOAD_FORWARD)  */
    goto _405;


    __quex_assert_no_passage();
_111:
    /* (948 from 946) (948 from 960)  */

    ++(me->buffer._read_p);

_408:
    input = *(me->buffer._read_p);


    __quex_debug_state(948);
switch( input ) {
case 0x0: goto _238;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _172;
case 0x2D: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _112;
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _112;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_237:
    /* (948 from RELOAD_FORWARD)  */
    goto _408;


    __quex_assert_no_passage();
_112:
    /* (949 from 948) (949 from 949)  */

    ++(me->buffer._read_p);

_411:
    input = *(me->buffer._read_p);


    __quex_debug_state(949);
switch( input ) {
case 0x0: goto _240;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _183;
case 0x2D: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _112;
case 0x3C: case 0x3D: case 0x3E: goto _183;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _112;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _183;
default: goto _93;
}


    __quex_assert_no_passage();
_239:
    /* (949 from RELOAD_FORWARD)  */
    goto _411;


    __quex_assert_no_passage();
_113:
    /* (950 from 950) (950 from 941) (950 from 990)  */

    ++(me->buffer._read_p);

_414:
    input = *(me->buffer._read_p);


    __quex_debug_state(950);
switch( input ) {
case 0x0: goto _242;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _184;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _113;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _184;
default: goto _93;
}


    __quex_assert_no_passage();
_241:
    /* (950 from RELOAD_FORWARD)  */
    goto _414;


    __quex_assert_no_passage();
_243:
    /* (951 from RELOAD_FORWARD)  */
_416:
    input = *(me->buffer._read_p);


    __quex_debug_state(951);
switch( input ) {
case 0x0: goto _244;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x44: goto _115;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_114:
    /* (951 from 938)  */
    ++(me->buffer._read_p);

    goto _416;


    __quex_assert_no_passage();
_115:
    /* (952 from 951) (952 from 966)  */

    ++(me->buffer._read_p);

_419:
    input = *(me->buffer._read_p);


    __quex_debug_state(952);
switch( input ) {
case 0x0: goto _246;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _185;
case 0x3A: goto _116;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _185;
default: goto _93;
}


    __quex_assert_no_passage();
_245:
    /* (952 from RELOAD_FORWARD)  */
    goto _419;


    __quex_assert_no_passage();
_247:
    /* (953 from RELOAD_FORWARD)  */
_421:
    input = *(me->buffer._read_p);


    __quex_debug_state(953);
switch( input ) {
case 0x0: goto _248;
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
case 0x9D: goto _185;
default: goto _93;
}


    __quex_assert_no_passage();
_116:
    /* (953 from 952)  */
    ++(me->buffer._read_p);

    goto _421;


    __quex_assert_no_passage();
_117:
    /* (954 from 937)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(954);
goto _186;


    __quex_assert_no_passage();
_249:
    /* (955 from RELOAD_FORWARD)  */
_424:
    input = *(me->buffer._read_p);


    __quex_debug_state(955);
switch( input ) {
case 0x0: goto _250;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x64: goto _119;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_118:
    /* (955 from 936)  */
    ++(me->buffer._read_p);

    goto _424;


    __quex_assert_no_passage();
_251:
    /* (956 from RELOAD_FORWARD)  */
_426:
    input = *(me->buffer._read_p);


    __quex_debug_state(956);
switch( input ) {
case 0x0: goto _252;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x75: goto _120;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_119:
    /* (956 from 955)  */
    ++(me->buffer._read_p);

    goto _426;


    __quex_assert_no_passage();
_253:
    /* (957 from RELOAD_FORWARD)  */
_428:
    input = *(me->buffer._read_p);


    __quex_debug_state(957);
switch( input ) {
case 0x0: goto _254;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x6C: goto _121;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_120:
    /* (957 from 956)  */
    ++(me->buffer._read_p);

    goto _428;


    __quex_assert_no_passage();
_121:
    /* (958 from 957)  */
    ++(me->buffer._read_p);

_430:
    input = *(me->buffer._read_p);


    __quex_debug_state(958);
switch( input ) {
case 0x0: goto _256;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x65: goto _122;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_255:
    /* (958 from RELOAD_FORWARD)  */
    goto _430;


    __quex_assert_no_passage();
_122:
    /* (959 from 958) (959 from 970)  */

    ++(me->buffer._read_p);

_433:
    input = *(me->buffer._read_p);


    __quex_debug_state(959);
switch( input ) {
case 0x0: goto _258;
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
default: goto _93;
}


    __quex_assert_no_passage();
_257:
    /* (959 from RELOAD_FORWARD)  */
    goto _433;


    __quex_assert_no_passage();
_123:
    /* (960 from 931) (960 from 928) (960 from 933)  */

    ++(me->buffer._read_p);

_436:
    input = *(me->buffer._read_p);


    __quex_debug_state(960);
switch( input ) {
case 0x0: goto _260;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _111;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_259:
    /* (960 from RELOAD_FORWARD)  */
    goto _436;


    __quex_assert_no_passage();
_124:
    /* (961 from 931) (961 from 972)  */

    ++(me->buffer._read_p);

_439:
    input = *(me->buffer._read_p);


    __quex_debug_state(961);
switch( input ) {
case 0x0: goto _262;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x67: goto _125;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_261:
    /* (961 from RELOAD_FORWARD)  */
    goto _439;


    __quex_assert_no_passage();
_263:
    /* (962 from RELOAD_FORWARD)  */
_441:
    input = *(me->buffer._read_p);


    __quex_debug_state(962);
switch( input ) {
case 0x0: goto _264;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x69: goto _126;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_125:
    /* (962 from 961)  */
    ++(me->buffer._read_p);

    goto _441;


    __quex_assert_no_passage();
_265:
    /* (963 from RELOAD_FORWARD)  */
_443:
    input = *(me->buffer._read_p);


    __quex_debug_state(963);
switch( input ) {
case 0x0: goto _266;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x6E: goto _127;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_126:
    /* (963 from 962)  */
    ++(me->buffer._read_p);

    goto _443;


    __quex_assert_no_passage();
_127:
    /* (964 from 963) (964 from 977)  */

    ++(me->buffer._read_p);

_446:
    input = *(me->buffer._read_p);


    __quex_debug_state(964);
switch( input ) {
case 0x0: goto _268;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _188;
case 0x3A: goto _128;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _188;
default: goto _93;
}


    __quex_assert_no_passage();
_267:
    /* (964 from RELOAD_FORWARD)  */
    goto _446;


    __quex_assert_no_passage();
_269:
    /* (965 from RELOAD_FORWARD)  */
_448:
    input = *(me->buffer._read_p);


    __quex_debug_state(965);
switch( input ) {
case 0x0: goto _270;
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
case 0x9D: goto _188;
default: goto _93;
}


    __quex_assert_no_passage();
_128:
    /* (965 from 964)  */
    ++(me->buffer._read_p);

    goto _448;


    __quex_assert_no_passage();
_129:
    /* (966 from 928) (966 from 971)  */

    ++(me->buffer._read_p);

_451:
    input = *(me->buffer._read_p);


    __quex_debug_state(966);
switch( input ) {
case 0x0: goto _272;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x64: goto _115;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_271:
    /* (966 from RELOAD_FORWARD)  */
    goto _451;


    __quex_assert_no_passage();
_273:
    /* (967 from RELOAD_FORWARD)  */
_453:
    input = *(me->buffer._read_p);


    __quex_debug_state(967);
switch( input ) {
case 0x0: goto _274;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x44: goto _131;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_130:
    /* (967 from 927)  */
    ++(me->buffer._read_p);

    goto _453;


    __quex_assert_no_passage();
_131:
    /* (968 from 967)  */
    ++(me->buffer._read_p);

_455:
    input = *(me->buffer._read_p);


    __quex_debug_state(968);
switch( input ) {
case 0x0: goto _276;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x55: goto _132;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_275:
    /* (968 from RELOAD_FORWARD)  */
    goto _455;


    __quex_assert_no_passage();
_132:
    /* (969 from 968)  */
    ++(me->buffer._read_p);

_457:
    input = *(me->buffer._read_p);


    __quex_debug_state(969);
switch( input ) {
case 0x0: goto _278;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x4C: goto _133;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_277:
    /* (969 from RELOAD_FORWARD)  */
    goto _457;


    __quex_assert_no_passage();
_279:
    /* (970 from RELOAD_FORWARD)  */
_459:
    input = *(me->buffer._read_p);


    __quex_debug_state(970);
switch( input ) {
case 0x0: goto _280;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x45: goto _122;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_133:
    /* (970 from 969)  */
    ++(me->buffer._read_p);

    goto _459;


    __quex_assert_no_passage();
_134:
    /* (971 from 926)  */
    ++(me->buffer._read_p);

_461:
    input = *(me->buffer._read_p);


    __quex_debug_state(971);
switch( input ) {
case 0x0: goto _282;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x6E: goto _129;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_281:
    /* (971 from RELOAD_FORWARD)  */
    goto _461;


    __quex_assert_no_passage();
_283:
    /* (972 from RELOAD_FORWARD)  */
_463:
    input = *(me->buffer._read_p);


    __quex_debug_state(972);
switch( input ) {
case 0x0: goto _284;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x65: goto _124;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_135:
    /* (972 from 926)  */
    ++(me->buffer._read_p);

    goto _463;


    __quex_assert_no_passage();
_136:
    /* (973 from 925)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(973);
goto _189;


    __quex_assert_no_passage();
_137:
    /* (974 from 924)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(974);
goto _190;


    __quex_assert_no_passage();
_285:
    /* (975 from RELOAD_FORWARD)  */
_467:
    input = *(me->buffer._read_p);


    __quex_debug_state(975);
switch( input ) {
case 0x0: goto _286;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x47: goto _139;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_138:
    /* (975 from 923)  */
    ++(me->buffer._read_p);

    goto _467;


    __quex_assert_no_passage();
_287:
    /* (976 from RELOAD_FORWARD)  */
_469:
    input = *(me->buffer._read_p);


    __quex_debug_state(976);
switch( input ) {
case 0x0: goto _288;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x49: goto _140;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_139:
    /* (976 from 975)  */
    ++(me->buffer._read_p);

    goto _469;


    __quex_assert_no_passage();
_289:
    /* (977 from RELOAD_FORWARD)  */
_471:
    input = *(me->buffer._read_p);


    __quex_debug_state(977);
switch( input ) {
case 0x0: goto _290;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _172;
case 0x4E: goto _127;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_140:
    /* (977 from 976)  */
    ++(me->buffer._read_p);

    goto _471;


    __quex_assert_no_passage();
_141:
    /* (978 from 981) (978 from 980) (978 from 979) (978 from 922)  */

    ++(me->buffer._read_p);

_474:
    input = *(me->buffer._read_p);


    __quex_debug_state(978);
switch( input ) {
case 0x0: goto _292;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _172;
case 0x2D: goto _146;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _145;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_291:
    /* (978 from RELOAD_FORWARD)  */
    goto _474;


    __quex_assert_no_passage();
_293:
    /* (979 from RELOAD_FORWARD)  */
_476:
    input = *(me->buffer._read_p);


    __quex_debug_state(979);
switch( input ) {
case 0x0: goto _294;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _171;
case 0x2E: goto _141;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _143;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _171;
default: goto _93;
}


    __quex_assert_no_passage();
_142:
    /* (979 from 922)  */
    ++(me->buffer._read_p);

    goto _476;


    __quex_assert_no_passage();
_143:
    /* (980 from 979)  */
    ++(me->buffer._read_p);

_478:
    input = *(me->buffer._read_p);


    __quex_debug_state(980);
switch( input ) {
case 0x0: goto _296;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _171;
case 0x2E: goto _141;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _144;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _171;
default: goto _93;
}


    __quex_assert_no_passage();
_295:
    /* (980 from RELOAD_FORWARD)  */
    goto _478;


    __quex_assert_no_passage();
_144:
    /* (981 from 980)  */
    ++(me->buffer._read_p);

_480:
    input = *(me->buffer._read_p);


    __quex_debug_state(981);
switch( input ) {
case 0x0: goto _298;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _171;
case 0x2E: goto _141;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _102;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _171;
default: goto _93;
}


    __quex_assert_no_passage();
_297:
    /* (981 from RELOAD_FORWARD)  */
    goto _480;


    __quex_assert_no_passage();
_299:
    /* (982 from RELOAD_FORWARD)  */
_482:
    input = *(me->buffer._read_p);


    __quex_debug_state(982);
switch( input ) {
case 0x0: goto _300;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _184;
case 0x2E: goto _149;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _153;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _184;
default: goto _93;
}


    __quex_assert_no_passage();
_145:
    /* (982 from 978)  */
    ++(me->buffer._read_p);

    goto _482;


    __quex_assert_no_passage();
_301:
    /* (983 from RELOAD_FORWARD)  */
_484:
    input = *(me->buffer._read_p);


    __quex_debug_state(983);
switch( input ) {
case 0x0: goto _302;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _172;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _147;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_146:
    /* (983 from 978)  */
    ++(me->buffer._read_p);

    goto _484;


    __quex_assert_no_passage();
_303:
    /* (984 from RELOAD_FORWARD)  */
_486:
    input = *(me->buffer._read_p);


    __quex_debug_state(984);
switch( input ) {
case 0x0: goto _304;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _172;
case 0x2E: goto _149;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _148;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_147:
    /* (984 from 983)  */
    ++(me->buffer._read_p);

    goto _486;


    __quex_assert_no_passage();
_305:
    /* (985 from RELOAD_FORWARD)  */
_488:
    input = *(me->buffer._read_p);


    __quex_debug_state(985);
switch( input ) {
case 0x0: goto _306;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _172;
case 0x2E: goto _149;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_148:
    /* (985 from 984)  */
    ++(me->buffer._read_p);

    goto _488;


    __quex_assert_no_passage();
_149:
    /* (986 from 990) (986 from 985) (986 from 984) (986 from 982)  */

    ++(me->buffer._read_p);

_491:
    input = *(me->buffer._read_p);


    __quex_debug_state(986);
switch( input ) {
case 0x0: goto _308;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _172;
case 0x2D: goto _151;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _150;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_307:
    /* (986 from RELOAD_FORWARD)  */
    goto _491;


    __quex_assert_no_passage();
_150:
    /* (987 from 986) (987 from 988)  */

    ++(me->buffer._read_p);

_494:
    input = *(me->buffer._read_p);


    __quex_debug_state(987);
switch( input ) {
case 0x0: goto _310;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _191;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _152;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _191;
default: goto _93;
}


    __quex_assert_no_passage();
_309:
    /* (987 from RELOAD_FORWARD)  */
    goto _494;


    __quex_assert_no_passage();
_151:
    /* (988 from 986)  */
    ++(me->buffer._read_p);

_496:
    input = *(me->buffer._read_p);


    __quex_debug_state(988);
switch( input ) {
case 0x0: goto _312;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _172;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _150;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _172;
default: goto _93;
}


    __quex_assert_no_passage();
_311:
    /* (988 from RELOAD_FORWARD)  */
    goto _496;


    __quex_assert_no_passage();
_152:
    /* (989 from 987)  */
    ++(me->buffer._read_p);

_498:
    input = *(me->buffer._read_p);


    __quex_debug_state(989);
switch( input ) {
case 0x0: goto _314;
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
default: goto _93;
}


    __quex_assert_no_passage();
_313:
    /* (989 from RELOAD_FORWARD)  */
    goto _498;


    __quex_assert_no_passage();
_315:
    /* (990 from RELOAD_FORWARD)  */
_500:
    input = *(me->buffer._read_p);


    __quex_debug_state(990);
switch( input ) {
case 0x0: goto _316;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _184;
case 0x2E: goto _149;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _113;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _184;
default: goto _93;
}


    __quex_assert_no_passage();
_153:
    /* (990 from 982)  */
    ++(me->buffer._read_p);

    goto _500;


    __quex_assert_no_passage();
_154:
    /* (991 from 998) (991 from 991) (991 from 1005) (991 from 1000) (991 from 1004) (991 from 997) (991 from 992) (991 from 921) (991 from 996) (991 from 1002) (991 from 995) (991 from 1006) (991 from 999) (991 from 994) (991 from 1001)  */

    ++(me->buffer._read_p);

_503:
    input = *(me->buffer._read_p);


    __quex_debug_state(991);
switch( input ) {
case 0x0: goto _318;
case 0x1: 
case 0xA: 
case 0xD: goto _170;
case 0x22: goto _156;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _154;
}


    __quex_assert_no_passage();
_317:
    /* (991 from RELOAD_FORWARD)  */
    goto _503;


    __quex_assert_no_passage();
_319:
    /* (992 from RELOAD_FORWARD)  */
_505:
    input = *(me->buffer._read_p);


    __quex_debug_state(992);
switch( input ) {
case 0x0: goto _320;
case 0x1: 
case 0xA: 
case 0xD: goto _170;
case 0x22: goto _156;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _157;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _154;
}


    __quex_assert_no_passage();
_155:
    /* (992 from 921)  */
    ++(me->buffer._read_p);

    goto _505;


    __quex_assert_no_passage();
_156:
    /* (993 from 1002) (993 from 996) (993 from 1005) (993 from 991) (993 from 992) (993 from 999) (993 from 1000) (993 from 995) (993 from 998) (993 from 921) (993 from 994) (993 from 997) (993 from 1006)  */

    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(993);
goto _192;


    __quex_assert_no_passage();
_157:
    /* (994 from 921) (994 from 992)  */

    ++(me->buffer._read_p);

_510:
    input = *(me->buffer._read_p);


    __quex_debug_state(994);
switch( input ) {
case 0x0: goto _322;
case 0x1: 
case 0xA: 
case 0xD: goto _170;
case 0x22: goto _156;
case 0x2E: goto _159;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _158;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _154;
}


    __quex_assert_no_passage();
_321:
    /* (994 from RELOAD_FORWARD)  */
    goto _510;


    __quex_assert_no_passage();
_158:
    /* (995 from 994)  */
    ++(me->buffer._read_p);

_512:
    input = *(me->buffer._read_p);


    __quex_debug_state(995);
switch( input ) {
case 0x0: goto _324;
case 0x1: 
case 0xA: 
case 0xD: goto _170;
case 0x22: goto _156;
case 0x2E: goto _159;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _168;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _154;
}


    __quex_assert_no_passage();
_323:
    /* (995 from RELOAD_FORWARD)  */
    goto _512;


    __quex_assert_no_passage();
_159:
    /* (996 from 1006) (996 from 1005) (996 from 995) (996 from 994)  */

    ++(me->buffer._read_p);

_515:
    input = *(me->buffer._read_p);


    __quex_debug_state(996);
switch( input ) {
case 0x0: goto _326;
case 0x1: 
case 0xA: 
case 0xD: goto _170;
case 0x22: goto _156;
case 0x2D: goto _160;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _161;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _154;
}


    __quex_assert_no_passage();
_325:
    /* (996 from RELOAD_FORWARD)  */
    goto _515;


    __quex_assert_no_passage();
_327:
    /* (997 from RELOAD_FORWARD)  */
_517:
    input = *(me->buffer._read_p);


    __quex_debug_state(997);
switch( input ) {
case 0x0: goto _328;
case 0x1: 
case 0xA: 
case 0xD: goto _170;
case 0x22: goto _156;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _161;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _154;
}


    __quex_assert_no_passage();
_160:
    /* (997 from 996)  */
    ++(me->buffer._read_p);

    goto _517;


    __quex_assert_no_passage();
_161:
    /* (998 from 997) (998 from 996)  */

    ++(me->buffer._read_p);

_520:
    input = *(me->buffer._read_p);


    __quex_debug_state(998);
switch( input ) {
case 0x0: goto _330;
case 0x1: 
case 0xA: 
case 0xD: goto _170;
case 0x22: goto _156;
case 0x2E: goto _162;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _163;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _154;
}


    __quex_assert_no_passage();
_329:
    /* (998 from RELOAD_FORWARD)  */
    goto _520;


    __quex_assert_no_passage();
_162:
    /* (999 from 998) (999 from 1000)  */

    ++(me->buffer._read_p);

_523:
    input = *(me->buffer._read_p);


    __quex_debug_state(999);
switch( input ) {
case 0x0: goto _332;
case 0x1: 
case 0xA: 
case 0xD: goto _170;
case 0x22: goto _156;
case 0x2D: goto _165;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _164;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _154;
}


    __quex_assert_no_passage();
_331:
    /* (999 from RELOAD_FORWARD)  */
    goto _523;


    __quex_assert_no_passage();
_333:
    /* (1000 from RELOAD_FORWARD)  */
_525:
    input = *(me->buffer._read_p);


    __quex_debug_state(1000);
switch( input ) {
case 0x0: goto _334;
case 0x1: 
case 0xA: 
case 0xD: goto _170;
case 0x22: goto _156;
case 0x2E: goto _162;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _154;
}


    __quex_assert_no_passage();
_163:
    /* (1000 from 998)  */
    ++(me->buffer._read_p);

    goto _525;


    __quex_assert_no_passage();
_164:
    /* (1001 from 1002) (1001 from 999)  */

    ++(me->buffer._read_p);

_528:
    input = *(me->buffer._read_p);


    __quex_debug_state(1001);
switch( input ) {
case 0x0: goto _336;
case 0x1: 
case 0xA: 
case 0xD: goto _170;
case 0x22: goto _166;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _167;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _154;
}


    __quex_assert_no_passage();
_335:
    /* (1001 from RELOAD_FORWARD)  */
    goto _528;


    __quex_assert_no_passage();
_165:
    /* (1002 from 999)  */
    ++(me->buffer._read_p);

_530:
    input = *(me->buffer._read_p);


    __quex_debug_state(1002);
switch( input ) {
case 0x0: goto _338;
case 0x1: 
case 0xA: 
case 0xD: goto _170;
case 0x22: goto _156;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _164;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _154;
}


    __quex_assert_no_passage();
_337:
    /* (1002 from RELOAD_FORWARD)  */
    goto _530;


    __quex_assert_no_passage();
_166:
    /* (1003 from 1001) (1003 from 1004)  */

    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(1003);
goto _193;


    __quex_assert_no_passage();
_339:
    /* (1004 from RELOAD_FORWARD)  */
_534:
    input = *(me->buffer._read_p);


    __quex_debug_state(1004);
switch( input ) {
case 0x0: goto _340;
case 0x1: 
case 0xA: 
case 0xD: goto _170;
case 0x22: goto _166;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _154;
}


    __quex_assert_no_passage();
_167:
    /* (1004 from 1001)  */
    ++(me->buffer._read_p);

    goto _534;


    __quex_assert_no_passage();
_341:
    /* (1005 from RELOAD_FORWARD)  */
_536:
    input = *(me->buffer._read_p);


    __quex_debug_state(1005);
switch( input ) {
case 0x0: goto _342;
case 0x1: 
case 0xA: 
case 0xD: goto _170;
case 0x22: goto _156;
case 0x2E: goto _159;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _169;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _154;
}


    __quex_assert_no_passage();
_168:
    /* (1005 from 995)  */
    ++(me->buffer._read_p);

    goto _536;


    __quex_assert_no_passage();
_169:
    /* (1006 from 1005)  */
    ++(me->buffer._read_p);

_538:
    input = *(me->buffer._read_p);


    __quex_debug_state(1006);
switch( input ) {
case 0x0: goto _344;
case 0x1: 
case 0xA: 
case 0xD: goto _170;
case 0x22: goto _156;
case 0x2E: goto _159;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _170;
default: goto _154;
}


    __quex_assert_no_passage();
_343:
    /* (1006 from RELOAD_FORWARD)  */
    goto _538;
_20:
    /* (611 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

_540:
__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_539:
    __quex_debug("Init State\n");
    __quex_debug_state(611);
switch( input ) {
case 0x0: goto _32;
case 0x9: goto _22;
case 0xA: goto _21;
case 0xD: 
case 0x20: goto _23;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _25;
default: goto _24;
}


    __quex_assert_no_passage();
_33:
    /* (611 from 617)  */
    goto _539;


    __quex_assert_no_passage();
_30:
    /* (611 from RELOAD_FORWARD)  */
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

    goto _540;


    __quex_assert_no_passage();
_27:
    /* (DROP_OUT from 613)  */
    goto _36;
_541:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_26:
    /* (DROP_OUT from 612)  */
    goto _35;


    __quex_assert_no_passage();
_28:
    /* (DROP_OUT from 614)  */
    goto _37;


    __quex_assert_no_passage();
_29:
    /* (DROP_OUT from 615)  */
    goto _34;


    __quex_assert_no_passage();
_25:
    /* (DROP_OUT from 611)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _82;
    goto _541;


    __quex_assert_no_passage();
_21:
    /* (612 from 611)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(612);
goto _26;


    __quex_assert_no_passage();
_22:
    /* (613 from 611)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(613);
goto _27;


    __quex_assert_no_passage();
_23:
    /* (614 from 611)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(614);
goto _28;


    __quex_assert_no_passage();
_24:
    /* (615 from 611)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(615);
goto _29;
_43:
    /* (644 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

_547:
__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_546:
    __quex_debug("Init State\n");
    __quex_debug_state(644);
switch( input ) {
case 0x0: goto _52;
case 0x9: goto _45;
case 0xA: goto _44;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _47;
default: goto _46;
}


    __quex_assert_no_passage();
_53:
    /* (644 from 648)  */
    goto _546;


    __quex_assert_no_passage();
_51:
    /* (644 from RELOAD_FORWARD)  */
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

    goto _547;


    __quex_assert_no_passage();
_49:
    /* (DROP_OUT from 646)  */
    goto _57;
_548:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_48:
    /* (DROP_OUT from 645)  */
    goto _56;


    __quex_assert_no_passage();
_50:
    /* (DROP_OUT from 647)  */
    goto _58;


    __quex_assert_no_passage();
_47:
    /* (DROP_OUT from 644)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _82;
    goto _548;


    __quex_assert_no_passage();
_44:
    /* (645 from 644)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(645);
goto _48;


    __quex_assert_no_passage();
_45:
    /* (646 from 644)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(646);
goto _49;


    __quex_assert_no_passage();
_46:
    /* (647 from 644)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(647);
goto _50;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_79:
    __quex_debug("* TERMINAL BAD_LEXATOM\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{
self.error_code = E_Error_NoHandler_OnBadLexatom;
self_send(QUEX_TOKEN_ID(TERMINATION));
__QUEX_PURE_RETURN;;

}
    /* Bad lexatom detection FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
__QUEX_PURE_RETURN;
_80:
    __quex_debug("* TERMINAL LOAD_FAILURE\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{
self.error_code = E_Error_NoHandler_OnLoadFailure;
self_send(QUEX_TOKEN_ID(TERMINATION));
__QUEX_PURE_RETURN;;

}
    /* Load failure FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
__QUEX_PURE_RETURN;
_81:
    __quex_debug("* TERMINAL OVERFLOW\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{
self.error_code = E_Error_NoHandler_OnOverflow;
self_send(QUEX_TOKEN_ID(TERMINATION));
__QUEX_PURE_RETURN;;

}
    /* Lexeme size exceeds buffer size. No further buffer load possible.
     */
__QUEX_PURE_RETURN;
_31:
    __quex_debug("* TERMINAL END_OF_STREAM\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 64 "zck.qx"
self_send(TK_TERMINATION);

__QUEX_PURE_RETURN;


#   line 3650 "Lexer.cpp"

}
    /* End of Stream FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
__QUEX_PURE_RETURN;
_82:
    __quex_debug("* TERMINAL FAILURE\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 65 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(TK_FAILURE);

__QUEX_PURE_RETURN;


#   line 3670 "Lexer.cpp"

}
RETURN;
_38:
    __quex_debug("* TERMINAL <skip>\n");
goto _20;
_42:
    __quex_debug("* TERMINAL SKIP_RANGE_OPEN\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{
#define Counter counter
self.error_code = E_Error_NoHandler_OnSkipRangeOpen;
self_send(QUEX_TOKEN_ID(TERMINATION));
__QUEX_PURE_RETURN;;

}
    /* End of Stream appeared, while scanning for end of skip-range.
     */
__QUEX_PURE_RETURN;
_34:
    __quex_debug("* TERMINAL <LOOP EXIT>\n");
    --(me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _19;

_35:
    __quex_debug("* TERMINAL <LOOP 172>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _33;

_36:
    __quex_debug("* TERMINAL <LOOP 173>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _33;

_37:
    __quex_debug("* TERMINAL <LOOP 174>\n");
goto _33;

_39:
    __quex_debug("* TERMINAL ENTER SKIP:\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

goto _38;

_40:
    __quex_debug("* TERMINAL ENTER SKIP:\n");
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

goto _38;

_41:
    __quex_debug("* TERMINAL ENTER SKIP:\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)1);

goto _38;

_55:
    __quex_debug("* TERMINAL <SKIP RANGE TERMINATED>\n");
goto _19;
_54:
    __quex_debug("* TERMINAL <LOOP EXIT>\n");
    --(me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _19;

_56:
    __quex_debug("* TERMINAL <COUPLE 187>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _55;

_57:
    __quex_debug("* TERMINAL <LOOP 188>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _53;

_58:
    __quex_debug("* TERMINAL <LOOP 189>\n");
goto _53;

_59:
    __quex_debug("* TERMINAL <skip range><skip_range open>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
goto _43;
_60:
    __quex_debug("* TERMINAL \"==\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 66 "zck.qx"
self_send(TK_OP_DEQ);

__QUEX_PURE_RETURN;


#   line 3802 "Lexer.cpp"

}
RETURN;
_61:
    __quex_debug("* TERMINAL \"=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 67 "zck.qx"
self_send(TK_OP_EQ);

__QUEX_PURE_RETURN;


#   line 3819 "Lexer.cpp"

}
RETURN;
_62:
    __quex_debug("* TERMINAL \"<=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 68 "zck.qx"
self_send(TK_OP_LTEQ);

__QUEX_PURE_RETURN;


#   line 3836 "Lexer.cpp"

}
RETURN;
_63:
    __quex_debug("* TERMINAL \"<\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 69 "zck.qx"
self_send(TK_OP_LT);

__QUEX_PURE_RETURN;


#   line 3853 "Lexer.cpp"

}
RETURN;
_64:
    __quex_debug("* TERMINAL \">=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 70 "zck.qx"
self_send(TK_OP_GTEQ);

__QUEX_PURE_RETURN;


#   line 3870 "Lexer.cpp"

}
RETURN;
_65:
    __quex_debug("* TERMINAL \">\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 71 "zck.qx"
self_send(TK_OP_GT);

__QUEX_PURE_RETURN;


#   line 3887 "Lexer.cpp"

}
RETURN;
_66:
    __quex_debug("* TERMINAL \"{\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 72 "zck.qx"
self_send(TK_OPEN_BRACE);

__QUEX_PURE_RETURN;


#   line 3904 "Lexer.cpp"

}
RETURN;
_67:
    __quex_debug("* TERMINAL \"}\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 73 "zck.qx"
self_send(TK_CLOSE_BRACE);

__QUEX_PURE_RETURN;


#   line 3921 "Lexer.cpp"

}
RETURN;
_68:
    __quex_debug("* TERMINAL {SIGN}[0-9]+\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
QUEX_LEXEME_TERMINATING_ZERO_SET(&me->buffer);
{

#   line 74 "zck.qx"
self_write_token_p()->number = (size_t)atoi( (char*)Lexeme );
self_send(TK_INTEGER);

__QUEX_PURE_RETURN;


#   line 3940 "Lexer.cpp"

}
RETURN;
_69:
    __quex_debug("* TERMINAL {DECIMAL}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 75 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(TK_DECIMAL);

__QUEX_PURE_RETURN;


#   line 3958 "Lexer.cpp"

}
RETURN;
_70:
    __quex_debug("* TERMINAL {DATE}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 76 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(TK_DATE);

__QUEX_PURE_RETURN;


#   line 3976 "Lexer.cpp"

}
RETURN;
_71:
    __quex_debug("* TERMINAL \"\\\"\"{DATE}\"\\\"\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 77 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), LexemeBegin+1, LexemeEnd-1);
self_send(TK_QDATE);

__QUEX_PURE_RETURN;


#   line 3994 "Lexer.cpp"

}
RETURN;
_72:
    __quex_debug("* TERMINAL {MODULE}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(6);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 78 "zck.qx"
self_send(TK_KW_MODULE);

__QUEX_PURE_RETURN;


#   line 4011 "Lexer.cpp"

}
RETURN;
_73:
    __quex_debug("* TERMINAL ^{BEGIN}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 79 "zck.qx"
self_send(TK_KW_BEGIN);

__QUEX_PURE_RETURN;


#   line 4028 "Lexer.cpp"

}
RETURN;
_74:
    __quex_debug("* TERMINAL ^{END}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 80 "zck.qx"
self_send(TK_KW_END);

__QUEX_PURE_RETURN;


#   line 4045 "Lexer.cpp"

}
RETURN;
_75:
    __quex_debug("* TERMINAL {QSTRING}\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 81 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), LexemeBegin+1, LexemeEnd-1);
self_send(TK_QSTRING);

__QUEX_PURE_RETURN;


#   line 4062 "Lexer.cpp"

}
RETURN;
_76:
    __quex_debug("* TERMINAL {CHAR_ID}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 82 "zck.qx"
self_write_token_p()->number = (size_t)atoi( (char*)LexemeBegin + 2 );
self_send(TK_CHAR_SCOPE);

__QUEX_PURE_RETURN;


#   line 4080 "Lexer.cpp"

}
RETURN;
_77:
    __quex_debug("* TERMINAL {TITLE_ID}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 83 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(TK_TITLE_ID);

__QUEX_PURE_RETURN;


#   line 4098 "Lexer.cpp"

}
RETURN;
_78:
    __quex_debug("* TERMINAL {STRING}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
    me->buffer._lexatom_before_lexeme_start = *(me->buffer._read_p - 1);
{

#   line 84 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(TK_STRING);

__QUEX_PURE_RETURN;


#   line 4116 "Lexer.cpp"

}
RETURN;
if(0) {
    /* Avoid unreferenced labels. */
    goto _79;
    goto _80;
    goto _81;
    goto _31;
    goto _82;
    goto _38;
    goto _42;
    goto _34;
    goto _35;
    goto _36;
    goto _37;
    goto _39;
    goto _40;
    goto _41;
    goto _55;
    goto _54;
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
    goto _75;
    goto _76;
    goto _77;
    goto _78;
}
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_557:
switch( target_state_index ) {
case 30: {
goto _30;}
case 31: {
goto _31;}
case 42: {
goto _42;}
case 51: {
goto _51;}
case 83: {
goto _83;}
case 170: {
goto _170;}
case 171: {
goto _171;}
case 172: {
goto _172;}
case 173: {
goto _173;}
case 174: {
goto _174;}
case 177: {
goto _177;}
case 182: {
goto _182;}
case 183: {
goto _183;}
case 184: {
goto _184;}
case 185: {
goto _185;}
case 187: {
goto _187;}
case 188: {
goto _188;}
case 191: {
goto _191;}
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
case 253: {
goto _253;}
case 255: {
goto _255;}
case 257: {
goto _257;}
case 259: {
goto _259;}
case 261: {
goto _261;}
case 263: {
goto _263;}
case 265: {
goto _265;}
case 267: {
goto _267;}
case 269: {
goto _269;}
case 271: {
goto _271;}
case 273: {
goto _273;}
case 275: {
goto _275;}
case 277: {
goto _277;}
case 279: {
goto _279;}
case 281: {
goto _281;}
case 283: {
goto _283;}
case 285: {
goto _285;}
case 287: {
goto _287;}
case 289: {
goto _289;}
case 291: {
goto _291;}
case 293: {
goto _293;}
case 295: {
goto _295;}
case 297: {
goto _297;}
case 299: {
goto _299;}
case 301: {
goto _301;}
case 303: {
goto _303;}
case 305: {
goto _305;}
case 307: {
goto _307;}
case 309: {
goto _309;}
case 311: {
goto _311;}
case 313: {
goto _313;}
case 315: {
goto _315;}
case 317: {
goto _317;}
case 319: {
goto _319;}
case 321: {
goto _321;}
case 323: {
goto _323;}
case 325: {
goto _325;}
case 327: {
goto _327;}
case 329: {
goto _329;}
case 331: {
goto _331;}
case 333: {
goto _333;}
case 335: {
goto _335;}
case 337: {
goto _337;}
case 339: {
goto _339;}
case 341: {
goto _341;}
case 343: {
goto _343;}
default: {
goto _343;}
}
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */


    __quex_assert_no_passage();
_52:
    /* (RELOAD_FORWARD from 644)  */
    target_state_index = QUEX_LABEL(51); target_state_else_index = QUEX_LABEL(42);

_553:
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

_552:

    __quex_debug3("RELOAD_FORWARD: success->%i; failure->%i", 
                  (int)target_state_index, (int)target_state_else_index);
    __quex_assert(*(me->buffer._read_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    
    __quex_debug_reload_before();                 
    load_result = QUEX_NAME(Buffer_load_forward)(&me->buffer, (QUEX_TYPE_LEXATOM**)position, PositionRegisterN);
    __quex_debug_reload_after(load_result);

    switch( load_result ) {
    case E_LoadResult_DONE:              QUEX_GOTO_STATE(target_state_index);      
    case E_LoadResult_BAD_LEXATOM:       goto _79;
    case E_LoadResult_FAILURE:           goto _80;
    case E_LoadResult_NO_SPACE_FOR_LOAD: goto _81;
    case E_LoadResult_NO_MORE_DATA:      QUEX_GOTO_STATE(target_state_else_index); 
    default:                             __quex_assert(false);
    }


    __quex_assert_no_passage();
_32:
    /* (RELOAD_FORWARD from 611)  */
    target_state_index = QUEX_LABEL(30); target_state_else_index = QUEX_LABEL(31);

    goto _553;


    __quex_assert_no_passage();
_194:
    /* (RELOAD_FORWARD from 920)  */
    target_state_index = QUEX_LABEL(83); target_state_else_index = QUEX_LABEL(31);

    goto _552;


    __quex_assert_no_passage();
_196:
    /* (RELOAD_FORWARD from 921)  */
    target_state_index = QUEX_LABEL(195); target_state_else_index = QUEX_LABEL(170);

    goto _552;


    __quex_assert_no_passage();
_198:
    /* (RELOAD_FORWARD from 922)  */
    target_state_index = QUEX_LABEL(197); target_state_else_index = QUEX_LABEL(171);

    goto _552;


    __quex_assert_no_passage();
_200:
    /* (RELOAD_FORWARD from 923)  */
    target_state_index = QUEX_LABEL(199); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_202:
    /* (RELOAD_FORWARD from 924)  */
    target_state_index = QUEX_LABEL(201); target_state_else_index = QUEX_LABEL(173);

    goto _552;


    __quex_assert_no_passage();
_204:
    /* (RELOAD_FORWARD from 925)  */
    target_state_index = QUEX_LABEL(203); target_state_else_index = QUEX_LABEL(174);

    goto _552;


    __quex_assert_no_passage();
_206:
    /* (RELOAD_FORWARD from 926)  */
    target_state_index = QUEX_LABEL(205); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_208:
    /* (RELOAD_FORWARD from 927)  */
    target_state_index = QUEX_LABEL(207); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_210:
    /* (RELOAD_FORWARD from 928)  */
    target_state_index = QUEX_LABEL(209); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_212:
    /* (RELOAD_FORWARD from 929)  */
    target_state_index = QUEX_LABEL(211); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_214:
    /* (RELOAD_FORWARD from 930)  */
    target_state_index = QUEX_LABEL(213); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_216:
    /* (RELOAD_FORWARD from 931)  */
    target_state_index = QUEX_LABEL(215); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_218:
    /* (RELOAD_FORWARD from 933)  */
    target_state_index = QUEX_LABEL(217); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_220:
    /* (RELOAD_FORWARD from 935)  */
    target_state_index = QUEX_LABEL(219); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_222:
    /* (RELOAD_FORWARD from 936)  */
    target_state_index = QUEX_LABEL(221); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_224:
    /* (RELOAD_FORWARD from 937)  */
    target_state_index = QUEX_LABEL(223); target_state_else_index = QUEX_LABEL(177);

    goto _552;


    __quex_assert_no_passage();
_226:
    /* (RELOAD_FORWARD from 938)  */
    target_state_index = QUEX_LABEL(225); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_228:
    /* (RELOAD_FORWARD from 939)  */
    target_state_index = QUEX_LABEL(227); target_state_else_index = QUEX_LABEL(171);

    goto _552;


    __quex_assert_no_passage();
_230:
    /* (RELOAD_FORWARD from 941)  */
    target_state_index = QUEX_LABEL(229); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_232:
    /* (RELOAD_FORWARD from 945)  */
    target_state_index = QUEX_LABEL(231); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_234:
    /* (RELOAD_FORWARD from 946)  */
    target_state_index = QUEX_LABEL(233); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_236:
    /* (RELOAD_FORWARD from 947)  */
    target_state_index = QUEX_LABEL(235); target_state_else_index = QUEX_LABEL(182);

    goto _552;


    __quex_assert_no_passage();
_238:
    /* (RELOAD_FORWARD from 948)  */
    target_state_index = QUEX_LABEL(237); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_240:
    /* (RELOAD_FORWARD from 949)  */
    target_state_index = QUEX_LABEL(239); target_state_else_index = QUEX_LABEL(183);

    goto _552;


    __quex_assert_no_passage();
_242:
    /* (RELOAD_FORWARD from 950)  */
    target_state_index = QUEX_LABEL(241); target_state_else_index = QUEX_LABEL(184);

    goto _552;


    __quex_assert_no_passage();
_244:
    /* (RELOAD_FORWARD from 951)  */
    target_state_index = QUEX_LABEL(243); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_246:
    /* (RELOAD_FORWARD from 952)  */
    target_state_index = QUEX_LABEL(245); target_state_else_index = QUEX_LABEL(185);

    goto _552;


    __quex_assert_no_passage();
_248:
    /* (RELOAD_FORWARD from 953)  */
    target_state_index = QUEX_LABEL(247); target_state_else_index = QUEX_LABEL(185);

    goto _552;


    __quex_assert_no_passage();
_250:
    /* (RELOAD_FORWARD from 955)  */
    target_state_index = QUEX_LABEL(249); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_252:
    /* (RELOAD_FORWARD from 956)  */
    target_state_index = QUEX_LABEL(251); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_254:
    /* (RELOAD_FORWARD from 957)  */
    target_state_index = QUEX_LABEL(253); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_256:
    /* (RELOAD_FORWARD from 958)  */
    target_state_index = QUEX_LABEL(255); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_258:
    /* (RELOAD_FORWARD from 959)  */
    target_state_index = QUEX_LABEL(257); target_state_else_index = QUEX_LABEL(187);

    goto _552;


    __quex_assert_no_passage();
_260:
    /* (RELOAD_FORWARD from 960)  */
    target_state_index = QUEX_LABEL(259); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_262:
    /* (RELOAD_FORWARD from 961)  */
    target_state_index = QUEX_LABEL(261); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_264:
    /* (RELOAD_FORWARD from 962)  */
    target_state_index = QUEX_LABEL(263); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_266:
    /* (RELOAD_FORWARD from 963)  */
    target_state_index = QUEX_LABEL(265); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_268:
    /* (RELOAD_FORWARD from 964)  */
    target_state_index = QUEX_LABEL(267); target_state_else_index = QUEX_LABEL(188);

    goto _552;


    __quex_assert_no_passage();
_270:
    /* (RELOAD_FORWARD from 965)  */
    target_state_index = QUEX_LABEL(269); target_state_else_index = QUEX_LABEL(188);

    goto _552;


    __quex_assert_no_passage();
_272:
    /* (RELOAD_FORWARD from 966)  */
    target_state_index = QUEX_LABEL(271); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_274:
    /* (RELOAD_FORWARD from 967)  */
    target_state_index = QUEX_LABEL(273); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_276:
    /* (RELOAD_FORWARD from 968)  */
    target_state_index = QUEX_LABEL(275); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_278:
    /* (RELOAD_FORWARD from 969)  */
    target_state_index = QUEX_LABEL(277); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_280:
    /* (RELOAD_FORWARD from 970)  */
    target_state_index = QUEX_LABEL(279); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_282:
    /* (RELOAD_FORWARD from 971)  */
    target_state_index = QUEX_LABEL(281); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_284:
    /* (RELOAD_FORWARD from 972)  */
    target_state_index = QUEX_LABEL(283); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_286:
    /* (RELOAD_FORWARD from 975)  */
    target_state_index = QUEX_LABEL(285); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_288:
    /* (RELOAD_FORWARD from 976)  */
    target_state_index = QUEX_LABEL(287); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_290:
    /* (RELOAD_FORWARD from 977)  */
    target_state_index = QUEX_LABEL(289); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_292:
    /* (RELOAD_FORWARD from 978)  */
    target_state_index = QUEX_LABEL(291); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_294:
    /* (RELOAD_FORWARD from 979)  */
    target_state_index = QUEX_LABEL(293); target_state_else_index = QUEX_LABEL(171);

    goto _552;


    __quex_assert_no_passage();
_296:
    /* (RELOAD_FORWARD from 980)  */
    target_state_index = QUEX_LABEL(295); target_state_else_index = QUEX_LABEL(171);

    goto _552;


    __quex_assert_no_passage();
_298:
    /* (RELOAD_FORWARD from 981)  */
    target_state_index = QUEX_LABEL(297); target_state_else_index = QUEX_LABEL(171);

    goto _552;


    __quex_assert_no_passage();
_300:
    /* (RELOAD_FORWARD from 982)  */
    target_state_index = QUEX_LABEL(299); target_state_else_index = QUEX_LABEL(184);

    goto _552;


    __quex_assert_no_passage();
_302:
    /* (RELOAD_FORWARD from 983)  */
    target_state_index = QUEX_LABEL(301); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_304:
    /* (RELOAD_FORWARD from 984)  */
    target_state_index = QUEX_LABEL(303); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_306:
    /* (RELOAD_FORWARD from 985)  */
    target_state_index = QUEX_LABEL(305); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_308:
    /* (RELOAD_FORWARD from 986)  */
    target_state_index = QUEX_LABEL(307); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_310:
    /* (RELOAD_FORWARD from 987)  */
    target_state_index = QUEX_LABEL(309); target_state_else_index = QUEX_LABEL(191);

    goto _552;


    __quex_assert_no_passage();
_312:
    /* (RELOAD_FORWARD from 988)  */
    target_state_index = QUEX_LABEL(311); target_state_else_index = QUEX_LABEL(172);

    goto _552;


    __quex_assert_no_passage();
_314:
    /* (RELOAD_FORWARD from 989)  */
    target_state_index = QUEX_LABEL(313); target_state_else_index = QUEX_LABEL(191);

    goto _552;


    __quex_assert_no_passage();
_316:
    /* (RELOAD_FORWARD from 990)  */
    target_state_index = QUEX_LABEL(315); target_state_else_index = QUEX_LABEL(184);

    goto _552;


    __quex_assert_no_passage();
_318:
    /* (RELOAD_FORWARD from 991)  */
    target_state_index = QUEX_LABEL(317); target_state_else_index = QUEX_LABEL(170);

    goto _552;


    __quex_assert_no_passage();
_320:
    /* (RELOAD_FORWARD from 992)  */
    target_state_index = QUEX_LABEL(319); target_state_else_index = QUEX_LABEL(170);

    goto _552;


    __quex_assert_no_passage();
_322:
    /* (RELOAD_FORWARD from 994)  */
    target_state_index = QUEX_LABEL(321); target_state_else_index = QUEX_LABEL(170);

    goto _552;


    __quex_assert_no_passage();
_324:
    /* (RELOAD_FORWARD from 995)  */
    target_state_index = QUEX_LABEL(323); target_state_else_index = QUEX_LABEL(170);

    goto _552;


    __quex_assert_no_passage();
_326:
    /* (RELOAD_FORWARD from 996)  */
    target_state_index = QUEX_LABEL(325); target_state_else_index = QUEX_LABEL(170);

    goto _552;


    __quex_assert_no_passage();
_328:
    /* (RELOAD_FORWARD from 997)  */
    target_state_index = QUEX_LABEL(327); target_state_else_index = QUEX_LABEL(170);

    goto _552;


    __quex_assert_no_passage();
_330:
    /* (RELOAD_FORWARD from 998)  */
    target_state_index = QUEX_LABEL(329); target_state_else_index = QUEX_LABEL(170);

    goto _552;


    __quex_assert_no_passage();
_332:
    /* (RELOAD_FORWARD from 999)  */
    target_state_index = QUEX_LABEL(331); target_state_else_index = QUEX_LABEL(170);

    goto _552;


    __quex_assert_no_passage();
_334:
    /* (RELOAD_FORWARD from 1000)  */
    target_state_index = QUEX_LABEL(333); target_state_else_index = QUEX_LABEL(170);

    goto _552;


    __quex_assert_no_passage();
_336:
    /* (RELOAD_FORWARD from 1001)  */
    target_state_index = QUEX_LABEL(335); target_state_else_index = QUEX_LABEL(170);

    goto _552;


    __quex_assert_no_passage();
_338:
    /* (RELOAD_FORWARD from 1002)  */
    target_state_index = QUEX_LABEL(337); target_state_else_index = QUEX_LABEL(170);

    goto _552;


    __quex_assert_no_passage();
_340:
    /* (RELOAD_FORWARD from 1004)  */
    target_state_index = QUEX_LABEL(339); target_state_else_index = QUEX_LABEL(170);

    goto _552;


    __quex_assert_no_passage();
_342:
    /* (RELOAD_FORWARD from 1005)  */
    target_state_index = QUEX_LABEL(341); target_state_else_index = QUEX_LABEL(170);

    goto _552;


    __quex_assert_no_passage();
_344:
    /* (RELOAD_FORWARD from 1006)  */
    target_state_index = QUEX_LABEL(343); target_state_else_index = QUEX_LABEL(170);

    goto _552;

_554:
/* RETURN -- after executing 'on_after_match' code. */
    __QUEX_PURE_RETURN;


_555:
/* CONTINUE -- after executing 'on_after_match' code. */

_19:
/* CONTINUE -- without executing 'on_after_match' (e.g. on FAILURE). */


    /* Mode change = another function takes over the analysis.
     * => After mode change the analyzer function needs to be quit!
     * ASSERT: 'CONTINUE' after mode change is not allowed.                   */
    __quex_assert(   me->DEBUG_analyzer_function_at_entry 
                  == me->current_analyzer_function);


    if( QUEX_NAME(TokenQueue_is_full)(&self._token_queue) ) {
        return;
    }


goto _556;

    __quex_assert_no_passage();

    /* Following labels are referenced in macros. It cannot be detected
     * whether the macros are applied in user code or not. To avoid compiler.
     * warnings of unused labels, they are referenced in unreachable code.   */
    goto _554; /* in RETURN                */
    goto _555; /* in CONTINUE              */
    goto _19; /* in CONTINUE and skippers */
#   if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
    goto _557; /* in QUEX_GOTO_STATE       */
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
#   undef MAIN
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


