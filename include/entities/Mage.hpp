#pragma once

#include "Unit.hpp"
#include "../abilities/Heal.hpp"
#include <memory>
#include <algorithm>

class Mage : public Unit {
    int manaRegen = 10;

public:
    Mage(int id) 
        : Unit(UnitStats(60, 30, 3, 2, 50), "M", id, std::make_unique<Heal>()) {}

    void onTurnEnd() override {
        restoreMana(manaRegen);
    }
};