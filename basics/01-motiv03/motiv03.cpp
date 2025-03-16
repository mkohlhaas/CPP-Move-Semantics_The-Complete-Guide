#include <print>
#include <string>
#include <vector>

using vec_strings = std::vector<std::string>;

vec_strings
createAndInsert()
{
    using std::string;

    vec_strings coll;      // create vector of strings
    coll.reserve(3);       // reserve memory for 3 elements
    string s = "data";     // create string object

    coll.push_back(s);     // insert string object
    coll.push_back(s + s); // insert temporary string
    coll.push_back(s);     // insert string

    return coll;           // return vector of strings; NRVO (Named Return Value Optimization)
}

int
main()
{
    vec_strings v; // create empty vector of strings

    //...
    v = createAndInsert(); // assign returned vector of strings
    //...

    int i{};
    for (auto s : v)
    {
        std::println("{} - {}", ++i, s);
    }
}
