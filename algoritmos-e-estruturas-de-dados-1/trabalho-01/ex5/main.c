#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//TAD lista não ordenada, dinamica com ENCADEAMENTO CICLICO
//CICLICO: ultimo aponta pro primeiro
//info: numeros reais
//operacoes inserir no inicio, inserir na posicao definida
//remover da posicao, tamanho e retornar maior elem

int main(){

    Lista lst = criaLista();
    int escolha,result,pos;
    double elem;

    while(1){
        do{
            printf("\nEscolha uma op%c%co de 1 %c 9\n",135,198,133);
            printf("1_Inserir no final da lista.\n");
            printf("2_Inserir no inicio da lista.\n");
            printf("3_Inserir em uma posi%c%co determinada da lista.\n", 135,198);
            printf("4_Remover do inicio da lista.\n");
            printf("5_Remover de uma posi%c%co determinada da lista.\n", 135,198);
            printf("6_Verificar tamanho da lista.\n");
            printf("7_Verificar o maior elemento da lista.\n");
            printf("8_Imprimir a lista.\n");
            printf("9_Sair.\n");
            printf("Escolha: ");
            scanf("%d", &escolha);
        }while(escolha < 0 || escolha > 9);


        switch(escolha){

        case 1: printf("Elemento que deseja inserir: ");
                scanf("%lf", &elem);
                result = insereFinal(&lst,elem);
                if(result != 1)
                    printf("Inser%c%co falhou.\n",135,198);
                else
                    printf("Inser%c%co feita com sucesso.\n", 135,198);
               break;

        case 2:printf("Elemento que deseja inserir: ");
                scanf("%lf", &elem);
                result = insereInicio(&lst,elem);
                if(result != 1)
                    printf("Inser%c%co falhou.\n",135,198);
                else
                    printf("Inser%c%co feita com sucesso.\n", 135,198);
               break;

        case 3: printf("Elemento que deseja inserir: ");
                scanf("%lf", &elem);
                printf("Posicao que deseja inserir: ");
                scanf("%d", &pos);
                result = inserePos(&lst,pos,elem);
                if(result == 0)
                    printf("Voce so pode inserir elementos entre o primeiro e o ultimo.\n");
                else
                    printf("Inser%c%co feita com sucesso.\n", 135,198);
               break;

        case 4: result = removeInicio(&lst, &elem);
                if(result == 1)
                    printf("Elemento removido: %lf.\n", elem);
                else
                    printf("Erro: nada foi removido.\n");
                break;

        case 5: printf("Posi%c%co que deseja remover: ", 135,198);
                scanf("%d", &pos);
                result = removePos(&lst,pos);
                if(result == 1)
                    printf("Elemento removido com sucesso.\n");
                else
                    printf("Voce so pode remover elementos entre o primeiro e o ultimo.\n");
                break;

        case 6: printf("O tamanho da lista %c: %d.\n", 130,tamanho(lst));
                break;

        case 7: if(listaVazia(lst) != 1)
                    printf("O maior elemento da lista %c: %lf.\n",130,maior(lst));
                else
                    printf("A lista est%c vazia.\n",160);
                break;

        case 8: imprimeLista(lst);
                break;

        case 9: return 0;

        }
    }
}
