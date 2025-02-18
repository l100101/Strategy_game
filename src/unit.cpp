#include "unit.h"


Unit::Unit(int x, int y)
{
    this->_x = x;
    this->_y = y;
}
Unit::Unit(){}
Unit::~Unit() {}

uint8_t Unit::get_x() { return _x; }

uint8_t Unit::get_y() { return _y; }