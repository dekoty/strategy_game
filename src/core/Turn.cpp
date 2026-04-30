#include "../../include/core/Turn.hpp"


void Turn::addPlayer(Player player) {
    players.push_back(std::move(player));
}


void Turn::nextTurn() {
    currentPlayerIndex++;
   
    if (currentPlayerIndex >= players.size()) {
        currentPlayerIndex = 0;
        roundNumber++; 
    }
}