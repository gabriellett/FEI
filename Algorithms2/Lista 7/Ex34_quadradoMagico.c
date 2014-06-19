#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  34 - Lista de Exercícios 7                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/


#define TAMANHO 3

void leMatriz(int[][TAMANHO]); //Entrada dos elementos da matriz
void inicializaMatriz(int[][2]); //Inicializa a matriz das somas com 0
int verificaResultados(int[][2],int[][TAMANHO]); //verifica se é quadrado magico
int verificaRepetido(int[][TAMANHO]); //verifica se existe elementos repetidos na matriz
        
int main(){
    
    int m[TAMANHO][TAMANHO],isRepetido=0,somas[TAMANHO+1][2];
    //somas: [*][0] = linhas | [*][1] = colunas
    //A ultima linha e' utilizada para guardar as somas das diagonais;
    leMatriz(m);

    
    system("cls");
        inicializaMatriz(somas);
    printf("    M:\n\n          ");
    int i,j;
    for(i=0;i<TAMANHO;i++){
        for(j=0;j<TAMANHO;j++){
            printf("%06d   ",m[i][j]);
            
            somas[i][0] = somas[i][0]+m[i][j]; //Faz a soma das linhas
            somas[j][1] = somas[j][1]+m[i][j]; //Faz a soma das colunas
            
            if(i==j){   //Diagonal Principal
                somas[TAMANHO][0]=somas[TAMANHO][0]+m[i][j];
            }
            if(i==((TAMANHO-1)-j)){   //Diagonal Secundaria
                somas[TAMANHO][1]=somas[TAMANHO][1]+m[i][j];
            }
        }
        printf("\n          ");
    }
    
    int isMagico = verificaResultados(somas,m);
    if (isMagico==1){
        printf("\n\nA matriz digitada e' um quadrado magico!\n\n");
    }else{
        printf("\n\nA matriz digitada nao e' um quadrado magico!\n\n");
    }
    system("pause");
}

void leMatriz(int m[][TAMANHO]){
    int i,j;
    for(i=0;i<TAMANHO;i++){
        for(j=0;j<TAMANHO;j++){
            printf("digite um valor para o elemento [%d,%d] da matriz:",i,j);
            scanf("%d",&m[i][j]);
  
        }
    }
    
}



void inicializaMatriz(int somas[][2]){
    int i;
    for (i=0;i<=TAMANHO;i++){
        somas[i][0]=0;
        somas[i][1]=0;
        
    }
}

int verificaResultados(int somas[][2],int m[][TAMANHO]){
    int i,j,k,l;
    for (i=0;i<=TAMANHO;i++){
        for(j=0;j<2;j++){
            for(k=0;k<=TAMANHO;k++){
                for(l=0;l<2;l++){
                    if(somas[i][j]!=somas[k][l]){
                        return 0;
                    }
                }
            }   
        }
    }
    if (verificaRepetido(m)==0){
        return 1;
    }else{
        return 0;
    }
}

int verificaRepetido(int m[][TAMANHO]){
    int i,j,k,l;
    for (i=0;i<TAMANHO;i++){
        for(j=0;j<TAMANHO;j++){
            for(k=0;k<TAMANHO;k++){
                for(l=0;l<TAMANHO;l++){
                    if(m[i][j]==m[k][l]){
                        if (i!=k && j!=l){
                            return 1;
                        }
                    }
                }
            }   
        }
    }
    return 0;
}
