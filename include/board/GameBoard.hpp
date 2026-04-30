#pragma once

#include "Cell.hpp"
#include "../common/Point.hpp"
#include <memory>
#include "../common/GameException.hpp"

class GameBoard {
    static const int SIZE = 10;
    Cell board[SIZE][SIZE];

public:

    void setUnitInBoard(Unit* u, Point p);

    void moveUnit(Point from, Point target);

    void removeUnit(Point p);

    void render();

    Cell& getCell(const Point& p) {
        if (p.x >= SIZE || p.y >= SIZE || p.x < 0  || p.y < 0) {
            throw OutOfRangeException();
        }

        return board[p.y][p.x];

    }

};