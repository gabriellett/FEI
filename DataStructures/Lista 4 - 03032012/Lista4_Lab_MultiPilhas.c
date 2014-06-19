#include <stdio.h>
#include <stdlib.h>

/***********************************************************/
/* Aluno: Gabriel Lett Viviani *//* 					   */
/* Exercicio  01 - Lista de Exercícios 03                  */
/* CC3651 --2012    --turma 610    						   */
/***********************************************************/
struct stPilha{
    int *itens;
    int topo;       
};

struct stLista{
    struct stPilha *pilhas;
    int quantPilhas;
};

void empilhaItem(struct stLista *,int,int,int);
void desempilha(struct stLista*,int);
void mostraPilhas(struct stLista);

int main()
{
    struct stLista lista;
    int i,j;
    int it;
    char op;
    scanf("%d\n", &lista.quantPilhas);
    lista.pilhas=(struct stPilha*)malloc(sizeof(struct stPilha)*lista.quantPilhas);

    for(i=0;i<lista.quantPilhas;i++){  
        int tamPilha=0,quantOp=-1;
        scanf("%d\n", &tamPilha);
        scanf("%d\n", &quantOp); 
        lista.pilhas[i].itens=(int*)calloc(sizeof(int),tamPilha);
        lista.pilhas[i].topo=-1;
        for(j=0;j<quantOp;j++){
            scanf("%c:%d\n", &op, &it);
            if(op=='E')
                empilhaItem(&lista,i,it,tamPilha);
            else
                desempilha(&lista,i);
                
        }
    }   

    mostraPilhas(lista);
}

void empilhaItem(struct stLista* lista,int codPilha,int it,int tamanho){
    if(lista->pilhas[codPilha].topo+1!=tamanho){
        lista->pilhas[codPilha].topo = lista->pilhas[codPilha].topo+1;
        lista->pilhas[codPilha].itens[lista->pilhas[codPilha].topo] = it;
    }
}

void desempilha(struct stLista* lista,int codPilha){
    if(lista->pilhas[codPilha].topo!=-1){
        lista->pilhas[codPilha].topo = lista->pilhas[codPilha].topo-1;
    }
}

void mostraPilhas(struct stLista lista){
    int i,j;
    for(i=0;i<lista.quantPilhas;i++){
        printf("Pilha %d:\n",i);
        
        if(lista.pilhas[i].topo!=-1){  
            if(i%2==0){
                for(j=lista.pilhas[i].topo;j>=0;j--){
                    printf("%d\n",lista.pilhas[i].itens[j]);
                }
            }else{ 
                for(j=0;j<=lista.pilhas[i].topo;j++){
                    printf("%d\n",lista.pilhas[i].itens[j]);
                }
            }
        }else{
            printf("Pilha Vazia!\n");
        }
    }
}
     
     

