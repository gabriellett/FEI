#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 04 - Lista de Exercícios 3                    */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int comparaChars(char);

int main()
{
    char carac;
    printf("Digite um caractere:");
    scanf("%c",&carac);
    if (comparaChars(carac)==1){
        printf("Voce escreveu uma vogal! (%c)\n",carac);    
    }else{
        printf("O caractere digitado nao foi uma vogal\n");
    }

    system("PAUSE");	
    return 0;
}

int comparaChars(char carac){
    if (carac=='a' || carac=='e' || carac=='i' || carac=='o' || carac=='u'){
        return 1; //retorna 1 se for vogal
    }
    return 0; //retorna 0 se não for vogal
}
