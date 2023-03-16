#include <stdio.h>
#include "ex3.h"

//ler pontos que determinam raio da esfera
int main(){
    double x1,y1,z1,x2,y2,z2;
    Esfera *E;
    printf("digite as coordenadas do raio da esfera no espaco tridimensional:\n");
    printf("P1: ");
    scanf("%lf %lf %lf",&x1,&y1,&z1);
    printf("P2: ");
    scanf("%lf %lf %lf",&x2,&y2,&z2);
    E = cria_esfera(x1,y1,z1,x2,y2,z2);

    printf("\nraio: %lf\narea: %lf\nvolume: %lf\n",raio(E),area(E),volume(E));

    libera_esfera(E);

    return 0;
}