#include "rock.h"
#include <math.h>

#define ZONA_ROCK_MIN AQUARIUM_HEIGTH - (AQUARIUM_HEIGTH / 5)
#define ZONA_ROCK_MAX AQUARIUM_HEIGTH - 40

Rock::Rock()
{
    int posy = GetRandomValue(ZONA_ROCK_MIN, ZONA_ROCK_MAX);
    int posx = GetRandomValue(0, AQUARIUM_WIDTH);
    this->position = {(float)posx, (float)posy};
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
    this->pfd[0] = this->position;
    this->pfd[1] = {
        this->position.x - r,
        this->position.y + this->size};
    this->pfd[2] = {
        this->position.x + r,
        this->position.y + this->size
    };
    this->Draw();
}

Vector2 *Rock::get_pfd() {
    return this->pfd;
}