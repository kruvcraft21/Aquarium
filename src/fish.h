#pragma once

#include "water_entity.h"

#define RAD45 (45 * PI) / 180

class Fish : Entity
{
private:
    int mass;
    float rotate = 0;
    Color coloreye;
    int step = 0;
    Vector2 direction;
    int speed = 1;
    void choose_color();
    void set_route();

public:
    void Init();
    void Draw();
    int Look();
    void Run();
    bool CheckWall();
    Fish(unsigned int mass, Vector2 pos);
    Fish();
};