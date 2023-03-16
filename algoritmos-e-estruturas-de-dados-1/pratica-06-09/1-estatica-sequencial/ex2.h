struct aluno{
    int matricula,faltas;
    char nome[50];
    float media;
};

typedef struct fila Fila;

Fila* criar_fila();
int fila_vazia(Fila* fila);
int fila_cheia(Fila* fila);
int insere_fim(Fila* fila, struct aluno insere);
int remove_ini(Fila* fila);
int get_elem(Fila *fila, int posicao, struct aluno *elemento);