#include "tasks.hpp"
#include <chrono>
#include <iostream>

int
main()
{
    Tasks ts;
    ts.start([] {
        std::this_thread::sleep_for(std::chrono::seconds{2});
        std::cout << "\nt1 done" << std::endl;
    });
    ts.start([] { std::cout << "\nt2 done" << std::endl; });
}
