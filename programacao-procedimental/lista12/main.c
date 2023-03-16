#include <stdlib.h>
#include <stdio.h>

void ex1(){
    int vetor1[10],vetor2[10],i;

    void leVetor(int *vetor, int n){ //passando vetor por referencia
        for(i=0;i<n;i++){
            printf("digite o valor da posicao %i: ",i+1);
            scanf("%i",&vetor[i]);
        }
    }
    leVetor(vetor1,10);
    leVetor(vetor2,10);

    void imprime(int *m,int n){
        for(i=0;i<n;i++)
            printf("%i\n",m[i]);
    }
    //imprime(vetor1,10);
    //imprime(vetor2,10);

    void positivosReferencia(int *vetor,int n,int *positivos){
        for(i=0;i<n;i++){
            if(vetor[i]>=0){
                *positivos=*positivos+1;
            }
        }
    }

    int positivosSemReferencia(int vetor,int positivos){
        if(vetor>=0)
            positivos++;
        return positivos;
    }

    int positivos1=0,positivos2=0;
    positivosReferencia(vetor1,10,&positivos1);
    for(i=0;i<10;i++)
        positivos2 = positivosSemReferencia(vetor2[i],positivos2);
        //positivos1 = positivosSemReferencia(vetor1[i],positivos1);

    printf("\npositivos vetor #1: %i\npositivos vetor #2: %i\n",positivos1,positivos2);
}       

void ex2(){
    struct Conta{
        char nome[50];
        int numCC;
    };

    void preencheCorrentista(struct Conta *conta){
        int i;
        for(i=0;i<5;i++){
            printf("nome[%i]: ",i);
            setbuf(stdin,NULL);
            gets(conta[i].nome);
            printf("numero da conta corrente[%i]: ",i);
            scanf("%i",&conta[i].numCC);
        }
    }
    
    void imprimeCorrentista(struct Conta *conta){
        int i;
        for(i=0;i<5;i++){
            printf("\nnome: %s",conta[i].nome);
            printf("\nnumero da conta corrente: %i",conta[i].numCC);
        }
        printf("\n");
    }

    struct Conta correntistas[5];
    preencheCorrentista(correntistas);
    imprimeCorrentista(correntistas);
}

void ex3(){
    struct Habitantes{
        char sexo;
        int olhos,cabelos,idade;
    };

    void leDados(int numHabitantes,struct Habitantes *habitantes){
        int i;
        for(i=0;i<numHabitantes;i++){
            printf("\nhabitante #%i\n",i+1);
            printf("sexo (M, F ou X): ");
            setbuf(stdin,NULL);
            scanf("%c",&habitantes[i].sexo);
            printf("cor dos olhos (1.azul/2.verde/3.castanho): ");
            scanf("%i",&habitantes[i].olhos);
            printf("cor dos cabelos (1.louro/2.preto/3.castanho): ");
            scanf("%i",&habitantes[i].cabelos);
            printf("idade: ");
            scanf("%i",&habitantes[i].idade);
        }
    }
    void imprimeDados(int numHabitantes,struct Habitantes *habitantes){
        int i;
        for(i=0;i<numHabitantes;i++){
            printf("\nhabitante #%i\n",i+1);
            printf("sexo (M, F ou X): %c\n",&habitantes[i].sexo);
            
            char* olhos[11];
            switch(habitantes[i].olhos){
                case 1: olhos*="azul"; break;
                case 2: olhos="verde"; break;
                case 3: olhos=castanho; break;
                default: olhos=indefinido; break;
            }
            printf("cor dos olhos: %s\n",olhos);

            char cabelos[15];
            switch(habitantes[i].cabelos){
                case 1: cabelos=louro; break;
                case 2: cabelos=preto; break;
                case 3: cabelos=castanho; break;
                default: cabelos=indefinido; break;
            }
            printf("cor dos cabelos: %s\n",cabelos);
            printf("idade: &i\n",&habitantes[i].idade);
        }
    }
    int maioresDeIdade(int numHabitantes,struct Habitantes *habitantes){
        int i,maioresDeIdade=0;
        for(i=0;i<numHabitantes;i++){
            if(habitantes[i].idade>=18){
                maioresDeIdade++;
            }
        }
        return maioresDeIdade;
    }
    int qtdHabitantes,deMaior;
    printf("numero de habitantes: ");
    scanf("%i",qtdHabitantes);

    struct Habitantes habitantes[qtdHabitantes];
    leDados(qtdHabitantes,habitantes);
    imprimeDados(qtdHabitantes,habitantes);
    deMaior=maioresDeIdade(qtdHabitantes,habitantes);
    printf("\nmaiores de idade: %i\n",deMaior);
}

int main(){
    //ex1();
    //ex2();
    ex3();
    return 0;
}