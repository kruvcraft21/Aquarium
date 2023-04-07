#pragma once

#define AQUARIUM_HEIGTH 450
#define AQUARIUM_WIDTH 800

class Entity
{
public:
    virtual void Init() = 0;
    virtual void Draw() = 0;
};