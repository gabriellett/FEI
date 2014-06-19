#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  05 - Lista de Exercícios 8                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int main(){

    char nomes[40][10];
    char nomeVerificar[40];
    int i;
    for (i=0;i<10;i++){
        printf("Digite o nome de numero %d (35 caracteres no maximo): ",i+1);
        gets(nomes[i]);
    }
    printf("\nDigite o nome a ser verificado: ");
    gets(nomes[10]);
    
    int totalIguais =0;
    for (i=0;i<10;i++){
        if (strcmp(nomes[i],nomes[10])==0){
            totalIguais++;
        }
    }
    printf("Existem %d ''%s'' digitados \n\n\n\n",totalIguais,nomes[10]);
    system("pause");
    return 0;
    
}
