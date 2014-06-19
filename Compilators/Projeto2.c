// Compiladores - Projeto II
//
// Gabriel Lett Viviani 

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

//	Tabela de variaves, cabendo 1000 variaveis com nome maximo de 255 caracteres
char tabelaVar[1000][255];

// Posicao da ultima variavel incluida
int ultimaVr = 0;

// String de entrada
char entrada[1000];

// Posicao de leitura da entrada
int posLeitEntrada = 0;

// Verifica se dois chars sao igais, retorna 1 caso seja, 0 caso contraio
int isIgual(char *,char*);

// Copia uma string para outra, sendo arg1 o destino, arg2 a fonte
void copyString(char *, char *);

// Retorna 1 caso o char seja uma letra/simbolo, 2 caso seja um numero
int getTipoDigito(char);

// Verifica se uma variavel existe na tabela, caso exista retorna a posicao.
int existeTabela(char *);

// Inclui uma NOVA variavel na tabela
void includeVar(char *);

// Estado de leitura inicial, roda ate' receber um numero ou simbolo != de ' '
void e0EsperaPalavra();

// Espera uma variavel para inclusao
void e1EsperaVariavel();

// Espera um numero para inclusao
void e2EsperaNumero();

void main(int argc, char ** arg){
    printf("Digite a string inicial:\n");
    gets(entrada);
    e0EsperaPalavra();
}

void e0EsperaPalavra(){
    int i,j;
    char tempS[255];
    while(entrada[posLeitEntrada]!=0){
        if(entrada[posLeitEntrada]!=' ' && entrada[posLeitEntrada]!=0){

            int tipoDigito = getTipoDigito(tempS);
            //printf("tipoDigito:%d\n",tipoDigito);
            if(tipoDigito==1){
                e1EsperaVariavel();
                posLeitEntrada--;
                // e' uma variavel
            }else if(tipoDigito == 2){
                e2EsperaNumero();
                posLeitEntrada--;
                // e1 um numero
            }
        }
        posLeitEntrada++;
    }
    // Fim
    system("PAUSE");
}

void e1EsperaVariavel(){
    char tempS[255];

    int i=0;
    
    while(entrada[posLeitEntrada] != ' ' && entrada[posLeitEntrada] != 0){
        tempS[i] = entrada[posLeitEntrada];
        posLeitEntrada++;
        i++;
    }
    tempS[i] = 0;
    includeVar(tempS);

    return;
}

void e2EsperaNumero(){
    int tempN = 0;
    while(entrada[posLeitEntrada] >= 48 && entrada[posLeitEntrada]<=57){
        tempN = (tempN*10) + (entrada[posLeitEntrada]-48);
        posLeitEntrada++;
    }

    printf("N(%d) ",tempN);

    return;
}

int existeTabela(char *var){
    int i;

    for(i=0; i<ultimaVr;i++){
        if(isIgual(var, tabelaVar[i])){
            return i;
        }
    }

    return -1;
}

void includeVar(char *var){
    int posInc = existeTabela(var);
    if(posInc == -1){
        posInc = ultimaVr;
        copyString(tabelaVar[posInc],var);
        ultimaVr++;
    }

    printf("V(%d) ",posInc);
    
    return;
}


void copyString(char *to, char *from){
    int i=0;
    while(from[i]!=0){
        to[i] = from[i];
        i++;
    }
}

int getTipoDigito(char c){

    if(entrada[posLeitEntrada] >= 48 && entrada[posLeitEntrada]<=57){
        return 2;
    }
    return 1;
}


int isIgual(char *str1, char *str2) {
	int i = 0;
	while (str1[i] == str2[i]) {
        // Verifica se e' fim da string
		if (str1[i] == '\0' && str2[i] == '\0')	{
			return 1;
		}
		i++;
	}
	return 0;
}
