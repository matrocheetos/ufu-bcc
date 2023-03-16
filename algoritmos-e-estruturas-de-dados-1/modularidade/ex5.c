#include <stdio.h>

void ordenar(int vetor1[],int vetor2[]){
    if(*vetor1<*vetor2){
        int temp=*vetor1;
        *vetor1=*vetor2;
        *vetor2=temp;
    }
}

int main(){
    int tamanho_vetor;
    printf("criar um vetor de quantas posicoes? ");
    scanf("%d",&tamanho_vetor);
    if(tamanho_vetor>30 || tamanho_vetor<1){
        printf("tamanho invalido! (maior que 30 ou menor que 1)\n");
        return 0;
    }

    int vetor[tamanho_vetor],i,j;
    for(i=0;i<tamanho_vetor;i++){
        printf("vetor[%d]: ",i);
        scanf("%d",&vetor[i]);
        if(i>0){
            for(j=i;j>0;j--){
                ordenar(&vetor[j],&vetor[j-1]);
            }
        }
    }

    printf("\nvetor em ordem crescente: ");
    for(i=0;i<tamanho_vetor;i++)
        printf("%d ",vetor[i]);

    printf("\n");
    return 0;
}