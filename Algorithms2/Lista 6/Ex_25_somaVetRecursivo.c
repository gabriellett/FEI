#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 25 - Lista de Exercícios 6                    */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int somaVet(int*,int);

int main(){
    int v[20],i,n=21;

    //Laco para popular o vetor com potencias de 2;
    for(i=0;i<20;i++){  
        if (i==0) 
        {
            v[i]=1;
        }else{
            v[i]=2*v[i-1];
        }
    }  
    while (n>20 || n<0){
        printf("Digite o numero n para realizar a soma dos numeros de indices \n0 a n (incluindo 0 e n) do vetor: (n<20):");
        scanf("%d",&n);
    }
    printf("\n\nA soma dos elementos do vetor de indices 0 ate' %d e' %d\n\n",n,somaVet(v,n));
    system("pause");
    return 0;
}

int somaVet(int *v, int n){

    if (n == 0){
        return v[n];
    }else{
    return v[n]+somaVet(v,n-1);
    }
}


