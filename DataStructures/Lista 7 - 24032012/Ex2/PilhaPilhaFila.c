#include <stdio.h>
#include <stdlib.h>

/***********************************************************/
/* Aluno: Gabriel Lett Viviani
/* Exercicio  01 - Lista de Exercícios 03                  */
/* CC3651 --2012    --turma 610 
/***********************************************************/

struct stPilha{
    struct stItem *topo;
    int quant;
};

struct stItem{
    int chave;
    struct stItem *anterior;
};

void enfileiraItem(struct stPilha*,int);
void desenfileira(struct stPilha *);
void exibirFila(struct stPilha *);
int desempilha(struct stPilha *);
void invertePilha(struct stPilha*, struct stItem*);

int main()
{
    struct stPilha pilha;
    
    pilha.topo=NULL;
    
    int it;
    char op;
              
    while(scanf("%c:%d\n", &op, &it)!=EOF)
    {
        if(op=='E'){
            enfileiraItem(&pilha,it);;
            
        }else
            desenfileira(&pilha);
    }

    exibirFila(&pilha);
}

void enfileiraItem(struct stPilha* pilha,int chave){
    struct stItem *it = (struct stItem*) malloc(sizeof(struct stItem));
    if(it != NULL){
        it->chave = chave;
        it->anterior = NULL;
    }
    it->anterior = pilha->topo;
    pilha->topo=it;
    pilha->quant= pilha->quant+1;
}

int desempilha(struct stPilha * pilha){
    if(pilha->topo != NULL){
        struct stItem * it = pilha->topo;
        int chave = pilha->topo->chave;
        
        
        pilha->topo = (pilha->topo)->anterior;
        
        free(it);

        pilha->quant= pilha->quant-1;

        return chave;
    }
    return 0;
}

void desenfileira(struct stPilha *pilha){
    if(pilha->topo==NULL){
        return;
    }
    
    struct stPilha aux;
    aux.topo=NULL;

    invertePilha(&aux,pilha->topo);

    

    while(pilha->topo!=NULL){
        desempilha(pilha);
    }
    
    invertePilha(pilha,aux.topo);
    
    desempilha(pilha);
}
void exibirFila(struct stPilha *pilha){
    struct stPilha aux;
    aux.topo=NULL;

    invertePilha(&aux,pilha->topo);
    
    while(aux.topo!=NULL){
        printf("%d\n",desempilha(&aux));
    }
}

void invertePilha(struct stPilha * pilhaInvertida,struct stItem * iteAtual){
    if(iteAtual!=NULL){
        invertePilha(pilhaInvertida,iteAtual->anterior);
        enfileiraItem(pilhaInvertida,iteAtual->chave);
    }
}
