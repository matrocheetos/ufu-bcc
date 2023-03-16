#include <stdio.h>
#include <stdlib.h>

void ex1(){
    printf("digite o valor do lado do quadrado:\n");
    int lado;
    scanf("%i",&lado);
    int area = lado * lado;
    printf("lado: %i -- area: %i\n",lado,area);
}

void ex2(){
    printf("digite tres notas separadas por espacos\n");
    int nota1;
    int nota2;
    int nota3;
    scanf("%i %i %i",&nota1,&nota2,&nota3);
    int media = (nota1+nota2+nota3)/3;
    printf("media: %i\n",media);
}

void ex3(){
    printf("digite notas e seus respectivos pesos separados por espacos:\n\n");
    int nota1;
    int nota2;
    int nota3;
    int peso1;
    int peso2;
    int peso3;
    printf("nota 1: ");
    scanf("%i %i",&nota1,&peso1);
    printf("nota 2: ");
    scanf("%i %i",&nota2,&peso2);
    printf("nota 3: ");
    scanf("%i %i",&nota3,&peso3);
    int media = (nota1*peso1 + nota2*peso2 + nota3*peso3)/3;
    printf("\nmedia: %i",media);
}

void ex4(){
    float salario, aumento;

    printf("insira o valor do salario do funcionario:\n");
    scanf("%f",&salario);
    aumento = salario*1.25;
    printf("aumento de 25%c: %.2f",'%',aumento);
}

void ex5(){
    float salario, gratificacao, imposto, recebe;

    printf("insira o valor do salario do funcionario:\n");
    scanf("%f",&salario);
    gratificacao = salario*0.05;
    imposto = salario*0.07;
    recebe = salario + gratificacao - imposto;
    printf("salario a receber: %.2f\n",recebe);
}

void ex6(){
    int hora,minutos,minfinal;

    printf("informe a hora a ser calculada em minutos no formato %chh:mm%c:\n",'"','"');
    scanf("%i:%i",&hora,&minutos);
    minfinal = hora*60 + minutos;
    printf("%i:%i equivalem a %i minutos",hora,minutos,minfinal);
}

void ex7(){
    int atual,nascimento,idade,i2020;

    printf("ano atual: ");
    scanf("%i",&atual);
    printf("ano de nascimento: ");
    scanf("%i",&nascimento);
    idade = atual - nascimento;
    i2020 = 2020 - nascimento;
    printf("idade: %i\nidade em 2020: %i",idade,i2020);
}

void ex8(){
    float altdegraus,altura;
    int qtddegraus;

    printf("altura de cada degrau: ");
    scanf("%f",&altdegraus);
    printf("altura que deseja alcancar: ");
    scanf("%f",&altura);
    qtddegraus = altura/altdegraus;
    printf("o usuario devera subir %i degraus",qtddegraus);
}

int main()
{
    //ex1();
    //ex2();
    ex3();
    //ex4();
    //ex5();
    //ex6();
    //ex7();
    //ex8();
    return 0;
}
