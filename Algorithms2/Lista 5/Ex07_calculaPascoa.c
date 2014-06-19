#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 7 - Lista de Exercícios 5                     */
/* CC2621 --2011    --turma 610     --                     */

/**************************************************************************/
/* Fontes:                                                                */
/*      Calculo da data da Pascoa: http://astro.if.ufrgs.br/pascoa.htm    */
/*      Calculo e exemplos: http://inf.ufrgs.br/~cabral/Pascoa.html       */
/*      Utilizado Ex 13 da lista 3                                        */
/**************************************************************************/

void calculaPascoa(int,int*,int*);
    
int main(){
    
    int ano=0,dia,mes;
    printf("Digite um ano entre 1582 e 2299:");
    while (ano <1582 || ano > 2299){
    scanf("%d",&ano);
    }
    
    system("cls");
    
    calculaPascoa(ano,&dia,&mes);
    
    printf("A pascoa do ano de %d ocorrera no dia %d do %d.\n",ano,dia,mes);
    system("pause");
}

void calculaPascoa(int ano, int *dia, int *mes){
    int a = ano;
    int c,n,k,i,j,l;
    
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
    *mes = 3 + ((l+40)/44);
    *dia = l + 28 - (31*(*mes/4));
   
}

