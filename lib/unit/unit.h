#pragma once

#include "../alldefs.h"
#include <Arduino.h>

class Unit
{
    public:
        Unit(int x, int y);
        ~Unit();
        uint8_t get_x();
        uint8_t get_y();
    private:
        int x;
        int y;
        int health;
        int tear;
        int cost;
    };