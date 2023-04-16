#pragma once

#include "fish.h"
#include "rock.h"
#include "food.h"

class Aquarium
{
private:
    Fish *fish;
    Rock *rock;
    int width;
    int heigth;
    Food *food = NULL;


public:
    Aquarium();
    void Init();
    void Run();
};