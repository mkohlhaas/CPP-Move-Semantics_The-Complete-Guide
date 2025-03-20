#include <string>
#include <vector>

template <typename T>
class Coll
{
  private:
    std::vector<T> values;

  public:
    Coll() = default;

    // In general, a function in a class template does not follow the rule of function templates.
    // It is what we call TEMPLOID, generic code that follows the rules of ordinary functions
    // when we instantiate the class.

    // function in class template:
    void
    insert(T &&val) // is an rvalue, NOT a universal reference
    {
        values.push_back(std::move(val));
    }
};

int
main()
{
    Coll<std::string> coll;
    coll.insert(std::string{"prvalue"}); // OK

    std::string str{"lvalue"};
    coll.insert(str);                    // ERROR: T&& of Coll<T> is not a universal reference
    coll.insert(std::move(str));         // OK
}
