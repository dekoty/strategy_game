#include "../../include/board/GameBoard.hpp"
#include <iostream>
#include <memory>


void GameBoard::setUnitInBoard(Unit* u, Point p) {
    board[p.y][p.x].setUnit(u);

}


void GameBoard::moveUnit(Point from, Point target) {
    Cell& cellFrom = getCell(from);
    Cell& cellTarget = getCell(target);

    cellTarget.setUnit(cellFrom.getUnit());

    cellFrom.removeUnit();
}


void GameBoard::render() {
    for (int y = 0; y < SIZE; ++y) {
        for (int x = 0; x < SIZE; ++x) {
            if (board[y][x].getUnit() != nullptr) {
                std::cout << board[y][x].getUnit()->getSymbol() << " ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}


void GameBoard::removeUnit(Point p) {
    Cell& cell = getCell(p);

    if (cell.isOccupied()) cell.removeUnit();   

}