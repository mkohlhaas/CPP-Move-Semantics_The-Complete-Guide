#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "geoobj.hpp"
#include <iostream>
#include <vector>

class Polygon : public GeoObj
{
  private:
    std::vector<Coord> points;

  public:
    // constructor for name and list of Coords
    Polygon(std::string n, std::initializer_list<Coord> pl = {}) : GeoObj{std::move(n)}, points{std::move(pl)}
    {
    }

    virtual void
    draw() const override
    {
        std::cout << "polygon '" << name << "' over";
        for (auto &p : points)
        {
            std::cout << " " << p;
        }
        std::cout << "\n";
    }
};

#endif
