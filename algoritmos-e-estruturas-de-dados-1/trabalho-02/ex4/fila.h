struct cliente{
    int hora_entrada, minuto_entrada, segundo_entrada;
    int tempo_de_atendimento;
    int tempo_de_espera;
};

typedef struct fila *Fila;

Fila cria_fila();
int fila_vazia(Fila f);
int insere_fim(Fila f, struct cliente elem);
int remove_inicio(Fila f, struct cliente *elem);
int tamanho(Fila f);

