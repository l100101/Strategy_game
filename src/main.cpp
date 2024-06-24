// принимаем и распаковываем отправленные в примере packData_mini_send данные
// определять тип строения по сопротивлению, избавиться от attiny13?
// Определять местоположение строения по сигналу с разных пинов(со сдвигового регистра)


#include "../alldefs.h"


#define RX_PIN 4   // пин
#define RX_ADDR 1  // наш адрес
#define CALL_PIN 5 // пин для вызова приёма

const int responsePin = 2; // Пин, на который приходит ответ от слота
unsigned long startTime;
// структурs для приёма
// Объявление структуры для юнитов
struct Factory
{
  int x;
  int y;
  int health;
  int tear;
  int cost;
};

// struct Tower
// {
//   int x;
//   int y;
//   int health;
//   int dmg;
//   int tear;
//   int cost;
// };

struct MEX
{ // Mass Extractor
  int x;
  int y;
  int health;
  int tear;
  int mass_per_sec;
  int cost;
};
struct Unit
{
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

Factory rxFac; // приёмная структурs
Tower rxTow;
Unit rxUnit;
MEX rxMEX;
byte bufferFac[sizeof(rxFac)];   // приёмный буфер
byte bufferTow[sizeof(rxTow)];   // приёмный буфер
byte bufferUnit[sizeof(rxUnit)]; // приёмный буфер
byte bufferMEX[sizeof(rxMEX)];   // приёмный буфер

uint8_t player1_towers[]={0};

void setup()
{
  // ПИН ОБЯЗАТЕЛЬНО PULLUP!!!111
  pinMode(RX_PIN, INPUT_PULLUP);
  pinMode(responsePin, INPUT_PULLUP);
  // Инициализация данных о юнитах (вы можете использовать свою логику инициализации)
  for (int i = 0; i < numberOfUnits; ++i)
  {
    units[i].x = random(15); // Пример: случайные координаты от 0 до 14
    units[i].y = random(15);
    units[i].health = random(1, 100); // Пример: случайное здоровье от 1 до 99
  }

  // Инициализация последовательной связи для вывода данных в монитор порта
  Serial.begin(9600);
}

void loop()
{
  field_callback_p1();
  delay(100);
}

int checkForResponse(unsigned long duration, unsigned long window)
{
  unsigned long currentTime = millis();
  unsigned long elapsed = currentTime - startTime;

  // Проверяем, находится ли текущее время в "окне" погрешности
  if ((elapsed >= duration - window) && (elapsed <= duration + window))
  {
    if (digitalRead(responsePin) == HIGH)
    {
      // Если пин в это время был в HIGH состоянии, ответ получен
      return 1;
    }
  }
  else if (elapsed > duration + window)
  {
    // Время истекло, ответа не было
    return 0;
  }
  // Время еще не истекло, и ответа пока нет
  return -1;
}

uint8_t field_callback_p1()
{
  digitalWrite(CALL_PIN, HIGH);
  for (int i = 1; i <= 5;)
  {
    int result = checkForResponse(i * 10, 2); // Проверяем наличие ответа в течение 50 мс с окном в 2 мс
    if (result == 1 || result == 0)
    {
      Serial.println("Ответ получен в заданное время");
      player1_towers[i] = result;
      i++;
    }
  }

  return 0;
}