#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//TAD lista não ordenada, dinamica com ENCADEAMENTO DUPLO
//ENCADEAMENTO DUPLO: tambem aponta pro elemento de tras (anterior)
//info: numeros inteiros
//operacoes: retornar tamanho, remover todas as ocorrencias de um elemento, remover maior
//esvaziar a lista, inverter a lista, retornar os multiplos de 3 de uma lista

struct no {
    int info;
    struct no *prox;
    struct no *ant; //agr tem anterior pq é encad. duplo
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

// Inser��o no in�cio
int insereElem(Lista *li, int element) {
    // Aloca��o de um novo n� e seu preenchimento
    Lista N = (Lista) malloc(sizeof(struct no));
    if (N == NULL) {
        return 0;
    }
    N->info = element;
    N->ant = NULL; // N�o h� antecessor ao novo n�
    N->prox = *li; // O sucessor � o resto da lista j� existente
    if (listaVazia(*li) == 0) {
        (*li)->ant = N; // O antecessor do 1� n� (antes nulo) aponta pro novo n�
    }
    *li = N; // Faz lista apontar pro 1� n�
    return 1;
}

//recebe o elemento a ser removido
int removeElem(Lista *lst, int elem){
    if(listaVazia(*lst) == 1)
        return 0;

    Lista aux = *lst;

    while(aux->prox != NULL && aux->info != elem)
        aux = aux->prox;

    if(aux->info != elem) return 0;

    if(aux->prox != NULL)
        aux->prox->ant = aux->ant;
    if(aux->ant != NULL)
        aux->ant->prox = aux->prox;
    if(aux == *lst)
        *lst = aux->prox;
    free(aux);
    return 1;
}

//utilizado p imprimir lista
int obtem_valor(Lista lst, int Pos){
    int i = 1;

    while(lst->prox != NULL && i < Pos){
        lst = lst->prox;
        i++;
    }
    return lst->info;
}

int tamanho(Lista li) {
    int Temp = 0;
    while (li != NULL) {
        Temp++;
        li = li->prox;
    }
    return Temp;
}

int esvaziar(Lista *li) {
    if (listaVazia(*li) == 1) {
        return 0;
    }
    while (listaVazia(*li) != 1) {
        removeElem(li, (*li)->info); //usa funcao pra remover cada elemento da lista
    }
    return 1;
}

//remove o maior elemento de uma lista
int removeMaior(Lista *li) {

    if(listaVazia(*li)==1)
        return 0;

    Lista aux = *li;
    int maior = (*li)->info;
    while (aux != NULL) {
        if (aux->info > maior) {
            maior = aux->info; //verifica qual é o maior
        }
        aux = aux->prox;
    }
    removeElem(li, maior); //usa funcao pra remover
    return 1;
}

//retorna uma nova lista q é a inversa da lista de entrada
Lista inverter(Lista lst){

    if(listaVazia(lst) == 1)
        return lst;

    Lista lst2 = NULL;

    while(lst != NULL){
        insereElem(&lst2,lst->info); //usa funcao pra inserir na nova lista
        lst = lst->prox;
    }

    return lst2;
}

//retorna uma nova lista com os multiplos de 3 ja inseridos em uma lista
Lista multiplos3(Lista lst){
    Lista lst2 = NULL;

    if(listaVazia(lst)==1)
        return 0;

    ///Pra ficar na mesma ordem da lista original vou verificar de tras pra frente
    while(lst->prox != NULL){
        lst = lst->prox;
    }

    while(lst != NULL){
        if(lst->info % 3 == 0) //verifica se é multiplo de 3
            insereElem(&lst2, lst->info); //insere os multiplos na nova lista
            lst = lst->ant;
    }

    return lst2;
}

//recebe um elemento a ser removido e apaga todas suas ocorrencias
int removeTodos(Lista *lst, int elem){
    int flag = 0; //qtd de remocoes feitas

    Lista aux;

    while(aux != NULL){ //comeca repeticao
            aux = *lst;

        if(aux == NULL) ///Ap�s remover o unico elemento da lista restante.
            return flag;

        while(aux->prox != NULL && aux->info != elem){
            aux = aux->prox; //avanca na lista
        }

        if(aux->info == elem) flag++; /// Flag conta a quantidade de remo�oes que foram feitas

        if(aux->info != elem) return flag;

        if(aux->prox != NULL)
            aux->prox->ant = aux->ant;
        if(aux->ant != NULL)
            aux->ant->prox = aux->prox;
        if(aux == *lst)
            *lst = aux->prox;
        free(aux);
    }
    //acaba repeticao
    return flag;
}
