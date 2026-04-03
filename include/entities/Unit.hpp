#pragma once
#include <string>



class Unit {
    int hp;
    int damage;
    std::string symbol = ".";

public:
    Unit(std::string sym = ".") : hp(100), damage(10), symbol(sym) {}

    std::string getSymbol() { return symbol; }
    void setSymbol(std::string sym) { symbol = sym; }
};