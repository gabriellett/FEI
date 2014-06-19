#include <stdio.h>
#include <stdlib.h>

/***********************************************************/
/* Aluno: Gabriel Lett Viviani 
/* Exercicio  01 - Lista de Exercícios 03                  */
/* CC3651 --2012    --turma 610 
/***********************************************************/

struct stFila{
    struct stItem *inicio,*fim;
};

struct stItem{
    int chave;
    struct stItem *proximo;
};

void empilhaItem(struct stFila*,int);
void desempilha(struct stFila*);
void exibirPilha(struct stFila*);

int desenfileira(struct stFila *);
void inverteFila(struct stFila*,struct stItem*);


int main()
{
    struct stFila fila;
    
    fila.inicio=NULL;
    fila.fim=NULL;
    
    int it;
    char op;
              
    while(scanf("%c:%d\n", &op, &it)!=EOF)
    {
        if(op=='E'){
            empilhaItem(&fila,it);;
            
        }else
            desempilha(&fila);
    }

    exibirPilha(&fila);
}

void empilhaItem(struct stFila* fila,int chave){
    struct stItem *it = (struct stItem*) malloc(sizeof(struct stItem));
    if(it != NULL)
    {
        it->chave = chave;
        it->proximo = NULL;
    }
    if(fila->inicio == NULL){
        fila->inicio = it;
        fila->fim = it;
    }else{
        
        (fila->fim)->proximo = it;
        fila->fim = it;
        
    }
}

int desenfileira(struct stFila * fila){
    if(fila->inicio != NULL){
        struct stItem * it = fila->inicio;
        int chave = it->chave;
        
        fila->inicio = (fila->inicio)->proximo;
        
        if(fila->inicio==NULL){
            fila->fim=NULL;
        }
        
        return chave;
        
    }
    return 0;
}

void desempilha(struct stFila *fila){
    if(fila->inicio==NULL){
        return;
    }
    
    struct stFila aux;
    aux.inicio=NULL;
    aux.fim=NULL;

    inverteFila(&aux,fila->inicio);

    desenfileira(&aux);

    while(fila->inicio!=NULL){
        desenfileira(fila);
    }
    inverteFila(fila,aux.inicio);

}
void exibirPilha(struct stFila *fila){
    struct stFila aux;
    aux.inicio=NULL;
    aux.fim=NULL;

    inverteFila(&aux,fila->inicio);
    
    while(aux.inicio!=NULL){
        printf("%d\n",desenfileira(&aux));
    }
}

void inverteFila(struct stFila * filaInvertida,struct stItem * iteAtual){
    if(iteAtual!=NULL){
        inverteFila(filaInvertida,iteAtual->proximo);
        empilhaItem(filaInvertida,iteAtual->chave);
    }
}
