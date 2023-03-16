#include <stdio.h>
#include "ex2.h"

int main(){
    Lista L;
    int opcao=0,x,y;

    printf("[0] Inicializar lista\n[1] Inserir elemento\n[2] Remover elemento\n[3] Imprimir lista\n[4] Sair\n");
    while (opcao != 4){
        printf("> ");
        scanf("%d",&opcao);
        switch(opcao){
            case 0: //inicializar lista
                L = criar_lista();
                printf("lista inicializada!\n");
                break;
            case 1: //inserir elemento
                printf("digite o inteiro a ser adicionado: ");
                scanf("%d",&x);
                y = insere_elem(L,x);
                if(y==0)
                    printf("erro!\n");
                else
                    printf("elemento adicionado!\n");
                break;
            case 2: //remover elemento
                if(lista_vazia(L)==1){
                    printf("lista ja esta vazia!");
                }else{
                    printf("digite o inteiro a ser removido: ");
                    scanf("%d",&x);
                    y = remove_elem(L,x);
                    if(y==0)
                        printf("elemento nao existe!\n");
                    else
                        printf("elemento removido!\n");
                }
                break;
            case 3: //imprimir lista
                printf("lista: ");
                y=0;
                while(obtem_valor_elem(L,y,&x)!=0){
                    printf("%d ",x);
                    y++;
                }
                printf("\n");
                break;
            case 4: //sair
                printf("encerrando o programa...\n");
                break;
            default:
                printf("opcao invalida!\n");
        }
    }
    return 0;
}