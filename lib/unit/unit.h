#ifndef UNIT_H
#define UNIT_H

#include <Arduino.h>

#define HIGH_PLAYER 1
#define LOW_PLAYER  2

#define TYPE_UNIT_TANK      0
#define TYPE_UNIT_SOLDIER   1
#define TYPE_UNIT_SNIPER    2

enum unit_dir {
    DIR_U_NONE        = 0,
    DIR_U_UP          = 1,
    DIR_U_DOWN        = 2,
    DIR_U_LEFT        = 3,
    DIR_U_RIGHT       = 4,
    DIR_U_UP_LEFT     = 5,
    DIR_U_UP_RIGHT    = 6,
    DIR_U_DOWN_LEFT   = 7,
    DIR_U_DOWN_RIGHT  = 8,
    DIR_U_VERTICAL    = 9,
    DIR_U_HORIZONTAL  = 10,
    DIR_U_COUNT       = 11
};
// #define DIR_NONE            0
// #define DIR_UP              1
// #define DIR_DOWN            2
// #define DIR_LEFT            3
// #define DIR_RIGHT           4
// #define DIR_UP_LEFT         5
// #define DIR_UP_RIGHT        6
// #define DIR_DOWN_LEFT       7
// #define DIR_DOWN_RIGHT      8
// #define DIR_VERTICAL        9
// #define DIR_HORIZONTAL      10
// #define DIR_COUNT           11

class Unit
{
    public:
        Unit(int8_t x, int8_t y, int8_t player) : _x(x), _y(y), _health(1), _player(player) {
            if (_player == LOW_PLAYER) _dir = DIR_U_DOWN_LEFT;
            if (_player == HIGH_PLAYER) _dir = DIR_U_DOWN_RIGHT;
        };
        ~Unit(){};
        

        uint8_t get_x(void) const { return _x; }
        uint8_t get_y(void) const { return _y; }
        void set_x(int8_t x) { _x = x; }
        void set_y(int8_t y) { _y = y; }
        void moveAuto() {
            if (_dir == DIR_U_NONE);
            if (_dir == DIR_U_UP)         _y--;
            if (_dir == DIR_U_DOWN)       _y++;
            if (_dir == DIR_U_LEFT)       _x--;
            if (_dir == DIR_U_RIGHT)      _x++;
            if (_dir == DIR_U_UP_LEFT)    { _y--; _x--; }
            if (_dir == DIR_U_UP_RIGHT)   { _y--; _x++; }
            if (_dir == DIR_U_DOWN_LEFT)  { _y++; _x--; }
            if (_dir == DIR_U_DOWN_RIGHT) { _y++; _x++; }
            if (_dir == DIR_U_VERTICAL    && _player == LOW_PLAYER)   { _y--; }
            if (_dir == DIR_U_VERTICAL    && _player == HIGH_PLAYER)  { _y++; }
            if (_dir == DIR_U_HORIZONTAL  && _player == LOW_PLAYER)   { _x--; }
            if (_dir == DIR_U_HORIZONTAL  && _player == HIGH_PLAYER)  { _x++; }
        } 

        void moveX(int8_t x) { 
            if (_player == LOW_PLAYER)  _x -= x;
            if (_player == HIGH_PLAYER) _x += x;
        }
        void moveY(int y) {
            if (_player == LOW_PLAYER)  _y -= y;
            if (_player == HIGH_PLAYER) _y += y;
        }
        void damaged(int8_t dmg)        { _health -= dmg; }
        int8_t get_health() const       { return _health; }
        int8_t get_player() const       { return _player; }
        int8_t get_direction() const    { return _dir; }
        void set_direction(int8_t dir)  { _dir = dir; }

    // private:
    protected:
        int8_t _x;
        int8_t _y;
        int8_t _health;
        int8_t _tear;
        int8_t _dir;
        int8_t _cost;
        int8_t _player;
        int8_t _unit_type;
};

#endif