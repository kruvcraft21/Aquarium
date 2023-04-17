#pragma once

#include "raylib.h"
#include <memory>
#include <vector>

constexpr int AQUARIUM_HEIGHT = 450; // Высота аквариума
constexpr int AQUARIUM_WIDTH = 800; // Ширина аквариума
constexpr int MAX_POINTS = 4; // Максимальное количество точек для отрисовки
constexpr int ZONA_ROCK_MIN = AQUARIUM_HEIGHT - (AQUARIUM_HEIGHT / 5); // Минимальная высота для расположения объекта "скала" в зоне
constexpr int ZONA_ROCK_MAX = AQUARIUM_HEIGHT - 40; // Максимальная высота для расположения объекта "скала" в зоне
constexpr int MAX_FISH = 10; // Максимальное количество объектов "рыба"
constexpr int MAX_ROCK = 10; // Максимальное количество объектов "скала"

class Entity
{
protected:
    std::unique_ptr<Vector2[]> pfd = std::make_unique<Vector2[]>(MAX_POINTS); // Массив точек для отрисовки
    Color colorbody = BLACK; // Цвет тела объекта
    int size = 10; // Размер объекта
    Vector2 Coord = {AQUARIUM_WIDTH / 2, AQUARIUM_HEIGHT / 2}; // Координаты объекта

public:
    virtual void Init() = 0; // Виртуальный метод инициализации объекта
    void Draw(); // Метод отрисовки объекта
};
