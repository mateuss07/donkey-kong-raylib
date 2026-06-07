#include "raylib.h"
#include "constantes.h"

#define MAX_INIMIGOS 10
#define ESQUERDA -1
#define DIREITA   1

typedef struct {
    int linha;
    int coluna;
    int direcao;
    int ativo;
} INIMIGO;

int inicializarInimigos(INIMIGO inimigos[], char mapa[LINHAS][COLUNAS]);
void atualizarInimigos(INIMIGO inimigos[], int qtd, char mapa[LINHAS][COLUNAS]);
void desenharInimigos(INIMIGO inimigos[], int qtd);