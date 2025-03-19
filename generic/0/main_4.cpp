#include <string>
#include <vector>

// Rvalue References of Actual Types

using Coll = std::vector<std::string>;

void bar(Coll &&arg);

void
foo(Coll &&arg) // arg is non-const rvalue
{
    bar(std::move(arg));

    // Doesn't make sense semantically but possible bc it will just be std::move for rvalues.
    // bar(std::forward<Coll>(arg));
}

int
main(int argc, char *argv[])
{
    Coll       v;
    Coll const c;

    foo(Coll{});
    foo(std::move(v));
    // foo(v);            // error
    // foo(c);            // error
    // foo(std::move(c)); // error
}
