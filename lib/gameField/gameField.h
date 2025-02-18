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
        // units_on_map.push_back(factories[0].createUnit());
    }
    ~gameField() {};
    void addFactory(int8_t x, int8_t y, int8_t player);
    void checkMoveField()
    {
        auto it = units_on_map.begin();
        while (it != units_on_map.end()) {
            if (it->get_x() >= _size || it->get_y() >= _size) {
                it = units_on_map.erase(it); // erase возвращает следующий итератор
            } else {
                ++it; // Переход к следующему элементу, если не удаляем
            }
        }
        // Serial.println("Units on map: " + String(units_on_map.size()));
    }
    void update(){
        auto it = units_on_map.begin();
        while (it != units_on_map.end()) {
            // it->moveX(1);
            it->moveY(1);
            ++it;
        }

        // for(size_t i = 0; i < units_on_map.size(); i++){
        //     units_on_map[i].moveX(1);
        //     units_on_map[i].moveY(1);
        //     // Serial.print(units_on_map[i].get_x());
        //     // Serial.print(units_on_map[i].get_y());
        //     // Serial.println(i);
        // }
        checkMoveField();

    };

    void createUnits()
    {
        for (auto Factory : factories)
        {
            units_on_map.push_back(Factory.createUnit(Factory.get_player()));
        }
    }

    bool getUnitExist(int8_t x, int8_t y){
        //возвращаем true если есть юнит в указанной координате
    //    return (x==units_on_map[0].get_x() && y==units_on_map[0].get_y());
       for( auto unit : units_on_map){
           if (unit.get_x() == x && unit.get_y() == y)
               return true;
       }
       return 0;
    };

    bool getFactoryExist(int8_t x, int8_t y){
        //возвращаем true если есть factory в указанной координате
        for( auto Factory : factories){
            if (Factory.get_x() == x && Factory.get_y() == y)
                return true;
        }
        return 0;
    }
    void clear();
    
private:
    uint8_t _size;
    // uint8_t units_on_map[8][8] = {0};
    std::vector<Factory> factories;
    std::vector<Unit> units_on_map;
};


#endif
