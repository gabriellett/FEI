#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  10 - Lista de Exercícios 7                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int getTraco(int[][4]);

int main(){  
        
    int m[4][4];
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("digite um valor para o elemento [%d,%d] da matriz:",i,j);
            scanf("%d",&m[i][j]);
        }
    }
    
    system("cls");
    printf("Matriz:\n");
    printf("\n\n    /\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(j==0 && i!=2){
                printf("   |%d,",m[i][j]);
            }else if(j==3){
                printf("%d",m[i][j]);
            }else if (j==0 && i==2){
                printf(" M=|%d,",m[i][j]);
            }else{
                printf("%d,",m[i][j]);
            }
        }
      printf("\n");
        
    }
    printf("    \\\n\n");
    printf("%d\n",getTraco(m));
    system("pause");
    return 0;
}

int getTraco(int m[][4]){
    int res=0,i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if (i==j){
                res = res+m[i][i];
            }
        }
    }
    return res;
}
