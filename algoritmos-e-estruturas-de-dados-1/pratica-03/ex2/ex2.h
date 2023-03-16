typedef struct ponto Ponto;

Ponto* cria_pto(double x, double y, double z);
void libera_pto(Ponto *p);
double distancia_pto(Ponto* p1, Ponto* p2);