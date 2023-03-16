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

int main(){
    struct agenda contato[20];
    int i,qtd_contatos=20;
    for(i=0;i<20;i++){
        cadastro(&contato[i],&i,&qtd_contatos);
    }
    for(i=0;i<qtd_contatos;i++){
        printf("\ncontato[%d]:\nnome: %s\nDDD: %d\nnro do telefone: %d\n",i,contato[i].nome,contato[i].DDD,contato[i].telefone);
        if(contato[i].tipo==0)
            printf("tipo: fixo\n");
        else if(contato[i].tipo==1)
            printf("tipo: celular\n");
    }
    return 0;
}