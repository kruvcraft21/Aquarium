﻿#include "fish.h"
#include <math.h>
#include <iostream>

#define MAX_DIST 50
#define MIN_DIST 3
#define RAD90 90 * DEG2RAD
#define MAX_MASS 4
#define MAX_SIZE MAX_MASS * 10
#define ROCKCOLOR 2189591295

Fish::Fish(unsigned int m, Vector2 pos) : mass((m % (MAX_MASS - 1)) + 1)
{

    this->size = this->mass * 10;
    this->Coord = pos;
    this->choose_color();
}

Fish::Fish() : mass(GetRandomValue(1, MAX_MASS - 1))
{
    this->size = mass * 10;
    this->Coord = {(float)GetRandomValue(MAX_SIZE, AQUARIUM_WIDTH - MAX_SIZE),
                   (float)GetRandomValue(MAX_SIZE, ZONA_ROCK_MIN - MAX_SIZE)};
    this->choose_color();
}

void Fish::choose_color()
{
    switch (this->size)
    {
    case 10:
        this->colorbody = VIOLET;
        break;
    case 20:
        this->colorbody = RED;
        break;
    default:
        this->colorbody = BLACK;
        break;
    }
}

Vector2 Fish::get_Coord()
{
    return this->Coord;
}

void Fish::Init()
{
    // Обновляем скорость на основе массы
    this->speed = MAX_MASS - mass;

    // Вычисляем синусы и косинусы углов для повышения производительности
    float rad = this->rotate;
    float sin_rad = sinf(rad); // Синус угла поворота
    float cos_rad = cosf(rad); // Косинус угла поворота
    float cos_rad_minus_rad60 = cosf(rad - RAD60); // Косинус разницы угла поворота и 60 градусов
    float sin_rad_minus_rad60 = sinf(rad - RAD60); // Синус разницы угла поворота и 60 градусов
    float cos_rad_plus_rad60 = cosf(rad + RAD60); // Косинус суммы угла поворота и 60 градусов
    float sin_rad_plus_rad60 = sinf(rad + RAD60); // Синус суммы угла поворота и 60 градусов

    // Вычисляем координаты точек для отрисовки тела рыбы
    float posx = this->Coord.x, posy = this->Coord.y; // Координаты центра рыбы
    float r = static_cast<float>(this->size); // Радиус тела рыбы
    float hight = r / 5.0f;
    this->pfd[0] = {
        posx + (hight * sin_rad), // Координаты вершины рыбы на основе синуса и косинуса угла поворота
        posy - (hight * cos_rad)};
    this->pfd[1] = {
        posx - (r * cos_rad_minus_rad60), // Координаты левой боковой рыбы на основе косинуса разницы угла поворота и 60 градусов
        posy - (r * sin_rad_minus_rad60)}; 
    this->pfd[2] = {
        posx - (hight * sin_rad), // Координаты нижней точки рыбы на основе синуса и косинуса угла поворота
        posy + (hight * cos_rad)};
    this->pfd[3] = {
        posx + (r * cos_rad_plus_rad60), // Координаты правой рыбы точки на основе косинуса суммы угла поворота и 60 градусов
        posy + (r * sin_rad_plus_rad60)};

    // Вызываем метод Draw() для отрисовки рыбы
    this->Draw();
}

bool lineLine(float current_pointx, float current_pointy, float next_pointx, float next_pointy,
              float start_linex, float start_liney, float end_linex, float end_liney, int &dist)
{
    // Вычисление разностей координат для улучшения читаемости кода
    float dx1 = next_pointx - current_pointx;
    float dy1 = next_pointy - current_pointy;
    float dx2 = end_linex - start_linex;
    float dy2 = end_liney - start_liney;

    // Вычисление знаменателя для определения точек пересечения
    float gamma = dy1 * dx2 - dx1 * dy2;

    // Проверка на деление на ноль
    if (gamma == 0)
    {
        return false;
    }

    // Вычисление параметров uA и uB для определения точек пересечения
    float uA = ((dx1) * (start_liney - current_pointy) - (dy1) * (start_linex - current_pointx)) / gamma;
    float uB = ((dx2) * (start_liney - current_pointy) - (dy2) * (start_linex - current_pointx)) / gamma;

    // Проверка на нахождение точек пересечения на отрезках
    if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1)
    {
        // Вычисление расстояния между точками пересечения и текущей точкой
        float distX = uA * dx2;
        float distY = uA * dy2;
        dist = (int)floor(sqrt((distX * distX) + (distY * distY)));
        return true;
    }

    return false;
}

void CheckCollisionLines(Vector2 *line, Vector2 *points, int points_cout, Obstacle &obstacle)
{
    int dist = obstacle.distance;
    int next = 0;
    float end_liney = line[1].y;
    float end_linex = line[1].x;
    float start_liney = line[0].y;
    float start_linex = line[0].x;
    for (int current = 0; current < points_cout; current++)
    {
        next = (current + 1) % points_cout;

        float current_pointx = points[current].x;
        float current_pointy = points[current].y;
        float next_pointx = points[next].x;
        float next_pointy = points[next].y;

        if (lineLine(current_pointx, current_pointy, next_pointx, next_pointy, start_linex, start_liney, end_linex, end_liney, dist))
        {
            obstacle.ishit = true;
            if (dist < obstacle.distance)
            {
                obstacle.distance = dist;
            }
        }
    }
}

Obstacle Fish::Look(Rock *rock)
{
    Obstacle danger = {0, WHITE, this->distance};
    for (int i = 0; i < MAX_ROCK; i++)
    {
        Vector2 *rock_pfd = rock[i].get_pfd();
        Vector2 line_dir[2];
        line_dir[0] = Coord;
        line_dir[1] = {Coord.x + (direction.x * this->distance), Coord.y + (direction.y * this->distance)};
        CheckCollisionLines(line_dir, rock_pfd, MAX_POINTS, danger);
        if (danger.ishit)
        {
            danger.color = rock[i].get_colorbody();
        }
    }
    return danger;
}

Vector2 GetRandomVector()
{
    int x = GetRandomValue(-1, 1);
    int y = GetRandomValue(-1, 1);
    while (x == 0 && y == 0)
    {
        x = GetRandomValue(-1, 1);
        y = GetRandomValue(-1, 1);
    }
    return {(float)x, (float)y};
}

void Fish::set_route()
{
    this->direction = GetRandomVector();
    this->distance = GetRandomValue(MIN_DIST, MAX_DIST) * this->speed;
    this->rotate = (float)atan2(direction.y, direction.x) + RAD90;
}

bool Fish::CheckWall()
{
    int posx = (int)this->Coord.x + (int)(this->size * this->direction.x);
    int posy = (int)this->Coord.y + (int)(this->size * this->direction.y);
    bool a = posx > AQUARIUM_WIDTH || posx < 0;
    bool b = posy > AQUARIUM_HEIGTH || posy < 0;
    return a || b;
}

void Fish::Run(Rock *rock)
{
    if (this->distance > 0 && !this->CheckWall())
    {
        Obstacle obstacle = this->Look(rock);
        if (obstacle.ishit)
        {
            switch (ColorToInt(obstacle.color))
            {
            case ROCKCOLOR:
                if (obstacle.distance - size <= size)
                {
                    this->set_route();
                    return;
                }
                break;
            }
        }

        this->distance -= this->speed;
        this->Coord.x += this->direction.x * this->speed;
        this->Coord.y += this->direction.y * this->speed;
    }
    else
    {
        this->set_route();
    }
}