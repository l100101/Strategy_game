#pragma once

#include "../lib/GyverBus/GBUSmini.h" // мини-библиотека с лёгкими функциями
#include "../lib/tower/tower.h"
#include "../lib/gameField/gameField.h"
#include "../lib/unit/unit.h"

#include <Arduino.h>
#include <TimerMs.h>   
#include <EncButton.h>
#include <ArduinoSTL.h>
// #include <GyverIO.h>

#define TRANSMIT_PIN 4 // пин для передачи
#define RECEIVE_PIN 5  // пин для приёма сигнала


TimerMs timerTower(0, 1);
TimerMs timerField(1000, 1, 0);
TimerMs timerSend(1001, 1, 0);

gameField field(8);


Unit unit_p1(0, 0);
Unit unit_p2(7, 7);
// Объявление структуры для юнитов
struct Factory
{
  int x;
  int y;
  int health;
  int tear;
  int cost;
};
Factory factory_p1;
Factory factory_p2;

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

// struct Unit
// {
//   int x;
//   int y;
//   int health;
//   int dmg;
//   int tear;
//   int cost;
// };
