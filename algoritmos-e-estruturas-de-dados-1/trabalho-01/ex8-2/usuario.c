//ex8
#include <stdio.h>
#include "lista.h"

int main(){
    Lista *L;
    int x,opcao=0,lista_criada=0;
    int a,k;

    printf("[0] Inicializar lista\n[1] Inserir um elemento\n[2] Remover um elemento\n[3] Imprimir lista\n[4] Calcular P(x)\n[5] Sair\n");
    while(opcao != 5){
        printf("> ");
        scanf("%i",&opcao);
        switch(opcao){
            case 0: //inicializar lista
                if(lista_criada==0){
                    L = cria_lista();
                    lista_criada=1;
                    printf("lista inicializada!\n");
                }else{
                    printf("lista já foi inicializada!\n");
                }
                break;
            case 1: //inserir elemento
                printf("digite os inteiros 'a' e 'k' (a*x^k) a serem adicionados ao polinomio:\n");
                printf("a: ");
                scanf("%d",&a);
                printf("k: ");
                scanf("%d",&k);
                x = insere_ord(L,a,k);

                if(x==1)
                    printf("elemento inserido!\n");
                else if(x==-1)
                    printf("'a' não pode ser igual a zero!\n");
                else if(x==0)
                    printf("erro!\n");

                break;
            case 2: //remover elemento
                if(lista_vazia(L)==1){
                    printf("lista ja esta vazia!");
                }else{
                    printf("digite o elemento 'k' para remover seu termo associado: ");
                    scanf("%d",&k);
                    x = remove_ord(L,k);

                    if(x==1)
                        printf("elemento removido!\n");
                    else if(x==-1)
                        printf("elemento nao encontrado!\n");
                    else if(x==0)
                        printf("erro!\n");
                }
                break;
            case 3: //imprimir lista
                printf("P(x) = ");
                x=1;
                while(obtem_elem(L,x,&a,&k)!=0){
                    if(a!=0){
                        if(a>0) //se 'a' for positivo
                            printf("+");
                        else //se 'a' for negativo
                            printf("-");
                    }
                    printf("%d",a);

                    if(k!=0)
                        printf("x^%d",k);

                    printf(" ");
                    x++;
                }
                printf("\n");
                break;
            case 4: //calcular P(x)
                printf("digite o valor de 'x' em P(x): ");
                scanf("%d",&x);
                printf("P(%d) = %d\n",x,calcular_Px(L,x));
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