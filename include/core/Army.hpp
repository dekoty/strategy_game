#pragma once

#include <vector>
#include "../entities/Unit.hpp"
#include <memory>
#include <algorithm>

class Army {
    std::vector<std::shared_ptr<Unit>> units;

public:
    void addUnit(std::shared_ptr<Unit> unit) {
        units.push_back(unit);
    }

    bool isDefeated() const {
        return units.empty();
    }

    auto& getUnits() const { return units;}

    void cleanupDead() {
        units.erase(std::remove_if(units.begin(), units.end(), [](const auto& u) { return !u->isAlive(); }), units.end());
    }

};