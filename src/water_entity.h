#pragma once

#include "raylib.h"

#define AQUARIUM_HEIGTH 450
#define AQUARIUM_WIDTH 800
#define MAX_POINTS 5
#define SIZE2H (float)sqrt(3) / 2

class Entity
{
protected:
    Vector2 *pfd = new Vector2[MAX_POINTS]; // points for draw
    Color colorbody;
    int size;
    Vector2 position;

public:
    virtual void Init() = 0;
    virtual void Draw() = 0;
};