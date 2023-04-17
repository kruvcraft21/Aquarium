﻿#include "aquarium.h"

Aquarium::Aquarium() {
    this->heigth = AQUARIUM_HEIGTH;
    this->width = AQUARIUM_WIDTH;
}

void Aquarium::Init() {
    InitWindow(this->width, this->heigth, "Aquarium");
    SetTargetFPS(30);
    this->fish = std::make_unique<Fish[]>(MAX_FISH);
    this->rock = std::make_unique<Rock[]>(MAX_ROCK);
    this->Run();
}

void Aquarium::Run() {
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(SKYBLUE);
            for (int i = 0; i < MAX_ROCK; i ++) {
                rock[i].Init();
            }
            for (int i = 0; i < MAX_FISH; i++) {
                this->fish[i].Init();
                this->fish[i].Run(this->rock.get());
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                food = std::make_unique<Food>(GetMousePosition());
            }
            else if (food != nullptr)
            {
                if (!food->is_eaten(fish.get()))
                {
                    food->Draw();
                }
                else
                {
                    food = nullptr;
                }
            }

            DrawFPS(10, 10);
        EndDrawing();
    }
}