#pragma once

#include <string>

class GeoObj
{
  protected:
    std::string name;

    // take by value and move
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
    GeoObj &operator=(const GeoObj &) & = delete;
    GeoObj &operator=(GeoObj &&) &      = delete;

    //...
};
