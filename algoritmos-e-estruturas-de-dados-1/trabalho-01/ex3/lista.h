typedef struct no *lista;

lista cria_lista();
int lista_vazia(lista lst);
int insere_ord(lista *lst,double elem);
int remove_ord(lista *lst,double elem);
void imprime_lista(lista lst);
int tamanho(lista *lst);
int maior(lista p);
int iguais(lista a,lista b);
int intercala(lista a, lista b,lista *c);
int esvaziar(lista *lst);
