#pragma once

#include "fish.h"
#include "rock.h"
#include <memory>
#include <vector>

using namespace std;

class Aquarium final
{
private:
    vector<Fish> fishes; // Указатель на массив объектов Fish
    vector<Rock> rocks; // Указатель на массив объектов Rock
    int width; // Ширина аквариума
    int height; // Высота аквариума

private:
    Aquarium(); // Конструктор класса Aquarium

public:
    Aquarium(const Aquarium&) = delete;
    Aquarium operator=(const Aquarium&) = delete;
    void Init(); // Метод инициализации аквариума
    void Run(); // Метод запуска цикла обновления и отрисовки аквариума
    // Метод для создания и получения единственного экземпляра аквариума
    static Aquarium& getInstance() {
        static Aquarium instance;
        return instance;
    }
    const vector<Rock> &get_rocks() const;
};
