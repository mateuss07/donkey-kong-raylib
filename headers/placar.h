#include <stdio.h>
#include <raylib.h>
#include "constantes.h"

typedef struct {
    char nome[20];
    int time;
}TIPO_PLACAR;

int carregar_placar(TIPO_PLACAR placar[]);
void salvar_placar(TIPO_PLACAR placar[], int qtd);
void desenhar_ranking(TIPO_PLACAR placar[], int qtd);
int desenhar_entrada_nome(char nome[]);
void inserir_no_placar(TIPO_PLACAR placar[], int *qtd, char nome[], int tempo);

