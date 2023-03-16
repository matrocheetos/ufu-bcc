#include <stdlib.h>
#include <string.h>
#include "ex2.h"

struct bebida{
    char nome[21];
    int volume;
    float preco;
};

struct lista{
    struct bebida Bebida[20];  //20 bebidas max
    int fim;
};

Lista* inicializar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));
    if(l != NULL){
        l->fim = 0;
    }
    return l;
}

int lista_vazia(Lista* l){
    if(l->fim==0)
        return 1;
    else
        return 0;
}

int lista_cheia(Lista* l){
    if(l->fim==20)
        return 1;
    else
        return 0;
}

int insere_ord(Lista *l, char nome[40], int volume, float preco){
    if(strlen(nome)>20)  //verifica tamanho da string
        return 1;

    strcpy(l->Bebida[l->fim].nome, nome);
    l->Bebida[l->fim].volume = volume;
    l->Bebida[l->fim].preco = preco;
    l->fim++;

    int i,j,menor;
    for(i=0;i<l->fim-1;i++){
        menor = i;
        for(j=i+1;j<l->fim;j++){
            if(strcmp(l->Bebida[i].nome, l->Bebida[j].nome) > 0){
                menor = j;
            }else if(strcmp(l->Bebida[i].nome, l->Bebida[j].nome) == 0){
                if(l->Bebida[i].volume > l->Bebida[j].volume)
                    menor = j;
            }
        }
        if(i != menor){
            Bebida troca;
            troca = l->Bebida[i];
            l->Bebida[i] = l->Bebida[menor];
            l->Bebida[menor] = troca;
        }
    }
    return 0;
}

int remove_ord(Lista *l, char nome[40]){
    if(strlen(nome)>20)  //verifica tamanho da string
        return 1;

    int i,j;
    for(i=0;i<l->fim;i++){
        if(strcmp(nome,l->Bebida[i].nome)==0){
            for(j=i;j<l->fim;j++)
                l->Bebida[j] = l->Bebida[j+1];
            l->fim--;
            return 0;
        }
    }
    return 1;
}

void get_pos(Lista *l, int posicao, char infoNome[], int* infoVol, float* infoPreco){
    strcpy(infoNome, l->Bebida[posicao].nome);
    *infoVol = l->Bebida[posicao].volume;
    *infoPreco = l->Bebida[posicao].preco;
}

int get_tamanho(Lista *l){
    return l->fim;
}