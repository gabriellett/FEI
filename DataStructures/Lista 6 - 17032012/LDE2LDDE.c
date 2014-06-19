#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************************************/
/* Aluno: Gabriel Lett Viviani *//* 					   */
/* Exercicio  02 - Lista de Exercícios 06                  */
/* CC3651 --2012    --turma 610    					       */
/***********************************************************/


struct stItemLDE{
    int chave;
    struct stItem *proximo;
};

struct stLDE{
    struct stItemLDE *inicio;
};


struct stItemLDDE{
    int chave;
    struct stItemLDDE *proximo;
    struct stItemLDDE *anterior;
};

struct stLDDE{
    int q;
    struct stItemLDDE *inicio;
    struct stItemLDDE *fim;
};


/* Cria um novo item na LDE */
struct stItem * criaItemLDE(int chave)
{
    struct stItemLDE *it = (struct stItemLDE*) malloc(sizeof(struct stItemLDE));
    if(it != NULL)
    {
        it->chave = chave;
        it->proximo = NULL;
    }
    return it;
}

/* Cria um novo item na LDDE*/
struct stItem * criaItem(int chave)
{
    struct stItemLLDE *it = (struct stItemLDDE*) malloc(sizeof(struct stItemLDDE));
    if(it != NULL)
    {
        it->chave = chave;
        it->proximo = NULL;
        it->anterior = NULL;
    }
    return it;
};

/* Insere um elemento na LDE */
void inserirLDE(struct stLDE *l, struct stItemLDE *novo)
{
    struct stItemLDE *atual=l->inicio, *anterior=NULL;
    if(l->inicio == NULL){
        l->inicio = novo;
    }else{
        int achei = 0;
        
        while(atual!=NULL && achei==0){
            if(atual->chave > novo->chave){
                achei = 1;
            }else{
                anterior = atual;
                atual = atual->proximo;
            }
        }
        
        if(achei==0){
            anterior->proximo = novo;
        }else if(anterior == NULL){
            l->inicio = novo;
            novo->proximo = atual;
        }else{
            novo->proximo = atual;
            anterior->proximo = novo;
        }
    }
}

/* Insere um item na LDDE */
void inserir(struct stLDDE *l, struct stItemLDDE *novo)
{
    struct stItemLDDE *atual=l->inicio;
    
    if(l->inicio == NULL){
        l->inicio = novo;
        l->fim = novo;
        novo->anterior = NULL;
        novo->proximo = NULL;
        l->q=1;
    }else{

        int achei = 0;
        
        do{
            if(atual->chave > novo->chave){
                achei=1;
            }else{
                atual = atual->proximo;
            }
        }while(achei==0 && atual!=l->inicio);
        
        /* Insere no Fim */
        if(achei==0){
            atual = atual->anterior;
            atual->proximo = novo;
            l->fim = novo;
            novo->anterior = atual;
            novo->proximo = NULL;
            l->q = l->q+1;
        /* Insere no Inicio */
        }else if(atual == l->inicio){
            l->inicio = novo;
            atual->anterior = novo;
            novo->proximo = atual;
            novo->anterior = NULL;
            l->q = l->q+1;
        /* Insere em qualquer posição */ 
        }else{
            novo->proximo = atual;
            novo->anterior = atual->anterior;
            atual->anterior = novo;
            novo->anterior->proximo = novo;
            l->q = l->q+1;
        }
    }
    
}


/* Exibe a LDE */
void mostrarLDE(struct stLDE *l)
{
    int q=0;
    struct stItemLDE *atual = l->inicio;

    while(atual!=NULL)
    {
        printf("%d\n", atual->chave);
        atual = atual->proximo;
        q++;
    }
}

/* Exibe a LLDE */
/* Exibe a LDDE 
 * Caso receba 1 exibira em ordem crescente
 * Caso receba -1 exibirá em ordem decrescente 
 */
void mostrarLDDE(struct stLDDE *l,int tipoExib)
{
    struct stItemLDDE *atual = l->inicio;
    if(l->q>0){
        if(tipoExib==1){
            do{
                printf("%d\n",atual->chave);
                atual = atual->proximo;
            }while(atual!=l->inicio);
        }else if(tipoExib==-1){
            atual = atual->anterior;
            do{
                printf("%d\n",atual->chave);
                atual = atual->anterior;
            }while(atual!=l->fim);
        }
    }
}


/* Remove um item qualquer dada a chave */
void removerLDE(struct stLDE *l,int chaveRemove){
    
    struct stItemLDE *atual = l->inicio, *anterior = NULL;
    while(atual!=NULL && atual->chave == chaveRemove){
        anterior = atual;
        atual = atual->proximo;
    }

    if(atual != NULL){
        if(anterior == NULL){
            l->inicio = atual->proximo;
        }else{
            anterior->proximo = atual->proximo;
        }
    }
}

int main(){
    struct stLDE lista;
    
    int isEOF=0;
    
    /* Inicializa o inicio da LDE */
    lista.inicio = NULL;
    
    /* Enquanto o arquivo não tiver acabado */
    while(!isEOF){
        
        char palavraAtu[110];
        /* Faz a leitura do prox caractere e verifica se é EOF */
        if(scanf("%s\n", &palavraAtu)==EOF){
            isEOF=1;     
        }else{
            struct stItem *item = criaItem(palavraAtu); 
            int retorno=inserir(&lista,item);
            
            /* Caso o retorno seja -1, exclui a palavra atual */
            if(retorno==-1){
                remover(&lista,palavraAtu);
            }    
        }
    }
    mostrar(&lista);
    
    return 0;
}
