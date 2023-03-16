#include <stdlib.h>
#include "lista.h"

struct lista{
    double info;
    struct lista *prox;
};

Lista* cria_lista(){
    Lista* ls = (Lista*) malloc(sizeof(Lista));
    if(ls!=NULL)
        *ls=NULL;
    return ls;
}

int lista_vazia(Lista* ls){
    if(ls == NULL || *ls == NULL)
        return 1;
    else
        return 0;
}

//insere din-encad recursiva
int insere_ord(Lista* ls, double elemento){
    if(ls==NULL)
        return 0;
    
    if(*ls==NULL || elemento <= (*ls)->info){
        Elemento *insere = (Elemento*) malloc(sizeof(Elemento));
        if(insere==NULL)
            return 0;

        insere->info = elemento;
        insere->prox = (*ls);
        *ls = insere;
        return 1;

    }else{
        int R = insere_ord(&((*ls)->prox),elemento);
        return R;
    }
}

//remove din-encad recursiva
int remove_ord(Lista* ls, double elemento){
    if(*ls==NULL || elemento < (*ls)->info)
        return 0;
    else{
        if(elemento==(*ls)->info){
            Elemento *remove = (*ls);
            *ls = remove->prox;
            free(remove);
            return 1;

        }else{
            int R = remove_ord(&((*ls)->prox),elemento);
            return R;
        }
    }
}

int obtem_elem(Lista* ls, int posicao, double *info){
    if(*ls==NULL || posicao<=0)
        return 0;
    
    Elemento *obtem = *ls;
    int i = 1;
    while(obtem!=NULL && i<posicao){
        obtem=obtem->prox;
        i++;
    }
    if(obtem==NULL)
        return 0;
    else{
        *info = obtem->info;
        return 1;
    }
}