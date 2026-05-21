#pragma once

#include <string>
#include <iostream>
#include <memory>
#include "../abilities/Ability.hpp"
#include "../common/Logger.hpp"

struct UnitStats {
    int hp;
    int maxHp;
    int damage;
    int attackRange;
    int moveRange;
    int mana;
    int maxMana;

    UnitStats(int h = 100, int d = 10, int atR = 1, int mvR = 1, int mn = 0)
        : hp(h), maxHp(h), damage(d), attackRange(atR), moveRange(mvR), mana(mn), maxMana(mn) {}
};




class Unit {
    UnitStats stats;
    int teamId;
    std::string symbol;
    std::unique_ptr<Ability> ability;

public:
    Unit(UnitStats s, std::string sym, int id, std::unique_ptr<Ability> ab = nullptr) 
        : stats(s), teamId(id), symbol(sym), ability(std::move(ab)) {}

    virtual ~Unit() = default;

    virtual void onTurnEnd() {}

    const UnitStats& getStats() const { return stats; }
    std::string getSymbol() const { return symbol; }
    int getTeamId() const { return teamId; }
    Ability* getAbility() const { return ability.get(); }

    bool hasAbility() const { return ability != nullptr; }

    void takeDamage(int d) { 
        stats.hp -= d;
        if (stats.hp < 0) stats.hp = 0;
        Logger::log("Юнит " + symbol + " получает урон. Осталось HP: " + std::to_string(stats.hp));
    }

    void heal(int amount) {
        stats.hp += amount; 
        if (stats.hp > stats.maxHp) stats.hp = stats.maxHp;
    }
    
    bool isAlive() const { return stats.hp > 0; }

    void useMana(int amount) {
        stats.mana -= amount; 
    }

    void restoreMana(int amount) {
        stats.mana = std::min(stats.maxMana, stats.mana + amount);
    }

    void buffDamage(int bonus) {
        stats.damage += bonus;
    }
};