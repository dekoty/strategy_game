#pragma once

#include "../entities/Unit.hpp"
#include "../entities/Item.hpp"
#include <memory>

class Cell {
    std::shared_ptr<Unit> unit;
    std::unique_ptr<Item> item;

public:
    Cell() : unit(nullptr), item(nullptr) {}

    std::shared_ptr<Unit> getUnit() { return unit; }
    
    void setUnit(std::shared_ptr<Unit> newObj) { unit = newObj; }

    void removeUnit() { unit.reset(); }

    bool isOccupied() { return unit != nullptr; }

    void setItem(std::unique_ptr<Item> newItem) { item = std::move(newItem); }

    Item* getItem() { return item.get(); }

    void removeItem() { item.reset(); }
    
    bool hasItem() const { return item != nullptr; }
   
};