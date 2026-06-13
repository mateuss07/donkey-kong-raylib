#include <raylib.h>
#include "constantes.h"

typedef struct
{
    int linha;
    int coluna;
    int ativo;
} JOGADOR_S;

JOGADOR_S inicializarJogador(char mapa[LINHAS][COLUNAS]);
void atualizarJogador(JOGADOR_S *jogador, char mapa[LINHAS][COLUNAS]);
void desenharJogador(JOGADOR_S jogador, Texture2D texturaJogador);