## lista estatica/sequencial:

- implementada através de um vetor, posições consecutivas;
- desvantagem: movimentação de elementos, super ou subestimação;
- recomendação: listas pequenas, tamanho pré-definido, muitas consultas, inserção e remoção no fim da lista;

- exemplo:
```c
struct lista{
    int no[max];
    int fim;
};

-> cria_lista()
-> lista_vazia()
    //verifica se lista está vazia, lista.fim=0;
```

- **lista não ordenada**:
    - insere na ordem de chegada no final da lista; insere_elem()
    - lista não pode estar cheia
- **lista ordenada**:
    - mantem a lista ordenada, envolve percorrimento da lista; insere_ord()
    - 5 casos possiveis:
        1. lista cheia
        2. lista vazia
        3. novo elemento < 1º
        4. novo elemento >= ultimo
        5. novo elemento entre o 1º e o último

