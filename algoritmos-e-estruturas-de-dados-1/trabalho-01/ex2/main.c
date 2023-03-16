#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//TAD lista ordenada estatica/sequencial
//info: nros inteiros
//parecida com o exercicio 1
//interface do usuario igual, mas agora remove pares, retorna o maior, intercala listas e não inverte

int main()
{
    int op, FLAG=0,elem;
    lista lst1,lst2;

    do{
        do{
            printf("\n");
            printf("1- Criar uma lista\n");
            printf("2- Inserir\n");
            printf("3- Remover\n");
            printf("4- Imprimir\n");
            printf("5- Maior\n");
            printf("6- Tamanho\n");
            printf("7- Intercalar\n");
            printf("8- Remover pares\n");
            printf("9- Esvaziar\n");
            printf("10- Sair\n");

            printf("Digite a operacao\n");
            scanf("%d",&op);

            if(op<1 || op>10)
                printf("Opcao inv�lida\n");

        }while(op<1 || op>10);

        if(op==10){
            printf("\nFim do progama\n");
            break;
        }
        else if(op!=1 && FLAG<2){
            printf("Antes de qualquer operacao, crie as duas listas primeiro");
            continue;
        }

        if(op==1 && FLAG==2){
            printf("Voce so pode criar ate duas listas");
            continue;
        }

    switch(op){
        case 1:{
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
        case 2:{
            int v;
            printf("Selecionar lista\n\n");
            printf("1- Lista 1\n");
            printf("2- Lista 2\n");
            scanf("%d",&v);

            if(v==1){
                printf("Digite o elemento\n");
                scanf("%d",&elem);
                if(insere_ord(lst1,elem))
                    printf("Elemento inserido na lista 1\n");
                else
                    printf("Falha na insercao\n");
            }
            if(v==2){
                printf("Digite o elemento\n");
                scanf("%d",&elem);
                if(insere_ord(lst2,elem))
                    printf("Elemento inserido na lista 2\n");
                else
                    printf("Falha na insercao\n");
            }
            break;
        }
        case 3:{
            int v;
            printf("4- Selecionar lista\n\n");
            printf("1- Lista 1\n");
            printf("2- Lista 2\n");
            scanf("%d",&v);

            if(v==1){
                printf("Digite o elemento\n");
                scanf("%d",&elem);
                if(remove_ord(lst1,elem))
                    printf("Elemento removido da lista 1\n");
                else
                    printf("Falha na remocao\n");
            }
            if(v==2){
                printf("Digite o elemento\n");
                scanf("%d",&elem);
                if(remove_ord(lst2,elem))
                    printf("Elemento removido da lista 2\n");
                else
                    printf("Falha na insercao\n");
            }
            break;
        }
        case 4:{
            printf("Lista 1\n");
            imprime_lista(lst1);

            printf("Lista 2\n");
            imprime_lista(lst2);
            break;
        }

        case 5:{
            int m1 = maior(lst1);
            int m2 = maior(lst2);

            if(m1==0){
                printf("\nLista 1 esta sem elementos\n");
            }else{
                printf("\nMaior elemento da lista 1: %d\n",m1);
            }
            if(m2==0){
                printf("Lista 2 esta sem elementos\n");
            }else{
                printf("Maior elemento da lista 2: %d\n",m2);
            }
            break;
        }
        case 6:{
            int t1 = tamanho(lst1);
            int t2 = tamanho(lst2);

            printf("Tamanho da lista 1: %d\n",t1);
            printf("Tamanho da lista 2: %d\n",t2);
            break;
        }
        case 7:{
            lista lst3;
            lst3 = cria_lista();
            if(intercala(lst1,lst2,lst3)==1){
                printf("\nLista intercalada:\n");
                imprime_lista(lst3);
            }else{
                printf("\nFalha na operacao:\n");
            }
            break;
        }
        case 8:{
            int v;
            printf("4- Selecionar lista\n\n");
            printf("1- Lista 1\n");
            printf("2- Lista 2\n");
            scanf("%d",&v);

            if(v==1){
                if(remove_pares(lst1)==0)
                    printf("Nao ha numeros pares na lista 1\n");
                else
                    printf("pares removidos da lista 1\n");
            }
            if(v==2){
                if(remove_pares(lst2)==0)
                    printf("Nao ha numeros pares na lista 2\n");
                else
                    printf("pares removidos da lista 2\n");
            }
            break;
        }
        case 9:{
            int v;
            printf("4- Selecionar lista\n\n");
            printf("1- Lista 1\n");
            printf("2- Lista 2\n");
            scanf("%d",&v);

            if(v==1){
                if(esvaziar(lst1))
                    printf("lista 1 esvaziada\n");
                else
                    printf("lista 1 ja esta vazia\n");
            }
            if(v==2){
                if(esvaziar(lst2))
                    printf("lista 2 esvaziada\n");
                else
                    printf("lista 2 ja esta vazia\n");
            }
        }
    }

    }while(op!=10);
}
