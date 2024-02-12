// принимаем и распаковываем отправленные в примере packData_mini_send данные
//определять тип строения по сопротивлению, избавиться от attiny13?
//Определять местоположение строения по сигналу с разных пинов(со сдвигового регистра)

#include "GBUSmini.h"  // мини-библиотека с лёгкими функциями

#define RX_PIN 4    // пин
#define RX_ADDR 1   // наш адрес

// структурs для приёма
// Объявление структуры для юнитов
struct Factory {
  int x;
  int y;
  int health;
  int tear;
  int cost;
};

struct Tower {
  int x;
  int y;
  int health;
  int dmg;
  int tear;
  int cost;
};

struct MEX { //Mass Extractor
  int x;
  int y;
  int health;
  int tear;
  int mass_per_sec;
  int cost;
};
struct Unit {
  int x;
  int y;
  int health;
  int dmg;
  int tear;
  int cost;
};

// Количество юнитов, tower, MEX
const int numberOfUnits = 30;
const int numberOfTowers = 10;
const int numberOfMEX = 10;

// Массив структур для хранения данных о юнитах
Unit units[numberOfUnits];
Tower towers[numberOfTowers];
MEX mex[numberOfMEX];

Factory rxFac;              // приёмная структурs
Tower rxTow;
Unit rxUnit;
MEX rxMEX;
byte bufferFac[sizeof(rxFac)];  // приёмный буфер
byte bufferTow[sizeof(rxTow)];  // приёмный буфер
byte bufferUnit[sizeof(rxUnit)];  // приёмный буфер
byte bufferMEX[sizeof(rxMEX)];  // приёмный буфер

void setup() {
  // ПИН ОБЯЗАТЕЛЬНО PULLUP!!!111
  pinMode(RX_PIN, INPUT_PULLUP);
  // Инициализация данных о юнитах (вы можете использовать свою логику инициализации)
  for (int i = 0; i < numberOfUnits; ++i) {
    units[i].x = random(15);  // Пример: случайные координаты от 0 до 14
    units[i].y = random(15);
    units[i].health = random(1, 100);  // Пример: случайное здоровье от 1 до 99
  }

  // Инициализация последовательной связи для вывода данных в монитор порта
  Serial.begin(9600);
}

void loop() {
  // Ваш основной игровой цикл здесь
  if (GBUS_read(RX_PIN, RX_ADDR, bufferTow, sizeof(bufferTow))) {
    // если успешно приняли, распаковываем
    unpackDataBytes(bufferTow, rxTow);
    // выводим проверяем
    Serial.println(rxTow.x);
    Serial.println(rxTow.y);
    Serial.println(rxTow.dmg);
    Serial.println();
  }
  
  // Вывод данных о юнитах, у которых хп не равно нулю
  for (int i = 0; i < numberOfUnits; ++i) {
    if (units[i].health != 0) {
      // Вывод информации о юните
      Serial.print("Unit ");
      Serial.print(i);
      Serial.print(" | X: ");
      Serial.print(units[i].x);
      Serial.print(" Y: ");
      Serial.print(units[i].y);
      Serial.print(" Health: ");
      Serial.println(units[i].health);
    }
  }

  // Задержка для читаемости вывода
  delay(1000);
}
