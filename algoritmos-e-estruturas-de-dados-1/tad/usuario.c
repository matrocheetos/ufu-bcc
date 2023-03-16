#include <stdio.h>
#include "ex1.h"

int main(){
    int x,y,i;
    double distancia;
    printf("digite a coordenada de dois pontos\n");
    for(i=1;i<=2;i++){
        printf("[%d]: ",i);
        scanf("%d %d",&x,&y);
        cria_pto(x,y,i);
    }
    distancia=distancia_pto();
    printf("\ndistancia entre os pontos: %lf\n",distancia);
    
    libera_pto();
    return 0;
}