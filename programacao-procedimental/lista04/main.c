#include <stdio.h>
#include <stdlib.h>

void ex1(){
    int num,impar,rep,res;
    impar=1;
    rep=1;
    res=0;

    printf("qtd de numeros impares a serem somados: ");
    scanf("%i",&num);

    printf("%i",impar);

    while(rep<=num){
        if(rep!=1)
            printf(" + %i",impar);
        res=res+impar;
        impar=impar+2;
        rep++;
    }
    printf("\nsoma dos %i primeiros impares: %i",num,res);
}

void ex2(){
    int num,rep,res;
    rep=1;
    res=1;

    printf("numero a ser calculado em fatorial: ");
    scanf("%i",&num);

    while(rep<=num){
        res=res*rep; //resultado eh resultado vezes o fatorial q cresce a cada while
        rep++;
    }
    printf("!%i = %i",num,res);
}

void ex3(){
    int hora,min,cond;
    cond=0;

    while(cond==0){
    printf("horas: ");
    scanf("%i",&hora);
    if (hora<0 || hora>23)
        printf("hora invalida!\n");
    else
        cond++;
    }

    cond=0;

    while(cond==0){
    printf("minuto: ");
    scanf("%i",&min);
    if (min<0 || min>59)
        printf("minuto invalido!\n");
    else
        cond++;
    }

    if(min<10)
        printf("hora digitada: %i:0%ih",hora,min);
    else
        printf("hora digitada: %i:%ih",hora,min);
}

void ex4(){
    int i,preco,consumo,media,maior,menor,maiorvalor;

    media=0;
    maior=0;

    printf("preco do Kwh: ");
    scanf("%i",&preco);

    for(i=1;i<=15;i++){
        printf("consumo de Kwh na residencia #%i: ",i);
        scanf("%i",&consumo);

        media = media+consumo;

        if(consumo>maior)
            maior=consumo;
        if(consumo<menor)
            menor=consumo;
    }

    media = media/15;
    maiorvalor = maior*preco;

    printf("\nconsumo medio entre as residencias: %i Kwh\nmaior consumo: %i Kwh\nmenor consumo: %i Kwh\nmaior valor a ser pago: $%i\n",media,maior,menor,maiorvalor);
}

void ex5(){
    int num,res,rep;
    rep=0;
    res=0;

    printf("digite numeros a serem calculados na formula MA, digite 0 para parar: ");

    while(num!=0){
        printf("%i)",rep);
        scanf("%i",&num);
        rep++;
        res=res+num;
    }
    printf("soma dos numeros: %i",res);
}

void ex6(){

}

int main()
{
    //ex1();
    //ex2();
    //ex3();
    //ex4();
    ex5();
    return 0;
}
