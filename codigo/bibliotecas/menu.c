#include "menu.h"
#include <stdio.h>
#include <raylib.h>
#include "constantes.h"
#include <string.h>

void desenharMenu(){

        DrawText("Donkey Kong - Raylib", LARGURA_TELA/2 - MeasureText("Donkey Kong - Raylib", 40)/2, ALTURA_TELA/2 - 50, 40, BLACK);
        DrawText("ENTER : Novo Jogo", LARGURA_TELA/2 - MeasureText("ENTER : Novo Jogo", 24)/2, ALTURA_TELA/2 + 10, 24, BLUE);
        DrawText("E : Ranking", LARGURA_TELA/2 - MeasureText("E : Ranking", 24)/2, ALTURA_TELA/2 + 30, 24, BLUE);
        DrawText("F4 : Sair", LARGURA_TELA/2 - MeasureText("F4 : Sair", 24)/2, ALTURA_TELA/2 + 50, 24, BLUE);
}