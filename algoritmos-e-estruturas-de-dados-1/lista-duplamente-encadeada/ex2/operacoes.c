#include <stdlib.h>
#include "ex2.h"

struct lista{
    int info;
    struct lista *prox, *ant;
};

Lista* criar_lista(){
    Lista* ls = (Lista*) malloc(sizeof(Lista));
    if(ls!=NULL)
        *ls=NULL;
    return ls;
}

int lista_vazia(Lista* ls){
    if(ls==NULL || *ls==NULL)
        return 1;
    else
        return 0;
}

//ordenado
int insere_elemento(Lista* ls, int info){
    if(ls==NULL)
        return 0;
    
    Elemento* insere = (Elemento*) malloc(sizeof(Elemento));
    if(insere == NULL)
        return 0;

    insere->info = info;
    if(lista_vazia(ls)==1){ //insere inicio
        insere->prox = NULL;
        insere->ant = NULL;
        *ls = insere;
        return 1;
    }else{ //procura onde inserir
        Elemento *anterior, *atual = *ls;
        while(atual!=NULL && atual->info<info){
            anterior=atual;
            atual=atual->prox;
        }
        if(atual==*ls){ //insere inicio
            insere->ant = NULL;
            (*ls)->ant = insere;
            insere->prox = (*ls);
            *ls = insere;
        }else{
            insere->prox = anterior->prox;
            insere->ant = anterior;
            anterior->prox = insere;
            if(atual!=NULL)
                atual->ant = insere;
        }
        return 1;
    }
}

int remove_elemento(Lista* ls, int info){
    if(ls==NULL)
        return 0;

    Elemento* remove = *ls;
    while(remove != NULL && remove->info != info)
        remove = remove->prox;
    if(remove==NULL)
        return 0;
    
    if(remove->ant==NULL)
        *ls = remove->prox;
    else
        remove->ant->prox = remove->prox;

    if(remove->prox!=NULL)
        remove->prox->ant = remove->ant;
    free(remove);
    return 1;
}

int obtem_valor_elem(Lista* ls, int posicao, int *info){
    if(ls==NULL)
        return 0;
    
    Elemento *obtem_valor = *ls;
    int i = 1;
    while(obtem_valor!=NULL && i<posicao){
        obtem_valor=obtem_valor->prox;
        i++;
    }
    if(obtem_valor==NULL)
        return 0;
    else{
        *info = obtem_valor->info;
        return 1;
    }
}