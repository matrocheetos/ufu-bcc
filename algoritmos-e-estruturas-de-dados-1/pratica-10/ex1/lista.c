#include <stdlib.h>
#include "lista.h"
#define MAX 30

struct lista{
    int tipo; //guarda o tipo da lista
    Union info[MAX];
    int fim;
};

Lista* criar_lista(int tipo){
    Lista *ls = (Lista*) malloc(sizeof(Lista));
    if(ls != NULL){
        ls->fim = 0;
        ls->tipo = tipo;
    }
    return ls;
}

int lista_vazia(Lista* ls){
    if(ls == NULL || ls->fim == 0)
        return 1;
    else
        return 0;
}

int lista_cheia(Lista* ls){
    if(ls->fim >= MAX)
        return 1;
    else
        return 0;
}

int insere_elem(Lista* ls, Union info){
    if(ls->tipo == 0)
        ls->info[ls->fim].i_float = info.i_float;
    else if(ls->tipo == 1){
        if(info.i_char < 65 || info.i_char > 68)
            return 0;
        ls->info[ls->fim].i_char = info.i_char;
    }else
        return 0;
    ls->fim++;
    return 1;
}

int remove_elem(Lista* ls, Union info){
    int i,j;
    if(ls->tipo==0){
        for(i=0;i<ls->fim;i++){
            if(ls->info[i].i_float == info.i_float){
                for(j=i;j<ls->fim-1;j++)
                    ls->info[j].i_float = ls->info[j+1].i_float;
                ls->fim--;
                return 1;
            }
        }
    }
    if(ls->tipo==1){
        if(info.i_char < 65 || info.i_char > 68)
            return 0;
        for(i=0;i<ls->fim;i++){
            if(ls->info[i].i_char == info.i_char){
                for(j=i;j<ls->fim-1;j++)
                    ls->info[j].i_char = ls->info[j+1].i_char;
                ls->fim--;
                return 1;
            }
        }
    }
    return 0;
}

int obtem_elem_pos(Lista* ls, int posicao, Union *info){
    if(posicao >= ls->fim)
        return 0;
    else if(ls->tipo == 0)
        info->i_float = ls->info[posicao].i_float;
    else if(ls->tipo == 1)
        info->i_float = ls->info[posicao].i_float;
    return 1;
}