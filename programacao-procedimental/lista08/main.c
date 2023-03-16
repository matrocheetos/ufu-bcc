#include <stdlib.h>
#include <stdio.h>

void ex1(){
    int matriz[5][5],i,j;

    printf("digite os elementos de uma matriz 5x5:\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("(%i,%i): ",i,j);
            scanf("%i",&matriz[i][j]);
        }
    }
    printf("\nelementos da diagonal principal:");
    for(i=0;i<5;i++)
        printf(" %i",matriz[i][i]);
    printf("\n");
}

void ex2(){
    int matriz[4][4],pares,i,j;

    printf("digite os elementos de uma matriz 4x4:\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("(%i,%i): ",i,j);
            scanf("%i",&matriz[i][j]);
        }
    }
    //print da matriz
    printf("\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("\t%i",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //print da posicao dos numeros pares
    printf("posicao dos numeros pares na matriz:\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(matriz[i][j]%2==0)
                printf("(%i,%i) ",i,j);
        }
    }
    printf("\n");
}

void ex3(){
    int matriz[4][7],soma=0,i,j;

    printf("digite os elementos de uma matriz 4x7:\n");
    for(i=0;i<4;i++){
        for(j=0;j<7;j++){
            printf("(%i,%i): ",i+1,j+1);
            scanf("%i",&matriz[i][j]);
            soma+=matriz[i][j];
        }
    }
    printf("\nsoma dos elementos da matriz: %i\n",soma);
}

void ex4(){
    int matriz[4][7],soma[4],i,j;

    printf("digite os elementos de uma matriz 4x7:\n");
    for(i=0;i<4;i++){
        for(j=0;j<7;j++){
            printf("(%i,%i): ",i+1,j+1);
            scanf("%i",&matriz[i][j]);
            soma[i]+=matriz[i][j];
        }
        printf("soma da linha [%i]: %i\n\n",i+1,soma[i]);
    }
}

void ex5(){
    int matriz[10][10],maiorNum,maior[2]={0,0},i,j;

    printf("digite os elementos de uma matriz 10x10:\n");
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("(%i,%i): ",i+1,j+1);
            scanf("%i",&matriz[i][j]);
            if(i==0 && j==0){
                maiorNum=matriz[i][j];
            }else{
                if(matriz[i][j]>maiorNum){
                    maiorNum=matriz[i][j];
                    maior[0]=i+1; //+1 p/ print
                    maior[1]=j+1;
                }
            }
        }
    }
    printf("\no maior valor '%i' esta na posicao (%i,%i)\n",maiorNum,maior[0],maior[1]);
}

void ex6(){
    int matriz[5][5],i,j;

    // todos os valores = 0
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            matriz[i][j]=0;
        }
    }

    // diagonal = 1
    for(i=0;i<5;i++)
        matriz[i][i]=1;

    printf("\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("\t%i",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void ex7(){
    int matrizA[4][4],matrizB[4][4],matrizC[4][4],i,j;

    printf("digite os elementos da matriz A(4x4):\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("A(%i,%i): ",i+1,j+1);
            scanf("%i",&matrizA[i][j]);
        }
    }

    printf("\ndigite os elementos da matriz B(4x4):\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("B(%i,%i): ",i+1,j+1);
            scanf("%i",&matrizB[i][j]);
        }
    }
    // verificar maiores numeros entre matriz A e B
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(matrizA[i][j]>matrizB[i][j])
                matrizC[i][j]=matrizA[i][j];
            else
                matrizC[i][j]=matrizB[i][j];
        }
    }
    //print da matriz A
    printf("\nmatriz A(4x4):\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("\t%i",matrizA[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //print da matriz B
    printf("\nmatriz B(4x4):\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("\t%i",matrizB[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //print da matriz C
    printf("\nmatriz C(4x4):\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("\t%i",matrizC[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void ex8(){
    int matriz[3][3],i,j;
    int somaLinha[3]={0,0,0},somaColuna[3]={0,0,0},somaDiagonais[2]={0,0};
    int verifLinha=0,verifColuna=0,verifDiagonais=0;

    printf("\ndigite os elementos da matriz 3x3:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("(%i,%i): ",i+1,j+1);
            scanf("%i",&matriz[i][j]);
            somaLinha[i]+=matriz[i][j];
            somaColuna[j]+=matriz[i][j];
        }
    }
    for(i=0;i<3;i++)
        somaDiagonais[0]+=matriz[i][i];
    somaDiagonais[1]+=matriz[0][2]+matriz[1][1]+matriz[2][0];

    if(somaLinha[0]==somaLinha[1] && somaLinha[0]==somaLinha[2]) //linha
        verifLinha=1;
    if(somaColuna[0]==somaColuna[1] && somaColuna[0]==somaColuna[2]) //coluna
        verifColuna=1;
    if(somaDiagonais[0]==somaDiagonais[1])
        verifDiagonais=1;

    printf("\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("\t%i",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    if(verifLinha==1 && verifColuna==1 && verifDiagonais==1)
        printf("a matriz eh um quadrado magico!\n\n");
    else
        printf("a matriz nao eh um quadrado magico\n\n");
}

int main(){
    //ex1();
    //ex2();
    //ex3();
    //ex4();
    //ex5();
    //ex6();
    //ex7();
    ex8();
    return 0;
}