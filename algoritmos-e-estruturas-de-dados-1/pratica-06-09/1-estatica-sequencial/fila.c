#include <stdlib.h>
#include <string.h>
#include "ex1.h"
#define MAX 20

struct dados{
    char info[11];
};

struct fila{
    struct dados dados[MAX];
    int inicio,final,qtd;
};

Fila* criar_fila(){
    Fila *fila = (Fila*) malloc(sizeof(struct fila));
    if(fila != NULL){
        fila->inicio = 0;
        fila->final = 0;
        fila->qtd = 0;
    }
    return fila;
}

int fila_vazia(Fila* fila){
    if(fila == NULL) return -1;
    if(fila->qtd == 0) return 1;
    else return 0;
}

int fila_cheia(Fila* fila){
    if(fila == NULL) return -1; // nao tem fila
    if(fila->qtd == MAX) return 1;
    else return 0;
}

int insere_fim(Fila* fila, char insere[40]){
    if(fila == NULL) return 0;
    if(fila_cheia(fila) == 1) return 0;
    if(strlen(insere) > 10) return 0;

    strcpy(fila->dados[fila->final].info,insere);
    fila->final = (fila->final+1)%MAX;
    fila->qtd++;
    return 1;
}

int remove_ini(Fila* fila){
    if(fila == NULL || fila_vazia(fila)) return 0;

    fila->inicio = (fila->inicio+1)%MAX;
    fila->qtd--;
    return 1;
}