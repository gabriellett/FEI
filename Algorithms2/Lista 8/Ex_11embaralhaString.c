#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

#define TAMANHO 80

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  11 - Lista de Exercícios 8                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/


char embaralhaString(char*,char*,char*);

int main(){
    char stringA[TAMANHO],stringB[TAMANHO],stringC[TAMANHO*2];
    
    printf("Digite a primeira string (%d caracteres): ",TAMANHO-5);
    gets(stringA);
    
    printf("Digite a segunda string (%d caracteres): ",TAMANHO-5);
    gets(stringB);
    embaralhaString(stringA,stringB,stringC);
    printf("\n '%s'+'%s' = \n",stringA,stringB);
    printf("As strings embaralhadas ficaram: '%s'.",stringC);

    system("pause");
    return 0;
    
}

char embaralhaString(char *stringA,char *stringB,char *stringC){
    int i,j,k;
    for (i=0,j=0,k=0;i<strlen(stringA)+strlen(stringB);){
        if (stringA[j]!=0){
            stringC[i]=stringA[j];
            j++;
            i++;
        }
        if (stringB[k]!=0){
            stringC[i]=stringB[k];
            k++;
            i++;
        }
    }
    
    stringC[i+1]=0;
    printf("%s",stringC);
    return stringC;

}
