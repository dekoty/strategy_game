#pragma once
#include <string>
#include <iostream>


class Unit {
    int hp;
    int damage;
    std::string symbol;

public:
    Unit(int h = 100,int d = 10, std::string sym = ".") : hp(h), damage(d), symbol(sym) {}

    virtual ~Unit() = default;

    std::string getSymbol() { return symbol; }
    void setSymbol(std::string sym) const { symbol = sym; }

    int getDamage() const { return damage; }

    void takeDamage(int d) { 
        hp -= d;
        if (hp < 0) hp = 0;

        std::cout << getSymbol() << ":"<< hp << std::endl;
     }

    bool isAlive() const { return hp; }
};