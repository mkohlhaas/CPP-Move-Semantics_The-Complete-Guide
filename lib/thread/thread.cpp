#include <iostream>
#include <thread>
#include <vector>

void
doThis(const std::string &arg)
{
    std::cout << "doThis(): " << arg << '\n';
}
void
doThat(const std::string &arg)
{
    std::cout << "doThat(): " << arg << '\n';
}

int
main()
{
    std::vector<std::thread> threads; // better std::jthread since C++20

    // start a couple of threads:
    std::string someArg{"Black Lives Matter"};
    threads.push_back(std::thread{doThis, someArg});
    threads.push_back(std::thread{doThat, std::move(someArg)});
    //...

    // wait for all threads to end:
    for (auto &t : threads)
    {
        t.join();
    }
}
