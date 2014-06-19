#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 
/* Exercicio 10 - Lista de Exercícios 2                    */
/* CC2621 --2010    --turma 610 
/***************************  FEI  *************************/

int main()
{
    int dividendo,divisor,quociente;
    printf("Digite o valor do dividendo:");
    scanf("%d",&dividendo);
    printf("Digite o valor do divisor:");
    scanf("%d",&divisor);
    
    if (divisor>dividendo){
        printf("O quociente e' 0 e o resto e' %d .",dividendo);
    }else{
        quociente = 0;
 
        while (divisor<=dividendo){
            dividendo -= divisor;
            quociente++;         
                   
        }
        printf("\nO quociente e' %d e o resto e' %d .\n\n",quociente,dividendo);
    }
    system("PAUSE");	
    return 0;
}
