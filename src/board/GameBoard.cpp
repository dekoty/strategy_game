#include "../../include/board/GameBoard.hpp"
#include <iostream>
#include <memory>


void GameBoard::setUnitInBoard(std::shared_ptr<Unit> u, Point p) {
    board[p.y][p.x].setUnit(u);

}


void GameBoard::moveUnit(Point from, Point target) {
    Cell& cellFrom = getCell(from);
    Cell& cellTarget = getCell(target);

    cellTarget.setUnit(cellFrom.getUnit());

    cellFrom.removeUnit();
}

void GameBoard::removeUnit(Point p) {
    Cell& cell = getCell(p);

    if (cell.isOccupied()) cell.removeUnit();   

}