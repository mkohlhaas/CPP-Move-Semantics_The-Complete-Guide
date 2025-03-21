#include "email.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int
main()
{
    std::vector<Email> coll{"tom@domain.de", "jill@company.com", "sarah@domain.de", "hana@company.com"};

    // remove all email addresses ending with ".de":
    auto newEnd = std::remove_if(coll.begin(), coll.end(), [](const Email &e) {
        auto &&val = e.getValue();
        return val.size() > 2 && val.substr(val.size() - 3) == ".de";
    });

    // print elements up to the new end:
    std::cout << "remaining elements:\n";
    for (auto pos = coll.begin(); pos != newEnd; ++pos)
    {
        std::cout << "  '" << *pos << "'\n";
    }

    // print all elements in the container:
    std::cout << "all elements:\n";
    for (const auto &elem : coll)
    {
        std::cout << "  '" << elem << "'\n";
    }
}
