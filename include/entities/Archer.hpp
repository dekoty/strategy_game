#pragma once

#include "Unit.hpp"

class Archer: public Unit {
public:
    Archer(int id): Unit(80, 20, 4, 2,"A", id) {}
};