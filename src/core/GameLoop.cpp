#include "../../include/core/GameLoop.hpp"
#include "../../include/entities/AllEntities.hpp"
#include "../../include/mechanics/Action.hpp"
#include <iostream>

void GameLoop::run() {
    auto m = std::make_unique<Mage>();
    auto a = std::make_unique<Archer>();
    auto s = std::make_unique<Swordsman>();


    Action ac(Point{5,5}, Point{0,0});

    board.setUnitInBoard(std::move(m),Point{4,9});
    board.setUnitInBoard(std::move(a), Point{3,9});
    board.setUnitInBoard(std::move(s), Point{5,9});

    while (isRunning) {
        render();
        processInput();
    }
}


void GameLoop::render() {
    board.render();
}


void GameLoop::processInput() {
    Point unit;
    Point target;


    std::cout << "Введите координаты юнита и цели:";

    if (!(std::cin >>  unit.x >> unit.y  >> target.x >> target.y)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Вводите только числа" << std::endl;
        
        return;
    }
    

    try
    {
        Action ac(unit, target);
        ac.execute(board);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    


}