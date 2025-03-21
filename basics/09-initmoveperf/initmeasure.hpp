#pragma once

#include "initmove.hpp"
#include <chrono>

// measure num initializations of whatever is currently defined as Person:
inline std::chrono::nanoseconds
measure(int num)
{
    std::chrono::nanoseconds totalDur{0};
    for (int i = 0; i < num; ++i)
    {
        std::string fname = "a firstname a bit too long for SSO";
        std::string lname = "a lastname a bit too long for SSO";

        // measure how long it takes to create 3 Persons in different ways:
        auto   t0 = std::chrono::steady_clock::now();
        Person p1{"a firstname a bit too long for SSO", "a lastname a bit too long for SSO"};
        Person p2{fname, lname};
        Person p3{std::move(fname), std::move(lname)};
        auto   t1 = std::chrono::steady_clock::now();
        totalDur += t1 - t0;
    }
    return totalDur;
}
