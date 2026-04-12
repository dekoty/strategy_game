#pragma once

#include "Cell.hpp"
#include "../common/Point.hpp"
#include <memory>

class GameBoard {
    static const int SIZE = 10;
    Cell board[SIZE][SIZE];

public:
    GameBoard();

    void setUnitInBoard(std::unique_ptr<Unit> u, Point p);

    void moveUnit(Point from, Point target);

    void render();

    Cell& getCell(const Point& p) {
        return board[p.y][p.x];

    }
};