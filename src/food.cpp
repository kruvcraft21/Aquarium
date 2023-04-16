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
        if (CheckCollisionPointCircle(fish[i].get_Coord(), this->Coord, 5)) {
            eaten |= true;
            fish[i].eats(1);
        }
    }
    return eaten;
}

void Food::Draw()
{
    DrawCircleV(Coord, 5, YELLOW);
}