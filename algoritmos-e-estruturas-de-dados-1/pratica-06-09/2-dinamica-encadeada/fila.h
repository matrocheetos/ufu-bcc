struct bebida{
    char nome[15];
    int volume;
    float preco;
};

typedef struct fila Fila;

Fila* criar_fila();
int fila_vazia(Fila* fila);
int fila_cheia(Fila* fila);
int insere_fim(Fila* fila, struct bebida elemento);
int remove_ini(Fila *fila);
void apaga_fila(Fila* fila);
void esvazia_fila(Fila* fila);
void imprime_fila(Fila* fila);