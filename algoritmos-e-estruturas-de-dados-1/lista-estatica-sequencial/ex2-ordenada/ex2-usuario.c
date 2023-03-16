#include <stdio.h>
#include "ex2.h"

int main(){
    Lista *L;
    L = criar_lista();

    int opcao=0,i;
    float x;
    while (opcao != 5){
        printf("[1] Inserir um elemento\n[2] Remover um elemento\n[3] Imprimir lista\n[4] Limpar a lista\n[5] Sair\n> ");
        scanf("%i",&opcao);
        switch(opcao){
            case 1: //inserir elemento
                if(lista_cheia(L)==1){
                    printf("lista cheia!\n");
                }else{
                    printf("digite o numero a ser adicionado: ");
                    scanf("%f",&x);
                    insere_elem(L,x);
                }
                break;
            case 2: //remover elemento
                if(lista_vazia(L)==1){
                    printf("lista ja esta vazia!");
                }else{
                    printf("digite o numero a ser removido: ");
                    scanf("%f",&x);
                    i = remove_elem(L,x);
                    if(i==1){
                        printf("elemento nao existe!\n");
                    }
                }
                break;
            case 3: //imprimir lista
                printf("lista: ");
                for(i=0;i<20;i++)
                    printf("%.2f ",get_posicao(L,i));
                printf("\n");
                break;
            case 4: //limpar lista
                limpa_lista(L);
                break;
            case 5: //sair
                printf("encerrando o programa...\n");
                break;
            default:
                printf("opcao invalida!\n");
        }
    }
    return 0;
}