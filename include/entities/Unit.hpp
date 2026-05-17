#pragma once

#include <string>
#include <iostream>
#include <memory>
#include "../abilities/Ability.hpp"

class Unit {
    int hp;
    int damage;
    int attackRange;
    int moveRange;
    int maxHp;
    int tmId;
    int mana = 0;
    int maxMana = 0;
    std::string symbol;
    std::unique_ptr<Ability> ability;

public:
    Unit(int h = 100,int d = 10, int atR = 1 , int mvR = 1,std::string sym = ".", int id = 0) : hp(h), maxHp(h),damage(d),attackRange(atR), moveRange(mvR),symbol(sym), tmId(id) {}

    virtual ~Unit() = default;

    virtual void onTurnEnd() {}

    std::string getSymbol() { return symbol; }

    int getHp() { return hp; }

    int getMaxHp() { return maxHp; }
    
    void setSymbol(std::string sym) { symbol = sym; }
    
    void setAbility(std::unique_ptr<Ability> ab) { ability = std::move(ab); }

    void setManaAndMx(int mn, int maxMn) { mana = mn; maxMana = maxMn; }

    int getMana() const { return mana; }

    int getMaxMana() const { return maxMana; }

    void useMana(int amount) { mana -= amount; }

    bool hasAbility() { return ability != nullptr; }

    Ability* getAbility() { return ability.get(); }

    int getTeamId() const {return tmId; }

    int getDamage() const { return damage; }

    int getAttackRange() const { return attackRange; }

    int getMoveRange() const { return moveRange; }

    void takeDamage(int d) { 
        hp -= d;
        if (hp < 0) hp = 0;

        std::cout << getSymbol() << ":"<< hp << std::endl;
     }

    bool isAlive() const { return hp; }

    void heal(int amount) {
        hp += amount; 

        if (hp > maxHp) hp = maxHp;

    }

};