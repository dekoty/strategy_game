#include "../../include/mechanics/Action.hpp"
#include "../../include/mechanics/Combat.hpp"
#include "../../include/common/GameException.hpp"
#include "../../include/common/Point.hpp"
#include "../../include/abilities/Ability.hpp"



 void Action::execute(GameBoard&  realBoard, Intent intent) {
    Cell& cellT = realBoard.getCell(target);
    Cell& cellF = realBoard.getCell(from);
    Unit* unitF = cellF.getUnit();
    Unit* unitT = cellT.getUnit();

    auto distance = calcDistance(target, from);
    
    if (cellF.getUnit() == nullptr) {
        throw EmptyCellException();
    }



    if (intent == Intent::UseSpell) {
        Ability* abil = unitF->getAbility();
        
        if (unitF->getMana() < abil->getCost()) throw NotEnoughManaException();
        if (distance > abil->getRange()) throw TargetOutOfRangeException();

        abil->use(unitF, unitT);
        unitF->useMana(abil->getCost());
    } 

    else if (!cellT.isOccupied()) {
        if (distance > unitF->getMoveRange()) throw TooFarException();

        realBoard.moveUnit(from, target);
    } 
    else {
        if (distance > unitF->getAttackRange()) throw TargetOutOfRangeException();
        if (unitF->getTeamId() == unitT->getTeamId()) throw FriendlyFireException();

        Combat combat(unitF, unitT);
        combat.fight();
    }

    if (unitT && !unitT->isAlive()) {
        std::string msg = "Юнит " + unitT->getSymbol() + " умер";
        realBoard.removeUnit(target);
    }

}