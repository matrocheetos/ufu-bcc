struct paciente{
    char nome[50];
    int idade;
    char orgao[8];
    int gravidade;
};
typedef struct no *Fila;

Fila cria_fila();
int fila_vazia(Fila f);
int insere_ord(Fila *f, struct paciente elem);
int remove_ini(Fila *f, struct paciente *elem);
int esvazia_fp(Fila *lst);
