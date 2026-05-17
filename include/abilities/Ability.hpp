#pragma once

#include <string>

class Unit;

class Ability {
public:
    virtual ~Ability() = default;

    virtual void use(Unit* caster, Unit* target) = 0;

    virtual int getCost() const = 0;

    virtual int getRange() const = 0;

    virtual std::string getName() const = 0;
};