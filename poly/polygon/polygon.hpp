#pragma once

#include "coord.hpp"
#include "geoobj.hpp"
#include <iostream>
#include <vector>

class Polygon : public GeoObj
{
  private:
    std::vector<Coord> points;

  public:
    // take by value and move
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
