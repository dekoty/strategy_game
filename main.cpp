#include "include/board/GameBoard.hpp"
#include "include/entities/AllEntities.hpp"
#include "include/mechanics/Action.hpp"
#include <iostream>

int main() {
    GameBoard gm;

    auto m = std::make_unique<Mage>();
    auto a = std::make_unique<Archer>();
    auto s = std::make_unique<Swordsman>();

    Action ac(Point{5,5}, Point{0,0});

    gm.setUnitInBoard(std::move(m),Point{2,2});

    gm.setUnitInBoard(std::move(a), Point{3,3});
    gm.setUnitInBoard(std::move(s), Point{4,4});

    gm.render();

    ac.execute(gm);

    std::cout << "\n";

    gm.render();

    return 0;
}

