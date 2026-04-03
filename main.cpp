#include <iostream>
#include <string>

struct Point {

    int x,y;
};

class Unit {
    int hp;
    int damage;
    std::string symbol = ".";

public:
    Unit(std::string sym = ".") : hp(100), damage(10), symbol(sym) {}

    std::string getSymbol() { return symbol; }
    void setSymbol(std::string sym) { symbol = sym; }
};

class Mage: public Unit {
public:
    Mage() : Unit("M") {}
};

class Swordsman: public Unit {
public:
    Swordsman(): Unit("S") {}
};

class Archer: public Unit {
public:
    Archer(): Unit("A") {}
};

class Cell {
bool status;
Unit* unit;

public:
    Cell() : status(false), unit(nullptr) {}

    Unit* getUnit() { return unit; }
    void setUnit(Unit* newObj) { unit = newObj;}

    bool getStatus() { return status; }

    void setStatus(bool st) { status = st; }
};

class GameBoard {
    static const int SIZE = 10;
    Cell board[SIZE][SIZE];

public:
    GameBoard() {
        Unit* wall = new Unit("#");

        setUnitInBoard(wall,Point{5, 5});
    }

    void setUnitInBoard(Unit* u, Point p) {
        board[p.y][p.x].setUnit(u);
        board[p.y][p.x].setStatus(true);
    }

    Cell& getCell(const Point& p) {
        return board[p.y][p.x];

    }


    void moveUnit(Point from, Point target) {
        Cell& cellFrom = getCell(from);
        Cell& cellTarget = getCell(target);

        cellTarget.setUnit(cellFrom.getUnit());
        cellTarget.setStatus(true);

        cellFrom.setUnit(nullptr);
        cellFrom.setStatus(false);

    }

    void render() {
        for (int y = 0; y < SIZE; ++y) {
            for (int x = 0; x < SIZE; ++x) {
                if (board[y][x].getUnit() != nullptr) {
                    std::cout << board[y][x].getUnit()->getSymbol() << " ";
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << std::endl;
        }
    }
};

class Action {
    Point from;
    Point target;

public:
    Action(Point fm, Point tar) : from(fm), target(tar) {}


    void setAction(Point fm, Point tg) {
        from = fm;
        target = tg;
    }

    void execute(GameBoard&  realBoard) {
        Cell& cell = realBoard.getCell(target);
        if (!cell.getStatus()) {
            realBoard.moveUnit(from, target);
        }
    }
};

int main() {
    GameBoard gm;

    Mage* m = new Mage();
    Archer* a = new Archer();
    Swordsman* s = new Swordsman;

    Action ac(Point{5,5}, Point{0,0});

    gm.setUnitInBoard(m,Point{2,2});

    gm.setUnitInBoard(a, Point{3,3});

    gm.render();

    ac.execute(gm);

    std::cout << "\n";

    gm.render();

    return 0;
}

