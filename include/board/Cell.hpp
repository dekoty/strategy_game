#pragma once

#include "../entities/Unit.hpp"
#include "../entities/Item.hpp"
#include <memory>

class Cell {
    Unit* unit;
    std::unique_ptr<Item> item;

public:
    Cell() : unit(nullptr) {}

    Unit* getUnit() { return unit; }
    
    void setUnit(Unit* newObj) { unit = newObj; }

    void removeUnit() { unit = nullptr; }

    bool isOccupied() { return unit != nullptr; }

    void setItem(std::unique_ptr<Item> newItem) { item = std::move(newItem); }

    Item* getItem() { return item.get(); }

    void removeItem() { item.reset(); }
    
    bool hasItem() const { return item != nullptr; }
   
};