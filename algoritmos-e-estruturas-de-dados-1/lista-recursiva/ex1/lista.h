typedef struct lista *Lista;
typedef struct lista Elemento;

Lista* cria_lista();
int lista_vazia(Lista* ls);
int insere_ord(Lista* ls, double elemento);
int remove_ord(Lista* ls, double elemento);
int obtem_elem(Lista* ls, int posicao, double *info);