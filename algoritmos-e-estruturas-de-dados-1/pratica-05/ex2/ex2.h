struct aluno{
    unsigned int matricula;
    char nome[20];
    float media;
    int faltas;
};

typedef struct lista *Lista;
typedef struct lista Elemento;

Lista* inicializar_lista();
int lista_vazia(Lista* ls);
int lista_cheia();
int insere_elem(Lista* ls, struct aluno registro);
int remove_elem(Lista* ls, unsigned int matricula);
int get_pos(Lista* ls, int posicao, struct aluno* dados);
int size_lista(Lista* ls);