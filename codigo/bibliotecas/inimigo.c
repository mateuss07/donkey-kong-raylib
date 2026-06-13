#include "inimigo.h"
#include <raylib.h>
#include "constantes.h"

int inicializarInimigos(INIMIGO_S inimigos[], char mapa[LINHAS][COLUNAS])
{
    int qtd=0;
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            if (mapa[i][j] == INIMIGO)
            {
                inimigos[qtd].linha = i;
                inimigos[qtd].coluna = j;
                inimigos[qtd].direcao = DIREITA;
                inimigos[qtd].ativo = 1;
                qtd++;
            }
        }
    }
    return qtd;
}
void atualizarInimigos(INIMIGO_S inimigos[], int qtd, char mapa[LINHAS][COLUNAS])
{
    int movimentoinimigo, dentrolimite, semburacoaolado;
    for (int i = 0; ((i < qtd) && (i < MAX_INIMIGOS)); i++)
    {
        movimentoinimigo = inimigos[i].coluna + inimigos[i].direcao;

        dentrolimite = (movimentoinimigo >= 0 && movimentoinimigo < COLUNAS);
        semburacoaolado = (((mapa[inimigos[i].linha + 1][movimentoinimigo] == PLATAFORMA) || 
        (mapa[inimigos[i].linha + 1][movimentoinimigo] == ESCADA_VAZIA))  && dentrolimite);
        if (!semburacoaolado)
        inimigos[i].direcao *= -1; //Inverte a direcao do inimigo se ele chega na borda da plataforma
        else
        inimigos[i].coluna = movimentoinimigo;
    }
}

void desenharInimigos(INIMIGO_S inimigos[], int qtd, Texture2D texturaInimigo){
    int x, y;
    for (int i=0;i<qtd;i++)
    {
        x = inimigos[i].coluna * TAMANHO;
        y = inimigos[i].linha * TAMANHO;
        DrawTexture(texturaInimigo, x, y, WHITE);
    }
}