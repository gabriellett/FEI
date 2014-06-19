#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************************************/
/* Aluno: Gabriel Lett Viviani
/* Exercicio  01 - Lista de Exercícios 05                  */
/* CC3651 --2012    --turma 610 
/***********************************************************/

char ordemLexicografica[26] = "abcdefghijklmnopqrstuvwxyz";

struct stItem{
    char palavra[110];
    struct stItem *proximo;
};

struct stLDE{
    struct stItem *inicio;
};


 /*
  * Retorna a posical da letra no alfabeto atual 
  */
 int posicaoLetra(char letra){
    int i = 0 ;
    while(ordemLexicografica[i]!=letra){
        i++;
        if(i==26){
            return -1;
        }
    }
    return i;
}

/* Retorna:
 *          -1 caso a primeira for anterior a segunda
 *          0 caso as duas forem iguais
 *          1 caso a segunda for anterior a primeira 
 */
int verificaPalavra(char primPalavra[105],char segPalavra[105]){
    int tamPrim = tamanhoString(primPalavra);
    int tamSeg = tamanhoString(segPalavra);
    int i=0;
    while(primPalavra[i]!= 0 && segPalavra[i]!=0){
        if(primPalavra[i] != segPalavra[i]){
            int posLetraPrim = posicaoLetra(primPalavra[i]); 
            int posLetraSeg = posicaoLetra(segPalavra[i]);
            if(posLetraPrim<posLetraSeg){
                return -1;
            }else{
                return 1;
            }
        }
        i++;
    }
    if(tamPrim<tamSeg){
        return -1;
    }else if(tamSeg<tamPrim){
        return 1;
    }
    return 0;
}

/* Retorna o tamanho da String */
int tamanhoString(char palavra[110]){
    int i=0;
    while(palavra[i]!=0){
        i++;
    }
    return i;
}

/* Cria um novo item */
struct stItem * criaItem(char palavra[110])
{
    struct stItem *it = (struct stItem*) malloc(sizeof(struct stItem));
    if(it != NULL)
    {
        strcpy(it->palavra,palavra);
        it->proximo = NULL;
    }
    return it;
}

/*
 * Retorna -1 caso deva excluir e 1 caso tenha inserido
 */
int inserir(struct stLDE *l, struct stItem *novo)
{
    struct stItem *atual=l->inicio, *anterior=NULL;
    if(l->inicio == NULL){
        l->inicio = novo;
    }else{
        if(verificaPalavra(novo->palavra,atual->palavra)!=0){
            int achei = 0;
            
            while(atual!=NULL && achei==0){
                if(verificaPalavra(atual->palavra, novo->palavra)==1){
                    achei = 1;
                }else if(verificaPalavra(atual->palavra, novo->palavra)==-1){
                    anterior = atual;
                    atual = atual->proximo;
                }else{
                    return -1;
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
        }else{
            return -1;
        }
    }
    return 1;
}

/* Exibe a LDE */
void mostrar(struct stLDE *l)
{
    int q=0;
    struct stItem *atual = l->inicio;

    while(atual!=NULL)
    {
        printf("%s\n", atual->palavra);
        atual = atual->proximo;
        q++;
    }
}

/* Remove um item qualquer dada a palavra */
void remover(struct stLDE *l,char palavraRemove[110]){
    
    struct stItem *atual = l->inicio, *anterior = NULL;
    while(atual!=NULL && verificaPalavra(atual->palavra,palavraRemove)!=0){
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
