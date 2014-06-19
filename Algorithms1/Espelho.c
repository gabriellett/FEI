#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int num,final,ultimo,aux;
  final = 0;
  printf("Digite um numero\n ");
  scanf("%d",&num);
  

  while (num != 0)
  {
        aux = num % 10;
        num = num / 10;
        final = final * 10 + aux;
  }
        printf("\n o numero final e %d \n",final);
  system("PAUSE");	
  return 0;
}
