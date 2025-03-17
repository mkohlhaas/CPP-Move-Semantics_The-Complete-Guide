#include "sharedint.hpp"
#include <print>

int
main()
{
    SharedInt si1{42};
    SharedInt si2{si1};
    std::println("{}", si1.asString()); // 42
    std::println("{}", si2.asString()); // 42

    SharedInt si3{42};
    SharedInt si4{std::move(si3)};
    std::println("{}", si3.asString()); // 0 (or crash)
    std::println("{}", si4.asString()); // 42
}
