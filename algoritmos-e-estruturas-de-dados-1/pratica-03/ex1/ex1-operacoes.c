#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ex1.h"

struct nro_complexo{
    double real,imaginaria;
};

Complexo* cria_nro(double Cr, double Ci){
    Complexo* p = (Complexo*) malloc(sizeof(Complexo));
    if(p!=NULL){
        p->real = Cr;
        p->imaginaria = Ci;
    }
    return p;
}

void libera_nro(Complexo* p){
    free(p);
}

double obter_partes(Complexo *p, int opcao){
    if(opcao==0)    // retorna parte real
        return p->real;
    else            // retorna parte imaginaria
        return p->imaginaria;
}

Complexo* soma(Complexo* c1, Complexo* c2){
    return cria_nro((c1->real + c2->real),(c1->imaginaria + c2->imaginaria));
} //retorna a soma das partes reais e das partes imaginarias

Complexo* sub(Complexo* c1, Complexo* c2){
    return cria_nro((c1->real - c2->real),(c1->imaginaria - c2->imaginaria));
} //retorna a subtracao das partes reais e das partes imaginarias

Complexo* mult(Complexo* c1, Complexo* c2){
    return cria_nro((c1->real*c2->real - c1->imaginaria*c2->imaginaria),(c1->real*c2->imaginaria + c1->imaginaria*c2->real));
} //retorna o produto das partes reais e das partes imaginarias