#pragma once

#include "../common/Point.hpp"
#include "../board/GameBoard.hpp"

enum class Intent {
    MoveOrAttack, 
    UseSpell      
};


class Action {
    Point from;
    Point target;

public:
    Action(Point fm, Point tar) : from(fm), target(tar) {}

    void execute(GameBoard&  realBoard, Intent intent);

    void setAction(Point fm, Point tg) {
        from = fm;
        target = tg;
    }
};