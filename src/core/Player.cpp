#include "../../include/core/Player.hpp"
#include "../../include/board/GameBoard.hpp"
#include "../../include/mechanics/Action.hpp"
#include "../../include/common/GameException.hpp"


void Player::makeMove(Point from, Point target, GameBoard& board, std::unique_ptr<IActionStrategy> strategy) {
    Unit* unit = board.getCell(from).getUnit();

    if (unit == nullptr) throw EmptyCellException();
    if (unit->getTeamId() != teamId) throw NotYourUnitException();

    strategy->execute(unit, from, target, board);
}
