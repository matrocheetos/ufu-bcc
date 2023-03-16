#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct hora{
    int hora,min,seg;
};

void ex1(){
    struct hora Hora;
    
    printf("hora: ");
    scanf("%i",&Hora.hora);
    printf("minuto: ");
    scanf("%i",&Hora.min);
    printf("segundo: ");
    scanf("%i",&Hora.seg);

    printf("\n%i:%i:%i\n",Hora.hora,Hora.min,Hora.seg);
}

struct endereco{
    char rua[150],cidade[50],estado[3];
    int numcasa,cep;
};

void ex2(){
    struct endereco Endereco;
    int valido=0;

    printf("rua: "); //rua
    gets(Endereco.rua);
    printf("numero da casa: "); //numcasa
    scanf("%i",&Endereco.numcasa);
    printf("cidade: "); //cidade
    setbuf(stdin,NULL);
    gets(Endereco.cidade);
    while(valido==0){
        printf("estado (somente 2 caracteres): "); //estado
        setbuf(stdin,NULL);
        scanf("%s",&Endereco.estado);
        if(Endereco.estado[2]!='\0'){
            printf("endereco invalido!\n");
        }else{
            valido=1;
        }
    }
    printf("cep (somente numeros): ");
    scanf("%i",&Endereco.cep);

    printf("\n%s, %i -- %i\n%s, %s\n\n",Endereco.rua,Endereco.numcasa,Endereco.cep,Endereco.cidade,Endereco.estado);
}

struct data{
    int dia,mes,ano;
};
struct pessoa{
    char nome[150],sexo;
    int peso;
    struct data Nasc;
    struct endereco Endereco;
};

void ex3(){
    struct pessoa Pessoa;

    printf("nome: "); //nome
    gets(Pessoa.nome);
    printf("sexo (M, F ou X): "); //sexo
    setbuf(stdin,NULL);
    scanf("%c",&Pessoa.sexo);
    printf("peso (em Kg): "); //peso
    scanf("%i",&Pessoa.peso);
    printf("data de nascimento (DD MM AAAA): "); //data nascimento
    scanf("%i%i%i",&Pessoa.Nasc.dia,&Pessoa.Nasc.mes,&Pessoa.Nasc.ano);
    
    printf("\nendereco:\n"); //endereco
    int valido=0;
    printf("rua: "); //rua
    setbuf(stdin,NULL);
    gets(Pessoa.Endereco.rua);
    printf("numero da casa: "); //numcasa
    scanf("%i",&Pessoa.Endereco.numcasa);
    printf("cidade: "); //cidade
    setbuf(stdin,NULL);
    gets(Pessoa.Endereco.cidade);
    while(valido==0){
        printf("estado (somente 2 caracteres): "); //estado
        setbuf(stdin,NULL);
        scanf("%s",&Pessoa.Endereco.estado);
        if(Pessoa.Endereco.estado[2]!='\0'){
            printf("endereco invalido!\n");
        }else{
            valido=1;
        }
    }
    printf("cep (somente numeros): ");
    scanf("%i",&Pessoa.Endereco.cep);

    printf("\n%s, %c, %iKg",Pessoa.nome,Pessoa.sexo,Pessoa.peso);
    printf("\ndata de nascimento: %i/%i/%i",Pessoa.Nasc.dia,Pessoa.Nasc.mes,Pessoa.Nasc.ano);
    printf("\n%s, %i\n%s, %s\nCEP: %i\n\n",Pessoa.Endereco.rua,Pessoa.Endereco.numcasa,Pessoa.Endereco.cidade,Pessoa.Endereco.estado,Pessoa.Endereco.cep);
}

struct computador{
    char marca[50];
    int anofab,peso;
};

void ex4(){
    struct computador Computador[3];
    int i,maisPesado=0;

    printf("registro de computadores:\n");
    for(i=0;i<3;i++){
        printf("computador #%i:\n",i+1);
        printf("marca: ");
        scanf("%s",&Computador[i].marca);
        printf("ano de fabricacao: ");
        scanf("%i",&Computador[i].anofab);
        printf("peso (em gramas): ");
        scanf("%i",&Computador[i].peso);
        if(i!=0){
            if(Computador[i].peso>Computador[maisPesado].peso)
                maisPesado=i;
        }
    }

    for(i=0;i<3;i++){
        printf("\ncomputador #%i: %s, %ig, ano %i",i+1,Computador[i].marca,Computador[i].peso,Computador[i].anofab);
    }
    printf("\n\no computador #%i eh o mais pesado (%i gramas)\n",maisPesado+1,Computador[maisPesado].peso);
}

int main(){
    //ex1();
    //ex2();
    //ex3();
    ex4();
    return 0;
}