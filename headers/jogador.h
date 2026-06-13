#include <raylib.h>
#include "constantes.h"

typedef struct
{
    int linha;
    int coluna;
    int ativo;
    int vidas;
} JOGADOR_S;

JOGADOR_S inicializarJogador(char mapa[LINHAS][COLUNAS]);
void atualizarJogador(JOGADOR_S *jogador, char mapa[LINHAS][COLUNAS]);
void desenharJogador(JOGADOR_S jogador, Texture2D texturaJogador);
void perdevida(JOGADOR_S *jogador,char mapa[LINHAS][COLUNAS]);