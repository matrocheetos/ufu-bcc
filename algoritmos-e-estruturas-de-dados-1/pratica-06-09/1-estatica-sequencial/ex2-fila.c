#include <stdlib.h>
#include <string.h>
#include "ex2.h"
#define MAX 20

struct fila{
    struct aluno alunos[MAX];
    int inicio,final,qtd;
};

Fila* criar_fila(){
    Fila *fila = (Fila*) malloc(sizeof(struct fila));
    if(fila != NULL){
        fila->inicio = 0;
        fila->final = 0;
        fila->qtd = 0;
    }
    return fila;
}

int fila_vazia(Fila* fila){
    if(fila == NULL) return -1;
    if(fila->qtd == 0) return 1;
    else return 0;
}

int fila_cheia(Fila* fila){
    if(fila == NULL) return -1; // nao tem fila
    if(fila->qtd == MAX) return 1;
    else return 0;
}

int insere_fim(Fila* fila, struct aluno insere){
    if(fila == NULL) return 0;
    if(fila_cheia(fila) == 1) return 0;
    if(strlen(insere.nome) > 50) return 0;

    strcpy(fila->alunos[fila->final].nome,insere.nome);
    fila->alunos[fila->final].matricula = insere.matricula;
    fila->alunos[fila->final].faltas = insere.faltas;
    fila->alunos[fila->final].media = insere.media;

    fila->final = (fila->final+1)%MAX;
    fila->qtd++;
    return 1;
}

int remove_ini(Fila* fila){
    if(fila == NULL || fila_vazia(fila)) return 0;

    fila->inicio = (fila->inicio+1)%MAX;
    fila->qtd--;
    return 1;
}

int get_elem(Fila *fila, int posicao, struct aluno *elemento){
    posicao = posicao+fila->inicio;
    if(fila == NULL || fila->final == fila->inicio || posicao >= fila->final) return 0;
    *elemento = fila->alunos[posicao];
    return 1;
}