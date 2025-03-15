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
        std::cout << " \"" << elem << "\"";
    }
    std::cout << "\n";
}

int
main()
{
    std::list<std::string> src{"don't", "vote", "for", "liars"};

    // move all elements from the list to the vector:
    std::vector<std::string> vec{std::make_move_iterator(src.begin()), std::make_move_iterator(src.end())};

    print("src", src);
    print("vec", vec);
}
