#include <windows.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Clears console screen (Windows only)
void clearScreen() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD homeCoords = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD cellCount;

    if (hConsole == INVALID_HANDLE_VALUE) return;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

    cellCount = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, ' ', cellCount, homeCoords, &count);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, homeCoords, &count);
    SetConsoleCursorPosition(hConsole, homeCoords);
}

// Configure serial port
bool setupSerial(HANDLE& serialPort, const std::string& portName) {
    serialPort = CreateFile(portName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (serialPort == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Cannot open port!\n";
        return false;
    }

    DCB dcbSerialParams = {0};
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(serialPort, &dcbSerialParams)) {
        std::cerr << "Error: Cannot get port settings!\n";
        return false;
    }

    dcbSerialParams.BaudRate = CBR_115200;  
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.Parity = NOPARITY;
    dcbSerialParams.StopBits = ONESTOPBIT;

    if (!SetCommState(serialPort, &dcbSerialParams)) {
        std::cerr << "Error: Cannot apply port settings!\n";
        return false;
    }

    return true;
}

// Read serial data frame-by-frame (using "---" as delimiter)
bool readSerialFrame(HANDLE serialPort, std::vector<std::vector<int>>& grid, int gridSize) {
    static std::string buffer;
    char tempBuffer[64];
    DWORD bytesRead;

    if (ReadFile(serialPort, tempBuffer, sizeof(tempBuffer) - 1, &bytesRead, NULL) && bytesRead > 0) {
        tempBuffer[bytesRead] = '\0';
        buffer += tempBuffer;

        size_t pos;
        while ((pos = buffer.find("---")) != std::string::npos) {
            std::string frameData = buffer.substr(0, pos);
            buffer.erase(0, pos + 3); // Remove "---" separator

            std::vector<std::vector<int>> newGrid(gridSize, std::vector<int>(gridSize, 0));
            size_t row = 0;
            size_t start = 0;
            size_t end;

            while ((end = frameData.find('\n', start)) != std::string::npos && row < gridSize) {
                std::string line = frameData.substr(start, end - start);
                start = end + 1;

                size_t col = 0;
                size_t numStart = 0;
                size_t numEnd;

                while ((numEnd = line.find(' ', numStart)) != std::string::npos && col < gridSize) {
                    std::string token = line.substr(numStart, numEnd - numStart);
                    
                    if (!token.empty() && std::all_of(token.begin(), token.end(), ::isdigit)) {
                        newGrid[row][col] = std::stoi(token);
                    } else {
                        newGrid[row][col] = 0;  // Если ошибка - ставим 0
                    }
                
                    numStart = numEnd + 1;
                    col++;
                }
                
                if (col < gridSize) {
                    newGrid[row][col] = std::stoi(line.substr(numStart));
                }

                row++;
            }

            grid = newGrid;
            return true;
        }
    }

    return false;
}

int main() {
    std::string portName;
    std::cout << "Enter COM port (e.g., COM3): ";
    std::cin >> portName;
    portName = "\\\\.\\" + portName;

    HANDLE serialPort;
    if (!setupSerial(serialPort, portName)) return 1;

    const int gridSize = 8;
    std::vector<std::vector<int>> grid(gridSize, std::vector<int>(gridSize, 0));

    while (true) {
        if (readSerialFrame(serialPort, grid, gridSize)) {
            clearScreen();

            for (const auto& row : grid) {
                for (int cell : row) {
                    std::cout << (cell > 128 ? '#' : '.');  
                }
                std::cout << '\n';
            }
        }

        Sleep(50);
    }

    CloseHandle(serialPort);
    return 0;
}
