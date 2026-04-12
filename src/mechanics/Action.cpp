#include "../../include/mechanics/Action.hpp"


 void Action::execute(GameBoard&  realBoard) {
    Cell& cell = realBoard.getCell(target);
    if (!cell.isOccupied()) {
        realBoard.moveUnit(from, target);
    }
}