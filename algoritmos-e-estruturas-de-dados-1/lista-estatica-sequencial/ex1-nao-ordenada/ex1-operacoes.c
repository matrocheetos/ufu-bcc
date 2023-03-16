#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

struct lista{
    float nro[20];
    int fim;
};

Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));
    if(l != NULL){
        l->fim = 0;
        limpa_lista(l);
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

void insere_elem(Lista* l, float nro){
    l->nro[l->fim] = nro;
    l->fim++;
}

int remove_elem(Lista* l, float nro){
    int i;
    for(i=0;i<l->fim;i++){
        if(l->nro[i]==nro){
            l->nro[i]=0;
            return 0;
        }
    }
    return 1;
}

void limpa_lista(Lista* l){
    int i;
    for(i=0;i<20;i++)
        l->nro[i] = 0;
    l->fim = 0;
}

float get_posicao(Lista* l, int posicao){
    return l->nro[posicao];
}