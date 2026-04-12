#pragma once

#include "../board/GameBoard.hpp"



class GameLoop {
    GameBoard board;
    bool isRunning;

public:
    GameLoop() : isRunning(true) {}

    void run ();

    void render();

    void processInput();
};




