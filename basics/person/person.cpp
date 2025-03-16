#include "person.hpp"
#include <iostream>
#include <vector>

int
main()
{
    std::vector<Person> coll{"Wolfgang Amadeus Mozart", //
                             "Johann Sebastian Bach",   //
                             "Ludwig van Beethoven"};   //

    std::cout << "capacity: " << coll.capacity() << '\n';
    coll.push_back("Pjotr Iljitsch Tschaikowski");

    // auto p = Person();
    // auto p = Person{"Ludwig van Beethoven"};
}
