#include <stdio.h>
#include <stdlib.h>

/***********************************************************/
/* Aluno: Gabriel Lett Viviani 
/* Exercicio  02 - Lista de Exercícios 04                  */
/* CC3651 --2012    --turma 610 
/***********************************************************/

/* Pilha */
struct stPilha{
    char palavra[110];
    int topo;       
};


void empilhaItem(struct stPilha *,char);
char desempilha(struct stPilha*);

/**
 * Main
 */
int main()
{
    /* Declara a struct pilha */
    struct stPilha pilha;

    /* Declara a variavel do char atual */
    char charAtu;
    
    /* Inicializa o char atual */
    scanf("%c", &charAtu);
    
    /* Variavel boleana que indica se o char atual é o EOF */
    int isEOF=0;
    
    /* Enquanto o arquivo não tiver acabado */
    while(!isEOF){
        /* Inicializa a pilha da palavra */
        pilha.topo=-1;
        
        /* Enquanto o arquivo não acabar e não terminar a palavra */
        while(charAtu!='\n' && !isEOF ){
            /* Empilha o caractere atual */
            empilhaItem(&pilha,charAtu);
            
            /* Faz a leitura do prox caractere e verifica se é EOF */
            if(scanf("%c", &charAtu)==EOF){
                isEOF=1;     
            }
        }
        
        /* Copia a palavra atual para uma aux */
        char palavraAux[110];
        strcpy(palavraAux,pilha.palavra);
        
        /* É palindromo até que prove-se o contrário */
        int isPalindromo = 1;
        
        /* Inicializa e declara o char atual (ultimo char da palavra */
        char aux=desempilha(&pilha);
        
        int i;
        
        /* Enquanto a pilha não esrtiver vazia */
        for(i=0;aux!=0;i++,aux=desempilha(&pilha)){
            
            /* Se o caractere não for = ao seu correspondente não é palindromo */
            if(aux!=pilha.palavra[i]){
                printf("Nao eh palindromo\n");
                isPalindromo=0;
                break; /* Sai do laço */
            }
        }
        
        /* Se continua sendo palindromo, é palindromo */
        if (isPalindromo){
            printf("Eh palindromo\n");
        }   
        
        /* Le o proximo caractere e verifica se é EOF */
        if(scanf("%c", &charAtu)==EOF){
            break; /* Se for EOF sai do laço */
        }
    }
}

/**
 * Empilha um caractere 'it' na pilha 'pilha' .
 */
void empilhaItem(struct stPilha* pilha,char it){
    if(pilha->topo+1!=100){
        pilha->topo = pilha->topo+1; /* Incrementa o topo */
        pilha->palavra[pilha->topo] = it;
    }
}

/**
 * Desempilha da pilha 'pilha' e retorna o caractere desempilhado.
 */
char desempilha(struct stPilha* pilha){
    if(pilha->topo!=-1){
        char charAtu = pilha->palavra[pilha->topo];
        pilha->topo = pilha->topo-1; /* Diminui o topo */
        return charAtu;
    }
    return 0; /* Caso a pilha esteja vazia retorna 0 */
}

     

