#pragma once
#include <memory>
#include "../entities/AllEntities.hpp"

class UnitCreator {
public:
    virtual ~UnitCreator() = default;
    virtual std::shared_ptr<Unit> createUnit(int teamId) const = 0;
};

class SwordsmanCreator : public UnitCreator {
public:
    std::shared_ptr<Unit> createUnit(int teamId) const override {
        return std::make_shared<Swordsman>(teamId);
    }
};

class ArcherCreator : public UnitCreator {
public:
    std::shared_ptr<Unit> createUnit(int teamId) const override {
        return std::make_shared<Archer>(teamId);
    }
};

class MageCreator : public UnitCreator {
public:
    std::shared_ptr<Unit> createUnit(int teamId) const override {
        return std::make_shared<Mage>(teamId);
    }
};