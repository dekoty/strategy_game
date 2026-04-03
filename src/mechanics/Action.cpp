#include "../../include/mechanics/Action.hpp"


 void Action::execute(GameBoard&  realBoard) {
    Cell& cell = realBoard.getCell(target);
    if (!cell.getStatus()) {
        realBoard.moveUnit(from, target);
    }
}