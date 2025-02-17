#include "gameField.h"
#include <Arduino.h>


void gameField::clear() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            units_on_map[i][j] = 0;
        }
    }
}

gameField::gameField(uint8_t size) {
    _size = size;
    clear();
}

void gameField::update(Unit *unit_p1, Unit *unit_p2) {
    units_on_map[unit_p1->get_y()][unit_p1->get_x()] = 1;
    units_on_map[unit_p2->get_y()][unit_p2->get_x()] = 1;

}