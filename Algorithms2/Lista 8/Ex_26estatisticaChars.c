#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 55

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  26 - Lista de Exercícios 8                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int main(){

    char nome[TAMANHO],letra[TAMANHO];
    int valor[TAMANHO];
    
    printf("Digite uma string (%d caracteres): ",TAMANHO-5);
    gets(nome);
    int i,j,k;
    
    //Inicializando os vetores
    for(i=0;i<TAMANHO;i++){
        letra[i]=0;
        valor[i]=0;
    }


    for (i=0;nome[i]!=0;i++){
        int existe=0;
        for(j=0;letra[j]!=0;j++){
            if(letra[j]==nome[i]){
                valor[j]++;
                existe++;
            }
        }
        if(existe==0){
            letra[j] = nome[i];
            valor[j]++;
        }
    }
    
    for(j=0;letra[j]!=0;j++){
        printf("'%c' : %d\n",letra[j],valor[j]);
    }
    system("pause");
    return 0;
}


    
