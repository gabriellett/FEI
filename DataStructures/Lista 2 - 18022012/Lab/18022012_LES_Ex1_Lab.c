#include <stdio.h>
#include <stdlib.h>

/***********************************************************/
/* Aluno: Gabriel Lett Viviani *//* 
/* Exercicio  01 - Lista de Exercícios 02                  */
/* CC3651 --2012    --turma 610    
/***********************************************************/

void incluiElemento(int *, int *,int);
void excluiElemento(int *,int *,int);
int buscaBinaria(int *,int,int, int);
    
int main(int argc, char *argv[])
{
    int i,entradas,j;
    int lista[30000];
    int elemento;
    char operacao;
    int quantElementos=0;
    scanf("%d",&entradas);
    for(i=0;i<=entradas;i++){
        scanf("%c",&operacao);
        scanf("%d\n",&elemento);

        if(operacao=='I'){
            incluiElemento(lista,&quantElementos,elemento);   
        }else if (operacao == 'E'){
            excluiElemento(lista,&quantElementos,elemento);
        }
    }
    for(j=0;j<quantElementos;j++){
        printf("%d\n",lista[j]);
    }
    return 0;
}

void incluiElemento(int *lista,int *quantElementos,int elemento){
    if(*quantElementos==0){
        lista[0]=elemento;
        *quantElementos = *quantElementos +1;
    }else{
        int achei=0,i=0;
        while(!achei && i<*quantElementos){
            if(lista[i]==elemento)return;
            if(lista[i]>elemento){
                achei=1;
                int j;
                for(j=*quantElementos-1;j>=i;j--){
                    lista[j+1] = lista[j];
                }
                lista[i]=elemento;
                *quantElementos = *quantElementos +1;
            }
            i++;
        }
        if (!achei){
            lista[*quantElementos] = elemento;
            *quantElementos = *quantElementos +1;
        }
        
        
    }
}



void excluiElemento(int *lista,int *quantElementos,int elemento){
    int posicao;
    do{
        posicao= buscaBinaria(lista,elemento,0,*quantElementos-1);
        if(posicao!=-1){
            if(posicao!=*quantElementos-1){
                int j;
                for(j=posicao+1;j<*quantElementos;j++){
                    lista[j-1] = lista[j];
                }
            }
            *quantElementos = *quantElementos -1;
        }
    }while(posicao!=-1);
}

int buscaBinaria(int *lista,int valor,int e, int d){
    int m;
    if(e <= d){
        m = (e+d)/2;
        if(lista[m] == valor){
            return m;
        }else if(lista[m] < valor){
            return buscaBinaria(lista,valor, m+1, d);
        }else{
            return buscaBinaria(lista,valor, e, m-1);
        }
    }
    return -1;
}
