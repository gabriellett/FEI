#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 11 - Lista de Exercícios 6                    */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

void ordenaVetor(int*);
void populaVetor(int*);
void imprimiVetor(int*);

int main(){
    int v[10];
    populaVetor(v);
    ordenaVetor(v);
    system("cls");
    printf("Vetor ordenado: \n\n");
    imprimiVetor(v);
    system("pause");
    return 0;
}

//Popula o vetor;
void populaVetor(int*n){
    int i;
    for (i=0;i<10;i++){
        setbuf(stdin, NULL);
        printf("Digite o %d numero:",i+1);
        scanf("%d",&n[i]);   
    }
}

//Ordenacao por selecao (seleciona o menor valor e coloca na pos. correta.
void ordenaVetor(int *v){
    int i,j,menor,aux;
    for (i=0;i<10;i++){
        menor=i;
        for (j=i+1;j<10;j++){
            if(v[j]<v[menor]){
                menor=j;
            }
        }
        aux=v[i];
        v[i]=v[menor];
        v[menor]=aux;
    }
}

//Imprime o vetor na tela
void imprimiVetor(int *v){
    int i;
    for(i=0;i<10;i++){
        printf("%d elemento: %d\n",i,v[i]);
    }
}
