#include <stdio.h>
#include <stdlib.h>

struct aluno{
    char nome[30];
    double media;
    int faltas;
};

void registro(struct aluno alunos[]){
    printf("nome: ");
    setbuf(stdin,NULL);
    gets(alunos->nome);
    MEDIA:
    printf("media: ");
    scanf("%lf",&alunos->media);
    if(alunos->media<0.0){
        printf("valor invalido! (negativo)\n");
        goto MEDIA;
    }
    FALTAS:
    printf("faltas: ");
    scanf("%d",&alunos->faltas);
    if(alunos->faltas<0){
        printf("valor invalido! (negativo)\n");
        goto FALTAS;
    }
}

void selectionSort(struct aluno alunos[], int qtd_alunos){
    int i,j,menor;
    struct aluno troca;
    for(i=0;i<qtd_alunos-1;i++){
        menor=i;
        for(j=i+1;j<qtd_alunos;j++){
            if(alunos[j].media<alunos[menor].media)
                menor=j;
        }
        if(i!=menor){
            troca=alunos[i];
            alunos[i]=alunos[menor];
            alunos[menor]=troca;
        }
    }
}

int main(){
    struct aluno *alunos;
    int qtd_alunos,i;

    printf("quantidade de alunos a serem registrados: ");
    scanf("%d",&qtd_alunos);
    if(qtd_alunos<1){
        printf("quantidade muito pequena! (menor que 1)\n");
        exit(1);
    }

    alunos=(struct aluno*) malloc(qtd_alunos*sizeof(struct aluno));
    if(alunos==NULL){
        printf("memoria insuficiente!\n");
        exit(1);
    }
    for(i=0;i<qtd_alunos;i++){
        printf("aluno [%d]\n",i);
        registro(&alunos[i]);
        printf("\n");
    }

    selectionSort(alunos,qtd_alunos);
    printf("alunos ordenados por media:\n");
    for(i=0;i<qtd_alunos;i++){
        printf("%s (%d falta(s)): %lf\n",alunos[i].nome,alunos[i].faltas,alunos[i].media);
    }

    free(alunos);
    return 0;
}