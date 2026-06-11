#include "constantes.h"


typedef struct {
    int linha;
    int coluna;
    int direcao;
    int ativo;
} INIMIGO_S;

int inicializarInimigos(INIMIGO_S inimigos[], char mapa[LINHAS][COLUNAS]);
void atualizarInimigos(INIMIGO_S inimigos[], int qtd, char mapa[LINHAS][COLUNAS]);
void desenharInimigos(INIMIGO_S inimigos[], int qtd);