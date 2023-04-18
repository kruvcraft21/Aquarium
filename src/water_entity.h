#pragma once

#include "raylib.h"
#include <memory>

// Высота аквариума
constexpr int AQUARIUM_HEIGHT = 450;
// Ширина аквариума
constexpr int AQUARIUM_WIDTH = 800; 
// Максимальное количество точек для отрисовки
constexpr int MAX_POINTS = 4; 
// Минимальная высота для расположения объекта "скала" в зоне
constexpr int ZONA_ROCK_MIN = AQUARIUM_HEIGHT - (AQUARIUM_HEIGHT / 5);
// Максимальная высота для расположения объекта "скала" в зоне
constexpr int ZONA_ROCK_MAX = AQUARIUM_HEIGHT - 40; 
// Максимальное количество объектов "рыба"
constexpr int MAX_FISH = 10;
// Максимальное количество объектов "скала" 
constexpr int MAX_ROCK = 10; 

class Entity
{
protected:
    // Массив точек для отрисовки
    std::unique_ptr<Vector2[]> pfd = std::make_unique<Vector2[]>(MAX_POINTS);
    // Цвет тела объекта
    Color colorbody = BLACK; 
    // Размер объекта
    int size = 10;
    // Координаты объекта
    Vector2 Coord = {AQUARIUM_WIDTH / 2, AQUARIUM_HEIGHT / 2};

public:
    // Виртуальный метод инициализации объекта
    virtual void Init() = 0;
    // Метод отрисовки объекта
    void Draw(); 
};
