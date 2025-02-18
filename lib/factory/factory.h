#ifndef FACTORY_H
#define FACTORY_H

#include <Arduino.h>
#include <unit.h>

class Factory {
    public:
        Factory(int x, int y);
        Unit createUnit();
        Unit moveUnit();
        int get_x() const;
        int get_y() const;
        void set_x(int x);
        void set_y(int y);
    
    private:
        int _x, _y;
    };

#endif