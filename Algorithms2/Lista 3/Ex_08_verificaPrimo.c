#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 08 - Lista de Exercícios 3                    */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int verificaPrimo(int);

int main()
{
    int numero=0;
    while (numero<=0){
          printf("Digite um numero maior que 0 para verificar se e' primo:  ");
          scanf("%d",&numero);
    }
    
    if (verificaPrimo(numero)==1 && numero!=1){
        printf("\nO numero %d e' primo!\n",numero);    
    }else{
        printf("\nO numero %d nao e' primo!\n",numero);  
    }
    system("PAUSE");	
    return 0;
}

//Funcao que verifica se o No e' primoe:]int verificaPrimo(int numero){
int verificaPrimo(int numero){
    int resultado = 0;
    int aux=1;
    int numDiv=0; //Numero de divisores
    while (aux<=numero){
          if (numero%aux==0){
             numDiv++;

          }
          aux++;
    }
    if (numDiv==2){
       resultado=1; //Retorna 1 caso for primo.
    }
    
    return resultado;
}
