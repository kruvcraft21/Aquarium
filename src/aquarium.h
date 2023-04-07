#pragma once

#include "fish.h"

#define MAX_FISH 5

class Aquarium
{
private:
    Fish *fish;
    int width;
    int heigth;


public:
    Aquarium();
    void Init();
    void Run();
};