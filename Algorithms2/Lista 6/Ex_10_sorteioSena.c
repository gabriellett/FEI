#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  10 - Lista de Exercícios 6                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int geraVetor(int*);
int verificaGerado(int*,int,int);
void populaVetor(int*);
int verificaResultado(int*,int*,char*);
void exibeResultado(int*,char*);

int main(){
    int v[6]; //Vetor dos numeros sorteados
    int n[6]; //Vetor dos numeros digitados pelo usuario
    int resultado; //Quantidade de acertos do usuario
    char acertos[12]; //Vetor das 'setinhas'.
    geraVetor(v);
    populaVetor(n);
    resultado=verificaResultados(v,n,acertos);
    system("cls");
    if (resultado==0){
        printf("Voce nao acertou nenhum numero!\n\n");
    }else if (resultado==6){
        //Mensagem parabenizando o usuario em caso de 6 acertos.
        printf("|*********************************************|\n|******************PARABENS!******************|\n|*********************************************|\n|       VOCE ACERTOU TODOS OS NUMEROS!!!      |\n|*********************************************|\n\n");
        exibeResultado(v,acertos);
    }else{
        printf("Parabens! Voce acertou %d numero(s) de 6!\n\n",resultado);
        exibeResultado(v,acertos);
    }
    
    system("pause");
    return 0;
}

//Gera os numeros sorteados
int geraVetor(int*v){
    //Planta o rand em funcao do relogio da maquina
    srand(time(NULL));  
    int i,existe=1,gerado;
    for (i=0;i<6;i++){
        existe=1;
        while (existe==1){
            gerado=(rand()%60)+1;//Gera um numero randomico entre 1 e 60 (incluindo 1 e 60);
            existe = verificaGerado(v,gerado,i-1); //Verifica se o valor gerado randomicamente ja' esta no vetor.
            if (existe==0){//Se nao existir:
                v[i] =gerado;
            }
        }
    }
}

//Verifica se o numero que foi digitado ja existe na matrix v
int verificaGerado(int *v, int gerado, int i){
    for (i;i>=0;i--){//i : indice de v que o valor deveria/vai ser gravado 
        if (v[i]==gerado){
            return 1;//Retorna 1 caso existir
        }
    }
    return 0;
}

//popula o vetor com os numeros digitados pelo usuario
void populaVetor(int*n){
    int i,existe,gerado;
    for (i=0;i<6;i++){
        existe=1;
        while (existe==1){
            setbuf(stdin, NULL);
            printf("Digite o %d numero:",i+1);
            scanf("%d",&gerado);
            //verifica se o numero ja' foi gerado;
            existe = verificaGerado(n,gerado,i-1);
            if (existe==0 && gerado >0 && gerado<=60){
                n[i] = gerado;
            }else{
                existe=1;
            }
        }

    }
}

//Verifica a quantidade de acertos do usuario e grava o vetor a que exibira as setinhas caso ocorram acertos.
int verificaResultados(int *v,int *n,char *a){
    int i, p, resultado=0;
    for (i=0;i<12;i++) a[i]=' ';//popula o vetor <a> com espacos em branco
    for (i=0;i<6;i++){
        for(p=0;p<6;p++){
            if (v[i]==n[p]){
                a[i*2]='\\';
                a[(i*2)+1]='/';
                resultado++;
            }
        }
    }
    return resultado;
}

//Exibe quais foram os acertos do usuario e os numeros sorteados
void exibeResultado(int *v,char *acertos){

    int i;

    for(i=0;i<6;i++){
        //exibe as setinhas
        printf("|%c%c|   ",acertos[i*2],acertos[(i*2)+1]);
    }

    printf("\n");
  
    for(i=0;i<6;i++){
        //exibe os numeros sorteados
        printf("|%2d|   ",v[i]);
    }
    printf("\n\n");
}
