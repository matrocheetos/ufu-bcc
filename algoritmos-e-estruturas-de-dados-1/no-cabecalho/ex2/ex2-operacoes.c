#include <stdlib.h>
#include "ex2.h"

struct lista{
    int info;
    struct lista *prox;
};

Lista criar_lista(){
    Lista ls;
    ls = (Lista) malloc(sizeof(Elemento));
    if(ls != NULL){
        ls->prox = NULL;
        ls->info = 0; //opcional: guardar qtd
    }
    return ls;
}

int lista_vazia(Lista ls){
    if(ls->prox == NULL)
        return 1; //vazia
    else
        return 0; //nao vazia
}

//lista não fica cheia, não tem lista_cheia()

//ordenada - sem passagem por referencia
int insere_elem(Lista ls, int elemento){
    Lista insere = (Lista) malloc(sizeof(Elemento));
    if(insere==NULL)
        return 0;

    insere->info = elemento;

    Lista aux = ls;
    while(aux->prox != NULL && aux->prox->info < elemento)
        aux = aux->prox; //avança

    //insere novo nó na lista
    insere->prox = aux->prox;
    aux->prox = insere;
    ls->info++; //incrementa nós da lista
    return 1;
}

int remove_elem(Lista ls, int elemento){
    if(lista_vazia(ls)==1)
        return 0;
    Lista remove = ls;

    while(remove->prox != NULL && remove->prox->info < elemento)
        remove=remove->prox;
    if(remove->prox == NULL || remove->prox->info > elemento)
        return 0;

    Lista remove2 = remove->prox;
    remove->prox = remove2->prox;
    free(remove2);
    ls->info--;
    return 1;
}

int obtem_valor_elem(Lista ls, int posicao, int *informacao){
    if(ls == NULL)
        return 0;

    Lista conteudo = ls;
    int i=0;
    while(conteudo != NULL && i-1<posicao){
        conteudo=conteudo->prox;
        i++;
    }
    if(conteudo == NULL)
        return 0;
    else{
        *informacao = conteudo->info;
        return 1;
    }
}