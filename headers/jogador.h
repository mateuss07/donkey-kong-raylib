#include "raylib.h"
#include "constantes.h"

typedef struct {
    int linha;
    int coluna;
    int ativo;
} JOGADOR;

JOGADOR inicializarJogador(char mapa[LINHAS][COLUNAS]);
void atualizarJogador(JOGADOR *jogador, char mapa[LINHAS][COLUNAS]);
void desenharJogador(JOGADOR jogador);