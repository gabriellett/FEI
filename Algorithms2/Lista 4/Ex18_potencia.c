#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 18 - Lista de Exercícios 4b                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

float calculaPotencia(int,int);
float divide(int,int,int);

int main(){

    int k,n;
    printf("Digite o primeiro numero (k):");
    scanf("%d",&k);
    printf("\nDigite o segundo numero (n):");
    scanf("%d",&n);    
    printf("\nO Resultado e' %f\n",calculaPotencia(k,n));
    system("pause");
    return 0;   
}


//Funcao que calcula k^n;
float calculaPotencia(int k,int n){
    if (n<0){
        return divide(1,calculaPotencia(k,n*-1),0);
    }else if (n==0){
        return (float)1;
    }else{
        return (float)k*calculaPotencia(k,n-1);
    }
}

//Funcao recursiva que calcula o resultado da multiplicacao atraves da soma (retirada do ex 11 da lista 4a).
//aux utilizado para contagem dos algarismos depois da virgula, evitando uma recursividade infinita em caso de divisoes que resultam
//em dizimas.
float divide(int x,int y,int aux){
    if (x<y){
        x*=10;
        aux++;
        if(aux>=7){
            return 0;
        }else{
            return 0.1*(divide(x-y,y,aux)+1);
        }
    }else if (x==y || x==0){
        return 1;
    }else{
        return 1+divide(x-y,y,aux);
    }

}
