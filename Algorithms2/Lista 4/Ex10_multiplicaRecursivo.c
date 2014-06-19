#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 10 - Lista de Exercícios 4a                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int multiplica(int,int);

int main(){
    
    int x,y;
    printf("Digite o primeiro numero (X):");
    scanf("%d",&x);
    printf("\nDigite o segundo numero (Y):");
    scanf("%d",&y);    
    if (x<0 && y<0){
        x *=-1;
        y *=-1;
        printf("\nO Resultado e' %d\n",multiplica(x,y));
    }else if (x<0){
        x*=-1;
        printf("\nO Resultado e' %d\n",multiplica(x,y)*-1);
    }else if (y<0){
        y*=-1;
        printf("\nO Resultado e' %d\n",multiplica(x,y)*-1);
    }else{
        printf("\nO Resultado e' %d\n",multiplica(x,y));
    }

    system("pause");
    return 0;   
}

//Funcao recursiva que calcula o resultado da multiplicacao atraves da soma.
int multiplica(int x,int y){
    int res=0;
    if (y==0 || x==0){
        return 0;
    }
    if (y==1){
        return x;
    }else{

        res = x + multiplica(x,y-1);
    }
    return res;
}
