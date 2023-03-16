#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    Fila f1 = cria_fila();
    Fila f2 = cria_fila();
    Fila f3 = cria_fila();
    Fila f4 = cria_fila();
    Fila f5 = cria_fila();

    Fila faux = cria_fila();

    int placa;
    int opcao;

    while(1){
        printf(" 1 - Insere veiculo\n");
        printf(" 2 - Remove veiculo\n");
        printf(" 3 - Visualizar cenario\n");
        printf(" 4 - Sair\n");
        printf(">> ");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Insira o numero da placa\n");
            scanf("%d",&placa);
                int tam1 = tamanho(f1);
                int tam2 = tamanho(f2);
                int tam3 = tamanho(f3);
                int tam4 = tamanho(f4);
                int tam5 = tamanho(f5);
                int tamaux = tamanho(faux);

                if(tamaux == 10){
                    printf("Estacionamento cheio!\n");
                }

                else if(tam1 == 10 && tam2 == 10 && tam3 == 10 && tam4 == 10 && tam5 == 10){
                    insere_fim(faux, placa);
                    printf("Carro inserido na fila de espera\n");
                }

                else if(tam1 == tam2 && tam2 == tam3 && tam3 == tam4 && tam4 == tam5){
                    insere_fim(f1, placa);
                    printf("Carro inserido no estacionamento\n");

                }else if(tam1 <= tam2 && tam1 <= tam3 && tam1 <= tam4 && tam1 <= tam5){
                    insere_fim(f1, placa);
                    printf("Carro inserido no estacionamento\n");
                }
                else if(tam2 < tam1 && tam2 <= tam3 && tam2 <= tam4 && tam2 <= tam5){
                    insere_fim(f2, placa);
                    printf("Carro inserido no estacionamento\n");
                }
                else if(tam3 < tam1 && tam3 < tam2 && tam3 <= tam4 && tam3 <= tam5){
                    insere_fim(f3, placa);
                    printf("Carro inserido no estacionamento\n");
                }
                else if(tam4 < tam1 && tam4 < tam2 && tam4 < tam3 && tam4 <= tam5){
                    insere_fim(f4, placa);
                    printf("Carro inserido no estacionamento\n");
                }
                else if(tam5 < tam1 && tam5 < tam2 && tam5 < tam3 && tam5 < tam4){
                    insere_fim(f5, placa);
                    printf("Carro inserido no estacionamento\n");
                }
        }

        if(opcao == 2){
            printf("Insira o numero da placa\n");
            scanf("%d", &placa);
            int i;

            int b1 = tamanho(f1);
            int b2 = tamanho(f2);
            int b3 = tamanho(f3);
            int b4 = tamanho(f4);
            int b5 = tamanho(f5);
            int v = 0;

            int varRemovida;
            for(i = 0; i < b1; i++){
                remove_ini(f1, &varRemovida);
                if(placa == varRemovida){
                    printf("\nCarro removido\n");
                    v = 1;
                }else{
                    insere_fim(f1, varRemovida);
                }
            }
            if(v==0){
            for(i = 0; i < b2; i++){
                remove_ini(f2, &varRemovida);
                if(placa == varRemovida){
                    printf("\nCarro removido\n");
                    v = 1;
                }else{
                    insere_fim(f2, varRemovida);
                }
            }
            for(i = 0; i < b3; i++){
                remove_ini(f3, &varRemovida);
                if(placa == varRemovida){
                    printf("\nCarro removido\n");
                    v = 1;
                }else{
                    insere_fim(f3, varRemovida);
                }
            }
            }
            if(v==0){
            for(i = 0; i < b4; i++){
                remove_ini(f4, &varRemovida);
                if(placa == varRemovida){
                    printf("\nCarro removido\n");
                    v = 1;
                }else{
                    insere_fim(f4, varRemovida);
                }
            }
            }
            if(v==0){
            for(i = 0; i < b5; i++){
                remove_ini(f5, &varRemovida);
                if(placa == varRemovida){
                    printf("\nCarro removido\n");
                    v = 1;
                }else{
                    insere_fim(f5, varRemovida);
                }
            }
            }
            int elem;
            if(fila_vazia(faux)==0){

            b1 = tamanho(f1);
            b2 = tamanho(f2);
            b3 = tamanho(f3);
            b4 = tamanho(f4);
            b5 = tamanho(f5);

                if(b1<=b2 && b1<=b3 && b1<=b4 && b1<=b5){
                    remove_ini(faux,&elem);
                    insere_fim(f1,elem);
                }
                if(b2<b1 && b2<=b3 && b2<=b4 && b2<=b5){
                    remove_ini(faux,&elem);
                    insere_fim(f2,elem);
                }
                if(b3<b1 && b3<b2 && b3<=b4 && b3<=b5){
                    remove_ini(faux,&elem);
                    insere_fim(f3,elem);
                }
                if(b4<b1 && b4<b2 && b4<b3 && b4<=b5){
                    remove_ini(faux,&elem);
                    insere_fim(f4,elem);
                }
                if(b5<b1 && b5<b2 && b5<b3 && b5<b4){
                    remove_ini(faux,&elem);
                    insere_fim(f5,elem);
                }
            }
            if(v==0){
                printf("\nCarro nao encontrado\n");
            }
        }

        if(opcao == 3){
            Fila aux2 = cria_fila();
            int elem;
            printf("BOX 1: \n");
            if(fila_vazia(f1)==1){
                printf("Vazio");
            }
            int i=1;
            while(fila_vazia(f1)==0){
                remove_ini(f1,&elem);
                printf("%d- %d\n",i,elem);
                insere_fim(aux2,elem);
                i++;
            }
            while(fila_vazia(aux2)==0){
                remove_ini(aux2,&elem);
                insere_fim(f1,elem);
            }

            printf("\nBOX 2: \n");
            if(fila_vazia(f2)==1){
                printf("Vazio");
            }
            i=1;
            while(fila_vazia(f2)==0){
                remove_ini(f2,&elem);
                printf("%d- %d\n",i,elem);
                insere_fim(aux2,elem);
                i++;
            }

            while(fila_vazia(aux2)==0){
                remove_ini(aux2,&elem);
                insere_fim(f2,elem);
            }

            printf("\nBOX 3: \n");
            if(fila_vazia(f3)==1){
                printf("Vazio");
            }
            i=1;
            while(fila_vazia(f3)==0){
                remove_ini(f3,&elem);
                printf("%d- %d\n",i,elem);
                insere_fim(aux2,elem);
                i++;
            }
            while(fila_vazia(aux2)==0){
                remove_ini(aux2,&elem);
                insere_fim(f3,elem);
            }

            printf("\nBOX 4: \n");
            if(fila_vazia(f4)==1){
                printf("Vazio");
            }
            i=1;
            while(fila_vazia(f4)==0){
                remove_ini(f4,&elem);
                printf("%d- %d\n",i,elem);
                insere_fim(aux2,elem);
                i++;
            }
            while(fila_vazia(aux2)==0){
                remove_ini(aux2,&elem);
                insere_fim(f4,elem);
            }

            printf("\nBOX 5: \n");
            if(fila_vazia(f5)==1){
                printf("Vazio");
            }
            i=1;
            while(fila_vazia(f5)==0){
                remove_ini(f5,&elem);
                printf("%d- %d\n",i,elem);
                insere_fim(aux2,elem);
                i++;
            }
            while(fila_vazia(aux2)==0){
                remove_ini(aux2,&elem);
                insere_fim(f5,elem);
            }

            printf("\nFILA DE ESPERA: \n");
            if(fila_vazia(faux)==1){
                printf("Vazio");
            }
            i=1;
            while(fila_vazia(faux)==0){
                remove_ini(faux,&elem);
                printf("%d- %d\n",i,elem);
                insere_fim(aux2,elem);
                i++;
            }
            while(fila_vazia(aux2)==0){
                remove_ini(aux2,&elem);
                insere_fim(faux,elem);
            }
            printf("\n");
            free(aux2);
        }
        if(opcao == 4){
            return 0;
        }
    }
}
