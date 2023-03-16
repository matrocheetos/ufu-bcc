#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int op, FLAG=0;
    Deque d;

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
            double elem;
            printf("Digite o elemento\n");
            scanf("%lf",&elem);
            if(insere_ini(&d,elem))
                printf("Elemento inserido no inicio\n");
            else
                printf("Falha na insercao\n");
            break;
        }
        case 3:{
            double elem;
            printf("Digite o elemento\n");
            scanf("%lf",&elem);
            if(insere_fim(&d,elem))
                printf("Elemento inserido no final\n");
            else
                printf("Falha na insercao\n");
            break;
        }
        case 4:{
            double elem;
            if(remove_ini(&d,&elem))
                printf("Inicio removido\n");
            else
                printf("O deque esta vazio\n");
            break;
        }
        case 5:{
            double elem;
            if(remove_fim(&d,&elem))
                printf("Final removido\n");
            else
                printf("O deque esta vazio\n");
            break;
        }
        case 6:{
            printf("\n");
            double elem;
            Deque aux = cria_deque();
            int j=0,i=0;
            while(deque_vazio(d)==0){
                remove_ini(&d,&elem);
                printf("%.2lf\n",elem);
                insere_ini(&aux,elem);
                i++;
            }

            for(j=0;j<i;j++){
                remove_ini(&aux,&elem);
                insere_ini(&d,elem);
            }
            free(aux);
            break;
        }
        case 7:{
            libera_deque(&d);
            printf("Deque liberado\n");
            FLAG--;
        }
    }

    }while(op!=8);
}
