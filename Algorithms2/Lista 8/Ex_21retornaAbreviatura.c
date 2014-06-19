#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 80

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  21 - Lista de Exercícios 8                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int main(){

    char nome[TAMANHO],nomeAtu[TAMANHO],abreviatura[TAMANHO];
    
    printf("Digite a primeira string (%d caracteres): ",TAMANHO-5);
    gets(nome);
    
    int posIni,posFin;
    int i,j,l=0;
    for (i=0;nome[i]!=0;i++){
        if(isalpha(nome[i])!=0){
            posIni = i;

            for(j=i+1;nome[j]!=0 && isalpha(nome[j])!=0;j++);
            posFin = j-1;

        
        int k;
        for (k=0;posIni<=posFin;posIni++,k++){
            nomeAtu[k] = nome[posIni];
        }
        nomeAtu[k+1] = 0;

        
        i=posFin;

        if (verificaNomesComuns(nomeAtu)==0){
        
            abreviatura[l] = nomeAtu[0];
            l++;
            abreviatura[(l)] = '.';
            l++;
        }
        }

    }
    abreviatura[l]=0;
    printf("\n\n%s\n",strupr(abreviatura));
    system("pause");
    return 0;   
}

int verificaNomesComuns(char *nomeAtu){
    int i,j;{
        if(strlen(nomeAtu)>4){
            return 0;
        }else{
            if (nomeAtu[0]!='d'){
                return 0;
            }else if(nomeAtu[1]!='o' && nomeAtu[1]!='a' && nomeAtu[1]!='e'){
                return 0;
            }else if(nomeAtu[2]!=' ' && nomeAtu[2]!='s'){
                return 0;
            }else{
                return 1;
            }
            
        }
    }
    
}
