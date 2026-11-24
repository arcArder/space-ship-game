#include "raylib.h"

int main() {
    const int kScreenWidth = 800;
    const int kScreenHeight = 600;

    // Окно фиксированного размера: его нельзя растянуть, поэтому вёрстка не сломается
    InitWindow(kScreenWidth, kScreenHeight, "Space Ship Game");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {  // закрывается по Esc и по кнопке закрытия окна
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Space Ship Game", 250, 280, 40, RAYWHITE);
        DrawText("Press Esc to exit", 300, 340, 20, GRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}