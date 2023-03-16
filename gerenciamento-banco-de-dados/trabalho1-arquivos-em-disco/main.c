#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//variavel global com o caminho para o arquivo
char caminho[60] = "D:\\trabalhoGBD\\registros.txt";

static const int tamanho_text = 46;

struct registro {
    int nseq;
    char text[46];
};

int rand_int(){
    int numero = 0;
    for(int i = 0; i < 9; i++){
        int aux = rand() % 10;
        numero += aux * pow(10,i);
    }
    return numero;
}

//gera uma string aleatoria de tamanho 'tam'
void random_string(char * string, int tam){
    static const char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < tam; ++i) {
        string[i] = letras[rand() % (sizeof(letras) - 1)];
    }

    string[tam] = '\0';
}

//cria o arquivo com n_reg registros inicias
FILE* create_heap_file (int n_reg){
    int i, aux= 1000000;
    struct registro registros;

    FILE *f;
    f = fopen(caminho, "wb");
    if(f == NULL){
        printf("Erro ao criar o arquivo!\n");
    }

    for(i = 1; i <= n_reg; i ++){
        random_string(registros.text, tamanho_text);
        registros.nseq = i;

        fwrite(&registros.nseq, sizeof(int), 1, f);
        fwrite(registros.text, tamanho_text, 1, f);

        if(i == aux){
            aux = aux + 1000000;
            printf("registros.nseq: %d\nn_reg: %d\n", registros.nseq, i);
        }

    }
    fclose(f);
    return f;
}

//procura um registro pelo nseq e imprime a tela
void read_random(FILE * f, int nseq){
    struct registro registros;

    f = fopen(caminho, "rb");

    long long int deslocamento = (nseq - 1) * 50LL;

    fseeko64(f, deslocamento, SEEK_SET);

    fread(&registros.nseq, sizeof(int), 1, f);
    fread(&registros.text, tamanho_text, 1, f);

    if(nseq == registros.nseq){
        printf("%d %s\n", registros.nseq, registros.text);
    }else{
        printf("Nao existe registro valido com esse nseq!\n");
    }
}

FILE * isrt_at_end(FILE * f, int * n_reg){
    struct registro registros;

    f = fopen(caminho, "ab");

    *n_reg = *n_reg + 1;

    random_string(registros.text, tamanho_text);
    registros.nseq = *n_reg;

    fwrite(&registros.nseq, sizeof(int), 1, f);
    fwrite(registros.text, tamanho_text, 1, f);

    printf("%d %s", registros.nseq, registros.text);


    fclose(f);
    return f;
}

void update_random(FILE * f, int nseq, char * new_text){
    struct registro registros;
    long long int deslocamento = (nseq - 1) * 50;
    f = fopen(caminho, "r+b");

    fseeko64(f, deslocamento, SEEK_SET);

    fread(&registros.nseq, sizeof(int), 1, f);
    fread(&registros.text, tamanho_text, 1, f);

    if(nseq == registros.nseq){
        printf("%d %s\n", registros.nseq, registros.text);

        fseeko64(f, deslocamento, SEEK_SET);

        printf("%d %s\n", nseq, new_text);

        fwrite(&nseq, sizeof(int), 1, f);
        fwrite(new_text, tamanho_text, 1, f);

    }else{
        printf("Nao existe registro com esse nseq!\n");
    }

    fclose(f);
}

void delete_random(FILE * f, int nseq){
    struct registro registros;
    long long int deslocamento = (nseq - 1) * 50;

    f = fopen(caminho, "r+b");

    fseeko64(f, deslocamento, SEEK_SET);

    fread(&registros.nseq, sizeof(int), 1, f);
    fread(&registros.text, tamanho_text, 1, f);


    if(nseq == registros.nseq){
        printf("%d %s\n", registros.nseq, registros.text);
        fseeko64(f, deslocamento, SEEK_SET);

        nseq = nseq * (-1);
        printf("%d %s\n", nseq, registros.text);

        fwrite(&nseq, sizeof(int), 1, f);
        fwrite(registros.text, tamanho_text, 1, f);

    }else{
        printf("Nao existe registro valido com esse nseq!\n");
    }

    fclose(f);
}

void leitura_seq(FILE *f, int tam_pagina){
    void * registro = malloc(tam_pagina * 50);
    int registros_lidos, reg_validos = 0, blocos_lidos = 0;
    if(registro == NULL){
        printf("Falha da alocacao do vetor!\n");
    }

    f = fopen(caminho, "rb");

    clock_t start = clock();
    while(feof(f) == 0){
        registros_lidos = fread(registro, 50, tam_pagina, f);
        blocos_lidos++;
        for(int i = 0; i < registros_lidos; i++){
            int *nseq = (int *) (registro + i * 50);
            char text[46], *c;

            c = (char *)(registro + i*50 + 7);
            for(int j = 0; j < tamanho_text; j++)
                text[j] = c[j];
            text[45] = '\0';

            if(*nseq > 0)
                reg_validos++;
            //if(i == registros_lidos-1)
            //    printf("%d %s\n", *nseq, text);
        }
    }
    clock_t end = clock();
    double tempo = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Registros validos: %d\nBlocos lidos: %d\nTempo de processamento: %lf", reg_validos, blocos_lidos, tempo);
}

void leitura_rand(FILE *f, int n_reg){
    setbuf(stdin, NULL);
    int nro_leitura = ceil((float) n_reg/100), nro_validos = 0, nro_invalidos = 0;
    printf("Numeros de registros a serem lidos: %d\nENTER p/ confirmar", nro_leitura);
    getchar();
    struct registro registros;

    f = fopen(caminho, "rb");

    clock_t start = clock();

    for(int i = 0; i < nro_leitura; i++){
        int nseq = (rand_int() % n_reg) + 1;
        long long int deslocamento = (nseq - 1) * 50LL;

        fseeko64(f, deslocamento, SEEK_SET);

        fread(&registros.nseq, sizeof(int), 1, f);
        fread(&registros.text, tamanho_text, 1, f);

        if(i%1000 == 0){
            printf("Iteracao do contador: %d\n", i+1);
            clock_t end = clock();
            double tempo = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Registros validos: %d\nRegistro invalidos: %d\nTempo de processamento: %lf\n---- // ----\n", nro_validos, nro_invalidos, tempo);
        }

        if(nseq == registros.nseq){
            nro_validos++;
        }else{
           nro_invalidos++;
        }

    }

}

int main()
{
    int n_reg;
    struct registro registros;
    char opcao;

    srand(time(NULL));

    printf("Numero de registros a serem criados: "); // -1 mantem o registro antigo
    //para 8gb de ram o numero deve ser 858.993.460
    scanf("%d", &n_reg);

    FILE * f;
    if(n_reg >= 0){
        f = create_heap_file(n_reg);
    }

    n_reg = 858993460;
    do{
        setbuf(stdin, NULL);
        printf("\n[1]Buscar um registros pelo nseq\n");
        printf("[2]Adicionar um registro ao final do arquivo\n");
        printf("[3]Atualizar um registro pelo nseq\n");
        printf("[4]Deletar um registro pelo nseq\n");
        printf("[5]Verificar registros validos por leitura sequencial\n");
        printf("[6]Verificar registros validos por leitura aleatoria\n");
        printf("[0]Encerrar programa\n");
        printf("Sua opcao: ");
        opcao = getchar();

        switch(opcao){
            case '1':
                printf("\nNSEQ do registro que deseja consultar: ");
                scanf("%d", &registros.nseq);
                read_random(f, registros.nseq);
                break;
            case '2':
                isrt_at_end(f, &n_reg);
                break;
            case '3':
                printf("\nNSEQ do registro que deseja atualizar: ");
                scanf("%d", &registros.nseq);

                random_string(registros.text, tamanho_text);

                update_random(f, registros.nseq, registros.text);

                break;

            case '4':
                printf("\nNSEQ do registro que deseja deletar: ");
                scanf("%d", &registros.nseq);

                delete_random(f, registros.nseq);

                break;
            case '5':
                printf("\nTamanho do bloco a ser lido: ");
                scanf("%d", &registros.nseq);

                leitura_seq(f, registros.nseq);

                break;
            case '6':
                leitura_rand(f, n_reg);

                break;
            default:
                break;

        }
    }while(opcao != '0');

    return 0;
}
