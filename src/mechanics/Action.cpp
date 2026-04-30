#include "../../include/mechanics/Action.hpp"
#include "../../include/mechanics/Combat.hpp"
#include "../../include/common/GameException.hpp"

 void Action::execute(GameBoard&  realBoard) {
    Cell& cellT = realBoard.getCell(target);
    Cell& cellF = realBoard.getCell(from);

    if (cellF.getUnit() == nullptr) {
        throw EmptyCellExcpetion();
    }


    if (!cellT.isOccupied()) {
        realBoard.moveUnit(from, target);

    } else {
        auto unitF = cellF.getUnit();

        auto unitT = cellT.getUnit();

        if (unitF->getTeamId() == unitT->getTeamId()) { 
            throw FriendlyFireException();
        }

        Combat combat(unitF, unitT);
        combat.fight();

        if (!unitT->isAlive()) {
            std::cout << "Юнит: " << unitT->getSymbol() << " умер" << std::endl ;

            realBoard.removeUnit(target);

        }
    }
}