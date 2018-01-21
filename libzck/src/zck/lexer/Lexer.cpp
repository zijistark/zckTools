
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

    /* (709 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_14:
    __quex_debug("Init State\n");
    __quex_debug_state(709);
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
    /* (709 from 713)  */
    goto _14;


    __quex_assert_no_passage();
_8:
    /* (DROP_OUT from 712)  */
    goto _13;
_15:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_6:
    /* (DROP_OUT from 710)  */
    goto _11;


    __quex_assert_no_passage();
_7:
    /* (DROP_OUT from 711)  */
    goto _12;


    __quex_assert_no_passage();
_5:
    /* (DROP_OUT from 709)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _16;
    goto _15;


    __quex_assert_no_passage();
_4:
    /* (712 from 709)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(712);
goto _8;


    __quex_assert_no_passage();
_2:
    /* (710 from 709)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(710);
goto _6;


    __quex_assert_no_passage();
_3:
    /* (711 from 709)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(711);
goto _7;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_10:
    __quex_debug("* TERMINAL <LOOP EXIT>\n");
    --(me->buffer._read_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p)));

goto _0;

_11:
    __quex_debug("* TERMINAL <LOOP 199>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_12:
    __quex_debug("* TERMINAL <LOOP 200>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

if( me->buffer._read_p != LexemeEnd ) goto _9;

goto _0;

_13:
    __quex_debug("* TERMINAL <LOOP 201>\n");
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
    /* (649 from RELOAD_FORWARD) (649 from BEFORE_ENTRY)  */

    input = *(me->buffer._read_p);


    __quex_debug("Init State\n");
    __quex_debug_state(649);
switch( input ) {
case 0x0: goto _160;
case 0x1: goto _138;
case 0x9: goto _81;
case 0xA: goto _96;
case 0xD: 
case 0x20: goto _83;
case 0x21: goto _94;
case 0x22: goto _91;
case 0x23: goto _86;
case 0x2B: goto _95;
case 0x2D: goto _88;
case 0x2E: goto _80;
case 0x30: goto _92;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _84;
case 0x3C: goto _85;
case 0x3D: goto _89;
case 0x3E: goto _87;
case 0x62: goto _97;
case 0x63: goto _90;
case 0x64: case 0x65: 
case 0x6B: goto _97;
case 0x7B: goto _82;
case 0x7D: goto _98;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _93;
}


    __quex_assert_no_passage();
_138:
    /* (DROP_OUT from 679) (DROP_OUT from 661) (DROP_OUT from 682) (DROP_OUT from 673) (DROP_OUT from 686) (DROP_OUT from 683) (DROP_OUT from 677) (DROP_OUT from 680) (DROP_OUT from 674) (DROP_OUT from 649) (DROP_OUT from 687) (DROP_OUT from 684) (DROP_OUT from 678) (DROP_OUT from 681) (DROP_OUT from 688) (DROP_OUT from 675)  */

        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _78;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_139:
    /* (DROP_OUT from 667) (DROP_OUT from 689) (DROP_OUT from 664) (DROP_OUT from 658) (DROP_OUT from 702) (DROP_OUT from 699) (DROP_OUT from 665) (DROP_OUT from 700) (DROP_OUT from 669) (DROP_OUT from 697) (DROP_OUT from 663) (DROP_OUT from 660) (DROP_OUT from 650) (DROP_OUT from 695) (DROP_OUT from 670) (DROP_OUT from 698)  */
    goto _74;


    __quex_assert_no_passage();
_140:
    /* (DROP_OUT from 651)  */
    goto _38;


    __quex_assert_no_passage();
_141:
    /* (DROP_OUT from 652)  */
    goto _65;


    __quex_assert_no_passage();
_142:
    /* (DROP_OUT from 653)  */
    goto _39;


    __quex_assert_no_passage();
_143:
    /* (DROP_OUT from 654) (DROP_OUT from 707) (DROP_OUT from 662) (DROP_OUT from 694) (DROP_OUT from 706)  */
    goto _67;


    __quex_assert_no_passage();
_144:
    /* (DROP_OUT from 655)  */
    goto _62;


    __quex_assert_no_passage();
_145:
    /* (DROP_OUT from 656)  */
    goto _57;


    __quex_assert_no_passage();
_146:
    /* (DROP_OUT from 657)  */
    goto _64;


    __quex_assert_no_passage();
_147:
    /* (DROP_OUT from 659)  */
    goto _60;


    __quex_assert_no_passage();
_148:
    /* (DROP_OUT from 666)  */
    goto _37;


    __quex_assert_no_passage();
_149:
    /* (DROP_OUT from 668)  */
    goto _66;


    __quex_assert_no_passage();
_150:
    /* (DROP_OUT from 671)  */
    goto _73;


    __quex_assert_no_passage();
_151:
    /* (DROP_OUT from 672)  */
    goto _59;


    __quex_assert_no_passage();
_152:
    /* (DROP_OUT from 676)  */
    goto _71;


    __quex_assert_no_passage();
_153:
    /* (DROP_OUT from 685)  */
    goto _70;


    __quex_assert_no_passage();
_154:
    /* (DROP_OUT from 690)  */
    goto _72;


    __quex_assert_no_passage();
_155:
    /* (DROP_OUT from 691)  */
    goto _58;


    __quex_assert_no_passage();
_156:
    /* (DROP_OUT from 692)  */
    goto _63;


    __quex_assert_no_passage();
_157:
    /* (DROP_OUT from 693)  */
    goto _61;


    __quex_assert_no_passage();
_158:
    /* (DROP_OUT from 704) (DROP_OUT from 696) (DROP_OUT from 705)  */
    goto _68;


    __quex_assert_no_passage();
_159:
    /* (DROP_OUT from 703) (DROP_OUT from 701)  */
    goto _69;


    __quex_assert_no_passage();
_80:
    /* (650 from 665) (650 from 662) (650 from 649) (650 from 658)  */

    ++(me->buffer._read_p);

_259:
    input = *(me->buffer._read_p);


    __quex_debug_state(650);
switch( input ) {
case 0x0: goto _162;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _139;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _135;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_161:
    /* (650 from RELOAD_FORWARD)  */
    goto _259;


    __quex_assert_no_passage();
_81:
    /* (651 from 649)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(651);
goto _140;


    __quex_assert_no_passage();
_82:
    /* (652 from 649)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(652);
goto _141;


    __quex_assert_no_passage();
_83:
    /* (653 from 649)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(653);
goto _142;


    __quex_assert_no_passage();
_84:
    /* (654 from 649) (654 from 658)  */

    ++(me->buffer._read_p);

_265:
    input = *(me->buffer._read_p);


    __quex_debug_state(654);
switch( input ) {
case 0x0: goto _164;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _143;
case 0x2E: goto _125;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _124;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _143;
default: goto _93;
}


    __quex_assert_no_passage();
_163:
    /* (654 from RELOAD_FORWARD)  */
    goto _265;


    __quex_assert_no_passage();
_85:
    /* (655 from 649)  */
    ++(me->buffer._read_p);

_267:
    input = *(me->buffer._read_p);


    __quex_debug_state(655);
if     ( input == 0x3D )  goto _123;
else if( input == 0x0 )   goto _166;
else                      goto _144;


    __quex_assert_no_passage();
_165:
    /* (655 from RELOAD_FORWARD)  */
    goto _267;


    __quex_assert_no_passage();
_86:
    /* (656 from 649)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(656);
goto _145;


    __quex_assert_no_passage();
_167:
    /* (657 from RELOAD_FORWARD)  */
_270:
    input = *(me->buffer._read_p);


    __quex_debug_state(657);
if     ( input == 0x3D )  goto _122;
else if( input == 0x0 )   goto _168;
else                      goto _146;


    __quex_assert_no_passage();
_87:
    /* (657 from 649)  */
    ++(me->buffer._read_p);

    goto _270;


    __quex_assert_no_passage();
_169:
    /* (658 from RELOAD_FORWARD)  */
_272:
    input = *(me->buffer._read_p);


    __quex_debug_state(658);
switch( input ) {
case 0x0: goto _170;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _139;
case 0x2E: goto _80;
case 0x30: goto _92;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _84;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_88:
    /* (658 from 649)  */
    ++(me->buffer._read_p);

    goto _272;


    __quex_assert_no_passage();
_89:
    /* (659 from 649)  */
    ++(me->buffer._read_p);

_274:
    input = *(me->buffer._read_p);


    __quex_debug_state(659);
if     ( input == 0x3D )  goto _121;
else if( input == 0x0 )   goto _172;
else                      goto _147;


    __quex_assert_no_passage();
_171:
    /* (659 from RELOAD_FORWARD)  */
    goto _274;


    __quex_assert_no_passage();
_173:
    /* (660 from RELOAD_FORWARD)  */
_276:
    input = *(me->buffer._read_p);


    __quex_debug_state(660);
switch( input ) {
case 0x0: goto _174;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _139;
case 0x5F: goto _119;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_90:
    /* (660 from 649)  */
    ++(me->buffer._read_p);

    goto _276;


    __quex_assert_no_passage();
_175:
    /* (661 from RELOAD_FORWARD)  */
_278:
    input = *(me->buffer._read_p);


    __quex_debug_state(661);
switch( input ) {
case 0x0: goto _176;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _106;
case 0x2D: goto _103;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _105;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _104;
}


    __quex_assert_no_passage();
_91:
    /* (661 from 649)  */
    ++(me->buffer._read_p);

    goto _278;


    __quex_assert_no_passage();
_92:
    /* (662 from 665) (662 from 658) (662 from 649) (662 from 707) (662 from 662)  */

    ++(me->buffer._read_p);

_281:
    input = *(me->buffer._read_p);


    __quex_debug_state(662);
switch( input ) {
case 0x0: goto _178;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _143;
case 0x2E: goto _80;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _92;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _143;
default: goto _93;
}


    __quex_assert_no_passage();
_177:
    /* (662 from RELOAD_FORWARD)  */
    goto _281;


    __quex_assert_no_passage();
_93:
    /* (663 from 706) (663 from 665) (663 from 650) (663 from 696) (663 from 705) (663 from 690) (663 from 649) (663 from 662) (663 from 703) (663 from 689) (663 from 664) (663 from 658) (663 from 699) (663 from 704) (663 from 671) (663 from 702) (663 from 660) (663 from 701) (663 from 695) (663 from 667) (663 from 698) (663 from 707) (663 from 670) (663 from 697) (663 from 669) (663 from 654) (663 from 663) (663 from 700) (663 from 694)  */

    ++(me->buffer._read_p);

_284:
    input = *(me->buffer._read_p);


    __quex_debug_state(663);
switch( input ) {
case 0x0: goto _180;
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
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_179:
    /* (663 from RELOAD_FORWARD)  */
    goto _284;


    __quex_assert_no_passage();
_94:
    /* (664 from 649)  */
    ++(me->buffer._read_p);

_286:
    input = *(me->buffer._read_p);


    __quex_debug_state(664);
switch( input ) {
case 0x0: goto _182;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: goto _139;
case 0x3D: goto _102;
case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_181:
    /* (664 from RELOAD_FORWARD)  */
    goto _286;


    __quex_assert_no_passage();
_183:
    /* (665 from RELOAD_FORWARD)  */
_288:
    input = *(me->buffer._read_p);


    __quex_debug_state(665);
switch( input ) {
case 0x0: goto _184;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _139;
case 0x2E: goto _80;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _92;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_95:
    /* (665 from 649)  */
    ++(me->buffer._read_p);

    goto _288;


    __quex_assert_no_passage();
_96:
    /* (666 from 649)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(666);
goto _148;


    __quex_assert_no_passage();
_97:
    /* (667 from 649)  */
    ++(me->buffer._read_p);

_291:
    input = *(me->buffer._read_p);


    __quex_debug_state(667);
switch( input ) {
case 0x0: goto _186;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _139;
case 0x5F: goto _99;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_185:
    /* (667 from RELOAD_FORWARD)  */
    goto _291;


    __quex_assert_no_passage();
_98:
    /* (668 from 649)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(668);
goto _149;


    __quex_assert_no_passage();
_187:
    /* (669 from RELOAD_FORWARD)  */
_294:
    input = *(me->buffer._read_p);


    __quex_debug_state(669);
switch( input ) {
case 0x0: goto _188;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: 
case 0x3C: case 0x3D: case 0x3E: goto _139;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _100;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_99:
    /* (669 from 667)  */
    ++(me->buffer._read_p);

    goto _294;


    __quex_assert_no_passage();
_100:
    /* (670 from 689) (670 from 669)  */

    ++(me->buffer._read_p);

_297:
    input = *(me->buffer._read_p);


    __quex_debug_state(670);
switch( input ) {
case 0x0: goto _190;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _139;
case 0x2D: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _101;
case 0x3C: case 0x3D: case 0x3E: goto _139;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _101;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_189:
    /* (670 from RELOAD_FORWARD)  */
    goto _297;


    __quex_assert_no_passage();
_101:
    /* (671 from 670) (671 from 671)  */

    ++(me->buffer._read_p);

_300:
    input = *(me->buffer._read_p);


    __quex_debug_state(671);
switch( input ) {
case 0x0: goto _192;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _150;
case 0x2D: 
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _101;
case 0x3C: case 0x3D: case 0x3E: goto _150;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _101;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _150;
default: goto _93;
}


    __quex_assert_no_passage();
_191:
    /* (671 from RELOAD_FORWARD)  */
    goto _300;


    __quex_assert_no_passage();
_102:
    /* (672 from 664)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(672);
goto _151;


    __quex_assert_no_passage();
_193:
    /* (673 from RELOAD_FORWARD)  */
_303:
    input = *(me->buffer._read_p);


    __quex_debug_state(673);
switch( input ) {
case 0x0: goto _194;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _106;
case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _105;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _104;
}


    __quex_assert_no_passage();
_103:
    /* (673 from 661)  */
    ++(me->buffer._read_p);

    goto _303;


    __quex_assert_no_passage();
_104:
    /* (674 from 687) (674 from 673) (674 from 680) (674 from 677) (674 from 684) (674 from 681) (674 from 688) (674 from 674) (674 from 678) (674 from 675) (674 from 682) (674 from 661) (674 from 679) (674 from 686) (674 from 683)  */

    ++(me->buffer._read_p);

_306:
    input = *(me->buffer._read_p);


    __quex_debug_state(674);
switch( input ) {
case 0x0: goto _196;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _106;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _104;
}


    __quex_assert_no_passage();
_195:
    /* (674 from RELOAD_FORWARD)  */
    goto _306;


    __quex_assert_no_passage();
_105:
    /* (675 from 673) (675 from 661)  */

    ++(me->buffer._read_p);

_309:
    input = *(me->buffer._read_p);


    __quex_debug_state(675);
switch( input ) {
case 0x0: goto _198;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _106;
case 0x2E: goto _108;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _107;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _104;
}


    __quex_assert_no_passage();
_197:
    /* (675 from RELOAD_FORWARD)  */
    goto _309;


    __quex_assert_no_passage();
_106:
    /* (676 from 679) (676 from 661) (676 from 684) (676 from 681) (676 from 682) (676 from 673) (676 from 677) (676 from 674) (676 from 688) (676 from 687) (676 from 678) (676 from 675) (676 from 680)  */

    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(676);
goto _152;


    __quex_assert_no_passage();
_199:
    /* (677 from RELOAD_FORWARD)  */
_313:
    input = *(me->buffer._read_p);


    __quex_debug_state(677);
switch( input ) {
case 0x0: goto _200;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _106;
case 0x2E: goto _108;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _117;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _104;
}


    __quex_assert_no_passage();
_107:
    /* (677 from 675)  */
    ++(me->buffer._read_p);

    goto _313;


    __quex_assert_no_passage();
_108:
    /* (678 from 688) (678 from 675) (678 from 677) (678 from 687)  */

    ++(me->buffer._read_p);

_316:
    input = *(me->buffer._read_p);


    __quex_debug_state(678);
switch( input ) {
case 0x0: goto _202;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _106;
case 0x2D: goto _109;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _110;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _104;
}


    __quex_assert_no_passage();
_201:
    /* (678 from RELOAD_FORWARD)  */
    goto _316;


    __quex_assert_no_passage();
_109:
    /* (679 from 678)  */
    ++(me->buffer._read_p);

_318:
    input = *(me->buffer._read_p);


    __quex_debug_state(679);
switch( input ) {
case 0x0: goto _204;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _106;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _110;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _104;
}


    __quex_assert_no_passage();
_203:
    /* (679 from RELOAD_FORWARD)  */
    goto _318;


    __quex_assert_no_passage();
_110:
    /* (680 from 679) (680 from 678)  */

    ++(me->buffer._read_p);

_321:
    input = *(me->buffer._read_p);


    __quex_debug_state(680);
switch( input ) {
case 0x0: goto _206;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _106;
case 0x2E: goto _112;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _111;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _104;
}


    __quex_assert_no_passage();
_205:
    /* (680 from RELOAD_FORWARD)  */
    goto _321;


    __quex_assert_no_passage();
_207:
    /* (681 from RELOAD_FORWARD)  */
_323:
    input = *(me->buffer._read_p);


    __quex_debug_state(681);
switch( input ) {
case 0x0: goto _208;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _106;
case 0x2E: goto _112;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _104;
}


    __quex_assert_no_passage();
_111:
    /* (681 from 680)  */
    ++(me->buffer._read_p);

    goto _323;


    __quex_assert_no_passage();
_112:
    /* (682 from 681) (682 from 680)  */

    ++(me->buffer._read_p);

_326:
    input = *(me->buffer._read_p);


    __quex_debug_state(682);
switch( input ) {
case 0x0: goto _210;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _106;
case 0x2D: goto _114;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _113;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _104;
}


    __quex_assert_no_passage();
_209:
    /* (682 from RELOAD_FORWARD)  */
    goto _326;


    __quex_assert_no_passage();
_113:
    /* (683 from 682) (683 from 684)  */

    ++(me->buffer._read_p);

_329:
    input = *(me->buffer._read_p);


    __quex_debug_state(683);
switch( input ) {
case 0x0: goto _212;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _115;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _116;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _104;
}


    __quex_assert_no_passage();
_211:
    /* (683 from RELOAD_FORWARD)  */
    goto _329;


    __quex_assert_no_passage();
_114:
    /* (684 from 682)  */
    ++(me->buffer._read_p);

_331:
    input = *(me->buffer._read_p);


    __quex_debug_state(684);
switch( input ) {
case 0x0: goto _214;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _106;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _113;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _104;
}


    __quex_assert_no_passage();
_213:
    /* (684 from RELOAD_FORWARD)  */
    goto _331;


    __quex_assert_no_passage();
_115:
    /* (685 from 686) (685 from 683)  */

    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(685);
goto _153;


    __quex_assert_no_passage();
_215:
    /* (686 from RELOAD_FORWARD)  */
_335:
    input = *(me->buffer._read_p);


    __quex_debug_state(686);
switch( input ) {
case 0x0: goto _216;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _115;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _104;
}


    __quex_assert_no_passage();
_116:
    /* (686 from 683)  */
    ++(me->buffer._read_p);

    goto _335;


    __quex_assert_no_passage();
_217:
    /* (687 from RELOAD_FORWARD)  */
_337:
    input = *(me->buffer._read_p);


    __quex_debug_state(687);
switch( input ) {
case 0x0: goto _218;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _106;
case 0x2E: goto _108;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _118;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _104;
}


    __quex_assert_no_passage();
_117:
    /* (687 from 677)  */
    ++(me->buffer._read_p);

    goto _337;


    __quex_assert_no_passage();
_118:
    /* (688 from 687)  */
    ++(me->buffer._read_p);

_339:
    input = *(me->buffer._read_p);


    __quex_debug_state(688);
switch( input ) {
case 0x0: goto _220;
case 0x1: 
case 0xA: 
case 0xD: goto _138;
case 0x22: goto _106;
case 0x2E: goto _108;
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _138;
default: goto _104;
}


    __quex_assert_no_passage();
_219:
    /* (688 from RELOAD_FORWARD)  */
    goto _339;


    __quex_assert_no_passage();
_119:
    /* (689 from 660)  */
    ++(me->buffer._read_p);

_341:
    input = *(me->buffer._read_p);


    __quex_debug_state(689);
switch( input ) {
case 0x0: goto _222;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _139;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _120;
case 0x3C: case 0x3D: case 0x3E: goto _139;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _100;
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_221:
    /* (689 from RELOAD_FORWARD)  */
    goto _341;


    __quex_assert_no_passage();
_120:
    /* (690 from 689) (690 from 690)  */

    ++(me->buffer._read_p);

_344:
    input = *(me->buffer._read_p);


    __quex_debug_state(690);
switch( input ) {
case 0x0: goto _224;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _154;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _120;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _154;
default: goto _93;
}


    __quex_assert_no_passage();
_223:
    /* (690 from RELOAD_FORWARD)  */
    goto _344;


    __quex_assert_no_passage();
_121:
    /* (691 from 659)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(691);
goto _155;


    __quex_assert_no_passage();
_122:
    /* (692 from 657)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(692);
goto _156;


    __quex_assert_no_passage();
_123:
    /* (693 from 655)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(693);
goto _157;


    __quex_assert_no_passage();
_124:
    /* (694 from 654)  */
    ++(me->buffer._read_p);

_349:
    input = *(me->buffer._read_p);


    __quex_debug_state(694);
switch( input ) {
case 0x0: goto _226;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _143;
case 0x2E: goto _125;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _136;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _143;
default: goto _93;
}


    __quex_assert_no_passage();
_225:
    /* (694 from RELOAD_FORWARD)  */
    goto _349;


    __quex_assert_no_passage();
_125:
    /* (695 from 694) (695 from 654) (695 from 706) (695 from 707)  */

    ++(me->buffer._read_p);

_352:
    input = *(me->buffer._read_p);


    __quex_debug_state(695);
switch( input ) {
case 0x0: goto _228;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _139;
case 0x2D: goto _127;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _126;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_227:
    /* (695 from RELOAD_FORWARD)  */
    goto _352;


    __quex_assert_no_passage();
_126:
    /* (696 from 695)  */
    ++(me->buffer._read_p);

_354:
    input = *(me->buffer._read_p);


    __quex_debug_state(696);
switch( input ) {
case 0x0: goto _230;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _158;
case 0x2E: goto _129;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _134;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _158;
default: goto _93;
}


    __quex_assert_no_passage();
_229:
    /* (696 from RELOAD_FORWARD)  */
    goto _354;


    __quex_assert_no_passage();
_231:
    /* (697 from RELOAD_FORWARD)  */
_356:
    input = *(me->buffer._read_p);


    __quex_debug_state(697);
switch( input ) {
case 0x0: goto _232;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _139;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _128;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_127:
    /* (697 from 695)  */
    ++(me->buffer._read_p);

    goto _356;


    __quex_assert_no_passage();
_233:
    /* (698 from RELOAD_FORWARD)  */
_358:
    input = *(me->buffer._read_p);


    __quex_debug_state(698);
switch( input ) {
case 0x0: goto _234;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _139;
case 0x2E: goto _129;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _130;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_128:
    /* (698 from 697)  */
    ++(me->buffer._read_p);

    goto _358;


    __quex_assert_no_passage();
_129:
    /* (699 from 698) (699 from 696) (699 from 704) (699 from 700)  */

    ++(me->buffer._read_p);

_361:
    input = *(me->buffer._read_p);


    __quex_debug_state(699);
switch( input ) {
case 0x0: goto _236;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _139;
case 0x2D: goto _132;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _131;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_235:
    /* (699 from RELOAD_FORWARD)  */
    goto _361;


    __quex_assert_no_passage();
_130:
    /* (700 from 698)  */
    ++(me->buffer._read_p);

_363:
    input = *(me->buffer._read_p);


    __quex_debug_state(700);
switch( input ) {
case 0x0: goto _238;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _139;
case 0x2E: goto _129;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_237:
    /* (700 from RELOAD_FORWARD)  */
    goto _363;


    __quex_assert_no_passage();
_131:
    /* (701 from 702) (701 from 699)  */

    ++(me->buffer._read_p);

_366:
    input = *(me->buffer._read_p);


    __quex_debug_state(701);
switch( input ) {
case 0x0: goto _240;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _159;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _133;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _159;
default: goto _93;
}


    __quex_assert_no_passage();
_239:
    /* (701 from RELOAD_FORWARD)  */
    goto _366;


    __quex_assert_no_passage();
_132:
    /* (702 from 699)  */
    ++(me->buffer._read_p);

_368:
    input = *(me->buffer._read_p);


    __quex_debug_state(702);
switch( input ) {
case 0x0: goto _242;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _139;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _131;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _139;
default: goto _93;
}


    __quex_assert_no_passage();
_241:
    /* (702 from RELOAD_FORWARD)  */
    goto _368;


    __quex_assert_no_passage();
_133:
    /* (703 from 701)  */
    ++(me->buffer._read_p);

_370:
    input = *(me->buffer._read_p);


    __quex_debug_state(703);
switch( input ) {
case 0x0: goto _244;
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
case 0x9D: goto _159;
default: goto _93;
}


    __quex_assert_no_passage();
_243:
    /* (703 from RELOAD_FORWARD)  */
    goto _370;


    __quex_assert_no_passage();
_134:
    /* (704 from 696)  */
    ++(me->buffer._read_p);

_372:
    input = *(me->buffer._read_p);


    __quex_debug_state(704);
switch( input ) {
case 0x0: goto _246;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _158;
case 0x2E: goto _129;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _135;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _158;
default: goto _93;
}


    __quex_assert_no_passage();
_245:
    /* (704 from RELOAD_FORWARD)  */
    goto _372;


    __quex_assert_no_passage();
_135:
    /* (705 from 704) (705 from 705) (705 from 650)  */

    ++(me->buffer._read_p);

_375:
    input = *(me->buffer._read_p);


    __quex_debug_state(705);
switch( input ) {
case 0x0: goto _248;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _158;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _135;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _158;
default: goto _93;
}


    __quex_assert_no_passage();
_247:
    /* (705 from RELOAD_FORWARD)  */
    goto _375;


    __quex_assert_no_passage();
_249:
    /* (706 from RELOAD_FORWARD)  */
_377:
    input = *(me->buffer._read_p);


    __quex_debug_state(706);
switch( input ) {
case 0x0: goto _250;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _143;
case 0x2E: goto _125;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _137;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _143;
default: goto _93;
}


    __quex_assert_no_passage();
_136:
    /* (706 from 694)  */
    ++(me->buffer._read_p);

    goto _377;


    __quex_assert_no_passage();
_137:
    /* (707 from 706)  */
    ++(me->buffer._read_p);

_379:
    input = *(me->buffer._read_p);


    __quex_debug_state(707);
switch( input ) {
case 0x0: goto _252;
case 0x1: 
case 0x9: case 0xA: 
case 0xD: 
case 0x20: 
case 0x22: case 0x23: goto _143;
case 0x2E: goto _125;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _92;
case 0x3C: case 0x3D: case 0x3E: 
case 0x7B: 
case 0x7D: 
case 0x81: 
case 0x8D: 
case 0x8F: case 0x90: 
case 0x9D: goto _143;
default: goto _93;
}


    __quex_assert_no_passage();
_251:
    /* (707 from RELOAD_FORWARD)  */
    goto _379;
_18:
    /* (398 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

_381:
__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_380:
    __quex_debug("Init State\n");
    __quex_debug_state(398);
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
    /* (398 from 404)  */
    goto _380;


    __quex_assert_no_passage();
_28:
    /* (398 from RELOAD_FORWARD)  */
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

    goto _381;


    __quex_assert_no_passage();
_23:
    /* (DROP_OUT from 398)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _78;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_24:
    /* (DROP_OUT from 399)  */
    goto _33;


    __quex_assert_no_passage();
_25:
    /* (DROP_OUT from 400)  */
    goto _34;


    __quex_assert_no_passage();
_26:
    /* (DROP_OUT from 401)  */
    goto _35;


    __quex_assert_no_passage();
_27:
    /* (DROP_OUT from 402)  */
    goto _32;


    __quex_assert_no_passage();
_20:
    /* (400 from 398)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(400);
goto _25;


    __quex_assert_no_passage();
_21:
    /* (401 from 398)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(401);
goto _26;


    __quex_assert_no_passage();
_22:
    /* (402 from 398)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(402);
goto _27;


    __quex_assert_no_passage();
_19:
    /* (399 from 398)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(399);
goto _24;
_41:
    /* (431 from BEFORE_ENTRY)  */
    __QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

_388:
__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

    input = *(me->buffer._read_p);

_387:
    __quex_debug("Init State\n");
    __quex_debug_state(431);
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
    /* (431 from 435)  */
    goto _387;


    __quex_assert_no_passage();
_49:
    /* (431 from RELOAD_FORWARD)  */
    (me->buffer._lexeme_start_p) = (me->buffer._read_p);

    goto _388;


    __quex_assert_no_passage();
_47:
    /* (DROP_OUT from 433)  */
    goto _55;
_389:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_46:
    /* (DROP_OUT from 432)  */
    goto _54;


    __quex_assert_no_passage();
_48:
    /* (DROP_OUT from 434)  */
    goto _56;


    __quex_assert_no_passage();
_45:
    /* (DROP_OUT from 431)  */
        me->buffer._read_p = me->buffer._lexeme_start_p + 1;
goto _78;
    goto _389;


    __quex_assert_no_passage();
_42:
    /* (432 from 431)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(432);
goto _46;


    __quex_assert_no_passage();
_43:
    /* (433 from 431)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(433);
goto _47;


    __quex_assert_no_passage();
_44:
    /* (434 from 431)  */
    ++(me->buffer._read_p);

    input = *(me->buffer._read_p);


    __quex_debug_state(434);
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

#   line 71 "zck.qx"
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

#   line 72 "zck.qx"
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
    __quex_debug("* TERMINAL <LOOP 120>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _31;

_34:
    __quex_debug("* TERMINAL <LOOP 121>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _31;

_35:
    __quex_debug("* TERMINAL <LOOP 122>\n");
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
    __quex_debug("* TERMINAL <COUPLE 135>\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _53;

_55:
    __quex_debug("* TERMINAL <LOOP 136>\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._read_p) - count_reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(count_reference_p = (me->buffer._read_p));

goto _51;

_56:
    __quex_debug("* TERMINAL <LOOP 137>\n");
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

#   line 73 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_OP_DEQ);

__QUEX_PURE_RETURN;


#   line 2755 "Lexer.cpp"

}
RETURN;
_59:
    __quex_debug("* TERMINAL \"!=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 74 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_OP_NEQ);

__QUEX_PURE_RETURN;


#   line 2772 "Lexer.cpp"

}
RETURN;
_60:
    __quex_debug("* TERMINAL \"=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 75 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_OP_EQ);

__QUEX_PURE_RETURN;


#   line 2789 "Lexer.cpp"

}
RETURN;
_61:
    __quex_debug("* TERMINAL \"<=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 76 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_OP_LTEQ);

__QUEX_PURE_RETURN;


#   line 2806 "Lexer.cpp"

}
RETURN;
_62:
    __quex_debug("* TERMINAL \"<\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 77 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_OP_LT);

__QUEX_PURE_RETURN;


#   line 2823 "Lexer.cpp"

}
RETURN;
_63:
    __quex_debug("* TERMINAL \">=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{

#   line 78 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_OP_GTEQ);

__QUEX_PURE_RETURN;


#   line 2840 "Lexer.cpp"

}
RETURN;
_64:
    __quex_debug("* TERMINAL \">\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 79 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_OP_GT);

__QUEX_PURE_RETURN;


#   line 2857 "Lexer.cpp"

}
RETURN;
_65:
    __quex_debug("* TERMINAL \"{\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 80 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_OPEN_BRACE);

__QUEX_PURE_RETURN;


#   line 2874 "Lexer.cpp"

}
RETURN;
_66:
    __quex_debug("* TERMINAL \"}\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{

#   line 81 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_CLOSE_BRACE);

__QUEX_PURE_RETURN;


#   line 2891 "Lexer.cpp"

}
RETURN;
_67:
    __quex_debug("* TERMINAL {SIGN}[0-9]+\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 82 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_INTEGER);

__QUEX_PURE_RETURN;


#   line 2908 "Lexer.cpp"

}
RETURN;
_68:
    __quex_debug("* TERMINAL {DECIMAL}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 83 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_DECIMAL);

__QUEX_PURE_RETURN;


#   line 2925 "Lexer.cpp"

}
RETURN;
_69:
    __quex_debug("* TERMINAL {DATE}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 84 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_DATE);

__QUEX_PURE_RETURN;


#   line 2942 "Lexer.cpp"

}
RETURN;
_70:
    __quex_debug("* TERMINAL \"\\\"\"{DATE}\"\\\"\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 85 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), LexemeBegin+1, LexemeEnd-1);
self_send(T_QDATE);

__QUEX_PURE_RETURN;


#   line 2959 "Lexer.cpp"

}
RETURN;
_71:
    __quex_debug("* TERMINAL {QSTRING}\n");
QUEX_FUNCTION_COUNT_ARBITRARY(&self, LexemeBegin, LexemeEnd);
{

#   line 86 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), LexemeBegin+1, LexemeEnd-1);
self_send(T_QSTRING);

__QUEX_PURE_RETURN;


#   line 2975 "Lexer.cpp"

}
RETURN;
_72:
    __quex_debug("* TERMINAL {CHAR_ID}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 87 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_CHAR_SCOPE);

__QUEX_PURE_RETURN;


#   line 2992 "Lexer.cpp"

}
RETURN;
_73:
    __quex_debug("* TERMINAL {TITLE_ID}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 88 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_TITLE_ID);

__QUEX_PURE_RETURN;


#   line 3009 "Lexer.cpp"

}
RETURN;
_74:
    __quex_debug("* TERMINAL {STRING}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(((size_t)(me->buffer._read_p - me->buffer._lexeme_start_p)));
{

#   line 89 "zck.qx"
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), me->buffer._lexeme_start_p, me->buffer._read_p);
self_send(T_STRING);

__QUEX_PURE_RETURN;


#   line 3026 "Lexer.cpp"

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
case 139: {
goto _139;}
case 143: {
goto _143;}
case 144: {
goto _144;}
case 146: {
goto _146;}
case 147: {
goto _147;}
case 150: {
goto _150;}
case 154: {
goto _154;}
case 158: {
goto _158;}
case 159: {
goto _159;}
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
    /* (RELOAD_FORWARD from 398)  */
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
    /* (RELOAD_FORWARD from 431)  */
    target_state_index = QUEX_LABEL(49); target_state_else_index = QUEX_LABEL(40);

    goto _394;


    __quex_assert_no_passage();
_160:
    /* (RELOAD_FORWARD from 649)  */
    target_state_index = QUEX_LABEL(79); target_state_else_index = QUEX_LABEL(29);

    goto _393;


    __quex_assert_no_passage();
_162:
    /* (RELOAD_FORWARD from 650)  */
    target_state_index = QUEX_LABEL(161); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_164:
    /* (RELOAD_FORWARD from 654)  */
    target_state_index = QUEX_LABEL(163); target_state_else_index = QUEX_LABEL(143);

    goto _393;


    __quex_assert_no_passage();
_166:
    /* (RELOAD_FORWARD from 655)  */
    target_state_index = QUEX_LABEL(165); target_state_else_index = QUEX_LABEL(144);

    goto _393;


    __quex_assert_no_passage();
_168:
    /* (RELOAD_FORWARD from 657)  */
    target_state_index = QUEX_LABEL(167); target_state_else_index = QUEX_LABEL(146);

    goto _393;


    __quex_assert_no_passage();
_170:
    /* (RELOAD_FORWARD from 658)  */
    target_state_index = QUEX_LABEL(169); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_172:
    /* (RELOAD_FORWARD from 659)  */
    target_state_index = QUEX_LABEL(171); target_state_else_index = QUEX_LABEL(147);

    goto _393;


    __quex_assert_no_passage();
_174:
    /* (RELOAD_FORWARD from 660)  */
    target_state_index = QUEX_LABEL(173); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_176:
    /* (RELOAD_FORWARD from 661)  */
    target_state_index = QUEX_LABEL(175); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_178:
    /* (RELOAD_FORWARD from 662)  */
    target_state_index = QUEX_LABEL(177); target_state_else_index = QUEX_LABEL(143);

    goto _393;


    __quex_assert_no_passage();
_180:
    /* (RELOAD_FORWARD from 663)  */
    target_state_index = QUEX_LABEL(179); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_182:
    /* (RELOAD_FORWARD from 664)  */
    target_state_index = QUEX_LABEL(181); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_184:
    /* (RELOAD_FORWARD from 665)  */
    target_state_index = QUEX_LABEL(183); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_186:
    /* (RELOAD_FORWARD from 667)  */
    target_state_index = QUEX_LABEL(185); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_188:
    /* (RELOAD_FORWARD from 669)  */
    target_state_index = QUEX_LABEL(187); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_190:
    /* (RELOAD_FORWARD from 670)  */
    target_state_index = QUEX_LABEL(189); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_192:
    /* (RELOAD_FORWARD from 671)  */
    target_state_index = QUEX_LABEL(191); target_state_else_index = QUEX_LABEL(150);

    goto _393;


    __quex_assert_no_passage();
_194:
    /* (RELOAD_FORWARD from 673)  */
    target_state_index = QUEX_LABEL(193); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_196:
    /* (RELOAD_FORWARD from 674)  */
    target_state_index = QUEX_LABEL(195); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_198:
    /* (RELOAD_FORWARD from 675)  */
    target_state_index = QUEX_LABEL(197); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_200:
    /* (RELOAD_FORWARD from 677)  */
    target_state_index = QUEX_LABEL(199); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_202:
    /* (RELOAD_FORWARD from 678)  */
    target_state_index = QUEX_LABEL(201); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_204:
    /* (RELOAD_FORWARD from 679)  */
    target_state_index = QUEX_LABEL(203); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_206:
    /* (RELOAD_FORWARD from 680)  */
    target_state_index = QUEX_LABEL(205); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_208:
    /* (RELOAD_FORWARD from 681)  */
    target_state_index = QUEX_LABEL(207); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_210:
    /* (RELOAD_FORWARD from 682)  */
    target_state_index = QUEX_LABEL(209); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_212:
    /* (RELOAD_FORWARD from 683)  */
    target_state_index = QUEX_LABEL(211); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_214:
    /* (RELOAD_FORWARD from 684)  */
    target_state_index = QUEX_LABEL(213); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_216:
    /* (RELOAD_FORWARD from 686)  */
    target_state_index = QUEX_LABEL(215); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_218:
    /* (RELOAD_FORWARD from 687)  */
    target_state_index = QUEX_LABEL(217); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_220:
    /* (RELOAD_FORWARD from 688)  */
    target_state_index = QUEX_LABEL(219); target_state_else_index = QUEX_LABEL(138);

    goto _393;


    __quex_assert_no_passage();
_222:
    /* (RELOAD_FORWARD from 689)  */
    target_state_index = QUEX_LABEL(221); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_224:
    /* (RELOAD_FORWARD from 690)  */
    target_state_index = QUEX_LABEL(223); target_state_else_index = QUEX_LABEL(154);

    goto _393;


    __quex_assert_no_passage();
_226:
    /* (RELOAD_FORWARD from 694)  */
    target_state_index = QUEX_LABEL(225); target_state_else_index = QUEX_LABEL(143);

    goto _393;


    __quex_assert_no_passage();
_228:
    /* (RELOAD_FORWARD from 695)  */
    target_state_index = QUEX_LABEL(227); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_230:
    /* (RELOAD_FORWARD from 696)  */
    target_state_index = QUEX_LABEL(229); target_state_else_index = QUEX_LABEL(158);

    goto _393;


    __quex_assert_no_passage();
_232:
    /* (RELOAD_FORWARD from 697)  */
    target_state_index = QUEX_LABEL(231); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_234:
    /* (RELOAD_FORWARD from 698)  */
    target_state_index = QUEX_LABEL(233); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_236:
    /* (RELOAD_FORWARD from 699)  */
    target_state_index = QUEX_LABEL(235); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_238:
    /* (RELOAD_FORWARD from 700)  */
    target_state_index = QUEX_LABEL(237); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_240:
    /* (RELOAD_FORWARD from 701)  */
    target_state_index = QUEX_LABEL(239); target_state_else_index = QUEX_LABEL(159);

    goto _393;


    __quex_assert_no_passage();
_242:
    /* (RELOAD_FORWARD from 702)  */
    target_state_index = QUEX_LABEL(241); target_state_else_index = QUEX_LABEL(139);

    goto _393;


    __quex_assert_no_passage();
_244:
    /* (RELOAD_FORWARD from 703)  */
    target_state_index = QUEX_LABEL(243); target_state_else_index = QUEX_LABEL(159);

    goto _393;


    __quex_assert_no_passage();
_246:
    /* (RELOAD_FORWARD from 704)  */
    target_state_index = QUEX_LABEL(245); target_state_else_index = QUEX_LABEL(158);

    goto _393;


    __quex_assert_no_passage();
_248:
    /* (RELOAD_FORWARD from 705)  */
    target_state_index = QUEX_LABEL(247); target_state_else_index = QUEX_LABEL(158);

    goto _393;


    __quex_assert_no_passage();
_250:
    /* (RELOAD_FORWARD from 706)  */
    target_state_index = QUEX_LABEL(249); target_state_else_index = QUEX_LABEL(143);

    goto _393;


    __quex_assert_no_passage();
_252:
    /* (RELOAD_FORWARD from 707)  */
    target_state_index = QUEX_LABEL(251); target_state_else_index = QUEX_LABEL(143);

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


