#include <stdio.h>
#include "fila.h"

int main(){
    Fila *F;
    int opcao=0,y,lista_inicializada=0;
    struct bebida bebida;

    printf("[0] Inicializar fila\n[1] Inserir um elemento\n[2] Remover um elemento (do fim da fila)\n[3] Imprimir fila\n[4] Esvaziar fila\n[5] Apagar fila\n[6] Sair\n");
    while (opcao != 6){
        printf("> ");
        scanf("%i",&opcao);
        switch(opcao){
            case 0: //inicializar fila
                if(lista_inicializada == 0){
                    F = criar_fila();
                    printf("fila inicializada!\n");
                    lista_inicializada = 1;
                }else{
                    printf("fila ja foi inicializada!\n");
                }
                break;
            case 1: //inserir elemento
                printf("digite os dados da bebida:\n");
                printf("nome: ");
                setbuf(stdin,NULL);
                gets(bebida.nome);
                printf("volume (em ml): ");
                scanf("%d",&bebida.volume);
                printf("preco: ");
                scanf("%f",&bebida.preco);
                y = insere_fim(F,bebida);
                if(y==0)
                    printf("erro!\n");
                else
                    printf("elemento adicionado!\n");
                break;
            case 2: //remover elemento do fim da fila
                if(fila_vazia(F)==1){
                    printf("fila ja esta vazia!");
                }else{
                    y = remove_ini(F);
                    if(y==0)
                        printf("erro!\n");
                    else
                        printf("elemento removido!\n");
                }
                break;
            case 3: //imprimir fila
                imprime_fila(F);
                break;
            case 4: //esvaziar fila
                esvazia_fila(F);
                printf("fila esvaziada!\n");
                break;
            case 5: //apagar fila
                apaga_fila(F);
                lista_inicializada = 0;
                printf("fila apagada!\n");
                break;
            case 6: //sair
                printf("encerrando o programa...\n");
                break;
            default:
                printf("opcao invalida!\n");
        }
    }
    return 0;
}