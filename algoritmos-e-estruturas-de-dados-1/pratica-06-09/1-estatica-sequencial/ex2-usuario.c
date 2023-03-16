#include <stdio.h>
#include "ex2.h"

int main(){
    Fila *F;
    int opcao=0,y;
    struct aluno aluno;

    printf("[0] Inicializar fila\n[1] Inserir um elemento\n[2] Remover um elemento (do fim da fila)\n[3] Imprimir fila\n[4] Sair\n");
    while (opcao != 4){
        printf("> ");
        scanf("%i",&opcao);
        switch(opcao){
            case 0: //inicializar fila
                F = criar_fila();
                printf("fila inicializada!\n");
                break;
            case 1: //inserir elemento
                printf("digite os dados do aluno:\n");
                printf("nome: ");
                setbuf(stdin,NULL);
                gets(aluno.nome);
                printf("matricula: ");
                scanf("%d",&aluno.matricula);
                printf("faltas: ");
                scanf("%d",&aluno.faltas);
                printf("media: ");
                scanf("%f",&aluno.media);
                y = insere_fim(F,aluno);
                if(y==0)
                    printf("erro!\n");
                else
                    printf("elemento adicionado!\n");
                break;
            case 2: //remover elemento do fim da fila
                if(fila_vazia(F)==1){
                    printf("fila ja esta vazia!");
                }else{
                    y = remove_ini(F);
                    if(y==0)
                        printf("erro!\n");
                    else
                        printf("elemento removido!\n");
                }
                break;
            case 3: //imprimir fila
                printf("fila:\n");
                y=0;
                while(get_elem(F,y,&aluno)!=0){
                    printf("%d) %s, %d - media %f %d faltas\n",y,aluno.nome,aluno.matricula,aluno.media,aluno.faltas);
                    y++;
                }
                break;
            case 4: //sair
                printf("encerrando o programa...\n");
                break;
            default:
                printf("opcao invalida!\n");
        }
    }
    return 0;
}