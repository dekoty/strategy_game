#include "../../include/abilities/Heal.hpp"
#include "../../include/entities/Unit.hpp" 
#include "../../include/common/GameException.hpp"
#include "../../include/common/Logger.hpp"

#include <iostream>


void Heal::use(Unit* caster, Unit* target) {
    if (target == nullptr) {
        throw std::runtime_error("Там некого лечить!");
    }

    if (target->getTeamId() != caster->getTeamId()) {
        throw HealEnemyException();
    }

    target->heal(healAmount);

    std::string msg = "[МАГИЯ] " + caster->getSymbol() + " исцеляет " + target->getSymbol() + " на " + std::to_string(healAmount) + " HP ";
    Logger::log(msg);
}