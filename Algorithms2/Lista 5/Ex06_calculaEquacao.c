#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 6 - Lista de Exercícios 5                    */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/


int calculaEquacao(float,float,float,float*,float*);
    
int main(){
    float a=0,b,c,raiz1=0,raiz2=0;
    while(a==0){
    printf("Digite o valor do coeficiente a:");
    scanf("%f",&a);
    }
    printf("\nDigite o valor do coeficiente b:");
    scanf("%f",&b);
    printf("\nDigite o valor do coeficiente c:");
    scanf("%f",&c);
    int numRaiz = calculaEquacao(a,b,c,&raiz1,&raiz2);
    system("cls");
    printf("Equacao: %.2f*x^2 + (%.2f)*x + (%.2f)\n",a,b,c);
    if (numRaiz ==0){
        printf("\nNao existem raiz reais para esta equacao!\n\n");   
    }else if(numRaiz == 1){
        printf("\nA equacao possui uma raiz: %f\n\n",raiz1);
    }else{
        printf("\nA equacao possui duas raizes reais: \n   1a: %f\n   2a: %f\n\n",raiz1,raiz2);
    }
    system("pause");
}

int calculaEquacao(float a, float b, float c, float *pRaiz1, float *pRaiz2 ){
    float delta = (b*b)-(4*a*c);
    int numRaiz;
    if (delta <0){
        return 0;
    }else if(delta==0){
        numRaiz = 1;
        *pRaiz1= (-1*b)/(2*a);
    }else {
        numRaiz = 2;
        *pRaiz1= ((-1*b)+sqrt(delta))/(2*a);
        *pRaiz2= ((-1*b)-sqrt(delta))/(2*a);
    }

    return numRaiz;
}
