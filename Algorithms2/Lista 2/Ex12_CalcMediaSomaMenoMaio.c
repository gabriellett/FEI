#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani
/* Exercicio 12 - Lista de Exercícios 2                    */
/* CC2621 --2011    --turma 610     
/***************************  FEI  *************************/


int main()
{
    int entrada=0, somatorio=0, maior=0, menor=0,qtd = 0;
    float media=0;
    while (entrada>=0){
        printf("Digite um numero:");
        scanf("%d",&entrada);

        if (entrada>=0){

            somatorio = somatorio + entrada;
            if (entrada > maior){
                maior = entrada;
            }
            
            if (qtd == 0){
                menor = entrada;
            }else if (entrada < menor){
                menor = entrada;
            }
            qtd++;
        }
    }
    if (qtd!=0)
    {
        media = (float)somatorio/(float)qtd;
    }
    printf("\n\n-Total de numeros computados: %d\n-Somatorio: %d\n-Menor numero digitado: %d\n-Maior numero digitado: %d\n-Media: %f\n",qtd,somatorio,menor,maior,media);
    
    system("PAUSE");	
    return 0;
}
