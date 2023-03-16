typedef struct lista *lista;

lista cria_lista();
int lista_vazia(lista lst);
int lista_cheia(lista lst);
int insere_ord(lista lst, int elem);
int remove_ord(lista lst, int elem);
int esvaziar(lista lst);
int maior(lista p);
int remove_pares(lista p);
int tamanho(lista p);
int intercala(lista a,lista b, lista c);
void imprime_lista(lista lst);
