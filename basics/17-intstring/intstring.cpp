#include "intstring.hpp"
#include <print>

int
main()
{
    IntString is1{42};
    IntString is2;
    std::println("is1 and is2 before move:");
    is1.dump();
    is2.dump();

    is2 = std::move(is1);

    std::println("is1 and is2 after move:");
    is1.dump();
    is2.dump();
}
