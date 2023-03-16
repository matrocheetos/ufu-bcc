typedef struct lista *Lista;
typedef struct lista Elemento;

Lista* criar_lista();
int lista_vazia(Lista* ls);
int insere_elemento(Lista* ls, int info);
int remove_elemento(Lista* ls, int info);
int obtem_valor_elem(Lista* ls, int posicao, int *info);