#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

//TAD lista não ordenada, dinâmica com ENCADEAMENTO CÍCLICO
//não ordenada pq não importa a patente dos soldados, é aleatório
//encadeamento cíclico pq os soldados sao organizados em uma roda, facilita a logica do exercicio

struct no {
char nome[20];
struct no * prox;
};

Lista cria_lista() {
return NULL;
}

int lista_vazia (Lista lst) {
if (lst == NULL)
return 1;
else
return 0;
}

//insere no final da lista circular
int insere_final (Lista *lst, char name[]) {

    Lista N = (Lista) malloc(sizeof(struct no));

if (N == NULL) return 0;

    strcpy(N->nome, name);
if (lista_vazia(*lst) == 1) { //ainda nao ha elementos na lista:
    N->prox = N; //novo nó aponta pra ele mesmo (circulo)
    *lst = N; //lista aponta pro novo nó (N)
}else { //ja tem elementos na lista:
    N->prox = (*lst)->prox; //novo nó aponta para 1o nó
    (*lst)->prox = N; //ultimo nó aponta pra novo nó (circulo)
    *lst = N; //lista aponta pra novo nó
}
return 1;
}

//recebe nome do soldado e o remove do meio da lista
int remove_soldado(Lista *lst,int n, char soldado[]){
    Lista aux = (*lst)->prox;

    for(int i = 0;i < n-1; i++){
        aux = aux->prox;
    }

    struct no *aux2 = aux->prox;
    strcpy(soldado, aux2->nome);

    aux->prox = aux2->prox;
    (*lst) = aux;
    free(aux2);


    return n;


}

//remove um soldado do início da lista
int remove_inicio (Lista *lst, char name[]) {
if(lista_vazia(*lst) == 1) return 0;

    Lista aux = (*lst)->prox;
    strcpy(name, aux->nome);

if(*lst == (*lst)->prox)
    *lst = NULL;
else
    (*lst)->prox = aux->prox;
free(aux);

return 1;
}

//remove um soldado do fim da lista
int remove_fim(Lista *lst,char soldado[]){
    if(lista_vazia(*lst) == 1) return 0;
    struct no *aux = (*lst)->prox;
    while(aux->prox != (*lst)){
        aux = aux->prox;
    }
    struct no *aux2 = aux->prox;
    aux->prox = aux2->prox;
    strcpy(soldado,aux2->nome);
    free(aux2);
    (*lst) = aux;
    return 1;
}


//sorteia o soldado a ser utilizado na entrada 2 e 3
void sorteiasoldado(Lista *lst,int num,char soldado[]){
    for(int i = 0;i<num-1;i++){
        (*lst) = (*lst)->prox;
    }
    strcpy(soldado, (*lst)->prox->nome);
}

//imprime a lista de soldados q ainda estao em volta da fogueira
void imprime(Lista *lst){
    if(lista_vazia(*lst) == 1){
        printf("Infelizmente nao temos nenhum soldado restante ;-;\n");
    }else{
    Lista aux = (*lst)->prox;
    printf("Lista de soldados : ");
    while(aux !=  (*lst)){
        printf("%s, ",aux->nome);
        aux = aux->prox;
    }
        printf("%s \n",(*lst)->nome);
    }
}

//imprime o nome do ultimo soldado sobrevivente
void imprimesobrevivente(Lista *lst){
        printf("%s \n",(*lst)->nome);
}

//encontra o soldado a ser utilizado na entrada 3
int procura_soldado(Lista *lst, char soldado[]){
    int cont = 1;
    Lista aux = (*lst)->prox;
    while(strcmp(aux->nome,soldado) != 0){
        cont++;
        aux = aux->prox;
    }
    return cont;
}

int tamanho(Lista *lst){
    if(lista_vazia(*lst) == 1){
        return 0;
    }else{
    int cont = 1;
    Lista aux = (*lst)->prox;
    while(aux != (*lst)){
        cont++;
        aux = aux->prox;
    }
        return cont;
    }
}
