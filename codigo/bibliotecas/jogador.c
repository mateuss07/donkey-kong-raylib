#include "jogador.h"
#include <raylib.h>
#include "constantes.h"

JOGADOR inicializarJogador(char mapa[LINHAS][COLUNAS]) {
    JOGADOR j;
    j.ativo = 1;

    for (int i = 0; i < LINHAS; i++) {
        for (int k = 0; k < COLUNAS; k++) {
            if (mapa[i][k] == JOGADOR_CHAR) {
                j.linha  = i;
                j.coluna = k;
            }
        }
    }
    return j;
}