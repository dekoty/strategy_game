#pragma once

#include <exception>
#include <string>

class GameException: public std::exception {

    std::string message;

public:
    GameException(const std::string msg) : message(msg) {}

    virtual const char* what() const noexcept override { return message.c_str(); }
    

};


class OutOfRangeException: public GameException {
public:
    OutOfRangeException() : GameException("Клетка находится за пределами поля 10x10") {}

};


class EmptyCellExcpetion: public GameException {
public:
    EmptyCellExcpetion() : GameException("В выбранной клетке нет юнита") {}

};

