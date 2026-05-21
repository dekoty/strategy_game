#pragma once

#include "Unit.hpp"

class Archer : public Unit {
public:
    Archer(int id) : Unit(UnitStats(80, 20, 4, 2, 0), "A", id) {}
};