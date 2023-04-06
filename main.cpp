#include <iostream>
#include "raylib.h"
#include <math.h>
#include "src/fish.h"

int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Accvarium");
    SetTargetFPS(60);

    Fish fish;
    
    int angle = 0;

    while (!WindowShouldClose()) {

        BeginDrawing();
            ClearBackground(SKYBLUE);
            fish.set_rot(angle++);
            fish.Draw();
            DrawFPS(10, 10);
        EndDrawing();
        angle++;
    }

    return 0;
}