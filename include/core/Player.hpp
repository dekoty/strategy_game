#pragma once

#include <string>
#include "../board/GameBoard.hpp"
#include "../common/Point.hpp"


class Player {
    std::string name;
    int teamId;
    
public:
    Player(std::string n, int i) : name(n), teamId(i) {}
    
    void makeMove(Point from, Point target, GameBoard& board);

    int getId() const { return teamId; }


};