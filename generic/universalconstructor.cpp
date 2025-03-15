#include <iostream>

class X
{
  public:
    X() = default;

    X(const X &)
    {
        std::cout << "copy constructor\n";
    }
    X(X &&)
    {
        std::cout << "move constructor\n";
    }

    template <typename T>
    X(T &&)
    {
        std::cout << "universal constructor\n";
    }
};

int
main()
{
    X       xv;
    const X xc;

    X xcc{xc};            // OK: calls copy constructor
    X xvc{xv};            // OOPS: calls universal constructor
    X xvm{std::move(xv)}; // OK: calls move constructor
    X xcm{std::move(xc)}; // OOPS: calls universal constructor
}
