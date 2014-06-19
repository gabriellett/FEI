#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 5 - Lista de Exercícios 5                    */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

void calculaSoma(int*, int*);

int main(){
    int somaPares=0,somaImpares=0;
    calculaSoma(&somaPares,&somaImpares);
    printf("A soma dos pares e' %d \nA soma dos impares e' %d\n\n",somaPares,somaImpares);
    system("pause");
}

//Funcao que calcula a soma dos numeros pares e inteiros entre 10 e 100.
void calculaSoma(int *pSomaPares,int *pSomaImpares){
    int n=11;
    while (n<100){
        if (n %2 ==0){
            *pSomaPares = *pSomaPares + n;
        }else{
            *pSomaImpares = *pSomaImpares +n;
        }
        n++;
    }
}
