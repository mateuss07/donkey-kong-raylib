#include <stdio.h>
#include <raylib.h>
#include "constantes.h"
#include <string.h>
#include "mapa.h"


void carregarMapa(char mapa[LINHAS][COLUNAS], int fase)
{
    char nomeArquivo[30];
    FILE *mapa_f;

    if (fase == 1)
        strcpy(nomeArquivo, "mapas/mapa1.txt");
    else if (fase == 2)
        strcpy(nomeArquivo, "mapas/mapa2.txt");
    else if (fase == 3)
        strcpy(nomeArquivo, "mapas/mapa3.txt");

    mapa_f = fopen(nomeArquivo, "r");

    if (!mapa_f)
        printf("Erro ao abrir o arquivo do mapa\n");
    else
    {
        for (int i = 0; i < LINHAS; i++)
        {
            fread(mapa[i], sizeof(char), COLUNAS, mapa_f);
            fgetc(mapa_f); // descarta o '\n'
        }

        fclose(mapa_f);
    }
}

void desenharMapa(char mapa[LINHAS][COLUNAS], Texture2D texturaEscada)
{
    int x, y;

    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            x = j * TAMANHO; // coluna j * tamanho(20) -> posição do pixel x
            y = i * TAMANHO; // coluna i * tamanho(20) -> posição do pixel y

            if (mapa[i][j] == PLATAFORMA)
                DrawRectangle(x, y, TAMANHO, TAMANHO, BLACK);
            else if (mapa[i][j] == ESCADA_VAZIA || mapa[i][j] == ESCADA_SUBIR)
                DrawTexture(texturaEscada, x, y, WHITE);
            else if (mapa[i][j] == PORTA)
                DrawRectangle(x, y, TAMANHO, TAMANHO, GREEN);
        }
    }
}
