#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 11 - Lista de Exercícios 4a                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

float divide(int,int,int);

int main(){

    int x,y;
    printf("Digite o primeiro numero (X):");
    scanf("%d",&x);
    printf("\nDigite o segundo numero (Y):");
    scanf("%d",&y);    
    if (x<0 && y<0){
        x *=-1;
        y *=-1;
        printf("\nO Resultado e' %f\n",divide(x,y,0));
    }else if (x<0){
        x*=-1;
        printf("\nO Resultado e' %f\n",divide(x,y,0)*-1);
    }else if (y<0){
        y*=-1;
        printf("\nO Resultado e' %f\n",divide(x,y,0)*-1);
    }else if (y==0){
        printf("\nDivisao por 0, o resultado e' infinito!\n");
    }else{
        printf("\nO Resultado e' %f\n",divide(x,y,0));
    }

    system("pause");
    return 0;   
}

//Funcao recursiva que calcula o resultado da multiplicacao atraves da soma.
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
