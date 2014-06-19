#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 
/* Exercicio 04 - Lista de Exercícios 2                    */
/* CC2621 --2010    --turma 610   
/***************************  FEI  *************************/


int main()
{
    int num1,num2,aux;
    printf("Digite o primeiro numero:");
    scanf("%d",&num1);
    printf("Digite o segundo numero:");
    scanf("%d",&num2);
    
    if(num1==num2){
        printf("Nao existe valores no intervalo entre os numeros e %d e %d",num1,num2);
    }else{
        if (num1 > num2){
            aux = num2;
            num2 = num1;
            num1 = aux;
        }
        if ((num1+1) == num2){
            printf("Nao existe valores no intervalo entre os numeros e %d e %d",num1,num2);
        }else{
            printf("\nValores no intervalo entre %d e %d:\n\ns",num1,num2);
            while (num1<(num2-1)){
                num1++;
                printf("%d\n",num1);
            }
        }
    }
    printf("\n");
    system("PAUSE");	
    return 0;
}
