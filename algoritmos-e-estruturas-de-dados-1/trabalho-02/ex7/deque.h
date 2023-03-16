typedef struct deque *deque;
deque cria_deque();
int deque_vazio(deque d);
int deque_cheio(deque d);
int insere_ini(deque d,int elem);
int insere_fim(deque d,int elem);
int remove_ini(deque d, int *elem);
int remove_fim(deque d, int *elem);
void libera_deque(deque d);

