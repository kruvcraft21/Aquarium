#pragma once

#include "raylib.h"
#include "fish.h"

class Food
{
private:
    Vector2 Coord = {0, 0};

public:
    Food(Vector2 pos);
    bool is_eaten(Fish *fishes);
    void Draw();
};