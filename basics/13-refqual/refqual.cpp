#include <print>

class C
{
  public:
    void
    foo() const &
    {
        std::println("foo() const&");
    }

    void
    foo() &&
    {
        std::println("foo() &&");
    }

    void
    foo() &
    {
        std::println("foo() &");
    }

    void
    foo() const &&
    {
        std::println("foo() const&&");
    }
};

int
main()
{
    C x;
    x.foo();             // foo() &
    C{}.foo();           // foo() &&
    std::move(x).foo();  // foo() &&

    const C cx;
    cx.foo();            // foo() const&
    std::move(cx).foo(); // foo() const&&
}
