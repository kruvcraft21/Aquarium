#pragma once

#include "raylib.h"

#define AQUARIUM_HEIGTH 450
#define AQUARIUM_WIDTH 800
#define MAX_POINTS 3
#define ZONA_ROCK_MIN AQUARIUM_HEIGTH - (AQUARIUM_HEIGTH / 5)
#define ZONA_ROCK_MAX AQUARIUM_HEIGTH - 40
#define MAX_FISH 10
#define MAX_ROCK 10

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