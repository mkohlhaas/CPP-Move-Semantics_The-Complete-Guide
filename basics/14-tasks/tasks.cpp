#include "tasks.hpp"
#include <chrono>
#include <print>

int
main()
{
    Tasks ts;

    ts.start([] {
        std::this_thread::sleep_for(std::chrono::seconds{2});
        std::println("t1 done");
    });

    ts.start([] { std::println("t2 done"); });
}
