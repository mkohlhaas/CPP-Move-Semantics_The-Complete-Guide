#include "person.hpp"
#include <print>
#include <vector>

int
main()
{
    // Problem: lots of copies!!!
    //
    // The reason that vector reallocation does not use move semantics is the STRONG EXCEPTION HANDLING GUARANTEE
    // we give for push_back(): When an exception is thrown in the middle of the reallocation of the vector the
    // C++ standard library guarantees to roll back the vector to its previous state. That is, push_back() gives a
    // kind of a transactional guarantee: either it succeeds or it has no effect.

    std::vector<Person> coll{"Wolfgang Amadeus Mozart", // COPY
                             "Johann Sebastian Bach",   // COPY
                             "Ludwig van Beethoven"};   // COPY

    std::println("capacity: {}", coll.capacity());      // capacity: 3

    coll.push_back("Pjotr Iljitsch Tschaikowski");      // MOVE
                                                        // COPY
                                                        // COPY
                                                        // COPY
}
