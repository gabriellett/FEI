#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  float acima,abaixo;
  float porcent;
  int selec;
  acima = 0;
  abaixo = 0;
  porcent = 0;
  float entrada = 1;
  printf("Selecionhe a Opção desejada: \n 1-- Porcentagem de multas acima de 140 \n 2-- Multa maior \n 3-- Duas multas maiores \n 4-- Obter a maior e a quantidade de multas iguais a esta \n");
  scanf("%d",&selec);
  if (selec==1)
  {
  printf("Digite a velocidade das multas aplicadas, quando desejar parar digite 0\n");
  {
      while (entrada != 0)
      {
         
         scanf("%f",&entrada);
            if (entrada > 140)
            {
            acima++;
            }
            if (entrada <140 && entrada != 0 )
            {
            abaixo++;

            }
        
        }
      }
        float tot;
        tot = acima+abaixo;
        printf("\n %f porcento das multas estão acima de 140",porcent);
  }
  if (selec==3)
  {
  printf("Digite a velocidade das multas aplicadas, quando desejar parar digite 0\n");
      float maxima1,maxima2;
      maxima1=0;
      maxima2=0;
      int aux = 0;
      while (entrada != 0)
      {

         scanf("%f",&entrada);
         if (entrada > maxima2)
         {
              maxima2=entrada;
         }
         else if(entrada > maxima1)
         {

             maxima1=entrada;

         }
         
        
        }
      
        printf("\n As 2 velocidades maximas registradas sao de %f e %f ",maxima1,maxima2);
  }
  
      if (selec==2)
  {
  printf("Digite a velocidade das multas aplicadas, quando desejar parar digite 0\n");
  {
      int maxima;
      maxima=0;
      while (entrada != 0)
      {

         scanf("%f",&entrada);
            if (entrada > maxima)
            {
            maxima=entrada;
            }
        
        }
      
        printf("\n A velocidade maxima registrada foi de %d",maxima);
  }
  }
        if (selec==4)
  {
  printf("Digite a velocidade das multas aplicadas, quando desejar parar digite 0\n");
  {
      int maxima;
      maxima=0;
      int nmax;
      nmax=0;
      while (entrada != 0)
      {

         scanf("%f",&entrada);
            if (entrada > maxima)
            {
            maxima=entrada;
            nmax=1;
            }
            else if (entrada == maxima)
            {
             nmax++;           
            }
         
        
        }
      
        printf("\n A velocidade maxima registrada foi de %d e o numero de quantidades desta mesma multa foi de %d",maxima,nmax);
  }
  }
  system("PAUSE");	
  return 0;
}
