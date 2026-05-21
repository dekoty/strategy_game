#pragma once
#include <string>
#include "Unit.hpp"

class Item {
    std::string name;
    std::string symbol;
    int value;
public:
    Item(std::string n, std::string s, int v) : name(n), symbol(s), value(v) {}

    virtual ~Item() = default;
    
    virtual void apply(Unit* unit) = 0;
    
    std::string getSymbol() const { return symbol; }
    std::string getName() const { return name; }
    int getValue() const { return value; }
};


class ManaPotion : public Item {
public:
  
    ManaPotion() : Item("Зелье маны", "?", 50) {}

    void apply(Unit* unit) override {
        unit->restoreMana(getValue()); 
    }

};