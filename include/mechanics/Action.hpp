#pragma once

#include "../common/Point.hpp"
#include "../board/GameBoard.hpp"

class Action {
    Point from;
    Point target;

public:
    Action(Point fm, Point tar) : from(fm), target(tar) {}

    void execute(GameBoard&  realBoard);

    void setAction(Point fm, Point tg) {
        from = fm;
        target = tg;
    }
};