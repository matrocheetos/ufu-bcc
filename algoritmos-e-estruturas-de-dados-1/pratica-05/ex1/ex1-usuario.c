#include <stdio.h>
#include "ex1.h"

int main(){
    Lista *L;
    int opcao=0,x,y;

    printf("[0] Inicializar lista\n[1] Inserir um elemento\n[2] Remover um elemento (1a ocorrencia)\n[3] Remover um elemento (por posicao)\n[4] Imprimir lista\n[5] Sair\n");
    while (opcao != 5){
        printf("> ");
        scanf("%i",&opcao);
        switch(opcao){
            case 0: //inicializar lista
                L = inicializar_lista();
                printf("lista inicializada!\n");
                break;
            case 1: //inserir elemento
                printf("digite o inteiro a ser adicionado: ");
                scanf("%d",&x);
                y = insere_ord(L,x);
                if(y==0)
                    printf("erro!\n");
                else
                    printf("elemento adicionado!\n");
                break;
            case 2: //remover elemento por ocorrencia
                if(lista_vazia(L)==1){
                    printf("lista ja esta vazia!");
                }else{
                    printf("digite o inteiro a ser removido: ");
                    scanf("%d",&x);
                    y = remove_ord(L,x,0);
                    if(y==0)
                        printf("elemento nao existe!\n");
                    else
                        printf("elemento removido!\n");
                }
                break;
            case 3: //remover elemento por posicao
                if(lista_vazia(L)==1){
                    printf("lista ja esta vazia!");
                }else{
                    printf("digite a posicao do inteiro a ser removido (comecando em zero): ");
                    scanf("%d",&x);
                    if(x<0){
                        printf("posicao invalida!\n");
                        break;
                    }
                    y = remove_ord(L,x,1);
                    if(y==0)
                        printf("elemento nao existe!\n");
                    else
                        printf("elemento removido!\n");
                }
                break;
            case 4: //imprimir lista
                printf("lista: ");
                y=0;
                while(get_pos(L,y,&x)!=0){
                    printf("%d ",x);
                    y++;
                }
                printf("\n");
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