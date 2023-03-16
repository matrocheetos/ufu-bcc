#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
#define max 20

int main()
{
    int op, FLAG=0;
    deque d;

    do{
        do{
            printf("\n");
            printf("1- Criar um deque\n");
            printf("2- Inserir no inicio\n");
            printf("3- Inserir no final\n");
            printf("4- Remover inicio\n");
            printf("5- Remover final\n");
            printf("6- Imprimir\n");
            printf("7- Liberar deque\n");
            printf("8- Sair\n");

            printf("Digite a operacao\n");
            scanf("%d",&op);

            if(op<1 || op>8)
                printf("Opcao inválida\n");

        }while(op<1 || op>8);

        if(op==8){
            printf("\nFim do progama\n");
            break;
        }
        else if(op!=1 && FLAG==0){
            printf("Antes de qualquer operacao, crie o deque primeiro\n");
            continue;
        }

        if(op==1 && FLAG==1){
            printf("O deque ja foi criado, libere o atual para criar outro\n");
            continue;
        }

    switch(op){
        case 1:{
            d = cria_deque();
            printf("Deque criado\n");
            FLAG++;
            break;
        }
        case 2:{
            int elem;
            printf("Digite o elemento\n");
            scanf("%d",&elem);
            if(insere_ini(d,elem))
                printf("Elemento inserido no inicio\n");
            else
                printf("Deque cheio\n");
            break;
        }
        case 3:{
            int elem;
            printf("Digite o elemento\n");
            scanf("%d",&elem);
            if(insere_fim(d,elem))
                printf("Elemento inserido no final\n");
            else
                printf("Deque cheio\n");
            break;
        }
        case 4:{
            int elem;
            if(remove_ini(d,&elem))
                printf("Inicio removido\n");
            else
                printf("Deque vazio\n");
            break;
        }
        case 5:{
            int elem;
            if(remove_fim(d,&elem))
                printf("Final removido\n");
            else
                printf("Deque vazio\n");
            break;
        }
        case 6:{
            printf("\n");
            int elem;
            int a[max];
            int j=0,i=0;
            while(deque_vazio(d)==0){
                remove_ini(d,&elem);
                printf("%d\n",elem);
                a[i] = elem;
                i++;
            }

            for(j=0;j<i;j++){
                insere_fim(d,a[j]);
            }
            break;
        }
        case 7:{
            libera_deque(d);
            printf("Deque liberado\n");
            FLAG--;
        }
    }

    }while(op!=8);
}
