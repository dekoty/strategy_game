#pragma once

#include "Ability.hpp"
#include "../entities/Unit.hpp"
#include <iostream>
#include <stdexcept>

class Heal : public Ability {
private:
    int healAmount = 20;
    int manaCost = 30;
    int castRange = 2;

public:
    void use(Unit* caster, Unit* target) override;

    int getCost() const  { return manaCost; }

    int getRange() const { return castRange; }

    std::string getName() const override { return "Heal"; }
};