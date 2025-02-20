// принимаем и распаковываем отправленные в примере packData_mini_send данные
// определять тип строения по сопротивлению, избавиться от attiny13?
// Определять местоположение строения по сигналу с разных пинов(со сдвигового регистра)

#include "../alldefs.h"

// --------------------------- CREATE OBJECTS ------------------------
gameField field(FIELD_SIZE);
TimerMs timerTower(0, 1);
TimerMs timerField(500, 1, 0);
TimerMs timerShow(500, 1, 0);
microLED<NUMLEDS, M_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> matrix(M_WIDTH, M_HEIGHT, ZIGZAG, LEFT_TOP, DIR_DOWN);

void setup()  {
  pinMode(RECEIVE_PIN, INPUT);
  Serial.begin(115200);
  field.addFactory(FIELD_SIZE-1, FIELD_SIZE-1, LOW_PLAYER);
  field.addFactory(0,0, HIGH_PLAYER);
  field.addWall(0, FIELD_SIZE/2);
  field.addWall(1, FIELD_SIZE/2);
  field.addWall(14, FIELD_SIZE/2);
  field.addWall(15, FIELD_SIZE/2);
  // matrix.setBrightness(0);
  // matrix.show();
}

void loop() {
// --------------------------- MOVE UNITS ----------------------------
  if(timerField.tick()) {
    field.createUnits();
    field.update();    
  }
  
// ---------------------------- PRINT FIELD --------------------------
  if(timerShow.tick())  {
    field.show();
  }
}
