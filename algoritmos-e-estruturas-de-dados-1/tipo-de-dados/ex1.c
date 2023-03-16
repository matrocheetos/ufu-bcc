#include <stdio.h>
#include <string.h>

struct dados_pacientes {
    int idade, e_civil;
    char nome[10];
    double peso, altura;
    float grau_miopia[2];
};

int main(){
    struct dados_pacientes paciente;

    strcpy(paciente.nome,"Jose");
    paciente.altura = 1.25;
    paciente.peso = 73;
    paciente.e_civil = 1;
    paciente.grau_miopia[0] = 1.75;
    paciente.grau_miopia[1] = 0;

    printf("mapa de memoria da struct paciente:");
    printf("\nbytes em paciente.nome: %lu",sizeof(paciente.nome));
    printf("\nbytes em paciente.altura: %lu",sizeof(paciente.altura));
    printf("\nbytes em paciente.peso: %lu",sizeof(paciente.peso));
    printf("\nbytes em paciente.e_civil: %lu",sizeof(paciente.e_civil));
    printf("\nbytes em paciente.grau_miopia[2]: %lu\n",sizeof(paciente.grau_miopia));

    return 0;
}