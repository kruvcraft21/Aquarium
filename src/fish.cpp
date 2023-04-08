#include "fish.h"
#include <math.h>

#define MAX_DIST 200
#define MIN_DIST 10
#define RAD90 90 * DEG2RAD
#define MAX_MASS 4
#define MAX_SIZE MAX_MASS * 10

Fish::Fish(unsigned int mass, Vector2 pos)
{
    this->mass = mass % MAX_MASS;
    this->size = mass * 10;
    this->position = pos;
    this->speed = MAX_MASS - mass;
    this->choose_color();
}

Fish::Fish()
{
    this->mass = GetRandomValue(1, MAX_MASS - 1);
    this->size = mass * 10;
    this->speed = MAX_MASS - mass;
    this->position = {
        (float)GetRandomValue(MAX_SIZE, GetScreenWidth() - MAX_SIZE),
        (float)GetRandomValue(MAX_SIZE, GetScreenHeight() - MAX_SIZE)};
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
    float r = (float)this->size;
    this->pfd[0] = {
        posx - (r * (cosf(rad - RAD45))),
        posy - (r * (sinf(rad - RAD45)))};
    this->pfd[1] = position;
    this->pfd[2] = {
        posx + (r * cosf(rad + RAD45)),
        posy + (r * sinf(rad + RAD45))};
    this->Draw();
}

void Fish::Draw()
{
    DrawLineStrip(this->pfd, MAX_POINTS, this->colorbody);
}

Obstacle Fish::Look(Rock *rock)
{
    Obstacle danger = {0, WHITE, this->distance};
    for (int i = 0; i < MAX_ROCK; i++)
    {
        Vector2 *rock_pfd = rock[i].get_pfd();
        for (int j = 1; j <= this->distance; j++)
        {
            Vector2 point = {position.x + (direction.x * j), position.y + (direction.y * j)};
            if (CheckCollisionPointTriangle(point, rock_pfd[0], rock_pfd[1], rock_pfd[2]) ||
                CheckCollisionPointCircle(point, rock_pfd[0], (float)this->size))
            {
                if (danger.distance > j)
                {
                    danger.ishit = true;
                    danger.color = rock[i].get_colorbody();
                    danger.distance = j;
                }
            }
        }
    }
    return danger;
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
    this->distance = GetRandomValue(MIN_DIST, MAX_DIST);
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

void Fish::Run(Rock *rock)
{
    if (this->distance > 0 && !this->CheckWall())
    {
        Obstacle danger = this->Look(rock);
        if (danger.ishit && danger.distance - speed <= this->size)
        {
            this->distance = 0;
            return;
        }
        this->distance -= this->speed;
        this->position.x += this->direction.x * this->speed;
        this->position.y += this->direction.y * this->speed;
    }
    else
    {
        this->set_route();
    }
}