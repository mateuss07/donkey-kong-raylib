#include <raylib.h>
#include <placar.h>
#include <mapa.h>
#include <jogador.h>
#include <inimigo.h>


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