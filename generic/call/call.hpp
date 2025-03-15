#include <utility> // for forward<>()

template <typename Func, typename... Args>
decltype(auto)
call(Func f, Args &&...args)
{
    //...
    return f(std::forward<Args>(args)...);
}
