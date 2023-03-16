#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ex3.h"

struct ponto{
    double x,y,z;
};

struct esfera{
    struct ponto pto_raio[2];
};

Esfera* cria_esfera(double x1, double y1, double z1, double x2, double y2, double z2){
    Esfera* e = (Esfera*) malloc(sizeof(Esfera));
    if(e != NULL){
        e->pto_raio[0].x = x1;
        e->pto_raio[0].y = y1;
        e->pto_raio[0].z = z1;
        e->pto_raio[1].x = x2;
        e->pto_raio[1].y = y2;
        e->pto_raio[1].z = z2;
    }
    return e;
}

void libera_esfera(Esfera *e){
    free(e);
}

double raio(Esfera* e){
    double dist_x = e->pto_raio[0].x - e->pto_raio[1].x;
    double dist_y = e->pto_raio[0].y - e->pto_raio[1].y;
    double dist_z = e->pto_raio[0].z - e->pto_raio[1].z;
    return sqrt(dist_x*dist_x + dist_y*dist_y + dist_z*dist_z);
}

double area(Esfera* e){
    //sendo pi = 3,14159
    return (4 * 3.14159 * (raio(e)*raio(e)));
}

double volume(Esfera *e){
    return (area(e)*raio(e)/3);
}