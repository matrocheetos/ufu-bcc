#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no{
    struct cliente info;
    struct no *prox;
};

struct fila{
    struct no *ini;
    struct no *fim;
};

Fila cria_fila(){
    Fila f;

    f = (Fila) malloc(sizeof(struct fila));
    if(f != NULL){
        f->ini = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_vazia(Fila f){
    if(f->ini == NULL)
        return 1;
    return 0;
}

int insere_fim(Fila f, struct cliente elem){
    struct no *novo;

    novo = (struct no*) malloc(sizeof(struct no));

    if(novo == NULL)
        return 0;

    //Copia os dados de "elem" para o novo nó
    novo->info.hora_entrada = elem.hora_entrada;
    novo->info.minuto_entrada = elem.minuto_entrada;
    novo->info.segundo_entrada = elem.segundo_entrada;
    novo->info.tempo_de_atendimento = elem.tempo_de_atendimento;
    novo->info.tempo_de_espera = elem.tempo_de_espera;
    novo->prox = NULL;

    //Se a fila for vazia esse nó é também o primeiro elemento da fila
    if(fila_vazia(f) == 1)
        f->ini = novo;
    //Se nao for vazia o campo fim nao sera null, portanto é necessario que o novo nó seja colocado depois do fim
    else
        f->fim->prox = novo;
    //Todo novo nó inserido é o ultimo por se tratar de uma fila
    f->fim = novo;
    return 1;
}

int remove_inicio (Fila f, struct cliente *elem){
    if(fila_vazia(f) == 1)
        return 0;

    //Copia os dados do elemento inicial para o "elem"
    struct no *aux = f->ini;
    elem->hora_entrada = aux->info.hora_entrada;
    elem->minuto_entrada = aux->info.minuto_entrada;
    elem->segundo_entrada = aux->info.segundo_entrada;
    elem->tempo_de_atendimento = aux->info.tempo_de_atendimento;
    elem->tempo_de_espera = aux->info.tempo_de_espera;

    //Se a fila possuir apenas um elemento o fim precisa voltar a apontar null
    if(f->ini == f->fim)
        f->fim = NULL;

    //O inicio aponta para o proximo elemento da lista, podendo ser null, caso a lista tenha apenas um elemento
    f->ini = aux->prox;
    //Libera o primeiro no da lista
    free(aux);
    return 1;
}

int tamanho(Fila f){
    int tam = 0;

    struct no *aux = f->ini;

    //Percorre a fila, em cada elemento, soma 1 no tamanho
    while(aux != NULL){
        tam++;
        aux = aux->prox;
    }

    return tam;
}
