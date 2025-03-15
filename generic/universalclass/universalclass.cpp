#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Coll
{
  private:
    std::vector<T> values;

  public:
    Coll() = default;

    // function in class template:
    void
    insert(T &&val)
    {
        values.push_back(std::move(val));
    }
};

int
main()
{
    Coll<std::string> coll;
    //...
    coll.insert(std::string{"prvalue"}); // OK
    std::string str{"lvalue"};
    coll.insert(str);                    // ERROR: T&& of Coll<T> is not a universal reference
    coll.insert(std::move(str));         // OK
                                         //...
}
