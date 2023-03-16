#include <stdio.h>
#include <stdlib.h>

int main(){
    int **p,x,i,j;
    printf("dimensoes da matriz[x][x]: ");
    scanf("%d",&x);
    if(x<1){
        printf("dimensoes muito pequenas!\n");
        exit(1);
    }

    p=(int **) malloc(x*sizeof(int *));
    for(i=0;i<x;i++){
        p[i]=(int *) malloc(x*sizeof(int));
        for(j=0;j<x;j++){
            printf("matriz[%d][%d]: ",i,j);
            scanf("%d",&p[i][j]);
        }
    }
    printf("\n");
    for(i=0;i<x;i++){
        for(j=0;j<x;j++){
            if(i<=j)
                printf("%d\t",p[i][j]);
            else
                printf("\t");
        }
        printf("\n");
    }


    for(i=0;i<x;i++)
        free(p[i]);
    free(p);
    return 0;
}