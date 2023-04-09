#include "rock.h"
#include <math.h>

Rock::Rock()
{
    int posy = GetRandomValue(ZONA_ROCK_MIN, ZONA_ROCK_MAX);
    int posx = GetRandomValue(0, AQUARIUM_WIDTH);
    this->Coord = {(float)posx, (float)posy};
    this->size = AQUARIUM_HEIGTH - posy;
    this->colorbody = GRAY;
}

void Rock::Draw()
{
    DrawTriangleStrip(this->pfd, 3, this->colorbody);
}

void Rock::Init()
{
    float r = this->size / (float)sqrt(3);
    this->pfd[0] = this->Coord;
    this->pfd[1] = {
        this->Coord.x - r,
        this->Coord.y + this->size};
    this->pfd[2] = {
        this->Coord.x + r,
        this->Coord.y + this->size
    };
    this->Draw();
}

Vector2 *Rock::get_pfd() {
    return this->pfd;
}