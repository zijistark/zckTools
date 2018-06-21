/* -*- C++ -*- vim: set syntax=cpp: */
#ifndef __QUEX_INCLUDE_GUARD__EXTRA__POST_CATEGORIZER__POST_CATEGORIZER_I
#define __QUEX_INCLUDE_GUARD__EXTRA__POST_CATEGORIZER__POST_CATEGORIZER_I

#include <quex/code_base/MemoryManager>
#include <quex/code_base/extra/post_categorizer/PostCategorizer>
#include <quex/code_base/lexeme>

QUEX_NAMESPACE_MAIN_OPEN

QUEX_INLINE void
QUEX_NAME(PostCategorizer__enter)(QUEX_NAME(Dictionary)*    me, 
                                  const QUEX_TYPE_LEXATOM*  EntryName, 
                                  QUEX_TYPE_TOKEN_ID        TokenID);
                          
QUEX_INLINE void          
QUEX_NAME(PostCategorizer__insert)(QUEX_NAME(Dictionary)*    me, 
                                   const QUEX_TYPE_LEXATOM*  EntryName, 
                                   QUEX_TYPE_TOKEN_ID        TokenID);
                          
QUEX_INLINE QUEX_TYPE_TOKEN_ID 
QUEX_NAME(PostCategorizer__get_token_id)(const QUEX_NAME(Dictionary)*  me,
                                         const QUEX_TYPE_LEXATOM*      Lexeme);

QUEX_INLINE void          
QUEX_NAME(PostCategorizer__remove)(QUEX_NAME(Dictionary)*    me, 
                                   const QUEX_TYPE_LEXATOM*  EntryName);
                          
QUEX_INLINE void          
QUEX_NAME(PostCategorizer__clear)(QUEX_NAME(Dictionary)* me);
                          
QUEX_INLINE void          
QUEX_NAME(PostCategorizer__clear_recursively)(QUEX_NAME(Dictionary)*      me, 
                                              QUEX_NAME(DictionaryNode)*  branch);
QUEX_INLINE int           
QUEX_NAME(PostCategorizer__compare)(QUEX_NAME(DictionaryNode)*  me, 
                                    QUEX_TYPE_LEXATOM           FirstCharacter, 
                                    const QUEX_TYPE_LEXATOM*    Remainder);

QUEX_INLINE QUEX_NAME(DictionaryNode)*  
QUEX_NAME(PostCategorizer__allocate_node)(const QUEX_TYPE_LEXATOM* Remainder);

QUEX_INLINE void 
QUEX_NAME(PostCategorizer__free_node)(QUEX_NAME(DictionaryNode)* node);

QUEX_INLINE QUEX_NAME(DictionaryNode)*
QUEX_NAME(PostCategorizer__find)(const QUEX_NAME(Dictionary)* me, 
                                 const QUEX_TYPE_LEXATOM*     EntryName);



QUEX_INLINE  QUEX_NAME(DictionaryNode)*  
QUEX_NAME(PostCategorizer__allocate_node)(const QUEX_TYPE_LEXATOM* Remainder)
{
    const size_t  RemainderL = QUEX_NAME_TOKEN(lexeme_length)(Remainder);
    /* Allocate in one beat: base and remainder: 
     *
     *   [Base   |Remainder             ]
     *
     * Then bend the base->name_remainder to the Remainder part of the allocated
     * memory. Note, that this is not very efficient, since one should try to allocate
     * the small node objects and refer to the remainder only when necessary. This
     * would reduce cache misses.                                                      */
    const size_t   BaseSize      = sizeof(QUEX_NAME(DictionaryNode));
    /* Length + 1 == memory size (terminating zero) */
    const size_t   RemainderSize = sizeof(QUEX_TYPE_LEXATOM) * (RemainderL + 1);
    uint8_t*       base          = 
                      (uint8_t*)
                      QUEXED(MemoryManager_allocate)(BaseSize + RemainderSize, 
                                                     E_MemoryObjectType_POST_CATEGORIZER_NODE);
    ((QUEX_NAME(DictionaryNode)*)base)->name_remainder = (const QUEX_TYPE_LEXATOM*)(base + BaseSize);
    return (QUEX_NAME(DictionaryNode)*)base;
}

QUEX_INLINE  void 
QUEX_NAME(PostCategorizer__free_node)(QUEX_NAME(DictionaryNode)* node)
{ 
    if( ! node ) return;
    
    QUEXED(MemoryManager_free)((void*)node, 
                               E_MemoryObjectType_POST_CATEGORIZER_NODE); 
}

QUEX_INLINE QUEX_NAME(DictionaryNode)* 
QUEX_NAME(DictionaryNode_new)(QUEX_TYPE_LEXATOM         FirstCharacter,
                              const QUEX_TYPE_LEXATOM*  Remainder,
                              QUEX_TYPE_TOKEN_ID        TokenID)
{
    QUEX_NAME(DictionaryNode)* me = QUEX_NAME(PostCategorizer__allocate_node)(Remainder);

    me->name_first_character = FirstCharacter;
    me->name_remainder       = Remainder;
    me->token_id             = TokenID;
    me->lesser               = 0x0;
    me->greater              = 0x0;

    return me;
}

QUEX_INLINE bool
QUEX_NAME(PostCategorizer_construct)(QUEX_NAME(Dictionary)* me)
{
    me->root = 0x0;
#   ifdef __QUEX_OPTION_PLAIN_C
    me->enter         = QUEX_NAME(PostCategorizer__enter);
    me->remove        = QUEX_NAME(PostCategorizer__remove);
    me->get_token_id  = QUEX_NAME(PostCategorizer__get_token_id);
    me->clear         = QUEX_NAME(PostCategorizer__clear);
    me->print_this    = QUEX_NAME(PostCategorizer_print_this);
    me->destruct_self = QUEX_NAME(PostCategorizer__clear);
#   endif
    return true;
}

QUEX_INLINE void
QUEX_NAME(PostCategorizer_destruct)(QUEX_NAME(Dictionary)* me)
{
    QUEX_NAME(PostCategorizer__clear)(me);
}

QUEX_INLINE int
QUEX_NAME(PostCategorizer__compare)(QUEX_NAME(DictionaryNode)* me, 
                                    QUEX_TYPE_LEXATOM          FirstCharacter, 
                                    const QUEX_TYPE_LEXATOM*   Remainder)
    /* Returns: '0'   if both strings are the same
       '< 0' string 0 < string 1
       '> 0' string 0 > string 1           */
{
    const QUEX_TYPE_LEXATOM* it0 = 0x0;
    const QUEX_TYPE_LEXATOM* it1 = 0x0;

    if     ( FirstCharacter > me->name_first_character ) return 1;
    else if( FirstCharacter < me->name_first_character ) return -1;
    else {
        /* Implementation according to: P.J. Plauger, "The Standard C Library", 1992 */
        it0 = Remainder;
        it1 = me->name_remainder;
        for(; *it0 == *it1; ++it0, ++it1) {
            /* Both letters are the same and == 0?
             * => both reach terminall zero without being different. */
            if( *it0 == 0 ) return 0;
        }
        return (int)(*it0) - (int)(*it1);
    }
}

QUEX_INLINE void
QUEX_NAME(PostCategorizer__enter)(QUEX_NAME(Dictionary)* me,
                                  const QUEX_TYPE_LEXATOM*  EntryName, 
                                  const QUEX_TYPE_TOKEN_ID    TokenID)
{
    QUEX_TYPE_LEXATOM           FirstCharacter = EntryName[0];
    const QUEX_TYPE_LEXATOM*    Remainder = FirstCharacter == 0x0 ? 0x0 : EntryName + 1;
    QUEX_NAME(DictionaryNode)*    node      = me->root;
    QUEX_NAME(DictionaryNode)*    prev_node = 0x0;
    int                           result = 0;

    if( me->root == 0x0 ) {
        me->root = QUEX_NAME(DictionaryNode_new)(FirstCharacter, Remainder, TokenID);
        return;
    }
    while( node != 0x0 ) {
        prev_node = node;
        result    = QUEX_NAME(PostCategorizer__compare)(node, FirstCharacter, Remainder);
        if     ( result > 0 ) node = node->greater;
        else if( result < 0 ) node = node->lesser;
        else                  return; /* Node with that name already exists */
    }
    __quex_assert( prev_node != 0x0 );
    __quex_assert( result != 0 );

    if( result > 0 ) 
        prev_node->greater = QUEX_NAME(DictionaryNode_new)(FirstCharacter, Remainder, TokenID);
    else 
        prev_node->lesser  = QUEX_NAME(DictionaryNode_new)(FirstCharacter, Remainder, TokenID);
}

QUEX_INLINE void
QUEX_NAME(PostCategorizer__remove)(QUEX_NAME(Dictionary)*  me,
                                   const QUEX_TYPE_LEXATOM*   EntryName)
{
    int                         result = 0;
    QUEX_TYPE_LEXATOM           FirstCharacter = EntryName[0];
    const QUEX_TYPE_LEXATOM*    Remainder = FirstCharacter == 0x0 ? 0x0 : EntryName + 1;
    QUEX_NAME(DictionaryNode)*  node   = 0x0;
    QUEX_NAME(DictionaryNode)*  parent = 0x0;
    QUEX_NAME(DictionaryNode)*  found  = me->root;

    __quex_assert( found != 0x0 );
    while( 1 + 1 == 2 ) {
        result = QUEX_NAME(PostCategorizer__compare)(found, FirstCharacter, Remainder);

        /* result == 0: found's name == EntryName 
         * On 'break': If found == root then parent = 0x0 which triggers a special treatment. */
        if( result == 0 ) break;

        parent = found;

        if     ( result > 0 )  found = found->greater;
        else if( result < 0 ) found = found->lesser;

        if( found == 0x0 ) return; /* Not found name with that name */
    };
    /* Found a node with 'EntryName' */

    /* Remove node and re-order tree */
    if( ! parent ) {
        if( found->lesser ) {
            for(node = found->lesser; node->greater != 0x0; node = node->greater );
            node->greater = found->greater;
            me->root      = found->lesser;
        } else {
            me->root      = found->greater;
        }
    }
    else if( found == parent->lesser ) {
        /* (1) 'found' is the 'lesser' child of the parent:
         *
         *                 (parent's greater tree)
         *                /
         *        (parent)        (greater tree)
         *               \       /
         *                (found)
         *                       \
         *                        (lesser tree)
         *
         *     All subnodes of (greater tree) are greater than all subnodes in (lesser tree).
         *     => (i) mount (lesser tree) to the least node of (greater tree).                
         *     Anything in the subtree of 'found' is lesser than anything in 'parent's 
         *     greater tree.
         *     => (ii) mount (greater tree) to the least node of the (parent's greater tree). */
        /* parent != 0x0, see above */
        if( found->greater ) {
            for(node = found->greater; node->lesser != 0x0; node = node->lesser );
            node->lesser   = found->lesser;
            parent->lesser = found->greater;
        } else {
            parent->lesser = found->lesser;
        }

    } else {
        /* (2) 'found' is the 'greater' child of the parent:
         *
         *     (i)  mount (greater tree) to the greatest node of (greater tree).                  
         *     (ii) mount (lesser tree) to the greatest node of the (parent's lesser tree). */
        /* parent != 0x0, see above */
        if( found->lesser ) {
            for(node = found->lesser; node->greater != 0x0; node = node->greater );
            node->greater   = found->greater;
            parent->greater = found->lesser;
        } else {
            parent->greater = found->greater;
        }
    }
    QUEX_NAME(PostCategorizer__free_node)(found);
}

QUEX_INLINE QUEX_NAME(DictionaryNode)*
QUEX_NAME(PostCategorizer__find)(const QUEX_NAME(Dictionary)*  me, 
                                 const QUEX_TYPE_LEXATOM*      EntryName)
{
    QUEX_TYPE_LEXATOM           FirstCharacter = EntryName[0];
    const QUEX_TYPE_LEXATOM*    Remainder      = FirstCharacter == 0x0 ? 0x0 : EntryName + 1;
    QUEX_NAME(DictionaryNode)*  node           = me->root;

    while( node != 0x0 ) {
        int result = QUEX_NAME(PostCategorizer__compare)(node, FirstCharacter, Remainder);

        if     ( result > 0 ) node = node->greater;
        else if( result < 0 ) node = node->lesser;
        else                  return node;
    }
    return 0x0;
}

QUEX_INLINE void
QUEX_NAME(PostCategorizer__clear_recursively)(QUEX_NAME(Dictionary)*      me, 
                                             QUEX_NAME(DictionaryNode)*  branch)
{
    __quex_assert(branch);

    if( branch->lesser )  QUEX_NAME(PostCategorizer__clear_recursively)(me, branch->lesser);
    if( branch->greater ) QUEX_NAME(PostCategorizer__clear_recursively)(me, branch->greater);
    QUEX_NAME(PostCategorizer__free_node)(branch);
}

QUEX_INLINE QUEX_TYPE_TOKEN_ID 
QUEX_NAME(PostCategorizer__get_token_id)(const QUEX_NAME(Dictionary)*  me,
                                         const QUEX_TYPE_LEXATOM*      Lexeme)
{
    QUEX_NAME(DictionaryNode)* found = QUEX_NAME(PostCategorizer__find)(me, Lexeme);
    if( ! found ) return QUEX_TOKEN_ID(UNINITIALIZED);
    return found->token_id;
}

QUEX_INLINE void
QUEX_NAME(PostCategorizer__clear)(QUEX_NAME(Dictionary)* me)
{
    if( ! me->root ) return;
    QUEX_NAME(PostCategorizer__clear_recursively)(me, me->root);
    me->root = (QUEX_NAME(DictionaryNode)*)0;
}

QUEX_INLINE void
QUEX_NAME(PostCategorizer_resources_absent_mark)(QUEX_NAME(Dictionary)* me)
{ 
    me->root = (QUEX_NAME(DictionaryNode)*)0;
}

QUEX_INLINE bool
QUEX_NAME(PostCategorizer_resources_absent)(QUEX_NAME(Dictionary)* me)
{ 
    return me->root == (QUEX_NAME(DictionaryNode)*)0;
}


QUEX_INLINE void
QUEX_NAME(PostCategorizer__print_tree)(QUEX_NAME(DictionaryNode)* node, int Depth)
{
    int i = 0;
    if( ! node ) {
        for(i=0; i<Depth; ++i) __QUEX_STD_printf("        ");
        __QUEX_STD_printf("[EMPTY]\n");
        return;
    }

    QUEX_NAME(PostCategorizer__print_tree)(node->greater, Depth + 1);

    for(i=0; i < Depth + 1; ++i) __QUEX_STD_printf("        ");
    __QUEX_STD_printf("/\n");

    for(i=0; i<Depth; ++i) __QUEX_STD_printf("        ");
    {
        uint8_t                    drain[256];
        uint8_t*                   drain_p     = &drain[0];
        uint8_t*                   remainder_p = (uint8_t*)0; 
        const QUEX_TYPE_LEXATOM* source_p     = &node->name_first_character;
        const QUEX_TYPE_LEXATOM* source_end_p = &source_p[1];

        /* Convert the first character                                       */
        QUEX_NAME_TOKEN(lexeme_to_utf8)(&source_p, source_end_p, &drain_p, &drain[256]);

        *drain_p++   = '\0';
        remainder_p  = drain_p;
        source_p     = node->name_remainder;
        source_end_p = source_p + QUEX_NAME_TOKEN(lexeme_length)(source_p) + 1;

        /* Convert the remainder                                             */
        QUEX_NAME_TOKEN(lexeme_to_utf8)(&source_p, source_end_p, &drain_p, &drain[256]);

        __QUEX_STD_printf("[%s]%s: %i\n", &drain[0], remainder_p, 
                          (int)node->token_id);
    }

    for(i=0; i<Depth + 1; ++i) __QUEX_STD_printf("        ");
    __QUEX_STD_printf("\\\n");

    QUEX_NAME(PostCategorizer__print_tree)(node->lesser, Depth + 1);
}

QUEX_INLINE void
QUEX_NAME(PostCategorizer_print_this)(QUEX_NAME(Dictionary)* me)
{
    QUEX_NAME(PostCategorizer__print_tree)(me->root, 0);
}


#ifndef __QUEX_OPTION_PLAIN_C
QUEX_INLINE 
QUEX_NAME(Dictionary)::QUEX_NAME(Dictionary)()
{ /* C/C++ Compability: Constructors/Destructors do nothing. */ }

QUEX_INLINE
QUEX_NAME(Dictionary)::~QUEX_NAME(Dictionary)()
{ /* C/C++ Compability: Constructors/Destructors do nothing. */ }

QUEX_INLINE void
QUEX_NAME(Dictionary)::clear()
{ QUEX_NAME(PostCategorizer__clear)(this); }

QUEX_INLINE QUEX_TYPE_TOKEN_ID 
QUEX_NAME(Dictionary)::get_token_id(const QUEX_TYPE_LEXATOM* Lexeme) const
{ return QUEX_NAME(PostCategorizer__get_token_id)(this, Lexeme); }

QUEX_INLINE void
QUEX_NAME(Dictionary)::remove(const QUEX_TYPE_LEXATOM* EntryName)
{ QUEX_NAME(PostCategorizer__remove)(this, EntryName); }

QUEX_INLINE void
QUEX_NAME(Dictionary)::enter(const QUEX_TYPE_LEXATOM*  EntryName, 
                             const QUEX_TYPE_TOKEN_ID    TokenID)
{ QUEX_NAME(PostCategorizer__enter)(this, EntryName, TokenID); }

QUEX_INLINE void
QUEX_NAME(Dictionary)::print_this()
{ QUEX_NAME(PostCategorizer_print_this)(this); }

#endif 

QUEX_NAMESPACE_MAIN_CLOSE

#endif /* __QUEX_INCLUDE_GUARD__EXTRA__POST_CATEGORIZER__POST_CATEGORIZER_I */
