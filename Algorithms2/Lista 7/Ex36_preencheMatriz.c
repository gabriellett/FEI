#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  36 - Lista de Exercícios 7                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

void recebeMatriz(int[][4]); //Entrada dos elementos da matriz

int main(){
    int matriz[4][4];
    
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("Digite o elemento [%d][%d] da matriz:",i,j);
            scanf("%d",&matriz[i][j]);
        }   
    }
    
    system("cls");
    
    for(i=0;i<4;i++){
        printf("\n     ");
        for(j=0;j<4;j++){

            if (i!=j){
                if (j>i){
                    printf("0001 ");
                }else{
                    printf("0002 ");
                }
            }else{
                printf("%04d ",matriz[i][j]);
            }
        }
    }
    printf("\n\n\n");
    system("pause");
    
    return 0;
}

