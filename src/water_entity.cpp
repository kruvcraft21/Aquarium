#include "water_entity.h"

void Entity::Draw()
{
    DrawTriangleFan(this->pfd.get(), MAX_POINTS, this->colorbody);
}