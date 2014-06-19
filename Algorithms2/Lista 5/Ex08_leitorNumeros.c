#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 7 - Lista de Exercícios 5                     */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int lerNumeros(int*,int*);

int main(){
    int quantidade=0,maior=0,menor;
    quantidade = lerNumeros(&maior,&menor);
    system("cls");
    if (quantidade ==0){
        printf("Nao foram digitados numeros positivos!\n\n");
    }else if (quantidade == 1){
        printf("Foi digitado %d numero\n   Numero digitado: %d\n\n",quantidade,maior);
    }else{
        printf("Foram digitados %d numeros\n   Maior digitado: %d\n   Menor digitado: %d\n\n",quantidade,maior,menor);
    }
    system("pause");
    return 0;
}

int lerNumeros(int *maior,int *menor){
    int quantidade = -1;
    int numeroDig=0;
    while (numeroDig>=0){
        quantidade++;
        
        if (numeroDig >*maior) *maior = numeroDig;
        if (numeroDig <*menor) *menor = numeroDig;
        
        printf("\nDigite um numero inteiro >=0, se desejar parar digite um numero negativo:");
        scanf("%d",&numeroDig);
        
        if(quantidade == 0 && numeroDig>=0){
            *maior=numeroDig;
            *menor=numeroDig;
        }
    }
    return quantidade;
}
