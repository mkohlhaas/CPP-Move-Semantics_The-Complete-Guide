#include "tasksbug.hpp"
#include <chrono>
#include <exception>
#include <iostream>

int
main()
{
    try
    {
        Tasks ts;
        ts.start([] {
            std::this_thread::sleep_for(std::chrono::seconds{2});
            std::cout << "\nt1 done" << std::endl;
        });
        ts.start([] { std::cout << "\nt2 done" << std::endl; });

        // OOPS: move tasks:
        Tasks other{std::move(ts)};
    }
    catch (const std::exception &e)
    {
        std::cerr << "EXCEPTION: " << e.what() << std::endl;
    }
}
