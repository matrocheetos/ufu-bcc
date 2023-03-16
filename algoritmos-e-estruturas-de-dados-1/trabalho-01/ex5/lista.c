#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//TAD lista não ordenada, dinamica com ENCADEAMENTO CICLICO
//CICLICO: ultimo aponta pro primeiro
//info: numeros reais
//operacoes inserir no inicio, inserir na posicao definida
//remover da posicao, tamanho e retornar maior elem

struct no {
    double info;
    struct no *prox;
};

Lista criaLista() { //cria a lista retornando null
    return NULL;
}

int listaVazia(Lista li) {
    if (li == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int insereInicio(Lista *li, double element) {
    Lista aux = *li;

    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL) {
        return 0;// Falha: n� n�o alocado
    }

    N->info = element;
    if(listaVazia(*li) == 1){
        N->prox = N;
        *li= N;
        return 1;
    }

    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

//operacoes vistas em sala??? (nao pediu no ex)
int insereFinal(Lista *li, double element) {
    Lista N = (Lista) malloc(sizeof(struct no)); // Aloca um novo nó e preenche campo info
    if (N == NULL) {
        return 0;  //falha: nó não alocado
    }
    N->info = element; // Insere o conteúdo
    // Caso em uma lista vazia
    if (listaVazia(*li) == 1) {
        N->prox = N; // Faz o novo nó apontar para ele mesmo
        *li = N; // Faz a lista apontar para o novo nó (último nó)
    }
    // Caso já tenha elementos naa lista, procura onde inserir
    else {
        N->prox = (*li)->prox; // Faz o novo nó apontar o 1o nó
        (*li)->prox = N; // Faz o último nó apontar para o novo nó
        *li = N; // Faz a lista apontar para o novo nó (último nó)
    }
    return 1;
}

//operacoes vistas em sala??? (nao pediu no ex)
int removeInicio(Lista *li, double *element) {
    // Trata lista vazia
    if (listaVazia(*li) == 1) {
        return 0;
    }
    Lista aux = (*li)->prox; // Faz aux apontar para 1o n�
    *element = aux->info; // Retorna valor do n� a ser removido
    if (*li == (*li)->prox) {
        *li = NULL;// Trata lista com 1 �nico n�
    }
    else {
        (*li)->prox = aux->prox;// Trata lista com + de 1 elemento
    }
    free(aux);
    return 1;
}

int imprimeLista(Lista li) {

    if (listaVazia(li) == 1) {
        printf("\nLista vazia\n");
        return 0;
    }

    Lista aux = li;
    aux = aux->prox; // Faz com que aux->info seja o primeiro elemento
    printf("Lista: ");
    do {
        printf("%.2lf ", aux->info);
        aux = aux->prox;
    }while (aux != li->prox);
    return 1;
}

int tamanho(Lista li) {
    if(listaVazia(li)==1){
        return 0;
    }
    Lista aux = li;
    int count = 0;
    do {
        count++;
        aux = aux->prox; //percorre a lista e conta quantos elementos
    }while (aux != li);
    return count;
}

// retorna o maior elemento
double maior(Lista li) {
    Lista aux = li;
    double maiorTemp = aux->info;
    do {
        if (aux->info > maiorTemp) { //verifica o maior
            maiorTemp = aux->info;
        }
        aux = aux->prox;
    }while (aux != li);
    return maiorTemp;
}

//recebe a posicao do elemento a ser removido
int removePos(Lista *li, int posicao) {

    if(posicao<1){ //nao pode ser posicao menor q 1, pq comeca a contar em 1
        return 0;
    }

    if(posicao>tamanho(*li)+1){ //verifica se a posicao é maior q o tamanho da lista
        return 0;
    }

    Lista aux = *li;
    aux = aux->prox; //(SO FALAR SE ELE PERGUNTAR)primeiro elemento de *li vai ser sempre apontado pelo final da lista

    if (posicao == 1) { //remove do inicio
        (*li)->prox = aux->prox;
        free(aux);
        return 1;
    } //ou procura onde remover{
    int i;
    for (i = 0; i < posicao - 2; i++) {
        aux = aux->prox;
    }
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
    //}
}

//recebe um elemento a ser inserido e sua posicao
int inserePos(Lista *li, int posicao, double element) {

    if(posicao<1){
        return 0;
    }

    if(posicao>tamanho(*li)+1){ //posicao maior que o max da lista
        return 0;
    }

    if (posicao == 1) { //se pede pra inserir no inicio
        insereInicio(li, element);
        return 1;
    }

    Lista aux = *li;
    aux = aux->prox; // Pula para o primeiro elemento da lista

   if (posicao == tamanho(*li) + 1) { //se pede pra inserir no final
        insereFinal(li, element);
    }
    else { //procura a posicao pra inserir
        Lista N = (Lista) malloc(sizeof(struct no));
        if (N == NULL) {
            return 0;
        }
        N->info = element; // Insere o conteúdo

        int i;
        for (i = 2; i <= posicao - 1; i++) {
            aux = aux->prox;
        }
        N->prox = aux->prox; //coloca o elemnto no meio da lista
        aux->prox = N;
    }
    return 1;
}

