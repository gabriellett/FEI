#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************************************/
/* Aluno: Gabriel Lett Viviani *//*						   */
/* Exercicio  01 - Lista de Exercícios 11                  */
/* CC3651 --2012    --turma 610     					   */
/***********************************************************/


struct stHeap { 
    int *itens;
    int quantidade;
};

int filhoEsquerdo(int);
int filhoDireito(int);
void peneiraMax(struct stHeap *,int pai);
void peneniraMin(struct stHeap *,int pai);
void removeMax(struct stHeap *);
void contruirHeap(struct stHeap *,char);
void mostrar(struct stHeap *);
void heapSort(struct stHeap *,char);

int main(){
    
    struct stHeap heap;
    heap.quantidade = 0;
    
    // Guarda se o tipo de ordenação é crescende ou descrescente
    char tipOrd;
    scanf("%s\n", &tipOrd);
    
    // Guarda o tamanho do heap
    int tamanho;
    scanf("%d\n", &tamanho);
    heap.itens = malloc(tamanho * sizeof(int));
        
    // Le todos os n numeros
    int i,numAtu;
    for(i=0;i<tamanho;i++){
        scanf("%d\n",&numAtu);
        heap.itens[i] = numAtu;
        heap.quantidade = heap.quantidade+1;
    }
    
    // Organiza o heap
    heapSort(&heap,tipOrd);
    
    // Mostra o heap ordenado
    mostrar(&heap);
    
    return 0;
}

// Obtem o filho esquerdo da chave
int filhoEsquerdo(int pai){
    return ((2*pai)+1);
}

// Obtem o filho direito da chave
int filhoDireito(int pai){
    return ((2*pai)+2);
}

int ultimoPai(struct stHeap heap){
    return (heap.quantidade/2)-1;
}

// Peneira para ordenar crescente
void peneirarMax ( struct stHeap *heap, int pai ) { 
    int esq = filhoEsquerdo(pai), 
        dir = filhoDireito(pai), 
        maior, 
        aux; 
    if ( esq < heap->quantidade && heap->itens[esq] > heap->itens[pai] ) { 
        maior = esq; 
    } else { 
        maior = pai; 
    }
    if ( dir < heap->quantidade && heap->itens[dir] > heap->itens[maior] ) { 
        maior = dir; 
    } 
    if ( maior != pai ) { 
        aux = heap->itens[pai]; 
        heap->itens[pai] = heap->itens[maior]; 
        heap->itens[maior] = aux; 
        peneirarMax(heap, maior); 
    } 
}

// Peneira para ordenar descrescente
void peneirarMin ( struct stHeap *heap, int pai ) { 
    int esq = filhoEsquerdo(pai), 
        dir = filhoDireito(pai), 
        menor, 
        aux; 
    if ((esq<heap->quantidade) && (heap->itens[esq]<heap->itens[pai])){ 
        menor = esq; 
    } else { 
        menor = pai; 
    }
    if ((dir<heap->quantidade) && (heap->itens[dir]<heap->itens[menor])){ 
        menor = dir; 
    } 
    if(menor!=pai){ 
        aux = heap->itens[pai]; 
        heap->itens[pai] = heap->itens[menor]; 
        heap->itens[menor] = aux; 
        peneirarMin(heap, menor); 
    } 
}

// Constroi o heap utilizando o peneirar correto
void construirHeap(struct stHeap *heap,char tipo){ 
    int i; 
    if(tipo=='C'){
        for ( i = ultimoPai ( *heap ); i >= 0; i--) {
            peneirarMax ( heap, i ); 
        } 
    }else if(tipo=='D'){
        for ( i = ultimoPai ( *heap ); i >= 0; i--) {
            peneirarMin ( heap, i ); 
        } 
    }
}

//  Remove o máximo
void removeMax(struct stHeap *heap){
    // Armazena a raiz 
    int aux = heap->itens[0];
    
    // Recebe o ultimo item
    heap->itens[0] = heap->itens[heap->quantidade-1];
    
    // Passa a raiz para o fim
    heap->itens[heap->quantidade-1]=aux;
    
    // Remove a raiz decrementando o tamanho
    heap->quantidade--;
}

// Ordena o heap
void heapSort(struct stHeap *heap,char tipOrd){
    int tam = heap->quantidade;
    
    // Constroi o heap
    construirHeap(heap,tipOrd);
    
    int i;
    
    // Remove item por item e reconstroi logo apos
    for(i=0;i<tam;i++){ 
        removeMax(heap);
        construirHeap(heap,tipOrd);
    }
    
    // Volta o tamanho do heap para o inicial
    heap->quantidade=tam;
}


// Exibe o heap na tela
void mostrar(struct stHeap *heap)
{
    int i;
    for(i=0 ; i<heap->quantidade ; i++){
        printf("%d\n",heap->itens[i]);
    }
}

