typedef struct lista *Lista;
typedef struct lista Elemento;

Lista* inicializar_lista();
int lista_vazia(Lista* ls);
int lista_cheia();
int insere_ord(Lista* ls, int elemento);
int remove_ord(Lista* ls, int elemento, int opcao);
int get_pos(Lista* ls, int posicao, int *informacao);