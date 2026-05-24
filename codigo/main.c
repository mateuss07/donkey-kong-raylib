#include <raylib.h>


int main() {

    InitWindow(800, 450, "Teste");

    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello Raylib!", 390, 200, 20, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}