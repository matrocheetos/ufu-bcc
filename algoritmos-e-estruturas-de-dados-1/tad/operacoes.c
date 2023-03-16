#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ex1.h"

struct ponto{
    int x,y;
};

void cria_pto(int x, int y, int i){
    if(i==1){
    Ponto *ponto;
    ponto = (Ponto*) malloc(2*sizeof(Ponto));
    if(ponto==NULL){
        printf("memoria insuficiente!\n");
        exit(1);
    }
    }
    ponto[i-1].x=x;
    ponto[i-1].y=y;
}

double distancia_pto(){
    return sqrt((ponto[1].x-ponto[0].x) * (ponto[1].x-ponto[0].x) + (ponto[1].y-ponto[0].y) * (ponto[1].y-ponto[0].y));
}

void libera_pto(){
    free(ponto);
}