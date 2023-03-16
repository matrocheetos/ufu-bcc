#include <stdio.h>

int main(){
    double *p, *q, *r, A[5];

    p=A;    //p=1234600, endereco de A[0]
    q=p+1;  //q=1234608, endereco de A[1]
    r=q+2;  //r=1234624, endereco de A[3]

    printf("&A[0] = %lu; *r = %lf;\n", &A[0], *r);  //saida: &A[0] = 1234600, *r = lixo
    printf("p = %lu; *(A+1) = %lf;\n", p, *(A+1));  //saida: p = 1234600, *(A+1) = lixo
    
    r=p+4;  //r=1234632, endereco de A[4]
    p=q;    //p=1234608, endereco de A[1]

    printf("p+1 = %lu; *(r-2) = %lf;\n", p+1, *(r-2));  //saida: p+1 = 1234616, *(r-2) = lixo
    printf("&A[4] = %lu; *r = %lf;\n", &A, *r);         //saida: &A[4] = 1234600, *r = lixo

    return 0;
}