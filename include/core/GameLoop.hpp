#pragma once

#include "../board/GameBoard.hpp"
#include <vector>
#include <utility>
#include "../core/Player.hpp"
#include "../core/Turn.hpp"

class GameLoop {
    GameBoard board;
    bool isRunning;
    Turn turnManager;
    std::string lastErrorMessage;

public:
    GameLoop() : isRunning(true) {}

    void run ();

    void render();

    std::pair<Point, Point> processInput();

    void init();

    void setupBoard();

    bool checkGameOver();

    void announceWinner(int loseId);

private:
    template<typename T>
    void spawnUnit(Player& player, Point p) {

        auto unit = std::make_unique<T>(player.getId());
    
        Unit* ptr = unit.get();
    
        board.setUnitInBoard(ptr, p);

        player.getArmy().addUnit(std::move(unit));

    }
};




