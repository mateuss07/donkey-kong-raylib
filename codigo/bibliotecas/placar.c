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
        while((qtd<10) && fread(&placar[qtd], sizeof(TIPO_PLACAR), 1, arq) == 1){
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
        printf("Erro ao abrir o placar\n");
    else{
        for(int i=0; i<qtd; i++){
            fwrite(&placar[i], sizeof(TIPO_PLACAR), 1, arq);
        }
        fclose(arq);
    }
}

void inserir_no_placar(TIPO_PLACAR placar[], int *qtd, char nome[], int tempo){
    
    int pos;
    int achou=0;
    pos = *qtd;

    //Acha posição para colocar o novo tempo
    for (int i = 0; i<*qtd && achou==0; i++) {
        if (tempo < placar[i].time) {
            pos = i;
            achou=1;
        }
    }

    if (*qtd <10) //Se o placar ainda não estiver cheio, aumenta a quantidade de jogadores (so nos primeiros ate encher)
        (*qtd)++;

    for (int i = *qtd-1; i>pos; i--) //Desloca todos jogadores acima do novo uma posição para acima
        placar[i] = placar[i - 1];

    strcpy(placar[pos].nome, nome); //Coloca o nome do novo jogador no ranking
    placar[pos].time = tempo; //Coloca o tempo do novo jogador no ranking
}


void desenhar_ranking(TIPO_PLACAR placar[], int qtd) {

    char texto[50];

    DrawText("RANKING", GetScreenWidth()/2 - MeasureText("RANKING", 40)/2, 50, 40, RAYWHITE);
    if(qtd == 0){
        DrawText("Nenhum recorde registrado ainda!", GetScreenWidth()/2 - MeasureText("Nenhum recorde registrado ainda!", 30)/2, 150, 30, BLACK);
    }
    else{
    for (int i=0; i < qtd; i++) {
        sprintf(texto, "%d- %s - %d segundos\n", i+1, placar[i].nome, placar[i].time);
        DrawText(texto, GetScreenWidth()/2 - MeasureText(texto, 30)/2, 100 + i * 40, 30, BLACK);
        }     
    }              
}
    
    


int desenhar_entrada_nome(char nome[]){
    int tamanho=0;
    int tecla = GetCharPressed();

    if (tecla > 0){
        if((tecla >= 32) && (tecla <=126) && (strlen(nome) < 19)){
            tamanho = strlen(nome);
            nome[tamanho] = tecla;
            nome[tamanho+1] = '\0';
        }
    }

    if(IsKeyPressed(KEY_BACKSPACE) && strlen(nome)>0){
        nome[strlen(nome)-1] = '\0';
    }

    DrawText("PARABENS!", LARGURA_TELA/2 - MeasureText("PARABENS!", 36)/2, ALTURA_TELA/2 - 100, 36, YELLOW);
    DrawText("Voce esta no top 10!", LARGURA_TELA/2 - MeasureText("Voce esta no top 10!", 22)/2, ALTURA_TELA/2 - 50, 22, RAYWHITE);
    DrawText("Digite seu nome:", LARGURA_TELA/2 - MeasureText("Digite seu nome:", 22)/2, ALTURA_TELA/2, 22, GRAY);
    DrawText(nome, LARGURA_TELA/2 - MeasureText(nome, 28)/2, ALTURA_TELA/2 + 35, 28, WHITE);
    DrawText("ENTER - Confirmar", LARGURA_TELA/2 - MeasureText("ENTER - Confirmar", 18)/2, ALTURA_TELA/2 + 90, 18, GRAY);
    
    
    if(IsKeyPressed(KEY_ENTER))
        return 1;
    else
        return 0;
}