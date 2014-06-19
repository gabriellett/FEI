#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int segundos,horas,minutos;
  printf("Digite a duracao do evento em segundos: \n");
  scanf("%d",&segundos);
  
  minutos = segundos/60;
  segundos %= 60;
  horas = minutos/60;
  minutos %= 60;
  
  printf("\nO evento durara %d horas, %d minutos e %d segundos.\n",horas,minutos,segundos);
  
  system("PAUSE");	
  return 0;
}
