#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  22 - Lista de Exercícios 7                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

void leMatriz(float[][5]); //Entrada dos elementos da matriz.

int main(){
    float m[5][5];
    /* Result
     *  [0]: Soma da linha 4
     *  [1]: Soma da linha 1
     *  [2]: Soma da diagonal principal
     *  [3]: Soma da diagonal secundaria
     *  [4}: Soma total
     */
    float result[5]={0,0,0,0,0};
    leMatriz(m);
    system("cls");
    printf("    M:\n\n          ");
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%010.3f   ",m[i][j]);
            if(i==3){
                result[0]=result[0]+m[i][j]; //Soma da linha ind. 3
            }
            if(j==1){
                result[1]=result[1]+m[i][j]; //Soma da coluna ind. 1
            }
            if(i==j){
                result[2]=result[2]+m[i][j]; //Soma da diagonal principal
            }
            if(i==(4-j)){
                result[3]=result[3]+m[i][j]; //Soma da diagonal secundária
            }
            result[4]=result[4]+m[i][j]; //Soma total
        }
        printf("\n          ");
    }
    printf("\n\nSoma da linha 4 de M:                   %f\nSoma da coluna 2 de M:                  %f\nSoma da diagonal principal:             %f\nSoma da diagonal secundaria:            %f\nSoma de todos os elementos da matriz M: %f\n\n\n\n",result[0],result[1],result[2],result[3],result[4]);
    
    system("pause");
    return 0;
    
}

void leMatriz(float m[][5]){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("digite um valor para o elemento [%d,%d] da matriz:",i,j);
            scanf("%f",&m[i][j]);
        }
    }
    
}
