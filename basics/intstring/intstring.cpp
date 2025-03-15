#include "intstring.hpp"
#include <iostream>

int
main()
{
    IntString is1{42};
    IntString is2;
    std::cout << "is1 and is2 before move:\n";
    is1.dump();
    is2.dump();

    is2 = std::move(is1);

    std::cout << "is1 and is2 after move:\n";
    is1.dump();
    is2.dump();
}
