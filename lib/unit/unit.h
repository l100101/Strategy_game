#ifndef UNIT_H
#define UNIT_H

#include <Arduino.h>

#define HIGH_PLAYER 1
#define LOW_PLAYER 2

class Unit
{
    public:
        Unit(int8_t x, int8_t y, int8_t player) : _x(x), _y(y), _player(player) {};
        ~Unit(){};

        uint8_t get_x() const { return _x; }
        uint8_t get_y() const { return _y; }
        void set_x(int x) { _x = x; }
        void set_y(int y) { _y = y; }
        void moveX(int8_t x) { 
            if (_player == LOW_PLAYER) _x += x;
            if (_player == HIGH_PLAYER) _x -= x;
        }
        void moveY(int y) {
            if (_player == LOW_PLAYER) _y -= y;
            if (_player == HIGH_PLAYER) _y += y;
        }

    private:
        int8_t _x;
        int8_t _y;
        int8_t health;
        int8_t tear;
        int8_t cost;
        int8_t _player;
    };

#endif