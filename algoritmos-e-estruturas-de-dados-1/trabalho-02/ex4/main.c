#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <time.h>

typedef struct caixa{
    int tempo_de_atendimento;
    int tempo_previsto;
    int disponivel; // 1 aberto, 0 fechado, -1 fecha quando possivel
}Caixa;

int main(){
    srand(time(NULL));

    ///Variaveis
    Fila f, aux;
    int qtd_inserida, i, caixas_abertos,result, tempo_dos_ultimos_clientes[5], at_dos_ultimos_clientes[5], contador_clientes, escolha, tempo, menor;
    float media_de_espera, media_at;
    struct tm *atual;
    time_t segundos;
    struct cliente elem;
    int cont2 = 0;

    Caixa caixas[8];

    ///Inicializacao de variaveis
    f = cria_fila();
    aux = cria_fila();
    if(f == NULL || aux == NULL) exit(-1);
    caixas_abertos = 1;
    contador_clientes = 0;
    media_de_espera = 0;
    media_at = 0;
    for(i = 0; i < 8; i++){
        caixas[i].tempo_de_atendimento = 0;
        caixas[i].tempo_previsto = 0;
        caixas[i].disponivel = 0;
    }
    tempo = 0;
    caixas[0].disponivel  = 1;

    ///Menu
    do{
        printf("*************MENU***************\n");
        printf("TEMPO: %d\n", tempo);
        printf("1) Simulador de fila.\n");
        printf("2) Simulador de tempo.\n");
        printf("3) Visualizador de cenario.\n");
        printf("4) Sair.\n");
        printf("Escolha: ");
        scanf("%d", &escolha);
        if(escolha < 1 || escolha > 4){
            while(escolha < 1 || escolha > 4 ){
                printf("Escolha inv%clida, tente outra: ",160);
                scanf("%d", &escolha);
            }
        }

        switch(escolha){

            case 1:{
                ///Simulador de fila
                    printf("Quantidade de clientes que ser%co inseridos na fila: ", 198);
                    scanf("%d", &qtd_inserida);


                    for(i = 0; i < qtd_inserida; i++){
                        //Novo elemento tera os dados da horário do sistema
                        time(&segundos);
                        atual = localtime(&segundos);
                        elem.hora_entrada = atual->tm_hour;
                        elem.minuto_entrada = atual->tm_min;
                        elem.segundo_entrada = atual->tm_sec;
                        elem.tempo_de_espera = 0;
                        //Um numero aleatorio de 2 à 10
                        elem.tempo_de_atendimento = 2 + (rand() % 9);
                        result = insere_fim(f, elem);
                        if(result == 0){
                            printf("\nERRO\n");
                            exit(1);
                        }
                    }
                    printf("\nSimula%c%co feita com sucessso.\n\n", 135,198);
                    break;
            }
            case 2:{
                 /// Simulador de tempo
                    for(i = 0; i < 8; i++){
                        //Atende e já chama o proximo cliente
                        if(caixas[i].disponivel == 1){
                            if(caixas[i].tempo_de_atendimento == caixas[i].tempo_previsto){
                                if(caixas[i].tempo_de_atendimento!=0 && caixas[i].tempo_previsto!=0){
                                    at_dos_ultimos_clientes[cont2 % 5] = caixas[i].tempo_previsto;
                                    cont2++;
                                }
                                result = remove_inicio(f, &elem);
                                if(result == 1){
                                    tempo_dos_ultimos_clientes[contador_clientes % 5] = elem.tempo_de_espera;
                                    contador_clientes++;
                                    caixas[i].tempo_de_atendimento = 0;
                                    caixas[i].tempo_previsto = elem.tempo_de_atendimento;
                                }else{
                                    caixas[i].tempo_de_atendimento = 0;
                                    caixas[i].tempo_previsto = 0;
                                }
                            }else caixas[i].tempo_de_atendimento++;
                        }
                        //Fecha o caixa quando o atendimento atual acabar
                        if(caixas[i].disponivel == -1){
                            if(caixas[i].tempo_de_atendimento == caixas[i].tempo_previsto){
                                caixas[i].tempo_de_atendimento = 0;
                                caixas[i].tempo_previsto = 0;
                                caixas[i].disponivel = 0;
                            }else caixas[i].tempo_de_atendimento++;
                        }
                    }

                    while(fila_vazia(f) != 1){
                        remove_inicio(f, &elem);
                        elem.tempo_de_espera++;
                        insere_fim(aux, elem);
                    }

                    while(fila_vazia(aux) != 1){
                        remove_inicio(aux,&elem);
                        insere_fim(f, elem);
                    }

                    tempo++;


                    ///Otimizador de caixas
                    if(contador_clientes > 0){
                        media_de_espera = 0;
                        if(contador_clientes < 5){
                            for(i = 0; i < contador_clientes; i++){
                                media_de_espera = media_de_espera + tempo_dos_ultimos_clientes[i];
                            }
                            media_de_espera = media_de_espera/contador_clientes;
                        }else{
                            for(i = 0; i < 5; i++){
                                media_de_espera = media_de_espera + tempo_dos_ultimos_clientes[i];
                            }
                            media_de_espera = media_de_espera/5;
                        }
                    }


                    if(media_de_espera >= (0.9*30) && tamanho(f) >= (0.8*15) && caixas_abertos < 8){
                        for(i = 0; i < 8; i++){
                            if(caixas[i].disponivel == 0){
                                caixas[i].disponivel = 1;
                                break;
                                }
                        }
                    caixas_abertos++;
                    }

                    if(media_de_espera <= (0.6*30) && tamanho(f) <= (0.6*15) && caixas_abertos > 1){
                        menor = 0;
                        for(i = 1; i < 8; i++){
                            //Tempo restante de i menor que o tempo restante de menor
                            if((caixas[i].tempo_previsto - caixas[i].tempo_de_atendimento) < (caixas[menor].tempo_previsto - caixas[menor].tempo_de_atendimento) && caixas[i].disponivel != 0)
                                menor = i;
                        }
                        //Muda o status do caixa q esta mais proximo de encerrar o atendimento, para fechar quando esse atendimento acabar
                        caixas[menor].disponivel = -1;
                        caixas_abertos--;
                    }
                    break;
            }
            case 3:{
                ///Visualizador de cenario
                    //Calcular a media de espera

                    if(cont2 > 0){
                        media_at = 0;
                        if(cont2 < 5){
                            for(i = 0; i < cont2; i++){
                                media_at = media_at + at_dos_ultimos_clientes[i];
                            }
                            media_at = media_at/cont2;
                        }else{
                            for(i = 0; i < 5; i++){
                                media_at = media_at + at_dos_ultimos_clientes[i];
                            }
                            media_at = media_at/5;
                        }
                    }

                    if(contador_clientes > 0){
                        media_de_espera = 0;
                        if(contador_clientes < 5){
                            for(i = 0; i < contador_clientes; i++){
                                media_de_espera = media_de_espera + tempo_dos_ultimos_clientes[i];
                            }
                            media_de_espera = media_de_espera/contador_clientes;
                        }else{
                            for(i = 0; i < 5; i++){
                                media_de_espera = media_de_espera + tempo_dos_ultimos_clientes[i];
                            }
                            media_de_espera = media_de_espera/5;
                        }
                    }

                    printf("-----Informa%c%ces gerais------\n\n", 135, 228);
                    printf("Caixas abertos: %d   \n", caixas_abertos);
                    printf("Tempo m%cdio de espera dos ultimos 5 clientes: %.2f   \n", 130, media_de_espera);
                    printf("Tempo m%cdio de atendimento dos ultimos 5 clientes: %.2f   \n", 130, media_at);
                    printf("Quantidade de pessoas na fila: %d\n", tamanho(f));

                    printf("\n\n-----Situa%c%co dos caixas-----\n\n",135,198);
                    for(i = 0; i < 8; i++){
                        if(caixas[i].disponivel == 1){
                            printf("\nCaixa %d -> ", i+1);
                            printf("Tempo de atendimento: %d   ", caixas[i].tempo_de_atendimento);
                            printf("Tempo previsto: %d   ", caixas[i].tempo_previsto);
                            printf("Tempo restante: %d", caixas[i].tempo_previsto - caixas[i].tempo_de_atendimento);
                        }else{
                            if(caixas[i].disponivel == -1){
                            printf("\nCaixa %d (fecha depois desse cliente) -> ", i+1);
                            printf("Tempo de atendimento: %d   ", caixas[i].tempo_de_atendimento);
                            printf("Tempo previsto: %d   ", caixas[i].tempo_previsto);
                            printf("Tempo restante: %d", caixas[i].tempo_previsto - caixas[i].tempo_de_atendimento);
                            }else{
                                printf("\nCaixa %d -> FECHADO", i+1);
                            }
                        }

                    }

                    if(fila_vazia(f) != 1){
                        printf("\n\n-----------Fila--------------\n");
                        i = 1;
                    }
                    else
                        printf("\n\nA fila est%c vazia.\n",160);

                    while(fila_vazia(f) != 1){
                        remove_inicio(f, &elem);
                        insere_fim(aux, elem);
                        printf("Cliente %d ->   ", i);
                        printf("Horario de chegada: ");
                        if(elem.hora_entrada < 10) printf("0");
                        printf("%d:", elem.hora_entrada);
                        if(elem.minuto_entrada < 10) printf("0");
                        printf("%d:", elem.minuto_entrada);
                        if(elem.segundo_entrada < 10) printf("0");
                        printf("%d   ", elem.segundo_entrada);
                        printf("Tempo de espera: %d   ", elem.tempo_de_espera);
                        printf("Tempo de atendimento previsto: %d\n\n", elem.tempo_de_atendimento);
                        i++;
                    }
                    while(fila_vazia(aux) != 1){
                        remove_inicio(aux, &elem);
                        insere_fim(f, elem);
                    }

                    break;

            }
        }

    }while(escolha != 4);

    return 0;
}
