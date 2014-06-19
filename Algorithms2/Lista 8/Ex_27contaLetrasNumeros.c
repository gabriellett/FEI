#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 80

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  27 - Lista de Exercícios 8                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int main(){
    char nome[TAMANHO],endereco[TAMANHO],telefone[TAMANHO],tudo[TAMANHO*3];
    int i;
    for(i=0;i<TAMANHO*3;i++){
        tudo[i]=0;
    }
    int letras=0,numeros=0;

    printf("Digite o nome (%d caracteres): ",TAMANHO-5);
    gets(nome);    
    
    printf("Digite o endereco (%d caracteres): ",TAMANHO-5);
    gets(endereco);    
    
    printf("Digite o telefone (%d caracteres): ",TAMANHO-5);
    gets(telefone);
    
    strcat(tudo,nome);
    strcat(tudo,endereco);
    strcat(tudo,telefone);

    for(i=0;tudo[i]!=0;i++){
        if(isalpha(tudo[i])!=0){
            letras++;
        }else if(isdigit(tudo[i])!=0){
            numeros++;
        }
    }
    
    printf("\n Quantidade de letras pertencentes ao alfabeto : %d \n Quantidade de dígitos numéricos: %d\n",letras,numeros);
    system("pause");
    return 0;
}
