#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/***********************************************************/
/* Aluno: Gabriel Lett Viviani *//* 					   */
/* Exercicio  02 - Lista de Exercícios 02                  */
/* CC3651 --2012    --turma 610    						   */
/***********************************************************/
/*
 TODO: Verificar se o arquivo de produtos foi importado
 TODO: Verificar se já existe venda com aquele CPF
 TODO: Verificar se já existe produto com aquele Codigo
*/
#define TAM 200

/* Struct que guarda os produtos de cada venda , para que o programa funcione 
 * sem o arquivo de produtos e' necessario gravar a descricao do produto e o 
 * preco tambem;
 */
 
struct stProduto
{
    int codigoProduto;
    double quantidade;
    char descricao[500];
    float preco;
};

/* Struct das vendas */
struct stVenda
{
    char cpf[15];
    int hora,minuto,segundo; 
    int quantProdutos;
    struct stProduto *produtos;
};

/* Struct geral da lista */

struct stLista
{
    struct stVenda vendas[TAM];
    struct stListaProdutos *listaProdutos;
    int quantVendas;
    int quantProdutos;
};

/* Struct da lista de produtos, que recebe os dados do arquivo */
struct stListaProdutos
{
    int codigoProduto;
    char descricao[500];
    float preco; 
};

void realizarVenda(struct stLista *);
void insereProduto(struct stLista *,int);
void verVenda(struct stLista *);
void abrirVenda(struct stLista *);
void salvarVenda(struct stLista *);
int menu();
void verificaOpcao(int,struct stLista *);
void incluiProduto(int, char*, float ,struct stLista *);
int buscaBinariaProdutos(struct stLista *,int,int,int);
int buscaBinariaVendas(struct stLista *,double,int,int);
void abrirProdutos(struct stLista *);

int main(){
    /* Lista que será usada durante todo o programa */
    struct stLista lista;
    lista.quantVendas = 0;
    lista.quantProdutos = 0;
    int opcao=-1;
    char resp = 'a';
    do{
        /* Enquanto a opção for diferente de sair */
        while(opcao!=6){
            opcao = menu();
            if(opcao==1){
                realizarVenda(&lista);
            }else if(opcao==2){
                verVenda(&lista);
            }else if(opcao==3){
                abrirVenda(&lista);
            }else if(opcao==4){
                abrirProdutos(&lista);
            }else if(opcao==5){
                salvarVenda(&lista);
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
        printf("--------------- SisCoVeRo II ---------------\nEscolha uma das opcoes a seguir\n\n   1 - Realizar Vendas\n   2 - Ver Vendas\n   3 - Abrir Arquivo de Vendas\n   4 - Carregar Produtos\n   5 - Salvar Vendas\n   6 - Sair\n\n  Opcao:");
        scanf("%d",&opcao);
    }while(opcao <1 || opcao >6);

    return opcao;
}


/* Realiza uma venda */
void realizarVenda(struct stLista *lista){
    int isEncontrado=0, i=0, j=0;
    int valido;

    /* Se não estiver cheia */
    if(lista->quantVendas < TAM){
        char cpfDigitado[15];
        valido=-1;
        /* CPF do cliente */
        while(valido!=1){
            setbuf(stdin, NULL);
            if(valido==0){
                printf("CPF Invalido!\n  Por favor, informe um CPF VALIDO (11 caracteres, somente numeros): ");
            }else{
                printf("Informe o CPF VALIDO do cliente (11 caracteres, somente numeros): ");
            }
            gets(cpfDigitado);
            printf("cpfDigitado:%s",cpfDigitado);
            valido=isCPF(cpfDigitado);
            
        }
        
        int codVenda=-1;
        if(lista->quantVendas==0){
            strcpy(lista->vendas[0].cpf,cpfDigitado);
            codVenda=0;
        }else if(atof(lista->vendas[(lista->quantVendas-1)].cpf)<atof(cpfDigitado)){
            strcpy(lista->vendas[lista->quantVendas].cpf,cpfDigitado);
            codVenda = lista->quantVendas;
        }else{
            int achei=0,i=0;
            while(!achei && i<(lista->quantVendas)){
                if(atof(lista->vendas[i].cpf)>atof(cpfDigitado)){
                    achei=1;
                    int j;
                    for(j=lista->quantVendas;j<=i;j--){
                        lista->vendas[j+1].produtos=(struct stProduto*)malloc(sizeof(struct stProduto)*lista->vendas[j].quantProdutos);
                        lista->vendas[j+1]=lista->vendas[j];
                    }
                    strcpy(lista->vendas[i].cpf,cpfDigitado);
                    codVenda=i;
                }
                i++;
            }
            /*if(!achei){ 
                strcpy(lista->listaProdutos[lista->quantProdutos].descricao,descricao);
                lista->listaProdutos[lista->quantProdutos].codigoProduto=codigo;
                lista->listaProdutos[lista->quantProdutos].preco=preco;
                lista->quantProdutos = lista->quantProdutos +1; 
               
            }*/
            
        }
        if(codVenda!=-1){
            insereProduto(lista,codVenda);
            lista->quantVendas++;
        }else{
            printf("Nao foi encontrada uma posicao para este cpf!\n");
            system("pause");
        }   
    }else{
        printf("\nO Programa chegou em sua capacidade maxima de vendas diarias!\n");
        system("pause");
    }

}

void insereProduto(struct stLista *lista,int codVenda){
        
    struct tm  ts;
    time_t     now;
    
    now = time(NULL); // Obtem os dados do SO
    ts = *localtime(&now); // Formata os dados no formato struct tm
    
    lista->vendas[codVenda].hora = ts.tm_hour;
    lista->vendas[codVenda].minuto = ts.tm_min;
    lista->vendas[codVenda].segundo = ts.tm_sec;
    
    system("cls");
    printf("Codigo da venda: %3d  -  Hora da inclusao: %d:%d:%d\n",codVenda,lista->vendas[codVenda].hora,lista->vendas[codVenda].minuto,lista->vendas[codVenda].segundo);
    int i=0;
    
    printf("Digite a quantidade de produtos a serem incluidos:");
    scanf("%d",&lista->vendas[codVenda].quantProdutos);

    lista->vendas[codVenda].produtos=(struct stProduto*)malloc(sizeof(struct stProduto)*lista->vendas[codVenda].quantProdutos);

    do{
        system("cls");
        printf("Codigo da venda: %3d  -  Hora da inclusao: %d:%d:%d\n",codVenda,lista->vendas[codVenda].hora,lista->vendas[codVenda].minuto,lista->vendas[codVenda].segundo);
        
        int resBuscaProd=-2;
        int codigoProduto;
        do{
            if(resBuscaProd==-1){
                printf("Produto invalido!");
            }
            setbuf(stdin, NULL);
            printf("Digite o codigo do produto:");
            scanf("%d",&codigoProduto);
            resBuscaProd= buscaBinariaProdutos(lista,codigoProduto,0,lista->quantProdutos);
        }while(resBuscaProd==-1);
        lista->vendas[codVenda].produtos[i].codigoProduto=codigoProduto;
        strcpy(lista->vendas[codVenda].produtos[i].descricao,lista->listaProdutos[resBuscaProd].descricao);
        lista->vendas[codVenda].produtos[i].preco = lista->listaProdutos[resBuscaProd].preco;
        printf("Descricao: %s\n",lista->listaProdutos[resBuscaProd].descricao);
        printf("Preco Unitario: %.2f\n",lista->listaProdutos[resBuscaProd].preco);
        setbuf(stdin, NULL);
        printf("Digite a quantidade deste produto:");
        scanf("%lf",&lista->vendas[codVenda].produtos[i].quantidade);
        i++;
    }while(i<lista->vendas[codVenda].quantProdutos);
    
}

void verVenda(struct stLista *lista){
    system("cls");
    double cpfDigitado;
    
    if(lista->quantVendas!=0){
        int resBusca=-2;
        do{
            system("cls");
            if(resBusca==-1)printf("Venda nao encontrada!\n");
            printf("Digite o cpf da venda desejada (0 para sair):");
            scanf("%lf",&cpfDigitado);
            if(cpfDigitado==0)return;
            resBusca= buscaBinariaVendas(lista,cpfDigitado,0,lista->quantVendas);
        }while(resBusca==-1);
        
        system("cls");

        int i;
        for(i=0;i<lista->vendas[resBusca].quantProdutos;i++){
            system("cls");
            printf("/------------------- --------- ---- --- -- -  -    -\n");
            printf("|Venda: %3d | CPF do cliente:%s\n",resBusca,lista->vendas[resBusca].cpf);
            printf("| Hora da inclusao: %d:%d:%d\n",lista->vendas[resBusca].hora,lista->vendas[resBusca].minuto,lista->vendas[resBusca].segundo);
            printf("|\n/------------------- --------- ---- --- -- -  -    -\n");
            printf("| Codigo do produto:   '%d'\n",lista->vendas[resBusca].produtos[i].codigoProduto);            
            printf("| Descricao do produto:'%s'\n",lista->vendas[resBusca].produtos[i].descricao);
            printf("| Quantidade vendida:  '%.2f'\n",lista->vendas[resBusca].produtos[i].quantidade);
            printf("| Preco do produto:    '%.2f'\n",lista->vendas[resBusca].produtos[i].preco);
            printf("|\n|    Produto %d de %d\n|\n",i+1,lista->vendas[resBusca].quantProdutos);
            printf("\\------------------- --------- ---- --- -- -  -    -\n    ");
            system("pause");
        }
    }else{
        printf("Atenção: A lista se encontra vazia!");
        system("pause");
    }
}


int isCPF(char cpf[15] ) {
	int soma = 0;
	 
    int j=0;
    int i=0;
    
    /* Calculando o primeiro digito verificador: */
    for ( i = 0; i <= 8; i++) {
        j = cpf[i]-48;
        soma += (j*(10-i));
    }
     
    if(soma%11>=2){
        if((11-(soma%11))!=(cpf[9]-48)){
            
            return 0;
        }
    }else{
        if((cpf[9]-48)!=0){

            return 0;
        }
    }
     
    soma=0;
    
    /* Calculando o segundo digito verificador */
    for ( i = 0; i <= 9; i++) {
        j = cpf[i]-48;
        soma += (j*(11-i));
    }

    if(soma%11>=2){
        if((11-(soma%11))!=(cpf[10]-48)){
            return 0;
        }
    }else{
        if((cpf[9]-48)!=0){
            return 0;
        }
    }
    
    if(cpf[11]!=0)return 0;
    return 1;
}

void salvarVenda(struct stLista *lista){
    FILE *arquivo;
    char nomeArq[100];
    setbuf(stdin, NULL);
    printf("Informe o nome do arquivo: ");
    gets(nomeArq);
    
    arquivo=fopen(nomeArq, "w");
    int i=0;
    fprintf(arquivo, "%d\n", lista->quantVendas);
    for(i=0; i<lista->quantVendas; i++)
    {
        int j;
        fprintf(arquivo, "%s %d %d %d %d \n", lista->vendas[i].cpf,  lista->vendas[i].quantProdutos, lista->vendas[i].hora,lista->vendas[i].minuto,lista->vendas[i].segundo);
        for(j=0;j<lista->vendas[i].quantProdutos;j++){
            fprintf(arquivo, "%d:%s:%f:%f:\n", lista->vendas[i].produtos[j].codigoProduto,  lista->vendas[i].produtos[j].descricao, lista->vendas[i].produtos[j].preco, lista->vendas[i].produtos[j].quantidade);
        }
    }
    fclose(arquivo);

    printf("Arquivo salvo com sucesso!\n"); 
    system("pause");
}

void abrirVenda(struct stLista *lista)
{
    FILE *arquivo;
    char nomeArq[100];
    int i=0;
    system("cls");
    do{
        setbuf(stdin, NULL);
        printf("\nInforme o nome do arquivo de importacao: ");
        gets(nomeArq);
        arquivo = fopen(nomeArq, "r");
        if(arquivo==NULL)
            printf("Arquivo %s nao existe, favor informar um nome valido!\n", nomeArq);
    }while(arquivo==NULL);
    
    int nLinhas = 0;
    int y=0; 
    char linha[500];    

    char chLinha='\0';
    while(chLinha!='\n'){
        chLinha=fgetc(arquivo);
        if(chLinha!='\n'){
            linha[y]=chLinha;    
            y++;
        }
        
    }
    
    lista->quantVendas=atoi(linha);

    for(i=0; i<lista->quantVendas; i++){
        int j;
        int aux=0;
        y=0;
        do{
            
            chLinha=fgetc(arquivo);
            
            if(chLinha!=' '){
                linha[y]=chLinha;    
                y++;
            }else{
                linha[y]=0;
                if(aux==0)strcpy(lista->vendas[i].cpf,linha);
                if(aux==1)lista->vendas[i].quantProdutos = atoi(linha);
                if(aux==2)lista->vendas[i].hora = atoi(linha);
                if(aux==3)lista->vendas[i].minuto = atoi(linha);
                if(aux==4)lista->vendas[i].segundo = atoi(linha);
                aux++;
                y=0;
            }
            
        }while(chLinha!='\n');

        lista->vendas[i].produtos=(struct stProduto*)malloc((lista->vendas[i].quantProdutos)+2 * (sizeof(struct stProduto)));
    
        for(j=0;j<lista->vendas[i].quantProdutos;j++){
            chLinha=fgetc(arquivo);
            y=0;
            aux=0;
            while(chLinha!='\n'){
                chLinha=fgetc(arquivo);
                
                if(chLinha!=':'){
                    linha[y]=chLinha;
                      
                    y++;
                    
                }else{
                    
                    linha[y]=0;
                    if(aux==0)lista->vendas[i].produtos[j].codigoProduto = atoi(linha);
                    if(aux==1)strcpy(lista->vendas[i].produtos[j].descricao,linha);
                    if(aux==2)lista->vendas[i].produtos[j].preco = atof(linha);
                    if(aux==3)lista->vendas[i].produtos[j].quantidade = atof(linha);
                    aux++;
                    y=0;
                    
                }
            }
        }
    }
    
    fclose(arquivo);
    printf("Arquivo importado com sucesso!\n");
    system("pause");
}

void abrirProdutos(struct stLista *lista){
    
    FILE *arquivo;
    char nomeArq[100];
    int i=0;
    system("cls");
    do{
        setbuf(stdin, NULL);
        printf("\nInforme o nome do arquivo de importacao: ");
        gets(nomeArq);
        arquivo = fopen(nomeArq, "r");
        if(arquivo==NULL)
            printf("Arquivo %s nao existe, favor informar um nome valido!\n", nomeArq);
    }while(arquivo==NULL);
    
    char ch='\0';
    int nLinhas = 0;
    
    while(ch!=EOF){
        ch=fgetc(arquivo);
        if(ch=='\n')nLinhas++;    
    }
    
    fclose(arquivo);
   
    
    lista->listaProdutos=(struct stListaProdutos*)malloc(nLinhas * (sizeof(struct stListaProdutos)));
    
    arquivo = fopen(nomeArq, "r");
    
    int n;
    char linha[500],desc[500],strCodigo[6],strPreco[20];
    int codigo;
    
    float preco;
         
    for(n=0;n<nLinhas;n++){
        
        char chLinha='\0';
        int y=0;
        while(chLinha!='\n'){
            chLinha=fgetc(arquivo);
            if(chLinha!='\n'){
                linha[y]=chLinha;    
                y++;
            }
        }
        
        int l,m;
        for(l=0,m=0;linha[l]!=':';l++,m++){
            strCodigo[m]=linha[l];
        }
        strCodigo[m]=0;
        
        l++;
        for(m=0;linha[l]!=':';l++,m++){
            desc[m]=linha[l];
        }
        desc[m]=0;
        
        l++;
        for(m=0;linha[l]!=0;l++,m++){
            strPreco[m]=linha[l];
        }
        strPreco[m]=0;
        incluiProduto(atoi(strCodigo),desc,atof(strPreco),lista);
        
        
    }
    
    fclose(arquivo);
    printf("Arquivo importado com sucesso!\n");
    system("pause");
}

void incluiProduto(int codigo, char descricao[500], float preco,struct stLista *lista){
    if (lista->quantProdutos==0){
        strcpy(lista->listaProdutos[0].descricao,descricao);
        lista->listaProdutos[0].codigoProduto=codigo;
        lista->listaProdutos[0].preco=preco;
        lista->quantProdutos = lista->quantProdutos +1;    
    }else{
        int achei=0,i=0;
        while(!achei && i<(lista->quantProdutos)){
            if(lista->listaProdutos[i].codigoProduto>codigo){
                achei=1;
                int j;
                for(j=lista->quantProdutos-1;j>=i;j--){
                    strcpy(lista->listaProdutos[j+1].descricao,lista->listaProdutos[j].descricao);
                    lista->listaProdutos[j+1].codigoProduto=lista->listaProdutos[j].codigoProduto;
                    lista->listaProdutos[j+1].preco=lista->listaProdutos[j].preco;       
                }
                strcpy(lista->listaProdutos[i].descricao,descricao);
                lista->listaProdutos[i].codigoProduto=codigo;
                lista->listaProdutos[i].preco=preco;
                lista->quantProdutos = lista->quantProdutos +1;        
            }
            i++;
        }
        if(!achei){ 
            strcpy(lista->listaProdutos[lista->quantProdutos].descricao,descricao);
            lista->listaProdutos[lista->quantProdutos].codigoProduto=codigo;
            lista->listaProdutos[lista->quantProdutos].preco=preco;
            lista->quantProdutos = lista->quantProdutos +1; 
               
        }
        
        
    }

}

int buscaBinariaProdutos(struct stLista *lista,int codigo,int e,int d){
    int m;
    if(e<=d){
        m=(e+d)/2;
        if(lista->listaProdutos[m].codigoProduto==codigo){
            return m;
        }else if(lista->listaProdutos[m].codigoProduto<codigo){
            return buscaBinariaProdutos(lista,codigo,m+1,d);
        }else{
            return buscaBinariaProdutos(lista,codigo,e,m-1);
        }
    }
    return -1;
}

int buscaBinariaVendas(struct stLista *lista,double cpf,int e,int d){
    int m;
    if(e<=d){
        m=(e+d)/2;
        if(atof(lista->vendas[m].cpf)==cpf){
            return m;
        }else if(atof(lista->vendas[m].cpf)<cpf){
            return buscaBinariaVendas(lista,cpf,m+1,d);
        }else{
            return buscaBinariaVendas(lista,cpf,e,m-1);
        }
    }
    return -1;
}
