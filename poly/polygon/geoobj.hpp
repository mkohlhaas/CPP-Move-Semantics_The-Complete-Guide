#ifndef GEOOBJ_HPP
#define GEOOBJ_HPP

#include "coord.hpp"
#include <string>

class GeoObj
{
  protected:
    std::string name; // name of the geometric object

    GeoObj(std::string n) : name{std::move(n)}
    {
    }

  public:
    std::string
    getName() const
    {
        return name;
    }

    virtual void draw() const = 0; // pure virtual function (introducing the API)

    virtual ~GeoObj() = default;   // would disable move semantics for name
  protected:
    // enable copy and move semantics (callable only for derived classes):
    GeoObj(const GeoObj &) = default;
    GeoObj(GeoObj &&)      = default;
    // disable assignment operator (due to the problem of slicing):
    GeoObj &operator=(GeoObj &&)      = delete;
    GeoObj &operator=(const GeoObj &) = delete;
    //...
};

#endif // GEOOBJ_HPP
