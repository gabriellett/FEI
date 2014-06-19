#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 11- Lista de Exercícios 2                     */
/* CC2621 --2010    --turma 610     --                     */
/* Compilador: DevC++ 4.9.9.2                              */
/***************************  FEI  *************************/

int main()
{
    int dividendo,divisor=0,quociente;
    while(divisor == 0){
        printf("Digite o valor do dividendo:");
        scanf("%d",&dividendo);
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
