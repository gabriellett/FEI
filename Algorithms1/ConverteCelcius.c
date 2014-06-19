#include <stdio.h>
#include <stdlib.h>

float converteFarenheit(float celcius){
    float farenheit = ((9*celcius)/5)+32;
    return farenheit;
}

float converteKelvin(float celcius){
    float kelvin = celcius+273.15; 
    return kelvin;
}
float converteRankine(float farenheit){
    float rankine = farenheit - 459.67;
    return rankine;
}
float converteReaumur(float celcius){
    float reaumur = celcius*0.8;
    return reaumur;
}

int main(int argc, char *argv[])
{
  float tempCelcius;
  printf("Digite uma temperatura em Celcius\n");
  scanf("%f",&tempCelcius);
  
  float farenheit = converteFarenheit(tempCelcius);
  printf("\nFarenheit: %f",farenheit);
  
  float kelvin = converteKelvin(tempCelcius);
  printf("\nKelvin...: %f",kelvin);
  
  float rankine = converteRankine(farenheit);
  printf("\nRankine..: %f",rankine);
  
  float reaumur = converteReaumur(tempCelcius);
  printf("\nReaumur..: %f\n\n",reaumur);
  
  system("PAUSE");	
  return 0;
}
