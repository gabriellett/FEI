#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

#define TAMANHO 80

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  20   Lista de Exercícios 8                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

void toRomanos(int,char*);

int main(){
    int numero=0,i=0;
    char romanos[TAMANHO];
    
    while(numero<=0 || numero >=4000){
        printf("Digite um numero de 1 a 3999:");
        scanf("%d",&numero);
    }
    
    toRomanos(numero,romanos);

    printf("\nO numero %d em algarismos romanos e': %s \n\n",numero,romanos);
   
    
    system("pause");
    return 0;
}

void toRomanos(int numero, char * romanos){
    int i=0;
    for(;numero>=1000;i++){
        romanos[i] = 'M';
        numero-=1000;
    }
    for(;numero>=900;i++){
        romanos[i] = 'C';
        i++;
        romanos[i] = 'M';
        numero-=900;
    }
    for(;numero>=500;i++){
        romanos[i] = 'D';
        numero-=500;
    }
    for(;numero>=400;i++){
        romanos[i] = 'C';
        i++;
        romanos[i] = 'D';
        numero-=400;
    }    
    for(;numero>=100;i++){
        romanos[i] = 'C';
        numero-=100;
    }
    for(;numero>=90;i++){
        romanos[i] = 'X';
        i++;
        romanos[i] = 'C';
        numero-=90;
    }    
    for(;numero>=50;i++){
        romanos[i] = 'L';
        numero-=50;
    }
    for(;numero>=40;i++){
        romanos[i] = 'X';
        i++;
        romanos[i] = 'L';
        numero-=40;
    }    
    for(;numero>=10;i++){
        romanos[i] = 'X';
        numero-=10;
    }
    for(;numero>=9;i++){
        romanos[i] = 'I';
        i++;
        romanos[i] = 'X';
        numero-=9;
    }
    for(;numero>=5;i++){
        romanos[i] = 'V';
        numero-=5;
    }
    for(;numero>=4;i++){
        romanos[i] = 'I';
        i++;
        romanos[i] = 'V';
        numero-=4;
    }
    for(;numero>=1;i++){
        romanos[i] = 'I';
        numero-=1;
    }
    romanos[i]=0;
}
