#include <string>

class Person
{
  private:
    std::string first; // first name
    std::string last;  // last name
  public:
    Person(const std::string &f, const std::string &l) : first{f}, last{l}
    {
    }
    //...
};
