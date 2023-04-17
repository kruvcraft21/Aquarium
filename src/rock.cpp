#include "rock.h"
#include <math.h>

Rock::Rock()
{
    int posy = GetRandomValue(ZONA_ROCK_MIN, ZONA_ROCK_MAX);
    int posx = GetRandomValue(0, AQUARIUM_WIDTH);
    Coord = {(float)posx, (float)posy};
    size = AQUARIUM_HEIGTH - posy;
    colorbody = GRAY;
    offset_side1 = {(float)GetRandomValue(0, size), (float)GetRandomValue(ZONA_ROCK_MIN - posy, size)};
    offset_side2 = {(float)GetRandomValue(0, size), (float)size};
    offset_side3 = {(float)GetRandomValue(0, size), (float)size};
    offset_side4 = {(float)GetRandomValue(0, size), (float)GetRandomValue(ZONA_ROCK_MIN - posy, size)};
}

void Rock::Init()
{
    float pos_x = Coord.x, pos_y = Coord.y;
    pfd[0] = {pos_x - offset_side1.x, pos_y + offset_side1.y};
    pfd[1] = {pos_x - offset_side2.x, pos_y + offset_side2.y};
    pfd[2] = {pos_x + offset_side3.x, pos_y + offset_side3.y};
    pfd[3] = {pos_x + offset_side4.x, pos_y + offset_side4.y};
    Draw();
}

Vector2* Rock::get_pfd()
{
    return pfd.get();
}
