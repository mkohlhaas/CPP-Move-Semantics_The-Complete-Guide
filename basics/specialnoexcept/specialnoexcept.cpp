#include <iostream>
#include <type_traits>

class B
{
    std::string s;
};

int
main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_nothrow_default_constructible<B>::value << '\n';
    std::cout << std::is_nothrow_copy_constructible<B>::value << '\n';
    std::cout << std::is_nothrow_move_constructible<B>::value << '\n';
    std::cout << std::is_nothrow_copy_assignable<B>::value << '\n';
    std::cout << std::is_nothrow_move_assignable<B>::value << '\n';
}
