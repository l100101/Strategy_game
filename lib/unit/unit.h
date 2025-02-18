#ifndef UNIT_H
#define UNIT_H

#include <Arduino.h>

class Unit
{
    public:
        Unit(int x, int y) : _x(x), _y(y) {};
        ~Unit(){};
        uint8_t get_x() const { return _x; }
        uint8_t get_y() const { return _y; }
        void set_x(int x) { _x = x; }
        void set_y(int y) { _y = y; }
        

    private:
        int _x;
        int _y;
        int health;
        int tear;
        int cost;
    };

#endif