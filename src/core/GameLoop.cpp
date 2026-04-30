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

    for ( auto& player : turnManager.getPlayers()) {
        int id = player.getId();
        
        int startY = (id == 1) ? 0 : 9;

        spawnUnit<Mage>(player, Point{4, startY});
        spawnUnit<Archer>(player, Point{3, startY});
        spawnUnit<Swordsman>(player, Point{5, startY});
        
    }
}


void GameLoop::run() {
    init();

    setupBoard();
    
    while (isRunning) {
        render();

        auto& currentPlayer = turnManager.getCurrentPlayer();

        std::cout << "---Раунд" << turnManager.getRoundNumber() << "---"<< std::endl;
        std::cout << "Ход игрока" << currentPlayer.getId() << std::endl;

        try
        {
            auto coordinates = processInput();

            currentPlayer.makeMove(coordinates.first, coordinates.second, board);

            for (auto& player: turnManager.getPlayers()) {
                player.getArmy().cleanupDead();

            }

            if (checkGameOver()) break;
            

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

void GameLoop::announceWinner(int loseId) {
    render();

    std::string winnerName;

    for (auto& player: turnManager.getPlayers()) {
        if (player.getId() != loseId)
            winnerName = player.getName();
    }


    std::cout << "\n";
    std::cout << "ИГРА ОКОНЧЕНА" << std::endl;
    std::cout << "ПОБЕДИТЕЛЬ: " << winnerName << std::endl;

    isRunning = false;

}

bool GameLoop::checkGameOver() {
    for (auto & player: turnManager.getPlayers()) {
        if (player.getArmy().isDefeated()) {
            announceWinner(player.getId());
            return true;
        }
    }

    return false;
}