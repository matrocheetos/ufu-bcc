#include <stdio.h>

int funcao(int x, int y){
    y=y-1;
    int i,resultado=x;
    for(i=0;i<y;i++)
        resultado=resultado*x;
    return resultado;
}

int main(){
    int x,y,resultado;

    printf("forneca a base e o expoente: ");
    scanf("%d %d",&x,&y);

    resultado=funcao(x,y);
    printf("resultado: %d\n",resultado);

    return 0;
}