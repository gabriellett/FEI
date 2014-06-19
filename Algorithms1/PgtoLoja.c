#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  float valor, valparc;
  int parc;
  printf("Digite o valor do produto \n");
  scanf("%f",&valor);
  printf("Digite o numero de parcelas \n");
  scanf("%d",&parc);
  
  if (parc <=0 || parc >5)
  {
           printf("\nNumero de parcelas incorreto");
  }
  if ( valor <=0)
  {
       printf("\nValor de produto invalido");
  }
  if ( parc == 1)
   {
       valor = valor - (0.2*valor);
       printf("O produto sera pago em uma parcela de %f",valor);
       
   }
   if (parc == 2)
   {
       valor = valor - (0.15*valor);
       valparc = valor/2;
       printf("O produto sera pago em uma 2 parcelas de %f",valparc);
   }
   if(parc == 3)
   {
         valor = valor - (0.09*valor);
         valparc = valor/3;
         printf("O produto sera pago em uma 3 parcelas de %f",valparc);
   }
   if(parc == 4)
   {
                valor = valor - (0.04*valor);
                valparc = valor/4;
                printf("O produto sera pago em uma 4 parcelas de %f",valparc);
   }
   if (parc==5)
   {
        valparc = valor/5;
        printf("O produto sera pago em uma 5 parcelas de %f",valparc);
   }

  system("PAUSE");	
  return 0;
}
