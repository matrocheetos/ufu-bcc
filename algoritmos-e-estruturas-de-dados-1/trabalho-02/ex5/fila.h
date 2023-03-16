typedef struct aluno aluno;
typedef struct fila *fila;
fila cria_fp();
int fp_vazia(fila f);
int fp_cheia(fila f);
int insere_fim(fila f, char nome[50], int matricula, int cg, int ano, float cra);
int remove_ord(fila f, char nome[50], int *matricula,int *cg, int *ano, float *cra);
int esvazia_fp(fila f);
