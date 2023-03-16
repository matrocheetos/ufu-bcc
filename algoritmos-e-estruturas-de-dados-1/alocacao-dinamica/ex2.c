#include <stdio.h>
#include <stdlib.h>

int main(){
    char *p;
    int tamanho_string,i;
    printf("digite o tamanho da string a ser alocada: ");
    scanf("%d",&tamanho_string);
    if(tamanho_string<1){
        printf("tamanho invalido! (menor que 1)\n");
        exit(1);
    }

    p=(char*) malloc(tamanho_string*sizeof(char));
    
    printf("digite o conteudo da string: ");
    setbuf(stdin,NULL);
    gets(p);

    for(i=0;i<tamanho_string;i++){
        if(p[i]=='a' || p[i]=='e' || p[i]=='i' || p[i]=='o' || p[i]=='u'){
            p[i]=127; //127 é codigo ASCII para 'DEL'
        }
    }

    printf("string sem as vogais: %s\n",p);

    free(p);
    return 0;
}