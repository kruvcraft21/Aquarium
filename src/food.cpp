#include "food.h"

Food::Food(Vector2 pos)
{
    this->Coord = pos;
    this->Draw();
}

bool Food::is_eaten(Fish *fish)
{
    bool eaten = false;
    for (int i = 0; i < MAX_FISH; i++)
    {
        if (CheckCollisionPointCircle(fish[i].get_Coord(), this->Coord, radius))
        {
            eaten = true;
            fish[i].eats(1);
        }
    }
    return eaten;
}

int Food::get_radius()
{
    return this->radius;
}

Color Food::get_color()
{
    return this->color;
}

void Food::Draw()
{
    DrawCircleV(Coord, radius, color);
}