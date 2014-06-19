#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 10 - Lista de Exercícios 3                    */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int anoBissexto(int);

int main()
{
    int ano;
    printf("Digite um ano: ");
    scanf("%d",&ano);
    
    if (anoBissexto(ano)==1){
        printf("O ano %d e' bissexto\n \n",ano);
    }else{
        printf("O ano %d nao e' bissexto\n \n",ano);
    }
    
    system("PAUSE");
    return 0;
}

//Funcao que verifica se o ano e' bissexto:
int anoBissexto(int ano) {   
        if ( ( ano % 4 == 0 && ano % 100 != 0 ) || ( ano % 400 == 0 ) ){   
            return 1;   //Retorna 1 caso for bissexto
        }   
        else{   
            return 0;   
        }   
}  
