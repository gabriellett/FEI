#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 21 - Lista de Exercícios 3                    */
/* CC2621 --2011    --turma 610     --                     */

/**********************************************************************************/
/*  Fontes:                                                                       */
/*      Conversao para Juliano: http://www.csgnetwork.com/juliangregcalconv.html  */
/*                                                                                */
/**********************************************************************************/

int leituraAno();
int leituraMes();
int leituraDia(int,int);
float paraJuliano(int,int,int);
int anoBissexto(int);
float diferencaDatas(int,int,int,int,int,int);

//Funcao main
int main()
{
    int ano1 = leituraAno();
    int mes1 = leituraMes();
    int dia1 = leituraDia(mes1,ano1);
    printf("\n-----------------------------------\n\n");
    int ano2 = leituraAno();
    int mes2 = leituraMes();
    int dia2 = leituraDia(mes2,ano2);
    printf("\n-----------------------------------\n-----------------------------------");
    float diferenca = diferencaDatas(dia1,mes1,ano1,dia2,mes2,ano2); //Recebe a diferenca
         
    printf("\n\nA diferenca entre as datas e' %.0f\n\n",diferenca);

    system("PAUSE");
    return 0;
}


//Funcao que calculara a diferenca entre as datas:  
float diferencaDatas(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    
    float juliano1 = paraJuliano(dia1,mes1,ano1);
    float juliano2 = paraJuliano(dia2,mes2,ano2);
    
    float diferenca =  juliano2-juliano1;
    
    if (diferenca<0){
        diferenca *=-1;
    }
    
    return diferenca;

}

//Funcao para leitura e validacao do dia: 
int leituraDia(int mes,int ano){
    int dia=0;
    int diaInvalido = 1;
    
    int bissexto = anoBissexto(ano); // verifica se o ano e' bissexto;
    
    while (diaInvalido == 1){
        printf("Digite o dia:  ");
        scanf("%d",&dia);

        if (bissexto == 1 && mes==2){
            if (dia >= 1 && dia <= 29){
                diaInvalido=0; //Validacao de Fevereiro em ano bissexto
            }   
        }else if (mes==2 && bissexto==0){
            if (dia >= 1 && dia <= 28){
                diaInvalido=0; //Validacao de Fevereiro em ano normal
            }   
        }else if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
            if (dia >=1 && dia<=31){
                diaInvalido=0; //Validacao de meses com 31 dias
            }
        }else if (dia>=1 && dia <=30){
                diaInvalido=0; //Validacao de meses com 30 dias
        }
    }
    return dia;
}
int leituraMes(){ //Leitura e validacao do Mes
    int mes=0;
    while (mes<1 || mes>12){
        printf("Digite o mes:  ");
        scanf("%d",&mes);
    }
    return mes;
}
int leituraAno(){ //Leitura do ano
     int ano=0;
     //O ano pode ser negativo (A.C.)
        printf("Digite o ano:  ");
        scanf("%d",&ano);
    
    return ano;
}

//Funcao que converte para o calendario juliano:
float paraJuliano(int dia, int mes, int ano){

    if (mes <=2){
        mes+=12;
        ano-=1;
    }
    
    float a =  (float)floor(ano/100);
    float b = (float)2-a+floor(a/4);
    float dataJul = (float)floor(365.25*(ano+4716))+floor(30.6001*(mes+1))+dia+b-1524.5;
      
    return dataJul;
    
}

//Funcao que verifica se o ano e' bissexto:
int anoBissexto(int ano) {   
        if ( ( ano % 4 == 0 && ano % 100 != 0 ) || ( ano % 400 == 0 ) ){   
            return 1;   //Retorna 1 caso for bissexto
        }   
        else{   
            return 0;   
        }   
}  
