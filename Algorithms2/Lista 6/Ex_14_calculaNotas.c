#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 14 - Lista de Exercícios 6                    */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

void imprimiVetor(int*);

int main(){
    int valor=0,i;
    int notas[7]={100,50,20,10,5,2,1};
    while (valor<=0){
        printf("Digite a quantia de reais (inteiro > 0):");
        scanf("%d",&valor);
    }
    
    for (i=0;i<7;i++){
        int aux=notas[i];
        notas[i]=valor/notas[i];
        valor = valor%aux;
    }
    printf("|-------------------| \n| Relacao de notas: |\n|-------------------|\n");
    imprimiVetor(notas);
    system("pause");
}


//Imprime o vetor na tela
void imprimiVetor(int *v){
    int i;
    int notas[7]={100,50,20,10,5,2,1};
    for(i=0;i<7;i++){
        printf("   %d notas de %d\n",v[i],notas[i]);
    }
}
