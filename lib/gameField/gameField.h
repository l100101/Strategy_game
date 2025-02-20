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

class gameField
{
public:
    gameField(uint8_t size) : _size(size) {}
    ~gameField() {};
    void addFactory(int8_t x, int8_t y, int8_t player);
    void checkMoveField(Unit *unit);

    Unit* checkAttackRange(std::vector<Unit>& units, std::vector<Unit>::iterator it);
    void update();
    void createUnits();

    bool getUnitExist(int8_t x, int8_t y);
    void calculateDirection(Unit& unit);
    bool getFactoryExist(int8_t x, int8_t y);
    void clear();
    void show();
    
private:
    uint8_t _size;
    std::vector<Factory>factories;
    std::vector<Unit>   units_on_map;
    std::vector<Wall>   walls_on_map;
    uint64_t steps_count = 0;
};


#endif
