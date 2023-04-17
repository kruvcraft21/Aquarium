#pragma once

#include "raylib.h"
#include "fish.h"

class Food
{
private:
    int radius = 5;
    Color color = YELLOW; 
    Vector2 Coord = {0, 0};

public:
    Food(Vector2 pos);
    bool is_eaten(Fish *fishes);
    void Draw();
    int get_radius();
    Color get_color();
};