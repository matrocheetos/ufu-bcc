#include <stdio.h>

void receber_inteiros(int qtd_inteiros, int inteiros[], int *soma, int i){
    printf("inteiro[%d]: ",i);
    scanf("%d",&(*inteiros));
    (*soma)=(*soma)+(*inteiros);
}

void maior_q_media(int qtd_inteiros, int inteiros[], int media, int *maiores_que_a_media){
    if((*inteiros)>media)
        (*maiores_que_a_media)=(*maiores_que_a_media)+1;
}

int main(){
    int qtd_inteiros,maiores_que_a_media=0,media,i,soma=0;
    printf("quantidade de inteiros a serem inseridos: ");
    scanf("%d",&qtd_inteiros);
    if(qtd_inteiros>15 || qtd_inteiros<1){
        printf("quantidade invalida! (maior que 15 ou menor que 1)\n");
        return 0;
    }
    else{
        int inteiros[qtd_inteiros];
        for(i=0;i<qtd_inteiros;i++)
            receber_inteiros(qtd_inteiros,&inteiros[i],&soma,i);
        
        media=soma/qtd_inteiros;

        for(i=0;i<qtd_inteiros;i++)
            maior_q_media(qtd_inteiros,&inteiros[i],media,&maiores_que_a_media);

        printf("%d numeros sao maiores que a media\n",maiores_que_a_media);
    }
    return 0;
}