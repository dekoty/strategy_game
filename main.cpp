#include "include/board/GameBoard.hpp"
#include "include/entities/AllEntities.hpp"
#include "include/mechanics/Action.hpp"
#include <iostream>

int main() {
    GameBoard gm;

    Mage* m = new Mage();
    Archer* a = new Archer();
    Swordsman* s = new Swordsman;

    Action ac(Point{5,5}, Point{0,0});

    gm.setUnitInBoard(m,Point{2,2});

    gm.setUnitInBoard(a, Point{3,3});

    gm.render();

    ac.execute(gm);

    std::cout << "\n";

    gm.render();

    return 0;
}

