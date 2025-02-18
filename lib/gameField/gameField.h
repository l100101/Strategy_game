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
        units_on_map.push_back(factories[0].createUnit());
    }
    ~gameField() {};
    void addFactory(int8_t x, int8_t y, int8_t player);
    void checkMoveField()
    {
        // for(auto unit : units_on_map){
        //     if (unit.get_x() >= _size)
        //         // unit.set_x(0);
        //         unit.~Unit();
        //     if (unit.get_y() >= _size)
        //         unit.set_y(0);
        // }
        if (units_on_map[0].get_x() >= _size)
            units_on_map[0].set_x(0);
        if (units_on_map[0].get_y() >= _size)
            units_on_map[0].set_y(0);
    }
    void update(){
        for(auto unit : units_on_map){
            unit.moveX(1);
            unit.moveY(1);
        }
        checkMoveField();

    };

    void createUnits()
    {
        for (auto Factory : factories)
        {
            units_on_map.push_back(Factory.createUnit());
        }

    }

    bool getUnitExist(int8_t x, int8_t y){
        //возвращаем true если есть юнит в указанной координате
       return (x==units_on_map[0].get_x() && y==units_on_map[0].get_y());
    };
    void clear();
    
private:
    uint8_t _size;
    // uint8_t units_on_map[8][8] = {0};
    std::vector<Factory> factories;
    std::vector<Unit> units_on_map;
};


#endif
