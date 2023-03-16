#include <stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};

typedef struct lista *Lista;
typedef struct lista Elemento;

int insere_ordenada(Lista* ls, int elemento){
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
        if((*ls)->info > elemento){ //insere inicio
            Elemento *atual = *ls;
            while(atual->prox != (*ls))
                atual = atual->prox; //procura o ultimo
            insere->prox = *ls;
            atual->prox = insere;
            *ls = insere;
            return 1;
        }
        Elemento *anterior = *ls, *atual = (*ls)->prox;
        while(atual!=(*ls) && atual->info<elemento){
            anterior = atual;
            atual = atual->prox;
        }
        anterior->prox = insere;
        insere->prox = atual;
    }
    return 1;
}