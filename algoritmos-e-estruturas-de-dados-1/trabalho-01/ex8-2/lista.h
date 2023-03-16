//ex8
typedef struct lista *Lista;
typedef struct lista Elemento;

Lista* cria_lista();
int lista_vazia(Lista *ls);
int insere_ord(Lista *ls, int a, int k);
int remove_ord(Lista *ls, int k);
int obtem_elem(Lista *ls, int posicao, int *a, int *k);
int calcular_Px(Lista *ls, int x);
