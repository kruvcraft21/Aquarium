#include "water_entity.h"

void Entity::Draw()
{
    // Отрисовка объекта в виде веера из треугольников
    // с использованием массива точек pfd, содержащего координаты вершин треугольников,
    // количества точек MAX_POINTS и цвета colorbody, определяющего цвет тела объекта
    DrawTriangleFan(this->pfd.get(), MAX_POINTS, this->colorbody);
}