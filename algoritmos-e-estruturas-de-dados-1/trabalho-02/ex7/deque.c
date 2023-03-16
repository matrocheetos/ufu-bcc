#include <stdlib.h>
#include "deque.h"
#define max 20

struct deque{
    int no[max];
    int ini,cont;
};

deque cria_deque(){
    deque d;
    d = (deque)malloc(sizeof(struct deque));
    if(d!=NULL){
        d->ini = 0;
        d->cont = 0;
    }
    return d;
}

int deque_vazio(deque d){
    if(d->cont == 0)
        return 1;
    else
        return 0;
}

int deque_cheio(deque d){
    if(d->cont == max)
        return 1;
    else
        return 0;
}

int insere_ini(deque d,int elem){
    if(deque_cheio(d)== 1)
        return 0;

    if(d->ini == 0)
        d->ini = max-1;
    else
        d->ini = d->ini-1;

    d->no[d->ini] = elem;
    d->cont++;
    return 1;
}

int insere_fim(deque d,int elem){
    if(deque_cheio(d)== 1)
        return 0;
    d->no[(d->ini+d->cont)%max] = elem;
    d->cont++;
    return 1;
}

int remove_ini(deque d, int *elem){
    if(deque_vazio(d) == 1)
        return 0;
    *elem = d->no[d->ini];
    d->ini = (d->ini+1)%max;
    d->cont--;
    return 1;
}

int remove_fim(deque d, int *elem){
    if(deque_vazio(d) == 1)
        return 0;
    *elem = d->no[(d->ini+d->cont)%max];
    d->cont--;
    return 1;
}

void libera_deque(deque d){
    free(d);
}
