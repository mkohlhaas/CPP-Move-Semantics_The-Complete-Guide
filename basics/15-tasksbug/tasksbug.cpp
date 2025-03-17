#include "tasksbug.hpp"
#include <chrono>
#include <exception>
#include <print>

int
main()
{
    try
    {
        Tasks ts;
        ts.start([] {
            std::this_thread::sleep_for(std::chrono::seconds{2});
            std::println("t1 done");
        });
        ts.start([] { std::println("t2 done"); });

        // OOPS: move tasks
        Tasks other{std::move(ts)};
    }
    catch (const std::exception &e)
    {
        std::println("EXCEPTION: {}", e.what());
    }
}
