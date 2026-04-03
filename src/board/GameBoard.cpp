#include "../../include/board/GameBoard.hpp"
#include <iostream>

GameBoard::GameBoard() {
        Unit* wall = new Unit("#");

        setUnitInBoard(wall,Point{5, 5});
    }

void GameBoard::setUnitInBoard(Unit* u, Point p) {
    board[p.y][p.x].setUnit(u);
    board[p.y][p.x].setStatus(true);
}


void GameBoard::moveUnit(Point from, Point target) {
    Cell& cellFrom = getCell(from);
    Cell& cellTarget = getCell(target);

    cellTarget.setUnit(cellFrom.getUnit());
    cellTarget.setStatus(true);

    cellFrom.setUnit(nullptr);
    cellFrom.setStatus(false);

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