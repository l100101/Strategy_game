#include "gameField.h"
void gameField::addFactory(int8_t x, int8_t y, int8_t player) {
    factories.push_back(Factory(x, y, player));
}

void gameField::addWall(int8_t x, int8_t y) {
    walls_on_map.push_back(Wall(x, y));
}
void gameField::checkMoveField(Unit *unit)
{
    if (unit->get_x() < 0 || unit->get_x() >= _size || unit->get_y() < 0 || unit->get_y() >= _size) 
       unit = units_on_map.erase(unit);     // erase возвращает следующий итератор
    // auto it = units_on_map.begin();
    // while (it != units_on_map.end()) {
        // if (it->get_x() >= _size || it->get_y() >= _size) {
            // it = units_on_map.erase(it); // erase возвращает следующий итератор?
        // } else {
        //     ++it; // Переход к следующему элементу, если не удаляем
        // }
    // }
    // Serial.println("Units on map: " + String(units_on_map.size()));
}

Unit* gameField::checkAttackRange(std::vector<Unit>& units, std::vector<Unit>::iterator it) {
    int8_t x = it->get_x();
    int8_t y = it->get_y();
    int8_t player = it->get_player();
    int8_t attackRange = ATTACK_RANGE; // Можно заменить на it->getAttackRange(), если такое есть

    for (auto enemy_it = units.begin(); enemy_it != units.end(); ++enemy_it) {
        if (enemy_it == it) continue; // Пропускаем самого себя

        if (enemy_it->get_player() != player) { // Проверяем, что это юнит противника
            int dx = abs(enemy_it->get_x() - x);
            int dy = abs(enemy_it->get_y() - y);

            if (dx <= attackRange && dy <= attackRange) {
                // Serial.println("Enemy in range!");
                return enemy_it; // Достаточно одного попадания в радиус
            }
        }
    }

    // Serial.println("No enemies in range.");
    return 0;
}

void gameField::calculateDirection(Unit& unit) {
    int8_t new_dir = DIR_U_VERTICAL;

    if (unit.get_x() > _size/2 && unit.get_player() == LOW_PLAYER)
        unit.set_direction(DIR_U_UP);
    if (unit.get_x() < _size/2-1 && unit.get_player() == HIGH_PLAYER)        
        unit.set_direction(DIR_U_DOWN);
    
    auto wall = walls_on_map.begin();
    while (wall != walls_on_map.end()) {
        if (unit.get_y() == wall->get_y() && unit.get_x() == wall->get_x())
            unit.set_direction(DIR_U_HORIZONTAL);

        // if (unit.get_direction() == DIR_U_UP )  {
        //     if (unit.get_y()-1 == wall->get_y())    {
        //         new_dir = DIR_U_HORIZONTAL;
        //         unit.set_direction(new_dir);
        //     }
        // }
        // else if (unit.get_direction() == DIR_U_DOWN) {
        //     if (unit.get_y()+1 == wall->get_y())    {
        //         new_dir = DIR_U_HORIZONTAL;
        //         unit.set_direction(new_dir);
        //     }
        // }
        // else if (unit.get_direction() == DIR_U_LEFT) {
        //     if (unit.get_x()-1 == wall->get_x())    {
        //         new_dir = DIR_U_VERTICAL;
        //         unit.set_direction(new_dir);
        //     }
        // }
        // else if (unit.get_direction() == DIR_U_RIGHT) {
        //     if (unit.get_x()+1 == wall->get_x())    {
        //         new_dir = DIR_U_VERTICAL;
        //         unit.set_direction(new_dir);
        //     }
        // else {
        //     unit.set_direction(new_dir);
        // }
    // }
    // if unit.find(wall);
    // unit.set_direction(DIR_U_HORIZONTAL);
        wall++;
    }
}

void gameField::update(){
    auto it = units_on_map.begin();
    while (it != units_on_map.end()) {
        checkMoveField(it);
//-------------------------------SET_DIRECTION UNITS-----------------------------
        calculateDirection(*it);    // Устанавливаем направление движения для каждого юнита

        // if (it->get_x() > _size/2 && it->get_player() == LOW_PLAYER)
        //     it->set_direction(DIR_UP_LEFT);
        
        // if (it->get_x() < _size/2-1 && it->get_player() == HIGH_PLAYER)        
        //     it->set_direction(DIR_DOWN_RIGHT);
//-------------------------------ATTACK UNITS------------------------------------
        Unit* enemy = checkAttackRange(units_on_map, it);   //проверяем наличие противника в радиусе каждого юнита
            if (enemy) {    //если увидели противника, наносим и получаем урон
                enemy->damaged(1);
                it->damaged(1);
                if (it->get_health() <= 0) 
                {
                    it = units_on_map.erase(it); // erase возвращает следующий итератор
                    it->set_direction(DIR_U_VERTICAL);
                }
                
                if (enemy->get_health() <= 0) {
                    enemy = units_on_map.erase(enemy); // erase возвращает следующий итератор
                    enemy->set_direction(DIR_U_VERTICAL);
                }
            }    
            
            
//-------------------------------MOVE UNITS------------------------------------
        it->moveAuto();
        ++it;
    }
    // checkMoveField();

    // for(size_t i = 0; i < units_on_map.size(); i++){
    //     units_on_map[i].moveX(1);
    //     units_on_map[i].moveY(1);
    //     // Serial.print(units_on_map[i].get_x());
    //     // Serial.print(units_on_map[i].get_y());
    //     // Serial.println(i);
    // }
    steps_count++;
}

void gameField::createUnits()
{
    if(steps_count%2 == 0)  {
    for (auto Factory : factories){
        units_on_map.push_back(Factory.createUnit(Factory.get_player()));
    }
    }
}

bool gameField::getUnitExist(int8_t x, int8_t y){
    //возвращаем true если есть юнит в указанной координате
//    return (x==units_on_map[0].get_x() && y==units_on_map[0].get_y());
   for( auto unit : units_on_map){
       if (unit.get_x() == x && unit.get_y() == y)
           return true;
   }
   return 0;
}

bool gameField::getWallExist(int8_t x, int8_t y){
   for( auto wall : walls_on_map){
       if (wall.get_x() == x && wall.get_y() == y)
           return true;
   }
   return 0;
}

bool gameField::getFactoryExist(int8_t x, int8_t y){
    //возвращаем true если есть factory в указанной координате
    for( auto Factory : factories){
        if (Factory.get_x() == x && Factory.get_y() == y)
            return true;
    }
    return 0;
}

void gameField::show(){
    for (int y = 0; y < _size; y++)
    {
        for (int x = 0; x < _size; x++)
        {
            // int color = units_on_map[y][x] ? 255 : 0;
            uint8_t color = 0;
            if (getUnitExist(x, y))
                color = 255;
            else if (getFactoryExist(x, y))
                color = 128;
            else if (getWallExist(x, y))
                color = 164;
            else
                color = 0;

            Serial.print(color);
            Serial.print(" ");
        }
        Serial.println();
    }
    Serial.println("---"); // Разделитель кадров
}