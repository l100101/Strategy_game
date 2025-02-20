#ifndef WALL_H
#define WALL_H 

#include <Arduino.h>
class Wall {
public:
    Wall(int8_t x, int8_t y, int8_t width, int8_t height) : _x(x), _y(y), _width(width), _height(height) {};
    void set_x(int8_t x) { _x = x; }
    void set_y(int8_t y) { _y = y; }
    void set_xy(int8_t x, int8_t y) { _x = x; _y = y; }
    void set_width(int8_t width)    { _width = width; }
    void set_height(int8_t height)  { _height = height; }
    int8_t get_x(void) const { return _x; }
    int8_t get_y(void) const { return _y; }
private:
    int8_t _x;
    int8_t _y;
    int8_t _width;
    int8_t _height;
};

#endif

