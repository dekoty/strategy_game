cmake_minimum_required(VERSION 3.10)
project(StrategyGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Позволяет писать #include "Board/GameBoard.hpp" вместо полного пути
include_directories(include)

# Собираем все исходники из папки src и подпапок + main.cpp
set(SOURCES
    main.cpp
    src/board/GameBoard.cpp
    src/mechanics/Action.cpp
    src/core/GameLoop.cpp
    src/core/Turn.cpp
    src/core/Player.cpp
)

# Создаем исполняемый файл
add_executable(StrategyGame ${SOURCES})