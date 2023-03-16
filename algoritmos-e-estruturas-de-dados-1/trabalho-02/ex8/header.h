typedef struct deque *Deque;
Deque cria_deque();
int deque_vazio(Deque d);
int insere_ini(Deque *d, double elem);
int insere_fim(Deque *d, double elem);
int remove_ini(Deque *d, double *elem);
int remove_fim (Deque *d, double *elem);
void libera_deque(Deque *d);
