#include <stdlib.h>
#include <string.h>
#include "ex1.h"

struct strings{
    char str[11];
};

struct lista{
    struct strings Str[20];
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

int insere_elem(Lista *l, char texto[40]){
    if(strlen(texto)>10)  //verifica tamanho da string
        return 1;
    else if(strlen(texto)<=10){
        strcpy(l->Str[l->fim].str,texto);
        l->fim++;
        return 0;
    }
}

int remove_elem(Lista *l, char texto[40]){
    if(strlen(texto)>10)  //verifica tamanho da string
        return 1;
    
    int i;
    for(i=0;i<20;i++){
        if(strcmp(texto,l->Str[i].str)==0){
            l->Str[i].str[0] = '\0';
            return 0;
        }
    }
    return 1;
}

char* get_pos(Lista *l, int posicao){
    return l->Str[posicao].str;
}