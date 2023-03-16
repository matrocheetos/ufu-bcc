#include <stdlib.h>
#include <string.h>
#include "ex2.h"

struct lista{
    struct aluno aluno;
    struct lista *prox;
};

Lista* inicializar_lista(){
    Lista* ls = (Lista*) malloc(sizeof(Lista));
    if(ls != NULL)
        *ls = NULL;
    return ls;
}

int lista_vazia(Lista* ls){
    if(ls == NULL)
        return 1; //vazia
    if(*ls == NULL)
        return 1; //vazia

    return 0; //não vazia
}

int lista_cheia(){
    Lista *ls = (Lista*) malloc(sizeof(Lista));
    if(ls == NULL)
        return 1; //nao conseguiu alocar memoria
    else
        return 0; //memoria não acabou
}

int insere_elem(Lista* ls, struct aluno registro){
    if(ls==NULL)
        return 0;
    Elemento* insere =(Elemento*) malloc(sizeof(Elemento));
    if(insere == NULL)
        return 0;
    
    insere->aluno = registro;
    insere->prox = (*ls);

    *ls = insere;
    return 1;
}

int remove_elem(Lista* ls, unsigned int matricula){
    Elemento* remove = (*ls);
    if(matricula == (*ls)->aluno.matricula){ //1o elemento
        *ls = remove->prox;
        free(remove);
        return 1;
    }
    while(remove->prox != NULL && remove->prox->aluno.matricula != matricula)
        remove=remove->prox;

    if(remove->prox == NULL)
        return 0; //matricula nao encontrada

    Elemento* remove2 = remove->prox;
    remove->prox = remove2->prox;
    free(remove2);
    return 1;
}

int get_pos(Lista* ls, int posicao, struct aluno* dados){
    Elemento* aluno = *ls;
    int i=0;
    while(aluno != NULL && i<posicao){
        aluno=aluno->prox;
        i++;
    }

    if(aluno == NULL)
        return 0;
    else{
        *dados = aluno->aluno;
        return 1;
    }
}

int size_lista(Lista* ls){
    int contador = 0;
    Elemento *size = (*ls);

    while(size != NULL){
        size = size->prox;
        contador++;
    }
    return contador;
}