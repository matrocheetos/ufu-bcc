#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

struct elemento{
    struct bebida bebida;
    struct elemento *prox;
};
typedef struct elemento Elemento;

struct fila{
    struct elemento *inicio;
    struct elemento *final;
};

Fila* criar_fila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if(fila != NULL){
        fila->final = NULL;
        fila->inicio = NULL;
    }
    return fila;
}

int fila_vazia(Fila* fila){
    if(fila == NULL) return 1;
    if(fila->inicio == NULL) return 1;
    return 0;
}

int fila_cheia(Fila* fila){
    return 0;
}

int insere_fim(Fila* fila, struct bebida elemento){
    if(fila == NULL) return 0;

    Elemento *insere = (Elemento*) malloc(sizeof(Elemento));
    if(insere == NULL) return 0;

    insere->bebida = elemento;
    insere->prox = NULL;

    if(fila->final == NULL)
        fila->inicio = insere;
    else
        fila->final->prox = insere;
    fila->final = insere;

    return 1;
}

int remove_ini(Fila *fila){
    if(fila == NULL) return 0;
    if(fila->inicio == NULL) return 0;

    Elemento *remove = fila->inicio;
    fila->inicio = fila->inicio->prox;
    if(fila->inicio == NULL)
        fila->final = NULL;
    free(remove);
    return 1;
}

void apaga_fila(Fila* fila){
    if(fila != NULL){
        Elemento *apaga;
        while(fila->inicio != NULL){
            apaga = fila->inicio;
            fila->inicio = fila->inicio->prox;
            free(apaga);
        }
        free(fila);
    }
}

void esvazia_fila(Fila* fila){
    fila = criar_fila();
}

void imprime_fila(Fila* fila){
    if(fila_vazia(fila) == 1)
        printf("fila vazia!\n");
    else{
        printf("fila:\n");
        Fila *imprime = fila;
        while(imprime != NULL){
            printf("%s, %d - R$ %.2f\n",imprime->inicio->bebida.nome,imprime->inicio->bebida.volume,imprime->inicio->bebida.preco);
            imprime->inicio = imprime->inicio->prox;
        }
        free(imprime);
    }
}