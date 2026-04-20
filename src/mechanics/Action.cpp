#include "../../include/mechanics/Action.hpp"
#include "../../include/mechanics/Combat.hpp"

 void Action::execute(GameBoard&  realBoard) {
    Cell& cellT = realBoard.getCell(target);
    Cell& cellF = realBoard.getCell(from);

    if (!cellT.isOccupied()) {
        realBoard.moveUnit(from, target);
    }

    Combat combat(cellF.getUnit(), cellT.getUnit());

    combat.fight();



    
}