#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 
/* Exercicio 05 - Lista de Exercícios 2                    */
/* CC2621 --2010    --turma 610   
/***************************  FEI  *************************/


int main()
{
    float num,soma,media;
    int i;

    for (i=1;i<=10;i++){
        
    printf("Digite o %do numero:",i);
    scanf("%f",&num);
    soma = soma+num;
    
    }
    
    media = soma/10;
    printf("\nA media entre os numeros digitados e' %.2f\n",media);
    system("PAUSE");	
    return 0;
}
