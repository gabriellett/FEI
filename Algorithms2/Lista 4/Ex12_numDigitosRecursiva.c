#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 12 - Lista de Exercícios 4a                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int numDigitos(int);

int main(){
    
    int numero;
    printf("Digite o numero desejado:");
    scanf("%d",&numero);

    if (numero<0){
        numero*=-1;
    }
    printf("\nO numero possui %d digitos\n",numDigitos(numero)); 
    system("pause");
    return 0;   
}

//Funcao recursiva que calcula a quantidade de digitos;
int numDigitos(int num){
    if (num<10){
        return 1;
    }
    return 1+numDigitos(num/10);
}
