typedef struct lista *Lista;
typedef struct lista Elemento;

Lista* criar_lista(int tipo);
int lista_vazia(Lista* ls);
int insere_elem(Lista* ls, float info_f, char info_c);
int remove_elem(Lista* ls, float info_f, char info_c);
int obtem_elem_pos(Lista* ls, int posicao, float *info_f, char *info_c);