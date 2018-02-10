
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

    /* (848 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_14:
    __quex_debug("Init State\n");
    __quex_debug_state(848);
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
    /* (848 from 852)  */
    goto _14;


    __quex_assert_no_passage();
_8:
    /* (DROP_OUT from 851)  */
    goto _13;
_15:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_6:
    /* (DROP_OUT from 849)  */
    goto _11;


    __quex_assert_no_passage();
_7:
    /* (DROP_OUT from 850)  */
    goto _12;


    __quex_assert_no_passage();
_5:
    /* (DROP_OUT from 848)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _16;
    goto _15;


    __quex_assert_no_passage();
_2:
    /* (849 from 848)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(849);
goto _6;


    __quex_assert_no_passage();
_3:
    /* (850 from 848)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(850);
goto _7;


    __quex_assert_no_passage();
_4:
    /* (851 from 848)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(851);
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
    __quex_debug("* TERMINAL <LOOP 229>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_12:
    __quex_debug("* TERMINAL <LOOP 230>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_13:
    __quex_debug("* TERMINAL <LOOP 231>\n");
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
#define   CONTINUE do { goto _485; } while(0)

#ifdef    RETURN
#   undef RETURN
#endif
#define   RETURN   do { goto _484; } while(0)

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
#   define QUEX_LABEL_STATE_ROUTER _487

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
_486:
    me->buffer._lexeme_start_p = me->buffer._read_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);
_87:
    /* (773 from BEFORE_ENTRY) (773 from RELOAD_FORWARD)  */

    input = *(me->buffer._read_p);


    __quex_debug("Init State\n");
    __quex_debug_state(773);
switch( input ) {
case 0x0: goto _187;
case 0x1: goto _161;
case 0x9: goto _99;
case 0xA: goto _98;
case 0xD: 
case 0x20: goto _102;
case 0x21: goto _105;
case 0x22: goto _110;
case 0x23: goto _103;
case 0x2B: goto _89;
case 0x2D: goto _97;
case 0x2E: goto _88;
case 0x30: goto _108;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _101;
case 0x3C: goto _100;
case 0x3D: goto _94;
case 0x3E: goto _106;
case 0x62: goto _107;
case 0x63: goto _96;
case 0x64: goto _92;
case 0x65: goto _93;
case 0x69: goto _109;
case 0x6B: goto _107;
case 0x74: goto _104;
case 0x7B: goto _90;
case 0x7D: goto _91;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _95;
}


    __quex_assert_no_passage();
_161:
    /* (DROP_OUT from 807) (DROP_OUT from 810) (DROP_OUT from 804) (DROP_OUT from 773) (DROP_OUT from 801) (DROP_OUT from 799) (DROP_OUT from 796) (DROP_OUT from 811) (DROP_OUT from 805) (DROP_OUT from 808) (DROP_OUT from 802) (DROP_OUT from 797) (DROP_OUT from 806) (DROP_OUT from 809) (DROP_OUT from 803) (DROP_OUT from 800)  */

        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _86;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_162:
    /* (DROP_OUT from 795) (DROP_OUT from 841) (DROP_OUT from 782) (DROP_OUT from 779) (DROP_OUT from 832) (DROP_OUT from 830) (DROP_OUT from 845) (DROP_OUT from 827) (DROP_OUT from 814) (DROP_OUT from 842) (DROP_OUT from 783) (DROP_OUT from 790) (DROP_OUT from 793) (DROP_OUT from 774) (DROP_OUT from 828) (DROP_OUT from 815) (DROP_OUT from 822) (DROP_OUT from 791) (DROP_OUT from 837) (DROP_OUT from 819) (DROP_OUT from 840) (DROP_OUT from 781) (DROP_OUT from 775) (DROP_OUT from 778) (DROP_OUT from 829) (DROP_OUT from 844) (DROP_OUT from 820)  */
    goto _82;


    __quex_assert_no_passage();
_163:
    /* (DROP_OUT from 776)  */
    goto _69;


    __quex_assert_no_passage();
_164:
    /* (DROP_OUT from 777)  */
    goto _70;


    __quex_assert_no_passage();
_165:
    /* (DROP_OUT from 780)  */
    goto _64;


    __quex_assert_no_passage();
_166:
    /* (DROP_OUT from 784)  */
    goto _41;


    __quex_assert_no_passage();
_167:
    /* (DROP_OUT from 785)  */
    goto _42;


    __quex_assert_no_passage();
_168:
    /* (DROP_OUT from 786)  */
    goto _66;


    __quex_assert_no_passage();
_169:
    /* (DROP_OUT from 824) (DROP_OUT from 787) (DROP_OUT from 825) (DROP_OUT from 794) (DROP_OUT from 823)  */
    goto _75;


    __quex_assert_no_passage();
_170:
    /* (DROP_OUT from 788)  */
    goto _43;


    __quex_assert_no_passage();
_171:
    /* (DROP_OUT from 789)  */
    goto _61;


    __quex_assert_no_passage();
_172:
    /* (DROP_OUT from 792)  */
    goto _68;


    __quex_assert_no_passage();
_173:
    /* (DROP_OUT from 798)  */
    goto _79;


    __quex_assert_no_passage();
_174:
    /* (DROP_OUT from 812)  */
    goto _78;


    __quex_assert_no_passage();
_175:
    /* (DROP_OUT from 813)  */
    goto _71;


    __quex_assert_no_passage();
_176:
    /* (DROP_OUT from 816)  */
    goto _81;


    __quex_assert_no_passage();
_177:
    /* (DROP_OUT from 817)  */
    goto _67;


    __quex_assert_no_passage();
_178:
    /* (DROP_OUT from 818)  */
    goto _63;


    __quex_assert_no_passage();
_179:
    /* (DROP_OUT from 821)  */
    goto _73;


    __quex_assert_no_passage();
_180:
    /* (DROP_OUT from 835) (DROP_OUT from 834) (DROP_OUT from 826)  */
    goto _76;


    __quex_assert_no_passage();
_181:
    /* (DROP_OUT from 833) (DROP_OUT from 831)  */
    goto _77;


    __quex_assert_no_passage();
_182:
    /* (DROP_OUT from 836)  */
    goto _65;


    __quex_assert_no_passage();
_183:
    /* (DROP_OUT from 838)  */
    goto _80;


    __quex_assert_no_passage();
_184:
    /* (DROP_OUT from 839)  */
    goto _62;


    __quex_assert_no_passage();
_185:
    /* (DROP_OUT from 843)  */
    goto _72;


    __quex_assert_no_passage();
_186:
    /* (DROP_OUT from 846)  */
    goto _74;


    __quex_assert_no_passage();
_88:
    /* (774 from 794) (774 from 773) (774 from 775) (774 from 783)  */

    ++(me->buffer._read_p);

_316:
    input = *(me->buffer._read_p);


    __quex_debug_state(774);
switch( input ) {
case 0x0: goto _189;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _162;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _149;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_188:
    /* (774 from RELOAD_FORWARD)  */
    goto _316;


    __quex_assert_no_passage();
_89:
    /* (775 from 773)  */
    ++(me->buffer._read_p);

_318:
    input = *(me->buffer._read_p);


    __quex_debug_state(775);
switch( input ) {
case 0x0: goto _191;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _162;
case 0x2E: goto _88;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _108;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_190:
    /* (775 from RELOAD_FORWARD)  */
    goto _318;


    __quex_assert_no_passage();
_90:
    /* (776 from 773)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(776);
goto _163;


    __quex_assert_no_passage();
_91:
    /* (777 from 773)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(777);
goto _164;


    __quex_assert_no_passage();
_92:
    /* (778 from 773)  */
    ++(me->buffer._read_p);

_322:
    input = *(me->buffer._read_p);


    __quex_debug_state(778);
switch( input ) {
case 0x0: goto _193;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x5F: goto _128;
case 0x6F: goto _160;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_192:
    /* (778 from RELOAD_FORWARD)  */
    goto _322;


    __quex_assert_no_passage();
_194:
    /* (779 from RELOAD_FORWARD)  */
_324:
    input = *(me->buffer._read_p);


    __quex_debug_state(779);
switch( input ) {
case 0x0: goto _195;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x5F: goto _128;
case 0x6C: goto _154;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_93:
    /* (779 from 773)  */
    ++(me->buffer._read_p);

    goto _324;


    __quex_assert_no_passage();
_196:
    /* (780 from RELOAD_FORWARD)  */
_326:
    input = *(me->buffer._read_p);


    __quex_debug_state(780);
if     ( input == 0x3D )  goto _153;
else if( input == 0x0 )   goto _197;
else                      goto _165;


    __quex_assert_no_passage();
_94:
    /* (780 from 773)  */
    ++(me->buffer._read_p);

    goto _326;


    __quex_assert_no_passage();
_95:
    /* (781 from 830) (781 from 779) (781 from 820) (781 from 838) (781 from 782) (781 from 823) (781 from 841) (781 from 795) (781 from 813) (781 from 826) (781 from 844) (781 from 775) (781 from 816) (781 from 834) (781 from 829) (781 from 778) (781 from 819) (781 from 837) (781 from 791) (781 from 781) (781 from 822) (781 from 840) (781 from 794) (781 from 825) (781 from 843) (781 from 774) (781 from 815) (781 from 833) (781 from 787) (781 from 828) (781 from 846) (781 from 790) (781 from 831) (781 from 821) (781 from 793) (781 from 783) (781 from 824) (781 from 842) (781 from 773) (781 from 814) (781 from 832) (781 from 827) (781 from 845) (781 from 835)  */

    ++(me->buffer._read_p);

_329:
    input = *(me->buffer._read_p);


    __quex_debug_state(781);
switch( input ) {
case 0x0: goto _199;
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
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_198:
    /* (781 from RELOAD_FORWARD)  */
    goto _329;


    __quex_assert_no_passage();
_200:
    /* (782 from RELOAD_FORWARD)  */
_331:
    input = *(me->buffer._read_p);


    __quex_debug_state(782);
switch( input ) {
case 0x0: goto _201;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x5F: goto _151;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_96:
    /* (782 from 773)  */
    ++(me->buffer._read_p);

    goto _331;


    __quex_assert_no_passage();
_202:
    /* (783 from RELOAD_FORWARD)  */
_333:
    input = *(me->buffer._read_p);


    __quex_debug_state(783);
switch( input ) {
case 0x0: goto _203;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _162;
case 0x2E: goto _88;
case 0x30: goto _108;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _101;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_97:
    /* (783 from 773)  */
    ++(me->buffer._read_p);

    goto _333;


    __quex_assert_no_passage();
_98:
    /* (784 from 773)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(784);
goto _166;


    __quex_assert_no_passage();
_99:
    /* (785 from 773)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(785);
goto _167;


    __quex_assert_no_passage();
_204:
    /* (786 from RELOAD_FORWARD)  */
_337:
    input = *(me->buffer._read_p);


    __quex_debug_state(786);
if     ( input == 0x3D )  goto _150;
else if( input == 0x0 )   goto _205;
else                      goto _168;


    __quex_assert_no_passage();
_100:
    /* (786 from 773)  */
    ++(me->buffer._read_p);

    goto _337;


    __quex_assert_no_passage();
_101:
    /* (787 from 783) (787 from 773)  */

    ++(me->buffer._read_p);

_340:
    input = *(me->buffer._read_p);


    __quex_debug_state(787);
switch( input ) {
case 0x0: goto _207;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _169;
case 0x2E: goto _136;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _137;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _169;
default: goto _95;
}


    __quex_assert_no_passage();
_206:
    /* (787 from RELOAD_FORWARD)  */
    goto _340;


    __quex_assert_no_passage();
_102:
    /* (788 from 773)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(788);
goto _170;


    __quex_assert_no_passage();
_103:
    /* (789 from 773)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(789);
goto _171;


    __quex_assert_no_passage();
_208:
    /* (790 from RELOAD_FORWARD)  */
_344:
    input = *(me->buffer._read_p);


    __quex_debug_state(790);
switch( input ) {
case 0x0: goto _209;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x68: goto _133;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_104:
    /* (790 from 773)  */
    ++(me->buffer._read_p);

    goto _344;


    __quex_assert_no_passage();
_210:
    /* (791 from RELOAD_FORWARD)  */
_346:
    input = *(me->buffer._read_p);


    __quex_debug_state(791);
switch( input ) {
case 0x0: goto _211;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: goto _162;
case 0x3D: goto _132;
case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_105:
    /* (791 from 773)  */
    ++(me->buffer._read_p);

    goto _346;


    __quex_assert_no_passage();
_106:
    /* (792 from 773)  */
    ++(me->buffer._read_p);

_348:
    input = *(me->buffer._read_p);


    __quex_debug_state(792);
if     ( input == 0x3D )  goto _131;
else if( input == 0x0 )   goto _213;
else                      goto _172;


    __quex_assert_no_passage();
_212:
    /* (792 from RELOAD_FORWARD)  */
    goto _348;


    __quex_assert_no_passage();
_107:
    /* (793 from 773)  */
    ++(me->buffer._read_p);

_350:
    input = *(me->buffer._read_p);


    __quex_debug_state(793);
switch( input ) {
case 0x0: goto _215;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x5F: goto _128;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_214:
    /* (793 from RELOAD_FORWARD)  */
    goto _350;


    __quex_assert_no_passage();
_108:
    /* (794 from 775) (794 from 773) (794 from 825) (794 from 783) (794 from 794)  */

    ++(me->buffer._read_p);

_353:
    input = *(me->buffer._read_p);


    __quex_debug_state(794);
switch( input ) {
case 0x0: goto _217;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _169;
case 0x2E: goto _88;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _108;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _169;
default: goto _95;
}


    __quex_assert_no_passage();
_216:
    /* (794 from RELOAD_FORWARD)  */
    goto _353;


    __quex_assert_no_passage();
_218:
    /* (795 from RELOAD_FORWARD)  */
_355:
    input = *(me->buffer._read_p);


    __quex_debug_state(795);
switch( input ) {
case 0x0: goto _219;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x66: goto _127;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_109:
    /* (795 from 773)  */
    ++(me->buffer._read_p);

    goto _355;


    __quex_assert_no_passage();
_220:
    /* (796 from RELOAD_FORWARD)  */
_357:
    input = *(me->buffer._read_p);


    __quex_debug_state(796);
switch( input ) {
case 0x0: goto _221;
case 0x1: 
case 0xA: 
case 0xD: goto _161;
case 0x22: goto _112;
case 0x2D: goto _113;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _114;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _111;
}


    __quex_assert_no_passage();
_110:
    /* (796 from 773)  */
    ++(me->buffer._read_p);

    goto _357;


    __quex_assert_no_passage();
_111:
    /* (797 from 796) (797 from 805) (797 from 800) (797 from 809) (797 from 804) (797 from 799) (797 from 808) (797 from 803) (797 from 807) (797 from 802) (797 from 811) (797 from 797) (797 from 806) (797 from 801) (797 from 810)  */

    ++(me->buffer._read_p);

_360:
    input = *(me->buffer._read_p);


    __quex_debug_state(797);
switch( input ) {
case 0x0: goto _223;
case 0x1: 
case 0xA: 
case 0xD: goto _161;
case 0x22: goto _112;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _111;
}


    __quex_assert_no_passage();
_222:
    /* (797 from RELOAD_FORWARD)  */
    goto _360;


    __quex_assert_no_passage();
_112:
    /* (798 from 801) (798 from 797) (798 from 806) (798 from 802) (798 from 807) (798 from 808) (798 from 803) (798 from 804) (798 from 799) (798 from 809) (798 from 800) (798 from 805) (798 from 796)  */

    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(798);
goto _173;


    __quex_assert_no_passage();
_113:
    /* (799 from 796)  */
    ++(me->buffer._read_p);

_364:
    input = *(me->buffer._read_p);


    __quex_debug_state(799);
switch( input ) {
case 0x0: goto _225;
case 0x1: 
case 0xA: 
case 0xD: goto _161;
case 0x22: goto _112;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _114;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _111;
}


    __quex_assert_no_passage();
_224:
    /* (799 from RELOAD_FORWARD)  */
    goto _364;


    __quex_assert_no_passage();
_114:
    /* (800 from 799) (800 from 796)  */

    ++(me->buffer._read_p);

_367:
    input = *(me->buffer._read_p);


    __quex_debug_state(800);
switch( input ) {
case 0x0: goto _227;
case 0x1: 
case 0xA: 
case 0xD: goto _161;
case 0x22: goto _112;
case 0x2E: goto _115;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _116;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _111;
}


    __quex_assert_no_passage();
_226:
    /* (800 from RELOAD_FORWARD)  */
    goto _367;


    __quex_assert_no_passage();
_115:
    /* (801 from 800) (801 from 802) (801 from 803) (801 from 804)  */

    ++(me->buffer._read_p);

_370:
    input = *(me->buffer._read_p);


    __quex_debug_state(801);
switch( input ) {
case 0x0: goto _229;
case 0x1: 
case 0xA: 
case 0xD: goto _161;
case 0x22: goto _112;
case 0x2D: goto _119;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _120;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _111;
}


    __quex_assert_no_passage();
_228:
    /* (801 from RELOAD_FORWARD)  */
    goto _370;


    __quex_assert_no_passage();
_116:
    /* (802 from 800)  */
    ++(me->buffer._read_p);

_372:
    input = *(me->buffer._read_p);


    __quex_debug_state(802);
switch( input ) {
case 0x0: goto _231;
case 0x1: 
case 0xA: 
case 0xD: goto _161;
case 0x22: goto _112;
case 0x2E: goto _115;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _117;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _111;
}


    __quex_assert_no_passage();
_230:
    /* (802 from RELOAD_FORWARD)  */
    goto _372;


    __quex_assert_no_passage();
_232:
    /* (803 from RELOAD_FORWARD)  */
_374:
    input = *(me->buffer._read_p);


    __quex_debug_state(803);
switch( input ) {
case 0x0: goto _233;
case 0x1: 
case 0xA: 
case 0xD: goto _161;
case 0x22: goto _112;
case 0x2E: goto _115;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _118;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _111;
}


    __quex_assert_no_passage();
_117:
    /* (803 from 802)  */
    ++(me->buffer._read_p);

    goto _374;


    __quex_assert_no_passage();
_234:
    /* (804 from RELOAD_FORWARD)  */
_376:
    input = *(me->buffer._read_p);


    __quex_debug_state(804);
switch( input ) {
case 0x0: goto _235;
case 0x1: 
case 0xA: 
case 0xD: goto _161;
case 0x22: goto _112;
case 0x2E: goto _115;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _111;
}


    __quex_assert_no_passage();
_118:
    /* (804 from 803)  */
    ++(me->buffer._read_p);

    goto _376;


    __quex_assert_no_passage();
_119:
    /* (805 from 801)  */
    ++(me->buffer._read_p);

_378:
    input = *(me->buffer._read_p);


    __quex_debug_state(805);
switch( input ) {
case 0x0: goto _237;
case 0x1: 
case 0xA: 
case 0xD: goto _161;
case 0x22: goto _112;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _120;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _111;
}


    __quex_assert_no_passage();
_236:
    /* (805 from RELOAD_FORWARD)  */
    goto _378;


    __quex_assert_no_passage();
_120:
    /* (806 from 801) (806 from 805)  */

    ++(me->buffer._read_p);

_381:
    input = *(me->buffer._read_p);


    __quex_debug_state(806);
switch( input ) {
case 0x0: goto _239;
case 0x1: 
case 0xA: 
case 0xD: goto _161;
case 0x22: goto _112;
case 0x2E: goto _122;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _121;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _111;
}


    __quex_assert_no_passage();
_238:
    /* (806 from RELOAD_FORWARD)  */
    goto _381;


    __quex_assert_no_passage();
_121:
    /* (807 from 806)  */
    ++(me->buffer._read_p);

_383:
    input = *(me->buffer._read_p);


    __quex_debug_state(807);
switch( input ) {
case 0x0: goto _241;
case 0x1: 
case 0xA: 
case 0xD: goto _161;
case 0x22: goto _112;
case 0x2E: goto _122;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _111;
}


    __quex_assert_no_passage();
_240:
    /* (807 from RELOAD_FORWARD)  */
    goto _383;


    __quex_assert_no_passage();
_122:
    /* (808 from 807) (808 from 806)  */

    ++(me->buffer._read_p);

_386:
    input = *(me->buffer._read_p);


    __quex_debug_state(808);
switch( input ) {
case 0x0: goto _243;
case 0x1: 
case 0xA: 
case 0xD: goto _161;
case 0x22: goto _112;
case 0x2D: goto _123;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _124;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _111;
}


    __quex_assert_no_passage();
_242:
    /* (808 from RELOAD_FORWARD)  */
    goto _386;


    __quex_assert_no_passage();
_123:
    /* (809 from 808)  */
    ++(me->buffer._read_p);

_388:
    input = *(me->buffer._read_p);


    __quex_debug_state(809);
switch( input ) {
case 0x0: goto _245;
case 0x1: 
case 0xA: 
case 0xD: goto _161;
case 0x22: goto _112;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _124;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _111;
}


    __quex_assert_no_passage();
_244:
    /* (809 from RELOAD_FORWARD)  */
    goto _388;


    __quex_assert_no_passage();
_124:
    /* (810 from 809) (810 from 808)  */

    ++(me->buffer._read_p);

_391:
    input = *(me->buffer._read_p);


    __quex_debug_state(810);
switch( input ) {
case 0x0: goto _247;
case 0x1: 
case 0xA: 
case 0xD: goto _161;
case 0x22: goto _126;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _125;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _111;
}


    __quex_assert_no_passage();
_246:
    /* (810 from RELOAD_FORWARD)  */
    goto _391;


    __quex_assert_no_passage();
_248:
    /* (811 from RELOAD_FORWARD)  */
_393:
    input = *(me->buffer._read_p);


    __quex_debug_state(811);
switch( input ) {
case 0x0: goto _249;
case 0x1: 
case 0xA: 
case 0xD: goto _161;
case 0x22: goto _126;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _161;
default: goto _111;
}


    __quex_assert_no_passage();
_125:
    /* (811 from 810)  */
    ++(me->buffer._read_p);

    goto _393;


    __quex_assert_no_passage();
_126:
    /* (812 from 811) (812 from 810)  */

    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(812);
goto _174;


    __quex_assert_no_passage();
_127:
    /* (813 from 795)  */
    ++(me->buffer._read_p);

_397:
    input = *(me->buffer._read_p);


    __quex_debug_state(813);
switch( input ) {
case 0x0: goto _251;
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
case 0x9D: goto _175;
default: goto _95;
}


    __quex_assert_no_passage();
_250:
    /* (813 from RELOAD_FORWARD)  */
    goto _397;


    __quex_assert_no_passage();
_128:
    /* (814 from 793) (814 from 779) (814 from 778)  */

    ++(me->buffer._read_p);

_400:
    input = *(me->buffer._read_p);


    __quex_debug_state(814);
switch( input ) {
case 0x0: goto _253;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _129;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_252:
    /* (814 from RELOAD_FORWARD)  */
    goto _400;


    __quex_assert_no_passage();
_129:
    /* (815 from 814) (815 from 837)  */

    ++(me->buffer._read_p);

_403:
    input = *(me->buffer._read_p);


    __quex_debug_state(815);
switch( input ) {
case 0x0: goto _255;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _162;
case 0x2D: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _130;
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _130;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_254:
    /* (815 from RELOAD_FORWARD)  */
    goto _403;


    __quex_assert_no_passage();
_130:
    /* (816 from 816) (816 from 815)  */

    ++(me->buffer._read_p);

_406:
    input = *(me->buffer._read_p);


    __quex_debug_state(816);
switch( input ) {
case 0x0: goto _257;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _176;
case 0x2D: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _130;
case 0x3C: case 0x3D: case 0x3E: goto _176;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _130;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _176;
default: goto _95;
}


    __quex_assert_no_passage();
_256:
    /* (816 from RELOAD_FORWARD)  */
    goto _406;


    __quex_assert_no_passage();
_131:
    /* (817 from 792)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(817);
goto _177;


    __quex_assert_no_passage();
_132:
    /* (818 from 791)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(818);
goto _178;


    __quex_assert_no_passage();
_258:
    /* (819 from RELOAD_FORWARD)  */
_410:
    input = *(me->buffer._read_p);


    __quex_debug_state(819);
switch( input ) {
case 0x0: goto _259;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x65: goto _134;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_133:
    /* (819 from 790)  */
    ++(me->buffer._read_p);

    goto _410;


    __quex_assert_no_passage();
_260:
    /* (820 from RELOAD_FORWARD)  */
_412:
    input = *(me->buffer._read_p);


    __quex_debug_state(820);
switch( input ) {
case 0x0: goto _261;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x6E: goto _135;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_134:
    /* (820 from 819)  */
    ++(me->buffer._read_p);

    goto _412;


    __quex_assert_no_passage();
_135:
    /* (821 from 820)  */
    ++(me->buffer._read_p);

_414:
    input = *(me->buffer._read_p);


    __quex_debug_state(821);
switch( input ) {
case 0x0: goto _263;
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
case 0x9D: goto _179;
default: goto _95;
}


    __quex_assert_no_passage();
_262:
    /* (821 from RELOAD_FORWARD)  */
    goto _414;


    __quex_assert_no_passage();
_136:
    /* (822 from 825) (822 from 824) (822 from 787) (822 from 823)  */

    ++(me->buffer._read_p);

_417:
    input = *(me->buffer._read_p);


    __quex_debug_state(822);
switch( input ) {
case 0x0: goto _265;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _162;
case 0x2D: goto _141;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _140;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_264:
    /* (822 from RELOAD_FORWARD)  */
    goto _417;


    __quex_assert_no_passage();
_266:
    /* (823 from RELOAD_FORWARD)  */
_419:
    input = *(me->buffer._read_p);


    __quex_debug_state(823);
switch( input ) {
case 0x0: goto _267;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _169;
case 0x2E: goto _136;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _138;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _169;
default: goto _95;
}


    __quex_assert_no_passage();
_137:
    /* (823 from 787)  */
    ++(me->buffer._read_p);

    goto _419;


    __quex_assert_no_passage();
_138:
    /* (824 from 823)  */
    ++(me->buffer._read_p);

_421:
    input = *(me->buffer._read_p);


    __quex_debug_state(824);
switch( input ) {
case 0x0: goto _269;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _169;
case 0x2E: goto _136;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _139;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _169;
default: goto _95;
}


    __quex_assert_no_passage();
_268:
    /* (824 from RELOAD_FORWARD)  */
    goto _421;


    __quex_assert_no_passage();
_139:
    /* (825 from 824)  */
    ++(me->buffer._read_p);

_423:
    input = *(me->buffer._read_p);


    __quex_debug_state(825);
switch( input ) {
case 0x0: goto _271;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _169;
case 0x2E: goto _136;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _108;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _169;
default: goto _95;
}


    __quex_assert_no_passage();
_270:
    /* (825 from RELOAD_FORWARD)  */
    goto _423;


    __quex_assert_no_passage();
_140:
    /* (826 from 822)  */
    ++(me->buffer._read_p);

_425:
    input = *(me->buffer._read_p);


    __quex_debug_state(826);
switch( input ) {
case 0x0: goto _273;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _180;
case 0x2E: goto _144;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _148;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _180;
default: goto _95;
}


    __quex_assert_no_passage();
_272:
    /* (826 from RELOAD_FORWARD)  */
    goto _425;


    __quex_assert_no_passage();
_274:
    /* (827 from RELOAD_FORWARD)  */
_427:
    input = *(me->buffer._read_p);


    __quex_debug_state(827);
switch( input ) {
case 0x0: goto _275;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _162;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _142;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_141:
    /* (827 from 822)  */
    ++(me->buffer._read_p);

    goto _427;


    __quex_assert_no_passage();
_276:
    /* (828 from RELOAD_FORWARD)  */
_429:
    input = *(me->buffer._read_p);


    __quex_debug_state(828);
switch( input ) {
case 0x0: goto _277;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _162;
case 0x2E: goto _144;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _143;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_142:
    /* (828 from 827)  */
    ++(me->buffer._read_p);

    goto _429;


    __quex_assert_no_passage();
_143:
    /* (829 from 828)  */
    ++(me->buffer._read_p);

_431:
    input = *(me->buffer._read_p);


    __quex_debug_state(829);
switch( input ) {
case 0x0: goto _279;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _162;
case 0x2E: goto _144;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_278:
    /* (829 from RELOAD_FORWARD)  */
    goto _431;


    __quex_assert_no_passage();
_144:
    /* (830 from 826) (830 from 829) (830 from 828) (830 from 834)  */

    ++(me->buffer._read_p);

_434:
    input = *(me->buffer._read_p);


    __quex_debug_state(830);
switch( input ) {
case 0x0: goto _281;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _162;
case 0x2D: goto _146;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _145;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_280:
    /* (830 from RELOAD_FORWARD)  */
    goto _434;


    __quex_assert_no_passage();
_145:
    /* (831 from 830) (831 from 832)  */

    ++(me->buffer._read_p);

_437:
    input = *(me->buffer._read_p);


    __quex_debug_state(831);
switch( input ) {
case 0x0: goto _283;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _181;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _147;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _181;
default: goto _95;
}


    __quex_assert_no_passage();
_282:
    /* (831 from RELOAD_FORWARD)  */
    goto _437;


    __quex_assert_no_passage();
_146:
    /* (832 from 830)  */
    ++(me->buffer._read_p);

_439:
    input = *(me->buffer._read_p);


    __quex_debug_state(832);
switch( input ) {
case 0x0: goto _285;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _162;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _145;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_284:
    /* (832 from RELOAD_FORWARD)  */
    goto _439;


    __quex_assert_no_passage();
_147:
    /* (833 from 831)  */
    ++(me->buffer._read_p);

_441:
    input = *(me->buffer._read_p);


    __quex_debug_state(833);
switch( input ) {
case 0x0: goto _287;
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
case 0x9D: goto _181;
default: goto _95;
}


    __quex_assert_no_passage();
_286:
    /* (833 from RELOAD_FORWARD)  */
    goto _441;


    __quex_assert_no_passage();
_148:
    /* (834 from 826)  */
    ++(me->buffer._read_p);

_443:
    input = *(me->buffer._read_p);


    __quex_debug_state(834);
switch( input ) {
case 0x0: goto _289;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _180;
case 0x2E: goto _144;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _149;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _180;
default: goto _95;
}


    __quex_assert_no_passage();
_288:
    /* (834 from RELOAD_FORWARD)  */
    goto _443;


    __quex_assert_no_passage();
_149:
    /* (835 from 834) (835 from 835) (835 from 774)  */

    ++(me->buffer._read_p);

_446:
    input = *(me->buffer._read_p);


    __quex_debug_state(835);
switch( input ) {
case 0x0: goto _291;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _180;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _149;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _180;
default: goto _95;
}


    __quex_assert_no_passage();
_290:
    /* (835 from RELOAD_FORWARD)  */
    goto _446;


    __quex_assert_no_passage();
_150:
    /* (836 from 786)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(836);
goto _182;


    __quex_assert_no_passage();
_151:
    /* (837 from 782)  */
    ++(me->buffer._read_p);

_449:
    input = *(me->buffer._read_p);


    __quex_debug_state(837);
switch( input ) {
case 0x0: goto _293;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _162;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _152;
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _129;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_292:
    /* (837 from RELOAD_FORWARD)  */
    goto _449;


    __quex_assert_no_passage();
_152:
    /* (838 from 837) (838 from 838)  */

    ++(me->buffer._read_p);

_452:
    input = *(me->buffer._read_p);


    __quex_debug_state(838);
switch( input ) {
case 0x0: goto _295;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _183;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _152;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _183;
default: goto _95;
}


    __quex_assert_no_passage();
_294:
    /* (838 from RELOAD_FORWARD)  */
    goto _452;


    __quex_assert_no_passage();
_153:
    /* (839 from 780)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(839);
goto _184;


    __quex_assert_no_passage();
_296:
    /* (840 from RELOAD_FORWARD)  */
_455:
    input = *(me->buffer._read_p);


    __quex_debug_state(840);
switch( input ) {
case 0x0: goto _297;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x69: goto _156;
case 0x73: goto _155;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_154:
    /* (840 from 779)  */
    ++(me->buffer._read_p);

    goto _455;


    __quex_assert_no_passage();
_155:
    /* (841 from 840)  */
    ++(me->buffer._read_p);

_457:
    input = *(me->buffer._read_p);


    __quex_debug_state(841);
switch( input ) {
case 0x0: goto _299;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x65: goto _158;
case 0x69: goto _156;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_298:
    /* (841 from RELOAD_FORWARD)  */
    goto _457;


    __quex_assert_no_passage();
_156:
    /* (842 from 845) (842 from 841) (842 from 840)  */

    ++(me->buffer._read_p);

_460:
    input = *(me->buffer._read_p);


    __quex_debug_state(842);
switch( input ) {
case 0x0: goto _301;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x66: goto _157;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_300:
    /* (842 from RELOAD_FORWARD)  */
    goto _460;


    __quex_assert_no_passage();
_302:
    /* (843 from RELOAD_FORWARD)  */
_462:
    input = *(me->buffer._read_p);


    __quex_debug_state(843);
switch( input ) {
case 0x0: goto _303;
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
default: goto _95;
}


    __quex_assert_no_passage();
_157:
    /* (843 from 842)  */
    ++(me->buffer._read_p);

    goto _462;


    __quex_assert_no_passage();
_158:
    /* (844 from 841)  */
    ++(me->buffer._read_p);

_464:
    input = *(me->buffer._read_p);


    __quex_debug_state(844);
switch( input ) {
case 0x0: goto _305;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x5F: goto _159;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_304:
    /* (844 from RELOAD_FORWARD)  */
    goto _464;


    __quex_assert_no_passage();
_159:
    /* (845 from 844)  */
    ++(me->buffer._read_p);

_466:
    input = *(me->buffer._read_p);


    __quex_debug_state(845);
switch( input ) {
case 0x0: goto _307;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _162;
case 0x69: goto _156;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _162;
default: goto _95;
}


    __quex_assert_no_passage();
_306:
    /* (845 from RELOAD_FORWARD)  */
    goto _466;


    __quex_assert_no_passage();
_160:
    /* (846 from 778)  */
    ++(me->buffer._read_p);

_468:
    input = *(me->buffer._read_p);


    __quex_debug_state(846);
switch( input ) {
case 0x0: goto _309;
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
default: goto _95;
}


    __quex_assert_no_passage();
_308:
    /* (846 from RELOAD_FORWARD)  */
    goto _468;
_22:
    /* (476 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

_470:
__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_469:
    __quex_debug("Init State\n");
    __quex_debug_state(476);
switch( input ) {
case 0x0: goto _34;
case 0x9: goto _24;
case 0xA: goto _23;
case 0xD: 
case 0x20: goto _25;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _27;
default: goto _26;
}


    __quex_assert_no_passage();
_35:
    /* (476 from 482)  */
    goto _469;


    __quex_assert_no_passage();
_32:
    /* (476 from RELOAD_FORWARD)  */
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

    goto _470;


    __quex_assert_no_passage();
_28:
    /* (DROP_OUT from 477)  */
    goto _37;
_471:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_29:
    /* (DROP_OUT from 478)  */
    goto _38;


    __quex_assert_no_passage();
_30:
    /* (DROP_OUT from 479)  */
    goto _39;


    __quex_assert_no_passage();
_31:
    /* (DROP_OUT from 480)  */
    goto _36;


    __quex_assert_no_passage();
_27:
    /* (DROP_OUT from 476)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _86;
    goto _471;


    __quex_assert_no_passage();
_26:
    /* (480 from 476)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(480);
goto _31;


    __quex_assert_no_passage();
_23:
    /* (477 from 476)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(477);
goto _28;


    __quex_assert_no_passage();
_24:
    /* (478 from 476)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(478);
goto _29;


    __quex_assert_no_passage();
_25:
    /* (479 from 476)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(479);
goto _30;
_45:
    /* (509 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

_477:
__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_476:
    __quex_debug("Init State\n");
    __quex_debug_state(509);
switch( input ) {
case 0x0: goto _54;
case 0x9: goto _47;
case 0xA: goto _46;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _49;
default: goto _48;
}


    __quex_assert_no_passage();
_55:
    /* (509 from 513)  */
    goto _476;


    __quex_assert_no_passage();
_53:
    /* (509 from RELOAD_FORWARD)  */
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

    goto _477;


    __quex_assert_no_passage();
_49:
    /* (DROP_OUT from 509)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _86;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_50:
    /* (DROP_OUT from 510)  */
    goto _58;


    __quex_assert_no_passage();
_51:
    /* (DROP_OUT from 511)  */
    goto _59;


    __quex_assert_no_passage();
_52:
    /* (DROP_OUT from 512)  */
    goto _60;


    __quex_assert_no_passage();
_48:
    /* (512 from 509)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(512);
goto _52;


    __quex_assert_no_passage();
_46:
    /* (510 from 509)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(510);
goto _50;


    __quex_assert_no_passage();
_47:
    /* (511 from 509)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(511);
goto _51;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_83:
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
_84:
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
_85:
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
_33:
    __quex_debug("* TERMINAL END_OF_STREAM\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 78 "zck.qx"
self_send(T_TERMINATION);

__QUEX_PURE_RETURN;


#   line 3159 "Lexer.cpp"

}
    /* End of Stream FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
__QUEX_PURE_RETURN;
_86:
    __quex_debug("* TERMINAL FAILURE\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 79 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_FAILURE);

__QUEX_PURE_RETURN;


#   line 3178 "Lexer.cpp"

}
RETURN;
_40:
    __quex_debug("* TERMINAL <skip>\n");
goto _22;
_44:
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
_36:
    __quex_debug("* TERMINAL <LOOP EXIT>\n");
    --(me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _21;

_37:
    __quex_debug("* TERMINAL <LOOP 138>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _35;

_38:
    __quex_debug("* TERMINAL <LOOP 139>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _35;

_39:
    __quex_debug("* TERMINAL <LOOP 140>\n");
goto _35;

_41:
    __quex_debug("* TERMINAL ENTER SKIP:\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

goto _40;

_42:
    __quex_debug("* TERMINAL ENTER SKIP:\n");
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

goto _40;

_43:
    __quex_debug("* TERMINAL ENTER SKIP:\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)1);

goto _40;

_57:
    __quex_debug("* TERMINAL <SKIP RANGE TERMINATED>\n");
goto _21;
_56:
    __quex_debug("* TERMINAL <LOOP EXIT>\n");
    --(me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _21;

_58:
    __quex_debug("* TERMINAL <COUPLE 153>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _57;

_59:
    __quex_debug("* TERMINAL <LOOP 154>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _55;

_60:
    __quex_debug("* TERMINAL <LOOP 155>\n");
goto _55;

_61:
    __quex_debug("* TERMINAL <skip range><skip_range open>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
goto _45;
_62:
    __quex_debug("* TERMINAL \"==\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 80 "zck.qx"
self_send(T_OP_DEQ);

__QUEX_PURE_RETURN;


#   line 3308 "Lexer.cpp"

}
RETURN;
_63:
    __quex_debug("* TERMINAL \"!=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 81 "zck.qx"
self_send(T_OP_NEQ);

__QUEX_PURE_RETURN;


#   line 3324 "Lexer.cpp"

}
RETURN;
_64:
    __quex_debug("* TERMINAL \"=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 82 "zck.qx"
self_send(T_OP_EQ);

__QUEX_PURE_RETURN;


#   line 3340 "Lexer.cpp"

}
RETURN;
_65:
    __quex_debug("* TERMINAL \"<=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 83 "zck.qx"
self_send(T_OP_LTEQ);

__QUEX_PURE_RETURN;


#   line 3356 "Lexer.cpp"

}
RETURN;
_66:
    __quex_debug("* TERMINAL \"<\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 84 "zck.qx"
self_send(T_OP_LT);

__QUEX_PURE_RETURN;


#   line 3372 "Lexer.cpp"

}
RETURN;
_67:
    __quex_debug("* TERMINAL \">=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 85 "zck.qx"
self_send(T_OP_GTEQ);

__QUEX_PURE_RETURN;


#   line 3388 "Lexer.cpp"

}
RETURN;
_68:
    __quex_debug("* TERMINAL \">\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 86 "zck.qx"
self_send(T_OP_GT);

__QUEX_PURE_RETURN;


#   line 3404 "Lexer.cpp"

}
RETURN;
_69:
    __quex_debug("* TERMINAL \"{\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 87 "zck.qx"
self_send(T_L_BRACE);

__QUEX_PURE_RETURN;


#   line 3420 "Lexer.cpp"

}
RETURN;
_70:
    __quex_debug("* TERMINAL \"}\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 88 "zck.qx"
self_send(T_R_BRACE);

__QUEX_PURE_RETURN;


#   line 3436 "Lexer.cpp"

}
RETURN;
_71:
    __quex_debug("* TERMINAL \"if\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 89 "zck.qx"
self_send(T_IF);

__QUEX_PURE_RETURN;


#   line 3452 "Lexer.cpp"

}
RETURN;
_72:
    __quex_debug("* TERMINAL {ELSIF}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 90 "zck.qx"
self_send(T_ELSIF);

__QUEX_PURE_RETURN;


#   line 3468 "Lexer.cpp"

}
RETURN;
_73:
    __quex_debug("* TERMINAL \"then\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(4);
{

#   line 91 "zck.qx"
self_send(T_THEN);

__QUEX_PURE_RETURN;


#   line 3484 "Lexer.cpp"

}
RETURN;
_74:
    __quex_debug("* TERMINAL \"do\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 92 "zck.qx"
self_send(T_DO);

__QUEX_PURE_RETURN;


#   line 3500 "Lexer.cpp"

}
RETURN;
_75:
    __quex_debug("* TERMINAL {SIGN}[0-9]+\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 93 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_INTEGER);

__QUEX_PURE_RETURN;


#   line 3517 "Lexer.cpp"

}
RETURN;
_76:
    __quex_debug("* TERMINAL {DECIMAL}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 94 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_DECIMAL);

__QUEX_PURE_RETURN;


#   line 3534 "Lexer.cpp"

}
RETURN;
_77:
    __quex_debug("* TERMINAL {DATE}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 95 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_DATE);

__QUEX_PURE_RETURN;


#   line 3551 "Lexer.cpp"

}
RETURN;
_78:
    __quex_debug("* TERMINAL \"\\\"\"{DATE}\"\\\"\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 96 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), LexemeBegin+1, LexemeEnd-1);
self_send(T_QDATE);

__QUEX_PURE_RETURN;


#   line 3568 "Lexer.cpp"

}
RETURN;
_79:
    __quex_debug("* TERMINAL {QSTRING}\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 97 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), LexemeBegin+1, LexemeEnd-1);
self_send(T_QSTRING);

__QUEX_PURE_RETURN;


#   line 3584 "Lexer.cpp"

}
RETURN;
_80:
    __quex_debug("* TERMINAL {CHAR_ID}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 98 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_CHAR_SCOPE);

__QUEX_PURE_RETURN;


#   line 3601 "Lexer.cpp"

}
RETURN;
_81:
    __quex_debug("* TERMINAL {TITLE_ID}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 99 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_TITLE_ID);

__QUEX_PURE_RETURN;


#   line 3618 "Lexer.cpp"

}
RETURN;
_82:
    __quex_debug("* TERMINAL {STRING}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 100 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_STRING);

__QUEX_PURE_RETURN;


#   line 3635 "Lexer.cpp"

}
RETURN;
if(0) {
    /* Avoid unreferenced labels. */
    goto _83;
    goto _84;
    goto _85;
    goto _33;
    goto _86;
    goto _40;
    goto _44;
    goto _36;
    goto _37;
    goto _38;
    goto _39;
    goto _41;
    goto _42;
    goto _43;
    goto _57;
    goto _56;
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
    goto _79;
    goto _80;
    goto _81;
    goto _82;
}
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_487:
switch( target_state_index ) {
case 32: {
goto _32;}
case 33: {
goto _33;}
case 44: {
goto _44;}
case 53: {
goto _53;}
case 87: {
goto _87;}
case 161: {
goto _161;}
case 162: {
goto _162;}
case 165: {
goto _165;}
case 168: {
goto _168;}
case 169: {
goto _169;}
case 172: {
goto _172;}
case 175: {
goto _175;}
case 176: {
goto _176;}
case 179: {
goto _179;}
case 180: {
goto _180;}
case 181: {
goto _181;}
case 183: {
goto _183;}
case 185: {
goto _185;}
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
default: {
goto _308;}
}
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */


    __quex_assert_no_passage();
_54:
    /* (RELOAD_FORWARD from 509)  */
    target_state_index = QUEX_LABEL(53); target_state_else_index = QUEX_LABEL(44);

_483:
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

_482:

    __quex_debug3("RELOAD_FORWARD: success->%i; failure->%i", 
                  (int)target_state_index, (int)target_state_else_index);
    __quex_assert(*(me->buffer._read_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    
    __quex_debug_reload_before();                 
    load_result = QUEX_NAME(Buffer_load_forward)(&me->buffer, (QUEX_TYPE_LEXATOM**)position, PositionRegisterN);
    __quex_debug_reload_after(load_result);

    switch( load_result ) {
    case E_LoadResult_DONE:              QUEX_GOTO_STATE(target_state_index);      
    case E_LoadResult_BAD_LEXATOM:       goto _83;
    case E_LoadResult_FAILURE:           goto _84;
    case E_LoadResult_NO_SPACE_FOR_LOAD: goto _85;
    case E_LoadResult_NO_MORE_DATA:      QUEX_GOTO_STATE(target_state_else_index); 
    default:                             __quex_assert(false);
    }


    __quex_assert_no_passage();
_34:
    /* (RELOAD_FORWARD from 476)  */
    target_state_index = QUEX_LABEL(32); target_state_else_index = QUEX_LABEL(33);

    goto _483;


    __quex_assert_no_passage();
_187:
    /* (RELOAD_FORWARD from 773)  */
    target_state_index = QUEX_LABEL(87); target_state_else_index = QUEX_LABEL(33);

    goto _482;


    __quex_assert_no_passage();
_189:
    /* (RELOAD_FORWARD from 774)  */
    target_state_index = QUEX_LABEL(188); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_191:
    /* (RELOAD_FORWARD from 775)  */
    target_state_index = QUEX_LABEL(190); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_193:
    /* (RELOAD_FORWARD from 778)  */
    target_state_index = QUEX_LABEL(192); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_195:
    /* (RELOAD_FORWARD from 779)  */
    target_state_index = QUEX_LABEL(194); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_197:
    /* (RELOAD_FORWARD from 780)  */
    target_state_index = QUEX_LABEL(196); target_state_else_index = QUEX_LABEL(165);

    goto _482;


    __quex_assert_no_passage();
_199:
    /* (RELOAD_FORWARD from 781)  */
    target_state_index = QUEX_LABEL(198); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_201:
    /* (RELOAD_FORWARD from 782)  */
    target_state_index = QUEX_LABEL(200); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_203:
    /* (RELOAD_FORWARD from 783)  */
    target_state_index = QUEX_LABEL(202); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_205:
    /* (RELOAD_FORWARD from 786)  */
    target_state_index = QUEX_LABEL(204); target_state_else_index = QUEX_LABEL(168);

    goto _482;


    __quex_assert_no_passage();
_207:
    /* (RELOAD_FORWARD from 787)  */
    target_state_index = QUEX_LABEL(206); target_state_else_index = QUEX_LABEL(169);

    goto _482;


    __quex_assert_no_passage();
_209:
    /* (RELOAD_FORWARD from 790)  */
    target_state_index = QUEX_LABEL(208); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_211:
    /* (RELOAD_FORWARD from 791)  */
    target_state_index = QUEX_LABEL(210); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_213:
    /* (RELOAD_FORWARD from 792)  */
    target_state_index = QUEX_LABEL(212); target_state_else_index = QUEX_LABEL(172);

    goto _482;


    __quex_assert_no_passage();
_215:
    /* (RELOAD_FORWARD from 793)  */
    target_state_index = QUEX_LABEL(214); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_217:
    /* (RELOAD_FORWARD from 794)  */
    target_state_index = QUEX_LABEL(216); target_state_else_index = QUEX_LABEL(169);

    goto _482;


    __quex_assert_no_passage();
_219:
    /* (RELOAD_FORWARD from 795)  */
    target_state_index = QUEX_LABEL(218); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_221:
    /* (RELOAD_FORWARD from 796)  */
    target_state_index = QUEX_LABEL(220); target_state_else_index = QUEX_LABEL(161);

    goto _482;


    __quex_assert_no_passage();
_223:
    /* (RELOAD_FORWARD from 797)  */
    target_state_index = QUEX_LABEL(222); target_state_else_index = QUEX_LABEL(161);

    goto _482;


    __quex_assert_no_passage();
_225:
    /* (RELOAD_FORWARD from 799)  */
    target_state_index = QUEX_LABEL(224); target_state_else_index = QUEX_LABEL(161);

    goto _482;


    __quex_assert_no_passage();
_227:
    /* (RELOAD_FORWARD from 800)  */
    target_state_index = QUEX_LABEL(226); target_state_else_index = QUEX_LABEL(161);

    goto _482;


    __quex_assert_no_passage();
_229:
    /* (RELOAD_FORWARD from 801)  */
    target_state_index = QUEX_LABEL(228); target_state_else_index = QUEX_LABEL(161);

    goto _482;


    __quex_assert_no_passage();
_231:
    /* (RELOAD_FORWARD from 802)  */
    target_state_index = QUEX_LABEL(230); target_state_else_index = QUEX_LABEL(161);

    goto _482;


    __quex_assert_no_passage();
_233:
    /* (RELOAD_FORWARD from 803)  */
    target_state_index = QUEX_LABEL(232); target_state_else_index = QUEX_LABEL(161);

    goto _482;


    __quex_assert_no_passage();
_235:
    /* (RELOAD_FORWARD from 804)  */
    target_state_index = QUEX_LABEL(234); target_state_else_index = QUEX_LABEL(161);

    goto _482;


    __quex_assert_no_passage();
_237:
    /* (RELOAD_FORWARD from 805)  */
    target_state_index = QUEX_LABEL(236); target_state_else_index = QUEX_LABEL(161);

    goto _482;


    __quex_assert_no_passage();
_239:
    /* (RELOAD_FORWARD from 806)  */
    target_state_index = QUEX_LABEL(238); target_state_else_index = QUEX_LABEL(161);

    goto _482;


    __quex_assert_no_passage();
_241:
    /* (RELOAD_FORWARD from 807)  */
    target_state_index = QUEX_LABEL(240); target_state_else_index = QUEX_LABEL(161);

    goto _482;


    __quex_assert_no_passage();
_243:
    /* (RELOAD_FORWARD from 808)  */
    target_state_index = QUEX_LABEL(242); target_state_else_index = QUEX_LABEL(161);

    goto _482;


    __quex_assert_no_passage();
_245:
    /* (RELOAD_FORWARD from 809)  */
    target_state_index = QUEX_LABEL(244); target_state_else_index = QUEX_LABEL(161);

    goto _482;


    __quex_assert_no_passage();
_247:
    /* (RELOAD_FORWARD from 810)  */
    target_state_index = QUEX_LABEL(246); target_state_else_index = QUEX_LABEL(161);

    goto _482;


    __quex_assert_no_passage();
_249:
    /* (RELOAD_FORWARD from 811)  */
    target_state_index = QUEX_LABEL(248); target_state_else_index = QUEX_LABEL(161);

    goto _482;


    __quex_assert_no_passage();
_251:
    /* (RELOAD_FORWARD from 813)  */
    target_state_index = QUEX_LABEL(250); target_state_else_index = QUEX_LABEL(175);

    goto _482;


    __quex_assert_no_passage();
_253:
    /* (RELOAD_FORWARD from 814)  */
    target_state_index = QUEX_LABEL(252); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_255:
    /* (RELOAD_FORWARD from 815)  */
    target_state_index = QUEX_LABEL(254); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_257:
    /* (RELOAD_FORWARD from 816)  */
    target_state_index = QUEX_LABEL(256); target_state_else_index = QUEX_LABEL(176);

    goto _482;


    __quex_assert_no_passage();
_259:
    /* (RELOAD_FORWARD from 819)  */
    target_state_index = QUEX_LABEL(258); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_261:
    /* (RELOAD_FORWARD from 820)  */
    target_state_index = QUEX_LABEL(260); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_263:
    /* (RELOAD_FORWARD from 821)  */
    target_state_index = QUEX_LABEL(262); target_state_else_index = QUEX_LABEL(179);

    goto _482;


    __quex_assert_no_passage();
_265:
    /* (RELOAD_FORWARD from 822)  */
    target_state_index = QUEX_LABEL(264); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_267:
    /* (RELOAD_FORWARD from 823)  */
    target_state_index = QUEX_LABEL(266); target_state_else_index = QUEX_LABEL(169);

    goto _482;


    __quex_assert_no_passage();
_269:
    /* (RELOAD_FORWARD from 824)  */
    target_state_index = QUEX_LABEL(268); target_state_else_index = QUEX_LABEL(169);

    goto _482;


    __quex_assert_no_passage();
_271:
    /* (RELOAD_FORWARD from 825)  */
    target_state_index = QUEX_LABEL(270); target_state_else_index = QUEX_LABEL(169);

    goto _482;


    __quex_assert_no_passage();
_273:
    /* (RELOAD_FORWARD from 826)  */
    target_state_index = QUEX_LABEL(272); target_state_else_index = QUEX_LABEL(180);

    goto _482;


    __quex_assert_no_passage();
_275:
    /* (RELOAD_FORWARD from 827)  */
    target_state_index = QUEX_LABEL(274); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_277:
    /* (RELOAD_FORWARD from 828)  */
    target_state_index = QUEX_LABEL(276); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_279:
    /* (RELOAD_FORWARD from 829)  */
    target_state_index = QUEX_LABEL(278); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_281:
    /* (RELOAD_FORWARD from 830)  */
    target_state_index = QUEX_LABEL(280); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_283:
    /* (RELOAD_FORWARD from 831)  */
    target_state_index = QUEX_LABEL(282); target_state_else_index = QUEX_LABEL(181);

    goto _482;


    __quex_assert_no_passage();
_285:
    /* (RELOAD_FORWARD from 832)  */
    target_state_index = QUEX_LABEL(284); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_287:
    /* (RELOAD_FORWARD from 833)  */
    target_state_index = QUEX_LABEL(286); target_state_else_index = QUEX_LABEL(181);

    goto _482;


    __quex_assert_no_passage();
_289:
    /* (RELOAD_FORWARD from 834)  */
    target_state_index = QUEX_LABEL(288); target_state_else_index = QUEX_LABEL(180);

    goto _482;


    __quex_assert_no_passage();
_291:
    /* (RELOAD_FORWARD from 835)  */
    target_state_index = QUEX_LABEL(290); target_state_else_index = QUEX_LABEL(180);

    goto _482;


    __quex_assert_no_passage();
_293:
    /* (RELOAD_FORWARD from 837)  */
    target_state_index = QUEX_LABEL(292); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_295:
    /* (RELOAD_FORWARD from 838)  */
    target_state_index = QUEX_LABEL(294); target_state_else_index = QUEX_LABEL(183);

    goto _482;


    __quex_assert_no_passage();
_297:
    /* (RELOAD_FORWARD from 840)  */
    target_state_index = QUEX_LABEL(296); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_299:
    /* (RELOAD_FORWARD from 841)  */
    target_state_index = QUEX_LABEL(298); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_301:
    /* (RELOAD_FORWARD from 842)  */
    target_state_index = QUEX_LABEL(300); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_303:
    /* (RELOAD_FORWARD from 843)  */
    target_state_index = QUEX_LABEL(302); target_state_else_index = QUEX_LABEL(185);

    goto _482;


    __quex_assert_no_passage();
_305:
    /* (RELOAD_FORWARD from 844)  */
    target_state_index = QUEX_LABEL(304); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_307:
    /* (RELOAD_FORWARD from 845)  */
    target_state_index = QUEX_LABEL(306); target_state_else_index = QUEX_LABEL(162);

    goto _482;


    __quex_assert_no_passage();
_309:
    /* (RELOAD_FORWARD from 846)  */
    target_state_index = QUEX_LABEL(308); target_state_else_index = QUEX_LABEL(186);

    goto _482;

_484:
/* RETURN -- after executing 'on_after_match' code. */
    __QUEX_PURE_RETURN;


_485:
/* CONTINUE -- after executing 'on_after_match' code. */

_21:
/* CONTINUE -- without executing 'on_after_match' (e.g. on FAILURE). */


    /* Mode change = another function takes over the analysis.
     * => After mode change the analyzer function needs to be quit!
     * ASSERT: 'CONTINUE' after mode change is not allowed.                   */
    __quex_assert(   me->DEBUG_analyzer_function_at_entry 
                  == me->current_analyzer_function);


    if( QUEX_NAME(TokenQueue_is_full)(&self._token_queue) ) {
        return;
    }


goto _486;

    __quex_assert_no_passage();

    /* Following labels are referenced in macros. It cannot be detected
     * whether the macros are applied in user code or not. To avoid compiler.
     * warnings of unused labels, they are referenced in unreachable code.   */
    goto _484; /* in RETURN                */
    goto _485; /* in CONTINUE              */
    goto _21; /* in CONTINUE and skippers */
#   if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
    goto _487; /* in QUEX_GOTO_STATE       */
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


