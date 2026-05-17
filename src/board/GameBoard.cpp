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

    std::cout << "   "; 
    for (int x = 0; x < SIZE; ++x) {
    
        if (x < 10) std::cout << x << " ";
        else std::cout << x; 
    }
    std::cout << "\n";


    for (int y = 0; y < SIZE; ++y) {
     
        if (y < 10) std::cout << " " << y << "| ";
        else std::cout << y << "| ";

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