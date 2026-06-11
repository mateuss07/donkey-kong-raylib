#include "menu.h"
#include <stdio.h>
#include <raylib.h>
#include "constantes.h"
#include <string.h>

void desenharMenu(){

        DrawText("Donkey Kong - Raylib", LARGURA_TELA/2 - MeasureText("Donkey Kong - Raylib", 40)/2, ALTURA_TELA/2 - 50, 40, BLACK);
        DrawText("ENTER : Novo Jogo", LARGURA_TELA/2 - MeasureText("ENTER : Novo Jogo", 24)/2, ALTURA_TELA/2 + 10, 24, BLUE);
        DrawText("E : Ranking", LARGURA_TELA/2 - MeasureText("E : Ranking", 24)/2, ALTURA_TELA/2 + 40, 24, BLUE);
        DrawText("L : Sair", LARGURA_TELA/2 - MeasureText("L : Sair", 24)/2, ALTURA_TELA/2 + 70, 24, BLUE);
}

void desenharPausa(){
        DrawRectangle(0, 0, LARGURA_TELA, ALTURA_TELA, Fade(BLACK, 0.7f));
        DrawText("PAUSA", LARGURA_TELA/2 - MeasureText("PAUSA", 40)/2, ALTURA_TELA/2 - 60, 40, RAYWHITE);
        DrawText("L - Sair do Jogo", LARGURA_TELA/2 - MeasureText("L - Sair do Jogo", 24)/2, ALTURA_TELA/2 + 0, 24, BLUE);
        DrawText("E - Ranking", LARGURA_TELA/2 - MeasureText("E - Ranking", 24)/2, ALTURA_TELA/2 + 30, 24, BLUE);
        DrawText("ESC - Retornar ao Menu", LARGURA_TELA/2 - MeasureText("ESC - Retornar ao Menu", 24)/2, ALTURA_TELA/2 + 60, 24, BLUE);
        DrawText("M - Continuar", LARGURA_TELA/2 - MeasureText("M - Continuar", 24)/2, ALTURA_TELA/2 + 90, 24, BLUE);
}
void desenharGameOver(){
        DrawRectangle(0, 0, LARGURA_TELA, ALTURA_TELA, Fade(BLACK, 0.7f));
        DrawText("GAME OVER", LARGURA_TELA/2 - MeasureText("GAME OVER", 40)/2, ALTURA_TELA/2 - 40, 40, RED);
        DrawText("L - Sair do Jogo", LARGURA_TELA/2 - MeasureText("L - Sair do Jogo", 24)/2, ALTURA_TELA/2 + 20, 24, BLUE);
        DrawText("M - Novo Jogo", LARGURA_TELA/2 - MeasureText("M - Novo Jogo", 24)/2, ALTURA_TELA/2 + 50, 24, BLUE);
        DrawText("ESC - Retornar ao Menu", LARGURA_TELA/2 - MeasureText("ESC - Retornar ao Menu", 24)/2, ALTURA_TELA/2 + 80, 24, BLUE);
}
void desenharVitoria(){
        DrawRectangle(0, 0, LARGURA_TELA, ALTURA_TELA, Fade(BLACK, 0.7f));
        DrawText("VOCÊ VENCEU!", LARGURA_TELA/2 - MeasureText("VOCÊ VENCEU!", 40)/2, ALTURA_TELA/2 - 40, 40, BLACK);
        DrawText("L - Sair do Jogo", LARGURA_TELA/2 - MeasureText("L - Sair do Jogo", 24)/2, ALTURA_TELA/2 + 20, 24, BLUE);
        DrawText("E - Ranking", LARGURA_TELA/2 - MeasureText("E - Ranking", 24)/2, ALTURA_TELA/2 + 50, 24, BLUE);
        DrawText("ESC - Retornar ao Menu", LARGURA_TELA/2 - MeasureText("ESC - Retornar ao Menu", 24)/2, ALTURA_TELA/2 + 80, 24, BLUE);
}