#include <raylib.h>
#include "mapa.h"
#include "menu.h"
#include "jogador.h"
#include "inimigo.h"
#include "constantes.h"

void desenharTempo(float tempo){
    DrawText(TextFormat("Tempo: %ds", (int)tempo), LARGURA_TELA - MeasureText(TextFormat("Tempo: %ds", (int)tempo), 22) - 2, 22, 22, BLACK);
    DrawText(TextFormat("Tempo: %ds", (int)tempo), LARGURA_TELA - MeasureText(TextFormat("Tempo: %ds", (int)tempo), 22) - 3, 21, 22, WHITE);
}
void desenharFase(int nivel) {
    DrawText(TextFormat("Fase: %d", nivel), LARGURA_TELA - MeasureText(TextFormat("Fase: %d", nivel), 22) - 2, 2, 22, BLACK);
    DrawText(TextFormat("Fase: %d", nivel), LARGURA_TELA - MeasureText(TextFormat("Fase: %d", nivel), 22) - 3, 1, 22, WHITE);
}


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
    float tempo_jogo = 0.0f;


    InitWindow(LARGURA_TELA, ALTURA_TELA, TITULO_JANELA);
    SetExitKey(KEY_L); //retira a saída padrão do raylib no esc e coloca no L
    SetTargetFPS(FPS);

    Texture2D texturaEscada = LoadTexture("sprites/escada2.png");
    Texture2D texturaJogador = LoadTexture("sprites/personagem.png");
    Texture2D texturaInimigo = LoadTexture("sprites/inimigo.png");

    carregarMapa(mapa, nivel);
    jogador = inicializarJogador(mapa);
    qtd = inicializarInimigos(inimigos, mapa);


while (!WindowShouldClose())
    {
        //RENDERIZAÇÃO:

        if (opcao == MENU) {
            if (IsKeyPressed(KEY_ENTER)){
                tempo_jogo = 0.0f;
                nivel = 1;
                carregarMapa(mapa, 1); // Carrega o mapa do primeiro nível
                jogador = inicializarJogador(mapa); // Reinicializa o jogador no mapa
                qtd = inicializarInimigos(inimigos, mapa); // Reinicializa os inimigos no mapa
                opcao = ENTRAR_JOGO;
            }
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
            tempo_jogo += GetFrameTime();

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
            if (IsKeyPressed(KEY_M)){
                tempo_jogo = 0.0f;
                nivel = 1;
                carregarMapa(mapa, 1); // Carrega o mapa do primeiro nível
                jogador = inicializarJogador(mapa); // Reinicializa o jogador no mapa
                qtd = inicializarInimigos(inimigos, mapa); // Reinicializa os inimigos no mapa
                opcao = ENTRAR_JOGO;
            }
        }

        else if(opcao == VITORIA){
            if (IsKeyPressed(KEY_ESCAPE))
                opcao = MENU;
            if (IsKeyPressed(KEY_L))
                opcao = SAIR;
            if (IsKeyPressed(KEY_M)){
                tempo_jogo = 0.0f;
                nivel = 1;
                carregarMapa(mapa, 1); // Carrega o mapa do primeiro nível
                jogador = inicializarJogador(mapa); // Reinicializa o jogador no mapa
                qtd = inicializarInimigos(inimigos, mapa); // Reinicializa os inimigos no mapa
                opcao = ENTRAR_JOGO;
            }
        }

        else if (opcao == SAIR) {
            UnloadTexture(texturaEscada);
            UnloadTexture(texturaJogador);
            UnloadTexture(texturaInimigo);
            CloseWindow();
            return 0;
        }



        //DESENHO:

        BeginDrawing();
        ClearBackground(GRAY);

    if (opcao == MENU)
        desenharMenu();
    else if(opcao == ENTRAR_JOGO){
        desenharMapa(mapa, texturaEscada);
        desenharJogador(jogador);
        desenharInimigos(inimigos, qtd);
        desenharTempo(tempo_jogo);
        desenharFase(nivel);
        

    }
    else if(opcao == PAUSA){
        desenharMapa(mapa, texturaEscada);
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

UnloadTexture(texturaEscada);
UnloadTexture(texturaJogador);
UnloadTexture(texturaInimigo);
CloseWindow();
return 0;
}