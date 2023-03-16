#include <stdio.h>
#include <stdlib.h>
#define max 20
#include "lista.h"

// TAD lista não ordenada estatica/sequencial
//info: nros inteiros
//operacoes: remover impares, retornar menor, retornar tamanho,
//esvaziar lista, inverter lista, concatenar lista

struct lista{ //define a estrutura lista
    int no[max];
    int Fim;
};

Lista cria_lista(){
    Lista lst;
    lst = (Lista)malloc(sizeof(struct lista));

    if(lst != NULL)
        lst -> Fim=0;

    return lst;
}

int lista_vazia(Lista lst){
    if(lst -> Fim==0)
        return 1; //lista está vazia
    else
        return 0;
}

int lista_cheia(Lista lst){
    if(lst -> Fim==max)
        return 1; //lista está cheia
    else
        return 0;
}

//insercao nao ordenada
int insere_elem(Lista lst, int elem) {
    if (lst == NULL || lista_cheia(lst) == 1)
        return 0;

    lst->no[lst->Fim] = elem;
    lst->Fim++;
    return 1;
}

//recebe o elemento a ser removido
int remove_elem(Lista lst, int elem) {
    if (lst == NULL || lista_vazia(lst) == 1)
        return 0;
    int i, aux = 0;
    while (aux < lst->Fim && lst->no[aux] != elem)
        aux++;

    if (aux == lst->Fim)
        return 0;

    for (i = aux+1; i < lst->Fim; i++)
        lst->no[i-1] = lst->no[i];

        lst->Fim--;
    return 1;
}

void imprime_lista(Lista p){
    int i=0;
    for(i=0;i<p->Fim;i++){
        printf("%d",p->no[i]);
        if(i<p->Fim-1)printf(" ");
    }
    printf("\n");
}

//retorna o menor elemento
int menor(Lista p){
    if(p->Fim==0)
        return 0;

    int i,menor = p->no[0];

    for(i=1;i<p->Fim;i++){
        if(p->no[i]<menor) //verificacao de menor
            menor=p->no[i];
    }
    return menor;
}

int tamanho(Lista p){
    return p->Fim; //nao eh fim-1 pq comeca contando do 1
}

//concatenar: recebe listas L1 e L2, retorna L3 (L1 seguido de L2)
int concatenar(Lista lst, Lista lst2,Lista *lst3){
    int i;
    if ( (lst->Fim + lst2->Fim) > max)
        return 0;
    *lst3=cria_lista(); //cria a lista resultado da concatenacao de L1 e L2
     if (*lst3 == NULL) {
        return 0;
    }
    for (i = 0; i < lst->Fim; i++) {
        (*lst3)->no[(*lst3)->Fim] = lst->no[i]; //insere todos elementos L1
        (*lst3)->Fim++;
    }
    for (i = 0; i < lst2->Fim; i++) {
        (*lst3)->no[(*lst3)->Fim] = lst2->no[i]; //insere todos elementos L2
        (*lst3)->Fim++;
 }
    return 1;
}

int remove_impar(Lista lst){

    if(lista_vazia(lst) == 1)
        return 0;

    int i = 0,j;
    int k=0, flag=0;

    while(k<lst->Fim){
    for(i=0; i<lst->Fim;i++){
        if(lst->no[i] % 2 != 0){ //verifica se é impar
            for(j = i; j < (lst->Fim)-1; j++)
                lst->no[j] = lst->no[j+1]; //movendo a lista qnd remove o elemento
        lst->Fim--;
        flag++;
        }
    }
    k++;
    }
    return flag;
}

int esvaziar(Lista lst){

    if(lista_vazia(lst) == 1)
        return 0;

    lst->Fim = 0; //so mudou a posicao do fim
    return 1;
}

int inverter(Lista lst, Lista lst2){

    int i;

    for(i=(lst->Fim-1);i>=0;i--){
        insere_elem(lst2,lst->no[i]); //percorre toda a lista e insere na ordem inversa
    }
    return 1;
}

