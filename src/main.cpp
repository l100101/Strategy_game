// принимаем и распаковываем отправленные в примере packData_mini_send данные
// определять тип строения по сопротивлению, избавиться от attiny13?
// Определять местоположение строения по сигналу с разных пинов(со сдвигового регистра)

#include "../alldefs.h"
gameField field(8);
TimerMs timerTower(0, 1);
TimerMs timerField(1000, 1, 0);
TimerMs timerSend(1001, 1, 0);


// const int responsePin = 2; // Пин, на который приходит ответ от слота

// Количество юнитов, tower, MEX
// const int numberOfUnits = 30;
// const int numberOfTowers = 10;
// const int numberOfMEX = 10;

// Массив структур для хранения данных о юнитах
// Unit units[numberOfUnits];
// Tower towers[numberOfTowers];
// MEX mex[numberOfMEX];

// Factory rxFac; // приёмная структурs
// // Tower rxTow;
// Unit rxUnit;
// MEX rxMEX;
// byte bufferFac[sizeof(rxFac)];   // приёмный буфер
// // byte bufferTow[sizeof(rxTow)];   // приёмный буфер
// byte bufferUnit[sizeof(rxUnit)]; // приёмный буфер
// byte bufferMEX[sizeof(rxMEX)];   // приёмный буфер


void setup()
{
  pinMode(RECEIVE_PIN, INPUT);
  Serial.begin(115200);
  field.addFactory(7,7, LOW_PLAYER);
  field.addFactory(0,0, HIGH_PLAYER);
}

// bool flag = false;
// unsigned long startTime;

// uint8_t sendSignal()
// {
//   digitalWrite(TRANSMIT_PIN, HIGH);
//   digitalWrite(LED_BUILTIN, HIGH);
//   startTime = millis();
//   flag = 1;

//   return 0;
// }

// uint8_t recieving()
// {
//   if (digitalRead(RECEIVE_PIN) == HIGH)
//   {
//     delayMicroseconds(50); // задержка 50 микросекунд для защиты от дребезга
    
//     if (digitalRead(RECEIVE_PIN) == LOW)//ложное 
//       return 0;

//     digitalWrite(TRANSMIT_PIN, LOW);
//     digitalWrite(LED_BUILTIN, LOW);

//     int recieve_time = millis() - startTime;
//     if (recieve_time > 15)
//       Serial.println(recieve_time);
//     flag = 0;
//   }
//   return 0;
// }

// void clear_field() {
//   for (int y = 0; y < 8; y++) {
//     for (int x = 0; x < 8; x++) {
//         units_on_map[y][x] = 0;
//     }
//   }
// }


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
    
    // factory_p1.createUnit();
    // factory_p2.createUnit();

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
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 8; x++) {
        // int color = units_on_map[y][x] ? 255 : 0;
        uint8_t color = field.getUnitExist(x, y) ? 255 : 0;
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