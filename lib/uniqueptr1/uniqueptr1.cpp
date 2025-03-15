#include <iostream>
#include <memory>
#include <string>

std::unique_ptr<std::string>
source()
{
    static long id{0};

    // create string with new and let ptr own it:
    auto ptr = std::make_unique<std::string>("obj" + std::to_string(++id));
    //...
    return ptr; // transfer ownership to caller
}

int
main()
{
    std::unique_ptr<std::string> p;
    for (int i = 0; i < 10; ++i)
    {
        p = source(); // p gets ownership of the returned object
                      // (previously returned object of source() is deleted)
        std::cout << *p << '\n';
        //...
    }
} // last-owned object of p is deleted
