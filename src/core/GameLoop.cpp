#include "../../include/core/GameLoop.hpp"
#include "../../include/entities/AllEntities.hpp"
#include "../../include/mechanics/Action.hpp"
#include "../../include/core/Player.hpp"
#include "../../include/common/Logger.hpp"
#include "../../include/factory/UnitFactory.hpp"
#include "../../include/entities/Item.hpp"
#include <iostream>
#include <random>
#include <ctime>


void GameLoop::init() {
    turnManager.addPlayer(Player("Player1", 1));
    turnManager.addPlayer(Player("Player2", 2));
}

void GameLoop::setupBoard() {
    MageCreator mageFactory;
    ArcherCreator archerFactory;
    SwordsmanCreator swordFactory;

    for (auto& player : turnManager.getPlayers()) {
        int startY = (player.getId() == 1) ? 0 : 9;
    
        auto mage = mageFactory.createUnit(player.getId());
        board.setUnitInBoard(mage, {4, startY});
        player.getArmy().addUnit(std::move(mage));

        auto archer = archerFactory.createUnit(player.getId());
        board.setUnitInBoard(archer, {3, startY});
        player.getArmy().addUnit(std::move(archer));

        auto sword = swordFactory.createUnit(player.getId());
        board.setUnitInBoard(sword, {5, startY});
        player.getArmy().addUnit(std::move(sword));

    }

    std::srand(std::time(nullptr));
    for (int i = 0; i < 2; ++i) { 
        int rx, ry;
        do {
            rx = std::rand() % 10;
            ry = std::rand() % 10;
        } while (board.getCell({rx, ry}).isOccupied() || board.getCell({rx, ry}).hasItem());
        
        board.getCell({rx, ry}).setItem(std::make_unique<ManaPotion>());
    }

}

void GameLoop::render() {

    renderer.renderBoard(board);
    renderer.renderStats(turnManager);
    renderer.renderLogs();
    renderer.renderError(lastErrorMessage);
    lastErrorMessage = ""; 
}

void GameLoop::run() {
    init(); 
    setupBoard();
    
    while (isRunning) {
        render();
        
        auto& currPlayer = turnManager.getCurrentPlayer();
        std::cout << "---Раунд " << turnManager.getRoundNumber() << "--- Ход игрока " << currPlayer.getId() << "\n";
        
        try {
            auto [from, to] = processInput();

            std::unique_ptr<IActionStrategy> strategy;
            std::shared_ptr<Unit> u = board.getCell(from).getUnit();

            if (u != nullptr && board.getCell(to).isOccupied()) {
                if (u->hasAbility()) {
                    std::cout << "1. Атака\n2. Способность (" << u->getAbility()->getName() << ")\nВыбор: ";
                    int choice; std::cin >> choice;
                    
                    if (choice == 2) {
                        strategy = std::make_unique<SpellStrategy>();
                    } else {
                        strategy = std::make_unique<AttackStrategy>();
                    }
                } else {
                    strategy = std::make_unique<AttackStrategy>();
                }
            } else {
                strategy = std::make_unique<MoveStrategy>();

                if (board.getCell(to).hasItem()) {
                    std::string itemName = board.getCell(to).getItem()->getName();
                    Logger::log(u->getSymbol() + " подобрал " + itemName);
                }
            }

            currPlayer.makeMove(from, to, board, std::move(strategy));

            for (auto& p: turnManager.getPlayers()) p.getArmy().cleanupDead();
            if (checkGameOver()) break;
            
            turnManager.nextTurn();
            for (auto& u : currPlayer.getArmy().getUnits()) u->onTurnEnd();
            
        } catch(const std::exception& e) { 
            lastErrorMessage = e.what(); 
        }
    }
}

std::pair<Point, Point> GameLoop::processInput() {
    Point unit;
    Point target;

    std::cout << "Введите координаты юнита и цели (x1 y1 x2 y2): ";
    if (!(std::cin >> unit.x >> unit.y >> target.x >> target.y)) {
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

    renderer.renderWinner(winnerName);
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