#include "../../include/mechanics/Action.hpp"
#include "../../include/mechanics/Combat.hpp"
#include "../../include/common/GameException.hpp"

void MoveStrategy::execute(Unit* unitF, Point from, Point target, GameBoard& board) {
    if (board.getCell(target).isOccupied()) throw InvalidInputException();
    if (calcDistance(from, target) > unitF->getStats().moveRange) throw TooFarException();
    
    board.moveUnit(from, target);

    Cell& targetCell = board.getCell(target);
    if (targetCell.hasItem()) {
        Item* item = targetCell.getItem();
        
        item->apply(unitF);
        
        targetCell.removeItem();
    }
}

void AttackStrategy::execute(Unit* unitF, Point from, Point target, GameBoard& board) {
    Unit* unitT = board.getCell(target).getUnit();
    if (!unitT) throw EmptyCellException();
    if (calcDistance(from, target) > unitF->getStats().attackRange) throw TargetOutOfRangeException();
    if (unitF->getTeamId() == unitT->getTeamId()) throw FriendlyFireException();

    Combat combat(unitF, unitT);
    combat.fight();

    if (!unitT->isAlive()) {
        board.removeUnit(target);
    }
}

void SpellStrategy::execute(Unit* unitF, Point from, Point target, GameBoard& board) {
    Unit* unitT = board.getCell(target).getUnit();
    Ability* abil = unitF->getAbility();
    
    if (!abil) throw InvalidInputException();
    if (unitF->getStats().mana < abil->getCost()) throw NotEnoughManaException();
    if (calcDistance(from, target) > abil->getRange()) throw TargetOutOfRangeException();

    abil->use(unitF, unitT);
    unitF->useMana(abil->getCost());
}