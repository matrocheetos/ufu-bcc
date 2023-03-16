#include <stdlib.h>
#include "ex2.h"

struct lista{
    int info;
    struct lista *prox;
};

Lista* criar_lista(){
    Lista* ls = (Lista*) malloc(sizeof(Lista));
    if(ls!=NULL)
        *ls = NULL;
    return ls;
}

int lista_vazia(Lista* ls){
    if(ls == NULL || (*ls) == NULL)
        return 1;
    else
        return 0;
}

int insere_inicio(Lista* ls, int elemento){
    if(ls == NULL)
        return 0;
    
    Elemento *insere = (Elemento*) malloc(sizeof(Elemento));
    if(insere == NULL)
        return 0;
    
    insere->info = elemento;
    if((*ls) == NULL){ //lista vazia: insere inicio
        *ls = insere;
        insere->prox = insere;
    }else{
        Elemento *aux = *ls;
        while(aux->prox != (*ls))
            aux = aux->prox;
        aux->prox = insere;
        insere->prox = *ls;
        *ls = insere;
    }
    return 1;
}

int remove_final(Lista* ls, int elemento){
    if(lista_vazia(ls) == 1)
        return 0;
    
    Elemento *remove = *ls;
    if(remove->info == elemento){
        if(remove==remove->prox){ //lista fica vazia
            free(remove);
            *ls=NULL;
            return 1;
        }else{
            Elemento *ultimo = *ls;
            while(ultimo->prox != (*ls)) //procura o ultimo
                ultimo = ultimo->prox;
            ultimo->prox = (*ls)->prox;
            *ls=(*ls)->prox;
            free(remove);
            return 1;
        }
    }
    Elemento *anterior = remove;
    remove = remove->prox;
    while(remove!=(*ls) && remove->info!=elemento){
        anterior = remove;
        remove = remove->prox;
    }
    if(remove==*ls) //nao encontrado
        return 0;
    anterior->prox = remove->prox;
    free(remove);
    return 1;
}

int obtem_valor_elem(Lista* ls, int posicao, int *informacao){
    if(lista_vazia(ls)==1)
        return 0;

    Elemento *conteudo = *ls;
    int i=1;
    while(conteudo->prox != (*ls) && i<posicao){
        conteudo=conteudo->prox;
        i++;
    }
    if(i!=posicao)
        return 0;
    else{
        *informacao = conteudo->info;
        return 1;
    }
}