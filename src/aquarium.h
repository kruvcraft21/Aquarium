#pragma once

#include "fish.h"
#include "rock.h"
#include <memory>

class Aquarium
{
private:
    std::unique_ptr<Fish[]> fish; // Указатель на массив объектов Fish
    std::unique_ptr<Rock[]> rock; // Указатель на массив объектов Rock
    int width; // Ширина аквариума
    int height; // Высота аквариума

public:
    Aquarium(); // Конструктор класса Aquarium
    void Init(); // Метод инициализации аквариума
    void Run(); // Метод запуска цикла обновления и отрисовки аквариума
    // Метод для создания и получения единственного экземпляра аквариума
    static Aquarium& getInstance() {
        static Aquarium instance;
        return instance;
    }
    Rock* get_rocks();
};
