#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//TAD lista dinamica/encadeada com cabeçalho
//info: 2 nros inteiros (coeficiente 'a' e valor 'k' da potencia)
//operacoes: inicializar polinomio, inserir novo termo (ax^k) no polinomio existente,
//imprimir P(x), eliminar termo na k-esima potencia, reinicializar polinomio,
//calcular P(x) e sair do sistema

int main(){

    Lista lst = cria_lista();

    int escolha,coef,pot,result;

    int x = 0; ///Verifica se o polinomio foi inicializado

    while(1){

        do{
            printf("\nEscolha de 1 %c 6\n", 133);
            printf("1_Inicializar ou reinicializar o polin%cmio.\n", 147);
            printf("2_Inserir um novo termo no polin%cmio.\n", 147);
            printf("3_Remover um termo, pela pot%cncia.\n", 136);
            printf("4_Calcular o polin%cmio, P(x).\n", 147);
            printf("5_Imprimir.\n");
            printf("6_Sair.\n");
            printf("Escolha: ");
            scanf("%d", &escolha);
            if(escolha != 1 && escolha != 6 && x ==0)
                printf("Inicialize o polin%cmio antes de fazer outra opera%c%co.\n",147,135,198);
        }while(escolha < 0 || escolha > 6 || (escolha != 1 && escolha != 6 && x == 0)); ///volta se a op��o for invalida ou se o polinomio nao for inicializado



        switch(escolha){

            case 1: if(x == 0){ /// S� sera possivel inicializar o polinomio 1 vez.
                        lst == cria_lista();
                        x = 1;
                    }
                    else
                        reinicializa_lista(&lst);
                    break;

            case 2: printf("Coeficiente: ");
                    scanf("%d", &coef);
                    printf("Potencia: ");
                    scanf("%d", &pot);
                    result = insere_ord(lst,coef,pot);
                    if(result != 1)
                        printf("Erro na inser%c%co.\n", 135,198);
                    else
                        printf("Inser%c%co feita com sucesso.\n", 135,198);
                    break;

        case 3: printf("Potencia que deseja remover: ");
                scanf("%d", &pot);
                result = remove_ord(lst,pot);
                if(result != 1)
                    printf("Erro na remo%c%co.\n", 135,198);
                else
                    printf("Remo%c%co feita com sucesso.\n", 135,198);
                break;

        case 4: printf("Valor de x: ");
                scanf("%d", &pot);

                printf("\nP(%d) = %d\n", pot, calcula_p(lst,pot));
                break;

        case 5: imprime_lista(lst);break;

        case 6: return 0;

        }
    }

}
