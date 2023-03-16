#include <stdlib.h>
#include "lista.h"

struct lista{
    int tipo;
    void *info;
    struct lista *prox;
};

Lista* criar_lista(int tipo){
    Lista *ls = (Lista*) malloc(sizeof(Lista));
    if(ls != NULL){
        (*ls)->tipo = tipo;
        *ls = NULL;
    }
    return ls;
}

int lista_vazia(Lista* ls){
    if(ls == NULL || *ls == NULL)
        return 1;
    else
        return 0;
}

int insere_elem(Lista* ls, float info_f, char info_c){
    if(ls==NULL) return 0;
    Elemento *insere = (Elemento*) malloc(sizeof(Elemento));
    if(insere == NULL) return 0;
    
    if((*ls)->tipo == 0){
        float *f;
        *f = info_f;
        insere->info = f;
    }else if((*ls)->tipo == 1){
        if(info_c < 65 || info_c > 68)
            return 0;
        char *c;
        *c = info_c;
        insere->info = c;
    }

    insere->prox = (*ls);
    *ls = insere;
    return 1;
}

int remove_elem(Lista* ls, float info_f, char info_c){
    Elemento* remove = (*ls);

    if((*ls)->tipo == 0){
        float *f;
        *f = info_f;
        if(f == (*ls)->info){ //1o elemento
            *ls = remove->prox;
            free(remove);
            return 1;
        }
        while(remove->prox != NULL && remove->prox->info != f)
            remove=remove->prox;
    }
    else if((*ls)->tipo == 1){
        if(info_c < 65 || info_c > 68)
            return 0;
        char *c;
        *c = info_c;
        if(c == (*ls)->info){ //1o elemento
            *ls = remove->prox;
            free(remove);
            return 1;
        }
        while(remove->prox != NULL && remove->prox->info != c)
            remove=remove->prox;
    }

    if(remove->prox == NULL)
        return 0; //matricula nao encontrada

    Elemento* remove2 = remove->prox;
    remove->prox = remove2->prox;
    free(remove2);
    return 1;
}

int obtem_elem_pos(Lista* ls, int posicao, float *info_f, char *info_c){
    Elemento* elem = *ls;
    int i=0;
    while(elem != NULL && i<posicao){
        elem=elem->prox;
        i++;
    }

    if(elem == NULL)
        return 0;
    else{
        if((*ls)->tipo == 0){
            float *f = elem->info;
            *info_f = *f;
        }else if((*ls)->tipo == 1){
            char *c = elem->info;
            *info_c = *c;
        }
        return 1;
    }
}