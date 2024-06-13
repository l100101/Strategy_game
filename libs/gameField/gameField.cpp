#include "GameField.h"

class GameField
{
private:
    static const int fieldSize = 15;
    char field[fieldSize][fieldSize];
    
public:
    void clearField();
    GameField()
    {
        for (int i = 0; i < fieldSize; ++i)
        {
            for (int j = 0; j < fieldSize; ++j)
            {
                field[i][j] = ' ';
            }
        }
    }

    void moveUnit(char unit, int newX, int newY)
    {
        if (newX < 0 || newX >= fieldSize || newY < 0 || newY >= fieldSize)
        {
            return;
        }
        for (int i = 0; i < fieldSize; ++i)
        {
            for (int j = 0; j < fieldSize; ++j)
            {
                if (field[i][j] == unit)
                {
                    field[i][j] = ' ';
                }
            }
        }
        field[newX][newY] = unit;
    }

    void updateField()
    {
        for (int i = 0; i < fieldSize; ++i)
        {
            for (int j = 0; j < fieldSize; ++j)
            {
                Serial.print(field[i][j]);
            }
            Serial.println();
        }
    }
};
