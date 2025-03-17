#include "person.hpp"
#include <print>
#include <vector>

int
main()
{
    std::vector<Person> coll{"Wolfgang Amadeus Mozart", // COPY
                             "Johann Sebastian Bach",   // COPY
                             "Ludwig van Beethoven"};   // COPY

    std::println("capacity: {}", coll.capacity());      // capacity: 3

    coll.push_back("Pjotr Iljitsch Tschaikowski");      // MOVE
                                                        // COPY
                                                        // COPY
                                                        // COPY
}
