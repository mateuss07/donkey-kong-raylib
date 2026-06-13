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



void desenhar_ranking(TIPO_PLACAR placar[], int qtd){

    }                   
    
    


void desenhar_entrada_nome(char nome[]){

    
}