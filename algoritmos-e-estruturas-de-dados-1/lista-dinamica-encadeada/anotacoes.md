## lista dinamica/encadeada:

- implementada atraves de elementos individualizados    ->    armazenam a informação desejada e o ponteiro para seu sucessor
- elementos ocupam posições não consecutivas
- espaço na memória proporcional ao número de elementos armazenado


vantagens:
- memória otimizada (teoricamente nunca fica cheia);
- não requer movimentação;
- não requer gerenciamento de espaço livre.

recomendação:
- listas grandes;
- aplicações de muita inserção e remoção / poucas consultas;
- tamanho máximo não reconhecido.

```c
struct nro{
    int info;
    struct nro *prox;
};
```

- cada elemento aponta para o próximo

```c
typedef struct nro *Lista;

Lista cria_lista(){
    return NULL;
} //criar lista vazia

int lista_vazia(Lista lst){
    if(lst == NULL)
        return 1; //lista vazia
    else
        return 0; //lista não vazia   
}
```

## lista não ordenada:
- 2 cenários de inserção: lista sem elementos / lista com 1 ou mais elementos;
- ambos tratados da mesma forma: alocação do novo nó;
- preenchimento dos campos: 'info' - recebe o valor do novo elemento // 'prox' - recebe o endereço armazenado pela lista
- variável sempre passada por referência