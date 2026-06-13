#include "placar.h"
#include <raylib.h>
#include "constantes.h"
#include <string.h>
#include <stdio.h>

int carregar_placar(TIPO_PLACAR placar[]){
    FILE *arq;
    int qtd=0;
    
    arq = fopen("placar.bin", "rb");

    if(!arq)
        return 0;
    else{
        while(qtd < 10 && fread(&placar[qtd], sizeof(TIPO_PLACAR), 1, arq) == 1){
            qtd++;
        }
        fclose(arq);
        return qtd;
    }
}

void salvar_placar(TIPO_PLACAR placar[], int qtd){
    FILE *arq;
    arq = fopen("placar.bin", "wb");

    if(!arq)
        printf("Erro ao abrir o arquivo do placar\n");
    else{
        for(int i=0; i<qtd; i++){
            fwrite(&placar[i], sizeof(TIPO_PLACAR), 1, arq);
        }
        fclose(arq);
    }
}

int inserir_no_ranking(TIPO_PLACAR placar[], int *qtd, char nome[]){
    
}



void desenhar_ranking(TIPO_PLACAR placar[], int qtd){

    }                   
    
    


void desenhar_entrada_nome(char nome[]){
    

    
}