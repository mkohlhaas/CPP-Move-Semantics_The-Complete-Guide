#include "initmeasure.hpp"
#include <iostream>

int
main(int argc, const char **argv)
{
    int num_iterations{1000};

    if (argc > 1)
    {
        num_iterations = std::atoi(argv[1]);
    }

    measure(5); // a few iterations to avoid measuring initial behavior

    using namespace std::chrono;
    nanoseconds                  ns_dur{measure(num_iterations)};
    duration<double, std::milli> ms_dur{ns_dur};

    std::cout << num_iterations << " iterations take:  " << ms_dur.count() << "ms\n";
    std::cout << "3 inits take on average:  " << ns_dur.count() / num_iterations << "ns\n";
}
