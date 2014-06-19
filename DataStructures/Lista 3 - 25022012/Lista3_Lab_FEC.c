#include <stdio.h>
#include <stdlib.h>

/***********************************************************/
/* Aluno: Gabriel Lett Viviani *//* 					   */
/* Exercicio  01 - Lista de Exercícios 03                  */
/* CC3651 --2012    --turma 610     			           */
/***********************************************************/

struct stFila{
    int *itens;
    int inicio,fim;
    int t;
};

void enfileiraItem(struct stFila *,int);
void desenfileira(struct stFila*);
void mostraFila(struct stFila);

int main()
{
    struct stFila fila;
    fila.inicio=0;
    fila.fim=0;
    int it;
    char op;
    scanf("%d\n", &fila.t);
    
    fila.itens=(int*)malloc(sizeof(int)*fila.t);
              
    while(scanf("%c:%d\n", &op, &it)!=EOF)
    {
        if(op=='E')
            enfileiraItem(&fila,it);
        else
            desenfileira(&fila);
    }


    mostraFila(fila);
}

void enfileiraItem(struct stFila* fila,int it){
    if(((fila->fim+1)%fila->t) != fila->inicio){
        fila->itens[fila->fim]=it;
        fila->fim=(fila->fim+1)%fila->t;
    }
}

void desenfileira(struct stFila* fila){
    if(fila->inicio!=fila->fim){
        fila->inicio= (fila->inicio+1)%fila->t;
    }

    
}

void mostraFila(struct stFila fila){
    int aux;
    for (aux=fila.inicio;aux!=fila.fim%fila.t;aux=(aux+1)%fila.t){
        printf("%d\n",fila.itens[aux]);
    }
}
     
     

