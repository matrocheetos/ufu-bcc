typedef struct lista Lista;

Lista* criar_lista();
int lista_vazia(Lista* l);
int lista_cheia(Lista* l);
void insere_elem(Lista* l, float nro);
int remove_elem(Lista* l, float nro);
void limpa_lista(Lista* l);
float get_posicao(Lista* l, int posicao);