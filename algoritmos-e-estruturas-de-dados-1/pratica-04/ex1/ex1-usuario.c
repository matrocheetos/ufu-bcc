#include <stdio.h>
#include "ex1.h"

int main(){
    Lista *L;
    int i, opcao=-1;
    char texto[40];

    while(opcao != 4){
        printf("[0] Inicializar lista\n[1] Inserir um elemento\n[2] Remover um elemento\n[3] Imprimir lista\n[4] Sair\n> ");
        scanf("%i",&opcao);
        switch(opcao){
            case 0: //inicializar lista
                L = inicializar_lista();
                printf("lista inicializada!\n");
                break;
            case 1: //inserir elemento
                if(lista_cheia(L)==1){
                    printf("lista cheia!\n");
                }else{
                    printf("digite a string a ser adicionada (max 10 caracteres): ");
                    setbuf(stdin,NULL);
                    gets(texto);
                    i = insere_elem(L,texto);
                    if(i==1)
                        printf("string muito grande! (mais de 10 caracteres)\n");
                }
                break;
            case 2: //remover elemento
                if(lista_vazia(L)==1){
                    printf("lista ja esta vazia!");
                }else{
                    printf("digite a string a ser removida: ");
                    setbuf(stdin,NULL);
                    gets(texto);
                    i = remove_elem(L,texto);
                    if(i==1){
                        printf("elemento nao existe!\n");
                    }
                }
                break;
            case 3: //imprimir lista
                printf("lista: ");
                for(i=0;i<20;i++)
                    printf("%s ",get_pos(L,i));
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