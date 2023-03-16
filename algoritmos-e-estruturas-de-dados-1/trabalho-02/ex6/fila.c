#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct no {
    struct paciente info;
    struct no *prox;
};

Fila cria_fila(){
    return NULL;
}

int fila_vazia(Fila f){
    if(f == NULL)
        return 1;
    return 0;
}

int insere_ord(Fila *f, struct paciente elem){

    Fila N = (Fila) malloc(sizeof(struct no));

    if(N == NULL) return 0;

    strcpy(N->info.nome, elem.nome);
    strcpy(N->info.orgao, elem.orgao);
    N->info.idade = elem.idade;
    N->info.gravidade = elem.gravidade;


    //Fila vazia
    if(fila_vazia(*f) == 1){
        N->prox = N;
        *f = N;
        return 1;
    }

    //Insere no final
    if((*f)->info.gravidade >= elem.gravidade){
        N->prox = (*f)->prox;
        (*f)->prox = N;
        *f = N;
        return 1;
    }
    //aux aponta para o primeiro no
    Fila aux = (*f)->prox;

    if(aux->info.gravidade < elem.gravidade){
        N->prox = aux;
        (*f)->prox = N;
        return 1;
    }

    while(aux->prox->info.gravidade > elem.gravidade){
        aux = aux->prox;
    }
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

int remove_ini(Fila *f, struct paciente *elem){
    if(fila_vazia(*f) == 1)
        return 0;

    Fila aux = (*f)->prox;
    strcpy(elem->nome, aux->info.nome);
    strcpy(elem->orgao, aux->info.orgao);
    elem->idade = aux->info.idade;
    elem->gravidade = aux->info.gravidade;


    if(*f == (*f)->prox)
        *f = NULL;

    else
        (*f)->prox = aux->prox;

    free(aux);
    return 1;
}

int esvazia_fp(Fila *lst){
    if(fila_vazia(*lst) == 1)
        return 0;

    struct paciente removido;

    while(fila_vazia(*lst) != 1){
        remove_ini(&(*lst), &removido);
    }
    return 1;
}
