#include "food.h"

Food::Food(Vector2 pos)
{
    this->Coord = pos;
    this->Draw();
}

bool Food::is_eaten(Fish *fishes)
{
    bool eaten = false;
    for (int i = 0; i < MAX_FISH; i++)
    {
        Fish fish = fishes[i];
        if (CheckCollisionPointCircle(fish.get_Coord(), this->Coord, 5)) {
            eaten |= true;
            fishes[i].eats(1);
        }
    }
    return eaten;
}

void Food::Draw()
{
    DrawCircleV(Coord, 5, YELLOW);
}