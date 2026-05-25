#include <raylib.h>
#include <mapa.h>

int main() {

    InitWindow(800, 450, "Teste");

    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello Raylib!", 400, 200, 40, BLUE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}