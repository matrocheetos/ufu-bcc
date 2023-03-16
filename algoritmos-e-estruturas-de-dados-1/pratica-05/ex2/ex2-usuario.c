#include <stdio.h>
#include "ex2.h"

int main(){
    Lista *L;
    int opcao=0,x;

    printf("[0] Inicializar lista\n[1] Registrar um aluno\n[2] Remover um registro\n[3] Imprimir lista\n[4] Apresentar tamanho da lista\n[5] Sair\n");
    while (opcao != 5){
        printf("> ");
        scanf("%i",&opcao);
        switch(opcao){
            case 0: //inicializar lista
                L = inicializar_lista();
                printf("lista inicializada!\n");
                break;
            case 1: //inserir registro do aluno
                printf("digite os dados do aluno:\n");
                struct aluno registro;
                printf("nro de matricula: ");
                scanf("%d",&registro.matricula);
                printf("nome: ");
                setbuf(stdin,NULL);
                gets(registro.nome);
                printf("media: ");
                scanf("%f",&registro.media);
                printf("faltas: ");
                scanf("%d",&registro.faltas);
                x = insere_elem(L,registro);
                if(x==0)
                    printf("erro!\n");
                else
                    printf("elemento adicionado!\n");
                break;
            case 2: //remover elemento
                if(lista_vazia(L)==1){
                    printf("lista ja esta vazia!");
                }else{
                    unsigned int matricula;
                    printf("digite o nro de matricula do aluno a ser removido: ");
                    scanf("%d",&matricula);
                    x = remove_elem(L,matricula);
                    if(x==0)
                        printf("elemento nao existe!\n");
                    else
                        printf("elemento removido!\n");
                }
                break;
            case 3: //imprimir lista
                if(lista_vazia(L)==1)
                    printf("lista vazia!\n");
                else{
                    printf("lista de alunos: ");
                    struct aluno imprimir; x=0;
                    while(get_pos(L,x,&imprimir) != 0){
                        printf("\n%d - %s - media %.2f - %d faltas",imprimir.matricula, imprimir.nome, imprimir.media, imprimir.faltas);
                        x++;
                    }
                    printf("\n");
                }
                break;
            case 4: //apresentar tamanho da lista
                if(lista_vazia(L)==1)
                    printf("lista vazia!\n");
                else
                    printf("a lista possui %d registros\n",size_lista(L));
                break;
            case 5: //sair
                printf("encerrando o programa...\n");
                break;
            default:
                printf("opcao invalida!\n");
        }
    }
    return 0;
}