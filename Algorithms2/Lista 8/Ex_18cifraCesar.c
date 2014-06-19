#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 80

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  18 - Lista de Exercícios 8                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int main(){
    char original[TAMANHO],codificada[TAMANHO];
    
    printf("Digite a primeira string (%d caracteres): ",TAMANHO-5);
    gets(original);
    strupr(original);
    int i;
    for (i=0;original[i]!=0;i++){
        if(original[i]>=65 && original[i] <= 87){
            codificada[i] = original[i]+3;
        }else if(original[i]>=88 && original[i] <= 90){
            codificada[i] = 65+(90-original[i]);
        }else if(original[i]){
            codificada[i] = original[i];
        }
    }
    codificada[i] = 0;
    
    printf("A mensagem codificada na cifra de cesar ficou: '%s' .\n\n",codificada);
    
    system("pause");
    return 0;
}
