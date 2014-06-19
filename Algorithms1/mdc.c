#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int a,b;printf("Entre com o dividendo \n");
  scanf("%d",&a);printf("Entre com o divisor \n");
  scanf("%d",&b);
  if (a<b){
	int aux;
	aux = a;
	a=b;
	b=aux;
  }
  while ( a % b != 0 ){
	b= a % b; 
  }
  
  printf("O mdc e' %d\n",b);
  
  system("PAUSE");	
  
  return 0;
}
