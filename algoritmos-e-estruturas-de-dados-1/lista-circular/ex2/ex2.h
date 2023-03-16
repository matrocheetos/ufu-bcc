typedef struct lista *Lista;
typedef struct lista Elemento;

Lista* criar_lista();
int lista_vazia(Lista* ls);
int insere_inicio(Lista* ls, int elemento);
int remove_final(Lista* ls, int elemento);
int obtem_valor_elem(Lista* ls, int posicao, int *informacao);