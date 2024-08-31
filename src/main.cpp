#include"raylib.h"
#include"globals.h"
#include"draw.h"
#include"movement.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Chess Game");
    InitBoard();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawChessboard(0, 0, 100);
        DrawBoard();
        DrawSelectedPiece();
        HandleInput();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
