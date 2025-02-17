#pragma once

#define BASE_RANGE_P1   2
#define BASE_RANGE_P2   2

#define BASE_HP_P1      100
#define BASE_HP_P2      100

#define BASE_DMG_P1     10
#define BASE_DMG_P2     10

#define BASE_DEF_P1     10
#define BASE_DEF_P2     10

#define BASE_SPEED_P1   10
#define BASE_SPEED_P2   10

#include "../alldefs.h"
#include "../unit/unit.h"

class gameField
{
public:
    gameField(uint8_t size);
    ~gameField();
    void clear();
    void update(Unit *unit_p1,Unit *unit_p2);
private:
    uint8_t _size;
    uint8_t units_on_map[8][8] = {0};

};
