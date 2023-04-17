#pragma once

#include "raylib.h"

class Food
{
private:
    int radius = 5;
    Color color = YELLOW; 
    Vector2 Coord = {0, 0};

public:
    Food(Vector2 pos);
    void Draw();
    int get_radius();
    Color get_color();
    Vector2 get_Coord();
};