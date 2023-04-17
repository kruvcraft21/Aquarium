#pragma once

#include "fish.h"
#include "rock.h"
#include "food.h"
#include <memory>

class Aquarium
{
private:
    std::unique_ptr<Fish[]> fish;
    std::unique_ptr<Rock[]> rock;
    int width;
    int heigth;
    std::unique_ptr<Food> food = nullptr;

public:
    Aquarium();
    void Init();
    void Run();
};