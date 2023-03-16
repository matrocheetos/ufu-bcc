#include <stdio.h>
#include <stdlib.h>

// 1. lê número inteiro e imprime
void ninteiro(){
    int inteiro = 25;
    printf("numero inteiro: %i\n", inteiro); // %i p/ nº inteiro
}

// 2. lê número real e imprime
void nreal(){
    double pi = 3.14;
    printf("numero real: %.2f\n", pi); // "%f" p/ nº real (float e double) e ".2" p/ definir quantas casas decimais
}

// 3. recebe input de 3 valores e soma
void somainteiros(){
    printf("digite 3 numeros separados por espacos:\n");
    int a;
    int b;
    int c;
    scanf("%i %i %i", &a, &b, &c); // "&" é usado antes da variável no scanf
    int resultado = a + b + c;
    printf("%i + %i + %i = %i\n", a, b, c, resultado);
}

// 4. lê número real e imprime o quadrado desse número
void inteiroquad(){
    int x = 11;
    int y = x * x;
    printf("numero: %i -- quadrado: %i\n", x, y);
}

// 4,1. recebe input de real e imprime o quadrado desse número
void inputaoquad(){
    printf("digite um numero inteiro a ser elevado ao quadrado:\n");
    int x;
    scanf("%i", &x);
    int y = x * x;
    printf("numero: %i -- quadrado: %i\n", x, y);
}

// 5. lê número real e imprime a quinta parte desse número
void umquinto(){
    int x = 125;
    int y = x/5;
    printf("numero: %i -- quinta parte: %i\n", x, y);
}

int main()
{
    printf("exercicios:\n");
    ninteiro();
    nreal();
    //somainteiros();
    inteiroquad();
    //inputaoquad();
    umquinto();
    return 0;
}
