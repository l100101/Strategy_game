#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#define BASE_RANGE_P1   2
#define BASE_RANGE_P2   2

#define BASE_HP_P1      100
#define BASE_HP_P2      100

#define BASE_DMG_P1     10
#define BASE_DMG_P2     10

#define BASE_DEF_P1     10
#define BASE_DEF_P2     10

#include <stdint.h>
#include <factory.h>
#include <vector>

class gameField
{
public:
    gameField(uint8_t size) : _size(size) {
        clear();  // Вызываем метод очистки
    }
    ~gameField() {};
    void addFactory(int x, int y);
    
    void update(){

        units_on_map.push_back(factories[0].createUnit());
        units_on_map[0].set_x(1);
        units_on_map[0].set_y(1);
    };

    bool getUnit(int8_t x, int8_t y){
        if (units_on_map[0].get_x() == x)
            return 1;
        return 0;
    };
    void clear();
    
    
    // void update(Unit *unit_p1,Unit *unit_p2);
private:
    uint8_t _size;
    // uint8_t units_on_map[8][8] = {0};
    std::vector<Factory> factories;
    std::vector<Unit> units_on_map;
};


#endif
