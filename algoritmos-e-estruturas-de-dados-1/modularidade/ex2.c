#include <stdio.h>
#include <string.h>

struct agenda {
    int DDD,telefone;
    int tipo; // 0 fixo, 1 celular
    char nome[20];
};

void cadastro(struct agenda contato[], int *i, int *qtd_contatos){
    printf("digite 'ACABOU' para encerrar registro na agenda\n");
    printf("nome: ");
    setbuf(stdin,NULL);
    gets(contato->nome);
    if(strcmp(contato->nome,"ACABOU")==0){
        *qtd_contatos=*i;
        *i=20;
        return;
    }
    printf("DDD: ");
    scanf("%d",&contato->DDD);
    printf("nro do telefone: ");
    scanf("%d",&contato->telefone);
    printf("fixo(0) ou celular(1): ");
    scanf("%d",&contato->tipo);
    printf("\n");
}

int consulta(struct agenda contato[],int i, int qtd_contatos,char nome_pesquisa[]){
    if(strcmp(nome_pesquisa,"FIM")==0)
        return 2;

    if(strcmp(nome_pesquisa,contato->nome)==0){
        printf("\ncontato[%d]:\nnome: %s\nDDD: %d\nnro do telefone: %d\n",i,contato->nome,contato->DDD,contato->telefone);
        if(contato->tipo==0)
            printf("tipo: fixo\n");
        else if(contato->tipo==1)
            printf("tipo: celular\n");
            return 1;
    }
    else if(i==qtd_contatos-1){
        printf("\nnome nao encontrado!\n");
        return 0;
    }
    else
        return 0;
}

int main(){
    struct agenda contato[20];
    int i,qtd_contatos=20,pesquisa_concluida;
    char nome_pesquisa[20];
    for(i=0;i<20;i++){
        cadastro(&contato[i],&i,&qtd_contatos);
    }
    while(pesquisa_concluida!=2){
        pesquisa_concluida=0;
        printf("\ndigite 'FIM' para encerrar pesquisa");
        printf("\npesquisa de contato pelo nome: ");
        setbuf(stdin,NULL);
        gets(nome_pesquisa);
        for(i=0;i<qtd_contatos;i++){
            if(pesquisa_concluida==0)
                pesquisa_concluida = consulta(&contato[i],i,qtd_contatos,nome_pesquisa);
        }
    }
    return 0;
}