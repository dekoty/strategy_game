#pragma once

#include "../entities/Unit.hpp"
#include <memory>

class Cell {
    Unit* unit;

public:
    Cell() : unit(nullptr) {}

    Unit* getUnit() { return unit; }
    
    void setUnit(Unit* newObj) { unit = newObj; }

    void removeUnit() { unit = nullptr; }

    bool isOccupied() { return unit != nullptr; }
   
};