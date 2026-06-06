#include <raylib.h>
#include "mapa.h"

int main() {


    char mapa[LINHAS][COLUNAS];

    InitWindow(LARGURA_TELA, ALTURA_TELA, TITULO_JANELA);
    SetTargetFPS(FPS);

    carregarMapa(mapa, 1);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GRAY);

        desenharMapa(mapa);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}