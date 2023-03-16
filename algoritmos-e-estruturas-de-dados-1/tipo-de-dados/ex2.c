#include <stdio.h>

struct ponto {
    int x,y;
};

struct retangulo {
    struct ponto inicio, fim;
};

int main(){
    struct retangulo ret;

    printf("coordenada inicial do retangulo: ");
    scanf("%d %d",&ret.inicio.x,&ret.inicio.y);
    printf("coordenada final do retangulo: ");
    scanf("%d %d",&ret.fim.x,&ret.fim.y);

    unsigned int area = (ret.fim.x - ret.inicio.x)*(ret.fim.y - ret.inicio.y);
    printf("\narea do retangulo: %d\n",area);

    return 0;
}