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
    Color colorbody;
    Color coloreye;
    Vector2 position;
    void choose_color();

public:
    void Init();
    void Draw();
    void set_rot(float rot);
    Fish(int mass, Vector2 pos);
    Fish();
};