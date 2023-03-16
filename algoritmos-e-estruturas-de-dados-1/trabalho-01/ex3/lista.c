#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//TAD lista ordenada dinamica/encadeada SEM CABEÇALHO
//info: nros reais
//alem das operacoes basicas:
//tamanho da lista, verifica se duas listas sao iguais, retorna o maior, esvazia lista, intercala listas

struct no{
    double info;
    struct no *prox;
};

lista cria_lista(){ //cria a lista retornando null, vai ter algum valor so na insercao
    return NULL;
}

int lista_vazia(lista lst){
    if(lst == NULL){
        return 1;
    }
    return 0;
}

//insercao ordenada em lista dinamica
int insere_ord(lista *lst,double elem){
    lista n = (lista) malloc(sizeof(struct no));
    if(n == NULL){
        return 0;
    }
    n->info=elem;
    if(lista_vazia(*lst) || elem<=(*lst)->info){ //verifica se é lista vazia
        n->prox = *lst;
        *lst = n;
        return 1;
    }
    lista aux = *lst;
    while(aux->prox != NULL && aux->prox->info < elem)
        aux=aux->prox;

    n->prox = aux->prox;
    aux->prox = n;
    return 1;
}

int remove_ord(lista *lst,double elem){
    if(lista_vazia(*lst) == 1 || elem<(*lst)->info)
        return 0;

    lista aux = *lst;
    if(elem == (*lst)->info){ //primeiro ou unico elemento
        *lst = aux->prox;
        free(aux);
        return 1;
 }
    while(aux->prox !=NULL && aux->prox->info < elem) //percorre lista
        aux = aux->prox;

    if(aux->prox == NULL || aux->prox->info > elem)
        return 0;

    lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

void imprime_lista(lista lst){
    if(lst==NULL)
        printf("lista vazia");
    while(lst!=NULL){
        printf(" %lf ", lst->info);
        lst=lst->prox;
    }
    printf("\n");
}

//percorre a lista e retorna quantos elementos ela possui
int tamanho(lista *lst){
    if(lista_vazia(*lst)==1)
    {
        return 0;
    }
    else
    {
        int cont = 1;
        lista aux;
        aux = *lst;
        if(aux->prox==NULL){
            return 1;
        }
        else{
        do{cont++;
            aux=aux->prox;
        }while(aux->prox!=NULL);
        return cont;
        }
    }
}

int maior(lista p){
    if(lista_vazia (p)==1)
        return 0;

    int maior=0;
    lista aux=p;
    while(aux!=NULL){
        if(aux->info>maior) //verifica qual o maior
            maior=aux->info;
        aux=aux->prox;
    }
return maior;
}

//compara duas listas e verifica se sao iguais
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

int intercala(lista a, lista b, lista *c){


    lista aux = a;
    lista aux2 = b;

    while(aux != NULL){
        insere_ord(c,aux->info); //insere lista 1 ordenada
        aux=aux->prox;
    }

    while(aux2 != NULL){
        insere_ord(c,aux2->info); //insere lista 2 ordenada
        aux2=aux2->prox;
    }
    return 1;
}

int esvaziar(lista *lst){

    if(lista_vazia(*lst)==1){
        return 0;
    }

    while(*lst != NULL){  //faz lista apontar pra NULL (lista chega no ultimo elemento e aponta pra NULL??)
        lista aux = *lst;
        *lst = aux->prox;
        free(aux);
    }
    return 1;
}
