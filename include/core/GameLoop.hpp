#pragma once

#include "../board/GameBoard.hpp"
#include <vector>
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
};




