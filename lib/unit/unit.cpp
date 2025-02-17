#include "unit.h"

Unit::Unit(int x, int y)
{
    this->x = x;
    this->y = y;
}

Unit::~Unit() {}

uint8_t Unit::get_x() { return x; }

uint8_t Unit::get_y() { return y; }