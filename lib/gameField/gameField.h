#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#define ATTACK_RANGE    1
#define BASE_RANGE_P1   2
#define BASE_RANGE_P2   2

#define BASE_HP_P1      100
#define BASE_HP_P2      100

#define BASE_DMG_P1     10
#define BASE_DMG_P2     10

#define BASE_DEF_P1     10
#define BASE_DEF_P2     10


#include <stdint.h>
#include <factory.h>
#include <vector>
#include <wall.h>
#include <pool.h>

#define COLOR_BLACK     0
#define COLOR_RED       1
#define COLOR_GREEN     2
#define COLOR_BLUE      3
#define COLOR_WHITE     4
#define COLOR_YELLOW    5
#define COLOR_PINK      6
#define COLOR_GRAY      7
#define COLOR_BROWN     8
#define COLOR_ORANGE    9
#define COLOR_TBLUE     10

class gameField
{
public:
    gameField(uint8_t size) : _size(size) {
        pool.set_x(size/2, size/2 - 1, size/2, size/2 - 1);
        pool.set_y(size/2, size/2, size/2-1, size/2-1);
    }
    ~gameField() {};
    void addFactory(int8_t x, int8_t y, int8_t player);
    void addWall(int8_t x, int8_t y);
    void checkMoveField(Unit *unit);

    Unit* checkAttackRange(std::vector<Unit>& units, std::vector<Unit>::iterator it);
    void update();
    void createUnits();

    bool getUnitExist(int8_t x, int8_t y);
    bool getFactoryExist(int8_t x, int8_t y);
    bool getWallExist(int8_t x, int8_t y);
    bool getPoolExist(int8_t x, int8_t y);
    void poolGenerateCoin();
    void poolStealCoin(int8_t player);
    void calculateDirection(Unit& unit);
    void clear();
    void show();
    
private:
    Pool pool;
    uint8_t _size;
    std::vector<Factory>factories;
    std::vector<Unit>   units_on_map;
    std::vector<Wall>   walls_on_map;
    uint64_t steps_count = 0;
    
};


#endif
