﻿#pragma once

#include "raylib.h"
#include <memory>
#include <vector>

#define AQUARIUM_HEIGHT 450
#define AQUARIUM_WIDTH 800
#define MAX_POINTS 4
#define ZONA_ROCK_MIN AQUARIUM_HEIGHT - (AQUARIUM_HEIGHT / 5)
#define ZONA_ROCK_MAX AQUARIUM_HEIGHT - 40
#define MAX_FISH 10
#define MAX_ROCK 10

class Entity
{
protected:
    std::unique_ptr<Vector2[]> pfd = std::make_unique<Vector2[]>(MAX_POINTS); // points for draw
    Color colorbody = BLACK;
    int size = 10;
    Vector2 Coord = {AQUARIUM_WIDTH / 2, AQUARIUM_HEIGHT / 2};

public:
    virtual void Init() = 0;
    void Draw();
};