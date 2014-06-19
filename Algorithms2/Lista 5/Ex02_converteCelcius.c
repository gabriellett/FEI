#include <stdio.h>
#include <stdlib.h>

/***************************  FEI  *************************/
/* Aluno: Gabriel Lett Viviani 							   */
/* Exercicio 2 - Lista de Exercícios 5                    */
/* CC2621 --2011    --turma 610     --                     */

/***************************  FEI  *************************/

void converteCelcius(float celcius,float *pFarenheit,float *pKelvin,float *pRankine,float *pReaumur){
    *pFarenheit = ((9*celcius)/5)+32;
    *pKelvin = celcius+273.15; 
    *pRankine = *pFarenheit + 459.67;
    *pReaumur = celcius*0.8;
}

int main()
{
  float tempCelcius,farenheit,kelvin,rankine,reaumur;
 
  printf("Digite uma temperatura em Celcius\n");
  scanf("%f",&tempCelcius);
  
  converteCelcius(tempCelcius,&farenheit,&kelvin,&rankine,&reaumur);
  
  printf("\n\nFarenheit: %f",farenheit);
  printf("\nKelvin...: %f",kelvin);
  printf("\nRankine..: %f",rankine);
  printf("\nReaumur..: %f\n\n",reaumur);
  
  system("PAUSE");	
  return 0;
}


