#include <string>
#include <utility>
#include <vector>

// Rvalue References of Function Template Parameters

template <typename Coll>
void bar(Coll &&arg);

template <typename Coll>
void
foo(Coll &&arg) // arg is a universal reference
{
    // std::move doesn't make sense
    // bar(std::move(arg));

    // now it makes sense to use std::forward
    bar(std::forward<Coll>(arg));
}

int
main(int argc, char *argv[])
{
    using Coll = std::vector<std::string>;

    Coll       v;
    Coll const c;

    // universal reference takes everything
    foo(Coll{});
    foo(std::move(v));
    foo(v);
    foo(c);
    foo(std::move(c));
}
