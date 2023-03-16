#include <stdlib.h>
#include <stdio.h>

void ex1(void){
    int par(int a){
        int verificacao;
        if(a%2==0)
            verificacao=1;
        else
            verificacao=0;
        return verificacao;
    }
    int numero,resultado;
    printf("digite um numero: ");
    scanf("%i",&numero);
    resultado=par(numero);
    if(resultado==0)
        printf("o numero eh impar\n");
    else if(resultado==1)
        printf("o numero eh par\n");
}

void ex2(void){
    int maiornumero(int a,int b){
        int maior;
        if(a>b)
            maior=a;
        if(b>a)
            maior=b;
        return maior;
    }

    int num1,num2,maior;
    printf("digite dois numeros: ");
    scanf("%i%i",&num1,&num2);
    maior=maiornumero(num1,num2);
    printf("%i eh o maior numero\n",maior);
}

void ex3(void){
    int media(char letra, int a, int b, int c){
        int resultado;
        if(letra=='a' || letra=='A'){
            resultado=(a+b+c)/3;
        }else{
            if(letra=='p' || letra=='P'){
                resultado=(5*a+3*b+2*c)/3;
            }
        }
    }
    int nota1,nota2,nota3,mediacalculada;
    char tipomedia;

    printf("digite as tres notas: ");
    scanf("%i%i%i",&nota1,&nota2,&nota3);
    printf("media aritmetica(A) ou ponderada(P)? ");
    setbuf(stdin,NULL);
    scanf("%c",&tipomedia);

    mediacalculada=media(tipomedia,nota1,nota2,nota3);

    printf("media: %i\n",mediacalculada);
}

void ex4(void){
    int funcao(int x){
        int f;
        if(x>=0)
            f = ((5+x)/x-2*x)*x;
        else
            f = ((5+x)/x-2*x)*(-x);
        return f;
    }

    int x,resultado;
    printf("digite um valor: ");
    scanf("%i",&x);
    resultado=funcao(x);
    printf("resultado: %i\n",resultado);
}

void ex5(){
    int fatorial(int a){
        int resultado=1;
        while(a>0){
            resultado=resultado*a;
            a--;
        }
        return resultado;
    }
    int somatorio(int a){
        int resultado=0;
        while(a>0){
            resultado+=a;
            a--;
        }
        return resultado;
    }
    int x,escolha,resposta;
    printf("digite um numero: ");
    scanf("%i",&x);
    printf("calcular: (1)Fatorial ou (2)Somatorio? ");
    scanf("%i",&escolha);
    if(escolha==1)
        resposta=fatorial(x);
    else if(escolha==2)
        resposta=somatorio(x);
    printf("resultado: %i\n",resposta);
}

void ex6(void){


}

int main(){
    //ex1();
    //ex2();
    //ex3();
    ex4();
    //ex5();
    return 0;
}