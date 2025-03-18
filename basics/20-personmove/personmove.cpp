#include "personmove.hpp"
#include <print>
#include <vector>

int
main()
{

    // Solution: Use move semantics on reallocation only when the move constructor of the
    // element types guarantees not to throw.

    std::vector<Person> coll{"Wolfgang Amadeus Mozart", // COPY
                             "Johann Sebastian Bach",   // COPY
                             "Ludwig van Beethoven"};   // COPY

    std::println("capacity: {}", coll.capacity());      // capacity: 3
    coll.push_back("Pjotr Iljitsch Tschaikowski");      // MOVE
                                                        // MOVE
                                                        // MOVE
                                                        // MOVE
}
