#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 07 - Lista de Exercícios 3                    */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

float calculaFatorial(int);

int main()
{
    int numero;
    printf("Digite o numero para calcular o fatorial:  ");
    scanf("%d",&numero);
    if (numero==0){
        printf("\nO Fatorial de 0 = 0\n");    
    }else if (numero==1){
        printf("\nO Fatorial de 1 = 1\n");  
    }else{  
        printf("\nO fatorial de %d = %.0f\n",numero,calculaFatorial(numero));
    }

    system("PAUSE");	
    return 0;
}

//Funcao que calcula o fatorial de um numero;
float calculaFatorial(int numero){
    float fatorial = 1;
    while (numero>0){
          fatorial = fatorial * (float)numero;
          numero--;
    }
    return fatorial; //retorna o fatorial do numero
}
