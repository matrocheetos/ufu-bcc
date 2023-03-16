#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "fila.h"
#include "lista.h"


int main(){


    ///Filas
    Fila coracao = cria_fila();
    Fila figado = cria_fila();
    Fila cornea = cria_fila();
    Fila rins = cria_fila();
    Fila pulmao = cria_fila();
    Fila aux = cria_fila();

    Lista doadores = cria_lista();
    Lista disponibilidade = cria_lista();
    Lista aux2 = cria_lista();
    Lista aux3 = cria_lista();

    ///Variaveis
    int escolha, flag_doador = 0;
    struct paciente p_cadastrando, p_lido;
    struct doador d_cadastrando, d_lido, d_lido2;
    int i, result;
    char info_orgao;

    do{
        printf("********MENU*******\n");
        printf("1_Cadastro de paciente.\n");
        printf("2_Cadastro de doador.\n");
        printf("3_Fila de pacientes.\n");
        printf("4_Fila de disponibilidade.\n");
        printf("5_Lista de doadores.\n");
        printf("6_Sair.\n");
        printf(">> ");
        scanf("%d", &escolha);

    ///Cadastrando paciente
    if(escolha == 1){
        //Lendo dados do paciente
        printf("\n-----------------------Cadastro de paciente-----------------------\n");
        printf("Nome: ");
        setbuf(stdin,NULL);
        gets(p_cadastrando.nome);
        printf("Idade: ");
        scanf("%d", &p_cadastrando.idade);
        printf("Gravidade do caso: ");
        scanf("%d", &p_cadastrando.gravidade);
        do{
            printf("Orgao necessario (coracao, cornea, figado, rim ou pulmao): ");
            setbuf(stdin,NULL);
            gets(p_cadastrando.orgao);
        }while(strcmp(p_cadastrando.orgao, "coracao") && strcmp(p_cadastrando.orgao, "cornea") && strcmp(p_cadastrando.orgao, "figado") && strcmp(p_cadastrando.orgao, "rim") && strcmp(p_cadastrando.orgao, "pulmao"));
        printf("\n------------------------------------------------------------------\n\n");

        ///Se estiver precisando de um coracao
        if(strcmp(p_cadastrando.orgao, "coracao") == 0){
            while(! lista_vazia(disponibilidade)){
                //verificando a lista de disponibilidade
                remove_ini_lista(&disponibilidade, &d_lido);
                //Se achar um coracao disponivel
                if(d_lido.coracao == 1){
                    flag_doador = 1; //Verifica se a lista de disponibilidade foi mexida

                    //Para mudar na lista de doadores
                    while(! lista_vazia(doadores)){
                        remove_ini_lista(&doadores, &d_lido2);
                        if(strcmp(d_lido.nome, d_lido2.nome) == 0 && d_lido2.coracao == 1){
                            strcpy(d_lido2.b_coracao, p_cadastrando.nome);
                            d_lido2.coracao = 0;
                            insere_fim(&aux3, d_lido2);
                            break;
                        }
                        insere_fim(&aux3, d_lido2);
                    }
                    //Coloca o paciente cadastrado como beneficiado
                    strcpy(d_lido.b_coracao, p_cadastrando.nome);
                    d_lido.coracao = 0;
                    //Se ainda tiver algum orgao desse doador, ele volta pra lista de disponibilidade
                    if(d_lido.cornea == 1 || d_lido.figado == 1 || d_lido.rins == 1 || d_lido.pulmao == 1)
                        insere_fim(&aux2, d_lido);
                    break;
                }
            }
            //Se nao encontrou um coracao, o paciente vai pra lista de espera
            if(lista_vazia(disponibilidade) == 1 && flag_doador == 0)
                insere_ord(&coracao, p_cadastrando);
            //Acaba de esvaziar a lista para restaurala depois
            while(! lista_vazia(disponibilidade)){
                remove_ini_lista(&disponibilidade, &d_lido);
                insere_fim(&aux2, d_lido);
            }
            //Restaura a lista de disponibilidade
            while(! lista_vazia(aux2)){
                remove_ini_lista(&aux2, &d_lido);
                insere_fim(&disponibilidade, d_lido);
            }

            //Restaurando a lista de doadores

            while(! lista_vazia(doadores)){
                remove_ini_lista(&doadores, &d_lido2);
                insere_fim(&aux3, d_lido2);
            }

            while(! lista_vazia(aux3)){
                remove_ini_lista(&aux3, &d_lido2);
                insere_fim(&doadores, d_lido2);
            }

        }

        ///Paciente precisando de cornea
        flag_doador = 0;
        if(strcmp(p_cadastrando.orgao, "cornea") == 0){
            while(! lista_vazia(disponibilidade)){
                //verificando a lista de disponibilidade
                remove_ini_lista(&disponibilidade, &d_lido);
                //Se achar um cornea disponivel
                if(d_lido.cornea == 1){
                    flag_doador = 1;

                    //Para mudar na lista de doadores
                    while(! lista_vazia(doadores)){
                        remove_ini_lista(&doadores, &d_lido2);
                        if(strcmp(d_lido.nome, d_lido2.nome) == 0 && d_lido2.cornea == 1){
                            strcpy(d_lido2.b_cornea, p_cadastrando.nome);
                            d_lido2.cornea = 0;
                            insere_fim(&aux3, d_lido2);
                            break;
                        }
                        insere_fim(&aux3, d_lido2);
                    }
                    //Coloca o paciente cadastrado como beneficiado
                    strcpy(d_lido.b_cornea, p_cadastrando.nome);
                    d_lido.cornea = 0;
                    //Se ainda tiver algum orgao desse doador, ele volta pra lista de disponibilidade
                    if(d_lido.coracao == 1 || d_lido.figado == 1 || d_lido.rins == 1 || d_lido.pulmao == 1)
                        insere_fim(&aux2, d_lido);
                    break;
                }
            }
            //Se nao encontrou um cornea, o paciente vai pra lista de espera
            if(lista_vazia(disponibilidade) == 1 && flag_doador == 0)
                insere_ord(&cornea, p_cadastrando);
            //Acaba de esvaziar a lista para restaurala depois
            while(! lista_vazia(disponibilidade)){
                remove_ini_lista(&disponibilidade, &d_lido);
                insere_fim(&aux2, d_lido);
            }
            //Restaura a lista de disponibilidade
            while(! lista_vazia(aux2)){
                remove_ini_lista(&aux2, &d_lido);
                insere_fim(&disponibilidade, d_lido);
            }

            //Restaurando a lista de doadores

            while(! lista_vazia(doadores)){
                remove_ini_lista(&doadores, &d_lido2);
                insere_fim(&aux3, d_lido2);
            }

            while(! lista_vazia(aux3)){
                remove_ini_lista(&aux3, &d_lido2);
                insere_fim(&doadores, d_lido2);
            }

        }

        ///Paciente precisando de figado
        flag_doador = 0;
        if(strcmp(p_cadastrando.orgao, "figado") == 0){
            while(! lista_vazia(disponibilidade)){
                //verificando a lista de disponibilidade
                remove_ini_lista(&disponibilidade, &d_lido);
                //Se achar um figado disponivel
                if(d_lido.figado == 1){
                    flag_doador = 1;

                    //Para mudar na lista de doadores
                    while(! lista_vazia(doadores)){
                        remove_ini_lista(&doadores, &d_lido2);
                        if(strcmp(d_lido.nome, d_lido2.nome) == 0 && d_lido2.figado == 1){
                            strcpy(d_lido2.b_figado, p_cadastrando.nome);
                            d_lido2.figado = 0;
                            insere_fim(&aux3, d_lido2);
                            break;
                        }
                        insere_fim(&aux3, d_lido2);
                    }
                    //Coloca o paciente cadastrado como beneficiado
                    strcpy(d_lido.b_figado, p_cadastrando.nome);
                    d_lido.figado = 0;
                    //Se ainda tiver algum orgao desse doador, ele volta pra lista de disponibilidade
                    if(d_lido.coracao == 1 || d_lido.cornea == 1 || d_lido.rins == 1 || d_lido.pulmao == 1)
                        insere_fim(&aux2, d_lido);
                    break;
                }
            }
            //Se nao encontrou um figado, o paciente vai pra lista de espera
            if(lista_vazia(disponibilidade) == 1 && flag_doador == 0)
                insere_ord(&figado, p_cadastrando);
            //Acaba de esvaziar a lista para restaurala depois
            while(! lista_vazia(disponibilidade)){
                remove_ini_lista(&disponibilidade, &d_lido);
                insere_fim(&aux2, d_lido);
            }
            //Restaura a lista de disponibilidade
            while(! lista_vazia(aux2)){
                remove_ini_lista(&aux2, &d_lido);
                insere_fim(&disponibilidade, d_lido);
            }

            //Restaurando a lista de doadores

            while(! lista_vazia(doadores)){
                remove_ini_lista(&doadores, &d_lido2);
                insere_fim(&aux3, d_lido2);
            }

            while(! lista_vazia(aux3)){
                remove_ini_lista(&aux3, &d_lido2);
                insere_fim(&doadores, d_lido2);
            }

        }

        ///Paciente precisando de rim
        flag_doador = 0;
        if(strcmp(p_cadastrando.orgao, "rim") == 0){
            while(! lista_vazia(disponibilidade)){
                //verificando a lista de disponibilidade
                remove_ini_lista(&disponibilidade, &d_lido);
                //Se achar um rins disponivel
                if(d_lido.rins == 1){
                    flag_doador = 1;

                    //Para mudar na lista de doadores
                    while(! lista_vazia(doadores)){
                        remove_ini_lista(&doadores, &d_lido2);
                        if(strcmp(d_lido.nome, d_lido2.nome) == 0 && d_lido2.rins == 1){
                            strcpy(d_lido2.b_rins, p_cadastrando.nome);
                            d_lido2.rins = 0;
                            insere_fim(&aux3, d_lido2);
                            break;
                        }
                        insere_fim(&aux3, d_lido2);
                    }
                    //Coloca o paciente cadastrado como beneficiado
                    strcpy(d_lido.b_rins, p_cadastrando.nome);
                    d_lido.rins = 0;
                    //Se ainda tiver algum orgao desse doador, ele volta pra lista de disponibilidade
                    if(d_lido.coracao == 1 || d_lido.figado == 1 || d_lido.rins == 1 || d_lido.pulmao == 1)
                        insere_fim(&aux2, d_lido);
                    break;
                }
            }
            //Se nao encontrou um rins, o paciente vai pra lista de espera
            if(lista_vazia(disponibilidade) == 1 && flag_doador == 0)
                insere_ord(&rins, p_cadastrando);
            //Acaba de esvaziar a lista para restaurala depois
            while(! lista_vazia(disponibilidade)){
                remove_ini_lista(&disponibilidade, &d_lido);
                insere_fim(&aux2, d_lido);
            }
            //Restaura a lista de disponibilidade
            while(! lista_vazia(aux2)){
                remove_ini_lista(&aux2, &d_lido);
                insere_fim(&disponibilidade, d_lido);
            }

            //Restaurando a lista de doadores

            while(! lista_vazia(doadores)){
                remove_ini_lista(&doadores, &d_lido2);
                insere_fim(&aux3, d_lido2);
            }

            while(! lista_vazia(aux3)){
                remove_ini_lista(&aux3, &d_lido2);
                insere_fim(&doadores, d_lido2);
            }

        }

        ///Paciente precisando de pulmao
        flag_doador = 0;
        if(strcmp(p_cadastrando.orgao, "pulmao") == 0){
            while(! lista_vazia(disponibilidade)){
                //verificando a lista de disponibilidade
                remove_ini_lista(&disponibilidade, &d_lido);
                //Se achar um pulmao disponivel
                if(d_lido.pulmao == 1){
                    flag_doador = 1;

                    //Para mudar na lista de doadores
                    while(! lista_vazia(doadores)){
                        remove_ini_lista(&doadores, &d_lido2);
                        if(strcmp(d_lido.nome, d_lido2.nome) == 0 && d_lido2.pulmao == 1){
                            strcpy(d_lido2.b_pulmao, p_cadastrando.nome);
                            d_lido2.pulmao = 0;
                            insere_fim(&aux3, d_lido2);
                            break;
                        }
                        insere_fim(&aux3, d_lido2);
                    }
                    //Coloca o paciente cadastrado como beneficiado
                    strcpy(d_lido.b_pulmao, p_cadastrando.nome);
                    d_lido.pulmao = 0;
                    //Se ainda tiver algum orgao desse doador, ele volta pra lista de disponibilidade
                    if(d_lido.coracao == 1 || d_lido.figado == 1 || d_lido.rins == 1 || d_lido.pulmao == 1)
                        insere_fim(&aux2, d_lido);
                    break;
                }
            }
            //Se nao encontrou um pulmao, o paciente vai pra lista de espera
            if(lista_vazia(disponibilidade) == 1 && flag_doador == 0)
                insere_ord(&pulmao, p_cadastrando);
            //Acaba de esvaziar a lista para restaurala depois
            while(! lista_vazia(disponibilidade)){
                remove_ini_lista(&disponibilidade, &d_lido);
                insere_fim(&aux2, d_lido);
            }

            //Restaura a lista de disponibilidade
            while(! lista_vazia(aux2)){
                remove_ini_lista(&aux2, &d_lido);
                insere_fim(&disponibilidade, d_lido);
            }

            //Restaurando a lista de doadores

            while(! lista_vazia(doadores)){
                remove_ini_lista(&doadores, &d_lido2);
                insere_fim(&aux3, d_lido2);
            }

            while(! lista_vazia(aux3)){
                remove_ini_lista(&aux3, &d_lido2);
                insere_fim(&doadores, d_lido2);
            }
        }
    }

    ///Cadastro de doadores
    if(escolha == 2){
        flag_doador = 0; //Para verificar se o doador esta com algum orgao disponivel
        printf("\n--------------------------Cadastro de doador--------------------------\n");
        printf("Nome do doador: ");
        setbuf(stdin,NULL);
        gets(d_cadastrando.nome);

        printf("Doou um coracao (s\\n), uma opcao invalida, sera considerada com \"n\": ");
        setbuf(stdin,NULL);
        scanf("%c", &info_orgao);
        if(info_orgao == 's') d_cadastrando.coracao = 1;
        else d_cadastrando.coracao = -1;

        printf("Doou uma cornea (s\\n), uma opcao invalida, sera considerada com \"n\": ");
        setbuf(stdin,NULL);
        scanf("%c", &info_orgao);
        if(info_orgao == 's') d_cadastrando.cornea = 1;
        else d_cadastrando.cornea = -1;

        printf("Doou um figado (s\\n), uma opcao invalida, sera considerada com \"n\": ");
        setbuf(stdin,NULL);
        scanf("%c", &info_orgao);
        if(info_orgao == 's') d_cadastrando.figado = 1;
        else d_cadastrando.figado = -1;

        printf("Doou um rim (s\\n), uma opcao invalida, sera considerada com \"n\": ");
        setbuf(stdin,NULL);
        scanf("%c", &info_orgao);
        if(info_orgao == 's') d_cadastrando.rins = 1;
        else d_cadastrando.rins = -1;

        printf("Doou um pulmao (s\\n), uma opcao invalida, sera considerada com \"n\": ");
        setbuf(stdin,NULL);
        scanf("%c", &info_orgao);
        if(info_orgao == 's') d_cadastrando.pulmao = 1;
        else d_cadastrando.pulmao = -1;

        printf("----------------------------------------------------------------------\n\n");

        //Se doou um coracao
        if(d_cadastrando.coracao == 1){
            result = remove_ini(&coracao, &p_lido);
            if(result == 1){
                strcpy(d_cadastrando.b_coracao, p_lido.nome);
                d_cadastrando.coracao = 0;
            }
            else
                flag_doador++;
        }else if(d_cadastrando.coracao == -1) strcpy(d_cadastrando.b_coracao, "Nao foi doado");

        //Se doou um cornea
        if(d_cadastrando.cornea == 1){
            result = remove_ini(&cornea, &p_lido);
            if(result == 1){
                strcpy(d_cadastrando.b_cornea, p_lido.nome);
                d_cadastrando.cornea = 0;
            }
            else
                flag_doador++;
        }else if(d_cadastrando.cornea == -1) strcpy(d_cadastrando.b_cornea, "Nao foi doado");

        //Se doou um figado
        if(d_cadastrando.figado == 1){
            result = remove_ini(&figado, &p_lido);
            if(result == 1){
                strcpy(d_cadastrando.b_figado, p_lido.nome);
                d_cadastrando.figado = 0;
            }
            else
                flag_doador++;
        }else if(d_cadastrando.figado == -1) strcpy(d_cadastrando.b_figado, "Nao foi doado");

        //Se doou um rim
        if(d_cadastrando.rins == 1){
            result = remove_ini(&rins, &p_lido);
            if(result == 1){
                strcpy(d_cadastrando.b_rins, p_lido.nome);
                d_cadastrando.rins = 0;
            }
            else
                flag_doador++;
        }else if(d_cadastrando.rins == -1) strcpy(d_cadastrando.b_rins, "Nao foi doado");

        //Se doou um pulmao
        if(d_cadastrando.pulmao == 1){
            result = remove_ini(&pulmao, &p_lido);
            if(result == 1){
                strcpy(d_cadastrando.b_pulmao, p_lido.nome);
                d_cadastrando.pulmao = 0;
            }
            else
                flag_doador++;
        }else if(d_cadastrando.pulmao == -1) strcpy(d_cadastrando.b_pulmao, "Nao foi doado");


        if(flag_doador != 0)
            insere_fim(&disponibilidade, d_cadastrando);
        insere_fim(&doadores, d_cadastrando);
    }

    ///Fila de Pacientes
    if(escolha == 3){
        printf("\n-----------------------Fila de pacientes-----------------------\n");
        i = 1;
        printf("\n**Coracao: ");
        if(fila_vazia(coracao) == 1) printf("Ninguem.\n");
        else{
            do{
                remove_ini(&coracao, &p_lido);
                insere_ord(&aux, p_lido);
                printf("\n   Paciente %d -> ", i);
                printf("%s, ", p_lido.nome);
                printf("possui %d anos, ", p_lido.idade);
                printf("precisa de %s, ", p_lido.orgao);
                printf("com urgencia de grau %d.\n", p_lido.gravidade);
                i++;
            }while(fila_vazia(coracao) == 0);
            while(fila_vazia(aux) == 0){
                remove_ini(&aux, &p_lido);
                insere_ord(&coracao, p_lido);
            }

        }

        i = 1;
        printf("\n**Cornea: ");
        if(fila_vazia(cornea) == 1) printf("Ninguem.\n");
        else{
            do{
                remove_ini(&cornea, &p_lido);
                insere_ord(&aux, p_lido);
                printf("\n   Paciente %d -> ", i);
                printf("%s, ", p_lido.nome);
                printf("possui %d anos, ", p_lido.idade);
                printf("precisa de %s, ", p_lido.orgao);
                printf("com urgencia de grau %d.\n", p_lido.gravidade);
                i++;
            }while(fila_vazia(cornea) == 0);
            while(fila_vazia(aux) == 0){
                remove_ini(&aux, &p_lido);
                insere_ord(&cornea, p_lido);
            }
        }

        i = 1;
        printf("\n**Figado: ");
        if(fila_vazia(figado) == 1) printf("Ninguem.\n");
        else{
            do{
                remove_ini(&figado, &p_lido);
                insere_ord(&aux, p_lido);
                printf("\n   Paciente %d -> ", i);
                printf("%s, ", p_lido.nome);
                printf("possui %d anos, ", p_lido.idade);
                printf("precisa de %s, ", p_lido.orgao);
                printf("com urgencia de grau %d.\n", p_lido.gravidade);
                i++;
            }while(fila_vazia(figado) == 0);
            while(fila_vazia(aux) == 0){
                remove_ini(&aux, &p_lido);
                insere_ord(&figado, p_lido);
            }
        }
        i = 1;
        printf("\n**Rins: ");
        if(fila_vazia(rins) == 1) printf("Ninguem.\n");
        else{
            do{
                remove_ini(&rins, &p_lido);
                insere_ord(&aux, p_lido);
                printf("\n   Paciente %d -> ", i);
                printf("%s, ", p_lido.nome);
                printf("possui %d anos, ", p_lido.idade);
                printf("precisa de %s, ", p_lido.orgao);
                printf("com urgencia de grau %d.\n", p_lido.gravidade);
                i++;
            }while(fila_vazia(rins) == 0);
            while(fila_vazia(aux) == 0){
                remove_ini(&aux, &p_lido);
                insere_ord(&rins, p_lido);
            }
        }
        i = 1;
        printf("\n**Pulmao: ");
        if(fila_vazia(pulmao) == 1) printf("Ninguem.\n");
        else{
            do{
                remove_ini(&pulmao, &p_lido);
                insere_ord(&aux, p_lido);
                printf("\n   Paciente %d -> ", i);
                printf("%s, ", p_lido.nome);
                printf("possui %d anos, ", p_lido.idade);
                printf("precisa de %s, ", p_lido.orgao);
                printf("com urgencia de grau %d.\n", p_lido.gravidade);
                i++;
            }while(fila_vazia(pulmao) == 0);
            while(fila_vazia(aux) == 0){
                remove_ini(&aux, &p_lido);
                insere_ord(&pulmao, p_lido);
            }
        }
    }

    ///Fila de disponibilidade

    if(escolha == 4){
        i = 1;
        printf("\n-----------------------Fila de disponibilidade-----------------------\n");
        if(lista_vazia(disponibilidade) == 1) printf("Nao ha nenhum orgao armazenado.\n");

        while(! lista_vazia(disponibilidade)){
            remove_ini_lista(&disponibilidade, &d_lido);
            insere_ini(&aux2, d_lido);
            printf("   Doador %d -> ", i);
            printf("%s, ", d_lido.nome);
            printf("orgaos que ainda nao foram doados: ");
            if(d_lido.coracao == 1) printf("coracao; ");
            if(d_lido.cornea == 1) printf("cornea; ");
            if(d_lido.figado == 1) printf("figado; ");
            if(d_lido.rins == 1) printf("rins; ");
            if(d_lido.pulmao == 1) printf("pulmao;");
            printf("\n");
            i++;
        }
        while(! lista_vazia(aux2)){
            remove_ini_lista(&aux2, &d_lido);
            insere_fim(&disponibilidade, d_lido);
        }
        printf("\n---------------------------------------------------------------------\n");
    }

    ///Fila de doadores

    if(escolha == 5){
        i = 1;
        printf("\n--------------------------Fila de doadores--------------------------\n");
        if(lista_vazia(doadores) == 1) printf("Nenhum orgao foi doado ainda.\n");
        while(! lista_vazia(doadores)){
            remove_ini_lista(&doadores, &d_lido);
            insere_fim(&aux2, d_lido);
            printf("*Doador %d: ", i);
            printf("%s\n", d_lido.nome);

            if(d_lido.coracao == 1) printf("   Coracao: disponivel.\n");
            else if(d_lido.coracao == -1) printf("   Coracao: %s\n", d_lido.b_coracao);
            else printf("   Coracao recebido por: %s\n", d_lido.b_coracao);

            if(d_lido.cornea == 1) printf("   Cornea: disponivel.\n");
            else if(d_lido.cornea == -1) printf("   Cornea: %s\n", d_lido.b_cornea);
            else printf("  Cornea recebido por: %s\n", d_lido.b_cornea);

            if(d_lido.figado == 1) printf("   Figado: disponivel.\n");
            else if(d_lido.figado == -1) printf("   Figado: %s\n", d_lido.b_figado);
            else printf("   Figado recebido por: %s\n", d_lido.b_figado);

            if(d_lido.rins == 1) printf("   Rim: disponivel.\n");
            else if(d_lido.rins == -1) printf("   Rim: %s\n", d_lido.b_rins);
            else printf("   Rim recebido por: %s\n", d_lido.b_rins);

            if(d_lido.pulmao == 1) printf("   Pulmao: disponivel.\n");
            else if(d_lido.pulmao == -1) printf("   Pulmao: %s\n", d_lido.b_pulmao);
            else printf("   Pulmao recebido por: %s\n", d_lido.b_pulmao);
            i++;
            printf("\n");
        }

        while(! lista_vazia(aux2)){
            remove_ini_lista(&aux2, &d_lido);
            insere_fim(&doadores, d_lido);
        }

    }
    }while(escolha != 6);

    return 0;
}
