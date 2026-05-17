#pragma once

#include "Unit.hpp"
#include "../abilities/Heal.hpp"

#include <memory>
#include <algorithm>

class Mage: public Unit {
    int manaRegen = 10;
public:
    Mage(int id) : Unit(60, 30, 3, 2,"M", id) {
        setManaAndMx(50, 50);
        setAbility(std::make_unique<Heal>());
    }

    void onTurnEnd() override {
        int mn = getMana();
        int maxMn = getMaxMana();

        if (mn < maxMn) {
            setManaAndMx(std::min(maxMn, getMana() + manaRegen), maxMn);
        }
    }


};