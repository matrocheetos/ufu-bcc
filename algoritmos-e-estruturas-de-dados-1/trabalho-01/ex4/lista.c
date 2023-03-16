#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//TAD lista ordenada dinamica/encadeada COM CABEÇALHO
//info: nros reais
//mesmas operacoes do ex3, mas agora possui cabeçalho e é lista de char(ex3 era numeros reais)

struct no{
    char info;
    struct no *prox;
};

lista cria_lista(){ //cria a lista inicializando o cabeçalho
    lista cab;
    cab = (lista)malloc(sizeof(struct no));
    if(cab!=NULL){
        cab->info = 0;
        cab->prox = NULL;
    }
    return cab;
}

int lista_vazia(lista lst){
    if(lst->prox == NULL){
        return 1;
    }
    return 0;
}

//similar à do ex3 mas adaptada ao uso do cabeçalho
int insere_ord(lista lst,char elem){
    lista n = (lista) malloc(sizeof(struct no));
    if(n == NULL){
        return 0;
    }
    //como tem cabeçalho, não verifica se a lista está vazia pq ja tem um elemento
    //por isso ja vai pra parte q procura onde inserir (ordenada)
    n->info=elem;
    lista aux = lst;
    while(aux->prox != NULL && aux->prox->info < elem)
        aux=aux->prox;

    n->prox = aux->prox;
    aux->prox = n;
    lst->info++; //adiciona 1 ao cabeçalho
    return 1;
}

int remove_ord(lista lst,char elem){
    if(lista_vazia(lst) == 1)
        return 0;

    lista aux = lst;
    while(aux->prox !=NULL && aux->prox->info < elem)
        aux = aux->prox;

    if(aux->prox == NULL || aux->prox->info > elem)
        return 0;

    lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    lst->info--; //diminui 1 do cabeçalho
    return 1;
}

//imprime igual ex3
void imprime_lista(lista lst){
    if(lista_vazia(lst)==1)
        printf("lista vazia");
    lista aux = lst->prox;
    while(aux!=NULL){
        printf(" %c ", aux->info);
        aux=aux->prox;
    }
    printf("\n");
}

//so precisa retornar o valor guardado no cabeçalho
int tamanho(lista lst){
    if(lista_vazia(lst)==1)
        return 0;
    else
        return lst->info;
}

//igual ex3
int maior(lista p){
    if(lista_vazia (p)==1)
        return 0;
    int maior=0;
    lista aux=p;
    while(aux!=NULL){
        if(aux->info>maior)
            maior=aux->info;
        aux=aux->prox;
    }
    return maior;
}

//igual ex3
int iguais(lista a,lista b){

    lista aux=a;
    lista aux2=b;
    while(aux!=NULL){
        if(aux->info!=aux2->info)
            return 0;
        aux=aux->prox;
        aux2=aux2->prox;
    }
return 1;
}

//igual ex3
int intercala(lista a, lista b, lista c){


    lista aux = a->prox;
    lista aux2 = b->prox;

    while(aux != NULL){
        insere_ord(c,aux->info);
        aux=aux->prox;
    }

    while(aux2 != NULL){
        insere_ord(c,aux2->info);
        aux2=aux2->prox;
    }
    return 1;
}

int esvaziar(lista lst){
    if(lista_vazia(lst)==1){
        return 0;
    }

    lista aux = lst;
    while(aux != NULL){
        lista aux2 = aux;
        aux = aux->prox; //limpa os valores da lista
        free(aux2);
    }
    lst->info = 0;      //precisa fazer alteracoes no cabeçalho
    lst->prox = NULL;   //faz lista apontar pra NULL
    return 1;
}
