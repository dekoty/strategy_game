#pragma once

#include <vector>
#include "../entities/Unit.hpp"
#include <memory>
#include <algorithm>

class Army {
    std::vector<std::unique_ptr<Unit>> units;

public:
    void addUnit(std::unique_ptr<Unit> unit) {
        units.push_back(std::move(unit));
    }

    bool isDefeated() const {
        return units.empty();
    }

    void cleanupDead() {
        units.erase(std::remove_if(units.begin(), units.end(), [](const auto& u) { return !u->isAlive(); }), units.end());
    }

};