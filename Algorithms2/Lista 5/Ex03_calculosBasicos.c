#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 3 - Lista de Exercícios 5                    */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/


float soma(int a,int b){
    return a+b;
}

float subtrai(int a,int b){
    return a-b;
}

float multiplica(int a, int b){
    return a*b;
}

float verificaDiv(int a, int b){
    if (b==0 && a !=0) {
        return 0;
    }
    return 1;    
}
float divide(int a, int b){
    return (float)a/b;
}

int main(){
    int a, b;
    printf("Digite o valor de a:");
    scanf("%d",&a);
    printf("Digite o valor de b:");
    scanf("%d",&b);
    
    printf("\n\nA soma e':%f",soma(a,b));
    printf("\nA subtracao e':%f",subtrai(a,b));
    printf("\nO resultado da multiplicacao e':%f",multiplica(a,b));
    if (verificaDiv(a,b)==1){
        if (a==0 && b==0){
            printf("\nDivisao possivel, o resultado e' indeterminado (0/0)\n\n");
        }else{
            printf("\nDivisao possivel, o resultado e':%f\n\n",divide(a,b));
        }   
    }else{
        printf("\nA Divisao nao e' possivel! (b=0)\n");
    }

    system("pause");
    
}
