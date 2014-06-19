#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int dia=1;
  int total = 0;
  int atual;
  int diamax;
  int okmax = 0;
  while (dia<=31)
  {
	printf("Digite o numero de visitantes de hoje (dia %d)",dia);
	scanf("%d",&atual);
	total = total + atual;
	if (total >3000 && okmax==0)
	{
		diamax = dia;
		okmax = 1;
	}
	dia++;
  }
  printf("O total de visitantes foi de %d , e a marca de 3000 visitantes foi ultrapassada no dia %d",total,diamax);
  system("PAUSE");	
  return 0;
}
