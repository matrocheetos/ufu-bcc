#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p, i, soma_impar=0;
    p=(int *) malloc(5*sizeof(int));
    if(p==NULL){
        printf("memoria insuficiente!\n");
        exit(1);
    }
    for(i=0;i<5;i++){
        printf("vetor[%d]: ",i);
        scanf("%d",&p[i]);
        if(p[i]%2!=0)
            soma_impar=soma_impar+p[i];
    }
    printf("inteiros no vetor: ");
    for(i=0;i<5;i++)
        printf("%d ",p[i]);
    printf("\nsoma dos impares: %d\n",soma_impar);

    free(p);
    return 0;
}