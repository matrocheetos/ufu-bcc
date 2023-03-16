typedef struct esfera Esfera;

Esfera* cria_esfera(double x1, double y1, double z1, double x2, double y2, double z2);
void libera_esfera(Esfera *e);
double raio(Esfera* e);
double area(Esfera* e);
double volume(Esfera *e);