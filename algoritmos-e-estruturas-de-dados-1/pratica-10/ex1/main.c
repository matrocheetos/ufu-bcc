#include <stdio.h>
#include "lista.h"

int main(){
    Lista *L;
    Union x;
    int opcao=0,tipo,y;

    printf("[0] Criar lista\n[1] Inserir um elemento\n[2] Remover um elemento\n[3] Imprimir lista\n[4] Sair\n");
    while (opcao != 4){
        printf("> ");
        scanf("%i",&opcao);
        switch(opcao){
            case 0: //criar lista
                printf("digite o tipo da lista de notas ('0' p/ nro real, '1' p/ conceito): ");
                scanf("%d",&tipo);
                if(tipo == 0 || tipo == 1){
                    L = criar_lista(tipo);
                    printf("lista criada!\n");
                }else
                    printf("tipo invalido!\n");
                break;
            case 1: //inserir elemento
                if(lista_cheia(L)==1){
                    printf("lista cheia!\n");
                }else{
                    printf("digite a nota a ser adicionada ");
                    if(tipo == 0){
                        printf("(nro real): ");
                        scanf("%f",&x.i_float);
                    }else if(tipo == 1){
                        printf("(A, B, C ou D): ");
                        setbuf(stdin,NULL);
                        scanf("%c",&x.i_char);
                    }
                    y = insere_elem(L,x);
                    if(y == 1)
                        printf("nota inserida!\n");
                    else
                        printf("erro!\n");
                }
                break;
            case 2: //remover elemento
                if(lista_vazia(L)==1){
                    printf("lista ja esta vazia!");
                }else{
                    printf("digite a nota a ser removida: ");
                    if(tipo == 0)
                        scanf("%f",&x.i_float);
                    else if(tipo == 1){
                        setbuf(stdin,NULL);
                        scanf("%c",&x.i_char);
                    }
                    y = remove_elem(L,x);
                    if(y == 1)
                        printf("nota removida!\n");
                    else
                        printf("nota nao encontrada!\n");
                }
                break;
            case 3: //imprimir lista
                printf("notas: ");
                y=0;
                while(obtem_elem_pos(L,y,&x) != 0){
                    if(tipo == 0)
                        printf("%.2f ",x.i_float);
                    else if(tipo == 1)
                        printf("%c ",x.i_char);
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