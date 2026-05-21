#pragma once
#include <memory>
#include "../entities/AllEntities.hpp"

class UnitCreator {
public:
    virtual ~UnitCreator() = default;
    virtual std::unique_ptr<Unit> createUnit(int teamId) const = 0;
};

class SwordsmanCreator : public UnitCreator {
public:
    std::unique_ptr<Unit> createUnit(int teamId) const override {
        return std::make_unique<Swordsman>(teamId);
    }
};

class ArcherCreator : public UnitCreator {
public:
    std::unique_ptr<Unit> createUnit(int teamId) const override {
        return std::make_unique<Archer>(teamId);
    }
};

class MageCreator : public UnitCreator {
public:
    std::unique_ptr<Unit> createUnit(int teamId) const override {
        return std::make_unique<Mage>(teamId);
    }
};