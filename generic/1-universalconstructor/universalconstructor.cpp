#include <print>

class X
{
  public:
    X() = default;

    X(const X &)
    {
        std::println("copy constructor");
    }

    X(X &&)
    {
        std::println("move constructor");
    }

    template <typename T>
    X(T &&)
    {
        std::println("universal constructor");
    }
};

int
main()
{
    X       xv;
    const X xc;

    X xcc{xc};            // OK:   copy constructor
    X xvc{xv};            // OOPS: universal constructor
    X xvm{std::move(xv)}; // OK:   move constructor
    X xcm{std::move(xc)}; // OOPS: universal constructor
}
