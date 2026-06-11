#include <raylib.h>
#include "mapa.h"
#include "menu.h"
#include "jogador.h"
#include "inimigo.h"
#include "constantes.h"
int verificarMorte(JOGADOR_S jogador, INIMIGO_S inimigos[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        if (jogador.coluna == inimigos[i].coluna && jogador.linha == inimigos[i].linha) {
            return 1; // Jogador morreu
        }
    }
    return 0; // Jogador esta vivo
}

int verificaPorta(JOGADOR_S jogador, char mapa[LINHAS][COLUNAS]) {
    if (mapa[jogador.linha][jogador.coluna] == PORTA) {
        return 1; // Jogador entrou na porta
    }
    return 0; // Jogador não entrou na porta
}


int main()
{
    int nivel = 1;
    INIMIGO_S inimigos[MAX_INIMIGOS];
    JOGADOR_S jogador;
    int opcao = MENU, qtd;
    char mapa[LINHAS][COLUNAS];

    InitWindow(LARGURA_TELA, ALTURA_TELA, TITULO_JANELA);
    SetExitKey(KEY_L); //retira a saída padrão do raylib no esc e coloca no L
    SetTargetFPS(FPS);

    carregarMapa(mapa, nivel);
    jogador = inicializarJogador(mapa);
    qtd = inicializarInimigos(inimigos, mapa);


while (!WindowShouldClose())
    {
        //RENDERIZAÇÃO:

        if (opcao == MENU) {
            if (IsKeyPressed(KEY_ENTER)) 
                opcao = ENTRAR_JOGO;
            if (IsKeyPressed(KEY_E))     
                opcao = ENTRA_RANKING;
            if (IsKeyPressed(KEY_L))
                opcao = SAIR;
        }
        else if (opcao == ENTRAR_JOGO)
        {
            if(IsKeyPressed(KEY_TAB))
                opcao = PAUSA;
           else {
            atualizarJogador(&jogador, mapa);
            atualizarInimigos(inimigos, qtd, mapa);

            if (verificarMorte(jogador, inimigos, qtd)) {
                // Logica para lidar com a morte do jogador
                // Por exemplo, você pode reiniciar o jogo ou mostrar uma tela de game over
                opcao = GAME_OVER;// Exibe game over na tela
            }
            if (verificaPorta(jogador, mapa)) {
                // Logica para lidar com a entrada na porta
                // Por exemplo, você pode carregar um novo mapa ou avançar para o próximo nível
                if (nivel < MAX_NIVEIS) {
                nivel++;// Avança para o próximo nível
                carregarMapa(mapa, nivel); // Carrega um novo mapa
                jogador = inicializarJogador(mapa); // Reinicializa o jogador no novo mapa
                qtd = inicializarInimigos(inimigos, mapa); // Reinicializa os inimigos no novo mapa
                }
                else
                {
                    opcao = VITORIA; // Exibe tela de vitória ou reinicia o jogo
                }
           }
        }
    }

        else if (opcao == PAUSA) {
            if (IsKeyPressed(KEY_M))
                opcao = ENTRAR_JOGO;
            if (IsKeyPressed(KEY_L))
                opcao = SAIR;
            if (IsKeyPressed(KEY_ESCAPE))
                opcao = MENU;
        }

        else if (opcao == ENTRA_RANKING) {
            if (IsKeyPressed(KEY_ESCAPE))
                opcao = MENU;
        }
        else if(opcao == GAME_OVER){
            if (IsKeyPressed(KEY_ESCAPE))
                opcao = MENU;
            if (IsKeyPressed(KEY_L))
                opcao = SAIR;
            if (IsKeyPressed(KEY_M))
                opcao = ENTRAR_JOGO;
        }

        else if(opcao == VITORIA){
            if (IsKeyPressed(KEY_ESCAPE))
                opcao = MENU;
            if (IsKeyPressed(KEY_L))
                opcao = SAIR;
            if (IsKeyPressed(KEY_M))
                opcao = ENTRAR_JOGO;
        }

        else if (opcao == SAIR) {
            CloseWindow();
            return 0;
        }



        //DESENHO:

        BeginDrawing();
        ClearBackground(GRAY);

    if (opcao == MENU)
        desenharMenu();
    else if(opcao == ENTRAR_JOGO){
        desenharMapa(mapa);
        desenharJogador(jogador);
        desenharInimigos(inimigos, qtd);
    }
    else if(opcao == PAUSA){
        desenharMapa(mapa);
        desenharJogador(jogador);
        desenharInimigos(inimigos, qtd);
        desenharPausa();
    }

    else if(opcao == GAME_OVER){
        desenharGameOver();
    }
    else if(opcao == VITORIA){
        desenharVitoria();
    }

    else if(opcao == ENTRA_RANKING){
        DrawText("Ainda sem ranking", LARGURA_TELA/2 - MeasureText("Ainda sem ranking", 40)/2, ALTURA_TELA/2 - 20, 40, BLACK);
    }
    EndDrawing();
}

CloseWindow();
return 0;
}