#include "aquarium.h"

Aquarium::Aquarium() {
    this->heigth = 450;
    this->width = 800;
}

void Aquarium::Init() {
    InitWindow(this->width, this->heigth, "Accvarium");
    SetTargetFPS(60);
    this->fish = new Fish[MAX_FISH];
    this->Run();
}

void Aquarium::Run() {
    int angle = 0;

    while (!WindowShouldClose()) {

        BeginDrawing();
            ClearBackground(SKYBLUE);
            for (int i = 0; i < MAX_FISH; i++) {
                this->fish[i].Init();
                this->fish[i].set_rot(angle);
            }
            DrawFPS(10, 10);
        EndDrawing();
        angle++;
    }
}