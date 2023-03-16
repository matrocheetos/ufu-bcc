typedef struct lista Lista;

Lista* inicializar_lista();
int lista_vazia(Lista* l);
int lista_cheia(Lista* l);
int insere_elem(Lista *l, char texto[40]);
int remove_elem(Lista *l, char texto[40]);
char* get_pos(Lista *l, int posicao);