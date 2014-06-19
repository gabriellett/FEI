#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 12 - Lista de Exercícios 3                    */
/* CC2621 --2011    --turma 610     --                     */

/*********************************************************************************************************/
/*  Fontes:                                                                                              */
/*      Calculo do dia da Semana: http://br.answers.yahoo.com/question/index?qid=20070423164331AAIm0gU   */
/*                                                                                                       */
/*********************************************************************************************************/


int diaSemana(int bissexto, int ano, int mes, int dia){
    int codigoMes = 0; //Codigo do mes: 1:0, 2:3, 3:3, 4:6, 5:1, 6:4, 7:6, 8:2, 9:5, 10:0, 11:3, 12:5;
    int soma = 0;
    
    if (mes==1) { codigoMes=0;}
    if (mes==2) { codigoMes=3;}
    if (mes==3) { codigoMes=3;}
    if (mes==4) { codigoMes=6;}
    if (mes==5) { codigoMes=1;}
    if (mes==6) { codigoMes=4;}
    if (mes==7) { codigoMes=6;}
    if (mes==8) { codigoMes=2;}
    if (mes==9) { codigoMes=5;}
    if (mes==10) { codigoMes=0;}
    if (mes==11) { codigoMes=3;}
    if (mes==12) { codigoMes=5;}
    
    if (bissexto==1 && mes==1 || mes==2){
    soma = ano + (ano/4) + codigoMes + dia -1 - mes;
    }else{
    soma = ano + (ano/4) + codigoMes + dia - mes;    
    }
    int codigo = soma % 7;
    
    return codigo;
}

int anoBissexto(int ano) {   
        if ( ( ano % 4 == 0 && ano % 100 != 0 ) || ( ano % 400 == 0 ) ){   
            return 1;   
        }   
        else{   
            return 0;   
        }   
}  




int main(){
    
    int ano=0,mes=0,dia=0;
    int diaInvalido = 1;
    
    while (ano<=0){
        printf("Digite o ano:  ");
        scanf("%d",&ano);
    }
    
    while (mes<1 || mes>12){
        printf("Digite o mes:  ");
        scanf("%d",&mes);
    }
    
    int bissexto = anoBissexto(ano); // verifica se o ano e' bissexto;
    
    while (diaInvalido == 1){
        printf("Digite o dia:  ");
        scanf("%d",&dia);

        if (bissexto == 1 && mes==2){
            if (dia >= 1 && dia <= 29){
                diaInvalido=0;
            }   
        }else if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
            if (dia >=1 && dia<=31){
                diaInvalido=0;
            }
        }else if (dia>=1 && dia <=30){
                diaInvalido=0;
        }
    }

    
    int codigoDia = diaSemana(bissexto,ano,mes,dia);
    
    if (codigoDia==0) { printf("\n %d / %d / %d e' um sabado!\n",dia,mes,ano);}
    if (codigoDia==1) { printf("\n %d / %d / %d e' um domigo!\n",dia,mes,ano);}
    if (codigoDia==2) { printf("\n %d / %d / %d e' uma segunda-feira!\n",dia,mes,ano);}
    if (codigoDia==3) { printf("\n %d / %d / %d e' uma terca-feira!\n",dia,mes,ano);}
    if (codigoDia==4) { printf("\n %d / %d / %d e' uma quarta-feira!\n",dia,mes,ano);}
    if (codigoDia==5) { printf("\n %d / %d / %d e' uma quinta-feira!\n",dia,mes,ano);}
    if (codigoDia==6) { printf("\n %d / %d / %d e' uma sexta-feira!\n",dia,mes,ano);}



    system("PAUSE");	
    return 0;
}


