#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Tamanho do vetor da struct */
#define TAMANHO 100

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  05 - Lista de Exercícios 9                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

struct veiculo{
    char marca[55];
    char modelo[55];
    int cor;
    int combustivel;
    int ano;
};

void verificaCor(int,struct veiculo[TAMANHO]);
int verificaCombustivel(int,struct veiculo[TAMANHO]);
void menu(struct veiculo[TAMANHO],int);
void verificaOpcao(int,struct veiculo[TAMANHO],int);
void ordenaVetorAno(struct veiculo[TAMANHO]);

int main(){
    struct veiculo sVeiculos[TAMANHO];
    int i,ano=0,totalBicombustivel=0;
    
    /* Faz a entrada dos valores */
    for (i=0;i<TAMANHO;i++){
        setbuf(stdin, NULL);
        printf("Veiculo No %d de %d:\n\nDigite a marca do veiculo (50 caracteres):\n",i+1,TAMANHO);
        gets(sVeiculos[i].marca);
        setbuf(stdin, NULL);
        printf("Digite o modelo do veiculo (50 caracteres):\n");
        gets(sVeiculos[i].modelo);    
        setbuf(stdin, NULL); 
        
        printf("Digite a cor do veiculo (somente preto, prata ou branco):\n");
        verificaCor(i, sVeiculos);
        setbuf(stdin, NULL);
        printf("Digite o combustivel do veiculo (somente gasolina, etanol ou bicombustivel):\n");
        totalBicombustivel = totalBicombustivel + verificaCombustivel(i,sVeiculos); 
        setbuf(stdin, NULL);

        printf("Digite o ano do veiculo (entre 1678 e 2012) :\n");
        scanf("%d",&ano);
        setbuf(stdin, NULL);
        while (ano < 1678 || ano >2012){
            printf("Ano invalido! Digite outro ano:");
            scanf("%d",&ano);
            setbuf(stdin, NULL);
        }
        sVeiculos[i].ano=ano;
        setbuf(stdin, NULL);      

        system("cls");
    }
    
    /* Ordena o vetor: */
    ordenaVetorAno(sVeiculos);
    
    /* Chama o menu */
    menu(sVeiculos,totalBicombustivel);
    system("pause");
    return 0;
    
}

/* Ordena o vetor por selection sort: */
void ordenaVetorAno(struct veiculo sVeiculos[TAMANHO]){
    int i,j,k,menor;
    struct veiculo aux;
    for (i=0;i<TAMANHO;i++){
        menor=i;
        for(j=i+1;j<TAMANHO;j++){
            if(sVeiculos[j].ano<sVeiculos[menor].ano){
                menor=j; 
            }
        }
        aux = sVeiculos[i];
        sVeiculos[i] = sVeiculos[menor];
        sVeiculos[menor] = aux;

    }
}

/* Verifica se a cor digitada é valida e atribui o codigo correto ao veiculo */
void verificaCor(int i, struct veiculo sVeiculos[TAMANHO]){
    int codCor=0;
    char cor[10];
    gets(cor);
    strlwr(cor);
    while(codCor==0){
        if (strcmp(cor,"preto")==0){
            codCor=1;
        }else if (strcmp(cor,"prata")==0){
            codCor=2;
        }else if (strcmp(cor,"branco")==0){
            codCor=3;
        }else{
            codCor=0;
            printf("Digite a cor do veiculo (somente preto, prata ou branco):\n");
            gets(cor);
            strlwr(cor);
        }
    }
    sVeiculos[i].cor=codCor;
}

/* Verifica se o combustivel digitado é valida e atribui o codigo correto ao veiculo */
int verificaCombustivel(int i, struct veiculo sVeiculos[TAMANHO]){
    int codCombustivel = 0;
    char combustivel[20];
    gets(combustivel);
    strlwr(combustivel);
    while(codCombustivel==0){
        if (strcmp(combustivel,"gasolina")==0){
            codCombustivel = 1;
        }else if (strcmp(combustivel,"etanol")==0){
            codCombustivel = 2;
        }else if (strcmp(combustivel,"bicombustivel")==0){
            codCombustivel = 3;
        }else{
            codCombustivel = 0;
            printf("Digite o combustivel do veiculo (somente gasolina, etanol ou bicombustivel):\n");
            gets(combustivel);
            strlwr(combustivel);
        }
    }
    sVeiculos[i].combustivel = codCombustivel;
    
    /* caso for bicombustivel, retorna 1 para que a soma do total de bicombustiveis já sejá realizada */
    if (codCombustivel==3){
         return 1;
    }else{
        return 0;
    }
}

void menu(struct veiculo sVeiculos[TAMANHO],int totalBicombustivel){
    int opcao;
    do{
        system("cls");
        printf("Escolha uma opcao:\n  1. Exibir marca e modelo de todos os carros de cor preta\n  2. Exibir marca, modelo, cor e ano de todos os veiculos ordenados pelo ano de fabricacao.\n  3. Exibir marca e modelo de todos os carros que sao movidos a Etanol.\n  4. Exibir percentual de carros bicombustiveis no conjunto.\n  5. Exibir marca e modelo do carro de cor branca mais antigo.\n  0. Sair\n\n  Opcao:");
        scanf("%d",&opcao);
    }while(opcao <0 || opcao >5);
    
    /* Verifica qual opção o usuario digitou */
    verificaOpcao(opcao,sVeiculos,totalBicombustivel);
}

void verificaOpcao(int opcao,struct veiculo sVeiculos[TAMANHO],int totalBicombustivel){
    int sair=0;
    system("cls");
    
    if (opcao==1){
        /* Marca e modelo de todos os carros de cor preta : */
        
        printf("Carros de cor preta: \n");
        int i,j;
        for(i=0;i<TAMANHO;i++){
            if(sVeiculos[i].cor==1){
                printf("%s - %s\n",sVeiculos[i].marca,sVeiculos[i].modelo);
                j++;
            }
            if (j%20==0){
                
                system("pause");
            }
        } 
    }else if(opcao==2){
        /*Marca, modelo, cor e ano de todos os veículos ordenados pelo ano de fabricação: */
        
        printf("Veiculos ordenados por ano de fabricacao: \n");

        char cor[3][10]={"Preto","Prata","Branco"};

        int i;
        for (i=0;i<TAMANHO;i++){
            printf("%s - %s - %s - %d\n",sVeiculos[i].marca,sVeiculos[i].modelo,cor[sVeiculos[i].cor-1],sVeiculos[i].ano);
            if(i+1%20==0)system("pause");
        }
    }else if(opcao==3){
        /* Marca e modelo de todos os carros que são movidos a Etanol: */
        
        printf("Carros movidos a etanol: \n");
        int i,k=0;
        for(i=0;i<TAMANHO;i++){
            if(sVeiculos[i].combustivel==2){
                printf("%s - %s\n",sVeiculos[i].marca,sVeiculos[i].modelo);
                k++;
            }
            if (k%20==0)system("pause");
        } 
    }else if(opcao==4){
        /* Percentual de carros bicombustíveis no conjunto: */
        printf("O total de carros bicombustivel %.2f %%",((float)totalBicombustivel/TAMANHO)*100);
        
    }else if(opcao==5){
        /* Marca e modelo do carro de cor branca mais antigo: */
        int achou = 0,i;
        for (i=0;i<TAMANHO;i++){
            if(sVeiculos[i].cor==3){
                achou=1;
                /* Ao encontrar o primeiro carro branco imprime e sai do for */
                printf("Carro de cor branca mais antigo:\n %s - %s",sVeiculos[i].marca,sVeiculos[i].modelo);
                break;
            }
        }
        
        if(achou==0)printf("Não existem carros brancos cadastrados!");
        
    }else if(opcao==0){
        /* Usuario selecionou a opcao de sair */
        char selec='a';
        while (selec != 's' && selec != 'S' && selec != 'n' && selec != 'N'){
            setbuf(stdin, NULL);
            printf("Deseja realmente sair? (<s> para sim e <n> para nao)");
            scanf("%c",&selec);
            system("cls");
        }
        if(selec=='s' || selec=='S')sair=1;
    }
    
    if (sair==0){
        /* Verifica se o usuario deseja continuar */
        char selec='a';
        while (selec != 's' && selec != 'S' && selec != 'n' && selec != 'N'){
            setbuf(stdin, NULL);
            printf("\n\nDeseja selecionar outra opcao? (<s> para sim e <n> para nao):");
            scanf("%c",&selec);
            system("cls");
        }
        
        if (selec=='s' || selec=='S'){
            /* se sim chama o menu novamente */
            menu(sVeiculos,totalBicombustivel);
        }
    }
}
