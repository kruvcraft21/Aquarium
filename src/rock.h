#pragma once

#include "water_entity.h"
#include "raylib.h"

class Rock : Entity
{
public:
    Vector3 *clone_pfd = new Vector3[MAX_POINTS];
    Rock();
    void Init();
    void Draw();
};