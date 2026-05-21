#pragma once

#include "../common/Point.hpp"
#include "../board/GameBoard.hpp"
#include "../entities/Unit.hpp"

class IActionStrategy {
public:
    virtual ~IActionStrategy() = default;
    virtual void execute(Unit* unitFrom, Point from, Point target, GameBoard& board) = 0;
};

class MoveStrategy : public IActionStrategy {
public:
    void execute(Unit* unitFrom, Point from, Point target, GameBoard& board) override;
};


class AttackStrategy : public IActionStrategy {
public:
    void execute(Unit* unitFrom, Point from, Point target, GameBoard& board) override;
};

class SpellStrategy : public IActionStrategy {
public:
    void execute(Unit* unitFrom, Point from, Point target, GameBoard& board) override;
};