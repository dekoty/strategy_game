#include "../../include/core/GameLoop.hpp"
#include "../../include/entities/AllEntities.hpp"
#include "../../include/mechanics/Action.hpp"
#include "../../include/core/Player.hpp"
#include <iostream>

void GameLoop::init() {
    turnManager.addPlayer(Player("Player1", 1));
    turnManager.addPlayer(Player("Player2", 2));
}

void GameLoop::setupBoard() {

    for (const auto& player : turnManager.getPlayers()) {
        int id = player.getId();
        
        int startY = (id == 1) ? 0 : 9;

        auto m = std::make_unique<Mage>(id);
        auto a = std::make_unique<Archer>(id);
        auto s = std::make_unique<Swordsman>(id);

        board.setUnitInBoard(std::move(m), Point{4, startY});
        board.setUnitInBoard(std::move(a), Point{3, startY});
        board.setUnitInBoard(std::move(s), Point{5, startY});
        
        
    }
}


void GameLoop::run() {
    init();

    setupBoard();
    
    while (isRunning) {
        render();

        auto currentPlayer = turnManager.getCurrentPlayer();

        std::cout << "---Раунд" << turnManager.getRoundNumber() << "---"<< std::endl;
        std::cout << "Ход игрока" << currentPlayer.getId() << std::endl;

        try
        {
            auto coordinates = processInput();

            currentPlayer.makeMove(coordinates.first, coordinates.second, board);

            turnManager.nextTurn();
          
        }
        catch(const std::exception& e)
        {
            lastErrorMessage = e.what();
        }
        
    }
}



void GameLoop::render() {
    std::system("clear");
    board.render();

    if (!lastErrorMessage.empty()) {
        std::cout << "\n[ВНИМАНИЕ]: " << lastErrorMessage << std::endl;
        lastErrorMessage = ""; 
    }
}


std::pair<Point, Point> GameLoop::processInput() {
    Point unit;
    Point target;


    std::cout << "Введите координаты юнита и цели:";

    if (!(std::cin >>  unit.x >> unit.y  >> target.x >> target.y)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        
        throw InvalidInputException();
    }

    return {unit, target};
        

}