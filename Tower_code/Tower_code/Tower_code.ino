// пакуем данные любого типа (например, структура) в буфер и отправляем
// принимаем и распаковываем в примере packData_mini_read

//Code for tower. any tower have adress, struct of data and LED indicator

#include "GBUSmini.h"	// мини-библиотека с лёгкими функциями

#define TX_PIN 4    // пин
#define RX_ADDR 3   // адрес приёмника
#define TX_ADDR 5   // наш адрес

// структура для отправки
struct Tower {
  byte val_b;
  int val_i;
  float val_f;
  byte x;
  byte y;
  byte health;
  byte dmg;
  byte tear;
  byte cost;
  byte team;
  //String "Tower";
};
bool flag =0;

Tower txData;              // отправная структура
byte buffer[sizeof(txData)];  // отправной буфер

void setup() {
  // ПИН ОБЯЗАТЕЛЬНО PULLUP!!!111
  pinMode(TX_PIN, INPUT_PULLUP);

  // заполняем структуру
  Tower.x = 2;
  Tower.y = 2;
  Tower.dmg = 1;

  // пакуем структуру в буфер
  packDataBytes(buffer, txData);
}

void loop() {
  // пин, адрес получателя, адрес отправителя, дата, размер
  if(flag)
  GBUS_send(TX_PIN, RX_ADDR, TX_ADDR, buffer, sizeof(buffer));
  delay(2000);
}
