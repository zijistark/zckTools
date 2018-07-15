/* vim: set ft=c:
 * (C) Frank-Rene Schaefer */
#ifndef  __QUEX_INCLUDE_GUARD__BUFFER__BYTES__BYTE_LOADER_WSTREAM_I
#define  __QUEX_INCLUDE_GUARD__BUFFER__BYTES__BYTE_LOADER_WSTREAM_I

#if ! defined(__QUEX_OPTION_PLAIN_C) && defined(__QUEX_OPTION_WCHAR_T)

#include <fstream>
#include <sstream>

QUEX_NAMESPACE_MAIN_OPEN

QUEX_INLINE void                       QUEX_NAME(ByteLoader_wstream_construct)(QUEX_NAME(ByteLoader_wstream)* me, 
                                                                               std::wistream*                 sh);
QUEX_INLINE QUEX_TYPE_STREAM_POSITION  QUEX_NAME(ByteLoader_wstream_tell)(QUEX_NAME(ByteLoader)* me);
QUEX_INLINE void                       QUEX_NAME(ByteLoader_wstream_seek)(QUEX_NAME(ByteLoader)* me, 
                                                                          QUEX_TYPE_STREAM_POSITION Pos);
QUEX_INLINE size_t                     QUEX_NAME(ByteLoader_wstream_load)(QUEX_NAME(ByteLoader)* me, 
                                                                          void*                  buffer, 
                                                                          const size_t           ByteN, 
                                                                          bool*                  end_of_stream_f);
QUEX_INLINE void                       QUEX_NAME(ByteLoader_wstream_delete_self)(QUEX_NAME(ByteLoader)* me);
QUEX_INLINE void                       QUEX_NAME(ByteLoader_wstream_print_this)(QUEX_NAME(ByteLoader)* me);
QUEX_INLINE bool                       QUEX_NAME(ByteLoader_wstream_compare_handle)(const QUEX_NAME(ByteLoader)* alter_ego_A, 
                                                                                    const QUEX_NAME(ByteLoader)* alter_ego_B);

QUEX_INLINE QUEX_NAME(ByteLoader)*
QUEX_NAME(ByteLoader_wstream_new)(std::wistream* sh)
{
    QUEX_NAME(ByteLoader_wstream)* me;

    if( ! sh ) return (QUEX_NAME(ByteLoader)*)0;

    me = (QUEX_NAME(ByteLoader_wstream)*)QUEXED(MemoryManager_allocate)(sizeof(QUEX_NAME(ByteLoader_wstream)),
                                                                       E_MemoryObjectType_BYTE_LOADER);

    if( ! me ) return (QUEX_NAME(ByteLoader)*)0;

    QUEX_NAME(ByteLoader_wstream_construct)(me, sh);
    return &me->base;
}

QUEX_INLINE QUEX_NAME(ByteLoader)*    
QUEX_NAME(ByteLoader_wstream_new_from_file_name)(const char* FileName)
{
    std::wifstream*        sh = new std::wifstream(FileName, std::ios_base::binary | std::ios::in);
    QUEX_NAME(ByteLoader)* alter_ego;

    if( ! sh || ! *sh ) {
        return (QUEX_NAME(ByteLoader)*)0;
    }
    alter_ego = QUEX_NAME(ByteLoader_wstream_new)(sh);
    if( ! alter_ego ) {
        return (QUEX_NAME(ByteLoader)*)0;
    }

    /* ByteLoader from file name *must* be owned by lexical analyzer, 
     * to ensure automatic closure and deletion.                              */
    alter_ego->handle_ownership = E_Ownership_LEXICAL_ANALYZER;
    return alter_ego;
}

QUEX_INLINE void
QUEX_NAME(ByteLoader_wstream_construct)(QUEX_NAME(ByteLoader_wstream)* me, 
                                        std::wistream*                 sh)
{
    /* IMPORTANT: input_handle must be set BEFORE call to constructor!
     *            Constructor does call 'tell()'                             */
    me->input_handle = sh;

    QUEX_NAME(ByteLoader_construct)(&me->base,
                         QUEX_NAME(ByteLoader_wstream_tell),
                         QUEX_NAME(ByteLoader_wstream_seek),
                         QUEX_NAME(ByteLoader_wstream_load),
                         QUEX_NAME(ByteLoader_wstream_delete_self),
                         QUEX_NAME(ByteLoader_wstream_print_this),
                         QUEX_NAME(ByteLoader_wstream_compare_handle));
    me->base.element_size = sizeof(wchar_t);
}

QUEX_INLINE void
QUEX_NAME(ByteLoader_wstream_delete_self)(QUEX_NAME(ByteLoader)* alter_ego)
{
    QUEX_NAME(ByteLoader_wstream)* me = (QUEX_NAME(ByteLoader_wstream)*)alter_ego;

    if( me->input_handle && me->base.handle_ownership == E_Ownership_LEXICAL_ANALYZER ) {
        delete me->input_handle;
    }
    QUEXED(MemoryManager_free)(me, E_MemoryObjectType_BYTE_LOADER);
}

/* The 'char_type' of a stream determines the atomic size of elements which are
 * read from the stream. It is unrelated to QUEX_TYPE_LEXATOM which
 * determines the size of a buffer element.                                  */
QUEX_INLINE QUEX_TYPE_STREAM_POSITION    
QUEX_NAME(ByteLoader_wstream_tell)(QUEX_NAME(ByteLoader)* alter_ego)            
{ 
    QUEX_NAME(ByteLoader_wstream)*    me       = (QUEX_NAME(ByteLoader_wstream)*)alter_ego;
    const QUEX_TYPE_STREAM_POSITION   CharSize = sizeof(wchar_t);
    std::streampos                    Position = me->input_handle->tellg();

    return (QUEX_TYPE_STREAM_POSITION)(Position * CharSize); 
}

QUEX_INLINE void    
QUEX_NAME(ByteLoader_wstream_seek)(QUEX_NAME(ByteLoader)*    alter_ego, 
                                  QUEX_TYPE_STREAM_POSITION Pos) 
{ 
    QUEX_NAME(ByteLoader_wstream)*    me       = (QUEX_NAME(ByteLoader_wstream)*)alter_ego;
    const QUEX_TYPE_STREAM_POSITION   CharSize = sizeof(wchar_t);
    std::streampos                    Target   = (std::streampos)(Pos / CharSize);

    me->input_handle->clear();                    /* Clear any iostate flag. */
    me->input_handle->seekg(Target); 
}

QUEX_INLINE size_t  
QUEX_NAME(ByteLoader_wstream_load)(QUEX_NAME(ByteLoader)*  alter_ego, 
                                  void*        buffer, 
                                  const size_t ByteN, 
                                  bool*        end_of_stream_f) 
{ 
    QUEX_NAME(ByteLoader_wstream)*    me = (QUEX_NAME(ByteLoader_wstream)*)alter_ego;
    const QUEX_TYPE_STREAM_POSITION   CharSize = sizeof(wchar_t);
    if( ! ByteN ) return (size_t)0;

    me->input_handle->read((wchar_t*)buffer, (std::streamsize)(ByteN / CharSize)); 

    const size_t loaded_char_n = (size_t)(me->input_handle->gcount());

    *end_of_stream_f = me->input_handle->eof();

    if( (! *end_of_stream_f) && me->input_handle->fail() ) {
        throw std::runtime_error("Fatal error during stream reading.");
    }

    /* std::fprintf(stdout, "tell 1 = %i, loaded_char_n = %i\n", (long)(me->input_handle->tellg()), loaded_char_n);*/
    return (size_t)(loaded_char_n * CharSize);
}

QUEX_INLINE bool  
QUEX_NAME(ByteLoader_wstream_compare_handle)(const QUEX_NAME(ByteLoader)* alter_ego_A, 
                                            const QUEX_NAME(ByteLoader)* alter_ego_B) 
/* RETURNS: true  -- if A and B point to the same std::wistream object.
 *          false -- else.                                                   */
{ 
    const QUEX_NAME(ByteLoader_wstream)* A = (QUEX_NAME(ByteLoader_wstream)*)(alter_ego_A);
    const QUEX_NAME(ByteLoader_wstream)* B = (QUEX_NAME(ByteLoader_wstream)*)(alter_ego_B);

    return A->input_handle == B->input_handle;
}

QUEX_INLINE void
QUEX_NAME(ByteLoader_wstream_print_this)(QUEX_NAME(ByteLoader)* alter_ego)
{
    QUEX_NAME(ByteLoader_wstream)*   me = (QUEX_NAME(ByteLoader_wstream)*)alter_ego;

    __QUEX_STD_printf("        stream:           ((%p));\n", (const void*)me->input_handle);
    __QUEX_STD_printf("        type:             wistream;\n");
    __QUEX_STD_printf("        stream:           ((%p));\n", (const void*)me->input_handle);
    if( me->input_handle ) {
        __QUEX_STD_printf("        end_of_stream:    %s;\n", E_Boolean_NAME(me->input_handle->eof()));
    }
}
QUEX_NAMESPACE_MAIN_CLOSE

#endif /* __QUEX_OPTION_PLAIN_C                                               */
#endif /*  __QUEX_INCLUDE_GUARD__BUFFER__BYTES__BYTE_LOADER_WSTREAM_I         */

