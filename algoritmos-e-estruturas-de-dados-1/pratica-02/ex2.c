#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bebida{
    char nome[20];
    int volume;
    float preco;
};

void limpar(struct bebida bebidas[]){
    strcpy(bebidas->nome,"\0");
    bebidas->volume=0;
    bebidas->preco=0.0;
}

void registro(struct bebida bebidas[], int *bebidas_registradas){
    printf("bebida [%d]\n",*bebidas_registradas);
    printf("nome: ");
    setbuf(stdin,NULL);
    gets(bebidas[*bebidas_registradas].nome);
    printf("volume (ml): ");
    scanf("%d",&bebidas[*bebidas_registradas].volume);
    printf("preco: ");
    scanf("%f",&bebidas[*bebidas_registradas].preco);
    *bebidas_registradas=*bebidas_registradas+1;
}

void apagar_ultimo_registro(struct bebida bebidas[],int *bebidas_registradas){
    limpar(&bebidas[*bebidas_registradas-1]);
    *bebidas_registradas=*bebidas_registradas-1;
    printf("ultimo registro de bebida apagado com sucesso\n");
}

void imprimir_tabela(struct bebida bebidas[],int bebidas_registradas){
    int i;
    for(i=0;i<bebidas_registradas;i++){
        printf("\nbebida[%d]: %s\t%d ml\t%f",i,bebidas[i].nome,bebidas[i].volume,bebidas[i].preco);
    }
}

int main(){
    struct bebida *bebidas;
    int i,escolha=0,bebidas_registradas=0;
    
    bebidas=(struct bebida*) malloc(20*sizeof(struct bebida));
    if(bebidas==NULL){
        printf("memoria insuficiente!\n");
        exit(1);
    }
    for(i=0;i<20;i++)
        limpar(&bebidas[i]);

    while(escolha!=4){
        printf("\n[1] Inserir registro\n[2] Apagar ultimo registro\n[3] Imprimir tabela\n[4] Sair\nescolha uma das opcoes: ");
        scanf("%d",&escolha);
        if(escolha>4 || escolha<1){
            printf("opcao invalida!\n");
            escolha=0;
        }else{
            printf("\n");
            if(escolha==1)
                registro(bebidas,&bebidas_registradas);
            if(escolha==2)
                apagar_ultimo_registro(bebidas,&bebidas_registradas);
            if(escolha==3)
                imprimir_tabela(bebidas,bebidas_registradas);
            if(escolha==4)
                printf("o programa esta sendo encerrado...\n");
        }
    }
    free(bebidas);
    return 0;
}