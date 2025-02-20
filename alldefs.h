#ifndef ALLDEFS_H
#define ALLDEFS_H

// #include "../lib/GyverBus/GBUSmini.h" // мини-библиотека с лёгкими функциями
// #include "lib/tower/tower.h"
// #include "lib/unit/unit.h"
#include <microLED.h>
#include <TimerMs.h>   
#include <gameField.h>
// #include "lib/gameField/gameField.h"
// #include <factory.h>
// #include <unit.h>
// #include "lib/factory/factory.h" // <"factory.h>
#include <Arduino.h>
#include <EncButton.h>
#include <ArduinoSTL.h>
// #include <GyverIO.h>

#define COLOR_DEBTH 3
#define M_PIN 8       // пин матрицы
#define M_WIDTH 16    // ширина матрицы
#define M_HEIGHT 16    // высота матрицы
#define NUMLEDS (M_WIDTH * M_HEIGHT) // для удобства запомним и количство ледов


#define TRANSMIT_PIN 4  // пин для передачи
#define RECEIVE_PIN 5   // пин для приёма сигнала
#define FIELD_SIZE 16
#define STEPS_PER_FOR_UNIT_CREATE 2

extern TimerMs timerTower;
extern TimerMs timerField;
extern TimerMs timerShow;
extern gameField field;


// Unit unit_p1(0, 0);
// Unit unit_p2(7, 7);
// Объявление структуры для юнитов
// struct Factory
// {
//   int x;
//   int y;
//   int health;
//   int tear;
//   int cost;
// };
// Factory factory_p1;
// Factory factory_p2;

// struct Tower
// {
//   int x;
//   int y;
//   int health;
//   int dmg;
//   int tear;
//   int cost;
// };

// struct MEX
// { // Mass Extractor
//   int x;
//   int y;
//   int health;
//   int tear;
//   int mass_per_sec;
//   int cost;
// };



#endif