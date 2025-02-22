#ifndef POOL_H
#define POOL_H

#include <Arduino.h>

#define POOL_SIZE 4
class Pool
{
    public:
        Pool() : _isExist(true) {}   //size?
        ~Pool() {}
        void set_x(int8_t x1, int8_t x2, int8_t x3, int8_t x4) { _x[0] = x1; _x[1] = x2; _x[2] = x3; _x[3] = x4; }
        void set_y(int8_t y1, int8_t y2, int8_t y3, int8_t y4) { _y[0] = y1; _y[1] = y2; _y[2] = y3; _y[3] = y4; }
        bool getExist(int8_t x, int8_t y) {
            for (int i = 0; i < POOL_SIZE; i++) {
                if (_x[i] == x && _y[i] == y) 
                    return true;
            } 
            return 0;
        }
        void setExist(bool isExist) { _isExist = isExist; }
        int8_t get_size() { return _size; }
        int8_t get_x(int8_t index) { return _x[index]; }
        int8_t get_y(int8_t index) { return _y[index]; }
    private:
        int8_t _x[POOL_SIZE];
        int8_t _y[POOL_SIZE];
        bool _isExist; 
        int8_t _size = POOL_SIZE;
};

#endif