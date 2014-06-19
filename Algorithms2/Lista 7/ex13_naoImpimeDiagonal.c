#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  13 - Lista de Exercícios 7                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

/*
13. Criar um algoritmo que leia os elementos de uma matriz inteira de 3 x 3 e imprimir todos os elementos,
exceto os elementos da diagonal principal.
*/


int main(){
    int m[3][3];
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("digite um valor para o elemento [%d,%d] da matriz:",i,j);
            scanf("%d",&m[i][j]);
        }
    }
    
    system("cls");
    printf("Matriz sem a diagonal:\n");
    printf("\n\n    /\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(j==0 && i!=1){
                if (i==j){
                    printf("   |?,");
                }else{
                    printf("   |%d,",m[i][j]);
                }
            }else if(j==2){
                if (i==j){
                    printf("?");
                }else{
                    printf("%d",m[i][j]);
                }
            }else if (j==0 && i==1){
                printf(" M=|%d,",m[i][j]);
                
            }else{
                if (i==j){
                    printf("?,");
                }else{
                    printf("%d,",m[i][j]);
                }
            }
        }
      printf("\n");
        
    }
    printf("    \\\n\n");
        
    system("pause");
    return 0;
}
