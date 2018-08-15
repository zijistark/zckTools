#ifndef ZCK_TRACER_H
#define ZCK_TRACER_H

#include <cassert>
#include <cstdio>
#include <string>
#include <string_view>
#include <utility>

#include "fmt/format.h"


NAMESPACE_ZCK;


template<typename TracerT>
struct ScopeTracer
{
  template<typename... Args>
  constexpr ScopeTracer(TracerT& tracer, std::string_view format, Args&& ...args)
    : _M_tracer( tracer )
    , _M_msg( fmt::format(format, std::forward<Args>(args)...) )
  {
    _M_tracer.push("{} {{", _M_msg);
  }

  ~ScopeTracer() noexcept
  {
    _M_tracer.pop("}} // END: {}", _M_msg);
  }

private:
  TracerT&          _M_tracer;
  const std::string _M_msg;
};


struct NullTracer
{
  template<size_t N> constexpr NullTracer(const char(&str)[N], FILE* out = nullptr) {}
  constexpr NullTracer(FILE* out = nullptr) {}
  constexpr void indent() const noexcept {}
  constexpr void dedent() const noexcept {}
  template<typename... Args> constexpr void trace(std::string_view format, Args&& ...args) const noexcept {}
  template<typename... Args> constexpr void push(std::string_view format, Args&& ...args) const noexcept {}
  template<typename... Args> constexpr void pop(std::string_view format, Args&& ...args) const noexcept {}
};


struct Tracer
{
  constexpr Tracer(FILE* out = stderr)
    : _M_indent(" ")
    , _M_level(0)
    , _M_file(out) {}

  template<size_t N>
  constexpr Tracer(const char(&str)[N], FILE* out = stderr)
    : _M_indent(str)
    , _M_level(0)
    , _M_file(out)
  {
    static_assert(N >= 1, "This constructor requires a C-string literal.");
  }

  template<typename... Args>
  void trace(std::string_view format, Args&& ...args)
  {
    for (unsigned int u = 0; u < _M_level; ++u)
      fputs(_M_indent, _M_file);

    /*
    if (_M_level)
      fmt::print(_M_file, "{}: ", _M_level + 1);
    */

    fmt::print(_M_file, format, std::forward<Args>(args)...);
    fputc('\n', _M_file);
    fflush(_M_file);
  }

  void indent() noexcept { ++_M_level; }
  void dedent() noexcept { --_M_level; }

  template<typename... Args>
  void push(std::string_view format, Args&& ...args)
  {
    trace(format, std::forward<Args>(args)...);
    indent();
  }

  template<typename... Args>
  void pop(std::string_view format, Args&& ...args)
  {
    dedent();
    trace(format, std::forward<Args>(args)...);
  }

private:
  const char* const _M_indent;
  unsigned int      _M_level;
  FILE*             _M_file;
};


NAMESPACE_ZCK_END;
#endif
