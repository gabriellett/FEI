#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 13 - Lista de Exercícios 6                    */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int compacta(int*,int*,int);
void populaVetor(int*,int);
void imprimiVetor(int*,int);

int main(){
    int v1[40],v2[40],final;
    int tam=40; //Define o tamanho do vetor
    populaVetor(v1,tam);
    final = compacta(v1,v2,tam);
    system("cls");
    printf("-- v2 ( v1 compactado ):\n\n");
    imprimiVetor(v2,final);
    system("pause");
    return 0;
}

int compacta(int* v1,int *v2,int tam){
    int i; //contador de v2;
    int j=0; //numero a ser verificado na repeticao;
    int k; //valor a ser gravado na v2 (No de elementos iguais).
    int l=0; //contador de v1;
    for (i=0;l<tam;i++){
        k=0; //Inicia o contador de elementos iguais;
        for(;v1[l]==j;l++){
           k++; //Incrementa o numero de elementos iguais
        }
        v2[i]=k;//Coloca no indice correto de v2 a quantidade de elementos iguais.
        j=(j+1)%2; //Muda o valor a ser comparado  
    }
    return i; //Retorna o ultimo indice com valor de v2
}

//Pede para o usuario inserir elementos no vetor;
void populaVetor(int *v,int tam){
    int i,dig;
    for (i=0;i<tam;i++){
        for (dig=-1;dig!= 0 && dig!=1;){
            setbuf(stdin, NULL);
            printf("Digite o %d numero:",i+1);
            scanf("%d",&dig);   
        }
        v[i]=dig;
    }
}

//Imprime o vetor na tela
void imprimiVetor(int *v,int final){
    int i,j;
    for(i=0,j=0;i<final;i++){
        printf("     %d: Serie de %d: %d\n",i+1,j,v[i]);
        j=(j+1)%2;  
    }
}
