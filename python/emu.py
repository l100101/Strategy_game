import pygame
import serial

# Параметры матрицы
WIDTH, HEIGHT = 400, 400
GRID_SIZE = 16
PIXEL_SIZE = WIDTH // GRID_SIZE

# Инициализация Serial (укажи правильный порт)
ser = serial.Serial("COM9", 115200, timeout=1)

# Инициализация Pygame
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))

def read_serial():
    grid = [[0] * GRID_SIZE for _ in range(GRID_SIZE)]
    buffer = []

    while True:
        line = ser.readline().decode().strip()
        print(f"Received: {line}")  # <-- Выведем входные данные
        if line == "---":
            break
        if line:  # Игнорируем пустые строки
            buffer.append(list(map(int, line.split())))

    # print("Parsed buffer:", buffer)  # Посмотрим, что получилось
    
    # Проверим размеры буфера
    if len(buffer) != GRID_SIZE or any(len(row) != GRID_SIZE for row in buffer):
        print("Warning: Incorrect grid size received!")
        return grid  # Вернём пустую сетку, чтобы избежать ошибки

    for y, row in enumerate(buffer):
        for x, value in enumerate(row):
            grid[y][x] = value
    return grid


def draw_grid(grid):
    screen.fill((0, 0, 0))
    for y in range(GRID_SIZE):
        for x in range(GRID_SIZE):
            color = (grid[y][x], 128, grid[y][x])  # Оттенки серого
            pygame.draw.rect(screen, color, (x * PIXEL_SIZE, y * PIXEL_SIZE, PIXEL_SIZE, PIXEL_SIZE))
    pygame.display.flip()

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    grid = read_serial()
    draw_grid(grid)

pygame.quit()
ser.close()
