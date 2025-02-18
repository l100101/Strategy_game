#ifndef FACTORY_H
#define FACTORY_H

#include <Arduino.h>
#include <unit.h>

class Factory {
    public:
        Factory(int x, int y);
        Unit createUnit();
        int get_x() const;
        int get_y() const;
    
    private:
        int _x, _y;
    };

#endif