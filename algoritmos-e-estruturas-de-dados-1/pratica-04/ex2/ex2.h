typedef struct lista Lista;
typedef struct bebida Bebida;

Lista* inicializar_lista();
int lista_vazia(Lista* l);
int lista_cheia(Lista* l);
int insere_ord(Lista *l, char nome[40], int volume, float preco);
int remove_ord(Lista *l, char nome[40]);
void get_pos(Lista *l, int posicao, char infoNome[], int* infoVol, float* infoPreco);
int get_tamanho(Lista *l);