// принимаем и распаковываем отправленные в примере packData_mini_send данные
// определять тип строения по сопротивлению, избавиться от attiny13?
// Определять местоположение строения по сигналу с разных пинов(со сдвигового регистра)

#include "../alldefs.h"


gameField field(FIELD_SIZE);
TimerMs timerTower(0, 1);
TimerMs timerField(500, 1, 0);
TimerMs timerSend(500, 1, 0);


void setup()
{
  pinMode(RECEIVE_PIN, INPUT);
  Serial.begin(115200);
  field.addFactory(FIELD_SIZE-1, FIELD_SIZE-1, LOW_PLAYER);
  field.addFactory(0,0, HIGH_PLAYER);
}

void loop()
{
  // Послал сигнал, запустил таймер, жду ответа, останавливаю таймер
  // if (!flag)
  //   sendSignal();
  // recieving();

  // --------------------------- MOVE UNITS -----------------------------
  if(timerField.tick())
  {
    field.createUnits();
      
    field.update();

    // Serial.print(field.getUnitExist(0,0));
    // Serial.print(field.getUnitExist(1,0));
    // Serial.print(field.getUnitExist(2,0));
    // Serial.print(field.getUnitExist(3,0));
    // Serial.print(field.getUnitExist(4,0));
    // Serial.print(field.getUnitExist(5,0));
    // Serial.print(field.getUnitExist(6,0));
    // Serial.print(field.getUnitExist(7,0));
    // Serial.println();
    
  }
  
  // ---------------------------- PRINT FIELD -----------------------------
  if(timerSend.tick())
  {
    for (int y = 0; y < FIELD_SIZE; y++) {
      for (int x = 0; x < FIELD_SIZE; x++) {
        // int color = units_on_map[y][x] ? 255 : 0;
        uint8_t color = 0;
        if( field.getUnitExist(x, y))
          color = 255;
        else if( field.getFactoryExist(x, y))
          color = 128;

        Serial.print(color); 
        Serial.print(" ");
      }
      Serial.println();
    }
    Serial.println("---"); // Разделитель кадров 
  }


}

// int checkForResponse(unsigned long duration, unsigned long window)
// {
//   unsigned long currentTime = millis();
//   unsigned long elapsed = currentTime - startTime;

//   // Проверяем, находится ли текущее время в "окне" погрешности
//   if ((elapsed >= duration - window) && (elapsed <= duration + window))
//   {
//     if (digitalRead(responsePin) == HIGH)
//     {
//       // Если пин в это время был в HIGH состоянии, ответ получен
//       return 1;
//     }
//   }
//   else if (elapsed > duration + window)
//   {
//     // Время истекло, ответа не было
//     return 0;
//   }
//   // Время еще не истекло, и ответа пока нет
//   return -1;
// }

// uint8_t field_callback_p1()
// {
//   digitalWrite(RECEIVE_PIN, HIGH);
//   for (int i = 1; i <= 5;)
//   {
//     int result = checkForResponse(i * 10, 2); // Проверяем наличие ответа в течение 50 мс с окном в 2 мс
//     if (result == 1 || result == 0)
//     {
//       Serial.println("Ответ получен в заданное время");
//       player1_towers[i] = result;
//       i++;
//     }
//   }

//   return 0;
// }