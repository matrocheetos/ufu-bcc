typedef struct lista *Lista;
typedef struct lista Elemento;

Lista* criar_lista();
int lista_vazia(Lista* ls);
int lista_cheia();
int insere_elem(Lista* ls, char elemento);
int remove_elem(Lista *ls, char elemento);
char obtem_posicao(Lista *ls, int verif);
void limpa_lista(Lista *ls);