#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 15 - Lista de Exercícios 4b                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int divide(int,int);

int main(){

    int x,y=0;
    printf("Digite o primeiro numero (X):");
    scanf("%d",&x);
    while(y==0){
        printf("\nDigite o segundo numero (Y):");
        scanf("%d",&y);    
    }
    if (x<0 && y<0){
        x *=-1;
        y *=-1;
        printf("\nO resto da divisao e' %d\n",divide(x,y));
    }else if (x<0){
        x*=-1;
        printf("\nO resto da divisao e' %d\n",divide(x,y));
    }else if (y<0){
        y*=-1;
        printf("\nO resto da divisao e' %d\n",divide(x,y));
    }else{
        printf("\nO resto da divisao e' %d\n",divide(x,y));
    }

    system("pause");
    return 0;   
}

//Funcao recursiva que calcula o resto da divisão (modificada do ex 11 da lista 4a).

int divide(int x,int y){
    if (x<y){
        return x;
    }else if (x==y ){
        return 0;
    }else{
        return divide(x-y,y);
    }

}
