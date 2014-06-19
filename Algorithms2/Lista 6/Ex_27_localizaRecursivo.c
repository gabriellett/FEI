#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 27 - Lista de Exercícios 6                    */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int localiza(int *v,int n, int x);

int main(){
    int v[20],i,n=21; 
    //Laco para popular o vetor com potencias de 2;
    for(i=0;i<20;i++){  
        if (i==0) 
        {
            v[i]=1;
        }else{
            v[i]=2*v[i-1];
        }
    }  
    
    while (n>20 || n<0){
        printf("Digite o numero n que representa a quantidade de elementos a serem \nconsiderados do vetor: (n<20):");
        scanf("%d",&n);
    }
    
    printf("\n\nDigite o valor a ser procurado:");
    int x;
    scanf("%d",&x);
    
    int resposta = localiza(v,n,x);
    if (resposta==-1){
        printf("\n\nValor nao encontrado entre os primeiros %d numeros do vetor!\n",n);
    }else {
        printf("\n\nValor %d encontrado no indice %d do vetor\n",x,resposta);
    }
    system("pause");
    return 0;

}

int localiza(int *v, int n, int x){
    n--;
    if (n == -1){
        return -1;
    }else if (v[n]==x){
        return n;
    }else{
        return localiza(v,n,x);
    }
}
