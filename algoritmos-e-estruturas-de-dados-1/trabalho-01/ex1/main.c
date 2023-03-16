#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// TAD lista não ordenada estatica/sequencial
//info: nros inteiros
//operacoes: remover impares, retornar menor, retornar tamanho,
//esvaziar lista, inverter lista, concatenar lista

int main()
{
    int op, FLAG=0,elem; // FLAG = qtd de listas criadas
    Lista lst1,lst2;

    do{
        do{
            printf("\n");
            printf("1- Criar uma lista\n");
            printf("2- Inserir\n");
            printf("3- Remover\n");
            printf("4- Imprimir\n");
            printf("5- Menor\n");
            printf("6- Tamanho\n");
            printf("7- Concatenar\n");
            printf("8- Remover impares\n");
            printf("9- Esvaziar\n");
            printf("10- Inverter\n");
            printf("11- Sair\n");

            printf("Digite a operacao\n");
            scanf("%d",&op);

            if(op<1 || op>11)
                printf("Opcao inv�lida\n");

        }while(op<1 || op>11);

        if(op==11){ //sair
            printf("\nFim do progama\n");
            break;
        }
        else if(op!=1 && FLAG<2){ 
            printf("Antes de qualquer operacao, crie as duas listas primeiro");
            continue;
        }

        if(op==1 && FLAG==2){ //restricao max de listas (2)
            printf("Voce so pode criar at� duas listas");
            continue;
        }

    switch(op){
        case 1:{ //criar lista
            if(FLAG==0){
                lst1 = cria_lista();
                printf("Lista 1 criada");
                FLAG++;
                break;
            }
            if(FLAG==1){
                lst2 = cria_lista();
                printf("Lista 2 criada");
                FLAG++;
                break;
            }
        }
        case 2:{ //inserir
            int v;
            printf("4- Selecionar lista\n\n");
            printf("1- Lista 1\n");
            printf("2- Lista 2\n");
            scanf("%d",&v);

            if(v==1){
                printf("Digite o elemento\n");
                scanf("%d",&elem);
                if(insere_elem(lst1,elem))
                    printf("Elemento inserido na lista 1\n");
                else
                    printf("Falha na insercao\n");
            }
            if(v==2){
                printf("Digite o elemento\n");
                scanf("%d",&elem);
                if(insere_elem(lst2,elem))
                    printf("Elemento inserido na lista 2\n");
                else
                    printf("Falha na insercao\n");
            }
            break;
        }
        case 3:{ //remover
            int v;
            printf("4- Selecionar lista\n\n");
            printf("1- Lista 1\n");
            printf("2- Lista 2\n");
            scanf("%d",&v);

            if(v==1){
                printf("Digite o elemento\n");
                scanf("%d",&elem);
                if(remove_elem(lst1,elem))
                    printf("Elemento removido da lista 1\n");
                else
                    printf("Falha na remocao\n");
            }
            if(v==2){
                printf("Digite o elemento\n");
                scanf("%d",&elem);
                if(remove_elem(lst2,elem))
                    printf("Elemento removido da lista 2\n");
                else
                    printf("Falha na insercao\n");
            }
            break;
        }
        case 4:{ //imprimir
            printf("Lista 1\n");
            imprime_lista(lst1);
            printf("Lista 2\n");
            imprime_lista(lst2);
            break;
        }

        case 5:{ //retornar menor valor
            int m1 = menor(lst1);
            int m2 = menor(lst2);

            if(m1==0){
                printf("\nLista 1 esta sem elementos\n");
            }else{
                printf("\nMenor elemento da lista 1: %d\n",m1);
            }
            if(m2==0){
                printf("Lista 2 esta sem elementos\n");
            }else{
                printf("Menor elemento da lista 2: %d\n",m2);
            }
            break;
        }
        case 6:{ //tamanho
            int t1 = tamanho(lst1);
            int t2 = tamanho(lst2);

            printf("Tamanho da lista 1: %d\n",t1);
            printf("Tamanho da lista 2: %d\n",t2);
            break;
        }
        case 7:{ //concatenar
            Lista lst3;
            if(concatenar(lst1,lst2,&lst3)==1){
                printf("\nLista concatenada");
                imprime_lista(lst3);
            }else{
                printf("\nFaha na operacao");
            }
            break;
        }
        case 8:{ //remove impares
            int v;
            printf("4- Selecionar lista\n\n");
            printf("1- Lista 1\n");
            printf("2- Lista 2\n");
            scanf("%d",&v);

            if(v==1){
                if(remove_impar(lst1)==0)
                    printf("Nao ha numeros impares na lista 1 para serem removidos\n");
                else
                    printf("Impares removidos da lista 1\n");
            }
            if(v==2){
                if(remove_impar(lst2)==0)
                    printf("Nao ha numeros impares na lista 2 para serem removidos\n");
                else
                    printf("Impares removido da lista 2\n");
            }
            break;
        }
        case 9:{ //esvaziar
            int v;
            printf("4- Selecionar lista\n\n");
            printf("1- Lista 1\n");
            printf("2- Lista 2\n");
            scanf("%d",&v);

            if(v==1){
                if(esvaziar(lst1))
                    printf("lista 1 esvaziada\n");
                else
                    printf("Lista 1 ja esta vazia\n");
            }
            if(v==2){
                if(esvaziar(lst2))
                    printf("lista 2 esvaziada\n");
                else
                    printf("Lista 2 ja esta vazia\n");
            }
            break;
        }
        case 10:{ //inverter
            int v;
            Lista lst3;
            lst3 = cria_lista();
            printf("4- Selecionar lista\n\n");
            printf("1- Lista 1\n");
            printf("2- Lista 2\n");
            scanf("%d",&v);

            if(v==1){

                inverter(lst1,lst3);
                printf("\nLista 1 invertida:\n");
                imprime_lista(lst3);
            }
            if(v==2){
                inverter(lst2,lst3);
                printf("\nLista 2 invertida:\n");
                imprime_lista(lst3);
            }
        }
    }

    }while(op!=11);
}
