#include "aquarium.h"

Aquarium::Aquarium() {
    this->heigth = AQUARIUM_HEIGTH;
    this->width = AQUARIUM_WIDTH;
}

void Aquarium::Init() {
    InitWindow(this->width, this->heigth, "Aquarium");
    SetTargetFPS(60);
    this->fish = new Fish[MAX_FISH];
    this->rock = new Rock[MAX_ROCK];
    this->Run();
}

void Aquarium::Run() {
    int angle = 0;
    while (!WindowShouldClose()) {

        BeginDrawing();
            ClearBackground(SKYBLUE);
            for (int i = 0; i < MAX_ROCK; i ++) {
                rock[i].Init();
            }
            for (int i = 0; i < MAX_FISH; i++) {
                this->fish[i].Init();
                this->fish[i].Run(this->rock);
            }
            DrawFPS(10, 10);
        EndDrawing();
        angle++;
    }
}