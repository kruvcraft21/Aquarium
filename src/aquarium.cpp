#include "aquarium.h"

// Конструктор класса Aquarium
Aquarium::Aquarium(){
    // Устанавливаем высоту аквариума равную заданному значению AQUARIUM_HEIGHT
    this->height = AQUARIUM_HEIGHT;
    // Устанавливаем ширину аквариума равную заданному значению AQUARIUM_WIDTH 
    this->width = AQUARIUM_WIDTH;
}

// Метод инициализации аквариума
void Aquarium::Init() {
    // Инициализация окна с использованием установленных значений высоты и ширины аквариума, а также заголовка окна "Aquarium"
    InitWindow(this->width, this->height, "Aquarium"); 
    // Устанавливаем целевое количество кадров в секунду (FPS) на 30
    SetTargetFPS(30); 
    // Создаем уникальный указатель на массив объектов типа Fish, выделяем память на максимальное количество рыб MAX_FISH
    this->fishes.resize(MAX_FISH);
    // Создаем уникальный указатель на массив объектов типа Rock, выделяем память на максимальное количество скал MAX_ROCK
    this->rocks.resize(MAX_ROCK);
    // Запускаем основной цикл выполнения программы в методе Run()
    this->Run(); 
}

// Метод запуска цикла обновления и отрисовки аквариума
void Aquarium::Run() {
    // Цикл выполняется до тех пор, пока окно не будет закрыто
    while (!WindowShouldClose()) {
        // Начало отрисовки кадра
        BeginDrawing();
            // Очистка фона окна, устанавливая его цвет на светло-голубой
            ClearBackground(SKYBLUE);
            // Цикл для инициализации всех скал в аквариуме
            for (auto &r : rocks) 
            {
                r.Init();
            }
            for (auto &fish : fishes) 
            {
                // Инициализация объектов рыбы
                fish.Init();
                // Выполнение движения рыбы и взаимодействия с объектами скалы
                fish.Run();
            }
            // Отрисовка текущего FPS на экране
            DrawFPS(10, 10);
        // Завершение рисования на экране
        EndDrawing();
    }
}

vector<Rock>& Aquarium::get_rocks()
{
    return this->rocks;
}