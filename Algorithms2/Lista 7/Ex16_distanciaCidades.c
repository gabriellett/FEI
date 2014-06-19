#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  16 - Lista de Exercícios 7                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

void menu(float[][5]); //Chama o menu
void verificaOpcao(int,float[][5]); //Verifica qual foi a opcao executada
float calculaDistancia(int,int,float[][5]); //Retorna a distancia entre as 2 cidades
void recebeTabela(float[][5]); //Entrada da tabela

int main(){

    float tabela[5][5]={{0,15,30,05,12},{15,00,10,17,28},{30,10,00,03,11},{05,17,03,00,80},{12,28,11,80,00}};
    menu(tabela);
    return 0;
    
}

void menu(float tabela[][5]){
    int opcao;
    do{
        system("cls");
        printf("Escolha uma opcao:\n  1. Digitar uma tabela (por padrao a tabela dada no exercicio e carregada)\n  2. Distancia entre duas cidades\n  3. Imprimir tabela (sem repeticoes)\n  4. Calcular distancia de um caminho (varias cidades)\n  0. Sair\n\n  Opcao:");
        scanf("%d",&opcao);
    }while(opcao <0 || opcao >5);
    verificaOpcao(opcao,tabela);
}

void verificaOpcao(int opcao,float tabela[][5]){
    
    system("cls");
    if (opcao==1){
        recebeTabela(tabela);
    }else if(opcao==2){
        int a=-1,b=-1;
        while (a<0 || a>4){
            printf("Digite o No primeira cidade (numero de 0 a 4, incluindo 0 e 4)\n");
            scanf("%d",&a);
        }
        while ( b<0 || b>4 || b==a){
            printf("Digite o No segunda cidade (numero de 0 a 4, incluindo 0 e 4)\n");
            scanf("%d",&b);
        }
        printf("A distancia entre a cidade %d e %d e' de %f\n\n",a,b,calculaDistancia(a,b,tabela));
        system("pause");
    }else if(opcao==3){
        
        int i,j;
        printf("Tabela sem repeticoes de distancias:\n\n              0        1        2        3        4\n       ");
        for(i=0;i<5;i++){
            printf("%d   ",i);
            for(j=0;j<=i;j++){
                printf("%06.1f   ",tabela[i][j]);
            }
            printf("\n       ");
        }
        system("pause");
    }else if(opcao==4){
        int entrada = -2, cidAnterior=-1;
        float total=0;
        while(entrada != -1){
            cidAnterior = entrada;
            do{
                printf("Digite uma cidade (-1 para finalizar):");
                scanf("%d",&entrada);
            }while( (entrada<0 && entrada !=-1) || (entrada >4 && entrada !=-1));
            if (cidAnterior!=-1 && entrada !=-1){
                total = total + calculaDistancia(cidAnterior,entrada,tabela);
            }
            printf("%f",total);
        }
        printf("A distancia total entre as cidades e' de %f",total);
    }
    
    char selec='a';
    while (selec != 's' && selec != 'S' && selec != 'n' && selec != 'N'){
        setbuf(stdin, NULL);
        printf("\n\nDeseja selecionar outra opcao? (<s> para sim e <n> para nao):");
        scanf("%c",&selec);
        system("cls");
    }
    if (selec=='s' || selec=='S'){
        menu(tabela);
    }
}

void recebeTabela(float tabela[][5]){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<=i;j++){

            printf("Digite a distancia entre a cidade %d e %d",i,j);
            scanf("%f",&tabela[i][j]);
            tabela[j][i] = tabela[i][j];
        }   
    }
}

float calculaDistancia(int a,int b,float tabela[][5]){
    return tabela[a][b];
}
