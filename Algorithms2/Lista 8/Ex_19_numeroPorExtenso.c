#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio  19  Lista de Exercícios 8                   */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

int main(){
    int numero=0,temAntes = 0;;
    
    char unidades[20][15]={"Zero","Um","Dois","Tres","Quatro","Cinco","Seis","Sete","Oito","Nove"};
    
    char dezenas[20][15]={"Dez","Vinte","Trinta","Quarenta","Cinquenta","Sessenta","Setenta","Oitenta","Noventa"};
    
    char centenas[20][15]={"Cento","Duzentos","Trezentos","Quatrossentos","Quinhentos","Seissentos","Setessentos","Oitossentos","Novessentos"};
    
    char dezAVinte[20][15]={"Onze","Doze","Treze","Quatorze","Quinze","Dezesseis","Dezessete","Dezoito","Dezenove"};
    
    while(numero <=0 || numero >=1000){
        printf("Digite um numero entre 0 e 1000:");
        scanf("%d",&numero);

    }

    if(numero>100){
        printf("%s",centenas[(numero/100)-1]);
        numero%=100;
        temAntes=1;
    }
    if(numero==100){
        printf("Cem");
    }
    if(numero>=20 || numero==10){ 
        if(temAntes==1)printf(" e ");
        printf("%s",dezenas[(numero/10)-1]);
        temAntes=1;
        numero%=10;
    }
    if(numero>10){
        if(temAntes==1)printf(" e ");
        printf("%s",dezAVinte[(numero-10)-1]);
        numero=0;
    }
    if(numero>=1){
        if(temAntes==1)printf(" e ");
        printf("%s",unidades[numero]);
    }
    printf("\n\n");

    system("pause");
    return 0;
}
