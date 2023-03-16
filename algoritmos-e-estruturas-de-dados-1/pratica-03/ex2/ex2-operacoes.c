#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ex2.h"

struct ponto{
    double x,y,z;
};

Ponto* cria_pto(double x, double y, double z){
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if(p != NULL){
        p->x = x;
        p->y = y;
        p->z = z;
    }
    return p;
}

void libera_pto(Ponto *p){
    free(p);
}

double distancia_pto(Ponto* p1, Ponto* p2){
    double dist_x = p1->x - p2->x;
    double dist_y = p1->y - p2->y;
    double dist_z = p1->z - p2->z;
    return sqrt(dist_x*dist_x + dist_y*dist_y + dist_z*dist_z);
}