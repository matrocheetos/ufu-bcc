#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define max 20

int main()
{
    int num;
    char op;
    pilha p = cria_pilha();

    do{
        printf("\nDigite o numero decimal a ser convertido\n");
        scanf("%d",&num);
        if(num<0){
            printf("Fim do programa\n");
            break;
        }
        do{
            printf("B - Binario\n");
            printf("O - Octal\n");
            printf("H - Hexadecimal\n");

            printf("Digite a conversao desejada\n");
            setbuf(stdin,NULL);
            scanf("%c",&op);

            if(op!='B' && op!='O' && op!='H' && op!='b' && op!='o' && op!='h')
                printf("Opcao inválida\n");

        }while(op!='B' && op!='O' && op!='H' && op!='b' && op!='o' && op!='h');

        if(op == 'B' || op == 'b'){
            pilha p = cria_pilha();
            int result = num;
            int resto;

            while(result != 0){
                resto = result%2;
                result = result/2;
                push(p,resto);
            }

            int elem;
            while(pilha_vazia(p)!=1){
                ve_topo(p,&elem);
                printf(" %d ", elem);
                pop(p,&elem);
            }
        }
        if(op == 'O' || op == 'o'){
            int result = num;
            int resto;

            while(result != 0){
                resto = result%8;
                result = result/8;
                push(p,resto);
            }

            int elem;
            while(pilha_vazia(p)!=1){
                ve_topo(p,&elem);
                printf(" %d ", elem);
                pop(p,&elem);
            }
        }
        if(op == 'H' || op == 'h'){
            int result = num;
            int resto;

            while(result != 0){
                resto = result%16;
                result = result/16;
                push(p,resto);
            }

            int elem;
            while(pilha_vazia(p)!=1){
                ve_topo(p,&elem);
                if(elem>=0 && elem<=9)
                    printf(" %d ", elem);
                if(elem == 10)
                    printf(" A ");
                if(elem == 11)
                    printf(" B ");
                if(elem == 12)
                    printf(" C ");
                if(elem == 13)
                    printf(" D ");
                if(elem == 14)
                    printf(" E ");
                if(elem == 15)
                    printf(" F ");
                pop(p,&elem);
            }
        }

    }while(num>=0);
return 0;
}
