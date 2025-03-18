#include <chrono>
#include <print>
#include <string>
#include <vector>

#define NOEXCEPT noexcept
// #define NOEXCEPT

// string wrapper with move constructor:
struct Str
{
    std::string val;

    // ensure each string has 100 characters:
    Str() : val(100, 'a') // don't use braces here
    {
    }

    // enable copy
    Str(const Str &) = default;

    // enable move (with and without noexcept):
    Str(Str &&s) NOEXCEPT : val{std::move(s.val)}
    {
    }
};

int
main()
{
    // create vector of 1 Million wrapped strings:
    std::vector<Str> coll;
    coll.resize(1000000);

    // measure time to reallocate memory for all elements:
    auto t0 = std::chrono::steady_clock::now();
    coll.reserve(coll.capacity() + 1);
    auto t1 = std::chrono::steady_clock::now();

    std::chrono::duration<double, std::milli> d{t1 - t0};
    std::println("{}ms", d.count());
}
