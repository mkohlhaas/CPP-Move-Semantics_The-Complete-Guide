#include <iostream>
#include <string>

class IntString
{
  private:
    int         val;  // value
    std::string sval; // cached string representation of the value
  public:
    IntString(int i = 0) : val{i}, sval{std::to_string(i)}
    {
    }
    void
    setValue(int i)
    {
        val  = i;
        sval = std::to_string(i);
    }
    //...
    void
    dump() const
    {
        std::cout << " [" << val << "/'" << sval << "']\n";
    }
};
