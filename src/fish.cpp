#include "fish.h"
#include <math.h>

Fish::Fish(int mass, Vector2 pos)
{
    this->mass = mass;
    this->position = pos;
    this->Init();
}

Fish::Fish()
{
    this->mass = (GetRandomValue(1, 3) * 10);
    this->position = {(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
    this->Init();
}

void Fish::Init()
{
    this->colorbody = BLACK;
    this->coloreye = WHITE;
    this->Draw();
}

void Fish::Draw()
{
    float posx = this->position.x, posy = this->position.y;
    float rad = this->rotate * DEG2RAD;
    float h = ((this->mass * (float)sqrt(3)) / 2);
    float r = this->mass / 2;
    this->pfd[0] = {
        posx + (h * sinf(rad)),
        posy - (h * cosf(rad))
    };
    this->pfd[1] = {
        posx - (r * (cosf(rad))),
        posy - (r * (sinf(rad)))
    };
    this->pfd[2] = {
        posx + (r * cosf(rad)),
        posy + (r * sinf(rad))
    };
    this->pfd[3] = {
        posx - (r * (cosf(rad - RAD45))),
        posy - (r * (sinf(rad - RAD45)))
    };
    this->pfd[4] = {
        posx + (r * cosf(rad + RAD45)),
        posy + (r * sinf(rad + RAD45))
    };
    DrawTriangle(this->pfd[0], this->pfd[1], this->pfd[2], this->colorbody);
    DrawTriangle(this->position, this->pfd[3], this->pfd[4], this->colorbody);
}

void Fish::set_rot(float rot) {
    this->rotate = rot;
}