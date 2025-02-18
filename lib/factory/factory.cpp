#include "factory.h"

Factory::Factory(int x, int y) : _x(x), _y(y) {}

Unit Factory::createUnit() {
    return Unit(_x, _y);  // Юнит создаётся рядом с фабрикой
}



void Factory::set_x(int x) { _x = x; }
void Factory::set_y(int y) { _y = y; }

int Factory::get_x() const { return _x; }
int Factory::get_y() const { return _y; }

// Unit* Factory::createUnit(int x, int y) {
//     Unit* newUnit = new Unit(x, y);  // Создаём юнита динамически
//     _field->addUnit(newUnit);        // Добавляем его в игровое поле
//     return newUnit;                  // Возвращаем ссылку
// }

// Factory::~Factory() {}