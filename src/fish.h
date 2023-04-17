#pragma once

#include "water_entity.h"
#include "rock.h"
#include "food.h"

#define RAD60 60.0f * DEG2RAD

typedef struct Obstacle
{
    bool ishit;
    Color color;
    int distance;
} Obstacle;

class Fish : Entity
{
private:
    int mass = 1;
    float rotate = 0;
    int distance = 0;
    Vector2 direction = {0, 0};
    int speed = 1;
    void choose_color();
    void set_route();

public:
    void eats(int m);
    Vector2 get_Coord();
    void Init();
    Obstacle Look(Rock *rock, Food *food);
    void Run(Rock *rock, Food *food);
    bool CheckWall();
    Fish(unsigned int mass, Vector2 pos);
    Fish();
};