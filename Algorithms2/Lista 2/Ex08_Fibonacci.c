#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 
/* Exercicio 08 - Lista de Exercícios 2                    */
/* CC2621 --2011    --turma 610    
/***************************  FEI  *************************/

int main(int argc, char *argv[])
{
    int n=0;
    
    //Leitura da entrada
    while (n<=0){
          printf("Digite a quantidade de numeros para serem \nexibidos da sequencia de Fibionacci (n!=0):");
          scanf("%d",&n);   
    }
    
    int atu = 0;
    int ant = 1;
    int res = 0;
    int aux = 0;
    system("cls");
    printf("====================== Sequencia Fibonacci de %d numeros ======================\n",n);
    while (aux<n){
        printf("\n%d: %d",aux+1,res);

        if (aux >=1){
            ant = atu;
        }
        atu = res;
        res = res + ant;
        aux++;

    }
    printf("\n\n================================================================================\n",n);
    system("PAUSE");	   
    return 0;
}
