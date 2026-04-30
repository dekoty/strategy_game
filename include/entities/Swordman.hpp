#pragma once

#include "Unit.hpp"

class Swordsman: public Unit {
public:
    Swordsman(int id): Unit(100, 15,"S", id) {}
};