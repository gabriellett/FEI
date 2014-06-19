#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 13 - Lista de Exercícios 3                    */
/* CC2621 --2011    --turma 610     --                     */

/**************************************************************************/
/* Fontes:                                                                */
/*      Calculo da data da Pascoa: http://astro.if.ufrgs.br/pascoa.htm    */
/*      Calculo e exemplos: http://inf.ufrgs.br/~cabral/Pascoa.html       */
/**************************************************************************/

int anoBissecto(int);
void calculaFeriados(int);


int main(){
    
    int ano=0;
    
    while (ano<=0){
        printf("Digite o ano:  ");
        scanf("%d",&ano);
    }
     
    calculaFeriados(ano);
    
    system("PAUSE");	
    return 0;
}

//Calcula e exibe na tela as datas dos feriados moveis:
  
void calculaFeriados(int a){ //a: ano

    int c,n,k,i,j,l,m,d;
    
    // Calculo da data da pascoa, vide fontes;
    c = a/100;
    n = a - (19*(a/19));
    k = (c - 17)/25;
    i = c - c/4 - ((c-k)/3) +(19*n) + 15;
    i = i - (30*(i/30));
    i = i - ((i/28)*(1-(i/28))*(29/(i+1))*((21-n)/11));
    j = a + a/4 + i + 2 -c + c/4;
    j = j - (7*(j/7));
    l = i - j;
    m = 3 + ((l+40)/44);
    d = l + 28 - (31*(m/4));


    printf("\n----------------------------------------------\n\nData da Pascoa: %d / %d / %d\n",d,m,a);
    
    int dia = d;
    int mes = m;
    int ano = a;

    int diaSextaF, mesSextaF; //Variaveis do dia e mes da Sexta Feira Santa;
    
    int diaSexta = dia-2;
    mesSextaF = mes;
    
    if (diaSexta <=0){ //Verificacao se houve mudanca de mes em relacao a pascoa;
        mesSextaF--;
        diaSexta = (diaSexta*-1);
        diaSexta = 31-diaSexta;
    }
    
    printf("Sexta-Feira Santa: %d / %d / %d\n",diaSexta,mesSextaF,a);
    
    int diaTercaCarn, mesTercaCarn; //Variaveis do dia e mes da Terca Feira de Carnaval;
    
    diaTercaCarn = dia-47;
    mesTercaCarn = mes-1; //Ocorrera' mudanca de mes obrigatoriamente;
    

    if (mesTercaCarn==4){
        diaTercaCarn= 30+diaTercaCarn;
    }else if(mesTercaCarn==3){ 
        diaTercaCarn= 31+diaTercaCarn;
    }else if(mesTercaCarn==2){
        if (anoBissexto(ano)==1){
            diaTercaCarn= 29+diaTercaCarn;  
        }else if (anoBissexto(ano)==0){
            diaTercaCarn= 28+diaTercaCarn;   
        }
    }
    
    if (diaTercaCarn<=0){//Caso houver mais uma mudanca de mes:

        mesTercaCarn--;
        if (mesTercaCarn==4){
            diaTercaCarn= 30+diaTercaCarn;
        }else if(mesTercaCarn==3){ 
            diaTercaCarn= 31+diaTercaCarn;
        }else if(mesTercaCarn==2){
            if (anoBissexto(ano)==1){
                diaTercaCarn= 29+diaTercaCarn;  
            }else if (anoBissexto(ano)==0){
                diaTercaCarn= 28+diaTercaCarn;
            }  
        }
    }
    
    printf("Terca feira de Carnaval: %d / %d / %d\n",diaTercaCarn,mesTercaCarn,a);
    
    int diaCorpus,mesCorpus; //Variaveis do dia e mes de Corput Christi;
    
    diaCorpus=dia +60;
    mesCorpus=mes;

    //Correcao dos dias e meses:
    if (mesCorpus==3){
        if (diaCorpus>31){
        diaCorpus = diaCorpus - 31;
        mesCorpus = mesCorpus+1;
        }
    }

    if (mesCorpus==4){
        if (diaCorpus>30){
        diaCorpus = diaCorpus - 30;
        mesCorpus = mesCorpus+1;
        }
    }
   
    if (mesCorpus==5){
        if (diaCorpus>31){
        diaCorpus = diaCorpus - 31;
        mesCorpus = mesCorpus+1;
        }
    }
    
    printf("Corpus Christi: %d / %d / %d\n\n",diaCorpus,mesCorpus,a);
  
  
}

//Verifica se o ano e' bissexto;
int anoBissexto(int ano) {   
        if ( ( ano % 4 == 0 && ano % 100 != 0 ) || ( ano % 400 == 0 ) ){   
            return 1;   
        }   
        else{   
            return 0;   
        }   
}  

