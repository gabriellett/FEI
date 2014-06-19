#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  07 - Lista de Exercícios 8                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int main(){
    
    char nome[40];
    printf("Digite um nome (maximo de 35 caracteres): ");
    gets(nome);
    
    int totalMaiusculas = 0,i;
    for (i=0;nome[i]!=0;i++){
        if(nome[i]>=65 && nome[i]<=90){
            totalMaiusculas++;
        }
    }
    
    printf("O numero de maiusculas e' :%d\n\n",totalMaiusculas);
    system("pause");
    return 0;
}
