#pragma once

#include "water_entity.h"
#include "raylib.h"

class Rock : Entity
{
private:
    Vector2 offset_side1; // Смещение для первой точки объекта
    Vector2 offset_side2; // Смещение для второй точки объекта
    Vector2 offset_side3; // Смещение для третьей точки объекта
    Vector2 offset_side4; // Смещение для четвертой точки объекта

public:
    Rock(); // Конструктор по умолчанию
    void Init() override; // Метод инициализации объекта
    Vector2 *get_pfd(); // Метод получения указателя на массив точек для отрисовки
    Color get_colorbody(); // Метод получения цвета тела объекта
};