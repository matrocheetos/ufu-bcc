#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

struct lista{
    char info;
    struct lista *prox;
};

Lista* criar_lista(){
    Lista* ls = (Lista*) malloc(sizeof(Lista));
    if(ls != NULL)
        *ls = NULL;
    return ls;
}

int lista_vazia(Lista* ls){
    if(ls == NULL)
        return 1; //vazia
    else
        return 0; //não vazia
}

int lista_cheia(){
    return 0; //memoria nao acabou

}

int insere_elem(Lista* ls, char elemento){
    if(ls==NULL)
        return 0;
    Elemento* N =(Elemento*) malloc(sizeof(Elemento));
    if(N == NULL){
        return 2;
    }
    N->info = elemento;
    N->prox = (*ls);
    *ls = N;
    return 1;
}

int remove_elem(Lista *ls, char elemento){
    if(lista_vazia(ls) == 1)
        return 0;
    Elemento* aux = *ls;
    if(elemento == (*ls)->info){
        *ls = aux->prox;
        free(aux);
        return 1;
    }
    while(aux->prox != NULL && aux->prox->info != elemento)
        aux=aux->prox;
    if(aux->prox == NULL)
        return 0;
    
    Elemento* aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

char obtem_posicao(Lista *ls, int verif){
    if(ls == NULL)
        return 0;
    
    Elemento* no = *ls;
    int i=1;
    while(no != NULL && i<verif){
        no=no->prox;
        i++;
    }

    if(no == NULL)
        return 0;
    else{
        return no->info;
    }
}

void limpa_lista(Lista *ls){
    if(ls != NULL){
        Elemento* no;
        while((*ls) != NULL){
            no = *ls;
            *ls = (*ls)->prox;
            free(no);
        }
        free(ls);
    }
}