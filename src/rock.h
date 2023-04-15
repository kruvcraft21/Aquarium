#pragma once

#include "water_entity.h"
#include "raylib.h"

class Rock : Entity
{
private:
    float r1 = 0;
    float r2 = 0;
    Vector2 offset_side1 = {0, 0};
    Vector2 offset_side2 = {0, 0};

public:
    Rock();
    void Init();
    Vector2 *get_pfd();
    Color get_colorbody() { return this->colorbody; }
};