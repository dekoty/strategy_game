#pragma once

#include "../board/GameBoard.hpp"
#include <vector>
#include <utility>
#include "Player.hpp"
#include "Turn.hpp"
#include "Renderer.hpp"

class GameLoop {
    GameBoard board;
    bool isRunning;
    Turn turnManager;
    std::string lastErrorMessage;
    Renderer renderer;

public:
    GameLoop() : isRunning(true) {}

    void run ();

    void render();
    
    std::pair<Point, Point> processInput();

    void init();

    void setupBoard();

    bool checkGameOver();

    void announceWinner(int loseId);

};




