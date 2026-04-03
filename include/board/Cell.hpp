#pragma once
#include "../entities/Unit.hpp"

class Cell {
    bool status;
    Unit* unit;

public:
    Cell() : status(false), unit(nullptr) {}

    Unit* getUnit() { return unit; }
    
    void setUnit(Unit* newObj) { unit = newObj;}

    bool getStatus() { return status; }

    void setStatus(bool st) { status = st; }
};