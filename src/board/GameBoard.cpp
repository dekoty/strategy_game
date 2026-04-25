#include "../../include/board/GameBoard.hpp"
#include <iostream>
#include <memory>
GameBoard::GameBoard() {
        std::unique_ptr<Unit> wall = std::make_unique<Unit>(100, 0, "#");

        setUnitInBoard(std::move(wall) , Point{5, 5});
    }

void GameBoard::setUnitInBoard(std::unique_ptr<Unit> u, Point p) {
    board[p.y][p.x].setUnit(std::move(u));

}


void GameBoard::moveUnit(Point from, Point target) {
    Cell& cellFrom = getCell(from);
    Cell& cellTarget = getCell(target);

    cellTarget.setUnit(cellFrom.releaseUnit());


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

    if (cell.isOccupied()) cell.setUnit(nullptr);   

}