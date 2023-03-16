#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ex1(){
    char bat[10]="batatinha";

    printf("\nvogais de 'batatinha':");
    for(int i=0;i<10;i++){
        if(bat[i]=='a' || bat[i]=='A' || bat[i]=='e' || bat[i]=='E' || bat[i]=='i' || bat[i]=='I' || bat[i]=='o' || bat[i]=='O' || bat[i]=='u' || bat[i]=='U'){
            printf(" %c",bat[i]);
        }
    }
    printf("\n");
}

void ex2(){
    char bat[10]="batatinha";

    printf("\nconsoantes de 'batatinha':");
    for(int i=0;i<10;i++){
        if(bat[i]!='a' && bat[i]!='A' && bat[i]!='e' && bat[i]!='E' && bat[i]!='i' && bat[i]!='I' && bat[i]!='o' && bat[i]!='O' && bat[i]!='u' && bat[i]!='U'){
            printf(" %c",bat[i]);
        }
    }
    printf("\n");
}

void ex3(){
    char bat[10]="batatinha";
    int numVogais=0,numConsoantes=0;

    for(int i=0;i<10;i++){   //vogais
        if(bat[i]=='a' || bat[i]=='A' || bat[i]=='e' || bat[i]=='E' || bat[i]=='i' || bat[i]=='I' || bat[i]=='o' || bat[i]=='O' || bat[i]=='u' || bat[i]=='U'){
            numVogais++;
        }
    }
    for(int i=0;i<10;i++){   //consoantes
        if(bat[i]!='a' && bat[i]!='A' && bat[i]!='e' && bat[i]!='E' && bat[i]!='i' && bat[i]!='I' && bat[i]!='o' && bat[i]!='O' && bat[i]!='u' && bat[i]!='U' && bat[i]!='\0'){
            numConsoantes++;
        }
    }
    printf("\nnumero de vogais: %i\nnumero de consoantes: %i\n",numVogais,numConsoantes);
}

void ex4(){
    char nome[50];
    int tamanhoString=0;

    printf("digite seu nome: ");
    gets(nome);

    for(int i=0;i<50;i++){
        if(nome[i]=='\0'){
            break;
        }else{
            tamanhoString++;
        }
    }
    printf("tamanho da string: %i\n",tamanhoString);
}

void ex5(){
    char nome[50];
    int tamanhoString;

    printf("digite seu nome: ");
    gets(nome);

    tamanhoString=strlen(nome);
    printf("tamanho da string: %i\n",tamanhoString);
}

void ex6(){
    char str1[50],str2[50];
    int iguais=0,i=0;

    printf("digite uma palavra: ");
    //gets(str1);
    scanf("%s",str1);
    printf("digite uma palavra: ");
    setbuf(stdin,NULL);
    //gets(str2);
    scanf("%s",str2);

    while(iguais==0){
        if(str1[i]==str2[i]){
            if(str1[i]=='\0'){
                iguais=1;
            }
        }else{
            if(str1[i]!=str2[i])
                iguais=2;
        }
        i++;
    }
    if(iguais==1)
        printf("as palavras sao iguais\n");
    if(iguais==2)
        printf("as palavras sao diferentes\n");
}

void ex7(){
    char str1[50],str2[50];

    printf("digite uma palavra: ");
    scanf("%s",str1);
    printf("digite uma palavra: ");
    setbuf(stdin,NULL);
    scanf("%s",str2);

    if(strcmp(str1,str2)==0)
        printf("as palavras sao iguais\n");
    else
        printf("as palavras sao diferentes\n");
     
}

void ex8(){
    char primeiroNome[20],meioNome[20],ultimoNome[20],nome[60]="";

    printf("digite seu primeiro nome: ");
    scanf("%s",primeiroNome);
    printf("digite seu nome do meio: ");
    setbuf(stdin,NULL);
    scanf("%s",meioNome);
    printf("digite seu ultimo nome: ");
    setbuf(stdin,NULL);
    scanf("%s",ultimoNome);

    for(int i=0;i<20;i++){
        if(primeiroNome[i]=='\0'){
            primeiroNome[i]=' ';
            primeiroNome[i+1]='\0';
            break;
        }
    }
    for(int i=0;i<20;i++){
        if(meioNome[i]=='\0'){
            meioNome[i]=' ';
            meioNome[i+1]='\0';
            break;
        }
    }

    strcat(nome,primeiroNome);
    strcat(nome,meioNome);
    strcat(nome,ultimoNome);

    printf("nome: %s\n",nome);
}

void ex9(){
    char str[70],strContrario[70];
    int i,j=70,verif,k;

    printf("digite uma palavra ou frase a ser verificada como palindromo: ");
    scanf("%s",str);

    for(i=0;j<70;i++){
        if(str[i]==' '){
            verif=0;
            k=i;
            while(verif==0){
                if(str[k]=='\0'){
                    verif=1;
                    break;
                }
                str[k]=str[k+1];
                k++;
            }
        }
    }

    for(i=0;i<70;i++){
        str[i]=strContrario[j];
        j--;
    }
    if(strcmp(str,strContrario)==0)
        printf("\na palavra/frase eh um palindromo\n");
    else
        printf("\na palavra/frase nao eh palindromo\n");
}

int main(){
    //ex1();
    //ex2();
    //ex3();
    //ex4();
    //ex5();
    //ex6();
    //ex7();
    //ex8();
    ex9();
    return 0;
}