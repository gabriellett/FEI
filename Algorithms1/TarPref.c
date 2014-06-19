#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float consumo,vfinal; 

  printf("Digite o consumo de agua em metros cubicos\n");
  scanf("%f",&consumo);
  if (consumo <= 20)
  {
              vfinal = consumo*1.6 ;              
              vfinal = vfinal - (0.05*vfinal);

  }
  if (consumo >20 && consumo <50)
  {
              vfinal = consumo * 2.9;
              if (vfinal <= 100)
              {
                         vfinal = vfinal - (0.05*vfinal);
              }
              else
              {
                         vfinal= vfinal + (0.1 * vfinal);
              }
  }
  if (consumo > 50)
  {
              vfinal = consumo * 4.2;
              vfinal = vfinal + (0.1 * vfinal);     
  }
  printf("\n O valor a ser pago é de %f",vfinal);
  system("PAUSE");	
  return 0;
}
