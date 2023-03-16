typedef struct nro_complexo Complexo;

Complexo* cria_nro(double Cr, double Ci);
void libera_nro(Complexo* p);
double obter_partes(Complexo *p, int opcao);
Complexo* soma(Complexo* c1, Complexo* c2);
Complexo* sub(Complexo* c1, Complexo* c2);
Complexo* mult(Complexo* c1, Complexo* c2);