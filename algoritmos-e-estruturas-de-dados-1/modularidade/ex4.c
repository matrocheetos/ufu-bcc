#include <stdio.h>

int fatorial(int x){
    int fat;
    if(x<=1)
        return 1;
    else{
        fat=x*fatorial(x-1);
        return fat;
    }
}

int combinacao(int fatX, int fatY, int fatXY){
    return fatX/(fatY*fatXY);
}

int main(){
    int M,P,fatM,fatP,fatMP,comb;

    printf("digite dois numeros inteiros: ");
    scanf("%d %d",&M,&P);
    if(P>M){
        printf("o segundo inteiro nao pode ser maior que o primeiro!\n");
        return 0;
    }

    fatM=fatorial(M);
    fatP=fatorial(P);
    fatMP=fatorial(M-P);

    comb=combinacao(fatM,fatP,fatMP);
    printf("combinacao = %d\n",comb);

    return 0;
}