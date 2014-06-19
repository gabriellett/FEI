#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  07 - Lista de Exercícios 9                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

typedef struct
{
int p, q;
}racional;

racional reduz(int,int);
int mdc(int,int);
racional soma(racional,racional);
racional mult(racional,racional);
racional divi(racional,racional);

int main(){
    int a,b=0;
    racional x,y;
    
    printf("Digite o valor de a para x:");
    scanf("%d",&a);
    while(b<1){
        printf("Digite o valor de b para x:");
        scanf("%d",&b);
    }
    if (a==b){
        a=1;
        b=1;    
    }
    x = reduz(a,b);
    printf("\nX: %d / %d\n\n",x.p,x.q);
    b=0;
    printf("Digite o valor de a para x:");
    scanf("%d",&a);
    while(b<1){
        printf("Digite o valor de b para x:");
        scanf("%d",&b);
    }
    if (a==b){
        a=1;
        b=1;    
    }
    y = reduz(a,b);
    printf("\nY: %d / %d\n\n",y.p,y.q);

    racional resSoma = soma(x,y);
    printf("Soma:%d / %d\n",resSoma.p,resSoma.q);
    
    racional resMult = mult(x,y);
    printf("Multiplicacao: %d / %d \n",resMult.p,resMult.q);
    
    racional resDiv = divi(x,y);
    printf("Multiplicacao: %d / %d \n\n",resDiv.p,resDiv.q);
    
    system("pause");
}

racional reduz(int a,int b){
    racional ab;
    ab.p = a;
    ab.q = b;
    int res = mdc(a,b);
    if (res!=a){
        ab.p = a/res;
        ab.q = b/res;
        return ab;
    }
    return ab;
}
racional neg(racional x){
    racional menx;
    menx.p = x.p*-1;
    menx.q = x.q;
}

racional soma(racional x,racional y){
    racional soma;
    int divComum = x.q*y.q;
    int a = ((divComum/x.q)*x.p) + ((divComum/y.q)*y.p);
    soma = reduz(a,divComum);
    return soma;
}

racional mult(racional x,racional y){
    int a,b;
    a = x.p*y.p;
    b = x.q*y.q;
    return reduz(a,b);
}

racional divi(racional x,racional y){
    int a,b;
    a = x.p*y.q;
    b = x.q*y.p;
    return reduz(a,b);
}
/* Algoritimo de Euclides recursivo que retorna o mdc */
int mdc(a,b){
    if(b==0) return a;
    else return mdc(b,a%b);
}
