#ifndef ZCK_TRACER_H
#define ZCK_TRACER_H

#include <cassert>
#include <cstdio>
#include <utility>

#include "fmt/format.h"


NAMESPACE_ZCK;


template<bool IsEnabled = true>
struct Tracer {

  constexpr Tracer(FILE* out = stderr)
    : _M_indent("  ")
    , _M_level(0)
    , _M_file(out) {}

  template<size_t IndentStringSize>
  constexpr Tracer(const char(&str)[IndentStringSize], FILE* out = stderr)
    : _M_indent(str)
    , _M_level(0)
    , _M_file(out)
  {
    static_assert(IndentStringSize >= 1, "This constructor requires a C-string literal.");
  }

  template<typename... Args>
  void trace(const char* const format, Args&& ...args)
  {
    if constexpr (IsEnabled)
    {
      for (unsigned int u = 0; u < _M_level; ++u)
        fputs(_M_indent, _M_file);

      fmt::print(_M_file, format, std::forward<Args>(args)...);
      fputc('\n', _M_file);
      fflush(_M_file);
    }
  }

  void push() noexcept
  {
    if constexpr (IsEnabled)
    {
      ++_M_level;
    }
  }

  void pop() noexcept
  {
    if constexpr (IsEnabled)
    {
      assert(_M_level > 0);
      --_M_level;
    }
  }

  template<typename... Args>
  void push(const char* const format, Args&& ...args)
  {
    if constexpr (IsEnabled)
    {
      trace(format, std::forward<Args>(args)...);
      push();
    }
  }

  template<typename... Args>
  void pop(const char* const format, Args&& ...args)
  {
    if constexpr (IsEnabled)
    {
      pop();
      trace(format, std::forward<Args>(args)...);
    }
  }

private:
  const char* const _M_indent;
  unsigned int      _M_level;
  FILE*             _M_file;
};


NAMESPACE_ZCK_END;
#endif
