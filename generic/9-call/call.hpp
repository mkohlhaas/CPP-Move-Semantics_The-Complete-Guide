#include <utility>

// Perfect Returning with decltype(auto)

// `decltype(auto)` yields exactly what we need for perfect returning:
// - for a plain value, we deduce a value, and
// - for a reference, we deduce a reference of the same type and value category.

template <typename Func, typename... Args>
decltype(auto)
call(Func f, Args &&...args)
{
    return f(std::forward<Args>(args)...);
}
