s#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

#define TAMANHO 80

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  10 - Lista de Exercícios 8                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int main(){
    char frase[TAMANHO],carac;
    
    printf("Digite uma frase (maximo de %d caracteres): ",TAMANHO-5);
    gets(frase);
    
    printf("Digite um caracter para ser substituido por asterisco [case-sensitive!]:");
    scanf("%c",&carac);
    
    int i;
    for(i=0;frase[i]!=0;i++){
        if(frase[i]==carac){
            frase[i]='*';
        }
        
    }
    printf("Frase com o caracter '%c' trocado por '*': '%s' .\n\n",carac,frase);
    system("pause");
    return 0;
}
