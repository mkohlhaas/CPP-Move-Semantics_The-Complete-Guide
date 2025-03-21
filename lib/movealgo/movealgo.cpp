#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T>
void
print(const std::string &name, const T &coll)
{
    std::cout << name << " (" << coll.size() << " elems): ";
    for (const auto &elem : coll)
    {
        std::cout << " '" << elem << "'";
    }
    std::cout << "\n";
}

int
main(int argc, char **argv)
{
    std::list<std::string>   coll1{"love", "is", "all", "you", "need"};
    std::vector<std::string> coll2;

    // ensure coll2 has enough elements to overwrite their values:
    coll2.resize(coll1.size());

    // print out size and values:
    print("coll1", coll1);
    print("coll2", coll2);

    // move assign the values from coll1 to coll2
    // - not changing any size
    std::move(coll1.begin(), coll1.end(), // source range
              coll2.begin());             // destination range

    // print out size and values:
    print("coll1", coll1);
    print("coll2", coll2);

    // move assign the first three values inside coll2 to the end
    // - not changing any size
    std::move_backward(coll2.begin(), coll2.begin() + 3, // source range
                       coll2.end());                     // destination range

    // print out size and values:
    print("coll1", coll1);
    print("coll2", coll2);
}
