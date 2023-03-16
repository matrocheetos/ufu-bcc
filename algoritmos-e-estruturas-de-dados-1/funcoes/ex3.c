#include <stdio.h>
#include <math.h>

int funcao(int x){
    int y = sqrt(x);
    if((y*y)==x)
        return 1;
    else
        return 0;
}

int main(){
    int x;
    printf("digite um numero inteiro positivo: ");
    scanf("%d",&x);
    int verificacao = funcao(x);
    if(verificacao==1)
        printf("eh quadrado perfeito\n");
    else
        printf("nao eh quadrado perfeito\n");

    return 0;
}