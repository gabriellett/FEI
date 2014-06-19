#include <stdio.h>
#include <stdlib.h>

/***********************************************************/
/* Aluno: Gabriel Lett Viviani 
/* Exercicio  01 - Lista de Exercícios 06                  */
/* CC3651 --2012    --turma 610  
/***********************************************************/



struct stItem{
    int chave;
    struct stItem *proximo;
    struct stItem *anterior;
};

struct stLDDE{
    int q;
    struct stItem *inicio;
    struct stItem *fim;
};

/* Cria um novo item */
struct stItem * criaItem(int chave)
{
    struct stItem *it = (struct stItem*) malloc(sizeof(struct stItem));
    if(it != NULL)
    {
        it->chave = chave;
        it->proximo = NULL;
        it->anterior = NULL;
    }
    return it;
};

void inserir(struct stLDDE *l, struct stItem *novo)
{
    struct stItem *atual=l->inicio;
    
    if(l->inicio == NULL){
        l->inicio = novo;
        l->fim = novo;
        novo->anterior = novo;
        novo->proximo = novo;
        l->q=1;
    }else{
        if(novo->chave!=atual->chave){
            int achei = 0;
            
            do{
                if(atual->chave > novo->chave){
                    achei=1;
                }else if(atual->chave < novo->chave){
                    atual = atual->proximo;
                }else{
                    free(novo);
                    achei=-1;
                    return;
                }
            }while(achei==0 && atual!=l->inicio);
            
            /* Insere no Fim */
            if(achei==0){
                atual = atual->anterior;
                atual->proximo = novo;
                l->fim = novo;
                novo->anterior = atual;
                novo->proximo = l->inicio;
                (l->inicio)->anterior = novo;
                l->q = l->q+1;
            /* Insere no Inicio */
            }else if(atual == l->inicio){
                l->inicio = novo;
                atual->anterior = novo;
                if(l->q==1){
                    atual->proximo = novo;
                }
                novo->proximo = atual;
                novo->anterior = l->fim;
                l->fim->proximo = novo;
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
}

/* Exibe a LDDE 
 * Caso receba 1 exibira em ordem crescente
 * Caso receba -1 exibirá em ordem decrescente 
 */
void mostrar(struct stLDDE *l,int tipoExib)
{
    struct stItem *atual = l->inicio;
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

/* Remove um item qualquer dada o tipo e o ind */
void remover(struct stLDDE *l,char indAtu, int indRem){
    int i;
    struct stItem *atual = l->inicio;
    if(l->q!=1){
        if(indAtu == 'D'){
            for(i=0;i<indRem;i++){
                atual = atual->proximo;
            }
        }else if(indAtu=='E'){
            for(i=0;i<indRem;i++){
                atual = atual->anterior;
            }        
        }
        
        if(atual==l->inicio){
            l->inicio = atual->proximo;
        }else if(atual==l->fim){
            l->fim = atual->anterior;
        }
       (atual->anterior)->proximo = atual->proximo;
       (atual->proximo)->anterior = atual->anterior;
    }else{
        l->inicio=NULL;
        l->fim=NULL;
    }
    l->q = l->q-1;
    free(atual);
}

int main(){
    struct stLDDE lista;
    
    int isEOF=0;
    
    /* Inicializa o inicio da LDE */
    lista.inicio = NULL;
    lista.fim = NULL;
    lista.q = 0;
    /* Enquanto o arquivo não tiver acabado */
    
    int q,i;
    char tipoAtu;
    int indRem;
    scanf("%d\n", &q);
    for(i=0;i<q;i++){
        
        int numAtu;
        scanf("%d\n", &numAtu);
        struct stItem *item = criaItem(numAtu); 
        inserir(&lista,item);
        
        
    }
    /* Faz a leitura do prox caractere e verifica se é EOF */
    while(scanf("%c:%d\n",&tipoAtu,&indRem)!=EOF){ 
        if(lista.q!=0){
            remover(&lista,tipoAtu,indRem);
        }
    }
    if(lista.q%2==0){  
        mostrar(&lista,1);
    }else{
        mostrar(&lista,-1);
    }
    
    return 0;
}
