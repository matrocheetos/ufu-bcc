#include <stdio.h>
#include "lista.h"

int main(){
    Lista *L;
    int y,opcao=0;
    double x;

    printf("[0] Inicializar lista\n[1] Inserir um elemento\n[2] Remover um elemento\n[3] Imprimir lista\n[4] Sair\n");
    while(opcao != 4){
        printf("> ");
        scanf("%i",&opcao);
        switch(opcao){
            case 0: //inicializar lista
                L = cria_lista();
                printf("lista inicializada!\n");
                break;
            case 1: //inserir elemento
                printf("digite o nro real a ser adicionado: ");
                scanf("%lf",&x);
                y = insere_ord(L,x);
                if(y==0)
                    printf("erro!\n");
                else
                    printf("elemento inserido!\n");
                break;
            case 2: //remover elemento
                if(lista_vazia(L)==1){
                    printf("lista ja esta vazia!");
                }else{
                    printf("digite o nro real a ser removido: ");
                    scanf("%lf",&x);
                    y = remove_ord(L,x);
                    if(y==0)
                        printf("erro!\n");
                    else
                        printf("elemento removido!\n");
                }
                break;
            case 3: //imprimir lista
                printf("lista: { ");
                y=1;
                while(obtem_elem(L,y,&x)!=0){
                    printf("%.2lf ",x);
                    y++;
                }
                printf("}\n");
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