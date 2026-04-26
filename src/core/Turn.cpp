#include "../../include/core/Turn.hpp"


void Turn::addPlayer(const Player& player) {
    players.push_back(player);
}


void Turn::nextTurn() {
    currentPlayerIndex++;
   
    if (currentPlayerIndex >= players.size()) {
        currentPlayerIndex = 0;
        roundNumber++; 
    }
}