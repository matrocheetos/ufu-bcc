//ex8
//lista dinamica encadeada ordenada
//se utilizará a lista dinamica encadeada porque não há um tamanho limite pré-definido e se realiza muita inserção; ordenada por requisito do exercício.

#include <stdlib.h>
#include "lista.h"

struct lista{
    int a,k;
    struct lista *prox;
};

//cria e inicializa a lista com P(x)=0x^0
Lista* cria_lista(){
    Lista* ls = (Lista*) malloc(sizeof(Lista));
    if(ls != NULL){
        *ls = NULL;
        Elemento *aux = (Elemento*) malloc(sizeof(Elemento));
        if(aux!=NULL){ //inicializacao com P(x)=0x^0
            aux->a = 0;
            aux->k = 0;
            aux->prox = (*ls);
            *ls = aux;
        }
    }
    return ls;
}

//verifica se a lista está vazia/não inicializada
int lista_vazia(Lista *ls){
    if(ls == NULL || *ls == NULL)
        return 1; //vazia
    else
        return 0; //não vazia
}

//insercao ordenada em relação à k-ésima potência (posição de k)
int insere_ord(Lista *ls, int a, int k){

    if(ls==NULL) return 0; //verifica se a lista é válida
    if(a==0) return -1; //'a' não pode ser zero

    Elemento *insere = (Elemento*) malloc(sizeof(Elemento));
    if(insere==NULL) return 0;

    insere->a = a;
    insere->k = k;

    if(lista_vazia(ls)==1){ //se a lista está vazia, insere no início
        insere->prox = (*ls);
        *ls = insere;
        return 1;
    }
    else{
        Elemento *anterior, *atual = *ls;
        int verif_k,verif_a; //utilizados para verificar igualdade do 'k' atual com outro 'k' inserido anteriormente

        while(atual != NULL && atual->k <= k){
            verif_k = atual->k;
            verif_a = atual->a;
            anterior = atual;
            atual = atual->prox;
        }

        if(verif_k == k)
            insere->a = a + verif_a; //soma os valores de 'a' para serem inseridos no mesmo 'k'

        if(atual == *ls){ //insere no inicio
            insere->prox = (*ls);
            *ls = insere;
        }else{ //insere no meio ou final
            insere->prox = anterior->prox;
            anterior->prox = insere;
        }

        if(verif_k == k)
            remove_ord(ls,k); //remove o elemento que foi duplicado e ficou "sobrando"

        return 1;
    }
}

//remove o termo relacionado à k-ésima potência (posição de k)
int remove_ord(Lista *ls, int k){
    if(ls==NULL) return 0; //verifica se a lista é válida

    Elemento *anterior, *remove = *ls;

    while(remove != NULL && remove->k != k){
        anterior = remove;
        remove = remove->prox;
    }

    if(remove == NULL){
        return -1; //posicao nao encontrada
    }

    if(remove == *ls){
        *ls = remove->prox; //remove do inicio
    }else{
        anterior->prox = remove->prox; //remove do meio ou final
    }
    free(remove);
    return 1;
}

//devolve os valores 'a' e 'k' em uma determinada posicao
int obtem_elem(Lista *ls, int posicao, int *a, int *k){
    if(ls==NULL) return 0; //verifica se a lista é válida

    Elemento *obtem = *ls;
    
    int i=1;
    while(obtem != NULL && i < posicao){
        obtem = obtem->prox;
        i++;
    }

    if(obtem == NULL)
        return 0; //lista nao tem elementos
    else{
        *a = obtem->a;
        *k = obtem->k;
        return 1;
    }
}

//calcula a potencia de um numero ; funcao implementada p/ nao ser necessaria a math.h
int potencia(int base, int expoente){
    if(expoente==0) return 1;
    
    int i,resultado=base;
    for(i=1;i<expoente;i++)
        resultado = resultado*base;

    return resultado;
}

//calcula o valor de P(x) para um valor de 'x' solicitado
int calcular_Px(Lista *ls, int x){
    if(x==0) return 0;
    
    int a,k,i=1,resultado=0;
    while(obtem_elem(ls,i,&a,&k)!=0){
        resultado = resultado + (a * potencia(x,k));
        i++;
    }
    return resultado;
}