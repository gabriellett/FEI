#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  11 - Lista de Exercícios 7                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/


int main(){
    int m[4][4],vMaiorLinha[4],vMenorColuna[4];
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
    
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(j==0){
                vMaiorLinha[i]=m[i][j];
            }else{
                if (m[i][j]>vMaiorLinha[i]){
                    vMaiorLinha[i]=m[i][j];
                }
            }  
            
            if(i==0){
                vMenorColuna[j]=m[i][j];
            }else{
                if (m[i][j]<vMenorColuna[j]){
                    vMenorColuna[j]=m[i][j];
                }
            } 
        }
    }
    for (i=0;i<4;i++){
        printf("\nMaior da linha %d:%d",i,vMaiorLinha[i]);
    }
    
    for (i=0;i<4;i++){
        printf("\nMenor da Coluna %d:%d",i,vMenorColuna[i]);
    }
    printf("\n");
    system("pause");
    return 0;

}

