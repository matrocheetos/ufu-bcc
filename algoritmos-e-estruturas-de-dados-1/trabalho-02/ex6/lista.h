struct doador{
    char nome[20];
    //0 se doado, 1 se disponivel, -1 se nao foi doado
    short int coracao, cornea, figado, rins, pulmao;
    char b_coracao[50], b_cornea[50], b_figado[50], b_rins[50], b_pulmao[50];
};

typedef struct node *Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ini(Lista *lst, struct doador elem);
int insere_fim(Lista *lst, struct doador elem);
int remove_fim(Lista *lst, struct doador *elem);
int remove_ini_lista(Lista *lst, struct doador *elem);

