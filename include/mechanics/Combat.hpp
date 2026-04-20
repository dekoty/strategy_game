#pragma once 

#include "../entities/Unit.hpp"

class Combat {
    Unit* attacker;
    Unit* defender;

public:
    Combat(Unit* attac, Unit* defend) : attacker(attac), defender(defend){}

    void fight() {

        defender->takeDamage(attacker->getDamage());
    }

};