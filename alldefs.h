#include "../lib/GyverBus/GBUSmini.h" // мини-библиотека с лёгкими функциями
#include "../lib/tower/tower.h"
#include "../lib/gameField/gameField.h"
#include "../lib/unit/unit.h"

#include <Arduino.h>
#include <TimerMs.h>   
#include <EncButton.h>
#include <ArduinoSTL.h>
// #include <GyverIO.h>

TimerMs timerTower(0, 1);