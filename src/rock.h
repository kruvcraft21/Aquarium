﻿#pragma once

#include "water_entity.h"
#include "raylib.h"

class Rock : Entity
{
public:
    Rock();
    void Init();
    void Draw();
    Vector2 *get_pfd();
    Color get_colorbody() { return this->colorbody; }
};