#include "rock.h"
#include <math.h>

// Конструктор по умолчанию
Rock::Rock()
{
    // Инициализация координаты и размера объекта
    int posy = GetRandomValue(ZONA_ROCK_MIN, ZONA_ROCK_MAX); // Случайная координата Y в заданном диапазоне
    int posx = GetRandomValue(0, AQUARIUM_WIDTH); // Случайная координата X в диапазоне ширины аквариума
    Coord = {(float)posx, (float)posy}; // Установка координаты объекта
    size = AQUARIUM_HEIGHT - posy; // Вычисление размера объекта на основе его Y-координаты

    // Инициализация цвета и смещений точек объекта
    colorbody = GRAY; // Установка цвета тела объекта
    offset_side1 = {(float)GetRandomValue(0, size), (float)GetRandomValue(ZONA_ROCK_MIN - posy, size)}; // Смещение точки 1
    offset_side2 = {(float)GetRandomValue(0, size), (float)size}; // Смещение точки 2
    offset_side3 = {(float)GetRandomValue(0, size), (float)size}; // Смещение точки 3
    offset_side4 = {(float)GetRandomValue(0, size), (float)GetRandomValue(ZONA_ROCK_MIN - posy, size)}; // Смещение точки 4
}

// Метод инициализации объекта
void Rock::Init()
{
    float pos_x = Coord.x; // Координата X объекта
    float pos_y = Coord.y; // Координата Y объекта

    // Вычисление координат точек на основе смещений
    pfd[0] = {pos_x - offset_side1.x, pos_y + offset_side1.y}; // Координаты первой точки
    pfd[1] = {pos_x - offset_side2.x, pos_y + offset_side2.y}; // Координаты второй точки
    pfd[2] = {pos_x + offset_side3.x, pos_y + offset_side3.y}; // Координаты третьей точки
    pfd[3] = {pos_x + offset_side4.x, pos_y + offset_side4.y}; // Координаты четвертой точки

    Draw(); // Вызов функции отрисовки
}

// Метод получения указателя на массив точек для отрисовки
Vector2* Rock::get_pfd()
{
    return pfd.get();
}

// Метод получения цвета тела объекта
Color Rock::get_colorbody() {
    return this->colorbody;
}