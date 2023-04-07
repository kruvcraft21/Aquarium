﻿#include "aquarium.h"

Aquarium::Aquarium() {
    this->heigth = AQUARIUM_HEIGTH;
    this->width = AQUARIUM_WIDTH;
}

void Aquarium::Init() {
    InitWindow(this->width, this->heigth, "Aquarium");
    SetTargetFPS(60);
    this->fish = new Fish[MAX_FISH];
    this->rock = new Rock[10];
    this->Run();
}

void Aquarium::Run() {
    int angle = 0;
    while (!WindowShouldClose()) {

        BeginDrawing();
            ClearBackground(SKYBLUE);
            for (int i = 0; i < 10; i ++) {
                rock[i].Init();
            }
            for (int i = 0; i < MAX_FISH; i++) {
                this->fish[i].Init();
                this->fish[i].Run();
            }
            DrawFPS(10, 10);
        EndDrawing();
        angle++;
    }
}