#include <stdio.h>
#include <string.h>

struct matricula{
    int nro_matricula,nota;
    char nome[40];
};

void leitura_dados(struct matricula matricula[]){
    printf("nome: ");
    setbuf(stdin,NULL);
    gets(matricula->nome);
    printf("numero de matricula: ");
    scanf("%d",&matricula->nro_matricula);
    printf("nota: ");
    scanf("%d",&matricula->nota);
}

void gravacao_dados(struct matricula matricula[], FILE *fp){
    fprintf(fp,"nome: %s\nnumero de matricula: %d\nnota: %d\n\n",matricula->nome,matricula->nro_matricula,matricula->nota);
}

int main(){
    char nome_arquivo[30];
    int qtd_alunos,i;

    printf("insira o nome do arquivo: ");
    gets(nome_arquivo,30,stdin);
    strcat(nome_arquivo,".txt");

    FILE *fp;
    fp = fopen(nome_arquivo,"w");
    if(!fp){
        printf("erro na abertura do arquivo!\n");
        return 0;
    }

    printf("quantidade de alunos a serem registrados: ");
    scanf("%d",&qtd_alunos);
    if(qtd_alunos>100 || qtd_alunos<1){
        printf("quantidade invalida! (maior que 100 ou menor que 1)\n");
        fclose(fp);
        return 0;
    }
    struct matricula matricula[qtd_alunos];

    for(i=0;i<qtd_alunos;i++){
        printf("\naluno [%d]\n",i+1);
        leitura_dados(&matricula[i]);
        gravacao_dados(&matricula[i],fp);
    }
    printf("\ndados gravados em %s \n",nome_arquivo);

    fclose(fp);
    return 0;
}