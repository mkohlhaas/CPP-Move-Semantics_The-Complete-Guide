#include <print>
#include <type_traits>

class B
{
    std::string s;
};

int
main()
{
    std::println("{}", std::is_nothrow_default_constructible<B>::value); // true
    std::println("{}", std::is_nothrow_move_constructible<B>::value);    // true
    std::println("{}", std::is_nothrow_move_assignable<B>::value);       // true

    std::println("{}", std::is_nothrow_copy_assignable<B>::value);       // false
    std::println("{}", std::is_nothrow_copy_constructible<B>::value);    // false
}
