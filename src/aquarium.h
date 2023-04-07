#pragma once

#include "fish.h"
#include "rock.h"

#define MAX_FISH 10

class Aquarium
{
private:
    Fish *fish;
    Rock *rock;
    int width;
    int heigth;


public:
    Aquarium();
    void Init();
    void Run();
};