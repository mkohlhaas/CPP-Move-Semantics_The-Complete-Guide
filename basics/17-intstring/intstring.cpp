#include "intstring.hpp"
#include <print>

int
main()
{
    IntString is1{42};
    IntString is2;

    std::println("is1 and is2 before move:");
    is1.print();
    is2.print();

    std::println("is1 and is2 after move:");
    is2 = std::move(is1);
    is1.print();
    is2.print();
}
