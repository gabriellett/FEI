#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/***********************************************************/
/* Aluno: Gabriel Lett Viviani *//* 					   */
/* Exercicio  01 - Lista de Exercícios 08                  */
/* CC3651 --2012    --turma 610     				       */
/***********************************************************/

struct stRegistroHash{
    int chave;
    struct stRegistroHash *proximo;
};

struct stTabelaHash{
    struct stRegistroHash **tabela;
    int tamanho;
};

/* Inicia a tabela com nulos */
struct stTabelaHash iniciaTabelaHash (int tam){
    struct stTabelaHash retorno;
    int i;
    retorno.tamanho = tam;
    retorno.tabela = (struct stRegistroHash**) malloc (tam*sizeof(struct stRegistroHash*));
    for(i=0;i<retorno.tamanho;i++){
        retorno.tabela[i]=NULL;
    }
    return retorno;
}

/* Cria o registro */
struct stRegistroHash * criaRegistroHash (int chave){ 
    struct stRegistroHash *reg = (struct stRegistroHash*) malloc (sizeof(struct stRegistroHash));
    reg->chave = chave;
    reg->proximo = NULL;
    return reg;
}

/* Encontra o indice atraves do metodo da divisao */
int metodoDivisao(int chave, int tamanho){
    return chave % tamanho;
}

/* Encontra o indice atraves do metodo da multiplicação */
int metodoMultiplicacao(int chave, int tamanho){
    float aux = chave * 0.61803;
    // fmod: mod para numeros flutuantes;
    aux = fmod(aux,1);
    return (tamanho * (aux ));
}

/* Inclui um elemento dada a tabela, o proprio elemento e o indice */
int incluiHash (struct stRegistroHash *reg, struct stRegistroHash **tabHash,int ind){

    int j = 0;
    struct stRegistroHash *atual;
    struct stRegistroHash *anterior;
    
    
    if(tabHash[ind]!=NULL){
       atual = tabHash[ind];
       
       // Em caso de colisão
       while(atual!=NULL){
            if(atual->chave == reg->chave) return;
            anterior = atual;
            atual = atual->proximo;     
       }
       anterior->proximo=reg;
       atual = reg;
    }else{
        //Se for o primeiro 
        tabHash[ind] = reg;
    }
}

/* Remove um elemento da tabelaHash dada a chave, a tabela e o indice */
void remover(int chave,struct stTabelaHash *tabHash,int indice){
    
    // Struct do atual e do anterior 
    struct stRegistroHash *atual,*anterior;
    anterior = NULL;
    
    // Caso o indice esteja vazio, retorna
    if(tabHash->tabela[indice]==NULL)return;
    
    atual = tabHash->tabela[indice];
    
    // Caso o indice seja o primeiro e unico
    if(atual->chave==chave && atual->proximo==NULL){
        tabHash->tabela[indice]=NULL;
        return;
    }
    
    // Caso o indice seja primeiro e possua proximos
    if(atual->chave==chave){
        tabHash->tabela[indice]=atual->proximo;
        free(atual);
        return;
    }
    
    // Caso não seja o primeiro
    while(atual!=NULL){

        //Quando encontrar
        if(atual->chave == chave){
            
            // Se for ultimo
            if(atual->proximo==NULL){
                atual=NULL;
                if(anterior!=NULL){
                    anterior->proximo=NULL;
                }else{
                    tabHash->tabela[indice]=NULL;
                }
                free(atual);
            }else{
                //Se estiver no meio
                anterior->proximo = atual->proximo;
            }
            return;
            
        }else{
            anterior = atual;
            atual = atual->proximo;
        }
    }
    return;    
}

/* Exibe a tabela Hash */
void mostrar(struct stTabelaHash *tabHash){
    int i;
    
    // Percorre todos indices da tabela 
    for(i=0;i<tabHash->tamanho;i++){
        printf("[%d]:",i);
        struct stRegistroHash *atual;
        atual = tabHash->tabela[i];
        if(atual!=NULL){
            //Exibe o indice atual até encontrar o nulo
            while(atual!=NULL){
                printf(" %d",atual->chave);
                atual=atual->proximo;
            }
        }else{
            //Caso esteja vazio
            printf(" livre");
        }
        printf("\n");
    }
}
int main(){
    
    // Declara a tabela
    struct stTabelaHash tabelaHash;
    int i,j;
    int it;
    char op;
    
    // Seta o tamanho
    scanf("%d\n", &tabelaHash.tamanho);
    scanf("%c\n", &op);
    
    // Inicia a tabela com nulos
    tabelaHash = iniciaTabelaHash(tabelaHash.tamanho);
    char tipoAtu;
    int chaveAtu;

    // Caso seja metodo da divisao
    if(op=='D'){
        // Recebe a operação e a chave até EOF
        while(scanf("%c:%d\n",&tipoAtu,&chaveAtu)!=EOF){ 
            
            //Caso ação seja incluir
            if(tipoAtu=='I'){
                incluiHash(criaRegistroHash(chaveAtu),tabelaHash.tabela,metodoDivisao(chaveAtu,tabelaHash.tamanho));
            //Caso ação seja remover
            }else{
                remover(chaveAtu,&tabelaHash,metodoDivisao(chaveAtu,tabelaHash.tamanho));
            }
        }   
    // Caso seja metodo da multiplicação
    }else if(op=='M'){
        // Recebe a operação e a chave até EOF
        while(scanf("%c:%d\n",&tipoAtu,&chaveAtu)!=EOF){ 
            //Caso ação seja Incluir
            if(tipoAtu=='I'){
                incluiHash(criaRegistroHash(chaveAtu),tabelaHash.tabela,metodoMultiplicacao(chaveAtu,tabelaHash.tamanho));
            //Caso ação seja remover
            }else{
                remover(chaveAtu,&tabelaHash,metodoMultiplicacao(chaveAtu,tabelaHash.tamanho));
            }
        }   
       
    }
    //Exibe a tabela Hash;
    mostrar(&tabelaHash);
}
