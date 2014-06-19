#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

#define TAMANHO 80

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  09 - Lista de Exercícios 8                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int main(){
    char nome[TAMANHO];
    printf("Digite um nome (maximo de %d caracteres): ",TAMANHO-5);
    gets(nome);
    int i;
    for(i=0;nome[i]!=0;i++){
        if(nome[i]>=65 && nome[i]<=90){
            nome[i] = tolower(nome[i]);
        }else if(nome[i]>=97 && nome[i] <=122){
            nome[i] = toupper(nome[i]);
        }
    }
    printf("Nome com maiusculos-minusculos invertidos: '%s' .\n\n",nome);
    system("pause");
    return 0;
}
