#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 
/* Exercicio 11- Lista de Exercícios 2                     */
/* CC2621 --2011    --turma 610    
/***************************  FEI  *************************/

int main()
{
    int dividendo,divisor=0,quociente;
    printf("Digite o valor do dividendo:");
    scanf("%d",&dividendo);

    while(divisor == 0){
        printf("Digite o valor do divisor:");
        scanf("%d",&divisor);
    }
    if (divisor>dividendo){
        printf("O resto da divisao e' %d .",dividendo);
    }else if(dividendo==0){
        printf("Não existe valor para dividir! (dividendo = 0)");
        }else{
            quociente = 0;
     
            while (divisor<=dividendo){
                dividendo -= divisor;
                quociente++;         
                       
            }
            printf("\nO resto da divisao e' %d .\n\n",dividendo);
        }
    system("PAUSE");	
    return 0;
}
