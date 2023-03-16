struct dados{
    char info[11];
};

typedef struct fila Fila;

Fila* criar_fila();
int fila_vazia(Fila* fila);
int fila_cheia(Fila* fila);
int insere_fim(Fila* fila, char insere[10]);
int remove_ini(Fila* fila);
int get_elem(Fila *fila, int posicao, struct dados *elemento);