#pragma once
#include "../entities/Unit.hpp"
#include <memory>
class Cell {
    std::unique_ptr<Unit> unit;

public:
    Cell() : unit(nullptr) {}

    Unit* getUnit() { return unit.get(); }
    
    void setUnit(std::unique_ptr<Unit> newObj) { unit = std::move(newObj); }

    std::unique_ptr<Unit> releaseUnit() { return std::move(unit); }

    bool isOccupied() { return unit != nullptr; }
   

};