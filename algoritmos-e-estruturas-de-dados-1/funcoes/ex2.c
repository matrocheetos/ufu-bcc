#include <stdio.h>

int funcao(int x){
    if(x>0)
        return 1;
    else if(x<0)
        return -1;
    else
        return 0;
}

int main(){
    int x;
    printf("digite um numero: ");
    scanf("%d",&x);
    
    x=funcao(x);
    printf("retornou %d\n",x);

    return 0;
}