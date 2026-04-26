#pragma once

#include "../core/Player.hpp"
#include <vector>


class Turn {
    std::vector<Player> players;
    int currentPlayerIndex;
    int roundNumber;

public:
    Turn() : currentPlayerIndex(0), roundNumber(1) {}

    Player& getCurrentPlayer() { return players[currentPlayerIndex]; }

    int getRoundNumber() const { return roundNumber; }

    void addPlayer(const Player& player);

    void nextTurn();


    std::vector<Player> getPlayers() { return players; }

};