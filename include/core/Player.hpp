#pragma once

#include <string>
#include "../board/GameBoard.hpp"
#include "../common/Point.hpp"
#include "../core/Army.hpp"

class Player {
    std::string name;
    int teamId;
    Army army;
    
public:
    Player(std::string n, int i) : name(n), teamId(i) {}
    
    void makeMove(Point from, Point target, GameBoard& board);

    int getId() const { return teamId; }

    std::string getName() const { return name; }

    Army& getArmy() {return army; }

};