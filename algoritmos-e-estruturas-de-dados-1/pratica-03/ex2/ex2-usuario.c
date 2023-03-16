#include <stdio.h>
#include "ex2.h"

int main(){
    double x,y,z;
    Ponto *P1,*P2;
    printf("digite a coordenada de dois pontos no espaco tridimensional:\n");
    printf("P1: ");
    scanf("%lf %lf %lf",&x,&y,&z);
    P1 = cria_pto(x,y,z);
    printf("P2: ");
    scanf("%lf %lf %lf",&x,&y,&z);
    P2 = cria_pto(x,y,z);

    printf("\ndistancia entre os dois pontos: %lf\n",distancia_pto(P1,P2));

    libera_pto(P1);
    libera_pto(P2);

    return 0;
}