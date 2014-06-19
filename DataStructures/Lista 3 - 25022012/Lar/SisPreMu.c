#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/***********************************************************/
/* Aluno: Gabriel Lett Viviani *//*						   */
/* Exercicio  02 - Lista de Exercícios 03                  */
/* CC3651 --2012    --turma 610     		               */
/***********************************************************/

#define TAM 30

/**
 * Struct das faixas do CD
 */
 
struct stFaixa
{
    int idFaixa;
    int tamFaixa;
    char nomeFaixa[110];
};

/* Struct do CD */

struct stCD
{
    struct stFaixa faixas[TAM];
    int quantFaixas;
};

struct stFila{
    int *itens;
    int inicio,fim;
    int tam;
};

void enfileiraFaixa(struct stFila *,int);
void desenfileiraFaixa(struct stFila*);
void limpaFila(struct stFila*);

void carregarCD(struct stCD *);
void verFaixas(struct stCD);
void cadastraSequencia(struct stCD,struct stFila *);
void tocarSequencia(struct stCD,struct stFila);
void ejetarCD(struct stCD *,struct stFila *);

void dorme(unsigned int);

int menu();
void verificaOpcao(int,struct stCD *);
int buscaBinariaFaixas(struct stCD,int,int,int);

int main(){
    /* Lista do CD */
    struct stCD lista;
    struct stFila fila;
    fila.inicio=-1;
    fila.fim=-1;
    fila.tam=0;
    lista.quantFaixas = 0;
    
    int opcao=-1;
    char resp = 'a';
    do{
        /* Enquanto a opção for diferente de sair */
        while(opcao!=6){
            opcao = menu();
            if(opcao==1){
                /* Verifica se existe CD carregado */
                if(lista.quantFaixas!=0){
                    printf("\nAtencao, já existe CD carregado! \n\n    Somente e' possivel cadastrar novas faixas se\n  nao existirem faixas cadastradas!\n"); 
                    system("pause");
                }else{
                    carregarCD(&lista);
                }
            }else if(opcao==2){
                /* Verifica se existem faixas cadastradas */
                if(lista.quantFaixas==0){
                    printf("\nAtencao, nao existem faixas cadastradas! \n\n    Somente e' possivel ver faixas se\n  existirem faixas cadastradas!\n"); 
                    system("pause");
                }else{
                    verFaixas(lista);
                }
            }else if(opcao==3){
                /* Verifica se existem faixas cadastradas */
                if(lista.quantFaixas==0){
                    printf("\nAtencao, nao existem faixas cadastradas! \n\n    Somente e' possivel cadastrar sequencias se\n  existirem faixas cadastradas!\n"); 
                    system("pause");
                }else{
                    cadastraSequencia(lista,&fila);
                }
            }else if(opcao==4){
                /* Verifica se existem faixas enfileiradas */
                if(fila.inicio==-1 && fila.fim==-1){
                    printf("\nAtencao, nao existe sequencia cadastrada! \n\n    Por favor, cadastre uma sequencia para poder toca-la!\n"); 
                    system("pause");
                }else{
                    tocarSequencia(lista,fila);
                }
            }else if(opcao==5){
                /* Verifica se existem vendas cadastradas */
                if(lista.quantFaixas==0){
                    printf("\nAtencao, nao existe CD carregado! \n\n    Somente e' possivel ejetar CD se\n  existir CD carregado!\n"); 
                    system("pause");
                }else{
                    ejetarCD(&lista,&fila);
                }
                
            }          
        }
        setbuf(stdin, NULL);
        printf("Deseja realmente sair?  (<s> para sim, qualquer outra coisa para nao)");

        scanf("%c",&resp);
    }while(resp !='s' && resp != 'S');

    return 0;
}

/* Metodo que exibe o menu e sómente retorna quando o numero digitado for valido */
int menu(){
    int opcao;
    do{
        setbuf(stdin, NULL);
        system("cls");
        printf("--------------- SisPreMu ---------------\nEscolha uma das opções a seguir:\n\n   1 - Carregar CD\n   2 - Ver Faixas\n   3 - Cadastrar Sequencia\n   4 - Tocar Sequencia\n   5 - Ejetar CD\n   6 - Sair\n\n  Opcao:");
        scanf("%d",&opcao);
    }while(opcao <1 || opcao >6);

    return opcao;
}


/* Cadastra uma sequencia */
void cadastraSequencia(struct stCD lista,struct stFila *fila){
    int quant = -1;
    
    while(quant<=0){
        printf("Digite o tamanho da sequencia (>0):");
        scanf("%d",&quant);
    }
    system("cls");
   
    fila->itens = (int)malloc(sizeof(int)*quant);
                        
    
    int i=0;
    
    fila->inicio=-1;
    fila->fim=-1;
    fila->tam=quant;
    
    for(i=0;i<quant;i++){
        int indFound=-1;
        int codigoFaixa;
        while(indFound==-1){
            printf("Digite o codigo da faixa:");
            scanf("%d",&codigoFaixa);
            
            indFound = buscaBinariaFaixas(lista,codigoFaixa,0,lista.quantFaixas);
            if(indFound==-1){
                printf("Faixa não encontrada! Tente novamente!");
                system("pause");
                system("cls");
            }
        }
         system("cls");
                
        int segTotal = lista.faixas[indFound].tamFaixa;
        
        int hora,minuto,segundo;
        if ((segTotal/60)>0){
            segundo = segTotal%60;
            segTotal = segTotal-segundo;
        }
        segTotal = segTotal/60;
        if ((segTotal)>60){
            minuto = segTotal%60;
            segTotal = (segTotal-minuto)/60;
        }else{
            minuto = segTotal;
            segTotal = 0;
        }
        
        enfileiraFaixa(fila,codigoFaixa);
        printf("ID: %d   | %s | %d:%d:%d - Faixa Enfileirada!\n",lista.faixas[indFound].idFaixa,lista.faixas[indFound].nomeFaixa,segTotal,minuto,segundo);
        system("pause");
    }
}

/* Exibe as faixas carregadas no sistema */
void verFaixas(struct stCD lista){
    system("cls");
    int i=0;
    for(i=0;i<lista.quantFaixas;i++){
        int segTotal = lista.faixas[i].tamFaixa;
        int hora,minuto,segundo;
        
        segundo = segTotal%60;
        segTotal = segTotal-segundo;
        
        segTotal = segTotal/60;
        if ((segTotal)>60){
            minuto = segTotal%60;
            segTotal = (segTotal-minuto)/60;
        }else{
            minuto = segTotal;
            segTotal = 0;
        }
        printf("ID: %d   | %s | %d:%d:%d \n",lista.faixas[i].idFaixa,lista.faixas[i].nomeFaixa,segTotal,minuto,segundo);
    }
    printf("\n\n");
    system("pause");
}

void carregarCD(struct stCD *lista){
    
    FILE *arquivo;
    char nomeArq[100];
    int i=0;
    system("cls");
    /* Pede o nome do arquivo até encontrar o arquivo */
    do{
        setbuf(stdin, NULL);
        printf("\nInforme o nome do arquivo do CD: ");
        gets(nomeArq);
        arquivo = fopen(nomeArq, "r");
        if(arquivo==NULL)
            printf("Arquivo %s nao existe, favor informar um nome valido!\n", nomeArq);
    }while(arquivo==NULL);
    
    char ch='\0';
    int nLinhas = 0;
    
    /* Le a quantidade de linhas no arquivo */
    while(ch!=EOF){
        ch=fgetc(arquivo);
        if(ch=='\n')nLinhas++;    
    }
    
    if(nLinhas>30){
        printf("Atencao! O arquivo selecionado possui mais de 30 faixas!\nSomente as 30 primeiras serao carregadas!");
        system("pause");
    }
    fclose(arquivo);
   
    arquivo = fopen(nomeArq, "r");
    
    int n;
    char linha[500],strNomeFaixa[110],strCodigo[4],strTempo[8];
         
    for(n=0;n<nLinhas && n<30;n++){
        
        /* Separa a linha em diversas strings */
        char chLinha='\0';
        int y=0;
        while(chLinha!='\n'){
            chLinha=fgetc(arquivo);
            if(chLinha!='\n'){
                linha[y]=chLinha;    
                y++;
            }else{
                linha[y]=0;
            }
        }
        
        int l,m;
        for(l=0,m=0;linha[l]!=':';l++,m++){
            strCodigo[m]=linha[l];
        }
        strCodigo[m]=0;
        
        l++;
        for(m=0;linha[l]!=':';l++,m++){
            strNomeFaixa[m]=linha[l];
        }
        strNomeFaixa[m]=0;
        
        
        
        l++;
        for(m=0;linha[l]!=0;l++,m++){
            strTempo[m]=linha[l];
        }
        strTempo[m]=0;
        
        int codigo = atoi(strCodigo);
        /* Inclui a faixa atual */
        if (lista->quantFaixas==0){
            strcpy(lista->faixas[0].nomeFaixa,strNomeFaixa);
            lista->faixas[0].idFaixa=codigo;
            lista->faixas[0].tamFaixa=atoi(strTempo);
            lista->quantFaixas = lista->quantFaixas +1;    
            
        /* Se estiver no meio da lista */
        }else{
            int achei=0,i=0;
            while(!achei && i<(lista->quantFaixas)){
                if(lista->faixas[i].idFaixa>codigo){
                    achei=1;
                    int j;
                    for(j=lista->quantFaixas-1;j>=i;j--){
                        strcpy(lista->faixas[j+1].nomeFaixa,lista->faixas[j].nomeFaixa);
                        lista->faixas[j+1].idFaixa=lista->faixas[j].idFaixa;
                        lista->faixas[j+1].tamFaixa=lista->faixas[j].tamFaixa;       
                    }
                    strcpy(lista->faixas[i].nomeFaixa,strNomeFaixa);
                    lista->faixas[i].idFaixa=codigo;
                    lista->faixas[i].tamFaixa=atoi(strTempo);
                    lista->quantFaixas = lista->quantFaixas +1;        
                }
                i++;
            }
            /* Se for a ultima faixa */
            if(!achei){ 
                strcpy(lista->faixas[lista->quantFaixas].nomeFaixa,strNomeFaixa);
                lista->faixas[lista->quantFaixas].idFaixa=codigo;
                lista->faixas[lista->quantFaixas].tamFaixa=atoi(strTempo);
                lista->quantFaixas = lista->quantFaixas +1; 
                   
            }
        }
    }
    fclose(arquivo);
    printf("Arquivo importado com sucesso!\n");
    system("pause");
}

/* Limpa as faixas cadastradas e a fila */
void ejetarCD(struct stCD *lista,struct stFila *fila){
    lista->quantFaixas=0;
    fila->inicio=-1;
    fila->fim=-1;
    free(fila->itens);
    
    printf("\nCD ejetado com sucesso! \n\n");
    system("pause");
    
}

void tocarSequencia(struct stCD lista,struct stFila fila){
    int i;
    for(i=0;i<fila.tam;i++){
        int codFaixa = buscaBinariaFaixas(lista,fila.itens[i],0,lista.quantFaixas);
        int tempo = lista.faixas[codFaixa].tamFaixa;
        char desc[110];
        strcpy(desc,lista.faixas[codFaixa].nomeFaixa);
        while(tempo>0){
            system("cls");
            
            tempo--;
            
            int segTotal = tempo;
            int hora,minuto,segundo;
            segundo = segTotal%60;
            segTotal = segTotal-segundo;
            segTotal = segTotal/60;
            if ((segTotal)>60){
                minuto = segTotal%60;
                segTotal = (segTotal-minuto)/60;
            }else{
                minuto = segTotal;
                segTotal = 0;
            }
            
            printf(  "      -,_,-,_,-,_,-,_,-,_,-[ Tocando Agora ]-,_,-,_,-,_,-,_,-,_,-");
            printf("\n          %s",desc);
            printf("\n      ---------------------[   %2d:%2d:%2d    ]----------------------",segTotal,minuto,segundo);
            
            dorme(1000);
        }
    }
    
    printf("\nTerminada a executacao das faixas em sequencia!\n");
}




int buscaBinariaFaixas(struct stCD lista,int codigo,int e,int d){
    int m;
    if(e<=d){
        m=(e+d)/2;
        if(lista.faixas[m].idFaixa==codigo){
            return m;
        }else if(lista.faixas[m].idFaixa<codigo){
            return buscaBinariaFaixas(lista,codigo,m+1,d);
        }else{
            return buscaBinariaFaixas(lista,codigo,e,m-1);
        }
    }
    return -1;
}

void enfileiraFaixa(struct stFila *fila,int codFaixa){
    if(fila->fim != fila->tam-1)
    {
        if(fila->inicio!=-1 || fila->fim!=-1)
        {
            fila->inicio = fila->inicio+1;
        }
        fila->fim = fila->fim+1;
        fila->itens[fila->fim]=codFaixa;
    }
}

void desenfileiraFaixa(struct stFila *fila){

    if(fila->inicio!=-1 || fila->fim!=-1)
    {
        if(fila->inicio== fila->fim!=-1)
        {
            fila->inicio = fila->inicio-1;
             fila->fim = fila->fim-1;
        }
        else
        {
           fila->inicio = fila->inicio+1;
        }
    }
}

/* O problema desta função é que ela consome o processamento do PC com o laço */
void dorme(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
