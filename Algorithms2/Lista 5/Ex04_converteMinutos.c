#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 4 - Lista de Exercícios 5                    */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

void converteMinutos(int minutosTotais, int *pMinutos, int *pHoras){
    *pHoras = minutosTotais / 60;
    *pMinutos = minutosTotais % 60;
}

int main()
{
    int minutosTotais=-1, minutos, horas;
 
    while (minutosTotais<0){
        printf("Digite os minutos:\n");
        scanf("%d",&minutosTotais);
    }
    converteMinutos(minutosTotais,&minutos,&horas);
    
    printf("\nHoras contidas nos minutos...: %d horas",horas); 
    printf("\n\nMinutos contidos nos minutos: %d minutos\n\n",minutos);
    
    system("PAUSE");	
    return 0;
}
