#include <print>
#include <utility>

// If you have a constructor that takes a single universal reference, this is a better match than:
// - The copy constructor if passing a non-const object
// - The move constructor if passing a const object

template <typename T>
void foo(const T &);  // for constant values (read-only access)

template <typename T>
void foo(const T &&); // for constant rvalues (mostly doesn't make sense; only for demonstration purposes)

template <typename T>
void foo(T &);        // for variable values (out parameters)

template <typename T>
void foo(T &&);       // for values that are no longer used (move semantics)

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
        requires(!std::is_same_v<std::remove_cvref_t<T>, X>) // uncomment this line to see difference
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

    //                        without requires        with requires
    X xcc1{xc};            // copy constructor        copy constructor
    X xvc1{xv};            // universal constructor   copy constructor
    X xvm1{std::move(xv)}; // move constructor        move constructor
    X xcm1{std::move(xc)}; // universal constructor   move constructor
}
