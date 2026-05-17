#include "../../include/core/Player.hpp"
#include "../../include/board/GameBoard.hpp"
#include "../../include/mechanics/Action.hpp"
#include "../../include/common/GameException.hpp"

void Player::makeMove(Point from, Point target, GameBoard& board) {
    
    Unit* unit = board.getCell(from).getUnit();

    if (unit == nullptr) { throw EmptyCellException();}

    if (unit->getTeamId() != teamId) { throw NotYourUnitException();} 

    Intent playerIntent = Intent::MoveOrAttack;

    if (board.getCell(target).isOccupied() && unit->hasAbility()) {
        std::cout << "\nВыберите действие для " << unit->getSymbol() << ":\n";
        std::cout << "1. Атака\n";
        std::cout << "2. Способность (" << unit->getAbility()->getName() << ")\n";
        std::cout << "Выбор: ";
        
        int choice;
        std::cin >> choice;
        if (choice == 2) playerIntent = Intent::UseSpell;
    }

    Action ac(from, target);
    ac.execute(board, playerIntent);
    
}
