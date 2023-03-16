#include <stdlib.h>
#include "fila.h"
#define max 20
#include <string.h>

struct aluno{
    int matricula;
    char nome[50];
    int cg;
    int ano;
    float cra;
};

struct fila{
    aluno no[max];
    int ini,fim;
};

fila cria_fp(){
    fila f;
    f = (fila)malloc(sizeof(struct fila));
    if(f!=NULL){
        f->ini = 0;
        f->fim = 0;
    }
    return f;
}

int fp_vazia(fila f){
    if(f->ini == f->fim)
        return 1;
    else
        return 0;
}

int fp_cheia(fila f){
    if(f->ini == (f->fim+1)%max)
        return 1;
    else
        return 0;
}

int insere_fim(fila f, char nome[50], int matricula, int cg, int ano, float cra){
    if(fp_cheia(f) == 1)
        return 0;
    f->no[f->fim].matricula = matricula;
    strcpy(f->no[f->fim].nome,nome);
    f->no[f->fim].cra = cra;
    f->no[f->fim].cg = cg;
    f->no[f->fim].ano = ano;
    f->fim = (f->fim+1)%max;
    return 1;
}

int remove_ord(fila f, char nome[50], int *matricula,int *cg, int *ano, float *cra){
    if(fp_vazia(f) == 1)
        return 0;

    int aux = f->no[f->ini].ano;
    int i,v=0;

    for(i=0;i<(f->fim);i++){
        if(aux > f->no[i].ano){
            aux = f->no[i].ano;
            v = i;
        }
    }

    strcpy(nome,f->no[v].nome);
    *matricula = f->no[v].matricula;
    *ano = f->no[v].ano;
    *cg = f->no[v].cg;
    *cra = f->no[v].cra;

    int j;
    for(j=v+1;j<=(f->fim);j++){
        strcpy(f->no[j-1].nome,f->no[j].nome);
        f->no[j-1].matricula = f->no[j].matricula;
        f->no[j-1].ano = f->no[j].ano;
        f->no[j-1].cg = f->no[j].cg;
        f->no[j-1].cra = f->no[j].cra;
    }
    f->fim = (f->fim-1)%max;
    return 1;
}

int esvazia_fp(fila f){
    if(fp_vazia(f) == 1)
        return 0;
    while(fp_vazia(f)==0){
        f->fim = (f->fim-1)%max;
    }
    f->ini = 0;
    return 1;
}
