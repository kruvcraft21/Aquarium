#include "water_entity.h"

void Entity::Draw()
{
    DrawTriangleFan(this->pfd, MAX_POINTS, this->colorbody);
}