#ifndef UNIT_H
#define UNIT_H

#include <Arduino.h>

class Unit
{
    public:
        Unit(int x, int y);
        Unit();
        ~Unit();
        uint8_t get_x();
        uint8_t get_y();
    private:
        int _x;
        int _y;
        int health;
        int tear;
        int cost;
    };

extern Unit unit_p1;
extern Unit unit_p2;

#endif