#include <stdio.h>
#include <stdlib.h>

void ex1(){
    int a,b;
    printf("insira um valor para A e B:\nA: ");
    scanf("%i",&a);
    printf("B: ");
    scanf("%i",&b);
    a=b;
    printf("A=%i\nB=%i",a,b);
}

void ex2(){
    float a,b,c,premio,soma,a1,b1,c1;
    printf("insira o valor investido:\npessoa A: ");
    scanf("%f",&a);
    printf("pessoa B: ");
    scanf("%f",&b);
    printf("pessoa C: ");
    scanf("%f",&c);
    printf("valor do premio: "); // premio é 100%
    scanf("%f",&premio);
    soma=a+b+c;
    if (soma>premio)
        printf("valor do premio incorreto");
    else{
        a1 = (a/soma)*premio;
        b1 = (b/soma)*premio;
        c1 = (c/soma)*premio;
        printf("cada apostador ganharia:\nA: %.2f reais\nB: %.2f reais\nC: %.2f reais",a1,b1,c1);
    }
}

void ex3(){
    int numero,c,d,u;
    printf("digite um numero de 100 a 999: ");
    scanf("%i",&numero);
    if (numero<100)
        printf("o numero deve ter tres digitos!");
    else {
        if (numero>999)
            printf("o numero deve ter tres digitos!");
        else {
            c=numero/100;
            numero=numero%100;
            d=numero/10;
            u=numero%10;
            printf("numero invertido: %i%i%i",u,d,c);
        }
    }
}

void ex4(){
    int num;
    printf("digite um numero inteiro: ");
    scanf("%i",&num);
    num = num%2;
    if (num==0)
        printf("o numero inserido eh par");
    else
        printf("o numero inserido eh impar");
}

void ex5(){
    char produto;
    printf("codigo do produto (de 1 a 4): ");
    //scanf("%c",produto); // char pode usar getchar (?)
    produto = getchar();
    switch(produto){
        case '1':
            printf("o produto eh um alimento nao-perecivel\n"); break;
        case '2':
            printf("o produto eh um alimento perecivel\n"); break;
        case '3':
            printf("o produto eh um item de higiente pessoal\n"); break;
        case '4':
            printf("o produto eh um material de limpeza\n"); break;
        default:
            printf("nao eh um codigo de produto valido\n");
    }
}

void ex6(){
    char sexo;
    int idade,contrib;
    printf("vc tem direito a aposentadoria?\nsexo (m ou f): ");
    sexo = getchar();
    if (sexo!='m' && sexo!='f')
        printf("nao eh um sexo valido");
        return 0;
    printf("idade (em anos): ");
    scanf("%i",&idade);
    printf("tempo de contribuicao (em anos): ");
    scanf("%i",&contrib);
    if (sexo==m){
        if (contrib>34){
            printf("o usuario tem direito a aposentadoria");
        }else if (idade>65){
            printf("o usuario tem direito a aposentadoria");
        }else
            printf("o usuario nao tem direito a aposentadoria");
    }
    }
    if (sexo==f){
        if (contrib>29)
            printf("o usuario tem direito a aposentadoria");
        else if (idade>60)
            printf("o usuario tem direito a aposentadoria");
        else
            printf("o usuario nao tem direito a aposentadoria");
    }
}

int main()
{
    //ex1();
    //ex2();
    //ex3();
    //ex4();
    //ex5();
    ex6();
    return 0;
}
