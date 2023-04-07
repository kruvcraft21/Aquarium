#pragma once

#include "water_entity.h"
#include "raylib.h"

#define MAX_POINTS 5
#define RAD45 (45 * PI) / 180

class Fish : Entity
{
private:
    int mass;
    Vector2* pfd = new Vector2[MAX_POINTS]; // points for draw
    float rotate = 0;
    int size;
    Color colorbody;
    Color coloreye;
    Vector2 position;
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