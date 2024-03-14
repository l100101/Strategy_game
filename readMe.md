# Strategy game
- Поле - Arduino nano + LED Matrix
- Строения - Attiny13 

## Железки 
- Arduino nano 
- Attiny13 x10
- Светодиодная матрица 15х15
- Сдвиговый регистр 74HC595 x2
- Энкодер х2
- Пьезоэлемент 

## Поле
В обоих углах каждого игрока находится  сооружения(светодиод), которые необходимо уничтожить
Юниты движутся каждый тик автоматически от установленной в слот башни 
 

## Строения 
- Главное сооружение 
- Оборонная башня 
- Завод юнитов 1
- Завод юнитов 2
- Завод юнитов 3


## Юниты 
- Стандартный - 1 пиксель. Движение (?)
- 
- 
- 

## Связь
- OneWire
- UART (башни только на передачу, Arduino инициирует сообщение подачей напряжения на attiny через 74hc595, возможно)

## Библиотеки
- 
- 
- 
