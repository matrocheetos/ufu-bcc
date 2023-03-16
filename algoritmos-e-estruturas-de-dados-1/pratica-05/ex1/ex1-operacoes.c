#include <stdlib.h>
#include "ex1.h"

struct lista{
    int inteiro;
    struct lista *prox;
};

Lista* inicializar_lista(){
    Lista* ls = (Lista*) malloc(sizeof(Lista));
    if(ls != NULL)
        *ls = NULL;
    return ls;
}

int lista_vazia(Lista* ls){
    if(ls == NULL)
        return 1; //vazia
    if(*ls == NULL)
        return 1; //vazia

    return 0; //não vazia
}

int lista_cheia(){
    Lista *ls = (Lista*) malloc(sizeof(Lista));
    if(ls == NULL)
        return 1; //nao conseguiu alocar memoria
    else
        return 0; //memoria não acabou
}

//insercao dinamica-encadeada ordenada
int insere_ord(Lista* ls, int elemento){
    Elemento *insere = (Elemento*) malloc(sizeof(Elemento));
    if(insere == NULL)
        return 0;

    insere->inteiro = elemento;
    if(lista_vazia(ls) == 1){ //primeiro elemento
        insere->prox = (*ls);
        *ls = insere;
        return 1;
    }
    else{ //procura posicao para inserir
        Elemento *anterior, *atual = *ls;
        while(atual != NULL && atual->inteiro < elemento){
            anterior = atual;
            atual = atual->prox;
        }
        if(atual == *ls){
            insere->prox = (*ls);
            *ls = insere;
        }else{
            insere->prox = anterior->prox;
            anterior->prox = insere;
        }
        return 1;
    }
}

int remove_ord(Lista* ls, int elemento, int opcao){
    Elemento *anterior, *remove=*ls;
    if(opcao==0){ //1a ocorrencia
        while(remove != NULL && remove->inteiro != elemento){
            anterior = remove;
            remove = remove->prox;
        }
    }else{ //por posicao
        int contador=0;
        while(remove != NULL && contador != elemento){
            anterior = remove;
            remove = remove->prox;
            contador++;
        }
    }
    if(remove == NULL) //elemento nao encontrado
        return 0;
    if(remove == *ls)
        *ls = remove->prox;
    else
        anterior->prox = remove->prox;

    free(remove);
    return 1;
}

int get_pos(Lista* ls, int posicao, int *informacao){
    if(ls == NULL)
        return 0;

    Elemento* conteudo = *ls;
    int i=0;
    while(conteudo != NULL && i<posicao){
        conteudo=conteudo->prox;
        i++;
    }

    if(conteudo == NULL)
        return 0;
    else{
        *informacao = conteudo->inteiro;
        return 1;
    }
}