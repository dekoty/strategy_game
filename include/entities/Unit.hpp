#pragma once
#include <string>
#include <iostream>


class Unit {
    int hp;
    int damage;
    int tmId;
    std::string symbol;

public:
    Unit(int h = 100,int d = 10, std::string sym = ".", int id = 0) : hp(h), damage(d), symbol(sym), tmId(id) {}

    virtual ~Unit() = default;

    std::string getSymbol() { return symbol; }
    
    void setSymbol(std::string sym) { symbol = sym; }
    
    int getTeamId() const {return tmId; }

    int getDamage() const { return damage; }

    void takeDamage(int d) { 
        hp -= d;
        if (hp < 0) hp = 0;

        std::cout << getSymbol() << ":"<< hp << std::endl;
     }

    bool isAlive() const { return hp; }
};