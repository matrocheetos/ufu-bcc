#include <stdio.h>
#include <stdlib.h>

// 1. l� n�mero inteiro e imprime
void ninteiro(){
    int inteiro = 25;
    printf("numero inteiro: %i\n", inteiro); // %i p/ n� inteiro
}

// 2. l� n�mero real e imprime
void nreal(){
    double pi = 3.14;
    printf("numero real: %.2f\n", pi); // "%f" p/ n� real (float e double) e ".2" p/ definir quantas casas decimais
}

// 3. recebe input de 3 valores e soma
void somainteiros(){
    printf("digite 3 numeros separados por espacos:\n");
    int a;
    int b;
    int c;
    scanf("%i %i %i", &a, &b, &c); // "&" � usado antes da vari�vel no scanf
    int resultado = a + b + c;
    printf("%i + %i + %i = %i\n", a, b, c, resultado);
}

// 4. l� n�mero real e imprime o quadrado desse n�mero
void inteiroquad(){
    int x = 11;
    int y = x * x;
    printf("numero: %i -- quadrado: %i\n", x, y);
}

// 4,1. recebe input de real e imprime o quadrado desse n�mero
void inputaoquad(){
    printf("digite um numero inteiro a ser elevado ao quadrado:\n");
    int x;
    scanf("%i", &x);
    int y = x * x;
    printf("numero: %i -- quadrado: %i\n", x, y);
}

// 5. l� n�mero real e imprime a quinta parte desse n�mero
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
