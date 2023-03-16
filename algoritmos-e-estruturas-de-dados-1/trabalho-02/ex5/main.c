#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define max 20
#include <string.h>

int main()
{
    int op, FLAG=0;
    fila f;

    do{
        do{
            printf("\n");
            printf("1- Criar uma FPA\n");
            printf("2- Inserir aluno\n");
            printf("3- Remover aluno mais antigo\n");
            printf("4- Esvaziar FPA\n");
            printf("5- Imprimir\n");
            printf("6- Sair\n");

            printf("Digite a operacao\n");
            scanf("%d",&op);

            if(op<1 || op>6)
                printf("Opcao inválida\n");

        }while(op<1 || op>6);

        if(op==6){
            printf("\nFim do progama\n");
            break;
        }
        else if(op!=1 && FLAG==0){
            printf("Antes de qualquer operacao, crie a FPA primeiro\n");
            continue;
        }

        if(op==1 && FLAG==1){
            printf("A FPA ja foi criada\n");
            continue;
        }

    switch(op){
        case 1:{
            f = cria_fp();
            printf("FPA criada\n");
            FLAG++;
            break;
        }
        case 2:{
            int matricula;
            char nome[50];
            int cg;
            int ano;
            float cra;

            printf("Digite o nome do aluno\n");
            setbuf(stdin,NULL);
            gets(nome);

            printf("Digite a matricula\n");
            scanf("%d",&matricula);

            printf("Digite a carga horaria semanal\n");
            scanf("%d",&cg);

            printf("Digite o ano de ingresso\n");
            scanf("%d",&ano);

            printf("Digite o cra\n");
            scanf("%f",&cra);

            if(insere_fim(f,nome,matricula,cg,ano,cra))
                printf("Aluno inserido\n");
            else
                printf("FPA esta cheia\n");
            break;
        }
        case 3:{
            int matricula;
            char nome[50];
            int cg;
            int ano;
            float cra;

            if(remove_ord(f,nome,&matricula,&cg,&ano,&cra))
                printf("Aluno removido\n");
            else
                printf("FPA esta vazia\n");
            break;
        }
        case 4:{
            if(esvazia_fp(f)==1)
                printf("FPA esvaziada\n");
            else
                printf("A FPA ja esta vazia");
            break;
        }
        case 5:{
            printf("\n");

            int matricula;
            char nome[50];
            int cg;
            int ano;
            float cra;

            int mat[max];
            char n[max][50];
            int ch[max];
            int a[max];
            float c[max];

            int j=0,i=0;
            while(fp_vazia(f) != 1){
                remove_ord(f,nome,&matricula,&cg,&ano,&cra);
                printf("Nome: %s\n",nome);
                printf("Matricula: %d\n",matricula);
                printf("Carga horaria semanal: %d\n",cg);
                printf("Ano de ingresso: %d\n",ano);
                printf("CRA: %.2f\n",cra);
                printf("\n");

                strcpy(n[i],nome);
                mat[i] = matricula;
                ch[i] = cg;
                a[i] = ano;
                c[i] = cra;

                i++;
            }

            for(j=0;j<i;j++){
                insere_fim(f,n[j],mat[j],ch[j],a[j],c[j]);
            }
            break;
        }
    }

    }while(op!=6);
}
