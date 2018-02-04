
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

    /* (802 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_14:
    __quex_debug("Init State\n");
    __quex_debug_state(802);
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
    /* (802 from 806)  */
    goto _14;


    __quex_assert_no_passage();
_5:
    /* (DROP_OUT from 802)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _16;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_6:
    /* (DROP_OUT from 803)  */
    goto _11;


    __quex_assert_no_passage();
_7:
    /* (DROP_OUT from 804)  */
    goto _12;


    __quex_assert_no_passage();
_8:
    /* (DROP_OUT from 805)  */
    goto _13;


    __quex_assert_no_passage();
_2:
    /* (803 from 802)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(803);
goto _6;


    __quex_assert_no_passage();
_3:
    /* (804 from 802)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(804);
goto _7;


    __quex_assert_no_passage();
_4:
    /* (805 from 802)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(805);
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
    __quex_debug("* TERMINAL <LOOP 219>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_12:
    __quex_debug("* TERMINAL <LOOP 220>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_13:
    __quex_debug("* TERMINAL <LOOP 221>\n");
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
#define   CONTINUE do { goto _449; } while(0)

#ifdef    RETURN
#   undef RETURN
#endif
#define   RETURN   do { goto _448; } while(0)

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
#   define QUEX_LABEL_STATE_ROUTER _451

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
_450:
    me->buffer._lexeme_start_p = me->buffer._read_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);
_83:
    /* (733 from BEFORE_ENTRY) (733 from RELOAD_FORWARD)  */

    input = *(me->buffer._read_p);


    __quex_debug("Init State\n");
    __quex_debug_state(733);
switch( input ) {
case 0x0: goto _175;
case 0x1: goto _151;
case 0x9: goto _93;
case 0xA: goto _87;
case 0xD: 
case 0x20: goto _99;
case 0x21: goto _88;
case 0x22: goto _94;
case 0x23: goto _102;
case 0x2B: goto _91;
case 0x2D: goto _96;
case 0x2E: goto _97;
case 0x30: goto _104;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _84;
case 0x3C: goto _95;
case 0x3D: goto _89;
case 0x3E: goto _85;
case 0x62: goto _90;
case 0x63: goto _101;
case 0x64: goto _90;
case 0x65: goto _100;
case 0x69: goto _98;
case 0x6B: goto _90;
case 0x7B: goto _103;
case 0x7D: goto _92;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _86;
}


    __quex_assert_no_passage();
_151:
    /* (DROP_OUT from 782) (DROP_OUT from 733) (DROP_OUT from 779) (DROP_OUT from 773) (DROP_OUT from 776) (DROP_OUT from 783) (DROP_OUT from 780) (DROP_OUT from 774) (DROP_OUT from 777) (DROP_OUT from 771) (DROP_OUT from 781) (DROP_OUT from 775) (DROP_OUT from 778) (DROP_OUT from 772) (DROP_OUT from 769) (DROP_OUT from 744)  */

        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _82;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_152:
    /* (DROP_OUT from 789) (DROP_OUT from 790) (DROP_OUT from 734) (DROP_OUT from 791) (DROP_OUT from 754)  */
    goto _71;


    __quex_assert_no_passage();
_153:
    /* (DROP_OUT from 735)  */
    goto _66;


    __quex_assert_no_passage();
_154:
    /* (DROP_OUT from 795) (DROP_OUT from 738) (DROP_OUT from 764) (DROP_OUT from 751) (DROP_OUT from 761) (DROP_OUT from 748) (DROP_OUT from 755) (DROP_OUT from 796) (DROP_OUT from 765) (DROP_OUT from 793) (DROP_OUT from 736) (DROP_OUT from 759) (DROP_OUT from 762) (DROP_OUT from 756) (DROP_OUT from 746) (DROP_OUT from 740) (DROP_OUT from 794) (DROP_OUT from 788) (DROP_OUT from 750) (DROP_OUT from 760) (DROP_OUT from 747) (DROP_OUT from 798) (DROP_OUT from 741)  */
    goto _78;


    __quex_assert_no_passage();
_155:
    /* (DROP_OUT from 737)  */
    goto _39;


    __quex_assert_no_passage();
_156:
    /* (DROP_OUT from 739)  */
    goto _62;


    __quex_assert_no_passage();
_157:
    /* (DROP_OUT from 742)  */
    goto _68;


    __quex_assert_no_passage();
_158:
    /* (DROP_OUT from 743)  */
    goto _40;


    __quex_assert_no_passage();
_159:
    /* (DROP_OUT from 745)  */
    goto _64;


    __quex_assert_no_passage();
_160:
    /* (DROP_OUT from 749)  */
    goto _41;


    __quex_assert_no_passage();
_161:
    /* (DROP_OUT from 752)  */
    goto _59;


    __quex_assert_no_passage();
_162:
    /* (DROP_OUT from 753)  */
    goto _67;


    __quex_assert_no_passage();
_163:
    /* (DROP_OUT from 757)  */
    goto _76;


    __quex_assert_no_passage();
_164:
    /* (DROP_OUT from 758)  */
    goto _77;


    __quex_assert_no_passage();
_165:
    /* (DROP_OUT from 763)  */
    goto _70;


    __quex_assert_no_passage();
_166:
    /* (DROP_OUT from 766)  */
    goto _69;


    __quex_assert_no_passage();
_167:
    /* (DROP_OUT from 792) (DROP_OUT from 800) (DROP_OUT from 767)  */
    goto _72;


    __quex_assert_no_passage();
_168:
    /* (DROP_OUT from 768)  */
    goto _63;


    __quex_assert_no_passage();
_169:
    /* (DROP_OUT from 770)  */
    goto _75;


    __quex_assert_no_passage();
_170:
    /* (DROP_OUT from 784)  */
    goto _74;


    __quex_assert_no_passage();
_171:
    /* (DROP_OUT from 785)  */
    goto _60;


    __quex_assert_no_passage();
_172:
    /* (DROP_OUT from 786)  */
    goto _61;


    __quex_assert_no_passage();
_173:
    /* (DROP_OUT from 787)  */
    goto _65;


    __quex_assert_no_passage();
_174:
    /* (DROP_OUT from 799) (DROP_OUT from 797)  */
    goto _73;


    __quex_assert_no_passage();
_118:
    /* (768 from 745)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(768);
goto _168;


    __quex_assert_no_passage();
_119:
    /* (769 from 769) (769 from 778) (769 from 772) (769 from 781) (769 from 777) (769 from 780) (769 from 775) (769 from 776) (769 from 771) (769 from 774) (769 from 783) (769 from 744) (769 from 779) (769 from 773) (769 from 782)  */

    ++(me->buffer._read_p);

_293:
    input = *(me->buffer._read_p);


    __quex_debug_state(769);
switch( input ) {
case 0x0: goto _233;
case 0x1: 
case 0xA: 
case 0xD: goto _151;
case 0x22: goto _120;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _119;
}


    __quex_assert_no_passage();
_232:
    /* (769 from RELOAD_FORWARD)  */
    goto _293;


    __quex_assert_no_passage();
_120:
    /* (770 from 772) (770 from 769) (770 from 776) (770 from 773) (770 from 780) (770 from 777) (770 from 781) (770 from 774) (770 from 771) (770 from 778) (770 from 775) (770 from 779) (770 from 744)  */

    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(770);
goto _169;


    __quex_assert_no_passage();
_121:
    /* (771 from 744)  */
    ++(me->buffer._read_p);

_297:
    input = *(me->buffer._read_p);


    __quex_debug_state(771);
switch( input ) {
case 0x0: goto _235;
case 0x1: 
case 0xA: 
case 0xD: goto _151;
case 0x22: goto _120;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _122;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _119;
}


    __quex_assert_no_passage();
_234:
    /* (771 from RELOAD_FORWARD)  */
    goto _297;


    __quex_assert_no_passage();
_122:
    /* (772 from 771) (772 from 744)  */

    ++(me->buffer._read_p);

_300:
    input = *(me->buffer._read_p);


    __quex_debug_state(772);
switch( input ) {
case 0x0: goto _237;
case 0x1: 
case 0xA: 
case 0xD: goto _151;
case 0x22: goto _120;
case 0x2E: goto _123;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _124;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _119;
}


    __quex_assert_no_passage();
_236:
    /* (772 from RELOAD_FORWARD)  */
    goto _300;


    __quex_assert_no_passage();
_123:
    /* (773 from 772) (773 from 774) (773 from 775) (773 from 776)  */

    ++(me->buffer._read_p);

_303:
    input = *(me->buffer._read_p);


    __quex_debug_state(773);
switch( input ) {
case 0x0: goto _239;
case 0x1: 
case 0xA: 
case 0xD: goto _151;
case 0x22: goto _120;
case 0x2D: goto _127;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _128;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _119;
}


    __quex_assert_no_passage();
_238:
    /* (773 from RELOAD_FORWARD)  */
    goto _303;


    __quex_assert_no_passage();
_240:
    /* (774 from RELOAD_FORWARD)  */
_305:
    input = *(me->buffer._read_p);


    __quex_debug_state(774);
switch( input ) {
case 0x0: goto _241;
case 0x1: 
case 0xA: 
case 0xD: goto _151;
case 0x22: goto _120;
case 0x2E: goto _123;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _125;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _119;
}


    __quex_assert_no_passage();
_124:
    /* (774 from 772)  */
    ++(me->buffer._read_p);

    goto _305;


    __quex_assert_no_passage();
_125:
    /* (775 from 774)  */
    ++(me->buffer._read_p);

_307:
    input = *(me->buffer._read_p);


    __quex_debug_state(775);
switch( input ) {
case 0x0: goto _243;
case 0x1: 
case 0xA: 
case 0xD: goto _151;
case 0x22: goto _120;
case 0x2E: goto _123;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _126;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _119;
}


    __quex_assert_no_passage();
_242:
    /* (775 from RELOAD_FORWARD)  */
    goto _307;


    __quex_assert_no_passage();
_126:
    /* (776 from 775)  */
    ++(me->buffer._read_p);

_309:
    input = *(me->buffer._read_p);


    __quex_debug_state(776);
switch( input ) {
case 0x0: goto _245;
case 0x1: 
case 0xA: 
case 0xD: goto _151;
case 0x22: goto _120;
case 0x2E: goto _123;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _119;
}


    __quex_assert_no_passage();
_244:
    /* (776 from RELOAD_FORWARD)  */
    goto _309;


    __quex_assert_no_passage();
_246:
    /* (777 from RELOAD_FORWARD)  */
_311:
    input = *(me->buffer._read_p);


    __quex_debug_state(777);
switch( input ) {
case 0x0: goto _247;
case 0x1: 
case 0xA: 
case 0xD: goto _151;
case 0x22: goto _120;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _128;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _119;
}


    __quex_assert_no_passage();
_127:
    /* (777 from 773)  */
    ++(me->buffer._read_p);

    goto _311;


    __quex_assert_no_passage();
_128:
    /* (778 from 773) (778 from 777)  */

    ++(me->buffer._read_p);

_314:
    input = *(me->buffer._read_p);


    __quex_debug_state(778);
switch( input ) {
case 0x0: goto _249;
case 0x1: 
case 0xA: 
case 0xD: goto _151;
case 0x22: goto _120;
case 0x2E: goto _130;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _129;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _119;
}


    __quex_assert_no_passage();
_248:
    /* (778 from RELOAD_FORWARD)  */
    goto _314;


    __quex_assert_no_passage();
_129:
    /* (779 from 778)  */
    ++(me->buffer._read_p);

_316:
    input = *(me->buffer._read_p);


    __quex_debug_state(779);
switch( input ) {
case 0x0: goto _251;
case 0x1: 
case 0xA: 
case 0xD: goto _151;
case 0x22: goto _120;
case 0x2E: goto _130;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _119;
}


    __quex_assert_no_passage();
_250:
    /* (779 from RELOAD_FORWARD)  */
    goto _316;


    __quex_assert_no_passage();
_130:
    /* (780 from 779) (780 from 778)  */

    ++(me->buffer._read_p);

_319:
    input = *(me->buffer._read_p);


    __quex_debug_state(780);
switch( input ) {
case 0x0: goto _253;
case 0x1: 
case 0xA: 
case 0xD: goto _151;
case 0x22: goto _120;
case 0x2D: goto _131;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _132;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _119;
}


    __quex_assert_no_passage();
_252:
    /* (780 from RELOAD_FORWARD)  */
    goto _319;


    __quex_assert_no_passage();
_131:
    /* (781 from 780)  */
    ++(me->buffer._read_p);

_321:
    input = *(me->buffer._read_p);


    __quex_debug_state(781);
switch( input ) {
case 0x0: goto _255;
case 0x1: 
case 0xA: 
case 0xD: goto _151;
case 0x22: goto _120;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _132;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _119;
}


    __quex_assert_no_passage();
_254:
    /* (781 from RELOAD_FORWARD)  */
    goto _321;


    __quex_assert_no_passage();
_132:
    /* (782 from 781) (782 from 780)  */

    ++(me->buffer._read_p);

_324:
    input = *(me->buffer._read_p);


    __quex_debug_state(782);
switch( input ) {
case 0x0: goto _257;
case 0x1: 
case 0xA: 
case 0xD: goto _151;
case 0x22: goto _134;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _133;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _119;
}


    __quex_assert_no_passage();
_256:
    /* (782 from RELOAD_FORWARD)  */
    goto _324;


    __quex_assert_no_passage();
_133:
    /* (783 from 782)  */
    ++(me->buffer._read_p);

_326:
    input = *(me->buffer._read_p);


    __quex_debug_state(783);
switch( input ) {
case 0x0: goto _259;
case 0x1: 
case 0xA: 
case 0xD: goto _151;
case 0x22: goto _134;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _119;
}


    __quex_assert_no_passage();
_258:
    /* (783 from RELOAD_FORWARD)  */
    goto _326;


    __quex_assert_no_passage();
_134:
    /* (784 from 783) (784 from 782)  */

    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(784);
goto _170;


    __quex_assert_no_passage();
_135:
    /* (785 from 739)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(785);
goto _171;


    __quex_assert_no_passage();
_136:
    /* (786 from 738)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(786);
goto _172;


    __quex_assert_no_passage();
_137:
    /* (787 from 735)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(787);
goto _173;


    __quex_assert_no_passage();
_138:
    /* (788 from 791) (788 from 734) (788 from 789) (788 from 790)  */

    ++(me->buffer._read_p);

_334:
    input = *(me->buffer._read_p);


    __quex_debug_state(788);
switch( input ) {
case 0x0: goto _261;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _154;
case 0x2D: goto _143;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _142;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_260:
    /* (788 from RELOAD_FORWARD)  */
    goto _334;


    __quex_assert_no_passage();
_139:
    /* (789 from 734)  */
    ++(me->buffer._read_p);

_336:
    input = *(me->buffer._read_p);


    __quex_debug_state(789);
switch( input ) {
case 0x0: goto _263;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _152;
case 0x2E: goto _138;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _140;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _152;
default: goto _86;
}


    __quex_assert_no_passage();
_262:
    /* (789 from RELOAD_FORWARD)  */
    goto _336;


    __quex_assert_no_passage();
_264:
    /* (790 from RELOAD_FORWARD)  */
_338:
    input = *(me->buffer._read_p);


    __quex_debug_state(790);
switch( input ) {
case 0x0: goto _265;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _152;
case 0x2E: goto _138;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _141;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _152;
default: goto _86;
}


    __quex_assert_no_passage();
_140:
    /* (790 from 789)  */
    ++(me->buffer._read_p);

    goto _338;


    __quex_assert_no_passage();
_141:
    /* (791 from 790)  */
    ++(me->buffer._read_p);

_340:
    input = *(me->buffer._read_p);


    __quex_debug_state(791);
switch( input ) {
case 0x0: goto _267;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _152;
case 0x2E: goto _138;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _104;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _152;
default: goto _86;
}


    __quex_assert_no_passage();
_266:
    /* (791 from RELOAD_FORWARD)  */
    goto _340;


    __quex_assert_no_passage();
_142:
    /* (792 from 788)  */
    ++(me->buffer._read_p);

_342:
    input = *(me->buffer._read_p);


    __quex_debug_state(792);
switch( input ) {
case 0x0: goto _269;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _167;
case 0x2E: goto _146;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _150;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _167;
default: goto _86;
}


    __quex_assert_no_passage();
_268:
    /* (792 from RELOAD_FORWARD)  */
    goto _342;


    __quex_assert_no_passage();
_270:
    /* (793 from RELOAD_FORWARD)  */
_344:
    input = *(me->buffer._read_p);


    __quex_debug_state(793);
switch( input ) {
case 0x0: goto _271;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _154;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _144;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_143:
    /* (793 from 788)  */
    ++(me->buffer._read_p);

    goto _344;


    __quex_assert_no_passage();
_272:
    /* (794 from RELOAD_FORWARD)  */
_346:
    input = *(me->buffer._read_p);


    __quex_debug_state(794);
switch( input ) {
case 0x0: goto _273;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _154;
case 0x2E: goto _146;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _145;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_144:
    /* (794 from 793)  */
    ++(me->buffer._read_p);

    goto _346;


    __quex_assert_no_passage();
_145:
    /* (795 from 794)  */
    ++(me->buffer._read_p);

_348:
    input = *(me->buffer._read_p);


    __quex_debug_state(795);
switch( input ) {
case 0x0: goto _275;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _154;
case 0x2E: goto _146;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_274:
    /* (795 from RELOAD_FORWARD)  */
    goto _348;


    __quex_assert_no_passage();
_146:
    /* (796 from 800) (796 from 795) (796 from 794) (796 from 792)  */

    ++(me->buffer._read_p);

_351:
    input = *(me->buffer._read_p);


    __quex_debug_state(796);
switch( input ) {
case 0x0: goto _277;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _154;
case 0x2D: goto _148;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _147;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_276:
    /* (796 from RELOAD_FORWARD)  */
    goto _351;


    __quex_assert_no_passage();
_147:
    /* (797 from 796) (797 from 798)  */

    ++(me->buffer._read_p);

_354:
    input = *(me->buffer._read_p);


    __quex_debug_state(797);
switch( input ) {
case 0x0: goto _279;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _174;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _149;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _174;
default: goto _86;
}


    __quex_assert_no_passage();
_278:
    /* (797 from RELOAD_FORWARD)  */
    goto _354;


    __quex_assert_no_passage();
_280:
    /* (798 from RELOAD_FORWARD)  */
_356:
    input = *(me->buffer._read_p);


    __quex_debug_state(798);
switch( input ) {
case 0x0: goto _281;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _154;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _147;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_148:
    /* (798 from 796)  */
    ++(me->buffer._read_p);

    goto _356;


    __quex_assert_no_passage();
_149:
    /* (799 from 797)  */
    ++(me->buffer._read_p);

_358:
    input = *(me->buffer._read_p);


    __quex_debug_state(799);
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
case 0x9D: goto _174;
default: goto _86;
}


    __quex_assert_no_passage();
_282:
    /* (799 from RELOAD_FORWARD)  */
    goto _358;


    __quex_assert_no_passage();
_150:
    /* (800 from 792)  */
    ++(me->buffer._read_p);

_360:
    input = *(me->buffer._read_p);


    __quex_debug_state(800);
switch( input ) {
case 0x0: goto _285;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _167;
case 0x2E: goto _146;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _117;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _167;
default: goto _86;
}


    __quex_assert_no_passage();
_284:
    /* (800 from RELOAD_FORWARD)  */
    goto _360;


    __quex_assert_no_passage();
_84:
    /* (734 from 746) (734 from 733)  */

    ++(me->buffer._read_p);

_363:
    input = *(me->buffer._read_p);


    __quex_debug_state(734);
switch( input ) {
case 0x0: goto _177;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _152;
case 0x2E: goto _138;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _139;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _152;
default: goto _86;
}


    __quex_assert_no_passage();
_176:
    /* (734 from RELOAD_FORWARD)  */
    goto _363;


    __quex_assert_no_passage();
_85:
    /* (735 from 733)  */
    ++(me->buffer._read_p);

_365:
    input = *(me->buffer._read_p);


    __quex_debug_state(735);
if     ( input == 0x3D )  goto _137;
else if( input == 0x0 )   goto _179;
else                      goto _153;


    __quex_assert_no_passage();
_178:
    /* (735 from RELOAD_FORWARD)  */
    goto _365;


    __quex_assert_no_passage();
_86:
    /* (736 from 765) (736 from 736) (736 from 759) (736 from 798) (736 from 762) (736 from 756) (736 from 795) (736 from 789) (736 from 746) (736 from 792) (736 from 733) (736 from 740) (736 from 766) (736 from 799) (736 from 763) (736 from 750) (736 from 757) (736 from 796) (736 from 760) (736 from 790) (736 from 747) (736 from 754) (736 from 793) (736 from 800) (736 from 734) (736 from 741) (736 from 767) (736 from 738) (736 from 764) (736 from 751) (736 from 758) (736 from 797) (736 from 761) (736 from 791) (736 from 748) (736 from 755) (736 from 794) (736 from 788)  */

    ++(me->buffer._read_p);

_368:
    input = *(me->buffer._read_p);


    __quex_debug_state(736);
switch( input ) {
case 0x0: goto _181;
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
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_180:
    /* (736 from RELOAD_FORWARD)  */
    goto _368;


    __quex_assert_no_passage();
_87:
    /* (737 from 733)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(737);
goto _155;


    __quex_assert_no_passage();
_182:
    /* (738 from RELOAD_FORWARD)  */
_371:
    input = *(me->buffer._read_p);


    __quex_debug_state(738);
switch( input ) {
case 0x0: goto _183;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: goto _154;
case 0x3D: goto _136;
case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_88:
    /* (738 from 733)  */
    ++(me->buffer._read_p);

    goto _371;


    __quex_assert_no_passage();
_89:
    /* (739 from 733)  */
    ++(me->buffer._read_p);

_373:
    input = *(me->buffer._read_p);


    __quex_debug_state(739);
if     ( input == 0x3D )  goto _135;
else if( input == 0x0 )   goto _185;
else                      goto _156;


    __quex_assert_no_passage();
_184:
    /* (739 from RELOAD_FORWARD)  */
    goto _373;


    __quex_assert_no_passage();
_90:
    /* (740 from 733)  */
    ++(me->buffer._read_p);

_375:
    input = *(me->buffer._read_p);


    __quex_debug_state(740);
switch( input ) {
case 0x0: goto _187;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _154;
case 0x5F: goto _109;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_186:
    /* (740 from RELOAD_FORWARD)  */
    goto _375;


    __quex_assert_no_passage();
_188:
    /* (741 from RELOAD_FORWARD)  */
_377:
    input = *(me->buffer._read_p);


    __quex_debug_state(741);
switch( input ) {
case 0x0: goto _189;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _154;
case 0x2E: goto _97;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _104;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_91:
    /* (741 from 733)  */
    ++(me->buffer._read_p);

    goto _377;


    __quex_assert_no_passage();
_92:
    /* (742 from 733)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(742);
goto _157;


    __quex_assert_no_passage();
_93:
    /* (743 from 733)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(743);
goto _158;


    __quex_assert_no_passage();
_94:
    /* (744 from 733)  */
    ++(me->buffer._read_p);

_381:
    input = *(me->buffer._read_p);


    __quex_debug_state(744);
switch( input ) {
case 0x0: goto _191;
case 0x1: 
case 0xA: 
case 0xD: goto _151;
case 0x22: goto _120;
case 0x2D: goto _121;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _122;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _151;
default: goto _119;
}


    __quex_assert_no_passage();
_190:
    /* (744 from RELOAD_FORWARD)  */
    goto _381;


    __quex_assert_no_passage();
_192:
    /* (745 from RELOAD_FORWARD)  */
_383:
    input = *(me->buffer._read_p);


    __quex_debug_state(745);
if     ( input == 0x3D )  goto _118;
else if( input == 0x0 )   goto _193;
else                      goto _159;


    __quex_assert_no_passage();
_95:
    /* (745 from 733)  */
    ++(me->buffer._read_p);

    goto _383;


    __quex_assert_no_passage();
_96:
    /* (746 from 733)  */
    ++(me->buffer._read_p);

_385:
    input = *(me->buffer._read_p);


    __quex_debug_state(746);
switch( input ) {
case 0x0: goto _195;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _154;
case 0x2E: goto _97;
case 0x30: goto _104;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _84;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_194:
    /* (746 from RELOAD_FORWARD)  */
    goto _385;


    __quex_assert_no_passage();
_97:
    /* (747 from 754) (747 from 746) (747 from 741) (747 from 733)  */

    ++(me->buffer._read_p);

_388:
    input = *(me->buffer._read_p);


    __quex_debug_state(747);
switch( input ) {
case 0x0: goto _197;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _154;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _117;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_196:
    /* (747 from RELOAD_FORWARD)  */
    goto _388;


    __quex_assert_no_passage();
_198:
    /* (748 from RELOAD_FORWARD)  */
_390:
    input = *(me->buffer._read_p);


    __quex_debug_state(748);
switch( input ) {
case 0x0: goto _199;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _154;
case 0x66: goto _116;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_98:
    /* (748 from 733)  */
    ++(me->buffer._read_p);

    goto _390;


    __quex_assert_no_passage();
_99:
    /* (749 from 733)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(749);
goto _160;


    __quex_assert_no_passage();
_200:
    /* (750 from RELOAD_FORWARD)  */
_393:
    input = *(me->buffer._read_p);


    __quex_debug_state(750);
switch( input ) {
case 0x0: goto _201;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _154;
case 0x5F: goto _109;
case 0x6C: goto _110;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_100:
    /* (750 from 733)  */
    ++(me->buffer._read_p);

    goto _393;


    __quex_assert_no_passage();
_101:
    /* (751 from 733)  */
    ++(me->buffer._read_p);

_395:
    input = *(me->buffer._read_p);


    __quex_debug_state(751);
switch( input ) {
case 0x0: goto _203;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _154;
case 0x5F: goto _105;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_202:
    /* (751 from RELOAD_FORWARD)  */
    goto _395;


    __quex_assert_no_passage();
_102:
    /* (752 from 733)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(752);
goto _161;


    __quex_assert_no_passage();
_103:
    /* (753 from 733)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(753);
goto _162;


    __quex_assert_no_passage();
_104:
    /* (754 from 746) (754 from 754) (754 from 733) (754 from 741) (754 from 791)  */

    ++(me->buffer._read_p);

_400:
    input = *(me->buffer._read_p);


    __quex_debug_state(754);
switch( input ) {
case 0x0: goto _205;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _152;
case 0x2E: goto _97;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _104;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _152;
default: goto _86;
}


    __quex_assert_no_passage();
_204:
    /* (754 from RELOAD_FORWARD)  */
    goto _400;


    __quex_assert_no_passage();
_206:
    /* (755 from RELOAD_FORWARD)  */
_402:
    input = *(me->buffer._read_p);


    __quex_debug_state(755);
switch( input ) {
case 0x0: goto _207;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _154;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _107;
case 0x3C: case 0x3D: case 0x3E: goto _154;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _106;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_105:
    /* (755 from 751)  */
    ++(me->buffer._read_p);

    goto _402;


    __quex_assert_no_passage();
_106:
    /* (756 from 759) (756 from 755)  */

    ++(me->buffer._read_p);

_405:
    input = *(me->buffer._read_p);


    __quex_debug_state(756);
switch( input ) {
case 0x0: goto _209;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _154;
case 0x2D: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _108;
case 0x3C: case 0x3D: case 0x3E: goto _154;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _108;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_208:
    /* (756 from RELOAD_FORWARD)  */
    goto _405;


    __quex_assert_no_passage();
_107:
    /* (757 from 757) (757 from 755)  */

    ++(me->buffer._read_p);

_408:
    input = *(me->buffer._read_p);


    __quex_debug_state(757);
switch( input ) {
case 0x0: goto _211;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _163;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _107;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _163;
default: goto _86;
}


    __quex_assert_no_passage();
_210:
    /* (757 from RELOAD_FORWARD)  */
    goto _408;


    __quex_assert_no_passage();
_108:
    /* (758 from 756) (758 from 758)  */

    ++(me->buffer._read_p);

_411:
    input = *(me->buffer._read_p);


    __quex_debug_state(758);
switch( input ) {
case 0x0: goto _213;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _164;
case 0x2D: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _108;
case 0x3C: case 0x3D: case 0x3E: goto _164;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _108;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _164;
default: goto _86;
}


    __quex_assert_no_passage();
_212:
    /* (758 from RELOAD_FORWARD)  */
    goto _411;


    __quex_assert_no_passage();
_109:
    /* (759 from 750) (759 from 740)  */

    ++(me->buffer._read_p);

_414:
    input = *(me->buffer._read_p);


    __quex_debug_state(759);
switch( input ) {
case 0x0: goto _215;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _154;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _106;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_214:
    /* (759 from RELOAD_FORWARD)  */
    goto _414;


    __quex_assert_no_passage();
_110:
    /* (760 from 750)  */
    ++(me->buffer._read_p);

_416:
    input = *(me->buffer._read_p);


    __quex_debug_state(760);
switch( input ) {
case 0x0: goto _217;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _154;
case 0x69: goto _112;
case 0x73: goto _111;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_216:
    /* (760 from RELOAD_FORWARD)  */
    goto _416;


    __quex_assert_no_passage();
_111:
    /* (761 from 760)  */
    ++(me->buffer._read_p);

_418:
    input = *(me->buffer._read_p);


    __quex_debug_state(761);
switch( input ) {
case 0x0: goto _219;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _154;
case 0x65: goto _114;
case 0x69: goto _112;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_218:
    /* (761 from RELOAD_FORWARD)  */
    goto _418;


    __quex_assert_no_passage();
_112:
    /* (762 from 765) (762 from 761) (762 from 760)  */

    ++(me->buffer._read_p);

_421:
    input = *(me->buffer._read_p);


    __quex_debug_state(762);
switch( input ) {
case 0x0: goto _221;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _154;
case 0x66: goto _113;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_220:
    /* (762 from RELOAD_FORWARD)  */
    goto _421;


    __quex_assert_no_passage();
_113:
    /* (763 from 762)  */
    ++(me->buffer._read_p);

_423:
    input = *(me->buffer._read_p);


    __quex_debug_state(763);
switch( input ) {
case 0x0: goto _223;
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
case 0x9D: goto _165;
default: goto _86;
}


    __quex_assert_no_passage();
_222:
    /* (763 from RELOAD_FORWARD)  */
    goto _423;


    __quex_assert_no_passage();
_114:
    /* (764 from 761)  */
    ++(me->buffer._read_p);

_425:
    input = *(me->buffer._read_p);


    __quex_debug_state(764);
switch( input ) {
case 0x0: goto _225;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _154;
case 0x5F: goto _115;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_224:
    /* (764 from RELOAD_FORWARD)  */
    goto _425;


    __quex_assert_no_passage();
_226:
    /* (765 from RELOAD_FORWARD)  */
_427:
    input = *(me->buffer._read_p);


    __quex_debug_state(765);
switch( input ) {
case 0x0: goto _227;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _154;
case 0x69: goto _112;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _86;
}


    __quex_assert_no_passage();
_115:
    /* (765 from 764)  */
    ++(me->buffer._read_p);

    goto _427;


    __quex_assert_no_passage();
_228:
    /* (766 from RELOAD_FORWARD)  */
_429:
    input = *(me->buffer._read_p);


    __quex_debug_state(766);
switch( input ) {
case 0x0: goto _229;
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
case 0x9D: goto _166;
default: goto _86;
}


    __quex_assert_no_passage();
_116:
    /* (766 from 748)  */
    ++(me->buffer._read_p);

    goto _429;


    __quex_assert_no_passage();
_117:
    /* (767 from 767) (767 from 747) (767 from 800)  */

    ++(me->buffer._read_p);

_432:
    input = *(me->buffer._read_p);


    __quex_debug_state(767);
switch( input ) {
case 0x0: goto _231;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _167;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _117;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _167;
default: goto _86;
}


    __quex_assert_no_passage();
_230:
    /* (767 from RELOAD_FORWARD)  */
    goto _432;
_20:
    /* (456 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

_434:
__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_433:
    __quex_debug("Init State\n");
    __quex_debug_state(456);
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
    /* (456 from 462)  */
    goto _433;


    __quex_assert_no_passage();
_30:
    /* (456 from RELOAD_FORWARD)  */
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

    goto _434;


    __quex_assert_no_passage();
_27:
    /* (DROP_OUT from 458)  */
    goto _36;
_435:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_26:
    /* (DROP_OUT from 457)  */
    goto _35;


    __quex_assert_no_passage();
_28:
    /* (DROP_OUT from 459)  */
    goto _37;


    __quex_assert_no_passage();
_29:
    /* (DROP_OUT from 460)  */
    goto _34;


    __quex_assert_no_passage();
_25:
    /* (DROP_OUT from 456)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _82;
    goto _435;


    __quex_assert_no_passage();
_21:
    /* (457 from 456)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(457);
goto _26;


    __quex_assert_no_passage();
_22:
    /* (458 from 456)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(458);
goto _27;


    __quex_assert_no_passage();
_23:
    /* (459 from 456)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(459);
goto _28;


    __quex_assert_no_passage();
_24:
    /* (460 from 456)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(460);
goto _29;
_43:
    /* (489 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

_441:
__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_440:
    __quex_debug("Init State\n");
    __quex_debug_state(489);
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
    /* (489 from 493)  */
    goto _440;


    __quex_assert_no_passage();
_51:
    /* (489 from RELOAD_FORWARD)  */
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

    goto _441;


    __quex_assert_no_passage();
_49:
    /* (DROP_OUT from 491)  */
    goto _57;
_442:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_48:
    /* (DROP_OUT from 490)  */
    goto _56;


    __quex_assert_no_passage();
_50:
    /* (DROP_OUT from 492)  */
    goto _58;


    __quex_assert_no_passage();
_47:
    /* (DROP_OUT from 489)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _82;
    goto _442;


    __quex_assert_no_passage();
_44:
    /* (490 from 489)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(490);
goto _48;


    __quex_assert_no_passage();
_45:
    /* (491 from 489)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(491);
goto _49;


    __quex_assert_no_passage();
_46:
    /* (492 from 489)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(492);
goto _50;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_79:
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
_80:
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
_81:
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
_31:
    __quex_debug("* TERMINAL END_OF_STREAM\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 76 "zck.qx"
self_send(T_TERMINATION);

__QUEX_PURE_RETURN;


#   line 2937 "Lexer.cpp"

}
    /* End of Stream FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
__QUEX_PURE_RETURN;
_82:
    __quex_debug("* TERMINAL FAILURE\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 77 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_FAILURE);

__QUEX_PURE_RETURN;


#   line 2956 "Lexer.cpp"

}
RETURN;
_38:
    __quex_debug("* TERMINAL <skip>\n");
goto _20;
_42:
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
_34:
    __quex_debug("* TERMINAL <LOOP EXIT>\n");
    --(me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _19;

_35:
    __quex_debug("* TERMINAL <LOOP 134>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _33;

_36:
    __quex_debug("* TERMINAL <LOOP 135>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _33;

_37:
    __quex_debug("* TERMINAL <LOOP 136>\n");
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
    __quex_debug("* TERMINAL <COUPLE 149>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _55;

_57:
    __quex_debug("* TERMINAL <LOOP 150>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _53;

_58:
    __quex_debug("* TERMINAL <LOOP 151>\n");
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
{

#   line 78 "zck.qx"
self_send(T_OP_DEQ);

__QUEX_PURE_RETURN;


#   line 3086 "Lexer.cpp"

}
RETURN;
_61:
    __quex_debug("* TERMINAL \"!=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 79 "zck.qx"
self_send(T_OP_NEQ);

__QUEX_PURE_RETURN;


#   line 3102 "Lexer.cpp"

}
RETURN;
_62:
    __quex_debug("* TERMINAL \"=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 80 "zck.qx"
self_send(T_OP_EQ);

__QUEX_PURE_RETURN;


#   line 3118 "Lexer.cpp"

}
RETURN;
_63:
    __quex_debug("* TERMINAL \"<=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 81 "zck.qx"
self_send(T_OP_LTEQ);

__QUEX_PURE_RETURN;


#   line 3134 "Lexer.cpp"

}
RETURN;
_64:
    __quex_debug("* TERMINAL \"<\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 82 "zck.qx"
self_send(T_OP_LT);

__QUEX_PURE_RETURN;


#   line 3150 "Lexer.cpp"

}
RETURN;
_65:
    __quex_debug("* TERMINAL \">=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 83 "zck.qx"
self_send(T_OP_GTEQ);

__QUEX_PURE_RETURN;


#   line 3166 "Lexer.cpp"

}
RETURN;
_66:
    __quex_debug("* TERMINAL \">\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 84 "zck.qx"
self_send(T_OP_GT);

__QUEX_PURE_RETURN;


#   line 3182 "Lexer.cpp"

}
RETURN;
_67:
    __quex_debug("* TERMINAL \"{\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 85 "zck.qx"
self_send(T_L_BRACE);

__QUEX_PURE_RETURN;


#   line 3198 "Lexer.cpp"

}
RETURN;
_68:
    __quex_debug("* TERMINAL \"}\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 86 "zck.qx"
self_send(T_R_BRACE);

__QUEX_PURE_RETURN;


#   line 3214 "Lexer.cpp"

}
RETURN;
_69:
    __quex_debug("* TERMINAL \"if\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 87 "zck.qx"
self_send(T_IF);

__QUEX_PURE_RETURN;


#   line 3230 "Lexer.cpp"

}
RETURN;
_70:
    __quex_debug("* TERMINAL {ELSIF}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 88 "zck.qx"
self_send(T_ELSIF);

__QUEX_PURE_RETURN;


#   line 3246 "Lexer.cpp"

}
RETURN;
_71:
    __quex_debug("* TERMINAL {SIGN}[0-9]+\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 89 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_INTEGER);

__QUEX_PURE_RETURN;


#   line 3263 "Lexer.cpp"

}
RETURN;
_72:
    __quex_debug("* TERMINAL {DECIMAL}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 90 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_DECIMAL);

__QUEX_PURE_RETURN;


#   line 3280 "Lexer.cpp"

}
RETURN;
_73:
    __quex_debug("* TERMINAL {DATE}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 91 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_DATE);

__QUEX_PURE_RETURN;


#   line 3297 "Lexer.cpp"

}
RETURN;
_74:
    __quex_debug("* TERMINAL \"\\\"\"{DATE}\"\\\"\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 92 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), LexemeBegin+1, LexemeEnd-1);
self_send(T_QDATE);

__QUEX_PURE_RETURN;


#   line 3314 "Lexer.cpp"

}
RETURN;
_75:
    __quex_debug("* TERMINAL {QSTRING}\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 93 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), LexemeBegin+1, LexemeEnd-1);
self_send(T_QSTRING);

__QUEX_PURE_RETURN;


#   line 3330 "Lexer.cpp"

}
RETURN;
_76:
    __quex_debug("* TERMINAL {CHAR_ID}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 94 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_CHAR_SCOPE);

__QUEX_PURE_RETURN;


#   line 3347 "Lexer.cpp"

}
RETURN;
_77:
    __quex_debug("* TERMINAL {TITLE_ID}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 95 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_TITLE_ID);

__QUEX_PURE_RETURN;


#   line 3364 "Lexer.cpp"

}
RETURN;
_78:
    __quex_debug("* TERMINAL {STRING}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 96 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_STRING);

__QUEX_PURE_RETURN;


#   line 3381 "Lexer.cpp"

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
_451:
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
case 151: {
goto _151;}
case 152: {
goto _152;}
case 153: {
goto _153;}
case 154: {
goto _154;}
case 156: {
goto _156;}
case 159: {
goto _159;}
case 163: {
goto _163;}
case 164: {
goto _164;}
case 165: {
goto _165;}
case 166: {
goto _166;}
case 167: {
goto _167;}
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
default: {
goto _284;}
}
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */


    __quex_assert_no_passage();
_52:
    /* (RELOAD_FORWARD from 489)  */
    target_state_index = QUEX_LABEL(51); target_state_else_index = QUEX_LABEL(42);

_447:
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

_446:

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
    /* (RELOAD_FORWARD from 456)  */
    target_state_index = QUEX_LABEL(30); target_state_else_index = QUEX_LABEL(31);

    goto _447;


    __quex_assert_no_passage();
_175:
    /* (RELOAD_FORWARD from 733)  */
    target_state_index = QUEX_LABEL(83); target_state_else_index = QUEX_LABEL(31);

    goto _446;


    __quex_assert_no_passage();
_177:
    /* (RELOAD_FORWARD from 734)  */
    target_state_index = QUEX_LABEL(176); target_state_else_index = QUEX_LABEL(152);

    goto _446;


    __quex_assert_no_passage();
_179:
    /* (RELOAD_FORWARD from 735)  */
    target_state_index = QUEX_LABEL(178); target_state_else_index = QUEX_LABEL(153);

    goto _446;


    __quex_assert_no_passage();
_181:
    /* (RELOAD_FORWARD from 736)  */
    target_state_index = QUEX_LABEL(180); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_183:
    /* (RELOAD_FORWARD from 738)  */
    target_state_index = QUEX_LABEL(182); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_185:
    /* (RELOAD_FORWARD from 739)  */
    target_state_index = QUEX_LABEL(184); target_state_else_index = QUEX_LABEL(156);

    goto _446;


    __quex_assert_no_passage();
_187:
    /* (RELOAD_FORWARD from 740)  */
    target_state_index = QUEX_LABEL(186); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_189:
    /* (RELOAD_FORWARD from 741)  */
    target_state_index = QUEX_LABEL(188); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_191:
    /* (RELOAD_FORWARD from 744)  */
    target_state_index = QUEX_LABEL(190); target_state_else_index = QUEX_LABEL(151);

    goto _446;


    __quex_assert_no_passage();
_193:
    /* (RELOAD_FORWARD from 745)  */
    target_state_index = QUEX_LABEL(192); target_state_else_index = QUEX_LABEL(159);

    goto _446;


    __quex_assert_no_passage();
_195:
    /* (RELOAD_FORWARD from 746)  */
    target_state_index = QUEX_LABEL(194); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_197:
    /* (RELOAD_FORWARD from 747)  */
    target_state_index = QUEX_LABEL(196); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_199:
    /* (RELOAD_FORWARD from 748)  */
    target_state_index = QUEX_LABEL(198); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_201:
    /* (RELOAD_FORWARD from 750)  */
    target_state_index = QUEX_LABEL(200); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_203:
    /* (RELOAD_FORWARD from 751)  */
    target_state_index = QUEX_LABEL(202); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_205:
    /* (RELOAD_FORWARD from 754)  */
    target_state_index = QUEX_LABEL(204); target_state_else_index = QUEX_LABEL(152);

    goto _446;


    __quex_assert_no_passage();
_207:
    /* (RELOAD_FORWARD from 755)  */
    target_state_index = QUEX_LABEL(206); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_209:
    /* (RELOAD_FORWARD from 756)  */
    target_state_index = QUEX_LABEL(208); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_211:
    /* (RELOAD_FORWARD from 757)  */
    target_state_index = QUEX_LABEL(210); target_state_else_index = QUEX_LABEL(163);

    goto _446;


    __quex_assert_no_passage();
_213:
    /* (RELOAD_FORWARD from 758)  */
    target_state_index = QUEX_LABEL(212); target_state_else_index = QUEX_LABEL(164);

    goto _446;


    __quex_assert_no_passage();
_215:
    /* (RELOAD_FORWARD from 759)  */
    target_state_index = QUEX_LABEL(214); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_217:
    /* (RELOAD_FORWARD from 760)  */
    target_state_index = QUEX_LABEL(216); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_219:
    /* (RELOAD_FORWARD from 761)  */
    target_state_index = QUEX_LABEL(218); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_221:
    /* (RELOAD_FORWARD from 762)  */
    target_state_index = QUEX_LABEL(220); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_223:
    /* (RELOAD_FORWARD from 763)  */
    target_state_index = QUEX_LABEL(222); target_state_else_index = QUEX_LABEL(165);

    goto _446;


    __quex_assert_no_passage();
_225:
    /* (RELOAD_FORWARD from 764)  */
    target_state_index = QUEX_LABEL(224); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_227:
    /* (RELOAD_FORWARD from 765)  */
    target_state_index = QUEX_LABEL(226); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_229:
    /* (RELOAD_FORWARD from 766)  */
    target_state_index = QUEX_LABEL(228); target_state_else_index = QUEX_LABEL(166);

    goto _446;


    __quex_assert_no_passage();
_231:
    /* (RELOAD_FORWARD from 767)  */
    target_state_index = QUEX_LABEL(230); target_state_else_index = QUEX_LABEL(167);

    goto _446;


    __quex_assert_no_passage();
_233:
    /* (RELOAD_FORWARD from 769)  */
    target_state_index = QUEX_LABEL(232); target_state_else_index = QUEX_LABEL(151);

    goto _446;


    __quex_assert_no_passage();
_235:
    /* (RELOAD_FORWARD from 771)  */
    target_state_index = QUEX_LABEL(234); target_state_else_index = QUEX_LABEL(151);

    goto _446;


    __quex_assert_no_passage();
_237:
    /* (RELOAD_FORWARD from 772)  */
    target_state_index = QUEX_LABEL(236); target_state_else_index = QUEX_LABEL(151);

    goto _446;


    __quex_assert_no_passage();
_239:
    /* (RELOAD_FORWARD from 773)  */
    target_state_index = QUEX_LABEL(238); target_state_else_index = QUEX_LABEL(151);

    goto _446;


    __quex_assert_no_passage();
_241:
    /* (RELOAD_FORWARD from 774)  */
    target_state_index = QUEX_LABEL(240); target_state_else_index = QUEX_LABEL(151);

    goto _446;


    __quex_assert_no_passage();
_243:
    /* (RELOAD_FORWARD from 775)  */
    target_state_index = QUEX_LABEL(242); target_state_else_index = QUEX_LABEL(151);

    goto _446;


    __quex_assert_no_passage();
_245:
    /* (RELOAD_FORWARD from 776)  */
    target_state_index = QUEX_LABEL(244); target_state_else_index = QUEX_LABEL(151);

    goto _446;


    __quex_assert_no_passage();
_247:
    /* (RELOAD_FORWARD from 777)  */
    target_state_index = QUEX_LABEL(246); target_state_else_index = QUEX_LABEL(151);

    goto _446;


    __quex_assert_no_passage();
_249:
    /* (RELOAD_FORWARD from 778)  */
    target_state_index = QUEX_LABEL(248); target_state_else_index = QUEX_LABEL(151);

    goto _446;


    __quex_assert_no_passage();
_251:
    /* (RELOAD_FORWARD from 779)  */
    target_state_index = QUEX_LABEL(250); target_state_else_index = QUEX_LABEL(151);

    goto _446;


    __quex_assert_no_passage();
_253:
    /* (RELOAD_FORWARD from 780)  */
    target_state_index = QUEX_LABEL(252); target_state_else_index = QUEX_LABEL(151);

    goto _446;


    __quex_assert_no_passage();
_255:
    /* (RELOAD_FORWARD from 781)  */
    target_state_index = QUEX_LABEL(254); target_state_else_index = QUEX_LABEL(151);

    goto _446;


    __quex_assert_no_passage();
_257:
    /* (RELOAD_FORWARD from 782)  */
    target_state_index = QUEX_LABEL(256); target_state_else_index = QUEX_LABEL(151);

    goto _446;


    __quex_assert_no_passage();
_259:
    /* (RELOAD_FORWARD from 783)  */
    target_state_index = QUEX_LABEL(258); target_state_else_index = QUEX_LABEL(151);

    goto _446;


    __quex_assert_no_passage();
_261:
    /* (RELOAD_FORWARD from 788)  */
    target_state_index = QUEX_LABEL(260); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_263:
    /* (RELOAD_FORWARD from 789)  */
    target_state_index = QUEX_LABEL(262); target_state_else_index = QUEX_LABEL(152);

    goto _446;


    __quex_assert_no_passage();
_265:
    /* (RELOAD_FORWARD from 790)  */
    target_state_index = QUEX_LABEL(264); target_state_else_index = QUEX_LABEL(152);

    goto _446;


    __quex_assert_no_passage();
_267:
    /* (RELOAD_FORWARD from 791)  */
    target_state_index = QUEX_LABEL(266); target_state_else_index = QUEX_LABEL(152);

    goto _446;


    __quex_assert_no_passage();
_269:
    /* (RELOAD_FORWARD from 792)  */
    target_state_index = QUEX_LABEL(268); target_state_else_index = QUEX_LABEL(167);

    goto _446;


    __quex_assert_no_passage();
_271:
    /* (RELOAD_FORWARD from 793)  */
    target_state_index = QUEX_LABEL(270); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_273:
    /* (RELOAD_FORWARD from 794)  */
    target_state_index = QUEX_LABEL(272); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_275:
    /* (RELOAD_FORWARD from 795)  */
    target_state_index = QUEX_LABEL(274); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_277:
    /* (RELOAD_FORWARD from 796)  */
    target_state_index = QUEX_LABEL(276); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_279:
    /* (RELOAD_FORWARD from 797)  */
    target_state_index = QUEX_LABEL(278); target_state_else_index = QUEX_LABEL(174);

    goto _446;


    __quex_assert_no_passage();
_281:
    /* (RELOAD_FORWARD from 798)  */
    target_state_index = QUEX_LABEL(280); target_state_else_index = QUEX_LABEL(154);

    goto _446;


    __quex_assert_no_passage();
_283:
    /* (RELOAD_FORWARD from 799)  */
    target_state_index = QUEX_LABEL(282); target_state_else_index = QUEX_LABEL(174);

    goto _446;


    __quex_assert_no_passage();
_285:
    /* (RELOAD_FORWARD from 800)  */
    target_state_index = QUEX_LABEL(284); target_state_else_index = QUEX_LABEL(167);

    goto _446;

_448:
/* RETURN -- after executing 'on_after_match' code. */
    __QUEX_PURE_RETURN;


_449:
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


goto _450;

    __quex_assert_no_passage();

    /* Following labels are referenced in macros. It cannot be detected
     * whether the macros are applied in user code or not. To avoid compiler.
     * warnings of unused labels, they are referenced in unreachable code.   */
    goto _448; /* in RETURN                */
    goto _449; /* in CONTINUE              */
    goto _19; /* in CONTINUE and skippers */
#   if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
    goto _451; /* in QUEX_GOTO_STATE       */
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


