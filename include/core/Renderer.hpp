#pragma once
#include "../board/GameBoard.hpp"
#include "Turn.hpp"
#include <string>

class Renderer {
public:
    void renderBoard(GameBoard& board);
    void renderStats(Turn& turnManager);
    void renderLogs();
    void renderError(const std::string& errorMsg);
    void renderWinner(const std::string& winnerName);
};