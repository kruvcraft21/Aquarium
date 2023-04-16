#include "aquarium.h"

Aquarium::Aquarium() {
    this->heigth = AQUARIUM_HEIGTH;
    this->width = AQUARIUM_WIDTH;
}

void Aquarium::Init() {
    InitWindow(this->width, this->heigth, "Aquarium");
    SetTargetFPS(30);
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

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (this->food != NULL) {
                    delete this->food;
                    this->food = NULL;
                }
                this->food = new Food(GetMousePosition());
            }
            else if (this->food != NULL) {
                if (!this->food->is_eaten(this->fish)) {
                    this->food->Draw();
                }
                else {
                    delete this->food;
                    this->food = NULL;
                }
            }

            DrawFPS(10, 10);
        EndDrawing();
        angle++;
    }
}