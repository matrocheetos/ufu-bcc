#include <stdio.h>
#include "ex2.h"

int main(){
    Lista *L;
    int i, opcao=-1;
    char texto[40];
    char imprimeNome[40]; int imprimeVol; float imprimePreco;

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
                    int volume; float preco;
                    printf("digite as informacoes sobre a bebida\nnome (max 20 caracteres): ");
                    setbuf(stdin,NULL);
                    gets(texto);
                    printf("volume (ml): ");
                    scanf("%d",&volume);
                    printf("preco: ");
                    scanf("%f",&preco);
                    i = insere_ord(L,texto,volume,preco);
                    if(i==1)
                        printf("nome da bebida muito grande! (mais de 20 caracteres)\n");
                }
                break;
            case 2: //remover elemento
                if(lista_vazia(L)==1){
                    printf("lista ja esta vazia!");
                }else{
                    printf("digite o nome da bebida a ser removida: ");
                    setbuf(stdin,NULL);
                    gets(texto);
                    i = remove_ord(L,texto);
                    if(i==1){
                        printf("bebida nao encontrada!\n");
                    }
                }
                break;
            case 3: //imprimir lista
                printf("lista: ");
                for(i=0;i<get_tamanho(L);i++){
                    get_pos(L,i,imprimeNome,&imprimeVol,&imprimePreco);
                    printf("\nBebida[%i]: %s - %d ml - R$%.2f",i+1,imprimeNome,imprimeVol,imprimePreco);
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