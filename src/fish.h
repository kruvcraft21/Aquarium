﻿#pragma once

#include "water_entity.h"
#include "rock.h"

#define RAD60 60.0f * DEG2RAD

typedef struct Obstacle
{
    bool isdetected; // Флаг, указывающий на обнаружение препятствия
    Color color; // Цвет обнаруженного препятствия
    int distance; // Расстояние до обнаруженного препятствия
} Obstacle;

class Fish : Entity
{
private:
    int mass = 1; // Масса рыбы
    float rotate = 0; // Угол поворота рыбы
    int distance = 0; // Расстояние, на которое рыба должна продвинуться
    Vector2 direction = {0, 0}; // Направление движения рыбы
    int speed = 1; // Скорость движения рыбы

private:
    Obstacle Look(); // Метод для поиска препятствий впереди рыбы
    bool CheckWall(); // Метод для проверки столкновения с границами аквариума
    void choose_color(); // Внутренний метод для выбора цвета рыбы
    void set_route(); // Внутренний метод для установки нового маршрута движения рыбы


public:
    void Init(); // Метод для инициализации рыбы
    void Run(); // Метод для выполнения движения рыбы
    Fish(unsigned int mass, Vector2 pos); // Конструктор с параметрами массы и начальных координат рыбы
    Fish(); // Конструктор по умолчанию
};
