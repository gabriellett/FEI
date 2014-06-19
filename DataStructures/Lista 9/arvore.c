#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************************************/
/* Aluno: Gabriel Lett Viviani *//* 					   */
/* Exercicio  01 - Lista de Exercícios 09                  */
/* CC3651 --2012    --turma 610     					   */
/***********************************************************/



/* Struct dos nos */
struct stNoArvore{
    struct stNoArvore * filhoDireito;
    struct stNoArvore * filhoEsquerdo;
    struct stNoArvore * pai;
    int chave;
};

/* Struct da arvore */
struct stArvore{
    struct stNoArvore * raiz;
    int quantRotacoes;
};

void leftRotate(struct stArvore * arvore,struct stNoArvore * noX){
     struct stNoArvore * noY = noX->filhoDireito;
     
    printf("\nLEFT:\n noX:%d--%d/%d,%d",noX->pai==NULL?99:noX->pai->chave,noX->chave,noX->filhoEsquerdo==NULL?99:noX->filhoEsquerdo->chave,noX->filhoDireito==NULL?99:noX->filhoDireito->chave);
    printf("\n noY:%d--%d/%d,%d",noY->pai==NULL?99:noY->pai->chave,noY->chave,noY->filhoEsquerdo==NULL?99:noY->filhoEsquerdo->chave,noY->filhoDireito==NULL?99:noY->filhoDireito->chave);
    
   
    noX->filhoDireito = noY->filhoEsquerdo;
    noY->pai = noX->pai;
    if(noX->pai == NULL){
        arvore->raiz=noY;
    }else if(noX->pai->filhoDireito == noX){
        noX->pai->filhoDireito = noY;
    }else{
        noX->pai->filhoEsquerdo = noY;
    }
    noY->filhoEsquerdo=noX;
    noX->pai = noY;
    printf("-------SOMEI--------");
    arvore->quantRotacoes = arvore->quantRotacoes+1;
    
    
     
    printf("\n noX:%d--%d/%d,%d",noX->pai==NULL?99:noX->pai->chave,noX->chave,noX->filhoEsquerdo==NULL?99:noX->filhoEsquerdo->chave,noX->filhoDireito==NULL?99:noX->filhoDireito->chave);
    printf("\n noY:%d--%d/%d,%d",noY->pai==NULL?99:noY->pai->chave,noY->chave,noY->filhoEsquerdo==NULL?99:noY->filhoEsquerdo->chave,noY->filhoDireito==NULL?99:noY->filhoDireito->chave);
    
   
}



void rightRotate(struct stArvore * arvore,struct stNoArvore * noY){
    
    struct stNoArvore * noX = noY->filhoEsquerdo;
    
    printf("\nRIGHT\n noX:%d--%d/%d,%d",noX->pai==NULL?99:noX->pai->chave,noX->chave,noX->filhoEsquerdo==NULL?99:noX->filhoEsquerdo->chave,noX->filhoDireito==NULL?99:noX->filhoDireito->chave);
    printf("\n noY:%d--%d/%d,%d",noY->pai==NULL?99:noY->pai->chave,noY->chave,noY->filhoEsquerdo==NULL?99:noY->filhoEsquerdo->chave,noY->filhoDireito==NULL?99:noY->filhoDireito->chave);
    
    noY->filhoEsquerdo = noX->filhoDireito;
    noX->pai = noY->pai;
    if(noY->pai == NULL){
        arvore->raiz=noX;
        printf("ROTEI RAIZ");
    }else if(noY->pai->filhoDireito == noY){
        noY->pai->filhoDireito = noX;
        printf("ROTEI FILHO DIREITO");
    }else{
        noY->pai->filhoEsquerdo = noX;
        printf("ROTEI FILHO ESQUERDO");
    }
    
    noX->filhoDireito = noY;
    noY->pai = noX;
    printf("\n noX:%d--%d/%d,%d",noX->pai==NULL?99:noX->pai->chave,noX->chave,noX->filhoEsquerdo==NULL?99:noX->filhoEsquerdo->chave,noX->filhoDireito==NULL?99:noX->filhoDireito->chave);
    printf("\n noY:%d--%d/%d,%d",noY->pai==NULL?99:noY->pai->chave,noY->chave,noY->filhoEsquerdo==NULL?99:noY->filhoEsquerdo->chave,noY->filhoDireito==NULL?99:noY->filhoDireito->chave);
    
    printf("-------SOMEI-------");
    arvore->quantRotacoes = arvore->quantRotacoes+1;
    
}

void corrigeBalanceamento(struct stArvore * arvore,struct stNoArvore * noAtual){
    int aux=0;


        
        int fatorE = calcularAltura(noAtual->filhoEsquerdo);
        printf("OK B");
        int fatorD = calcularAltura(noAtual->filhoDireito);
        printf("OK C");
        int fatorR = fatorE-fatorD;
        
        printf("fatorR:%d\n",fatorR);
        if (fatorR==-2){
            
            printf("fatorD:%d\n",fatorD);
            if(fatorD==1){
                rightRotate(arvore,noAtual->filhoDireito);
            }
            leftRotate(arvore,noAtual);
        }else if(fatorR==2){
            printf("fatorE:%d\n",fatorE);
            if(fatorE==-1){
                leftRotate(arvore,noAtual->filhoEsquerdo);
            }
            rightRotate(arvore,noAtual);
        }
       
    
    if(noAtual->pai!=NULL){
        corrigeBalanceamento(arvore,noAtual->pai);
    }
}

/* Função inserir */
void inserirNo(struct stArvore * arvore, int chave){
    
    // Declara o no atual */
    struct stNoArvore * noAtual = arvore->raiz;
    
    // Vars. utlizadas para definir se o filho será esquerdo ou direito
    int isFilDir=0;
    int isFilEsq=0;
    
    // Auxiliar do Pai */
    struct stNoArvore *pai;
    
    // Percorre até encontrar a posição */
    while(noAtual!=NULL){
        pai=NULL;

        // Zera as auxiliares de definição do 'lado' do pai 
        isFilDir=0;
        isFilEsq=0;
        
        //Caso as chaves sejam iguais 
        if(noAtual->chave == chave){
            return;
        }
        
        // Caso contrário 
        pai=noAtual;
        
        // Se a chave for menor que o no atual, vai para esquerda 
        if(chave < noAtual->chave){
            noAtual = noAtual->filhoEsquerdo;
            isFilEsq=1;
            
        // Caso contrario, vai para direita
        }else if(chave > noAtual->chave){
            noAtual = noAtual->filhoDireito;
            isFilDir=1;
        }
    }
    
    // Ao encontrar a posição
    if(noAtual==NULL){
        // Declara o novo nó
        struct stNoArvore *noAtual = (struct stNoArvore*) malloc (sizeof(struct stNoArvore));
        
        // Seta as chaves
        noAtual->chave = chave;
        
        // Anula os filhos
        noAtual->filhoDireito = NULL;
        noAtual->filhoEsquerdo = NULL;
        
        // Seta o filho do pai correto 
        if(isFilDir==1){
            noAtual->pai = pai;
            pai->filhoDireito = noAtual;
        }else if(isFilEsq==1){
            noAtual->pai = pai;
            pai->filhoEsquerdo = noAtual;
        }else{
            noAtual->pai = NULL;
            arvore->raiz = noAtual;
        }
        
        corrigeBalanceamento(arvore,noAtual);
        // ** FIM **
        return;
    }
}


// Exibe em pré
void mostraPre(struct stNoArvore * atual){
    if(atual != NULL){
     printf("%d\n",atual->chave);
     mostraPre(atual->filhoEsquerdo);
     mostraPre(atual->filhoDireito);
    }
}

// Exibe em Pós
void mostraPos(struct stNoArvore * atual){
    if(atual != NULL){
     mostraPos(atual->filhoEsquerdo);
     mostraPos(atual->filhoDireito);
     printf("%d\n",atual->chave);
    }
}

// Exibe em In
void mostraIn(struct stNoArvore * atual){
    if(atual != NULL){
     mostraIn(atual->filhoEsquerdo);
     printf("%d\n",atual->chave);
     mostraIn(atual->filhoDireito);
    }
}

// Retorna a altura da arvore
int calcularAltura(struct stNoArvore * atual){
    if(atual == NULL){
        return 0;
    }else if(atual->filhoEsquerdo == NULL && atual->filhoDireito == NULL){
        return 0;
    }else{
        int altEsq = calcularAltura(atual->filhoEsquerdo);
        int altDir = calcularAltura(atual->filhoDireito);
        if(altEsq>altDir){
            return 1+altEsq;
        }else{
            return 1+altDir;
        }
    }
}

int main(){
    
    // Declara a arvore
    struct stArvore arvore;
    
    // Anual a raiz
    arvore.raiz=NULL;
    
    //Zera a quantidade de rotações
    arvore.quantRotacoes = 0;
    
    // Guarda se é pre, pos ou in
    char tipMos[5];
    scanf("%s\n", &tipMos);
    
    // Guarda a chave atual
    int chaveAtu;

    // Enquanto não encontrar o fim do arquivo txt
    while(scanf("%d\n",&chaveAtu)!=EOF){ 
        // Insere a chave atual;
        inserirNo(&arvore,chaveAtu);
    }

    // Exibe utilizando o algoritimo desejado
    if(strcmp(tipMos,"PRE")){
        mostraPre(arvore.raiz);
    }else if(strcmp(tipMos,"POS")){
        mostraPos(arvore.raiz);
    }else if(strcmp(tipMos,"IN")){
        mostraIn(arvore.raiz);
    }

    // Exibe a altura;    
    printf("%d\n%d",calcularAltura(arvore.raiz),arvore.quantRotacoes);

}


    
