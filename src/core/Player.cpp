#include "../../include/core/Player.hpp"
#include "../../include/board/GameBoard.hpp"
#include "../../include/mechanics/Action.hpp"
#include "../../include/common/GameException.hpp"
void Player::makeMove(Point from, Point target, GameBoard& board) {
    
    Unit* unit = board.getCell(from).getUnit();

    if (unit == nullptr) { throw EmptyCellExcpetion();}

    if (unit->getTeamId() != teamId) { throw NotYourUnitException();} 

    Action ac(from, target);
    ac.execute(board);
    
}
