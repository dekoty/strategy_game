#pragma once

#include "Unit.hpp"

class Mage: public Unit {
public:
    Mage(int id) : Unit(60, 30, "M", id) {}
};