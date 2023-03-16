//Foi decidido utilizar a lista encadeada com cabe�alho, pois o exercicio pede para se inicializar a lista com 0x^0,
//para isso ser possivel o cabe�alho do polinomio sera sempre esse termo.
//Al�m disso a lista encadeada � uma boa op�ao nesse caso, pois da a liberdade de o programa poder receber quantos termos
//o usuario desejar, sem a preocupa�ao da lista ficar cheia.

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <math.h>

//TAD lista dinamica/encadeada com cabeçalho
//info: 2 nros inteiros (coeficiente 'a' e valor 'k' da potencia)
//operacoes: inicializar polinomio, inserir novo termo (ax^k) no polinomio existente,
//imprimir P(x), eliminar termo na k-esima potencia, reinicializar polinomio,
//calcular P(x) e sair do sistema

struct no {
    int pot;
    int coef;
    struct no *prox;
};

//cria a lista e inicializa com os valores no cabeçalho
Lista cria_lista(){
    Lista cab;

    cab = (Lista) malloc(sizeof(struct no));

    if(cab != NULL){ ///O cabeçalho vai ser sempre 0x^0
        cab->pot = 0;
        cab->coef = 0;
        cab->prox = NULL;
    }

    return cab;
}

int lista_vazia(Lista lst){ //verifica se lista é vazia considerando o cabeçalho
    if(lst->coef == 0 && lst->pot == 0 && lst->prox == NULL) //lista vazia quando além do prox ser NULL, cab == 0x^0
        return 1;
    return 0;
}

//insercao ordenada em relacao à k-ésima potencia, recebe coeficiente e potencia
int insere_ord(Lista lst, int coef, int pot){
    Lista N;

    N = (Lista) malloc(sizeof(struct no));

    if(N == NULL) return 0;

    N->coef = coef;
    N->pot = pot;

    if(pot == 0){ //adiciona no primeiro nó
        lst->coef = lst->coef + N->coef;
        return 1;
    }

    while(lst->prox != NULL && lst->prox->pot < pot)
        lst = lst->prox;

   if(lst->prox != NULL)
        if(lst->prox->pot == pot){ //verifica se potencia ja existe, se sim, soma o coeficiente
            lst->prox->coef = N->coef + lst->prox->coef; ///Soma quando inserir o termo de uma potencia que ja existe no polinomio
            return 1;
        }
    
    //insercao quando nao se encontra uma potencia igual:
    N->prox = lst->prox;
    lst->prox = N;

    return 1;
}

//remove o elemento relacionado à k-ésima potência
int remove_ord(Lista lst, int elem){
    if(lista_vazia(lst) == 1)
        return 0;

    Lista aux = lst;

    while(aux->prox != NULL && aux->prox->pot < elem) //percorre a lista
        aux = aux->prox;

    if(aux->prox ==NULL || aux->prox->pot > elem) //nao encontra a potencia
        return 0;

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

//impressao do polinomio
void imprime_lista(Lista lst){

     if(lista_vazia(lst) == 1){
        printf("0x^0\n");
     }

    if(lst->coef == 0)
        lst = lst->prox; ///Nao imprime a potencia de 0, caso o coeficiente seja 0

     while (lst!= NULL){
        if(lst->pot == 0){
            if(lst->coef > 0)printf("+");
            printf("%d",lst->coef);
        }else{
            if(lst->coef > 0)printf("+");
            printf("%dx^%d",lst->coef,lst->pot);
        }
        lst = lst->prox;
      }
      printf("\n");
}

//faz a lista retornar ao seu estado de vazio, fica igual quando foi criada inicialmente
void reinicializa_lista(Lista *lst){

    if(lista_vazia(*lst) != 1){ //verifica se ja nao esta vazia
        Lista *aux;
        while((*lst) != NULL){
            aux = (*lst);
            (*lst) = (*lst)->prox;
            free(aux);
        }
        Lista nova = cria_lista();
        *lst = nova;
    }
}

//recebe 'x' e calcula P(x)
int calcula_p(Lista lst, int p){

    int result = 0;

    if(lista_vazia(lst) == 1)
        return 0;

    while(lst != NULL){ //calcula o polinomio de acordo com os valores da lista e 'x'
        result = (result) + ((pow(p,lst->pot)) * (lst->coef));
        lst = lst->prox; //percorre a lista
    }

    return result;

}
