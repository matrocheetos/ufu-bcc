#include <stdio.h>
#include "ex1.h"

int main(){
    Lista *L;

    int opcao=0,i;
    char a;
    while (opcao != 5){
        printf("[0] Inicializar lista\n[1] Inserir um elemento\n[2] Remover um elemento\n[3] Imprimir lista\n[4] Limpar a lista\n[5] Sair\n> ");
        scanf("%i",&opcao);
        switch(opcao){
            case 0:
                L = criar_lista();
                break;
            case 1: //inserir elemento
                printf("digite o elemento do tipo 'char' a ser adicionado: ");
                scanf(" %c",&a);
                int x = insere_elem(L,a);
                break;
            case 2: //remover elemento
                if(lista_vazia(L)==1){
                    printf("lista ja esta vazia!");
                }else{
                    printf("digite o elemento do tipo 'char' a ser removido: ");
                    scanf(" %c",&a);
                    i = remove_elem(L,a);
                    if(i==0){
                        printf("elemento nao existe!\n");
                    }
                }
                break;
            case 3: //imprimir lista
                printf("lista: ");
                a=32; i=1;
                while(a!=0){
                    a = obtem_posicao(L,i);
                    printf("%c ",a);
                    i++;
                }
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