#include "persondefault.hpp"
#include <iostream>
#include <vector>

int
main()
{
    std::vector<Person> coll{"Wolfgang Amadeus Mozart", "Johann Sebastian Bach", "Ludwig van Beethoven"};
    std::cout << "capacity: " << coll.capacity() << '\n';
    coll.push_back("Pjotr Iljitsch Tschaikowski");

    std::cout << "name of coll[0]: " << coll[0].getName() << '\n';
}
