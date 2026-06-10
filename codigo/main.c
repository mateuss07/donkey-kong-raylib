#include <raylib.h>
#include "mapa.h"
#include "menu.h"
#include "jogador.h"

int main() {

    JOGADOR_S jogador;
    int opcao = MENU;
    char mapa[LINHAS][COLUNAS];

    InitWindow(LARGURA_TELA, ALTURA_TELA, TITULO_JANELA);
    SetTargetFPS(FPS);

    carregarMapa(mapa, 1);
    jogador = inicializarJogador(mapa);

    while (!WindowShouldClose()) {

        if (opcao == ENTRAR_JOGO)
            atualizarJogador(&jogador, mapa);
        BeginDrawing();
        ClearBackground(GRAY);

        if(opcao == MENU){
        desenharMenu();

        if (IsKeyPressed(KEY_ENTER)) 
            opcao = ENTRAR_JOGO;
        if (IsKeyPressed(KEY_E))     
            opcao = ENTRA_RANKING;
        if (IsKeyPressed(KEY_ESCAPE)) 
            opcao = SAIR;
        }

        if (opcao == ENTRAR_JOGO) {
        desenharMapa(mapa);
        desenharJogador(jogador);
        }
        else if (opcao == ENTRA_RANKING){
            DrawText("Ainda sem ranking", LARGURA_TELA/2 - MeasureText("Ainda sem ranking", 40)/2, ALTURA_TELA/2 - 20, 40, BLACK);
        }
        else if (opcao == SAIR){
           CloseWindow();
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}