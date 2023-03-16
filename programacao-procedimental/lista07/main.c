#include <stdlib.h>
#include <stdio.h>

void ex1(){
    int v[10],impares=1,i;

    for(i=0;i<10;i++){
        v[i]=impares;
        impares+=2;
        printf("v[%i] = %i\n",i,v[i]);
    }
}

void ex2(){
    int a[10],b[10],c[10],i;

    printf("digite os valores do vetor A:\n");

    for(i=0;i<10;i++){
        printf("A[%i]: ",i);
        scanf("%i",&a[i]);
    }
    printf("\ndigite os valores do vetor B:\n");

    for(i=0;i<10;i++){
        printf("B[%i]: ",i);
        scanf("%i",&b[i]);
    }
    printf("\nvetor C[] = A[] - B[]:\n");
    for(i=0;i<10;i++){
        c[i]=a[i]-b[i];
        printf("C[%i]: %i\n",i,c[i]);
    }
}

void ex3(){
    int v[7],num2=0,num3=0,num5=0,i;

    printf("digite 7 numeros inteiros no intervalo de [0,9]:\n");
    for(i=0;i<7;i++){
        printf("#%i: ",i+1);
        scanf("%i",&v[i]);
        if(v[i]<0 || v[i]>9){
            printf("o valor deve estar entre 0 e 9!\n");
            i--;
        }else{
        if(v[i]==2)
            num2++;
        if(v[i]==3)
            num3++;
        if(v[i]==5)
            num5++;
        }
    }
    printf("\nqtd de numeros 2: %i\n",num2);
    printf("qtd de numeros 3: %i\n",num3);
    printf("qtd de numeros 5: %i\n",num5);
}

void ex4(){
    int n,i,produtof=0;

    printf("numero de elementos nos vetores: ");
    scanf("%i",&n);

    int x[n],y[n],produto[n];

    printf("digite os valores do vetor x:\n");
    for(i=0;i<n;i++){
        printf("X[%i]: ",i);
        scanf("%i",&x[i]);
    }

    printf("digite os valores do vetor y:\n");
    for(i=0;i<n;i++){
        printf("Y[%i]: ",i);
        scanf("%i",&y[i]);
    }

    //produto escalar entre x[] e y[]
    produto[0]=0;
    for(i=0;i<n;i++){
        produto[i]=x[i]*y[i];
        produtof+=+produto[i];
    }
    printf("\nproduto escalar entre os vetores x e y: %i\n",produtof);
}

void ex5(){
    int v[10],maior,menor,i;

    printf("digite 10 numeros:\n");
    for(i=0;i<10;i++){
        printf("#%i: ",i);
        scanf("%i",&v[i]);
        if(i=0){
            maior=v[i];
            menor=v[i];
        }
        if(v[i]>maior)
            maior=v[i];
        if(v[i]<menor)
            menor=v[i];
    }
    printf("\nmaior valor: %i\nmenor valor: %i\n",maior,menor);
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