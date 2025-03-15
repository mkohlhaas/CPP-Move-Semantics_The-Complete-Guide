#include <algorithm>
#include <iostream>
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

void
process(std::string s) // gets moved value from rvalues
{
    std::cout << "- process(" << s << ")\n";
    //...
}

int
main()
{
    std::vector<std::string> coll{"don't", "vote", "for", "liars"};
    print("coll", coll);

    // move away only the elements processed:
    std::for_each(std::make_move_iterator(coll.begin()), std::make_move_iterator(coll.end()), [](auto &&elem) {
        if (elem.size() != 4)
        {
            process(std::move(elem));
        }
    });

    print("coll", coll);
}
