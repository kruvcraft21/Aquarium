#include "fish.h"
#include <math.h>

#define MAX_DIST 200
#define RAD90 90 * DEG2RAD

Fish::Fish(unsigned int mass, Vector2 pos)
{
    this->mass = mass % 4;
    this->size = mass * 10;
    this->position = pos;
    this->speed = 4 - mass;
    this->choose_color();
}

Fish::Fish()
{
    this->mass = GetRandomValue(1, 3);
    this->size = mass * 10;
    this->speed = 4 - mass;
    this->position = {(float)GetRandomValue(40, (float)GetScreenWidth() - 40), (float)GetRandomValue(40, (float)GetScreenHeight() - 40)};
    this->choose_color();
}

void Fish::choose_color()
{
    switch (this->size)
    {
    case 10:
        this->colorbody = VIOLET;
        break;
    case 20:
        this->colorbody = RED;
        break;
    default:
        this->colorbody = BLACK;
        break;
    }
    this->coloreye = WHITE;
}

void Fish::Init()
{
    float posx = this->position.x, posy = this->position.y;
    float rad = this->rotate;
    float h = this->size * SIZE2H;
    float r = (float)this->size / 2;
    this->pfd[0] = {
        posx + (h * sinf(rad)),
        posy - (h * cosf(rad))};
    this->pfd[1] = {
        posx - (r * (cosf(rad))),
        posy - (r * (sinf(rad)))};
    this->pfd[2] = {
        posx + (r * cosf(rad)),
        posy + (r * sinf(rad))};
    this->pfd[3] = {
        posx - (r * (cosf(rad - RAD45))),
        posy - (r * (sinf(rad - RAD45)))};
    this->pfd[4] = {
        posx + (r * cosf(rad + RAD45)),
        posy + (r * sinf(rad + RAD45))};
    this->Draw();
}

void Fish::Draw()
{
    DrawTriangle(this->pfd[0], this->pfd[1], this->pfd[2], this->colorbody);
    DrawTriangle(this->position, this->pfd[3], this->pfd[4], this->colorbody);
}

int Fish::Look()
{
    return 0;
}

Vector2 GetRandomVector()
{
    int x = GetRandomValue(-1, 1);
    int y = GetRandomValue(-1, 1);
    while (x == 0 && y == 0)
    {
        x = GetRandomValue(-1, 1);
        y = GetRandomValue(-1, 1);
    }
    return {(float)x, (float)y};
}

void Fish::set_route()
{
    this->direction = GetRandomVector();
    this->step = GetRandomValue(10, MAX_DIST);
    this->rotate = (float)atan2(direction.y, direction.x) + RAD90;
}

bool Fish::CheckWall()
{
    int posx = this->position.x + this->size * this->direction.x;
    int posy = this->position.y + this->size * this->direction.y;
    bool a = posx > AQUARIUM_WIDTH || posx < 0;
    bool b = posy > AQUARIUM_HEIGTH || posy < 0;
    return a || b;
}

void Fish::Run()
{
    if (this->step > 0 && !this->CheckWall())
    {
        this->step--;
        this->position.x += this->direction.x * this->speed;
        this->position.y += this->direction.y * this->speed;
    }
    else
    {
        this->set_route();
    }
}