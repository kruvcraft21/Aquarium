#include "rock.h"
#include <math.h>

#define MAX_HEIGTH_ROCK AQUARIUM_HEIGTH - 40
#define MIN_HEIGTH_ROCK AQUARIUM_HEIGTH - (AQUARIUM_HEIGTH / 8)

Rock::Rock()
{
    int posy = GetRandomValue(MIN_HEIGTH_ROCK, MAX_HEIGTH_ROCK);
    int posx = GetRandomValue(0, AQUARIUM_WIDTH);
    this->position = {(float)posx, (float)posy};
    this->size = AQUARIUM_HEIGTH - posy;
    this->colorbody = GRAY;
}

void Rock::Draw()
{
    DrawTriangle(this->position, this->pfd[0], this->pfd[1], this->colorbody);
}

void Rock::Init()
{
    float r = size / (2 * sqrt(3));
    float r2 = size / 2;
    this->pfd[0] = {
        this->position.x - r,
        this->position.y + this->size};
    this->pfd[1] = {
        this->position.x + r,
        this->position.y + this->size
    };
    this->clone_pfd[0] = {
        position.x, position.y
    };
    this->clone_pfd[1] = {
        this->pfd[0].x, this->pfd[0].y
    };
    this->clone_pfd[2] = {
        this->pfd[1].x, this->pfd[1].y
    };
    this->Draw();
}