#include "jogador.h"
#include <raylib.h>
#include "constantes.h"

JOGADOR_S inicializarJogador(char mapa[LINHAS][COLUNAS])
{
    JOGADOR_S j;
    j.ativo = 1;

    for (int i = 0; i < LINHAS; i++)
    {
        for (int k = 0; k < COLUNAS; k++)
        {
            if (mapa[i][k] == JOGADOR)
            {
                j.linha = i;
                j.coluna = k;
            }
        }
    }
    return j;
}
void desenharJogador(JOGADOR_S j)
{
    int x, y;
    x = j.coluna * TAMANHO;
    y = j.linha * TAMANHO;
    DrawRectangle(x, y, TAMANHO, TAMANHO, BLUE);
}

void atualizarJogador(JOGADOR_S *j, char mapa[LINHAS][COLUNAS])
{
    int novalinha, novacoluna, chaoabaixo, escadasubir, escadadescer, naescada;
    char celulaatual;

    novalinha = j->linha;
    novacoluna = j->coluna;
    celulaatual = mapa[j->linha][j->coluna];
    chaoabaixo = (((j->linha + 1) < LINHAS) && (mapa[j->linha + 1][j->coluna] == PLATAFORMA ||
    mapa[j->linha + 1][j->coluna] == ESCADA_SUBIR ||
    mapa[j->linha + 1][j->coluna] == ESCADA_DESCER));

    escadasubir = (celulaatual == ESCADA_SUBIR || 
              (chaoabaixo && mapa[j->linha + 1][j->coluna] == ESCADA_SUBIR));
    escadadescer = (celulaatual == ESCADA_DESCER);


    if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && chaoabaixo)
        novacoluna++;
    else if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) && chaoabaixo)
        novacoluna--;

    if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) && escadasubir)
{
    if (novalinha - 1 >= 0 && (mapa[novalinha - 1][j->coluna] == ESCADA_SUBIR  ||
        mapa[novalinha - 1][j->coluna] == ESCADA_DESCER ||
        mapa[novalinha - 1][j->coluna] == PLATAFORMA))
        novalinha--;

}
    if ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) && escadadescer)
{
    if (novalinha + 1 < LINHAS && (mapa[novalinha + 1][j->coluna] == ESCADA_DESCER || mapa[novalinha + 1][j->coluna] == PLATAFORMA || mapa[novalinha + 1][j->coluna] == ESCADA_SUBIR))
        novalinha++;
}
    if ((novalinha >= 0 && novalinha < LINHAS) && (novacoluna >= 0 && novacoluna < COLUNAS) && (mapa[novalinha][novacoluna] != PLATAFORMA))
    {
        j->linha = novalinha;
        j->coluna = novacoluna;
    }
}