#include "customerimpl.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int
main()
{
    std::vector<Customer> coll;
    // coll.reserve(100);
    for (int i = 0; i < 12; ++i)
    {
        coll.push_back(Customer{"TestCustomer " + std::to_string(i - 5)});
    }

    std::cout << "\n==== sort =================================\n\n";
    std::sort(coll.begin(),                                                                        //
              coll.end(),                                                                          //
              [](const Customer &c1, const Customer &c2) { return c1.getName() < c2.getName(); }); //
}
