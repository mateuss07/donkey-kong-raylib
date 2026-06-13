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

int inserir_no_placar(TIPO_PLACAR placar[], int *qtd, char nome[], int tempo){
    
    int pos;
    int achou=0;
    pos = *qtd;

    if(*qtd == 10 && tempo >= placar[9].time) //Verifica se entra no ranking
        return 0;

    //Achar posição para colocar o novo tempo
    for (int i = 0; i<*qtd && achou==0; i++) {
        if (tempo < placar[i].time) {
            pos = i;
            achou=1;
        }
    }

    if (*qtd <10) //Se o placar ainda não estiver cheio, aumenta a quantidade de jogadores (so nos primeiros ate encher)
        (*qtd)++;

    for (int i = *qtd-1; i>pos; i--) //Desloca todos jogadores acima do novo uma posição para baixo
        placar[i] = placar[i - 1];

    strcpy(placar[pos].nome, nome); //Coloca o nome do novo jogador no ranking
    placar[pos].time = tempo; //Coloca o tempo do novo jogador no ranking

    return 1;
}


void desenhar_ranking(TIPO_PLACAR placar[], int qtd) {
    DrawText("RANKING", GetScreenWidth()/2 - MeasureText("RANKING", 40)/2, 50, 40, GOLD);
    for (int i = 0; i < qtd; i++) {
        char texto[50];
        sprintf(texto, "%d. %s - %d segundos\n", i + 1, placar[i].nome, placar[i].time);
        DrawText(texto, GetScreenWidth()/2 - MeasureText(texto, 30)/2, 100 + i * 40, 30, BLACK);
    }                   
}
    
    


void desenhar_entrada_nome(char nome[]){
    

    
}