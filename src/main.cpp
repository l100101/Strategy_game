// принимаем и распаковываем отправленные в примере packData_mini_send данные
// определять тип строения по сопротивлению, избавиться от attiny13?
// Определять местоположение строения по сигналу с разных пинов(со сдвигового регистра)

#include "../alldefs.h"

// --------------------------- CREATE OBJECTS ------------------------
gameField field(FIELD_SIZE);
TimerMs timerTower(0, 1);
TimerMs timerField(500, 1, 0);
TimerMs timerSend(500, 1, 0);


void setup()  {
  pinMode(RECEIVE_PIN, INPUT);
  Serial.begin(115200);
  field.addFactory(FIELD_SIZE-1, FIELD_SIZE-1, LOW_PLAYER);
  field.addFactory(0,0, HIGH_PLAYER);
}

void loop() {
// --------------------------- MOVE UNITS ----------------------------
  if(timerField.tick()) {
    field.createUnits();
    field.update();    
  }
  
// ---------------------------- PRINT FIELD --------------------------
  if(timerSend.tick())  {
    field.show();
  }
}
