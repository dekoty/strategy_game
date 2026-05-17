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


class EmptyCellException: public GameException {
public:
    EmptyCellException() : GameException("В выбранной клетке нет юнита") {}

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

class TargetOutOfRangeException : public GameException {
public:
    TargetOutOfRangeException()
        : GameException("Юнит не может совершить атаку на такой дистанции!") {}
};

class TooFarException : public GameException {
public:
    TooFarException() : GameException("Юнит не может уйти так далеко!") {}
};

class HealEnemyException : public GameException {
public:
    HealEnemyException() : GameException("Вражеских юнитов лечить нельзя") {}
};

class NotEnoughManaException : public GameException {
public:
    NotEnoughManaException() : GameException("Недостаточно маны!") {}
};
