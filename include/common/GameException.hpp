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

class NotYourUnitException : public GameException {
public:
    NotYourUnitException() : GameException("Попытка управления чужим юнитом!") {}
};

class FriendlyFireException : public GameException {
public:
    FriendlyFireException() : GameException("Нельзя атаковать своих союзников!") {}
};

class InvalidInputException : public GameException {
public:
    InvalidInputException() 
        : GameException("Ошибка ввода. Ожидались числовые координаты (x1 y1 x2 y2).") {}
};

