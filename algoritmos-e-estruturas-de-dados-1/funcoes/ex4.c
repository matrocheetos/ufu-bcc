#include <stdio.h>

int funcao(int*x, int*y, int i){
    int produto=x[i]*y[i];
    return produto;
}

int main(){
    int x[10],y[10],produto[10],i;
    
    printf("digite 10 numeros p vetor x: ");
    for(i=0;i<10;i++)
        scanf("%d",&x[i]);

    printf("digite 10 numeros p vetor y: ");
    for(i=0;i<10;i++)
        scanf("%d",&y[i]);

    printf("produtos:\n");
    for(i=0;i<10;i++){
        produto[i]=funcao(x,y,i);
        printf("%d\n",produto[i]);
    }

    return 0;
}