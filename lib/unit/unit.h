#ifndef UNIT_H
#define UNIT_H

#include <Arduino.h>

#define HIGH_PLAYER 1
#define LOW_PLAYER  2

#define TYPE_UNIT_TANK      0
#define TYPE_UNIT_SOLDIER   1
#define TYPE_UNIT_SNIPER    2

class Unit
{
    public:
        Unit(int8_t x, int8_t y, int8_t player) : _x(x), _y(y), _player(player), _health(1) {};
        ~Unit(){};
        

        uint8_t get_x(void) const { return _x; }
        uint8_t get_y(void) const { return _y; }
        void set_x(int8_t x) { _x = x; }
        void set_y(int8_t y) { _y = y; }
        void moveX(int8_t x) { 
            if (_player == LOW_PLAYER) _x -= x;
            if (_player == HIGH_PLAYER) _x += x;
        }
        void moveY(int y) {
            if (_player == LOW_PLAYER) _y -= y;
            if (_player == HIGH_PLAYER) _y += y;
        }
        void damaged(int8_t dmg) { _health -= dmg; }
        int8_t get_health() const { return _health; }
        int8_t get_player() const { return _player; }
    // private:
    protected:
        int8_t _x;
        int8_t _y;
        int8_t _health;
        int8_t _tear;
        int8_t _cost;
        int8_t _player;
        int8_t _unit_type;
};

#endif