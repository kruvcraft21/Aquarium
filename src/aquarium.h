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
    std::unique_ptr<Food> food = nullptr;


public:
    Aquarium();
    void Init();
    void Run();
};