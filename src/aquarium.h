#pragma once

#include "fish.h"
#include "rock.h"
#include <memory>

class Aquarium
{
private:
    std::unique_ptr<Fish[]> fish;
    std::unique_ptr<Rock[]> rock;
    int width;
    int height;

public:
    Aquarium();
    void Init();
    void Run();
};