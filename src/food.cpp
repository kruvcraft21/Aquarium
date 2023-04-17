#include "food.h"

Food::Food(Vector2 pos)
{
    this->Coord = pos;
    this->Draw();
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

Vector2 Food::get_Coord()
{
    return this->Coord;
}