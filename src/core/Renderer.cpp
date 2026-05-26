#include "../../include/core/Renderer.hpp"
#include "../../include/common/Logger.hpp"
#include <iostream>
#include <cstdlib> 

void Renderer::renderBoard(GameBoard& board) {
    std::system("clear");
    std::cout << "   "; 
    for (int x = 0; x < 10; ++x) {
        if (x == 0) std::cout << " " << x << " ";
        else if (x > 0 && x < 10) std::cout << x << " "; 
        else std::cout << x; 
    }
    std::cout << "\n";

    for (int y = 0; y < 10; ++y) {
        if (y < 10) std::cout << " " << y << "| ";
        else std::cout << y << "| ";

        for (int x = 0; x < 10; ++x) {
            Cell& cell = board.getCell({x, y});
            std::shared_ptr<Unit> u = cell.getUnit();
            
            if (u != nullptr) {
                std::cout << u->getSymbol() << " ";
            } else if (cell.hasItem()) {
                std::cout << cell.getItem()->getSymbol() << " "; 
            } else {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
}

void Renderer::renderStats(Turn& turnManager) {
    std::cout << "\n=== СОСТОЯНИЕ ВОЙСК ===\n";
    
    for (auto& player : turnManager.getPlayers()) {
        std::cout << "Игрок " << player.getId() << " (" << player.getName() << "):\n";
        
        auto& units = player.getArmy().getUnits();
        if (units.empty()) {
            std::cout << "  [АРМИЯ УНИЧТОЖЕНА]\n";
            continue;
        }

        for (auto& unitPtr : units) {
            auto& stats = unitPtr->getStats();
            
            std::cout << "  [" << unitPtr->getSymbol() << "] "
                      << "HP: " << stats.hp << "/" << stats.maxHp << " | "
                      << "DMG: " << stats.damage;
            
            if (stats.maxMana > 0) {
                std::cout << " | MANA: " << stats.mana << "/" << stats.maxMana;
            }
            std::cout << "\n";
        }
        std::cout << "-----------------------\n";
    }
}

void Renderer::renderLogs() {
    const auto& logs = Logger::getMessages();
    if (!logs.empty()) {
        std::cout << "\n---СОБЫТИЯ ХОДА---\n";
        for (const auto& msg : logs) {
            std::cout << "-->" << msg << std::endl;
        }
        std::cout << "\n";
        Logger::clear(); 
    }
}

void Renderer::renderError(const std::string& errorMsg) {
    if (!errorMsg.empty()) {
        std::cout << "\n[ВНИМАНИЕ]: " << errorMsg << std::endl;
    }
}


void Renderer::renderWinner(const std::string& winnerName) {
    std::cout << "\nИГРА ОКОНЧЕНА\nПОБЕДИТЕЛЬ: " << winnerName << std::endl;
}