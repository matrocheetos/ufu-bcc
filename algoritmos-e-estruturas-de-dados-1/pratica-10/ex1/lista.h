typedef struct lista Lista;
typedef union{float i_float; char i_char;} Union;

Lista* criar_lista(int tipo);
int lista_vazia(Lista* ls);
int lista_cheia(Lista* ls);
int insere_elem(Lista* ls, Union info);
int remove_elem(Lista* ls, Union info);
int obtem_elem_pos(Lista* ls, int posicao, Union *info);

// union{
//     float i_float;
//     char i_char;
// }info[MAX];