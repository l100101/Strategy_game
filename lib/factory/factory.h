#ifndef FACTORY_H
#define FACTORY_H

#include <Arduino.h>
#include <unit.h>
class Factory {
    public:
        Factory(int8_t x, int8_t y, int8_t player) : _x(x), _y(y), _player(player) {}
        ~Factory() {};
        Unit createUnit(int8_t player);
        Unit moveUnit();
        int get_x() const;
        int get_y() const;
        void set_x(int x);
        void set_y(int y);
        int8_t get_player() const;
    
    private:
        int _x, _y, _player;
    };

#endif