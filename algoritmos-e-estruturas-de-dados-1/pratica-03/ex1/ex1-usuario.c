#include <stdio.h>
#include "ex1.h"

int main(){
    int i,x,y;
    Complexo *C1, *C2, *C3;
    printf("digite 3 numeros complexos (parte real e imaginaria):\n");
    printf("C1: ");
    scanf("%i %i",&x,&y);
    C1 = cria_nro(x,y);
    printf("C2: ");
    scanf("%i %i",&x,&y);
    C2 = cria_nro(x,y);
    printf("C3: ");
    scanf("%i %i",&x,&y);
    C3 = cria_nro(x,y);

    // (C1 - C3) * C2
    Complexo *operacao = mult(sub(C1,C3),C2);

    printf("resultado %lf + (%lf*i)\n",obter_partes(operacao,0),obter_partes(operacao,1));

    libera_nro(C1);
    libera_nro(C2);
    libera_nro(C3);

    return 0;
}