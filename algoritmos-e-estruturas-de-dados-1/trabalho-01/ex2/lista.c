#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define max 20

//TAD lista ordenada estatica/sequencial
//info: nros inteiros
//parecida com o exercicio 1
//mas agora remove pares, retorna o maior, intercala

struct lista{
    int no[max];
    int fim;
};

lista cria_lista(){
    lista lst;
    lst = (lista)malloc(sizeof(struct lista));

    if(lst != NULL)
        lst -> fim=0;

    return lst;
}

int lista_vazia(lista lst){
    if(lst -> fim==0)
        return 1;
    else return 0;
}

int lista_cheia(lista lst){
    if(lst -> fim==max)
        return 1;
    else return 0;
}

//ATE AQUI TÁ IGUAL

//insercao ordenada
int insere_ord(lista lst, int elem){
    if(lst == NULL  || lista_cheia(lst) == 1)
        return 0;

    if(lista_vazia(lst) == 1 || elem>=lst->no[lst->fim]){ //se lista é vazia
        lst->no[lst->fim] = elem;
    }else{ //verificacoes de onde inserir na lista
        int i, aux=0;

        while(elem >= lst->no[aux])
            aux++;

        for(i=lst->fim; i>aux; i--)
            lst->no[i] = lst->no[i-1];

        lst->no[aux] = elem;
    }
    lst->fim++;
    return 1;
}

int remove_ord(lista lst, int elem){
    //if com verificacoes a mais pra se estiver maior que o primeiro ou maior que o ultimo (vantagem de ser ordenada)
    if(lst == NULL  || lista_vazia(lst) == 1 || elem < lst->no[0] || elem>lst->no[lst->fim-1])
        return 0;

    int i, aux=0;

    while(aux < lst->fim && lst->no[aux]<elem)
        aux++;

    if(aux == lst->fim || lst->no[aux] > elem)
        return 0;

    for(i=aux+1; i<lst->fim; i++)
        lst->no[i-1] = lst->no[i];

    lst->fim--;
    return 1;
}

//esvazia: igual ex1
int esvaziar(lista lst){

    if(lista_vazia(lst)==1){
        return 0;
    }

    lst->fim = 0;
    return 1;
}

//imprime: igual ex1
void imprime_lista(lista p){
    int i=0;
    for(i=0;i<p->fim;i++){
        printf("%d",p->no[i]);
        if(i<p->fim-1)printf(" ");
    }
    printf("\n");
}

//retorna o maior elemento
int maior(lista p){
    if(p->fim==0)
        return 0;
    int i,maior = p->no[0];
    for(i=1;i<p->fim;i++){
        if(p->no[i]>maior) //verificacao de maior
            maior=p->no[i];
    }
    return maior;
}

int remove_pares(lista lst){

    if(lista_vazia(lst) == 1)
        return 0;

    int i = 0,j;
    int k=0, flag=0;

    while(k<lst->fim){
    for(i=0; i<lst->fim;i++){
        if(lst->no[i] % 2 == 0){ //verifica se é par
            for(j = i; j < (lst->fim)-1; j++)
                lst->no[j] = lst->no[j+1]; //move a lista qnd remove o elemento
        lst->fim--;
        flag++;
        }
    }
    k++;
    }
    return flag;
}

//tamanho: igual ex1
int tamanho(lista p){
    return p->fim;
}

//intercalar: retorna L3 com intercalacao dos elementos de L1 e L2 de forma ordenada
int intercala(lista a,lista b,lista c){
    if((a->fim+b->fim)>max)
        return 0;

    int x=0, y=0;
    while(x<a->fim){            //utiliza funcao insere_ord pra facilitar processo
        insere_ord(c,a->no[x]); //insere elementos da L1
        x++;
    }
    while(y<b->fim){
        insere_ord(c,b->no[y]); //insere elementos da L2
        y++;
    }
    return 1;
}
