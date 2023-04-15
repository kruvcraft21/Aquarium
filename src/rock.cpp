#include "rock.h"
#include <math.h>

Rock::Rock()
{
    int posy = GetRandomValue(ZONA_ROCK_MIN, ZONA_ROCK_MAX);
    int posx = GetRandomValue(0, AQUARIUM_WIDTH);
    this->Coord = {(float)posx, (float)posy};
    this->size = AQUARIUM_HEIGTH - posy;
    this->colorbody = GRAY;
    this->offset_side1 = { (float)GetRandomValue(0, this->size), (float)GetRandomValue(-this->size, this->size)};
    this->offset_side2 = { (float)GetRandomValue(0, this->size), (float)GetRandomValue(-this->size, this->size)};
    this->r1 = GetRandomValue(0, this->size);
    this->r2 = GetRandomValue(0, this->size);
}

void Rock::Draw()
{
    DrawTriangleFan(this->pfd, MAX_POINTS, this->colorbody);
}

void Rock::Init()
{
    float pos_x = this->Coord.x, pos_y = this->Coord.y;
    this->pfd[0] = {
        pos_x - this->offset_side1.x,
        pos_y + this->offset_side1.y
    };
    this->pfd[1] = {
        pos_x - this->r1,
        pos_y + this->size
    };
    this->pfd[2] = {
        pos_x + this->r2,
        pos_y + this->size
    };
    this->pfd[3] = {
        pos_x + this->offset_side2.x,
        pos_y + this->offset_side2.y
    };
    this->Draw();
}

Vector2 *Rock::get_pfd() {
    return this->pfd;
}