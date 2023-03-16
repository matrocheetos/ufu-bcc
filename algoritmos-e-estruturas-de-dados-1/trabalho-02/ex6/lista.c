#include <stdlib.h>
#include <strings.h>
#include "lista.h"

struct node{
    struct doador info;
    struct node *prox;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst == NULL)
        return 1;
    return 0;
}

int insere_ini(Lista *lst, struct doador elem){

    Lista N = (Lista) malloc(sizeof(struct node));

    if(N == NULL) return 0;

    strcpy(N->info.nome, elem.nome);
    strcpy(N->info.b_coracao, elem.b_coracao);
    strcpy(N->info.b_cornea, elem.b_cornea);
    strcpy(N->info.b_figado, elem.b_figado);
    strcpy(N->info.b_pulmao, elem.b_pulmao);
    strcpy(N->info.b_rins, elem.b_rins);
    N->info.coracao = elem.coracao;
    N->info.cornea = elem.cornea;
    N->info.figado = elem.figado;
    N->info.pulmao = elem.pulmao;
    N->info.rins = elem.rins;


    if(lista_vazia(*lst) == 1){
        N->prox = N;
        *lst = N;
    }else{
        N->prox = *lst;
        (*lst)->prox = N;
    }
    return 1;
}

int insere_fim(Lista *lst, struct doador elem){

    Lista N = (Lista) malloc(sizeof(struct node));

    if(N == NULL) return 0;

    strcpy(N->info.nome, elem.nome);
    strcpy(N->info.b_coracao, elem.b_coracao);
    strcpy(N->info.b_cornea, elem.b_cornea);
    strcpy(N->info.b_figado, elem.b_figado);
    strcpy(N->info.b_pulmao, elem.b_pulmao);
    strcpy(N->info.b_rins, elem.b_rins);
    N->info.coracao = elem.coracao;
    N->info.cornea = elem.cornea;
    N->info.figado = elem.figado;
    N->info.pulmao = elem.pulmao;
    N->info.rins = elem.rins;


    if(lista_vazia(*lst) == 1){
        N->prox = N;
        *lst = N;
    }else{
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
        *lst = N;
    }
    return 1;
}

int remove_ini_lista(Lista *lst, struct doador *elem){
    if(lista_vazia(*lst) == 1)
        return 0;

    Lista aux = (*lst)->prox;
    strcpy(elem->nome, aux->info.nome);
    strcpy(elem->b_coracao, aux->info.b_coracao);
    strcpy(elem->b_cornea, aux->info.b_cornea);
    strcpy(elem->b_figado, aux->info.b_figado);
    strcpy(elem->b_rins, aux->info.b_rins);
    strcpy(elem->b_pulmao, aux->info.b_pulmao);
    elem->coracao = aux->info.coracao;
    elem->cornea = aux->info.cornea;
    elem->figado = aux->info.figado;
    elem->rins = aux->info.rins;
    elem->pulmao = aux->info.pulmao;


    if((*lst)->prox == *lst)
        *lst = NULL;
    else
        (*lst)->prox = aux->prox;
    free(aux);
    return 1;
}

int remove_fim(Lista *lst, struct doador *elem){
    if(lista_vazia(*lst) == 1)
        return 0;

    strcpy(elem->b_coracao, (*lst)->info.b_coracao);
    strcpy(elem->b_cornea, (*lst)->info.b_cornea);
    strcpy(elem->b_figado, (*lst)->info.b_figado);
    strcpy(elem->b_rins, (*lst)->info.b_rins);
    strcpy(elem->b_pulmao, (*lst)->info.b_pulmao);
    elem->coracao = (*lst)->info.coracao;
    elem->cornea = (*lst)->info.cornea;
    elem->figado = (*lst)->info.figado;
    elem->rins = (*lst)->info.rins;
    elem->pulmao = (*lst)->info.pulmao;


    if((*lst)->prox == *lst){
        *lst = NULL;
        return 1;
    }

    Lista aux = (*lst)->prox;

    while(aux->prox != *lst)
        aux = aux->prox;

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    *lst = aux;
    free(aux2);
    return 1;
}
