#include "jogador.h"
#include <raylib.h>
#include "constantes.h"

JOGADOR inicializarJogador(char mapa[LINHAS][COLUNAS])
{
    JOGADOR j;
    j.ativo = 1;

    for (int i = 0; i < LINHAS; i++)
    {
        for (int k = 0; k < COLUNAS; k++)
        {
            if (mapa[i][k] == JOGADOR_CHAR)
            {
                j.linha = i;
                j.coluna = k;
            }
        }
    }
    return j;
}
void desenharJogador(JOGADOR j)
{
    int x, y;
    x = j.coluna * TAMANHO;
    y = j.linha * TAMANHO;
    DrawRectangle(x, y, TAMANHO, TAMANHO, BLUE);
}

void atualizarJogador(JOGADOR *j, char mapa[LINHAS][COLUNAS])
{
    int novalinha, novacoluna, chaoabaixo, escadasubir, escadadescer;
    char celulaatual;

    novalinha = j->linha;
    novacoluna = j->coluna;
    celulaatual = mapa[j->linha][j->coluna];
    chaoabaixo = (((j->linha + 1) < LINHAS) && (mapa[j->linha + 1][j->coluna] == PLATAFORMA));
    escadasubir = (celulaatual == ESCADA_SUBIR);
    escadadescer = (celulaatual == ESCADA_DESCER);
    if ((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) && chaoabaixo)
        novacoluna++;
    else if ((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) && chaoabaixo)
        novacoluna--;

    if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && escadasubir)
    {
        for (int i = j->linha - 1; i >= 0; i--)
        {
            if (mapa[i][j->coluna] == ESCADA_DESCER)
            {
                novalinha = i;
                break;
            }
        }
    }

    if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && escadadescer)
    {
        for (int i = j->linha + 1; i < LINHAS; i++)
        {
            if (mapa[i][j->coluna] == ESCADA_SUBIR)
            {
                novalinha = i;
                break;
            }
        }
    }

    if ((novalinha >= 0 && novalinha < LINHAS) && (novacoluna >= 0 && novacoluna < COLUNAS) && (mapa[novalinha][novacoluna] != PLATAFORMA))
    {
        j->linha = novalinha;
        j->coluna = novacoluna;
    }
}