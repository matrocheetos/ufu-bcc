#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define max 20

struct pilha{
    int no[max];
    int topo;
};

pilha cria_pilha(){
    pilha p;
    p = (pilha)malloc(sizeof(struct pilha));
    if(p!=NULL)
        p->topo = -1;
    return p;
}

int pilha_vazia(pilha p){
    if(p->topo == -1)
        return 1;
    else
        return 0;
}

int pilha_cheia(pilha p){
    if(p->topo == max-1)
        return 1;
    else
        return 0;
}

int push(pilha p, int elem){
    if(p == NULL  || pilha_cheia(p) == 1)
        return 0;
    p->topo ++;
    p->no[p->topo] = elem;
    return 1;
}

int pop(pilha p, int *elem){
    if(p == NULL  || pilha_vazia(p) == 1)
        return 0;
    *elem = p->no[p->topo];
    p->topo--;
    return 1;
}

int ve_topo(pilha p, int *elem){
    if(p == NULL  || pilha_vazia(p) == 1)
        return 0;
    *elem = p->no[p->topo];
    return 1;
}

int esvazia_pilha(pilha p){
    if(pilha_vazia(p)==1)
        return 0;

    while(pilha_vazia(p)==0){
        p->topo--;
    }
    return 1;
}
