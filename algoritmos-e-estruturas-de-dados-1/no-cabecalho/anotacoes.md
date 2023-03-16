# nó cabeçalho

- primeira posicao da lista, ou vazio ou guarda qtd de posicoes, etc
- aponta sempre pro nó cabeçalho, posicao fixa na memória

---
## ordenadas:

- insercao sem cabeçalho com passagem por referencia:

```c
int insere_ord(Lista *ls, int elemento){
    Lista insere = (Lista) malloc(sizeof(Elemento));
    if(insere==NULL)
        return 0;

    insere->info = elemento;
    if(lista_vazia(*ls) || elemento <= (*ls)->info){
        insere->prox = *ls;
        (*ls) = insere;
        return 1;
    }
    Lista aux = *ls;
    while(aux->prox != NULL && aux->prox->info < elemento)
        aux = aux->prox; //avança

    //insere novo nó na lista
    insere->prox = aux->prox;
    aux->prox = insere;
    return 1;
}
```

- insercao com cabeçalho sem passagem por referencia:

```c
int insere_ord(Lista ls, int elemento){
    Lista insere = (Lista) malloc(sizeof(Elemento));
    if(insere==NULL)
        return 0;

    insere->info = elemento;

    Lista aux = ls;
    while(aux->prox != NULL && aux->prox->info < elemento)
        aux = aux->prox; //avança

    //insere novo nó na lista
    insere->prox = aux->prox;
    aux->prox = insere;
    ls->info++; //incrementa nós da lista
    return 1;
}
```

- remocao COM cabeçalho:

```c
int remove_elem(Lista ls, int elemento){
    if(lista_vazia(ls)==1)
        return 0;
    Lista remove = ls;

    while(remove->prox != NULL && remove->prox->info < elemento)
        remove=remove->prox;
    if(remove->prox == NULL || remove->prox->info > elemento)
        return 0;

    Lista remove2 = remove->prox;
    remove->prox = remove2->prox;
    free(remove2);
    ls->info--;
    return 1;
}
```

- remocao SEM cabeçalho:

```c
int remove_elem(Lista *ls, int elemento){
    if(lista_vazia(*ls)==1 || elemento<(*ls)->info)
        return 0;
    Lista remove = ls;

    if(elemento==(*ls)->info){
        *ls = remove->prox;
        free(remove);
        return 1;
    }
    while(remove->prox != NULL && remove->prox->info < elemento)
        remove=remove->prox;
    if(remove->prox == NULL || remove->prox->info > elemento)
        return 0;

    Lista remove2 = remove->prox;
    remove->prox = remove2->prox;
    free(remove2);
    return 1;
}
```
---
## não ordenadas:

- insercao sem passagem por referencia:

```c
int insere_elem(Lista ls, int elemento){
    Lista insere;
    insere = (Lista) malloc(sizeof(Elemento));
    if(insere != NULL){
        insere->info = elemento; //insere conteudo
        insere->prox = ls->prox; //aponta para o 1º nó atual da lista
        ls->prox = insere; //faz o cabeçalho apontar pro novo nó
        ls->info++; //opcional: incrementa qtd de nós na lista
        return 1;
    }
    return 0;
}
```

- insercao com passagem por referencia:

```c
int insere_elem(Lista *ls, int elemento){
    Lista insere;
    insere = (Lista) malloc(sizeof(Elemento));
    if(insere != NULL){
        insere->info = elemento; //insere conteudo
        insere->prox = (*ls)->prox; //aponta para o 1º nó atual da lista
        (*ls)->prox = insere; //faz o cabeçalho apontar pro novo nó
        (*ls)->info++; //opcional: incrementa qtd de nós na lista
        return 1;
    }
    return 0;
}
```

- remocao COM cabeçalho:

```c
int remove_elem(Lista ls, int elem){
    if(lista_vazia(ls) == 1 )
        return 0;
    Lista remove = ls;
    
    while(remove->prox != NULL && remove->prox->info != elemento)
        remove = remove->prox;
    if(remove->prox == NULL)
        return 0;

    Lista remove2 = remove->prox;
    remove->prox = remove2->prox;
    free(remove2);
    ls->info--;
    return 1;
}
```

- remocao SEM cabeçalho:

```c
int remove_elem(Lista *ls, int elemento){
    if(lista_vazia(*ls) == 1 )
        return 0;
    Lista remove = *ls;
    if(elemento == (*ls)->info){
        *ls = remove->prox;
        free(remove);
        return 1;
    }
    while(remove->prox != NULL && remove->prox->info != elemento)
        remove = remove->prox;
    if(remove->prox == NULL)
        return 0;

    Lista remove2 = remove->prox;
    remove->prox = remove2->prox;
    free(remove2);
    return 1;
}
```
