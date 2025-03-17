#include "persondefault.hpp"
#include <print>
#include <vector>

int
main()
{
    std::vector<Person> coll{"Wolfgang Amadeus Mozart", // COPY
                             "Johann Sebastian Bach",   // COPY
                             "Ludwig van Beethoven"};   // COPY

    std::println("capacity: {}", coll.capacity());      // capacity: 3
    coll.push_back("Pjotr Iljitsch Tschaikowski");      // move operations are taking place

    std::println("{}", coll[0].getName());              // Wolfgang Amadeus Mozart
    std::println("{}", coll[1].getName());              // Johann Sebastian Bach
    std::println("{}", coll[2].getName());              // Ludwig van Beethoven
    std::println("{}", coll[3].getName());              // Pjotr Iljitsch Tschaikowski
}
