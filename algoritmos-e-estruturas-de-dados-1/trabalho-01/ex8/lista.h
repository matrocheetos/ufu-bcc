typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord (Lista lst, int coefi, int potencia);
int remove_ord (Lista lst, int potencia);
void imprime_lista(Lista lst);
void reinicializa_lista(Lista *lst);
int calcula_p(Lista lst, int p);
