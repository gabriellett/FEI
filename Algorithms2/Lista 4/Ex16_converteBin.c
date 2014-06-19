#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 16 - Lista de Exercícios 4b                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int converteBin(int);

int main(){

    int numero;
    printf("Digite um numero:");
    scanf("%d",&numero);
    converteBin(numero);
    printf("\n\n");
    system("pause");
    return 0;   
}

//Funcao recursiva que converte decimal para binario.
int converteBin(int decimal){
    if ((decimal / 2) !=0){
        converteBin(decimal/2);
    }
    printf("%d",decimal%2);
    return 0;
}
